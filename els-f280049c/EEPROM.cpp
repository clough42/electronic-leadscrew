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


#include "EEPROM.h"

// Raise the EEPROM CS line
#define CS_SET GpioDataRegs.GPBSET.bit.GPIO34 = 1

// Lower the EEPROM CS line
#define CS_CLEAR GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1

EEPROM :: EEPROM(void)
{

}

void EEPROM :: initHardware(void)
{
    EALLOW;

    // Set up SPI A
    SpibRegs.SPICCR.bit.SPISWRESET = 0;         // Enter RESET state
    SpibRegs.SPICCR.bit.SPICHAR = 0x7;          // 8 bits
    SpibRegs.SPICCR.bit.CLKPOLARITY = 1;        // data latched on rising edge
    SpibRegs.SPICTL.bit.CLK_PHASE=0;            // normal clocking scheme
    SpibRegs.SPICTL.bit.MASTER_SLAVE=1;         // master
    SpibRegs.SPIBRR.bit.SPI_BIT_RATE = ((25000000 / 250000) - 1); // baud rate = 250k LSPCLK
    SpibRegs.SPIPRI.bit.TRIWIRE=0;              // Normal (4-wire) mode
    SpibRegs.SPICCR.bit.SPISWRESET = 1;         // clear reset state; ready to transmit

    // Set up muxing for SPIB pins
    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 0x2;      // select SPIB_SIMO
    GpioCtrlRegs.GPAGMUX2.bit.GPIO24 = 0x1;
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0x3;      // select SPIB_SOMI
    GpioCtrlRegs.GPAGMUX2.bit.GPIO31 = 0x0;
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0x3;      // select SPIB_CLK
    GpioCtrlRegs.GPBGMUX1.bit.GPIO32 = 0x0;

    // just use GPIO34 as the chip select so we can control it ourselves
    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0x0;      // SELECT GPIO34
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;         // output
    CS_SET;                                     // set it to high

    EDIS;
}
