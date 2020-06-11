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

Encoder :: Encoder( void )
{
    this->previous = 0;
    this->rpm = 0;
#ifdef ENCODER_USE_EQEP1
    this->base = EQEP1_BASE;
#else
    this->base = EQEP2_BASE;
#endif
}

void Encoder :: initHardware(void)
{
    // EALLOW;

#ifdef ENCODER_USE_EQEP1
    GPIO_setPadConfig(35, GPIO_PIN_TYPE_PULLUP);
    GPIO_setPadConfig(37, GPIO_PIN_TYPE_PULLUP);
    GPIO_setPadConfig(59, GPIO_PIN_TYPE_PULLUP);

    GPIO_setQualificationMode(35, GPIO_QUAL_SYNC);
    GPIO_setQualificationMode(37, GPIO_QUAL_SYNC);
    GPIO_setQualificationMode(59, GPIO_QUAL_SYNC);

    GPIO_setPinConfig(GPIO_35_EQEP1A);
    GPIO_setPinConfig(GPIO_37_EQEP1B);
    GPIO_setPinConfig(GPIO_59_EQEP1I);

    /*
    GpioCtrlRegs.GPBPUD.bit.GPIO35 = 0;     // Enable pull-up on GPIO35 (EQEP1A)
    GpioCtrlRegs.GPBPUD.bit.GPIO37 = 0;     // Enable pull-up on GPIO371 (EQEP1B)
    GpioCtrlRegs.GPBPUD.bit.GPIO59 = 0;     // Enable pull-up on GPIO59 (EQEP1I)

    GpioCtrlRegs.GPBQSEL1.bit.GPIO35 = 0;   // Sync to SYSCLKOUT GPIO35 (EQEP1A)
    GpioCtrlRegs.GPBQSEL1.bit.GPIO37 = 0;   // Sync to SYSCLKOUT GPIO37 (EQEP1B)
    GpioCtrlRegs.GPBQSEL2.bit.GPIO59 = 0;   // Sync to SYSCLKOUT GPIO59 (EQEP1I)

    GpioCtrlRegs.GPBMUX1.bit.GPIO35 = 1;    // Configure GPIO35 as EQEP1A
    GpioCtrlRegs.GPBGMUX1.bit.GPIO35 = 2;
    GpioCtrlRegs.GPBMUX1.bit.GPIO37 = 1;    // Configure GPIO37 as EQEP1B
    GpioCtrlRegs.GPBGMUX1.bit.GPIO37 = 2;
    GpioCtrlRegs.GPBMUX2.bit.GPIO59 = 3;    // Configure GPIO59 as EQEP1I
    GpioCtrlRegs.GPBGMUX2.bit.GPIO59 = 2;
    */
#endif
#ifdef ENCODER_USE_EQEP2
    GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;     // Enable pull-up on GPIO14 (EQEP2A)
    GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0;     // Enable pull-up on GPIO15 (EQEP2B)
    GpioCtrlRegs.GPAPUD.bit.GPIO26 = 0;     // Enable pull-up on GPIO26 (EQEP2I)

    GpioCtrlRegs.GPAQSEL1.bit.GPIO14 = 0;   // Sync to SYSCLKOUT GPIO14 (EQEP2A)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO15 = 0;   // Sync to SYSCLKOUT GPIO15 (EQEP2B)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO26 = 0;   // Sync to SYSCLKOUT GPIO26 (EQEP2I)

    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 2;    // Configure GPIO14 as EQEP2A
    GpioCtrlRegs.GPAGMUX1.bit.GPIO14 = 2;
    GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 2;    // Configure GPIO15 as EQEP2B
    GpioCtrlRegs.GPAGMUX1.bit.GPIO15 = 2;
    GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 2;    // Configure GPIO26 as EQEP2I
    GpioCtrlRegs.GPAGMUX2.bit.GPIO26 = 0;
#endif

    //EDIS;

    EQEP_setDecoderConfig(this->base, EQEP_CONFIG_QUADRATURE);
    EQEP_setPositionCounterConfig(EQEP1_BASE, EQEP_POSITION_RESET_IDX, 0xFFFFFFFF);
    EQEP_setInputPolarity(this->base, true, true, true, false);
    EQEP_setEmulationMode(this->base, EQEP_EMULATIONMODE_RUNFREE);
    EQEP_setPositionCounterConfig(this->base, EQEP_POSITION_RESET_MAX_POS, _ENCODER_MAX_COUNT);
    EQEP_enableUnitTimer(this->base, DEVICE_SYSCLK_FREQ / RPM_CALC_RATE_HZ);
    EQEP_setLatchMode(EQEP1_BASE, EQEP_LATCH_UNIT_TIME_OUT);
    EQEP_enableModule(this->base);

    /*
    ENCODER_REGS.QDECCTL.bit.QSRC = 0;         // QEP quadrature count mode
    ENCODER_REGS.QDECCTL.bit.IGATE = 1;        // gate the index pin
    ENCODER_REGS.QDECCTL.bit.QAP = 1;          // invert A input
    ENCODER_REGS.QDECCTL.bit.QBP = 1;          // invert B input
    ENCODER_REGS.QDECCTL.bit.QIP = 1;          // invert index input
    ENCODER_REGS.QEPCTL.bit.FREE_SOFT = 2;     // unaffected by emulation suspend
    ENCODER_REGS.QEPCTL.bit.PCRM = 1;          // position count reset on maximum position
    ENCODER_REGS.QPOSMAX = _ENCODER_MAX_COUNT;  // Max position count

    ENCODER_REGS.QUPRD = CPU_CLOCK_HZ / RPM_CALC_RATE_HZ; // Unit Timer latch at RPM_CALC_RATE_HZ Hz
    ENCODER_REGS.QEPCTL.bit.UTE=1;             // Unit Timeout Enable
    ENCODER_REGS.QEPCTL.bit.QCLM=1;            // Latch on unit time out

    ENCODER_REGS.QEPCTL.bit.QPEN=1;            // QEP enable
    */

}

Uint16 Encoder :: getRPM(void)
{
    if((EQEP_getInterruptStatus(EQEP1_BASE) & EQEP_INT_UNIT_TIME_OUT) != 0)
    {
        Uint32 current = EQEP_getPositionLatch(this->base);
        Uint32 count = (current > previous) ? current - previous : previous - current;

        // deal with over/underflow
        if( count > _ENCODER_MAX_COUNT/2 ) {
            count = _ENCODER_MAX_COUNT - count; // just subtract from max value
        }

        rpm = count * 60 * RPM_CALC_RATE_HZ / ENCODER_RESOLUTION;
        previous = current;

        EQEP_clearInterruptStatus(EQEP1_BASE, EQEP_INT_UNIT_TIME_OUT);
    }

    return rpm;
}
