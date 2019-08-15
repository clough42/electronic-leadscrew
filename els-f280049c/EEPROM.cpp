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
#define CS_RELEASE GpioDataRegs.GPBSET.bit.GPIO34 = 1

// Lower the EEPROM CS line
#define CS_ASSERT GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1

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

void EEPROM :: configureSpiBus( void )
{
    // configure the shared bus
    this->spiBus->setFourWire();
    this->spiBus->setSixteenBits();
}

void EEPROM :: sendReadCommand(Uint16 blockNumber)
{
    Uint16 address = blockNumber << 4;
    Uint16 command = 0b0000001100000000 +           // read
            (address & 0b0000000011111111) +        // bits 0-7 of address
            ((address & 0b0000000100000000) << 3);  // bit 8 of address

    this->spiBus->sendWord(command);
}

void EEPROM :: receivePage(Uint16 pageSize, Uint16 *buffer)
{
    for( Uint16 i=0; i < pageSize; i++ ) {
        buffer[i] = this->spiBus->receiveWord();
    }
}

void EEPROM :: sendPage(Uint16 pageSize, Uint16 *buffer)
{
    for( Uint16 i=0; i < pageSize; i++ ) {
        this->spiBus->sendWord(buffer[i]);
    }
}

bool EEPROM :: readPage(Uint16 pageNum, Uint16 *buffer)
{
    this->spiBus->setSixteenBits();
    this->spiBus->setFourWire();

    CS_ASSERT;
    sendReadCommand(pageNum);
    receivePage(EEPROM_PAGE_SIZE, buffer);
    CS_RELEASE;

    return true;
}

//bool EEPROM :: writePage(Uint16 pageNum, Uint16 *buffer)
//{
//    this->spiBus->setSixteenBits();
//    this->spiBus->setFourWire();
//
//    setWriteLatch();
//
//    CS_ASSERT;
//    sendWriteCommand(pageNum);
//    sendPage(EEPROM_PAGE_SIZE, buffer);
//    CS_RELEASE;
//
//    waitForWriteCycle();
//
//    return true;
//}
