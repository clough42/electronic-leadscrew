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

StepperDrive :: StepperDrive(void)
{
    //
    // Set up global state variables
    //
    this->currentPosition = 0;
    this->desiredPosition = 0;

    //
    // State machine starts at state zero
    //
    this->state = 0;
}

void StepperDrive :: initHardware(void)
{
    //
    // Configure GPIO pins for output
    // GPIO0 = Step
    // GPIO1 = Direction
    // GPIO6 - Enable
    // GPIO
    //
    /*
    EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 0;

    GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO1 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO6 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO7 = 0; // input

    GPIO_CLEAR_STEP;
    GPIO_CLEAR_DIRECTION;
    GPIO_SET_ENABLE;
    EDIS;
    */

    GPIO_setPinConfig(GPIO_0_GPIO0);
    GPIO_setPinConfig(GPIO_1_GPIO1);
    GPIO_setPinConfig(GPIO_6_GPIO6);
    GPIO_setPinConfig(GPIO_7_GPIO7);
    GPIO_setDirectionMode(0, GPIO_DIR_MODE_OUT);
    GPIO_setDirectionMode(1, GPIO_DIR_MODE_OUT);
    GPIO_setDirectionMode(6, GPIO_DIR_MODE_OUT);
    GPIO_setDirectionMode(7, GPIO_DIR_MODE_IN);

    GPIO_CLEAR_STEP;
    GPIO_CLEAR_DIRECTION;
    GPIO_CLEAR_ENABLE;
}






