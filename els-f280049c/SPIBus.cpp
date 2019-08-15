/*
 * SPIBus.cpp
 *
 *  Created on: Aug 15, 2019
 *      Author: clough
 */

#include "SPIBus.h"
#include "F28x_Project.h"

// wait for the current serial shift operation to complete
#define WAIT_FOR_SERIAL while(SpibRegs.SPISTS.bit.INT_FLAG !=1) {}


SPIBus :: SPIBus( void )
{

}

void SPIBus :: initHardware(void)
{
    // Set up SPI B
    SpibRegs.SPICCR.bit.SPISWRESET = 0; // Enter RESET state
    setEightBits();
    SpibRegs.SPICCR.bit.CLKPOLARITY = 1; // data latched on rising edge
    SpibRegs.SPICTL.bit.CLK_PHASE = 0; // normal clocking scheme
    SpibRegs.SPICTL.bit.MASTER_SLAVE = 1; // master
    SpibRegs.SPIBRR.bit.SPI_BIT_RATE = ((25000000 / 250000) - 1); // baud rate = 250k LSPCLK
    setThreeWire();
    SpibRegs.SPICCR.bit.SPISWRESET = 1; // clear reset state; ready to transmit

    EALLOW;

    // Set up muxing for SPIB pins
    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 0x2;      // select SPIB_SIMO
    GpioCtrlRegs.GPAGMUX2.bit.GPIO24 = 0x1;
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0x3;      // select SPIB_SOMI
    GpioCtrlRegs.GPAGMUX2.bit.GPIO31 = 0x0;
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0x3;      // select SPIB_CLK
    GpioCtrlRegs.GPBGMUX1.bit.GPIO32 = 0x0;

    EDIS;
}

void SPIBus :: setThreeWire( void )
{
    SpibRegs.SPIPRI.bit.TRIWIRE = 1; // 3-wire mode
}

void SPIBus :: setFourWire( void )
{
    SpibRegs.SPIPRI.bit.TRIWIRE = 0; // Normal (4-wire) mode
}

void SPIBus :: setEightBits( void )
{
    SpibRegs.SPICCR.bit.SPICHAR = 0x7; // 8 bits
}

void SPIBus :: setSixteenBits( void )
{
    SpibRegs.SPICCR.bit.SPICHAR = 0xF; // 16 bits
}

void SPIBus :: sendWord(Uint16 data)
{
    SpibRegs.SPITXBUF = data;
    WAIT_FOR_SERIAL;
    dummy = SpibRegs.SPIRXBUF;
}

Uint16 SPIBus :: receiveWord(void) {
    SpibRegs.SPITXBUF = dummy;
    WAIT_FOR_SERIAL;
    return SpibRegs.SPIRXBUF;
}




