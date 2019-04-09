//###########################################################################
//
// FILE:    f28004x_ecap.h
//
// TITLE:   ECAP Register Definitions.
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

#ifndef __F28004X_ECAP_H__
#define __F28004X_ECAP_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// ECAP Individual Register Bit Definitions:

struct ECCTL0_BITS {                    // bits description
    Uint16 INPUTSEL:7;                  // 6:0 INPUT source select
    Uint16 rsvd1:9;                     // 15:7 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union ECCTL0_REG {
    Uint32  all;
    struct  ECCTL0_BITS  bit;
};

struct ECCTL1_BITS {                    // bits description
    Uint16 CAP1POL:1;                   // 0 Capture Event 1 Polarity select
    Uint16 CTRRST1:1;                   // 1 Counter Reset on Capture Event 1
    Uint16 CAP2POL:1;                   // 2 Capture Event 2 Polarity select
    Uint16 CTRRST2:1;                   // 3 Counter Reset on Capture Event 2
    Uint16 CAP3POL:1;                   // 4 Capture Event 3 Polarity select
    Uint16 CTRRST3:1;                   // 5 Counter Reset on Capture Event 3
    Uint16 CAP4POL:1;                   // 6 Capture Event 4 Polarity select
    Uint16 CTRRST4:1;                   // 7 Counter Reset on Capture Event 4
    Uint16 CAPLDEN:1;                   // 8 Enable Loading CAP1-4 regs on a Cap Event
    Uint16 PRESCALE:5;                  // 13:9 Event Filter prescale select
    Uint16 FREE_SOFT:2;                 // 15:14 Emulation mode
};

union ECCTL1_REG {
    Uint16  all;
    struct  ECCTL1_BITS  bit;
};

struct ECCTL2_BITS {                    // bits description
    Uint16 CONT_ONESHT:1;               // 0 Continuous or one-shot
    Uint16 STOP_WRAP:2;                 // 2:1 Stop value for one-shot, Wrap for continuous
    Uint16 REARM:1;                     // 3 One-shot re-arm
    Uint16 TSCTRSTOP:1;                 // 4 TSCNT counter stop
    Uint16 SYNCI_EN:1;                  // 5 Counter sync-in select
    Uint16 SYNCO_SEL:2;                 // 7:6 Sync-out mode
    Uint16 SWSYNC:1;                    // 8 SW forced counter sync
    Uint16 CAP_APWM:1;                  // 9 CAP/APWM operating mode select
    Uint16 APWMPOL:1;                   // 10 APWM output polarity select
    Uint16 CTRFILTRESET:1;              // 11 Reset event filter, modulus counter, and interrupt flags.
    Uint16 DMAEVTSEL:2;                 // 13:12 DMA event select
    Uint16 MODCNTRSTS:2;                // 15:14 modulo counter status
};

union ECCTL2_REG {
    Uint16  all;
    struct  ECCTL2_BITS  bit;
};

struct ECEINT_BITS {                    // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 CEVT1:1;                     // 1 Capture Event 1 Interrupt Enable
    Uint16 CEVT2:1;                     // 2 Capture Event 2 Interrupt Enable
    Uint16 CEVT3:1;                     // 3 Capture Event 3 Interrupt Enable
    Uint16 CEVT4:1;                     // 4 Capture Event 4 Interrupt Enable
    Uint16 CTROVF:1;                    // 5 Counter Overflow Interrupt Enable
    Uint16 CTR_EQ_PRD:1;                // 6 Period Equal Interrupt Enable
    Uint16 CTR_EQ_CMP:1;                // 7 Compare Equal Interrupt Enable
    Uint16 rsvd2:1;                     // 8 Reserved
    Uint16 rsvd3:7;                     // 15:9 Reserved
};

union ECEINT_REG {
    Uint16  all;
    struct  ECEINT_BITS  bit;
};

