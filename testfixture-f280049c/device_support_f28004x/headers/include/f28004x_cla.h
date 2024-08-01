//###########################################################################
//
// FILE:    f28004x_cla.h
//
// TITLE:   CLA Register Definitions.
//
//###########################################################################
// $TI Release: F28004x Support Library v1.05.00.00 $
// $Release Date: Thu Oct 18 15:43:57 CDT 2018 $
// $Copyright:
// Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef __F28004X_CLA_H__
#define __F28004X_CLA_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// CLA Individual Register Bit Definitions:

struct MCTL_BITS {                      // bits description
    Uint16 HARDRESET:1;                 // 0 Hard Reset
    Uint16 SOFTRESET:1;                 // 1 Soft Reset
    Uint16 IACKE:1;                     // 2 IACK enable
    Uint16 rsvd1:13;                    // 15:3 Reserved
};

union MCTL_REG {
    Uint16  all;
    struct  MCTL_BITS  bit;
};

struct SOFTINTEN_BITS {                 // bits description
    Uint16 TASK1:1;                     // 0 Configure Software Interrupt or End of Task interrupt.
    Uint16 TASK2:1;                     // 1 Configure Software Interrupt or End of Task interrupt.
    Uint16 TASK3:1;                     // 2 Configure Software Interrupt or End of Task interrupt.
    Uint16 TASK4:1;                     // 3 Configure Software Interrupt or End of Task interrupt.
    Uint16 TASK5:1;                     // 4 Configure Software Interrupt or End of Task interrupt.
    Uint16 TASK6:1;                     // 5 Configure Software Interrupt or End of Task interrupt.
    Uint16 TASK7:1;                     // 6 Configure Software Interrupt or End of Task interrupt.
    Uint16 TASK8:1;                     // 7 Configure Software Interrupt or End of Task interrupt.
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union SOFTINTEN_REG {
    Uint16  all;
    struct  SOFTINTEN_BITS  bit;
};

struct _MSTSBGRND_BITS {                // bits description
    Uint16 RUN:1;                       // 0 Background task run status bit.
    Uint16 _BGINTM:1;                    // 1 Indicates whether background task can be interrupted.
    Uint16 BGOVF:1;                     // 2 background task harware trigger overflow.
    Uint16 rsvd1:13;                    // 15:3 Reserved
};

union _MSTSBGRND_REG {
    Uint16  all;
    struct  _MSTSBGRND_BITS  bit;
};

struct _MCTLBGRND_BITS {                // bits description
    Uint16 BGSTART:1;                   // 0 Background task start bit
    Uint16 TRIGEN:1;                    // 1 Background task hardware trigger enable
    Uint16 rsvd1:13;                    // 14:2 Reserved
    Uint16 BGEN:1;                      // 15 Enable background task
};

union _MCTLBGRND_REG {
    Uint16  all;
    struct  _MCTLBGRND_BITS  bit;
};

struct MIFR_BITS {                      // bits description
    Uint16 INT1:1;                      // 0 Task 1 Interrupt Flag
    Uint16 INT2:1;                      // 1 Task 2 Interrupt Flag
    Uint16 INT3:1;                      // 2 Task 3 Interrupt Flag
    Uint16 INT4:1;                      // 3 Task 4 Interrupt Flag
    Uint16 INT5:1;                      // 4 Task 5 Interrupt Flag
    Uint16 INT6:1;                      // 5 Task 6 Interrupt Flag
    Uint16 INT7:1;                      // 6 Task 7 Interrupt Flag
    Uint16 INT8:1;                      // 7 Task 8 Interrupt Flag
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union MIFR_REG {
    Uint16  all;
    struct  MIFR_BITS  bit;
};

struct MIOVF_BITS {                     // bits description
    Uint16 INT1:1;                      // 0 Task 1 Interrupt Overflow Flag
    Uint16 INT2:1;                      // 1 Task 2 Interrupt Overflow Flag
    Uint16 INT3:1;                      // 2 Task 3 Interrupt Overflow Flag
    Uint16 INT4:1;                      // 3 Task 4 Interrupt Overflow Flag
    Uint16 INT5:1;                      // 4 Task 5 Interrupt Overflow Flag
    Uint16 INT6:1;                      // 5 Task 6 Interrupt Overflow Flag
    Uint16 INT7:1;                      // 6 Task 7 Interrupt Overflow Flag
    Uint16 INT8:1;                      // 7 Task 8 Interrupt Overflow Flag
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union MIOVF_REG {
    Uint16  all;
    struct  MIOVF_BITS  bit;
};

struct MIFRC_BITS {                     // bits description
    Uint16 INT1:1;                      // 0 Task 1 Interrupt Force
    Uint16 INT2:1;                      // 1 Task 2 Interrupt Force
    Uint16 INT3:1;                      // 2 Task 3 Interrupt Force
    Uint16 INT4:1;                      // 3 Task 4 Interrupt Force
    Uint16 INT5:1;                      // 4 Task 5 Interrupt Force
    Uint16 INT6:1;                      // 5 Task 6 Interrupt Force
    Uint16 INT7:1;                      // 6 Task 7 Interrupt Force
    Uint16 INT8:1;                      // 7 Task 8 Interrupt Force
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union MIFRC_REG {
    Uint16  all;
    struct  MIFRC_BITS  bit;
};

struct MICLR_BITS {                     // bits description
    Uint16 INT1:1;                      // 0 Task 1 Interrupt Flag Clear
    Uint16 INT2:1;                      // 1 Task 2 Interrupt Flag Clear
    Uint16 INT3:1;                      // 2 Task 3 Interrupt Flag Clear
    Uint16 INT4:1;                      // 3 Task 4 Interrupt Flag Clear
    Uint16 INT5:1;                      // 4 Task 5 Interrupt Flag Clear
    Uint16 INT6:1;                      // 5 Task 6 Interrupt Flag Clear
    Uint16 INT7:1;                      // 6 Task 7 Interrupt Flag Clear
    Uint16 INT8:1;                      // 7 Task 8 Interrupt Flag Clear
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union MICLR_REG {
    Uint16  all;
    struct  MICLR_BITS  bit;
};

struct MICLROVF_BITS {                  // bits description
    Uint16 INT1:1;                      // 0 Task 1 Interrupt Overflow Flag Clear
    Uint16 INT2:1;                      // 1 Task 2 Interrupt Overflow Flag Clear
    Uint16 INT3:1;                      // 2 Task 3 Interrupt Overflow Flag Clear
    Uint16 INT4:1;                      // 3 Task 4 Interrupt Overflow Flag Clear
    Uint16 INT5:1;                      // 4 Task 5 Interrupt Overflow Flag Clear
    Uint16 INT6:1;                      // 5 Task 6 Interrupt Overflow Flag Clear
    Uint16 INT7:1;                      // 6 Task 7 Interrupt Overflow Flag Clear
    Uint16 INT8:1;                      // 7 Task 8 Interrupt Overflow Flag Clear
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union MICLROVF_REG {
    Uint16  all;
    struct  MICLROVF_BITS  bit;
};

struct MIER_BITS {                      // bits description
    Uint16 INT1:1;                      // 0 Task 1 Interrupt Enable
    Uint16 INT2:1;                      // 1 Task 2 Interrupt Enable
    Uint16 INT3:1;                      // 2 Task 3 Interrupt Enable
    Uint16 INT4:1;                      // 3 Task 4 Interrupt Enable
    Uint16 INT5:1;                      // 4 Task 5 Interrupt Enable
    Uint16 INT6:1;                      // 5 Task 6 Interrupt Enable
    Uint16 INT7:1;                      // 6 Task 7 Interrupt Enable
    Uint16 INT8:1;                      // 7 Task 8 Interrupt Enable
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union MIER_REG {
    Uint16  all;
    struct  MIER_BITS  bit;
};

struct MIRUN_BITS {                     // bits description
    Uint16 INT1:1;                      // 0 Task 1 Run Status
    Uint16 INT2:1;                      // 1 Task 2 Run Status
    Uint16 INT3:1;                      // 2 Task 3 Run Status
    Uint16 INT4:1;                      // 3 Task 4 Run Status
    Uint16 INT5:1;                      // 4 Task 5 Run Status
    Uint16 INT6:1;                      // 5 Task 6 Run Status
    Uint16 INT7:1;                      // 6 Task 7 Run Status
    Uint16 INT8:1;                      // 7 Task 8 Run Status
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union MIRUN_REG {
    Uint16  all;
    struct  MIRUN_BITS  bit;
};

struct _MSTF_BITS {                     // bits description
    Uint16 LVF:1;                       // 0 Latched Overflow Flag
    Uint16 LUF:1;                       // 1 Latched Underflow Flag
    Uint16 NF:1;                        // 2 Negative Float Flag
    Uint16 ZF:1;                        // 3 Zero Float Flag
    Uint16 rsvd1:2;                     // 5:4 Reserved
    Uint16 TF:1;                        // 6 Test Flag
    Uint16 rsvd2:2;                     // 8:7 Reserved
    Uint16 RNDF32:1;                    // 9 Round 32-bit Floating-Point Mode
    Uint16 rsvd3:1;                     // 10 Reserved
    Uint16 MEALLOW:1;                   // 11 MEALLOW Status
    Uint32 _RPC:16;                      // 27:12 Return PC
    Uint16 rsvd4:4;                     // 31:28 Reserved
};

union _MSTF_REG {
    Uint32  all;
    struct  _MSTF_BITS  bit;
};

struct _MPSACTL_BITS {                  // bits description
    Uint16 MPABSTART:1;                 // 0 Start logging PAB onto PSA1
    Uint16 MPABCYC:1;                   // 1 PAB logging into PSA1 is on every cycle or when PAB changes.
    Uint16 MDWDBSTART:1;                // 2 Start logging DWDB onto PSA2
    Uint16 MDWDBCYC:1;                  // 3 DWDB logging into PSA2 is on every cycle.
    Uint16 MPSA1CLEAR:1;                // 4 PSA1 clear
    Uint16 MPSA2CLEAR:1;                // 5 PSA2 Clear
    Uint16 MPSA2CFG:2;                  // 7:6 PSA2 Polynomial Configuration
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union _MPSACTL_REG {
    Uint16  all;
    struct  _MPSACTL_BITS  bit;
};

union MR_REG {
    Uint32              i32;
    float               f32;
};

struct CLA_REGS {
    Uint16                                   MVECT1;                       // Task Interrupt Vector
    Uint16                                   MVECT2;                       // Task Interrupt Vector
    Uint16                                   MVECT3;                       // Task Interrupt Vector
    Uint16                                   MVECT4;                       // Task Interrupt Vector
    Uint16                                   MVECT5;                       // Task Interrupt Vector
    Uint16                                   MVECT6;                       // Task Interrupt Vector
    Uint16                                   MVECT7;                       // Task Interrupt Vector
    Uint16                                   MVECT8;                       // Task Interrupt Vector
    Uint16                                   rsvd1[8];                     // Reserved
    union   MCTL_REG                         MCTL;                         // Control Register
    Uint16                                   rsvd2[10];                    // Reserved
    Uint16                                   _MVECTBGRNDACTIVE;            // Active register for MVECTBGRND.
    union   SOFTINTEN_REG                    SOFTINTEN;                    // CLA Software Interrupt Enable Register
    union   _MSTSBGRND_REG                   _MSTSBGRND;                   // Status register for the back ground task.
    union   _MCTLBGRND_REG                   _MCTLBGRND;                   // Control register for the back ground task.
    Uint16                                   _MVECTBGRND;                  // Vector for the back ground task.
    union   MIFR_REG                         MIFR;                         // Interrupt Flag Register
    union   MIOVF_REG                        MIOVF;                        // Interrupt Overflow Flag Register
    union   MIFRC_REG                        MIFRC;                        // Interrupt Force Register
    union   MICLR_REG                        MICLR;                        // Interrupt Flag Clear Register
    union   MICLROVF_REG                     MICLROVF;                     // Interrupt Overflow Flag Clear Register
    union   MIER_REG                         MIER;                         // Interrupt Enable Register
    union   MIRUN_REG                        MIRUN;                        // Interrupt Run Status Register
    Uint16                                   rsvd3;                        // Reserved
    Uint16                                   _MPC;                         // CLA Program Counter
    Uint16                                   rsvd4;                        // Reserved
    Uint16                                   _MAR0;                        // CLA Auxiliary Register 0
    Uint16                                   _MAR1;                        // CLA Auxiliary Register 1
    Uint16                                   rsvd5[2];                     // Reserved
    union   _MSTF_REG                        _MSTF;                        // CLA Floating-Point Status Register
    union   MR_REG                           _MR0;                         // CLA Floating-Point Result Register 0
    Uint16                                   rsvd6[2];                     // Reserved
    union   MR_REG                           _MR1;                         // CLA Floating-Point Result Register 1
    Uint16                                   rsvd7[2];                     // Reserved
    union   MR_REG                           _MR2;                         // CLA Floating-Point Result Register 2
    Uint16                                   rsvd8[2];                     // Reserved
    union   MR_REG                           _MR3;                         // CLA Floating-Point Result Register 3
    Uint16                                   rsvd9[4];                     // Reserved
    union   _MPSACTL_REG                     _MPSACTL;                     // CLA PSA Control Register
    Uint16                                   rsvd10;                       // Reserved
    Uint32                                   _MPSA1;                       // CLA PSA1 Register
    Uint32                                   _MPSA2;                       // CLA PSA2 Register
    Uint16                                   rsvd11[56];                   // Reserved
};

struct SOFTINTFRC_BITS {                // bits description
    Uint16 TASK1:1;                     // 0 Force CLA software interrupt for the corresponding task.
    Uint16 TASK2:1;                     // 1 Force CLA software interrupt for the corresponding task.
    Uint16 TASK3:1;                     // 2 Force CLA software interrupt for the corresponding task.
    Uint16 TASK4:1;                     // 3 Force CLA software interrupt for the corresponding task.
    Uint16 TASK5:1;                     // 4 Force CLA software interrupt for the corresponding task.
    Uint16 TASK6:1;                     // 5 Force CLA software interrupt for the corresponding task.
    Uint16 TASK7:1;                     // 6 Force CLA software interrupt for the corresponding task.
    Uint16 TASK8:1;                     // 7 Force CLA software interrupt for the corresponding task.
    Uint16 rsvd1:8;                     // 15:8 Reserved
};

union SOFTINTFRC_REG {
    Uint16  all;
    struct  SOFTINTFRC_BITS  bit;
};

struct CLA_ONLY_REGS {
    Uint16                                   rsvd1[128];                   // Reserved
    Uint16                                   _MVECTBGRNDACTIVE;            // Active register for MVECTBGRND.
    Uint16                                   rsvd2[63];                    // Reserved
    union   _MPSACTL_REG                     _MPSACTL;                     // CLA PSA Control Register
    Uint16                                   rsvd3;                        // Reserved
    Uint32                                   _MPSA1;                       // CLA PSA1 Register
    Uint32                                   _MPSA2;                       // CLA PSA2 Register
    Uint16                                   rsvd4[26];                    // Reserved
    union   SOFTINTEN_REG                    SOFTINTEN;                    // CLA Software Interrupt Enable Register
    Uint16                                   rsvd5;                        // Reserved
    union   SOFTINTFRC_REG                   SOFTINTFRC;                   // CLA Software Interrupt Force Register
    Uint16                                   rsvd6[12];                    // Reserved
};

struct CLA_SOFTINT_REGS {
    union   SOFTINTEN_REG                    SOFTINTEN;                    // CLA Software Interrupt Enable Register
    Uint16                                   rsvd1;                        // Reserved
    union   SOFTINTFRC_REG                   SOFTINTFRC;                   // CLA Software Interrupt Force Register
    Uint16                                   rsvd2[12];                    // Reserved
};

//---------------------------------------------------------------------------
// CLA External References & Function Declarations:
//
extern volatile struct CLA_ONLY_REGS Cla1OnlyRegs;
extern volatile struct CLA_SOFTINT_REGS Cla1SoftIntRegs;
extern volatile struct CLA_REGS Cla1Regs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
