//###########################################################################
//
// FILE:	F2806x_DefaultIsr.c
//
// TITLE:	F2806x Device Default Interrupt Service Routines.
//
// This file contains shell ISR routines for the 2803x PIE vector table.
// Typically these shell ISR routines can be used to populate the entire PIE
// vector table during device debug.  In this manner if an interrupt is taken
// during firmware development, there will always be an ISR to catch it.
//
// As development progresses, these ISR routines can be eliminated and replaced
// with the user's own ISR routines for each interrupt.  Since these shell ISRs
// include infinite loops they will typically not be included as-is in the final
// production firmware.
//
//###########################################################################
// $TI Release: $
// $Release Date: $
// $Copyright:
// Copyright (C) 2009-2022 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//###########################################################################

//
// Included Files
//
#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File

//
// INT13_ISR - INT13 or CPU-Timer1 is connected to INT13 of CPU 
// (use MINT13 mask): ISR can be used by the user.
//
__interrupt void
INT13_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// INT14_ISR - INT14 or CPU-Timer2
//
__interrupt void
INT14_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// DATALOG_ISR - Datalogging interrupt
//
__interrupt void
DATALOG_ISR(void)
{
    //
    // Insert ISR Code here
    //
    
    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// RTOSINT_ISR - RTOS interrupt
//
__interrupt void
RTOSINT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// EMUINT_ISR - Emulation interrupt
//
__interrupt void
EMUINT_ISR(void)    
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// NMI_ISR - Non-maskable interrupt
//
__interrupt void
NMI_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// ILLEGAL_ISR - Illegal operation TRAP
//
__interrupt void
ILLEGAL_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm("          ESTOP0");
    for(;;);
}

//
// USER1_ISR - User Defined trap 1
//
__interrupt void
USER1_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// USER2_ISR - User Defined trap 2
//
__interrupt void
USER2_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// USER3_ISR - User Defined trap 3
//
__interrupt void
USER3_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// USER4_ISR - User Defined trap 4
//
__interrupt void
USER4_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// USER5_ISR - User Defined trap 5
//
__interrupt void
USER5_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// USER6_ISR - User Defined trap 6
//
__interrupt void
USER6_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// USER7_ISR - User Defined trap 7
//
__interrupt void
USER7_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// USER8_ISR - User Defined trap 8
//
__interrupt void
USER8_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// USER9_ISR - User Defined trap 9
//
__interrupt void
USER9_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// USER10_ISR - User Defined trap 10
//
__interrupt void
USER10_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// USER11_ISR - User Defined trap 11
//
__interrupt void
USER11_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// USER12_ISR - User Defined trap 12
//
__interrupt void
USER12_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// PIE Group 1 - MUXed into CPU INT1
//

//
// ADCINT1_ISR - ADC is INT1.1 (Can also be ISR for INT10.1 when enabled)
//
__interrupt void
ADCINT1_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this 
    // interrupt
    //
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// ADCINT2_ISR - ADC is INT1.2 (Can also be ISR for INT10.2 when enabled)
//
__interrupt void
ADCINT2_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm("	  ESTOP0");
    for(;;);
}

//
// INT1.3 - Reserved
//

//
// XINT1_ISR - INT1.4
//
__interrupt void
XINT1_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// XINT2_ISR - INT1.5
//
__interrupt void
XINT2_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// ADCINT9_ISR - INT1.6
//
__interrupt void
ADCINT9_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// TINT0_ISR - INT1.7 is CPU-Timer 0 
//
__interrupt void
TINT0_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// WAKEINT_ISR - INT1.8 is WD, LOW Power
//
__interrupt void
WAKEINT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// PIE Group 2 - MUXed into CPU INT2
//

//
// EPWM1_TZINT_ISR - INT2.1 is EPWM Trip Zone-1
//
__interrupt void
EPWM1_TZINT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// EPWM2_TZINT_ISR - INT2.2 is EPWM Trip Zone-2
//
__interrupt void
EPWM2_TZINT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// EPWM3_TZINT_ISR - INT2.3 is EPWM Trip Zone-3
//
__interrupt void
EPWM3_TZINT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// EPWM4_TZINT_ISR - INT2.4 is EPWM Trip Zone-4
//
__interrupt void
EPWM4_TZINT_ISR(void) 
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// EPWM5_TZINT_ISR - INT2.5 is EPWM Trip Zone-5
//
__interrupt void
EPWM5_TZINT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// EPWM6_TZINT_ISR - INT2.6 is EPWM Trip Zone-6
//
__interrupt void
EPWM6_TZINT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// EPWM7_TZINT_ISR - INT2.7 is EPWM Trip Zone-7
//
__interrupt void
EPWM7_TZINT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// EPWM8_TZINT_ISR - INT2.8 is EPWM Trip Zone-8
//
__interrupt void
EPWM8_TZINT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// PIE Group 3 - MUXed into CPU INT3
//

