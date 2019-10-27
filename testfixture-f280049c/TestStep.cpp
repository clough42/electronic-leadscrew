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

#include "TestStep.h"

#define STEP_FEEDBACK GpioDataRegs.GPBDAT.bit.GPIO37;
#define DIRECTION_FEEDBACK GpioDataRegs.GPBDAT.bit.GPIO40;
#define ENABLE_FEEDBACK GpioDataRegs.GPBDAT.bit.GPIO56;

#define ASSERT(x) (pass &&= x)

TestStep :: TestStep( StepperDrive *stepperDrive )
{
    this->stepperDrive = stepperDrive;
}

void TestStep :: initHardware(void)
{
    EALLOW;
    GpioCtrlRegs.GPBMUX1.bit.GPIO37 = 0;
    GpioCtrlRegs.GPBMUX1.bit.GPIO40 = 0;
    GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 0;

    GpioCtrlRegs.GPBDIR.bit.GPIO37 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO40 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO56 = 0;

    EDIS;
}

void TestStep :: test(LED_REG *output)
{
    bool pass = true;

    GPIO_SET_STEP;
    GPIO_SET_DIRECTION;
    GPIO_SET_ENABLE;
    DELAY_US(100);

    pass = pass && STEP_FEEDBACK;
    pass = pass && DIRECTION_FEEDBACK;
    pass = pass && ENABLE_FEEDBACK;

    GPIO_CLEAR_STEP;
    GPIO_SET_DIRECTION;
    GPIO_SET_ENABLE;
    DELAY_US(100);

    pass = pass && ! STEP_FEEDBACK;
    pass = pass && DIRECTION_FEEDBACK;
    pass = pass && ENABLE_FEEDBACK;

    GPIO_SET_STEP;
    GPIO_CLEAR_DIRECTION;
    GPIO_SET_ENABLE;
    DELAY_US(100);

    pass = pass && STEP_FEEDBACK;
    pass = pass && ! DIRECTION_FEEDBACK;
    pass = pass && ENABLE_FEEDBACK;

    GPIO_SET_STEP;
    GPIO_SET_DIRECTION;
    GPIO_CLEAR_ENABLE;
    DELAY_US(100);

    pass = pass && STEP_FEEDBACK;
    pass = pass && DIRECTION_FEEDBACK;
    pass = pass && ! ENABLE_FEEDBACK;

    GPIO_CLEAR_STEP;
    GPIO_CLEAR_DIRECTION;
    GPIO_CLEAR_ENABLE;
    DELAY_US(100);

    pass = pass && ! STEP_FEEDBACK;
    pass = pass && ! DIRECTION_FEEDBACK;
    pass = pass && ! ENABLE_FEEDBACK;

    output->bit.STEP_GREEN = pass;
    output->bit.STEP_RED = !pass;
}
