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

#include "TestVREG.h"

TestVREG :: TestVREG( void )
{

}

void TestVREG :: initHardware(void)
{

    SetVREF(ADC_ADCA, ADC_INTERNAL, ADC_VREF3P3);
    SetVREF(ADC_ADCB, ADC_INTERNAL, ADC_VREF3P3);
    SetVREF(ADC_ADCC, ADC_INTERNAL, ADC_VREF3P3);

    EALLOW;
    AdcaRegs.ADCCTL1.bit.ADCPWDNZ = 1; // power up
    //AdcaRegs.ADCCTL1.bit.INTPULSEPOS = 1; // pulse at end of conversion
    AdcaRegs.ADCSOC0CTL.bit.CHSEL = 5; // ADCINB1
    AdcaRegs.ADCSOC0CTL.bit.ACQPS = 30; // 31 SYSCLK cycles
    AdcaRegs.ADCSOC0CTL.bit.TRIGSEL = 1; // CPU1 timer
    EDIS;
}

void TestVREG :: test(LED_REG *output)
{
    bool pass = false;

    // trigger a conversion
    ////AdcaRegs.ADCSOCFRC1.bit.SOC0 = 1;
    //DELAY_US(1000000);
    //while(AdcaRegs.ADCINTFLG.bit.ADCINT1 != 1);
    Uint16 result = AdcaResultRegs.ADCRESULT0;

    pass = ( result > 1900 && result < 2100 );

    output->bit.VREG_GREEN = pass;
    output->bit.VREG_RED = !pass;
}
