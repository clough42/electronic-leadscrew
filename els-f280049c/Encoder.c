#include "Encoder.h"
#include "Configuration.h"



void Encoder_Init(void)
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

    EQep1Regs.QUPRD = 80000000 / RPM_CALC_RATE_HZ; // Unit Timer latch at RPM_CALC_RATE_HZ Hz
    EQep1Regs.QEPCTL.bit.UTE=1;             // Unit Timeout Enable
    EQep1Regs.QEPCTL.bit.QCLM=1;            // Latch on unit time out

    EQep1Regs.QEPCTL.bit.QPEN=1;            // QEP enable

}

Uint32 previous = 0;
Uint16 rpm = 0;

Uint16 Encoder_GetRPM(void)
{
    if(EQep1Regs.QFLG.bit.UTO==1)       // If unit timeout (one 10Hz period)
    {
        Uint32 new = EQep1Regs.QPOSLAT;
        Uint32 count = (new > previous) ? new - previous : previous - new;

        // deal with over/underflow
        if( count > _ENCODER_MAX_COUNT/2 ) {
            count = _ENCODER_MAX_COUNT - count; // just subtract from max value
        }

        rpm = count * 60 * RPM_CALC_RATE_HZ / 4096;

        if( rpm > 2000 ) {
            previous = new;
        }

        previous = new;
        EQep1Regs.QCLR.bit.UTO=1;       // Clear interrupt flag
    }

    return rpm;
}
