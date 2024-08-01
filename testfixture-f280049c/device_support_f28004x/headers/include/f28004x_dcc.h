//###########################################################################
//
// FILE:    f28004x_dcc.h
//
// TITLE:   DCC Register Definitions.
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

#ifndef __F28004X_DCC_H__
#define __F28004X_DCC_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// DCC Individual Register Bit Definitions:

struct DCCGCTRL_BITS {                 // bits description
    bp_16 DCCENA:4;                    // 3:0 DCC Enable
    bp_16 ERRENA:4;                    // 7:4 Error Enable
    bp_16 SINGLESHOT:4;                // 11:8 Single-Shot Enable
    bp_16 DONEENA:4;                   // 15:12 DONE Enable
    bp_32 rsvd1:16;                    // 31:16 Reserved
};

union DCCGCTRL_REG {
    bp_32  all;
    struct  DCCGCTRL_BITS  bit;
};

struct DCCREV_BITS {                   // bits description
    bp_16 MINOR:6;                     // 5:0 Minor Revision Number
    bp_16 CUSTOM:2;                    // 7:6 Custom Module Number
    bp_16 MAJOR:3;                     // 10:8 Major Revision Number
    bp_16 RTL:5;                       // 15:11 Design Release Number
    bp_32 FUNC:12;                     // 27:16 Functional Release Number
    bp_32 rsvd1:2;                     // 29:28 Reserved
    bp_32 SCHEME:2;                    // 31:30 Defines Scheme for Module
};

union DCCREV_REG {
    bp_32  all;
    struct  DCCREV_BITS  bit;
};

struct DCCCNTSEED0_BITS {              // bits description
    bp_32 COUNTSEED0:20;               // 19:0 Seed Value for Counter 0
    bp_32 rsvd1:12;                    // 31:20 Reserved
};

union DCCCNTSEED0_REG {
    bp_32  all;
    struct  DCCCNTSEED0_BITS  bit;
};

struct DCCVALIDSEED0_BITS {            // bits description
    bp_16 VALIDSEED:16;                // 15:0 Seed Value for Valid Duration Counter 0
    bp_32 rsvd1:16;                    // 31:16 Reserved
};

union DCCVALIDSEED0_REG {
    bp_32  all;
    struct  DCCVALIDSEED0_BITS  bit;
};

struct DCCCNTSEED1_BITS {              // bits description
    bp_32 COUNTSEED1:20;               // 19:0 Seed Value for Counter 1
    bp_32 rsvd1:12;                    // 31:20 Reserved
};

union DCCCNTSEED1_REG {
    bp_32  all;
    struct  DCCCNTSEED1_BITS  bit;
};

struct DCCSTATUS_BITS {                // bits description
    bp_16 ERR:1;                       // 0 Error Flag
    bp_16 DONE:1;                      // 1 Single-Shot Done Flag
    bp_16 rsvd1:14;                    // 15:2 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union DCCSTATUS_REG {
    bp_32  all;
    struct  DCCSTATUS_BITS  bit;
};

struct DCCCNT0_BITS {                  // bits description
    bp_32 COUNT0:20;                   // 19:0 Current Value of Counter 0
    bp_32 rsvd1:12;                    // 31:20 Reserved
};

union DCCCNT0_REG {
    bp_32  all;
    struct  DCCCNT0_BITS  bit;
};

struct DCCVALID0_BITS {                // bits description
    bp_16 VALID0:16;                   // 15:0 Current Value of Valid 0
    bp_32 rsvd1:16;                    // 31:16 Reserved
};

union DCCVALID0_REG {
    bp_32  all;
    struct  DCCVALID0_BITS  bit;
};

struct DCCCNT1_BITS {                  // bits description
    bp_32 COUNT1:20;                   // 19:0 Current Value of Counter 1
    bp_32 rsvd1:12;                    // 31:20 Reserved
};

union DCCCNT1_REG {
    bp_32  all;
    struct  DCCCNT1_BITS  bit;
};

struct DCCCLKSRC1_BITS {               // bits description
    bp_16 CLKSRC1:4;                   // 3:0 Clock Source Select for Counter 1
    bp_16 rsvd1:8;                     // 11:4 Reserved
    bp_16 KEY:4;                       // 15:12 Enables or Disables Clock Source Selection for COUNT1
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union DCCCLKSRC1_REG {
    bp_32  all;
    struct  DCCCLKSRC1_BITS  bit;
};

struct DCCCLKSRC0_BITS {               // bits description
    bp_16 CLKSRC0:4;                   // 3:0 Clock Source Select for Counter 0
    bp_16 rsvd1:12;                    // 15:4 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union DCCCLKSRC0_REG {
    bp_32  all;
    struct  DCCCLKSRC0_BITS  bit;
};

struct DCC_REGS {
    union   DCCGCTRL_REG                     DCCGCTRL;                     // Global Control Register
    union   DCCREV_REG                       DCCREV;                       // DCC Revision Register
    union   DCCCNTSEED0_REG                  DCCCNTSEED0;                  // Counter 0 seed value
    union   DCCVALIDSEED0_REG                DCCVALIDSEED0;                // Valid 0 seed value
    union   DCCCNTSEED1_REG                  DCCCNTSEED1;                  // Counter 1 Seed Value
    union   DCCSTATUS_REG                    DCCSTATUS;                    // DCC Status
    union   DCCCNT0_REG                      DCCCNT0;                      // Counter 0 Value
    union   DCCVALID0_REG                    DCCVALID0;                    // Valid Value 0
    union   DCCCNT1_REG                      DCCCNT1;                      // Counter 1 Value
    union   DCCCLKSRC1_REG                   DCCCLKSRC1;                   // Clock Source 1
    union   DCCCLKSRC0_REG                   DCCCLKSRC0;                   // Clock Source 0
};

//---------------------------------------------------------------------------
// DCC External References & Function Declarations:
//
extern volatile struct DCC_REGS Dcc0Regs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
