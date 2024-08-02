//###########################################################################
//
// FILE:   F2806x_Cla_defines.h
//
// TITLE:  #defines used in CLA examples
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

#ifndef F2806x_CLA_DEFINES_H
#define F2806x_CLA_DEFINES_H

#ifdef __cplusplus
extern "C" {
#endif

//
// Defines
//

//
// MCTL Register
//
#define CLA_FORCE_RESET           0x1
#define CLA_IACK_ENABLE           0x1
#define CLA_IACK_DISABLE          0x0

//
// MMEMCFG Register
//
#define CLA_CLA_SPACE             0x1
#define CLA_CPU_SPACE             0x0

//
// MIER Interrupt Enable Register
//
#define CLA_INT_ENABLE            0x1
#define CLA_INT_DISABLE           0x0

//
// PERINT11SEL Interrupt Source Select Register
//
#define CLA_INT1_NONE             0x1
#define CLA_INT1_ADCINT1          0x0
#define CLA_INT1_EPWM1INT         0x2

#define CLA_INT2_NONE             0x1
#define CLA_INT2_ADCINT2          0x0
#define CLA_INT2_EPWM2INT         0x2

#define CLA_INT3_NONE             0x1
#define CLA_INT3_ADCINT3          0x0
#define CLA_INT3_EPWM3INT         0x2

#define CLA_INT4_NONE             0x1
#define CLA_INT4_ADCINT4          0x0
#define CLA_INT4_EPWM4INT         0x2

#define CLA_INT5_NONE             0x1
#define CLA_INT5_ADCINT5          0x0
#define CLA_INT5_EPWM5INT         0x2

#define CLA_INT6_NONE             0x1
#define CLA_INT6_ADCINT6          0x0
#define CLA_INT6_EPWM6INT         0x2

#define CLA_INT7_NONE             0x1
#define CLA_INT7_ADCINT7          0x0
#define CLA_INT7_EPWM7INT         0x2

#define CLA_INT8_NONE             0x1
#define CLA_INT8_ADCINT4          0x0
#define CLA_INT8_CPUTIMER0INT     0x2

//
// Useful CLA Operation Macros:
//
#define Cla1ForceTask1andWait()__asm("  IACK  #0x0001");             \
                               __asm("  RPT #3 || NOP");             \
                                while(Cla1Regs.MIRUN.bit.INT1 == 1);


#define Cla1ForceTask2andWait()__asm("  IACK  #0x0002");             \
                               __asm("  RPT #3 || NOP");             \
                                while(Cla1Regs.MIRUN.bit.INT2 == 1);

#define Cla1ForceTask3andWait()__asm("  IACK  #0x0004");             \
                               __asm("  RPT #3 || NOP");             \
                                while(Cla1Regs.MIRUN.bit.INT3 == 1);

#define Cla1ForceTask4andWait()__asm("  IACK  #0x0008");             \
                               __asm("  RPT #3 || NOP");             \
                                while(Cla1Regs.MIRUN.bit.INT4 == 1);

#define Cla1ForceTask5andWait()__asm("  IACK  #0x0010");             \
                               __asm("  RPT #3 || NOP");             \
                                while(Cla1Regs.MIRUN.bit.INT5 == 1);

#define Cla1ForceTask6andWait()__asm("  IACK  #0x0020");             \
                               __asm("  RPT #3 || NOP");             \
                                while(Cla1Regs.MIRUN.bit.INT6 == 1);

#define Cla1ForceTask7andWait()__asm("  IACK  #0x0040");             \
                               __asm("  RPT #3 || NOP");             \
                                while(Cla1Regs.MIRUN.bit.INT7 == 1);

#define Cla1ForceTask8andWait()__asm("  IACK  #0x0080");             \
                               __asm("  RPT #3 || NOP");             \
                                while(Cla1Regs.MIRUN.bit.INT8 == 1);

#define Cla1ForceTask1()       __asm("  IACK  #0x0001")
#define Cla1ForceTask2()       __asm("  IACK  #0x0002")
#define Cla1ForceTask3()       __asm("  IACK  #0x0004")
#define Cla1ForceTask4()       __asm("  IACK  #0x0008")
#define Cla1ForceTask5()       __asm("  IACK  #0x0010")
#define Cla1ForceTask6()       __asm("  IACK  #0x0020")
#define Cla1ForceTask7()       __asm("  IACK  #0x0040")
#define Cla1ForceTask8()       __asm("  IACK  #0x0080")

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of F2806x_CLA_DEFINES_H

//
// End of file
//

