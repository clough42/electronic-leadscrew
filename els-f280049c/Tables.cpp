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

#include "els.h"


//
// INCH THREAD DEFINITIONS
//
// Each row in the table defines a standard imperial thread, with the display data,
// LED indicator states and gear ratio fraction to use.
//
#if defined(LEADSCREW_TPI)
#define TPI_NUMERATOR(tpi) ((Uint32)LEADSCREW_TPI*STEPPER_RESOLUTION*STEPPER_MICROSTEPS*10)
#define TPI_DENOMINATOR(tpi) ((Uint32)tpi*ENCODER_RESOLUTION)
#endif
#if defined(LEADSCREW_HMM)
#define TPI_NUMERATOR(tpi) ((Uint32)254*100*STEPPER_RESOLUTION*STEPPER_MICROSTEPS)
#define TPI_DENOMINATOR(tpi) ((Uint32)tpi*ENCODER_RESOLUTION*LEADSCREW_HMM)
#endif
#define TPI_FRACTION(tpi) .numerator = TPI_NUMERATOR(tpi), .denominator = TPI_DENOMINATOR(tpi)

const FEED_THREAD inch_thread_table[] =
{
 { .display = "8 tpi",    TPI_FRACTION(80) },
 { .display = "9 tpi",    TPI_FRACTION(90) },
 { .display = "10 tpi",   TPI_FRACTION(100) },
 { .display = "11 tpi",   TPI_FRACTION(110) },
 { .display = "11.5 tpi", TPI_FRACTION(115) },
 { .display = "12 tpi",   TPI_FRACTION(120) },
 { .display = "13 tpi",   TPI_FRACTION(130) },
 { .display = "14 tpi",   TPI_FRACTION(140) },
 { .display = "16 tpi",   TPI_FRACTION(160) },
 { .display = "18 tpi",   TPI_FRACTION(180) },
 { .display = "19 tpi",   TPI_FRACTION(190) },
 { .display = "20 tpi",   TPI_FRACTION(200) },
 { .display = "24 tpi",   TPI_FRACTION(240) },
 { .display = "26 tpi",   TPI_FRACTION(260) },
 { .display = "27 tpi",   TPI_FRACTION(270) },
 { .display = "28 tpi",   TPI_FRACTION(280) },
 { .display = "32 tpi",   TPI_FRACTION(320) },
 { .display = "36 tpi",   TPI_FRACTION(360) },
 { .display = "40 tpi",   TPI_FRACTION(400) },
 { .display = "44 tpi",   TPI_FRACTION(440) },
 { .display = "48 tpi",   TPI_FRACTION(480) },
 { .display = "56 tpi",   TPI_FRACTION(560) },
 { .display = "64 tpi",   TPI_FRACTION(640) },
 { .display = "72 tpi",   TPI_FRACTION(720) },
 { .display = "80 tpi",   TPI_FRACTION(800) },
};



//
// INCH FEED DEFINITIONS
//
// Each row in the table defines a standard imperial feed rate, with the display data,
// LED indicator states and gear ratio fraction to use.
//

#if defined(LEADSCREW_TPI)
#define THOU_IN_NUMERATOR(thou) ((Uint32)thou*LEADSCREW_TPI*STEPPER_RESOLUTION*STEPPER_MICROSTEPS)
#define THOU_IN_DENOMINATOR(thou) ((Uint32)ENCODER_RESOLUTION*1000)
#endif
#if defined(LEADSCREW_HMM)
#define THOU_IN_NUMERATOR(thou) ((Uint32)thou*254*STEPPER_RESOLUTION*STEPPER_MICROSTEPS)
#define THOU_IN_DENOMINATOR(thou) ((Uint32)ENCODER_RESOLUTION*100*LEADSCREW_HMM)
#endif
#define THOU_IN_FRACTION(thou) .numerator = THOU_IN_NUMERATOR(thou), .denominator = THOU_IN_DENOMINATOR(thou)

const FEED_THREAD inch_feed_table[] =
{
 { .display = "0.001in", THOU_IN_FRACTION(1) },
 { .display = "0.002in", THOU_IN_FRACTION(2) },
 { .display = "0.003in", THOU_IN_FRACTION(3) },
 { .display = "0.004in", THOU_IN_FRACTION(4) },
 { .display = "0.005in", THOU_IN_FRACTION(5) },
 { .display = "0.006in", THOU_IN_FRACTION(6) },
 { .display = "0.007in", THOU_IN_FRACTION(7) },
 { .display = "0.008in", THOU_IN_FRACTION(8) },
 { .display = "0.009in", THOU_IN_FRACTION(9) },
 { .display = "0.010in", THOU_IN_FRACTION(10) },
 { .display = "0.011in", THOU_IN_FRACTION(11) },
 { .display = "0.012in", THOU_IN_FRACTION(12) },
 { .display = "0.013in", THOU_IN_FRACTION(13) },
 { .display = "0.015in", THOU_IN_FRACTION(15) },
 { .display = "0.017in", THOU_IN_FRACTION(17) },
 { .display = "0.020in", THOU_IN_FRACTION(20) },
 { .display = "0.023in", THOU_IN_FRACTION(23) },
 { .display = "0.026in", THOU_IN_FRACTION(26) },
 { .display = "0.030in", THOU_IN_FRACTION(30) },
 { .display = "0.035in", THOU_IN_FRACTION(35) },
 { .display = "0.040in", THOU_IN_FRACTION(40) },
};