//
// EPWM1_INT_ISR - INT 3.1 is EPWM-1
//
__interrupt void
EPWM1_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// EPWM2_INT_ISR - INT3.2 is EPWM-2
//
__interrupt void
EPWM2_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// EPWM3_INT_ISR - INT3.3 is EPWM-3
//
__interrupt void
EPWM3_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// EPWM4_INT_ISR - INT3.4 is EPWM-4
//
__interrupt void
EPWM4_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// EPWM5_INT_ISR - INT3.5 is EPWM-5
//
__interrupt void
EPWM5_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// EPWM6_INT_ISR - INT3.6 is EPWM-6
//
__interrupt void
EPWM6_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// EPWM7_INT_ISR - INT3.7 is EPWM-7
//
__interrupt void
EPWM7_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// EPWM8_INT_ISR - INT3.8 is EPWM-8
//
__interrupt void
EPWM8_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// PIE Group 4 - MUXed into CPU INT4
//

//
// ECAP1_INT_ISR - INT 4.1 is ECAP-1
//
__interrupt void
ECAP1_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// ECAP2_INT_ISR - INT4.2 is ECAP-2
//
__interrupt void
ECAP2_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// ECAP3_INT_ISR - INT4.3 is ECAP-3
//
__interrupt void
ECAP3_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// INT4.4 - Reserved
//

//
// INT4.5 - Reserved
//

//
// INT4.6 - Reserved
//

//
// HRCAP1_INT_ISR - INT4.7 is HRCAP-1
//
__interrupt void
HRCAP1_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// HRCAP2_INT_ISR - INT4.8 is HRCAP-2
//
__interrupt void
HRCAP2_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// PIE Group 5 - MUXed into CPU INT5
//

//
// EQEP1_INT_ISR - INT 5.1 is EQEP-1
//
__interrupt void
EQEP1_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// EQEP2_INT_ISR - INT5.2 is EQEP-2
//
__interrupt void
EQEP2_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// INT5.3 - Reserved
//

//
// HRCAP3_INT_ISR - INT5.4 is HRCAP-3
//
__interrupt void
HRCAP3_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// HRCAP4_INT_ISR - INT5.5 is HRCAP-4
//
__interrupt void
HRCAP4_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// INT5.6 - Reserved
//

//
// INT5.7 - Reserved
//

//
// USB0_INT_ISR - INT5.8 is USB-0
//
__interrupt void
USB0_INT_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP5;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// PIE Group 6 - MUXed into CPU INT6
//

//
// SPIRXINTA_ISR - INT6.1 is SPI-A
//
__interrupt void
SPIRXINTA_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// SPITXINTA_ISR - INT6.2 is SPI-A
//
__interrupt void
SPITXINTA_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// SPIRXINTB_ISR - INT6.3 is SPI-B
//
__interrupt void
SPIRXINTB_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// SPITXINTB_ISR - INT6.4 is SPI-B
//
__interrupt void
SPITXINTB_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// MRINTA_ISR - INT6.5 is McBSP-A
//
__interrupt void
MRINTA_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// MXINTA_ISR - INT6.6 is McBSP-A
//
__interrupt void
MXINTA_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP6;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// INT6.7 - Reserved
//

//
// INT6.8 - Reserved
//

//
// PIE Group 7 - MUXed into CPU INT7
//

//
// DINTCH1_ISR - INT7.1 is DMA Channel 1
//
__interrupt void
DINTCH1_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// DINTCH2_ISR - INT7.2 is DMA Channel 2
//
__interrupt void
DINTCH2_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// DINTCH3_ISR - INT7.3 is DMA Channel 3
//
__interrupt void
DINTCH3_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// DINTCH4_ISR - INT7.4 is DMA Channel 4
//
__interrupt void
DINTCH4_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// DINTCH5_ISR - INT7.5 is DMA Channel 5
//
__interrupt void
DINTCH5_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// DINTCH6_ISR - INT7.6 is DMA Channel 6
//
__interrupt void
DINTCH6_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP7;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// INT7.7 - Reserved
//

//
// INT7.8 - Reserved
//

//
// PIE Group 8 - MUXed into CPU INT8
//

//
// I2CINT1A_ISR - INT8.1 is I2C-A
//
__interrupt void
I2CINT1A_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// I2CINT2A_ISR - INT8.2 is I2C-A
//
__interrupt void
I2CINT2A_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP8;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

