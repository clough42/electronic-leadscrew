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

#ifndef __TABLES_H
#define __TABLES_H

typedef struct FEED_THREAD
{
    const char *display;
    Uint32 numerator;
    Uint32 denominator;
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
    const FEED_THREAD *select(Uint16 index);
    Uint16 count(void) { return this->numRows; }
    Uint16 index(void) { return this->selectedRow; }
};


class FeedTableFactory
{
private:
    FeedTable inchThreads;
    FeedTable inchFeeds;
    FeedTable metricThreads;
    FeedTable metricFeeds;

public:
    FeedTableFactory(void);

    FeedTable *getFeedTable(bool metric, bool thread);
};


#endif // __TABLES_H
