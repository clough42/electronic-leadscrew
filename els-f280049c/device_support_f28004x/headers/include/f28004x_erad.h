//###########################################################################
//
// FILE:    f28004x_erad.h
//
// TITLE:   ERAD Register Definitions.
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

#ifndef __F28004X_ERAD_H__
#define __F28004X_ERAD_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// ERAD Individual Register Bit Definitions:

struct GLBL_EVENT_STAT_BITS {           // bits description
    Uint16 HWBP1:1;                     // 0 Bus Comparator Module Event Status
    Uint16 HWBP2:1;                     // 1 Bus Comparator Module Event Status
    Uint16 HWBP3:1;                     // 2 Bus Comparator Module Event Status
    Uint16 HWBP4:1;                     // 3 Bus Comparator Module Event Status
    Uint16 HWBP5:1;                     // 4 Bus Comparator Module Event Status
    Uint16 HWBP6:1;                     // 5 Bus Comparator Module Event Status
    Uint16 HWBP7:1;                     // 6 Bus Comparator Module Event Status
    Uint16 HWBP8:1;                     // 7 Bus Comparator Module Event Status
    Uint16 CTM1:1;                      // 8 Counter Module Event Status
    Uint16 CTM2:1;                      // 9 Counter Module Event Status
    Uint16 CTM3:1;                      // 10 Counter Module Event Status
    Uint16 CTM4:1;                      // 11 Counter Module Event Status
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union GLBL_EVENT_STAT_REG {
    Uint16  all;
    struct  GLBL_EVENT_STAT_BITS  bit;
};

struct GLBL_HALT_STAT_BITS {            // bits description
    Uint16 HWBP1:1;                     // 0 Bus Comparator Module Halt Status
    Uint16 HWBP2:1;                     // 1 Bus Comparator Module Halt Status
    Uint16 HWBP3:1;                     // 2 Bus Comparator Module Halt Status
    Uint16 HWBP4:1;                     // 3 Bus Comparator Module Halt Status
    Uint16 HWBP5:1;                     // 4 Bus Comparator Module Halt Status
    Uint16 HWBP6:1;                     // 5 Bus Comparator Module Halt Status
    Uint16 HWBP7:1;                     // 6 Bus Comparator Module Halt Status
    Uint16 HWBP8:1;                     // 7 Bus Comparator Module Halt Status
    Uint16 CTM1:1;                      // 8 Counter Module Halt Status
    Uint16 CTM2:1;                      // 9 Counter Module Halt Status
    Uint16 CTM3:1;                      // 10 Counter Module Halt Status
    Uint16 CTM4:1;                      // 11 Counter Module Halt Status
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union GLBL_HALT_STAT_REG {
    Uint16  all;
    struct  GLBL_HALT_STAT_BITS  bit;
};

struct GLBL_ENABLE_BITS {               // bits description
    Uint16 HWBP1:1;                     // 0 Bus Comparator Module Global Enable
    Uint16 HWBP2:1;                     // 1 Bus Comparator Module Global Enable
    Uint16 HWBP3:1;                     // 2 Bus Comparator Module Global Enable
    Uint16 HWBP4:1;                     // 3 Bus Comparator Module Global Enable
    Uint16 HWBP5:1;                     // 4 Bus Comparator Module Global Enable
    Uint16 HWBP6:1;                     // 5 Bus Comparator Module Global Enable
    Uint16 HWBP7:1;                     // 6 Bus Comparator Module Global Enable
    Uint16 HWBP8:1;                     // 7 Bus Comparator Module Global Enable
    Uint16 CTM1:1;                      // 8 Counter Module Global Enable
    Uint16 CTM2:1;                      // 9 Counter Module Global Enable
    Uint16 CTM3:1;                      // 10 Counter Module Global Enable
    Uint16 CTM4:1;                      // 11 Counter Module Global Enable
    Uint16 rsvd1:4;                     // 15:12 Reserved
};

union GLBL_ENABLE_REG {
    Uint16  all;
    struct  GLBL_ENABLE_BITS  bit;
};

struct GLBL_CTM_RESET_BITS {            // bits description
    Uint16 CTM1:1;                      // 0 Global Reset for the counters
    Uint16 CTM2:1;                      // 1 Global Reset for the counters
    Uint16 CTM3:1;                      // 2 Global Reset for the counters
    Uint16 CTM4:1;                      // 3 Global Reset for the counters
    Uint16 rsvd1:12;                    // 15:4 Reserved
};

union GLBL_CTM_RESET_REG {
    Uint16  all;
    struct  GLBL_CTM_RESET_BITS  bit;
};

struct GLBL_OWNER_BITS {                // bits description
    Uint16 OWNER:2;                     // 1:0 Global Ownership Bits
    Uint16 rsvd1:14;                    // 15:2 Reserved
};

union GLBL_OWNER_REG {
    Uint16  all;
    struct  GLBL_OWNER_BITS  bit;
};

struct ERAD_GLOBAL_REGS {
    union   GLBL_EVENT_STAT_REG              GLBL_EVENT_STAT;              // Global Event Status Register
    Uint16                                   rsvd1;                        // Reserved
    union   GLBL_HALT_STAT_REG               GLBL_HALT_STAT;               // Global Halt Status Register
    Uint16                                   rsvd2;                        // Reserved
    union   GLBL_ENABLE_REG                  GLBL_ENABLE;                  // Global Enable Register
    Uint16                                   rsvd3;                        // Reserved
    union   GLBL_CTM_RESET_REG               GLBL_CTM_RESET;               // Global Counter Reset
    Uint16                                   rsvd4[3];                     // Reserved
    union   GLBL_OWNER_REG                   GLBL_OWNER;                   // Global Ownership
    Uint16                                   rsvd5[8];                     // Reserved
};

struct HWBP_CLEAR_BITS {                // bits description
    Uint16 EVENT_CLR:1;                 // 0 Event Clear register
    Uint16 rsvd1:15;                    // 15:1 Reserved
};

union HWBP_CLEAR_REG {
    Uint16  all;
    struct  HWBP_CLEAR_BITS  bit;
};

struct HWBP_CNTL_BITS {                 // bits description
    Uint16 rsvd1:2;                     // 1:0 Reserved
    Uint16 BUS_SEL:3;                   // 4:2 Bus select bits
    Uint16 STOP:1;                      // 5 Stop bit (Halt/No Halt of CPU)
    Uint16 RTOSINT:1;                   // 6 RTOSINT bit
    Uint16 COMP_MODE:3;                 // 9:7 Compare mode
    Uint16 rsvd2:1;                     // 10 Reserved
    Uint16 rsvd3:1;                     // 11 Reserved
    Uint16 rsvd4:4;                     // 15:12 Reserved
};

union HWBP_CNTL_REG {
    Uint16  all;
    struct  HWBP_CNTL_BITS  bit;
};

struct HWBP_STATUS_BITS {               // bits description
    Uint16 EVENT_FIRED:1;               // 0 HWBP Event Fired bits
    Uint16 rsvd1:7;                     // 7:1 Reserved
    Uint16 MODULE_ID:6;                 // 13:8 Identification bits
    Uint16 STATUS:2;                    // 15:14 Status bits
};

union HWBP_STATUS_REG {
    Uint16  all;
    struct  HWBP_STATUS_BITS  bit;
};

struct ERAD_HWBP_REGS {
    Uint32                                   HWBP_MASK;                    // HWBP Mask Register
    Uint32                                   HWBP_REF;                     // HWBP Reference Register
    union   HWBP_CLEAR_REG                   HWBP_CLEAR;                   // HWBP Clear Register
    Uint16                                   rsvd1;                        // Reserved
    union   HWBP_CNTL_REG                    HWBP_CNTL;                    // HWBP Control Register
    union   HWBP_STATUS_REG                  HWBP_STATUS;                  // HWBP Status Register
};

struct CTM_CNTL_BITS {                  // bits description
    Uint16 rsvd1:2;                     // 1:0 Reserved
    Uint16 START_STOP_MODE:1;           // 2 Start_stop mode bit
    Uint16 EVENT_MODE:1;                // 3 Event mode bit
    Uint16 RST_ON_MATCH:1;              // 4 Reset_on_match bit
    Uint16 rsvd2:1;                     // 5 Reserved
    Uint16 STOP:1;                      // 6 Stop bit (Halt/No Halt of CPU)
    Uint16 RTOSINT:1;                   // 7 RTOSINT bit
    Uint16 START_STOP_CUMULATIVE:1;     // 8 Start stop cumulative bit
    Uint16 rsvd3:1;                     // 9 Reserved
    Uint16 RST_EN:1;                    // 10 Enable Reset
    Uint16 RST_INP_SEL:5;               // 15:11 Reset Input select
};

union CTM_CNTL_REG {
    Uint16  all;
    struct  CTM_CNTL_BITS  bit;
};

struct CTM_STATUS_BITS {                // bits description
    Uint16 EVENT_FIRED:1;               // 0 Counter Event Fired bits
    Uint16 OVERFLOW:1;                  // 1 Counter Overflowed
    Uint16 MODULE_ID:10;                // 11:2 Identification bits
    Uint16 STATUS:4;                    // 15:12 Status bits
};

union CTM_STATUS_REG {
    Uint16  all;
    struct  CTM_STATUS_BITS  bit;
};

struct CTM_INPUT_SEL_BITS {             // bits description
    Uint16 CTM_INP_SEL_EN:1;            // 0 Count input select enable
    Uint16 CNT_INP_SEL:5;               // 5:1 Count input select
    Uint16 STA_INP_SEL:5;               // 10:6 Start input select
    Uint16 STO_INP_SEL:5;               // 15:11 Stop input select
};

union CTM_INPUT_SEL_REG {
    Uint16  all;
    struct  CTM_INPUT_SEL_BITS  bit;
};

struct CTM_CLEAR_BITS {                 // bits description
    Uint16 EVENT_CLEAR:1;               // 0 Clear EVENT_FIRED
    Uint16 OVERFLOW_CLEAR:1;            // 1 Clear OVERFLOW
    Uint16 rsvd1:14;                    // 15:2 Reserved
};

union CTM_CLEAR_REG {
    Uint16  all;
    struct  CTM_CLEAR_BITS  bit;
};

struct CTM_INPUT_SEL_MSB_BITS {         // bits description
    Uint16 CTM_INP_SEL_MSB:1;           // 0 Count input select
    Uint16 rsvd1:3;                     // 3:1 Reserved
    Uint16 STA_INP_SEL_MSB:1;           // 4 Start input select
    Uint16 rsvd2:3;                     // 7:5 Reserved
    Uint16 STO_INP_SEL_MSB:1;           // 8 Stop input select
    Uint16 rsvd3:3;                     // 11:9 Reserved
    Uint16 RST_INP_SEL_MSB:1;           // 12 Reset Input Select
    Uint16 rsvd4:3;                     // 15:13 Reserved
};

union CTM_INPUT_SEL_MSB_REG {
    Uint16  all;
    struct  CTM_INPUT_SEL_MSB_BITS  bit;
};

struct ERAD_COUNTER_REGS {
    union   CTM_CNTL_REG                     CTM_CNTL;                     // Counter Control Register
    union   CTM_STATUS_REG                   CTM_STATUS;                   // Counter Status Register
    Uint32                                   CTM_REF;                      // Counter Reference Register
    Uint32                                   CTM_COUNT;                    // Counter Current Value Register
    Uint32                                   CTM_MAX_COUNT;                // Counter Max Count Value Register
    union   CTM_INPUT_SEL_REG                CTM_INPUT_SEL;                // Counter Input Select Register
    union   CTM_CLEAR_REG                    CTM_CLEAR;                    // Counter Clear Register
    union   CTM_INPUT_SEL_MSB_REG            CTM_INPUT_SEL_MSB;            // Counter Input Select Extension Register
    Uint16                                   rsvd1[5];                     // Reserved
};

//---------------------------------------------------------------------------
// ERAD External References & Function Declarations:
//
extern volatile struct ERAD_GLOBAL_REGS EnhancedDebugGlobalRegs;
extern volatile struct ERAD_HWBP_REGS EnhancedDebugHWBP1Regs;
extern volatile struct ERAD_HWBP_REGS EnhancedDebugHWBP2Regs;
extern volatile struct ERAD_HWBP_REGS EnhancedDebugHWBP3Regs;
extern volatile struct ERAD_HWBP_REGS EnhancedDebugHWBP4Regs;
extern volatile struct ERAD_HWBP_REGS EnhancedDebugHWBP5Regs;
extern volatile struct ERAD_HWBP_REGS EnhancedDebugHWBP6Regs;
extern volatile struct ERAD_HWBP_REGS EnhancedDebugHWBP7Regs;
extern volatile struct ERAD_HWBP_REGS EnhancedDebugHWBP8Regs;
extern volatile struct ERAD_COUNTER_REGS EnhancedDebugCounter1Regs;
extern volatile struct ERAD_COUNTER_REGS EnhancedDebugCounter2Regs;
extern volatile struct ERAD_COUNTER_REGS EnhancedDebugCounter3Regs;
extern volatile struct ERAD_COUNTER_REGS EnhancedDebugCounter4Regs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
