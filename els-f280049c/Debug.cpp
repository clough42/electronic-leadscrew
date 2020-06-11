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

#include "Debug.h"


Debug :: Debug( void )
{

}


void Debug :: initHardware( void )
{

    /*
     * This is clough42 did it, these are GPIO outputs that you can hook up
     * to a logic probe
     *
    GPIO_setPinConfig(GPIO_2_GPIO2);
    GPIO_setDirectionMode(2, GPIO_DIR_MODE_OUT);
    GPIO_setPinConfig(GPIO_3_GPIO3);
    GPIO_setDirectionMode(3, GPIO_DIR_MODE_OUT);
     */

    // these are the two red/green LEDs on the board
    GPIO_setAnalogMode(23, GPIO_ANALOG_DISABLED);
    GPIO_setDirectionMode(23, GPIO_DIR_MODE_OUT);
    GPIO_setDirectionMode(34, GPIO_DIR_MODE_OUT);

    // start with both off
    GPIO_writePin(23, 0);
    GPIO_writePin(34, 0);
}
