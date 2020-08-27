/*
 * nextion.cpp
 *
 *  Created on: Aug 25, 2020
 *      Author: Kent A. Vander Velden (kent.vandervelden@gmail.com)
 *
 *  Summary: The routines here translate between the existing seven
 *  segment display and the Nextion, leaving as much code untouched
 *  as possible. Two UARTS are used, SCIA for virtual COM debugging
 *  and SCIB which connects to the Nextion. An additional GPIO pin
 *  is used as a limit switch input, which may be useful as a hard
 *  limit to profile or thread up to a shoulder.
 *
 *  Other than the TI routines at the end of this file, which have
 *  their own terms, the code is released to the public domain
 *  "as is" and is unsupported.
 *
 */

#include "F28x_Project.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <file.h>
#include "driverlib.h"
#include "device.h"
#include "nextion.h"

typedef unsigned char uchar_t;

// Set to 1 to enable debugging of the Nextion messages over the
// virtual COM port.
#define NEXTION_DEBUG 0

#if NEXTION_DEBUG
#include "launchxl_ex1_sci_io.h"

static void scia_init();
//static void transmitSCIAChar(uint16_t a);
//static void transmitSCIAMessage(const unsigned char *msg);
//static void initSCIAFIFO(void);
#endif

static void scib_init();
static void transmitSCIBChar(uint16_t a);
static void transmitSCIBMessage(const unsigned char *msg);
static void initSCIBFIFO(void);

static int nextion_read(uchar_t buf[], const int nmax)
{
    int n = 0;

    while (n < nmax && ScibRegs.SCIFFRX.bit.RXFFST)
    {
        uint16_t ReceivedChar = ScibRegs.SCIRXBUF.all;
        buf[n++] = ReceivedChar;

        // This delay is done to increase chances that a complete message from
        // the Nextion will be received in one function call. To eliminate the
        // delay, add memory to the Nextion routines, continuing to
        // read and tokenize per call until a valid message is gathered.
        // ~208us to transmit 8-bits at 38.4kBaud
        DELAY_US(500);
    }

#if NEXTION_DEBUG
    if (n > 0)
    {
        printf("%d:", n);
        for (int i = 0; i < n; i++)
        {
            printf(" %02x", buf[i]);
        }
        putchar('\r');
        putchar('\n');
    }
#endif

    return n;
}

static void nextion_send(const uchar_t *msg)
{
    transmitSCIBMessage((const unsigned char*) msg);
}

void nextion_init()
{
    // Configure the GPIO pin for the limit switch input
    // GPIO_setPinConfig(GPIO_25_GPIO25);
    GPIO_SetupPinMux(25, GPIO_MUX_CPU1, 0);
    GPIO_SetupPinOptions(25, GPIO_INPUT, GPIO_OPENDRAIN | GPIO_PULLUP);

#if NEXTION_DEBUG
    GPIO_setPinConfig(GPIO_28_SCIRXDA);
    GPIO_setPinConfig(GPIO_29_SCITXDA);

    GPIO_setQualificationMode(28, GPIO_QUAL_ASYNC);

    scia_init();
#endif

    GPIO_setPinConfig(GPIO_13_SCIRXDB);
    GPIO_setPinConfig(GPIO_40_SCITXDB);

    GPIO_setPadConfig(13, GPIO_PIN_TYPE_PULLUP);
    // GPIO_setPadConfig(40, GPIO_PIN_TYPE_PULLUP);

    GPIO_setQualificationMode(13, GPIO_QUAL_ASYNC);

    scib_init();

    initSCIBFIFO();

#if NEXTION_DEBUG
    // To help with debugging, configure the UART that is connected to
    // USB port, the virtual terminal, to be stdout.
    volatile int status = 0;
    status = add_device("scia", _SSA, SCI_open, SCI_close, SCI_read, SCI_write,
                        SCI_lseek, SCI_unlink, SCI_rename);
    volatile FILE *fid = fopen("scia", "w");
    freopen("scia:", "w", stdout);
    setvbuf(stdout, NULL, _IONBF, 0);
#endif
}

