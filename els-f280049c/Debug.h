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

#ifndef __DEBUG_H
#define __DEBUG_H

#include "driverlib.h"
#include "device.h"

class Debug
{
public:
    Debug(void);
    void initHardware(void);

    /*
    // analyzer pin 1
    void begin1( void );
    void end1( void );

    // analyzer pin 2
    void begin2( void );
    void end2( void );
    */

    // LEDs on board
    void toggle_led_1(void);
    void toggle_led_2(void);
};

inline void Debug::toggle_led_1(void)
{
    GPIO_togglePin(23);
}

inline void Debug::toggle_led_2(void)
{
    GPIO_togglePin(34);
}

/*
inline void Debug :: begin1( void )
{
    GPIO_writePin(2, 1);
}

inline void Debug :: end1( void )
{
    GPIO_writePin(2, 0);
}

inline void Debug :: begin2( void )
{
    GPIO_writePin(3, 1);
}

inline void Debug :: end2( void )
{
    GPIO_writePin(3, 0);
}
*/

#endif // __DEBUG_H