struct ECFLG_BITS {                     // bits description
    Uint16 INT:1;                       // 0 Global Flag
    Uint16 CEVT1:1;                     // 1 Capture Event 1 Interrupt Flag
    Uint16 CEVT2:1;                     // 2 Capture Event 2 Interrupt Flag
    Uint16 CEVT3:1;                     // 3 Capture Event 3 Interrupt Flag
    Uint16 CEVT4:1;                     // 4 Capture Event 4 Interrupt Flag
    Uint16 CTROVF:1;                    // 5 Counter Overflow Interrupt Flag
    Uint16 CTR_PRD:1;                   // 6 Period Equal Interrupt Flag
    Uint16 CTR_CMP:1;                   // 7 Compare Equal Interrupt Flag
    Uint16 rsvd1:1;                     // 8 Reserved
    Uint16 rsvd2:7;                     // 15:9 Reserved
};

union ECFLG_REG {
    Uint16  all;
    struct  ECFLG_BITS  bit;
};

struct ECCLR_BITS {                     // bits description
    Uint16 INT:1;                       // 0 ECAP Global Interrupt Status Clear
    Uint16 CEVT1:1;                     // 1 Capture Event 1 Status Clear
    Uint16 CEVT2:1;                     // 2 Capture Event 2 Status Clear
    Uint16 CEVT3:1;                     // 3 Capture Event 3 Status Clear
    Uint16 CEVT4:1;                     // 4 Capture Event 4 Status Clear
    Uint16 CTROVF:1;                    // 5 Counter Overflow Status Clear
    Uint16 CTR_PRD:1;                   // 6 Period Equal Status Clear
    Uint16 CTR_CMP:1;                   // 7 Compare Equal Status Clear
    Uint16 rsvd1:1;                     // 8 Reserved
    Uint16 rsvd2:7;                     // 15:9 Reserved
};

union ECCLR_REG {
    Uint16  all;
    struct  ECCLR_BITS  bit;
};

struct ECFRC_BITS {                     // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 CEVT1:1;                     // 1 Capture Event 1 Force Interrupt
    Uint16 CEVT2:1;                     // 2 Capture Event 2 Force Interrupt
    Uint16 CEVT3:1;                     // 3 Capture Event 3 Force Interrupt
    Uint16 CEVT4:1;                     // 4 Capture Event 4 Force Interrupt
    Uint16 CTROVF:1;                    // 5 Counter Overflow Force Interrupt
    Uint16 CTR_PRD:1;                   // 6 Period Equal Force Interrupt
    Uint16 CTR_CMP:1;                   // 7 Compare Equal Force Interrupt
    Uint16 rsvd2:1;                     // 8 Reserved
    Uint16 rsvd3:7;                     // 15:9 Reserved
};

union ECFRC_REG {
    Uint16  all;
    struct  ECFRC_BITS  bit;
};

struct ECAPSYNCINSEL_BITS {             // bits description
    Uint16 SEL:5;                       // 4:0 SYNCIN source select
    Uint16 rsvd1:11;                    // 15:5 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union ECAPSYNCINSEL_REG {
    Uint32  all;
    struct  ECAPSYNCINSEL_BITS  bit;
};

struct ECAP_REGS {
    Uint32                                   TSCTR;                        // Time-Stamp Counter
    Uint32                                   CTRPHS;                       // Counter Phase Offset Value Register
    Uint32                                   CAP1;                         // Capture 1 Register
    Uint32                                   CAP2;                         // Capture 2 Register
    Uint32                                   CAP3;                         // Capture 3 Register
    Uint32                                   CAP4;                         // Capture 4 Register
    Uint16                                   rsvd1[6];                     // Reserved
    union   ECCTL0_REG                       ECCTL0;                       // Capture Control Register 0
    union   ECCTL1_REG                       ECCTL1;                       // Capture Control Register 1
    union   ECCTL2_REG                       ECCTL2;                       // Capture Control Register 2
    union   ECEINT_REG                       ECEINT;                       // Capture Interrupt Enable Register
    union   ECFLG_REG                        ECFLG;                        // Capture Interrupt Flag Register
    union   ECCLR_REG                        ECCLR;                        // Capture Interrupt Clear Register
    union   ECFRC_REG                        ECFRC;                        // Capture Interrupt Force Register
    Uint16                                   rsvd2[4];                     // Reserved
    union   ECAPSYNCINSEL_REG                ECAPSYNCINSEL;                // SYNC source select register
};

