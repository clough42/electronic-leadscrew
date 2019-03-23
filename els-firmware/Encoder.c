#include "Encoder.h"



void Encoder_Init(void)
{
    EALLOW;

    GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0;   // Enable pull-up on GPIO20 (EQEP1A)
    GpioCtrlRegs.GPAPUD.bit.GPIO21 = 0;   // Enable pull-up on GPIO21 (EQEP1B)
    GpioCtrlRegs.GPAPUD.bit.GPIO23 = 0;   // Enable pull-up on GPIO23 (EQEP1I)

    GpioCtrlRegs.GPAQSEL2.bit.GPIO20 = 0;  // Sync to SYSCLKOUT GPIO20 (EQEP1A)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO21 = 0;  // Sync to SYSCLKOUT GPIO21 (EQEP1B)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO23 = 0;  // Sync to SYSCLKOUT GPIO23 (EQEP1I)

    GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 1;   // Configure GPIO20 as EQEP1A
    GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 1;   // Configure GPIO21 as EQEP1B
    GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 1;   // Configure GPIO23 as EQEP1I

    EDIS;

    EQep1Regs.QUPRD=8000000;            // Unit Timer latch at 10Hz

    EQep1Regs.QDECCTL.bit.QSRC=00;      // QEP quadrature count mode

    EQep1Regs.QEPCTL.bit.FREE_SOFT=2;   // unaffected by emulation suspend

    EQep1Regs.QEPCTL.bit.PCRM=01;       // position count reset on maximum position

    EQep1Regs.QEPCTL.bit.UTE=1;         // Unit Timeout Enable
    EQep1Regs.QEPCTL.bit.QCLM=1;        // Latch on unit time out
    EQep1Regs.QPOSMAX=0xffffffff;       // Max position count
    EQep1Regs.QEPCTL.bit.QPEN=1;        // QEP enable

}

Uint32 previous = 0;
Uint16 rpm = 0;

Uint16 Encoder_GetRPM(void)
{
    if(EQep1Regs.QFLG.bit.UTO==1)       // If unit timeout (one 10Hz period)
    {
        Uint32 new = EQep1Regs.QPOSLAT;
        Uint32 count = (new > previous) ? new - previous : previous - new;

        rpm = count * 600 / 4096;

        if( rpm > 2000 ) {
            previous = new;
        }

        previous = new;
        EQep1Regs.QCLR.bit.UTO=1;       // Clear interrupt flag
    }

    return rpm;
}
