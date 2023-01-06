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

#include "TestEEPROM.h"

TestEEPROM :: TestEEPROM( EEPROM *eeprom )
{
    this->eeprom = eeprom;
    this->count = 0;
}

void TestEEPROM :: initHardware(void)
{

}

bool TestEEPROM::checkPage(Uint16 pageNum, Uint16 buf1[EEPROM_PAGE_SIZE])
{
    Uint16 buf2[EEPROM_PAGE_SIZE];
    bool match = true;

    for(int i = 0; i < EEPROM_PAGE_SIZE; i++)
    {
        buf2[i] = 0;
    }

    this->eeprom->readPage(pageNum, buf2);

    for (int i = 0; i < EEPROM_PAGE_SIZE; i++)
    {
        if (buf1[i] != buf2[i])
        {
            match = false;
        }
    }
    return match;
}

void TestEEPROM :: test(LED_REG *output)
{
    Uint16 buf1[EEPROM_PAGE_SIZE];

    for(int i = 0; i < EEPROM_PAGE_SIZE; i++)
    {
        buf1[i] = count++;
    }

    this->eeprom->writePage(63, buf1);
    bool test1K = checkPage(7, buf1);    // should not collide for an 8K EEPROM
    bool test2K = checkPage(15, buf1);   // should not collide for an 8K EEPROM
    bool test4K = checkPage(31, buf1);   // should not collide for an 8K EEPROM
    bool test8K = checkPage(63, buf1);   // should read back for an 8K EEPROM

    bool pass =
            !test1K && !test2K && !test4K && test8K;

    output->bit.EEPROM_GREEN = pass;
    output->bit.EEPROM_RED = !pass;
}