// Wait for the Nextion to become ready.
void nextion_wait()
{
    // The easiest way to while for the Nextion to be ready with a fixed delay
    // to have a fixed delay.
    //   DELAY_US(250000);
    // But the required time, while short, is unspecified. Instead, wait for
    // the Nextion to send a ready message, eventually timing out if necessary.
    //
    // Nexiton will send
    //   0x00 0x00 0x00 0xff 0xff 0xff
    // on start up, and
    //   0x88 0xff 0xff 0xff
    // when ready. Often both messages will be read in a single
    // nextion_read(...) call
    //
    // The Nextion is ready fast and I rarely saw the ready message unless
    // power cycling only the Nextion. It may be better to test if the Nextion
    // is ready by checking its response to a query like which page is current.

    // Timeout after 40 * 25us = 1s
    for (int i = 0; i < 40; i++)
    {
        const int nmax = 6;
        uchar_t msg[nmax];
        int n = nextion_read(msg, nmax);
        if (n > 3)
        {
            bool has_end = msg[n - 3] == 0xff && msg[n - 2] == 0xff
                    && msg[n - 1] == 0xff;
            if (n >= 4 && msg[n - 4] == 0x88 && has_end)
            {
                break;
            }
        }
        DELAY_US(25000);
    }
}

// Update the Nextion feed display using the same information used
// to update the seven-segment display.
void nextion_feed(const FEED_THREAD *f, LED_REG leds)
{
    {
        uchar_t msg2[8 + 4 + 5] = { "t1.txt=\"" };
        uchar_t *p = msg2 + 8;
        for (int i = 0; i < 4; i++)
        {
            Uint16 a = f->display[i];
            Uint16 pnt = a & POINT;
            a &= ~POINT;
            switch (a)
            {
            case BLANK:
                *p++ = ' ';
                break;
            case ZERO:
                *p++ = '0';
                break;
            case ONE:
                *p++ = '1';
                break;
            case TWO:
                *p++ = '2';
                break;
            case THREE:
                *p++ = '3';
                break;
            case FOUR:
                *p++ = '4';
                break;
            case FIVE:
                *p++ = '5';
                break;
            case SIX:
                *p++ = '6';
                break;
            case SEVEN:
                *p++ = '7';
                break;
            case EIGHT:
                *p++ = '8';
                break;
            case NINE:
                *p++ = '9';
                break;
            default:
                *p++ = '?';
                break;
            }
            if (pnt)
            {
                *p++ = '.';
            }
        }
        *p++ = '"';
        *p++ = '\xff';
        *p++ = '\xff';
        *p++ = '\xff';
        *p++ = '\0';
        nextion_send(msg2);
    }

    {
        const uchar_t *msgs[5] = { "b8.txt=\"mm Pitch\"\xff\xff\xff",
                                   "b8.txt=\"mm / rev\"\xff\xff\xff",
                                   "b8.txt=\"TPI\"\xff\xff\xff",
                                   "b8.txt=\"inch / rev\"\xff\xff\xff",
                                   "b8.txt=\"???\"\xff\xff\xff" };

        int i = 4;
        if (leds.bit.THREAD && leds.bit.TPI)
        {
            i = 2;
        }
        else if (leds.bit.FEED && leds.bit.INCH)
        {
            i = 3;
        }
        else if (leds.bit.THREAD && leds.bit.MM)
        {
            i = 0;
        }
        else if (leds.bit.FEED && leds.bit.MM)
        {
            i = 1;
        }

        nextion_send(msgs[i]);
    }

    {
        const uchar_t *msgs[5] = { "b9.txt=\"Right Hand\"\xff\xff\xff",
                                   "b9.txt=\"Left Hand\"\xff\xff\xff",
                                   "b9.txt=\"Forward\"\xff\xff\xff",
                                   "b9.txt=\"Reverse\"\xff\xff\xff",
                                   "b9.txt=\"???\"\xff\xff\xff" };

        int i = 4;
        if (leds.bit.THREAD && leds.bit.FORWARD)
        {
            i = 0;
        }
        else if (leds.bit.THREAD && leds.bit.REVERSE)
        {
            i = 1;
        }
        else if (leds.bit.FEED && leds.bit.FORWARD)
        {
            i = 2;
        }
        else if (leds.bit.FEED && leds.bit.REVERSE)
        {
            i = 3;
        }

        nextion_send(msgs[i]);
    }
}

void nextion_rpm(Uint16 rpm)
{
    static bool do_once = true;
    static Uint16 p_rpm = 0;

    if (p_rpm != rpm || do_once)
    {
        uchar_t msg2[32];
        sprintf((char*) msg2, "t0.txt=\"%u\"\xff\xff\xff", rpm);
        nextion_send(msg2);

        p_rpm = rpm;
        do_once = false;
    }
}

