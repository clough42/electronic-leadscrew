// Clough42 Electronic Leadscrew
// https://github.com/clough42/electronic-leadscrew
//
// MIT License
//
// Copyright (c) 2019 James Clough
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#include "ControlPanel.h"

// Time delay to allow CS (STB) line to reach high state and be registered
#define CS_RISE_TIME_US 5

// Time delay after sending read command, before clocking in data
#define DELAY_BEFORE_READING_US 1


// Lower the TM1638 CS (STB) line
#define CS_ASSERT GpioDataRegs.GPBCLEAR.bit.GPIO33 = 1

// Raise the TM1638 CS (STB) line
#define CS_RELEASE GpioDataRegs.GPBSET.bit.GPIO33 = 1


ControlPanel :: ControlPanel(SPIBus *spiBus)
{
    this->spiBus = spiBus;
    this->leds.all = 0;
    this->keys.all = 0;
    this->brightness = 3;
}

void ControlPanel :: initHardware(void)
{
    EALLOW;

    // use GPIO33 as the chip select so we can control it ourselves
    GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 0x0;      // SELECT GPIO33
    GpioCtrlRegs.GPBDIR.bit.GPIO33 = 1;         // output
    CS_RELEASE;                                 // set it to high

    EDIS;
}

void ControlPanel :: configureSpiBus( void )
{
    // configure the shared bus
    this->spiBus->setThreeWire();
    this->spiBus->setEightBits();
}

Uint16 ControlPanel :: reverse_byte(Uint16 x)
{
    static const Uint16 table[] = {
        0x0000, 0x8000, 0x4000, 0xc000, 0x2000, 0xa000, 0x6000, 0xe000,
        0x1000, 0x9000, 0x5000, 0xd000, 0x3000, 0xb000, 0x7000, 0xf000,
        0x0800, 0x8800, 0x4800, 0xc800, 0x2800, 0xa800, 0x6800, 0xe800,
        0x1800, 0x9800, 0x5800, 0xd800, 0x3800, 0xb800, 0x7800, 0xf800,
        0x0400, 0x8400, 0x4400, 0xc400, 0x2400, 0xa400, 0x6400, 0xe400,
        0x1400, 0x9400, 0x5400, 0xd400, 0x3400, 0xb400, 0x7400, 0xf400,
        0x0c00, 0x8c00, 0x4c00, 0xcc00, 0x2c00, 0xac00, 0x6c00, 0xec00,
        0x1c00, 0x9c00, 0x5c00, 0xdc00, 0x3c00, 0xbc00, 0x7c00, 0xfc00,
        0x0200, 0x8200, 0x4200, 0xc200, 0x2200, 0xa200, 0x6200, 0xe200,
        0x1200, 0x9200, 0x5200, 0xd200, 0x3200, 0xb200, 0x7200, 0xf200,
        0x0a00, 0x8a00, 0x4a00, 0xca00, 0x2a00, 0xaa00, 0x6a00, 0xea00,
        0x1a00, 0x9a00, 0x5a00, 0xda00, 0x3a00, 0xba00, 0x7a00, 0xfa00,
        0x0600, 0x8600, 0x4600, 0xc600, 0x2600, 0xa600, 0x6600, 0xe600,
        0x1600, 0x9600, 0x5600, 0xd600, 0x3600, 0xb600, 0x7600, 0xf600,
        0x0e00, 0x8e00, 0x4e00, 0xce00, 0x2e00, 0xae00, 0x6e00, 0xee00,
        0x1e00, 0x9e00, 0x5e00, 0xde00, 0x3e00, 0xbe00, 0x7e00, 0xfe00,
        0x0100, 0x8100, 0x4100, 0xc100, 0x2100, 0xa100, 0x6100, 0xe100,
        0x1100, 0x9100, 0x5100, 0xd100, 0x3100, 0xb100, 0x7100, 0xf100,
        0x0900, 0x8900, 0x4900, 0xc900, 0x2900, 0xa900, 0x6900, 0xe900,
        0x1900, 0x9900, 0x5900, 0xd900, 0x3900, 0xb900, 0x7900, 0xf900,
        0x0500, 0x8500, 0x4500, 0xc500, 0x2500, 0xa500, 0x6500, 0xe500,
        0x1500, 0x9500, 0x5500, 0xd500, 0x3500, 0xb500, 0x7500, 0xf500,
        0x0d00, 0x8d00, 0x4d00, 0xcd00, 0x2d00, 0xad00, 0x6d00, 0xed00,
        0x1d00, 0x9d00, 0x5d00, 0xdd00, 0x3d00, 0xbd00, 0x7d00, 0xfd00,
        0x0300, 0x8300, 0x4300, 0xc300, 0x2300, 0xa300, 0x6300, 0xe300,
        0x1300, 0x9300, 0x5300, 0xd300, 0x3300, 0xb300, 0x7300, 0xf300,
        0x0b00, 0x8b00, 0x4b00, 0xcb00, 0x2b00, 0xab00, 0x6b00, 0xeb00,
        0x1b00, 0x9b00, 0x5b00, 0xdb00, 0x3b00, 0xbb00, 0x7b00, 0xfb00,
        0x0700, 0x8700, 0x4700, 0xc700, 0x2700, 0xa700, 0x6700, 0xe700,
        0x1700, 0x9700, 0x5700, 0xd700, 0x3700, 0xb700, 0x7700, 0xf700,
        0x0f00, 0x8f00, 0x4f00, 0xcf00, 0x2f00, 0xaf00, 0x6f00, 0xef00,
        0x1f00, 0x9f00, 0x5f00, 0xdf00, 0x3f00, 0xbf00, 0x7f00, 0xff00,
    };
    return table[x];
}

