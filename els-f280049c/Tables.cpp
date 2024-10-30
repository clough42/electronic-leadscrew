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


#include "Tables.h"


//
// INCH THREAD DEFINITIONS
//
// Each row in the table defines a standard imperial thread, with the display data,
// LED indicator states and gear ratio fraction to use. The units for TPI_FRACTION
// are threads per 100 inches.
//
#if defined(LEADSCREW_TPI)
#define TPI_NUMERATOR(tpi) ((Uint64)LEADSCREW_TPI*STEPPER_RESOLUTION*STEPPER_MICROSTEPS*100)
#define TPI_DENOMINATOR(tpi) ((Uint64)tpi*ENCODER_RESOLUTION)
#endif
#if defined(LEADSCREW_HMM)
#define TPI_NUMERATOR(tpi) ((Uint64)254*1000*STEPPER_RESOLUTION*STEPPER_MICROSTEPS)
#define TPI_DENOMINATOR(tpi) ((Uint64)tpi*ENCODER_RESOLUTION*LEADSCREW_HMM)
#endif
#define TPI_FRACTION(tpi) .numerator = TPI_NUMERATOR(tpi), .denominator = TPI_DENOMINATOR(tpi)

const FEED_THREAD inch_thread_table[] =
{
#ifdef EXTENDED_INCH_THREADS
 { .display = {BLANK, FOUR,       BLANK, BLANK},   .leds = LED_THREAD | LED_TPI, TPI_FRACTION(400) },
 { .display = {BLANK, FOUR|POINT, FIVE,  BLANK},   .leds = LED_THREAD | LED_TPI, TPI_FRACTION(450) },
 { .display = {BLANK, FIVE,       BLANK, BLANK},   .leds = LED_THREAD | LED_TPI, TPI_FRACTION(500) },
 { .display = {BLANK, FIVE|POINT, FIVE,  BLANK},   .leds = LED_THREAD | LED_TPI, TPI_FRACTION(550) },
 { .display = {BLANK, FIVE|POINT, SEVEN, FIVE},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(575) },
 { .display = {BLANK, SIX,        BLANK, BLANK},   .leds = LED_THREAD | LED_TPI, TPI_FRACTION(600) },
 { .display = {BLANK, SIX|POINT,  FIVE,  BLANK},   .leds = LED_THREAD | LED_TPI, TPI_FRACTION(650) },
 { .display = {BLANK, SEVEN,      BLANK, BLANK},   .leds = LED_THREAD | LED_TPI, TPI_FRACTION(700) },
#endif
 { .display = {BLANK, EIGHT,      BLANK, BLANK},   .leds = LED_THREAD | LED_TPI, TPI_FRACTION(800) },
 { .display = {BLANK, NINE,       BLANK, BLANK},   .leds = LED_THREAD | LED_TPI, TPI_FRACTION(900) },
#ifdef EXTENDED_INCH_THREADS
 { .display = {BLANK, NINE|POINT, FIVE,  BLANK},   .leds = LED_THREAD | LED_TPI, TPI_FRACTION(950) },
#endif
 { .display = {BLANK, ONE,   ZERO,      BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(1000) },
 { .display = {BLANK, ONE,   ONE,       BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(1100) },
 { .display = {BLANK, ONE,   ONE|POINT, FIVE},     .leds = LED_THREAD | LED_TPI, TPI_FRACTION(1150) },
 { .display = {BLANK, ONE,   TWO,       BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(1200) },
 { .display = {BLANK, ONE,   THREE,     BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(1300) },
 { .display = {BLANK, ONE,   FOUR,      BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(1400) },
 { .display = {BLANK, ONE,   SIX,       BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(1600) },
 { .display = {BLANK, ONE,   EIGHT,     BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(1800) },
 { .display = {BLANK, ONE,   NINE,      BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(1900) },
 { .display = {BLANK, TWO,   ZERO,      BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(2000) },
#ifdef EXTENDED_INCH_THREADS
 { .display = {BLANK, TWO,   TWO,       BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(2200) },
 { .display = {BLANK, TWO,   THREE,     BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(2300) },
#endif
 { .display = {BLANK, TWO,   FOUR,      BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(2400) },
 { .display = {BLANK, TWO,   SIX,       BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(2600) },
 { .display = {BLANK, TWO,   SEVEN,     BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(2700) },
 { .display = {BLANK, TWO,   EIGHT,     BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(2800) },
 { .display = {BLANK, THREE, TWO,       BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(3200) },
 { .display = {BLANK, THREE, SIX,       BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(3600) },
#ifdef EXTENDED_INCH_THREADS
 { .display = {BLANK, THREE, EIGHT,     BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(3800) },
#endif
 { .display = {BLANK, FOUR,  ZERO,      BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(4000) },
 { .display = {BLANK, FOUR,  FOUR,      BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(4400) },
#ifdef EXTENDED_INCH_THREADS
 { .display = {BLANK, FOUR,  SIX,       BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(4600) },
#endif
 { .display = {BLANK, FOUR,  EIGHT,     BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(4800) },
 { .display = {BLANK, FIVE,  SIX,       BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(5600) },
 { .display = {BLANK, SIX,   FOUR,      BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(6400) },
 { .display = {BLANK, SEVEN, TWO,       BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(7200) },
 { .display = {BLANK, EIGHT, ZERO,      BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(8000) },
#ifdef EXTENDED_INCH_THREADS
 { .display = {BLANK, EIGHT, EIGHT,     BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(8800) },
 { .display = {BLANK, NINE,  TWO,       BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(9200) },
 { .display = {BLANK, NINE,  SIX,       BLANK},    .leds = LED_THREAD | LED_TPI, TPI_FRACTION(9600) },
// shift the display to keep an initial BLANK to avoid running into RPM
 { .display = {BLANK, ONE,   ZERO,      FOUR},     .leds = LED_THREAD | LED_TPI, TPI_FRACTION(10400) },
 { .display = {BLANK, ONE,   ONE,       TWO},      .leds = LED_THREAD | LED_TPI, TPI_FRACTION(11200) },
#endif
};



//
// INCH FEED DEFINITIONS
//
// Each row in the table defines a standard imperial feed rate, with the display data,
// LED indicator states and gear ratio fraction to use.
//

#if defined(LEADSCREW_TPI)
#define THOU_IN_NUMERATOR(thou) ((Uint64)thou*LEADSCREW_TPI*STEPPER_RESOLUTION_FEED*STEPPER_MICROSTEPS_FEED)
#define THOU_IN_DENOMINATOR(thou) ((Uint64)ENCODER_RESOLUTION*1000)
#endif
#if defined(LEADSCREW_HMM)
#define THOU_IN_NUMERATOR(thou) ((Uint64)thou*254*STEPPER_RESOLUTION_FEED*STEPPER_MICROSTEPS_FEED)
#define THOU_IN_DENOMINATOR(thou) ((Uint64)ENCODER_RESOLUTION*100*LEADSCREW_HMM)
#endif
#define THOU_IN_FRACTION(thou) .numerator = THOU_IN_NUMERATOR(thou), .denominator = THOU_IN_DENOMINATOR(thou)

const FEED_THREAD inch_feed_table[] =
{
 { .display = {POINT, ZERO, ZERO,  ONE},    .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(1) },
 { .display = {POINT, ZERO, ZERO,  TWO},    .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(2) },
 { .display = {POINT, ZERO, ZERO,  THREE},  .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(3) },
 { .display = {POINT, ZERO, ZERO,  FOUR},   .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(4) },
 { .display = {POINT, ZERO, ZERO,  FIVE},   .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(5) },
 { .display = {POINT, ZERO, ZERO,  SIX},    .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(6) },
 { .display = {POINT, ZERO, ZERO,  SEVEN},  .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(7) },
 { .display = {POINT, ZERO, ZERO,  EIGHT},  .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(8) },
 { .display = {POINT, ZERO, ZERO,  NINE},   .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(9) },
 { .display = {POINT, ZERO, ONE,   ZERO},   .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(10) },
 { .display = {POINT, ZERO, ONE,   ONE},    .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(11) },
 { .display = {POINT, ZERO, ONE,   TWO},    .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(12) },
 { .display = {POINT, ZERO, ONE,   THREE},  .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(13) },
 { .display = {POINT, ZERO, ONE,   FIVE},   .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(15) },
 { .display = {POINT, ZERO, ONE,   SEVEN},  .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(17) },
 { .display = {POINT, ZERO, TWO,   ZERO},   .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(20) },
 { .display = {POINT, ZERO, TWO,   THREE},  .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(23) },
 { .display = {POINT, ZERO, TWO,   SIX},    .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(26) },
 { .display = {POINT, ZERO, THREE, ZERO},   .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(30) },
 { .display = {POINT, ZERO, THREE, FIVE},   .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(35) },
 { .display = {POINT, ZERO, FOUR,  ZERO},   .leds = LED_FEED | LED_INCH, THOU_IN_FRACTION(40) },
};




//
// METRIC THREAD DEFINITIONS
//
// Each row in the table defines a standard metric thread, with the display data,
// LED indicator states and gear ratio fraction to use.
//
#if defined(LEADSCREW_TPI)
#define HMM_NUMERATOR(hmm) ((Uint64)hmm*LEADSCREW_TPI*STEPPER_RESOLUTION*STEPPER_MICROSTEPS)
#define HMM_DENOMINATOR(hmm) ((Uint64)ENCODER_RESOLUTION*254*100)
#endif
#if defined(LEADSCREW_HMM)
#define HMM_NUMERATOR(hmm) ((Uint64)hmm*STEPPER_RESOLUTION*STEPPER_MICROSTEPS)
#define HMM_DENOMINATOR(hmm) ((Uint64)ENCODER_RESOLUTION*LEADSCREW_HMM*10)
#endif
#define HMM_FRACTION(hmm) .numerator = HMM_NUMERATOR(hmm), .denominator = HMM_DENOMINATOR(hmm)

const FEED_THREAD metric_thread_table[] =
{
#ifdef EXTENDED_METRIC_THREADS
 { .display = {POINT,  ONE,   BLANK, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(100) },
 { .display = {POINT,  ONE,   TWO,   FIVE},  .leds = LED_THREAD | LED_MM, HMM_FRACTION(125) },
 { .display = {POINT,  ONE,   FIVE,  BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(150) },
#endif
 { .display = {POINT,  TWO,   BLANK, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(200) },
#ifdef EXTENDED_METRIC_THREADS
 { .display = {POINT,  TWO,   TWO,   FIVE},  .leds = LED_THREAD | LED_MM, HMM_FRACTION(225) },
#endif
 { .display = {POINT,  TWO,   FIVE,  BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(250) },
 { .display = {POINT,  THREE, BLANK, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(300) },
 { .display = {POINT,  THREE, FIVE,  BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(350) },
 { .display = {POINT,  FOUR,  BLANK, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(400) },
 { .display = {POINT,  FOUR,  FIVE,  BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(450) },
 { .display = {POINT,  FIVE,  BLANK, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(500) },
#ifdef EXTENDED_METRIC_THREADS
 { .display = {POINT,  FIVE,  FIVE,  BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(550) },
#endif
 { .display = {POINT,  SIX,   BLANK, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(600) },
#ifdef EXTENDED_METRIC_THREADS
 { .display = {POINT,  SIX,   FIVE,  BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(650) },
#endif
 { .display = {POINT,  SEVEN, BLANK, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(700) },
 { .display = {POINT,  SEVEN, FIVE, BLANK},  .leds = LED_THREAD | LED_MM, HMM_FRACTION(750) },
 { .display = {POINT,  EIGHT, BLANK, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(800) },
#ifdef EXTENDED_METRIC_THREADS
 { .display = {POINT,  EIGHT, SEVEN, FIVE},  .leds = LED_THREAD | LED_MM, HMM_FRACTION(875) },
 { .display = {POINT,  NINE,  BLANK, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(900) },
#endif
 { .display = {BLANK, ONE,           BLANK, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(1000) },
#ifdef EXTENDED_METRIC_THREADS
 { .display = {BLANK, ONE | POINT,   ONE,   BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(1100) },
 { .display = {BLANK, ONE | POINT,   TWO,   BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(1200) },
#endif
 { .display = {BLANK, ONE | POINT,   TWO,   FIVE},  .leds = LED_THREAD | LED_MM, HMM_FRACTION(1250) },
#ifdef EXTENDED_METRIC_THREADS
 { .display = {BLANK, ONE | POINT,   THREE, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(1300) },
 { .display = {BLANK, ONE | POINT,   FOUR,  BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(1400) },
#endif
 { .display = {BLANK, ONE | POINT,   FIVE,  BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(1500) },
#ifdef EXTENDED_METRIC_THREADS
 { .display = {BLANK, ONE | POINT,   SIX,   BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(1600) },
#endif
 { .display = {BLANK, ONE | POINT,   SEVEN, FIVE},  .leds = LED_THREAD | LED_MM, HMM_FRACTION(1750) },
#ifdef EXTENDED_METRIC_THREADS
 { .display = {BLANK, ONE | POINT,   EIGHT, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(1800) },
#endif
 { .display = {BLANK, TWO,           BLANK, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(2000) },
#ifdef EXTENDED_METRIC_THREADS
 { .display = {BLANK, TWO | POINT,   TWO,   FIVE},  .leds = LED_THREAD | LED_MM, HMM_FRACTION(2250) },
#endif
 { .display = {BLANK, TWO | POINT,   FIVE,  BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(2500) },
#ifdef EXTENDED_METRIC_THREADS
 { .display = {BLANK, TWO | POINT,   SEVEN, FIVE},  .leds = LED_THREAD | LED_MM, HMM_FRACTION(2750) },
#endif
 { .display = {BLANK, THREE,         BLANK, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(3000) },
#ifdef EXTENDED_METRIC_THREADS
 { .display = {BLANK, THREE | POINT, TWO,   FIVE},  .leds = LED_THREAD | LED_MM, HMM_FRACTION(3250) },
#endif
 { .display = {BLANK, THREE | POINT, FIVE,  BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(3500) },
 { .display = {BLANK, FOUR,          BLANK, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(4000) },
 { .display = {BLANK, FOUR | POINT,  FIVE,  BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(4500) },
 { .display = {BLANK, FIVE,          BLANK, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(5000) },
 { .display = {BLANK, FIVE | POINT,  FIVE,  BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(5500) },
#ifdef EXTENDED_METRIC_THREADS
 { .display = {BLANK, FIVE | POINT,  SEVEN, FIVE},  .leds = LED_THREAD | LED_MM, HMM_FRACTION(5750) },
#endif
 { .display = {BLANK, SIX,           BLANK, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(6000) },
#ifdef EXTENDED_METRIC_THREADS
 { .display = {BLANK, SIX | POINT,   FIVE,  BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(6500) },
 { .display = {BLANK, SEVEN,         BLANK, BLANK}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(7000) },
#endif
};



//
// METRIC FEED DEFINITIONS
//
// Each row in the table defines a standard metric feed, with the display data,
// LED indicator states and gear ratio fraction to use.
//
#if defined(LEADSCREW_TPI)
#define HMM_NUMERATOR_FEED(hmm) ((Uint64)hmm*10*LEADSCREW_TPI*STEPPER_RESOLUTION_FEED*STEPPER_MICROSTEPS_FEED)
#define HMM_DENOMINATOR_FEED(hmm) ((Uint64)ENCODER_RESOLUTION*254*100)
#endif
#if defined(LEADSCREW_HMM)
#define HMM_NUMERATOR_FEED(hmm) ((Uint64)hmm*STEPPER_RESOLUTION_FEED*STEPPER_MICROSTEPS_FEED)
#define HMM_DENOMINATOR_FEED(hmm) ((Uint64)ENCODER_RESOLUTION*LEADSCREW_HMM)
#endif
#define HMM_FRACTION_FEED(hmm) .numerator = HMM_NUMERATOR_FEED(hmm), .denominator = HMM_DENOMINATOR_FEED(hmm)

const FEED_THREAD metric_feed_table[] =
{
 { .display = {BLANK, ZERO | POINT, ZERO,  TWO},   .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(2) },
 { .display = {BLANK, ZERO | POINT, ZERO,  FIVE},  .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(5) },
 { .display = {BLANK, ZERO | POINT, ZERO,  SEVEN}, .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(7) },
 { .display = {BLANK, ZERO | POINT, ONE,   ZERO},  .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(10) },
 { .display = {BLANK, ZERO | POINT, ONE,   TWO},   .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(12) },
 { .display = {BLANK, ZERO | POINT, ONE,   FIVE},  .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(15) },
 { .display = {BLANK, ZERO | POINT, ONE,   SEVEN}, .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(17) },
 { .display = {BLANK, ZERO | POINT, TWO,   ZERO},  .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(20) },
 { .display = {BLANK, ZERO | POINT, TWO,   TWO},   .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(22) },
 { .display = {BLANK, ZERO | POINT, TWO,   FIVE},  .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(25) },
 { .display = {BLANK, ZERO | POINT, TWO,   SEVEN}, .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(27) },
 { .display = {BLANK, ZERO | POINT, THREE, ZERO},  .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(30) },
 { .display = {BLANK, ZERO | POINT, THREE, FIVE},  .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(35) },
 { .display = {BLANK, ZERO | POINT, FOUR,  ZERO},  .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(40) },
 { .display = {BLANK, ZERO | POINT, FOUR,  FIVE},  .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(45) },
 { .display = {BLANK, ZERO | POINT, FIVE,  ZERO},  .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(50) },
 { .display = {BLANK, ZERO | POINT, FIVE,  FIVE},  .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(55) },
 { .display = {BLANK, ZERO | POINT, SIX,   ZERO},  .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(60) },
 { .display = {BLANK, ZERO | POINT, SEVEN, ZERO},  .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(70) },
 { .display = {BLANK, ZERO | POINT, EIGHT, FIVE},  .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(85) },
 { .display = {BLANK, ONE | POINT,  ZERO,  ZERO},  .leds = LED_FEED | LED_MM, HMM_FRACTION_FEED(100) },
};


// *entry* for custom feed
FEED_THREAD custom_feed = { .display = {BLANK, ONE | POINT, ZERO, ZERO}, .leds = LED_THREAD | LED_MM, HMM_FRACTION(100) };

// when set overrides table with custom feed
bool    FeedTableFactory::useCustomPitch;


FeedTable::FeedTable(const FEED_THREAD *table, Uint16 numRows, Uint16 defaultSelection)
{
    this->table = table;
    this->numRows = numRows;
    this->selectedRow = defaultSelection;
}

const FEED_THREAD *FeedTable :: current(void)
{
    // check for custom feed
    if (FeedTableFactory::useCustomPitch)
        return &custom_feed;
    else
        return &table[selectedRow];
}

const FEED_THREAD *FeedTable :: next(void)
{
    // if in custom pitch then first step out
    if (FeedTableFactory::useCustomPitch)
        FeedTableFactory::useCustomPitch = false;
    else
    {
        if( this->selectedRow < this->numRows - 1 )
        {
            this->selectedRow++;
        }
    }
    return this->current();
}

const FEED_THREAD *FeedTable :: previous(void)
{
    // if in custom pitch then first step out
    if (FeedTableFactory::useCustomPitch)
        FeedTableFactory::useCustomPitch = false;
    else
    {
        if( this->selectedRow > 0 )
        {
            this->selectedRow--;
        }
    }
    return this->current();
}

FeedTableFactory::FeedTableFactory(void):
        inchThreads(inch_thread_table, sizeof(inch_thread_table)/sizeof(inch_thread_table[0]), INITIAL_INCH_THREAD_INDEX),
        inchFeeds(inch_feed_table, sizeof(inch_feed_table)/sizeof(inch_feed_table[0]), INITIAL_INCH_FEED_INDEX),
        metricThreads(metric_thread_table, sizeof(metric_thread_table)/sizeof(metric_thread_table[0]), INITIAL_METRIC_THREAD_INDEX),
        metricFeeds(metric_feed_table, sizeof(metric_feed_table)/sizeof(metric_feed_table[0]), INITIAL_METRIC_FEED_INDEX)
{
    this->customPitch = 100;
    this->useCustomPitch = false;
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


// custom pitch code


void FeedTableFactory :: setCustomPitch(Uint16 pitch)
{
    // calculate the fraction feed
    custom_feed.numerator = HMM_NUMERATOR(1) * (Uint64) pitch;
    custom_feed.denominator = HMM_DENOMINATOR(1);

    // fill in the three digits for the display
    Uint16 digit = pitch / 100;
    pitch = pitch - (digit * 100);
    custom_feed.display[1] = valueToDigit(digit) | POINT;

    digit = pitch / 10;
    pitch = pitch - (digit * 10);
    custom_feed.display[2] = valueToDigit(digit);

    custom_feed.display[3] = valueToDigit(pitch);
}


// convert a numeric value to a LED digit
Uint16 FeedTableFactory :: valueToDigit(Uint16 value)
{
    switch (value)
    {
        case 0: return ZERO;
        case 1: return ONE;
        case 2: return TWO;
        case 3: return THREE;
        case 4: return FOUR;
        case 5: return FIVE;
        case 6: return SIX;
        case 7: return SEVEN;
        case 8: return EIGHT;
        case 9: return NINE;
        case 10: return LETTER_A;
        case 11: return LETTER_B;
        case 12: return LETTER_C;
        case 13: return LETTER_D;
        case 14: return LETTER_E;
        case 15: return LETTER_F;

        default: return BLANK;
    }
}

void FeedTableFactory :: incCustomDigit( Uint16 digit )
{
    // extract the digits and increment the appropriate one
    Uint16 pitch = this->customPitch;
    Uint16 hundreds = pitch / 100;
    pitch = pitch - (hundreds * 100);
    Uint16 tens = pitch / 10;
    Uint16 units = pitch - (tens * 10);

    if (digit == 1 && hundreds < 9)
        hundreds++;
    else if (digit == 2 && tens < 9)
        tens++;
    else if (digit == 3 && units < 9)
        units++;

    this->customPitch = hundreds * 100 + tens * 10 + units;

    setCustomPitch(this->customPitch);
    this->cursorTimer = 0;
}

void FeedTableFactory :: decCustomDigit( Uint16 digit )
{
    // extract the digits and decrement the appropriate one
    Uint16 pitch = this->customPitch;
    Uint16 hundreds = pitch / 100;
    pitch = pitch - (hundreds * 100);
    Uint16 tens = pitch / 10;
    Uint16 units = pitch - (tens * 10);

    if (digit == 1 && hundreds > 0)
        hundreds--;
    else if (digit == 2 && tens > 0)
        tens--;
    else if (digit == 3 && units > 0)
        units--;

    this->customPitch = hundreds * 100 + tens * 10 + units;

    setCustomPitch(this->customPitch);
    this->cursorTimer = 0;
}


void FeedTableFactory :: flashCustomDigit( Uint16 digit )
{
    this->cursorTimer++;

    if (this->cursorTimer == 0x20)
    {
        custom_feed.display[digit] = BLANK;
        custom_feed.display[1] |= POINT;
    }

    if (this->cursorTimer == 0x30)
    {
        setCustomPitch(this->customPitch);
        this->cursorTimer = 0;
    }
}


void FeedTableFactory :: flashCustomOff()
{
    setCustomPitch(this->customPitch);
    this->cursorTimer = 0;
}