KEY_REG nextion_loop(bool alarm, bool &enabled, bool &at_stop, bool &init)
{
    static bool do_once = true;
    bool p_enabled = enabled;

    // Check the limit switch and update the enabled state
    at_stop = GPIO_ReadPin(25);
    enabled = enabled && !at_stop;

    // Receive message from Nextion display
    const int nmax = 12;
    uchar_t msg[nmax];
    int n = nextion_read(msg, nmax);

    // Feed_mode must be initialized with the same that's initially shown on the seven-segment display.
    // This is a kludge but correcting this might have involved more changes in the original code.
    // Worse case is the two are initially out of sync, but will sync up once the mode is changed.
    static int feed_mode = 3;

    // Decode message from Nextion display and emulate a seven-segment key presses
    KEY_REG key;
    key.all = 0;
    if (n > 3)
    {
        bool has_end = msg[n - 3] == 0xff && msg[n - 2] == 0xff
                && msg[n - 1] == 0xff;

        if (has_end && (n == 10 || n == 4) && msg[n - 4] == 0x88)
        {
            // Reinitialize the screen if the Nextion resets, through a flag
            // passed back to UserInterface the feed information is reinitialized.
            do_once = true;
#if NEXTION_DEBUG
            printf("Reinitialize\r\n");
#endif
        }
        else if (has_end && n == 7 && msg[0] == 0x65)
        {
            // Touch Event
            uchar_t page_num = msg[1];
            uchar_t comp_id = msg[2];
            uchar_t event = msg[3];

            if (page_num == 0 && event == 1)
            {
                switch (comp_id)
                {
                case 9:
                    key.bit.DOWN = 1;
                    break;
                case 10:
                    key.bit.UP = 1;
                    break;
                case 14:
                    // Consider the desired state of the LEDs and what keys must be pressed to move to desired state.
                    // Desired state for each feed_mode:
                    // 0:
                    //  leds.bit.THREAD = 1;
                    //  leds.bit.MM = 1;
                    // 1:
                    //  leds.bit.FEED = 1;
                    //  leds.bit.MM = 1;
                    // 2:
                    //  leds.bit.THREAD = 1;
                    //  leds.bit.TPI = 1;
                    // 3:
                    //  leds.bit.FEED = 1;
                    //  leds.bit.INCH = 1;
                    feed_mode = (feed_mode + 1) % 4;
                    switch (feed_mode)
                    {
                    case 0:
                        key.bit.FEED_THREAD = 1;
                        key.bit.IN_MM = 1;
                        break;
                    case 1:
                        key.bit.FEED_THREAD = 1;
                        break;
                    case 2:
                        key.bit.FEED_THREAD = 1;
                        key.bit.IN_MM = 1;
                        break;
                    case 3:
                        key.bit.FEED_THREAD = 1;
                        break;
                    }
                    break;
                case 15:
                    key.bit.FWD_REV = 1;
                    break;
                case 18:
                    // Remain disabled if limit switch is tripped, else toggle enable.
                    enabled = !at_stop && !enabled;
                    break;
                default:
                    break;
                }
            }
        }
    }

    // Set credits message once
    if (do_once)
    {
        const uchar_t *msg = { "t2.txt=\"ELS 1.1.02\r\n"
                               "James Clough - Clough42\r\n"
                               "\r\n"
                               "Nextion display\r\n"
                               "Kent A. Vander Velden"
                               "\"\xff\xff\xff" };
        nextion_send(msg);
    }

    // Update alarm indicator
    {
        static bool p_alarm = true;
        const uchar_t *msgs[2] = { "r1.val=0\xff\xff\xff",
                                   "r1.val=1\xff\xff\xff" };

        if (p_alarm != alarm || do_once)
        {
            // In this fast loop, update the display only if needed to avoid flicker.
            nextion_send(msgs[alarm ? 1 : 0]);
            p_alarm = alarm;
        }
    }

    // Update the enable/disable button
    if (p_enabled != enabled || do_once)
    {
        const uchar_t *msgs[2] = { "b11.txt=\"Enable\"\xff\xff\xff",
                                   "b11.txt=\"Disable\"\xff\xff\xff" };
        nextion_send(msgs[enabled ? 1 : 0]);
    }

    init = do_once;
    do_once = false;

    return key;
}

// ===========================================================================
// The support function below are from or based on TI's C2000Ware examples.
// Most are from sci_ex1_echoback.c, and below is the associated TI license.
// ===========================================================================
//
//#############################################################################
// $TI Release: F28002x Support Library v3.02.00.00 $
// $Release Date: Tue May 26 17:23:28 IST 2020 $
// $Copyright:
// Copyright (C) 2020 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
//
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the
//   distribution.
//
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