struct HRCTL_BITS {                     // bits description
    Uint16 HRE:1;                       // 0 High Resolution Enable
    Uint16 HRCLKE:1;                    // 1 High Resolution Clock Enable
    Uint16 PRDSEL:1;                    // 2 Calibration Period Match
    Uint16 CALIBSTART:1;                // 3 Calibration start
    Uint16 CALIBSTS:1;                  // 4 Calibration status
    Uint16 CALIBCONT:1;                 // 5 Continuous mode Calibration Select
    Uint16 rsvd1:10;                    // 15:6 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union HRCTL_REG {
    Uint32  all;
    struct  HRCTL_BITS  bit;
};

struct HRINTEN_BITS {                   // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 CALIBDONE:1;                 // 1 Calibration doe interrupt enable
    Uint16 CALPRDCHKSTS:1;              // 2 Calibration period check status enable
    Uint16 rsvd2:13;                    // 15:3 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union HRINTEN_REG {
    Uint32  all;
    struct  HRINTEN_BITS  bit;
};

struct HRFLG_BITS {                     // bits description
    Uint16 CALIBINT:1;                  // 0 Global calibration Interrupt Status Flag
    Uint16 CALIBDONE:1;                 // 1 Calibration Done Interrupt Flag Bit
    Uint16 CALPRDCHKSTS:1;              // 2 Calibration period check status Flag Bi
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union HRFLG_REG {
    Uint32  all;
    struct  HRFLG_BITS  bit;
};

struct HRCLR_BITS {                     // bits description
    Uint16 CALIBINT:1;                  // 0 Clear Global calibration Interrupt Flag
    Uint16 CALIBDONE:1;                 // 1 Clear Calibration Done Interrupt Flag Bit
    Uint16 CALPRDCHKSTS:1;              // 2 Clear Calibration period check status Flag Bit:
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union HRCLR_REG {
    Uint32  all;
    struct  HRCLR_BITS  bit;
};

struct HRFRC_BITS {                     // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 CALIBDONE:1;                 // 1 Force Calibration Done Interrupt Flag Bit
    Uint16 CALPRDCHKSTS:1;              // 2 Force Calibration period check status Flag Bit:
    Uint16 rsvd2:13;                    // 15:3 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union HRFRC_REG {
    Uint32  all;
    struct  HRFRC_BITS  bit;
};

struct HRCAP_REGS {
    union   HRCTL_REG                        HRCTL;                        // High-Res Control Register
    Uint16                                   rsvd1[2];                     // Reserved
    union   HRINTEN_REG                      HRINTEN;                      // High-Res Calibration Interrupt Enable Register
    union   HRFLG_REG                        HRFLG;                        // High-Res Calibration Interrupt Flag Register
    union   HRCLR_REG                        HRCLR;                        // High-Res Calibration Interrupt Clear Register
    union   HRFRC_REG                        HRFRC;                        // High-Res Calibration Interrupt Force Register
    Uint32                                   HRCALPRD;                     // High-Res Calibration Period Register
    Uint32                                   HRSYSCLKCTR;                  // High-Res Calibration SYSCLK Counter Register
    Uint32                                   HRSYSCLKCAP;                  // High-Res Calibration SYSCLK Capture Register
    Uint32                                   HRCLKCTR;                     // High-Res Calibration HRCLK Counter Register
    Uint32                                   HRCLKCAP;                     // High-Res Calibration HRCLK Capture Register
    Uint16                                   rsvd2[10];                    // Reserved
};

//---------------------------------------------------------------------------
// ECAP External References & Function Declarations:
//
extern volatile struct ECAP_REGS ECap1Regs;
extern volatile struct ECAP_REGS ECap2Regs;
extern volatile struct ECAP_REGS ECap3Regs;
extern volatile struct ECAP_REGS ECap4Regs;
extern volatile struct ECAP_REGS ECap5Regs;
extern volatile struct ECAP_REGS ECap6Regs;
extern volatile struct ECAP_REGS ECap7Regs;
extern volatile struct HRCAP_REGS HRCap6Regs;
extern volatile struct HRCAP_REGS HRCap7Regs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
