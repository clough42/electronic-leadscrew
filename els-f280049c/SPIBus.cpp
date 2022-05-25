/*
 * SPIBus.cpp
 *
 *  Created on: Aug 15, 2019
 *      Author: clough
 */

#include "SPIBus.h"
#include "F28x_Project.h"
#include "Configuration.h"

// wait for the current serial shift operation to complete
#define WAIT_FOR_SERIAL while(SpibRegs.SPISTS.bit.INT_FLAG !=1) {}


SPIBus :: SPIBus( void )
{
    mask = 0xffff;
}

void SPIBus :: initHardware(void)
{
    // Set up slow speed clock
    EALLOW;

#ifdef TARGET_F28004X
    ClkCfgRegs.LOSPCP.bit.LSPCLKDIV = 0b100; // LPSCLK = SYSCLK/8 = 12.5MHz
#endif
#ifdef TARGET_F2806X
    SysCtrlRegs.LOSPCP.bit.LSPCLK = 0b100;     //LPSCLK = SYSCLK/8 = 11.25Mhz
#endif

    EDIS;

    // Set up SPI B
    SpibRegs.SPICCR.bit.SPISWRESET = 0; // Enter RESET state
    setEightBits();
    SpibRegs.SPICCR.bit.CLKPOLARITY = 1; // data latched on rising edge
    SpibRegs.SPICTL.bit.CLK_PHASE = 0; // normal clocking scheme
    SpibRegs.SPICTL.bit.MASTER_SLAVE = 1; // master
#ifdef TARGET_F28004X
    SpibRegs.SPIBRR.bit.SPI_BIT_RATE = 127; // SPI bit rate = LPSCLK/128 ~ 98Kbps
#endif
#ifdef TARGET_F2806X
    SpibRegs.SPIBRR = 127;
#endif

    setThreeWire();
    SpibRegs.SPICCR.bit.SPISWRESET = 1; // clear reset state; ready to transmit

    EALLOW;

    // Set up muxing for SPIB pins
#ifdef TARGET_F28004X
    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 0x2;      // select SPIB_SIMO
    GpioCtrlRegs.GPAGMUX2.bit.GPIO24 = 0x1;
    GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 0x3;      // select SPIB_SOMI
    GpioCtrlRegs.GPAGMUX2.bit.GPIO31 = 0x0;
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 0x3;      // select SPIB_CLK
    GpioCtrlRegs.GPBGMUX1.bit.GPIO32 = 0x0;
#endif

#ifdef TARGET_F2806X
    GpioCtrlRegs.GPAPUD.bit.GPIO24 = 0;   // Enable pull-up on GPIO24 (SPISIMOB)
    GpioCtrlRegs.GPAPUD.bit.GPIO25 = 0;   // Enable pull-up on GPIO25 (SPISOMIB)
    GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;   // Enable pull-up on GPIO14 (SPICLKB)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO24 = 3; // Asynch input GPIO24 (SPISIMOB)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO25 = 3; // Asynch input GPIO25 (SPISOMIB)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO14 = 3; // Asynch input GPIO14 (SPICLKB)
    GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 3; // Configure GPIO24 as SPISIMOB
    GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 3; // Configure GPIO25 as SPISOMIB
    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 3; // Configure GPIO14 as SPICLKB
#endif

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
    mask = 0x00ff;                     // set the mask to 8 bits
}

void SPIBus :: setSixteenBits( void )
{
    SpibRegs.SPICCR.bit.SPICHAR = 0xF; // 16 bits
    mask = 0xffff;                     // set the mask to 16 bits
}

void SPIBus :: sendWord(Uint16 data)
{
    SpibRegs.SPICTL.bit.TALK = 1;
    SpibRegs.SPITXBUF = data;
    WAIT_FOR_SERIAL;
    dummy = SpibRegs.SPIRXBUF;
}

Uint16 SPIBus :: receiveWord(void) {
    SpibRegs.SPICTL.bit.TALK = 0;
    SpibRegs.SPITXBUF = dummy;
    WAIT_FOR_SERIAL;
    return SpibRegs.SPIRXBUF & mask; // mask off if we're in 8-bit mode
}