#if NEXTION_DEBUG
//
// scia_init - SCIA  8-bit word, baud rate 0x001A, default, 1 STOP bit,
// no parity
//
static void scia_init()
{
    //
    // Note: Clocks were turned on to the SCIA peripheral
    // in the InitSysCtrl() function
    //

    //
    // 1 stop bit,  No loopback, No parity,8 char bits, async mode,
    // idle-line protocol
    //
    SciaRegs.SCICCR.all = 0x0007;

    //
    // enable TX, RX, internal SCICLK, Disable RX ERR, SLEEP, TXWAKE
    //
    SciaRegs.SCICTL1.all = 0x0003;

    SciaRegs.SCICTL2.bit.TXINTENA = 1;
    SciaRegs.SCICTL2.bit.RXBKINTENA = 1;

    //
    // 115200 baud @LSPCLK = 25MHz (100 MHz SYSCLK)
    //
    SciaRegs.SCIHBAUD.all = 0x00;
    SciaRegs.SCILBAUD.all = 0x1A;

    //
    // Relinquish SCI from Reset
    //
    SciaRegs.SCICTL1.all = 0x0023;

    return;
}
#endif

//
// scib_init - SCIB  8-bit word, baud rate 0x001A, default, 1 STOP bit,
// no parity
//
static void scib_init()
{
    //
    // Note: Clocks were turned on to the SCIB peripheral
    // in the InitSysCtrl() function
    //

    //
    // 1 stop bit,  No loopback, No parity,8 char bits, async mode,
    // idle-line protocol
    //
    ScibRegs.SCICCR.all = 0x0007;

    //
    // enable TX, RX, internal SCICLK, Disable RX ERR, SLEEP, TXWAKE
    //
    ScibRegs.SCICTL1.all = 0x0003;

    ScibRegs.SCICTL2.bit.TXINTENA = 1;
    ScibRegs.SCICTL2.bit.RXBKINTENA = 1;

#if 0
    //
    // 9600 baud @LSPCLK = 25MHz (100 MHz SYSCLK)
    //
    ScibRegs.SCIHBAUD.all = 0x01;
    ScibRegs.SCILBAUD.all = 0x44;
#else
    //
    // 38400 baud @LSPCLK = 25MHz (100 MHz SYSCLK)
    //
    ScibRegs.SCIHBAUD.all = 0x00;
    ScibRegs.SCILBAUD.all = 0x50;
#endif

    //
    // Relinquish SCI from Reset
    //
    ScibRegs.SCICTL1.all = 0x0023;

    return;
}

#if NEXTION_DEBUG
#if 0
//
// transmitSCIAChar - Transmit a character from the SCI
//
static void transmitSCIAChar(uint16_t a)
{
    while (SciaRegs.SCIFFTX.bit.TXFFST != 0)
    {

    }
    SciaRegs.SCITXBUF.all = a;
}

//
// transmitSCIAMessage - Transmit message via SCIA
//
static void transmitSCIAMessage(const unsigned char *msg)
{
    int i;
    i = 0;
    while (msg[i] != '\0')
    {
        transmitSCIAChar(msg[i]);
        i++;
    }
}

//
// initSCIAFIFO - Initialize the SCI FIFO
//
static void initSCIAFIFO(void)
{
    SciaRegs.SCIFFTX.all = 0xE040;
    SciaRegs.SCIFFRX.all = 0x2044;
    SciaRegs.SCIFFCT.all = 0x0;
}
#endif
#endif

//
// transmitSCIAChar - Transmit a character from the SCI
//
static void transmitSCIBChar(uint16_t a)
{
    while (ScibRegs.SCIFFTX.bit.TXFFST != 0)
    {

    }
    ScibRegs.SCITXBUF.all = a;
}

//
// transmitSCIAMessage - Transmit message via SCIB
//
static void transmitSCIBMessage(const unsigned char *msg)
{
    int i;
    i = 0;
    while (msg[i] != '\0')
    {
        transmitSCIBChar(msg[i]);
        i++;
    }
}

//
// initSCIBFIFO - Initialize the SCI FIFO
//
static void initSCIBFIFO(void)
{
    ScibRegs.SCIFFTX.all = 0xE040;
    ScibRegs.SCIFFRX.all = 0x2044;
    ScibRegs.SCIFFCT.all = 0x0;
}

// ===========================================================================
