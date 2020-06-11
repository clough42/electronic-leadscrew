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
#ifndef __EEPROM_H
#define __EEPROM_H

#include "Configuration.h"

#if HARDWARE_VERSION == 1
#  define EEPROM_CHIP_25AA040A
#elif HARDWARE_VERSION == 2
#  define EEPROM_CHIP_AT25080B
#else
#  error Must define a valid HARDWARE_VERSION
#endif



#define EEPROM_PAGE_SIZE 8 // 2-byte words

class EEPROM
{
private:
    // Shared SPI bus
    SPIBus *spiBus;

    Uint16 readStatusRegister( void );
    void setWriteLatch( void );
    void waitForWriteCycle( void );
    void sendReadCommand(Uint16 blockNumber);
    void sendWriteCommand(Uint16 blockNumber);
    void receivePage(Uint16 numWords, Uint16 *buffer);
    void sendPage(Uint16 numWords, Uint16 *buffer);
    void initSpi(void);
    void configureSpiBus8Bit(void);
    void configureSpiBus16Bit(void);

public:
    EEPROM(SPIBus *spiBus);

    // initialize hardware for operation
    void initHardware(void);

    bool readPage(Uint16 pageNum, Uint16 *buffer);
    bool writePage(Uint16 pageNum, Uint16 *buffer);
};


#endif // __EEPROM_H
#endif
