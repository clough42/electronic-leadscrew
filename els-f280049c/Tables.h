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


#ifndef __TABLES_H
#define __TABLES_H

#include "F28x_Project.h"
#include "Configuration.h"
#include "ControlPanel.h"



typedef struct FEED_THREAD
{
    Uint16 display[4];
    union LED_REG leds;
    Uint64 numerator;
    Uint64 denominator;
} FEED_THREAD;



class FeedTable
{
private:
    const FEED_THREAD *table;
    Uint16 selectedRow;
    Uint16 numRows;

public:
    FeedTable(const FEED_THREAD *table, Uint16 numRows, Uint16 defaultSelection);

    const FEED_THREAD *current(void);
    const FEED_THREAD *next(void);
    const FEED_THREAD *previous(void);
};


class FeedTableFactory
{
private:
    FeedTable inchThreads;
    FeedTable inchFeeds;
    FeedTable metricThreads;
    FeedTable metricFeeds;

    void    setCustomPitch(Uint16 pitch);
    Uint16  customPitch;
    Uint16  cursorTimer;

public:
    FeedTableFactory(void);

    FeedTable *getFeedTable(bool metric, bool thread);

    // custom feed 'stuff'
    void flashCustomDigit( Uint16 digit );  // valid values for digit is: 1 (100's), 2 (10's) & 3 (units)
    void flashCustomOff();
    void incCustomDigit( Uint16 digit );
    void decCustomDigit( Uint16 digit );
    Uint16  valueToDigit(Uint16 value);
    static bool    useCustomPitch;
};


#endif // __TABLES_H
