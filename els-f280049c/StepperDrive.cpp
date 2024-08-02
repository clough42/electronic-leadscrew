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


#include "StepperDrive.h"


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
    EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.STEP_PIN = 0;
    GpioCtrlRegs.GPAMUX1.bit.DIRECTION_PIN = 0;
    GpioCtrlRegs.GPAMUX1.bit.ENABLE_PIN = 0;
    GpioCtrlRegs.GPAMUX1.bit.ALARM_PIN = 0;

    GpioCtrlRegs.GPADIR.bit.STEP_PIN = 1;
    GpioCtrlRegs.GPADIR.bit.DIRECTION_PIN = 1;
    GpioCtrlRegs.GPADIR.bit.ENABLE_PIN = 1;
    GpioCtrlRegs.GPADIR.bit.ALARM_PIN = 0; // input

    GPIO_CLEAR_STEP;
    GPIO_CLEAR_DIRECTION;
    EDIS;

    setEnabled(true);
}