// INT8.3 - Reserved
// INT8.4 - Reserved
// INT8.5 - Reserved
// INT8.6 - Reserved
// INT8.7 - Reserved
// INT8.8 - Reserved

//
// PIE Group 9 - MUXed into CPU INT9
//

//
// SCIRXINTA_ISR - INT9.1 is SCI-A
//
__interrupt void
SCIRXINTA_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// SCITXINTA_ISR - INT9.2 is SCI-A
//
__interrupt void
SCITXINTA_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// SCIRXINTB_ISR - INT9.3 is SCI-B
//
__interrupt void
SCIRXINTB_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// SCITXINTB_ISR - INT9.4 is SCI-B
//
__interrupt void
SCITXINTB_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// ECAN0INTA_ISR - INT9.5 is ECAN-A
//
__interrupt void
ECAN0INTA_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// ECAN1INTA_ISR - INT9.6 is ECAN-A
//
__interrupt void
ECAN1INTA_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP9;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// INT9.7 - Reserved
//

//
// INT9.8 - Reserved
//

//
// PIE Group 10 - MUXed into CPU INT10
//

//
// INT10.1 - Reserved or ADCINT1_ISR
//

//
// INT10.2 - Reserved or ADCINT2_ISR
//

//
// ADCINT3_ISR - INT10.3 is ADC
//
__interrupt void
ADCINT3_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// ADCINT4_ISR - INT10.4 is ADC
//
__interrupt void
ADCINT4_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// ADCINT5_ISR - INT10.5 is ADC
//
__interrupt void
ADCINT5_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// ADCINT6_ISR - INT10.6 is ADC
//
__interrupt void
ADCINT6_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// ADCINT7_ISR - INT10.7 is ADC
//
__interrupt void
ADCINT7_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// ADCINT8_ISR - INT10.8 is ADC
//
__interrupt void
ADCINT8_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP10;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// PIE Group 11 - MUXed into CPU INT11
//

//
// CLA1_INT1_ISR - INT11.1 is MCLA
//
__interrupt void
CLA1_INT1_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP11;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// CLA1_INT2_ISR - INT11.2 is MCLA
//
__interrupt void
CLA1_INT2_ISR(void)
{

    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP11;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm("	  ESTOP0");
    for(;;);
}

//
// CLA1_INT3_ISR - INT11.3 is MCLA
//
__interrupt void
CLA1_INT3_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP11;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// CLA1_INT4_ISR - INT11.4 is MCLA
//
__interrupt void
CLA1_INT4_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP11;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// CLA1_INT5_ISR - INT11.5 is MCLA
//
__interrupt void
CLA1_INT5_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP11;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// CLA1_INT6_ISR - INT11.6 is MCLA
//
__interrupt void
CLA1_INT6_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP11;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// CLA1_INT7_ISR - INT11.7 is MCLA
//
__interrupt void
CLA1_INT7_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP11;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// CLA1_INT8_ISR - INT11.8 is MCLA
//
__interrupt void
CLA1_INT8_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP11;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// PIE Group 12 - MUXed into CPU INT12
//

//
// XINT3_ISR - INT12.1 is External interrupt 3
//
__interrupt void
XINT3_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// INT12.2 - Reserved
//

//
// INT12.3 - Reserved
//

//
// INT12.4 - Reserved
//

//
// INT12.5 - Reserved
//

//
// INT12.6 - Reserved
//

//
// LVF_ISR - INT12.7 is Latched overflow
//
__interrupt void
LVF_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// LUF_ISR - INT12.8 is Latched underflow
//
__interrupt void
LUF_ISR(void)
{
    //
    // Insert ISR Code here
    //

    //
    // To receive more interrupts from this PIE group, acknowledge this
    // interrupt
    //
    // PieCtrlRegs.PIEACK.all = PIEACK_GROUP12;

    //
    // Next two lines for debug only to halt the processor here
    // Remove after inserting ISR Code
    //
    __asm ("      ESTOP0");
    for(;;);
}

//
// Catch All Default ISRs
//

//
// EMPTY_ISR - Empty ISR only does a return.
//
__interrupt void
EMPTY_ISR(void)
{

}

//
// PIE_RESERVED - Reserved space.  For test.
//
__interrupt void
PIE_RESERVED(void)
{
    __asm ("      ESTOP0");
    for(;;);
}

//
// rsvd_ISR - For test
//
__interrupt void
rsvd_ISR(void)
{
    __asm ("      ESTOP0");
    for(;;);
}

//
// End of file
//

