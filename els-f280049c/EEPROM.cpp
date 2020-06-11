// Electronic Leadscrew
// https://github.com/alexphredorg/electronic-leadscrew
//
// Copyright (c) 2020 Alex Wetmore
//
// Derived from:
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

#if 0
//
// TODO -- move to devicelib and re-enable
//
#include "EEPROM.h"

// Raise the EEPROM CS line
#define CS_RELEASE GpioDataRegs.GPBSET.bit.GPIO34 = 1

// Lower the EEPROM CS line
#define CS_ASSERT GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1

// enough time for the CS line to rise and be deteted
#define CS_RISE_TIME_US 5

EEPROM :: EEPROM(SPIBus *spiBus)
{
    this->spiBus = spiBus;
}

void EEPROM :: initHardware(void)
{
    EALLOW;

    // use GPIO34 as the chip select
    GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 0x0;      // SELECT GPIO34
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;         // output
    CS_RELEASE;                                 // set it to high

    EDIS;
}

void EEPROM :: configureSpiBus8Bit( void )
{
    // configure the shared bus
    this->spiBus->setFourWire();
    this->spiBus->setEightBits();
}

void EEPROM :: configureSpiBus16Bit( void )
{
    // configure the shared bus
    this->spiBus->setFourWire();
    this->spiBus->setSixteenBits();
}

Uint16 EEPROM :: readStatusRegister(void)
{
    Uint16 command = 0b0000010100000000;

    configureSpiBus8Bit();

    CS_ASSERT;
    this->spiBus->sendWord(command);
    Uint16 status = this->spiBus->receiveWord();
    CS_RELEASE;
    DELAY_US(CS_RISE_TIME_US);

    return status;
}

void EEPROM :: setWriteLatch(void)
{
    Uint16 command = 0b0000011000000000;

    configureSpiBus8Bit();

    CS_ASSERT;
    this->spiBus->sendWord(command);
    CS_RELEASE;
    DELAY_US(CS_RISE_TIME_US);

}

void EEPROM :: waitForWriteCycle(void)
{
    while( readStatusRegister() & 0b0000000000000001 );
}

void EEPROM :: sendReadCommand(Uint16 blockNumber)
{
    Uint16 command = 0b0000001100000000;            // read
    Uint16 address = blockNumber << 4;

#ifdef EEPROM_CHIP_25AA040A
    // combine the address with the command
    command +=
            (address & 0b0000000011111111) +        // bits 0-7 of address
            ((address & 0b0000000100000000) << 3);  // bit 8 of address

    // send the command-address
    configureSpiBus16Bit();
    this->spiBus->sendWord(command);
#endif

#ifdef EEPROM_CHIP_AT25080B
    // send the command
    configureSpiBus8Bit();
    this->spiBus->sendWord(command);

    // send the address
    configureSpiBus16Bit();
    this->spiBus->sendWord(address);
#endif
}

void EEPROM :: sendWriteCommand(Uint16 blockNumber)
{
    Uint16 command = 0b0000001000000000;            // write
    Uint16 address = blockNumber << 4;

#ifdef EEPROM_CHIP_25AA040A
    // combine the address with the command
    command +=
            (address & 0b0000000011111111) +        // bits 0-7 of address
            ((address & 0b0000000100000000) << 3);  // bit 8 of address

    // send the command-address
    configureSpiBus16Bit();
    this->spiBus->sendWord(command);
#endif

#ifdef EEPROM_CHIP_AT25080B
    // send the command
    configureSpiBus8Bit();
    this->spiBus->sendWord(command);

    // send the address
    configureSpiBus16Bit();
    this->spiBus->sendWord(address);
#endif
}

void EEPROM :: receivePage(Uint16 pageSize, Uint16 *buffer)
{
    configureSpiBus16Bit();

    for( Uint16 i=0; i < pageSize; i++ ) {
        buffer[i] = this->spiBus->receiveWord();
    }
}

void EEPROM :: sendPage(Uint16 pageSize, Uint16 *buffer)
{
    configureSpiBus16Bit();

    for( Uint16 i=0; i < pageSize; i++ ) {
        this->spiBus->sendWord(buffer[i]);
    }
}

bool EEPROM :: readPage(Uint16 pageNum, Uint16 *buffer)
{
    CS_ASSERT;
    sendReadCommand(pageNum);
    receivePage(EEPROM_PAGE_SIZE, buffer);
    CS_RELEASE;
    DELAY_US(CS_RISE_TIME_US);

    return true;
}

bool EEPROM :: writePage(Uint16 pageNum, Uint16 *buffer)
{
    setWriteLatch();

    CS_ASSERT;
    sendWriteCommand(pageNum);
    sendPage(EEPROM_PAGE_SIZE, buffer);
    CS_RELEASE;
    DELAY_US(CS_RISE_TIME_US);

    waitForWriteCycle();

    return true;
}
#endif
