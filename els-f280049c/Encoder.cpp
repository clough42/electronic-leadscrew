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


#include "Encoder.h"
#include "Configuration.h"


Encoder :: Encoder( void )
{
    this->previous = 0;
    this->rpm = 0;
}

void Encoder :: initHardware(void)
{
    EALLOW;

    GpioCtrlRegs.GPBPUD.bit.GPIO35 = 0;     // Enable pull-up on GPIO20 (EQEP1A)
    GpioCtrlRegs.GPBPUD.bit.GPIO37 = 0;     // Enable pull-up on GPIO21 (EQEP1B)
    GpioCtrlRegs.GPBPUD.bit.GPIO59 = 0;     // Enable pull-up on GPIO23 (EQEP1I)

    GpioCtrlRegs.GPBQSEL1.bit.GPIO35 = 0;   // Sync to SYSCLKOUT GPIO20 (EQEP1A)
    GpioCtrlRegs.GPBQSEL1.bit.GPIO37 = 0;   // Sync to SYSCLKOUT GPIO21 (EQEP1B)
    GpioCtrlRegs.GPBQSEL2.bit.GPIO59 = 0;   // Sync to SYSCLKOUT GPIO23 (EQEP1I)

    GpioCtrlRegs.GPBMUX1.bit.GPIO35 = 1;    // Configure GPIO20 as EQEP1A
    GpioCtrlRegs.GPBGMUX1.bit.GPIO35 = 2;
    GpioCtrlRegs.GPBMUX1.bit.GPIO37 = 1;    // Configure GPIO20 as EQEP1A
    GpioCtrlRegs.GPBGMUX1.bit.GPIO37 = 2;
    GpioCtrlRegs.GPBMUX2.bit.GPIO59 = 3;    // Configure GPIO20 as EQEP1A
    GpioCtrlRegs.GPBGMUX2.bit.GPIO59 = 2;

    EDIS;

    EQep1Regs.QDECCTL.bit.QSRC = 0;         // QEP quadrature count mode
    EQep1Regs.QDECCTL.bit.IGATE = 1;        // gate the index pin
    EQep1Regs.QDECCTL.bit.QAP = 1;          // invert A input
    EQep1Regs.QDECCTL.bit.QBP = 1;          // invert B input
    EQep1Regs.QDECCTL.bit.QIP = 1;          // invert index input
    EQep1Regs.QEPCTL.bit.FREE_SOFT = 2;     // unaffected by emulation suspend
    EQep1Regs.QEPCTL.bit.PCRM = 1;          // position count reset on maximum position
    EQep1Regs.QPOSMAX = _ENCODER_MAX_COUNT;  // Max position count

    EQep1Regs.QUPRD = CPU_CLOCK_HZ / RPM_CALC_RATE_HZ; // Unit Timer latch at RPM_CALC_RATE_HZ Hz
    EQep1Regs.QEPCTL.bit.UTE=1;             // Unit Timeout Enable
    EQep1Regs.QEPCTL.bit.QCLM=1;            // Latch on unit time out

    EQep1Regs.QEPCTL.bit.QPEN=1;            // QEP enable

}

Uint16 Encoder :: getRPM(void)
{
    if(EQep1Regs.QFLG.bit.UTO==1)       // If unit timeout (one 10Hz period)
    {
        Uint32 current = EQep1Regs.QPOSLAT;
        Uint32 count = (current > previous) ? current - previous : previous - current;

        // deal with over/underflow
        if( count > _ENCODER_MAX_COUNT/2 ) {
            count = _ENCODER_MAX_COUNT - count; // just subtract from max value
        }

        rpm = count * 60 * RPM_CALC_RATE_HZ / 4096;

        previous = current;
        EQep1Regs.QCLR.bit.UTO=1;       // Clear interrupt flag
    }

    return rpm;
}