//
// METRIC THREAD DEFINITIONS
//
// Each row in the table defines a standard metric thread, with the display data,
// LED indicator states and gear ratio fraction to use.
//
#if defined(LEADSCREW_TPI)
#define HMM_NUMERATOR(hmm) ((Uint32)hmm*10*LEADSCREW_TPI*STEPPER_RESOLUTION*STEPPER_MICROSTEPS)
#define HMM_DENOMINATOR(hmm) ((Uint32)ENCODER_RESOLUTION*254*100)
#endif
#if defined(LEADSCREW_HMM)
#define HMM_NUMERATOR(hmm) ((Uint32)hmm*STEPPER_RESOLUTION*STEPPER_MICROSTEPS)
#define HMM_DENOMINATOR(hmm) ((Uint32)ENCODER_RESOLUTION*LEADSCREW_HMM)
#endif
#define HMM_FRACTION(hmm) .numerator = HMM_NUMERATOR(hmm), .denominator = HMM_DENOMINATOR(hmm)

const FEED_THREAD metric_thread_table[] =
{
 { .display = "0.2mm",  HMM_FRACTION(20) },
 { .display = "0.25mm", HMM_FRACTION(25) },
 { .display = "0.3mm",  HMM_FRACTION(30) },
 { .display = "0.35mm", HMM_FRACTION(35) },
 { .display = "0.4mm",  HMM_FRACTION(40) },
 { .display = "0.45mm", HMM_FRACTION(45) },
 { .display = "0.5mm",  HMM_FRACTION(50) },
 { .display = "0.6mm",  HMM_FRACTION(60) },
 { .display = "0.7mm",  HMM_FRACTION(70) },
 { .display = "0.75mm", HMM_FRACTION(75) },
 { .display = "0.8mm",  HMM_FRACTION(80) },
 { .display = "1mm",    HMM_FRACTION(100) },
 { .display = "1.25mm", HMM_FRACTION(125) },
 { .display = "1.5mm",  HMM_FRACTION(150) },
 { .display = "1.75mm", HMM_FRACTION(175) },
 { .display = "2.0mm",  HMM_FRACTION(200) },
 { .display = "2.5mm",  HMM_FRACTION(250) },
 { .display = "3mm",    HMM_FRACTION(300) },
 { .display = "3.5mm",  HMM_FRACTION(350) },
 { .display = "4mm",    HMM_FRACTION(400) },
 { .display = "4.5mm",  HMM_FRACTION(450) },
 { .display = "5mm",    HMM_FRACTION(500) },
 { .display = "5.5mm",  HMM_FRACTION(550) },
 { .display = "6mm",    HMM_FRACTION(600) },
};



//
// METRIC FEED DEFINITIONS
//
// Each row in the table defines a standard metric feed, with the display data,
// LED indicator states and gear ratio fraction to use.
//
const FEED_THREAD metric_feed_table[] =
{
 { .display = "0.02mm", HMM_FRACTION(2) },
 { .display = "0.05mm", HMM_FRACTION(5) },
 { .display = "0.07mm", HMM_FRACTION(7) },
 { .display = "0.1mm",  HMM_FRACTION(10) },
 { .display = "0.12mm", HMM_FRACTION(12) },
 { .display = "0.15mm", HMM_FRACTION(15) },
 { .display = "0.17mm", HMM_FRACTION(17) },
 { .display = "0.2mm",  HMM_FRACTION(20) },
 { .display = "0.22mm", HMM_FRACTION(22) },
 { .display = "0.25mm", HMM_FRACTION(25) },
 { .display = "0.27mm", HMM_FRACTION(27) },
 { .display = "0.3mm",  HMM_FRACTION(30) },
 { .display = "0.35mm", HMM_FRACTION(35) },
 { .display = "0.4mm",  HMM_FRACTION(40) },
 { .display = "0.45mm", HMM_FRACTION(45) },
 { .display = "0.5mm",  HMM_FRACTION(50) },
 { .display = "0.55mm", HMM_FRACTION(55) },
 { .display = "0.6mm",  HMM_FRACTION(60) },
 { .display = "0.7mm",  HMM_FRACTION(70) },
 { .display = "0.85mm", HMM_FRACTION(85) },
 { .display = "1.0mm",  HMM_FRACTION(100) },
};





FeedTable::FeedTable(const FEED_THREAD *table, Uint16 numRows, Uint16 defaultSelection)
{
    this->table = table;
    this->numRows = numRows;
    this->selectedRow = defaultSelection;
}

const FEED_THREAD *FeedTable :: current(void)
{
    return &table[selectedRow];
}

const FEED_THREAD *FeedTable :: next(void)
{
    if( this->selectedRow < this->numRows - 1 )
    {
        this->selectedRow++;
    }
    return this->current();
}

const FEED_THREAD *FeedTable :: previous(void)
{
    if( this->selectedRow > 0 )
    {
        this->selectedRow--;
    }
    return this->current();
}

const FEED_THREAD *FeedTable :: select(Uint16 index)
{
    if( index < this->numRows )
    {
        this->selectedRow = index;
    }
    return this->current();
}

FeedTableFactory::FeedTableFactory(void):
        inchThreads(inch_thread_table, sizeof(inch_thread_table)/sizeof(inch_thread_table[0]), 12),
        inchFeeds(inch_feed_table, sizeof(inch_feed_table)/sizeof(inch_feed_table[0]), 4),
        metricThreads(metric_thread_table, sizeof(metric_thread_table)/sizeof(metric_thread_table[0]), 6),
        metricFeeds(metric_feed_table, sizeof(metric_feed_table)/sizeof(metric_feed_table[0]), 4)
{
}

FeedTable *FeedTableFactory::getFeedTable(bool metric, bool thread)
{
    if( metric )
    {
        if( thread )
        {
            return &this->metricThreads;
        }
        else
        {
            return &this->metricFeeds;
        }
    }
    else
    {
        if( thread )
        {
            return &this->inchThreads;
        }
        else
        {
            return &this->inchFeeds;
        }
    }

}
