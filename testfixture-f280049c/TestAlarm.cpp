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

#include "TestAlarm.h"

TestAlarm :: TestAlarm( StepperDrive *stepperDrive )
{
    this->stepperDrive = stepperDrive;
}

void TestAlarm :: initHardware(void)
{
    EALLOW;
    GpioCtrlRegs.GPBMUX1.bit.GPIO35 = 0;

    GpioCtrlRegs.GPBDIR.bit.GPIO35 = 1; // output;

    EDIS;
}

void TestAlarm :: test(LED_REG *output)
{
    bool pass = true;

    GpioDataRegs.GPBSET.bit.GPIO35 = 1;
    DELAY_US(1000);

    pass = pass && ! this->stepperDrive->isAlarm();

    GpioDataRegs.GPBCLEAR.bit.GPIO35 = 1;
    DELAY_US(1000);

    pass = pass && this->stepperDrive->isAlarm();

    output->bit.ALM_GREEN = pass;
    output->bit.ALM_RED = !pass;
}