void ControlPanel :: sendData()
{
    int i;
    Uint16 briteVal = 0x80;
    if( this->brightness > 0 ) {
        briteVal = 0x87 + this->brightness;
    }

    SpibRegs.SPICTL.bit.TALK = 1;

    CS_ASSERT;
    spiBus->sendWord(reverse_byte(briteVal));       // brightness
    CS_RELEASE;
    DELAY_US(CS_RISE_TIME_US);              // give CS line time to register high

    CS_ASSERT;
    spiBus->sendWord(reverse_byte(0x40));           // auto-increment
    CS_RELEASE;
    DELAY_US(CS_RISE_TIME_US);              // give CS line time to register high

    CS_ASSERT;
    spiBus->sendWord(reverse_byte(0xc0));           // display data
    for( i=0; i < 16; i++ ) {
        spiBus->sendWord(this->displayData[i]);
    }
    CS_RELEASE;
    DELAY_US(CS_RISE_TIME_US);              // give CS line time to register high

    SpibRegs.SPICTL.bit.TALK = 0;
}

KEY_REG ControlPanel :: readKeys(void)
{
    SpibRegs.SPICTL.bit.TALK = 1;

    CS_ASSERT;
    spiBus->sendWord(reverse_byte(0x40));           // auto-increment
    CS_RELEASE;
    DELAY_US(CS_RISE_TIME_US);              // give CS line time to register high

    CS_ASSERT;
    spiBus->sendWord(reverse_byte(0x42));

    SpibRegs.SPICTL.bit.TALK = 0;

    DELAY_US(DELAY_BEFORE_READING_US); // delay required by TM1638 per datasheet

    Uint16 byte1 = spiBus->receiveWord();
    Uint16 byte2 = spiBus->receiveWord();
    Uint16 byte3 = spiBus->receiveWord();
    Uint16 byte4 = spiBus->receiveWord();

    KEY_REG keyMask;
    keyMask.all = byte3;

    CS_RELEASE;
    DELAY_US(CS_RISE_TIME_US);              // give CS line time to register high

    return keyMask;
}

KEY_REG ControlPanel :: getKeys()
{
    KEY_REG newKeys;

    configureSpiBus();

    newKeys = readKeys();

    return newKeys;
}

void ControlPanel :: setBrightness( Uint16 brightness )
{
    if( brightness > 8 ) brightness = 8;

    this->brightness = brightness;
}

void ControlPanel :: setLeds(LED_REG leds)
{
    displayData[0] =
            (leds.bit.VREG_RED << 15) +
            (leds.bit.STEP_RED << 14) +
            (leds.bit.ALM_RED << 13) +
            (leds.bit.EEPROM_RED << 12);
    displayData[1] = 0x0000ffff;
    displayData[2] =
            (leds.bit.VREG_GREEN << 15) +
            (leds.bit.STEP_GREEN << 14) +
            (leds.bit.ALM_GREEN << 13) +
            (leds.bit.EEPROM_GREEN << 12);
    displayData[3] = 0x0000ffff;
    displayData[4] =
            (leds.bit.A << 15) +
            (leds.bit.B << 14) +
            (leds.bit.C << 13) +
            (leds.bit.D << 12);
    displayData[5] = 0x0000ffff;
    displayData[6] = 0x0000ffff;
    displayData[7] = 0x0000ffff;
    displayData[8] = 0x0000ffff;
    displayData[9] = 0x0000ffff;
    displayData[10] = 0x0000ffff;
    displayData[11] = 0x0000ffff;
    displayData[12] = 0x0000ffff;
    displayData[13] = 0x0000ffff;
    displayData[14] = 0x0000ffff;
    displayData[15] = 0x0000ffff;
}

void ControlPanel :: refresh()
{
    configureSpiBus();

    sendData();
}






