//###########################################################################
//
// FILE:    f28004x_xbar.h
//
// TITLE:   XBAR Register Definitions.
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

#ifndef __F28004X_XBAR_H__
#define __F28004X_XBAR_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// XBAR Individual Register Bit Definitions:

struct XBARFLG1_BITS {                  // bits description
    Uint16 CMPSS1_CTRIPL:1;             // 0 Input Flag for CMPSS1.CTRIPL Signal
    Uint16 CMPSS1_CTRIPH:1;             // 1 Input Flag for CMPSS1.CTRIPH Signal
    Uint16 CMPSS2_CTRIPL:1;             // 2 Input Flag for CMPSS2.CTRIPL Signal
    Uint16 CMPSS2_CTRIPH:1;             // 3 Input Flag for CMPSS2.CTRIPH Signal
    Uint16 CMPSS3_CTRIPL:1;             // 4 Input Flag for CMPSS3.CTRIPL Signal
    Uint16 CMPSS3_CTRIPH:1;             // 5 Input Flag for CMPSS3.CTRIPH Signal
    Uint16 CMPSS4_CTRIPL:1;             // 6 Input Flag for CMPSS4.CTRIPL Signal
    Uint16 CMPSS4_CTRIPH:1;             // 7 Input Flag for CMPSS4.CTRIPH Signal
    Uint16 CMPSS5_CTRIPL:1;             // 8 Input Flag for CMPSS5.CTRIPL Signal
    Uint16 CMPSS5_CTRIPH:1;             // 9 Input Flag for CMPSS5.CTRIPH Signal
    Uint16 CMPSS6_CTRIPL:1;             // 10 Input Flag for CMPSS6.CTRIPL Signal
    Uint16 CMPSS6_CTRIPH:1;             // 11 Input Flag for CMPSS6.CTRIPH Signal
    Uint16 CMPSS7_CTRIPL:1;             // 12 Input Flag for CMPSS7.CTRIPL Signal
    Uint16 CMPSS7_CTRIPH:1;             // 13 Input Flag for CMPSS7.CTRIPH Signal
    Uint16 CMPSS8_CTRIPL:1;             // 14 Input Flag for CMPSS8.CTRIPL Signal
    Uint16 CMPSS8_CTRIPH:1;             // 15 Input Flag for CMPSS8.CTRIPH Signal
    Uint16 CMPSS1_CTRIPOUTL:1;          // 16 Input Flag for CMPSS1.CTRIPOUTL Signal
    Uint16 CMPSS1_CTRIPOUTH:1;          // 17 Input Flag for CMPSS1.CTRIPOUTH Signal
    Uint16 CMPSS2_CTRIPOUTL:1;          // 18 Input Flag for CMPSS2.CTRIPOUTL Signal
    Uint16 CMPSS2_CTRIPOUTH:1;          // 19 Input Flag for CMPSS2.CTRIPOUTH Signal
    Uint16 CMPSS3_CTRIPOUTL:1;          // 20 Input Flag for CMPSS3.CTRIPOUTL Signal
    Uint16 CMPSS3_CTRIPOUTH:1;          // 21 Input Flag for CMPSS3.CTRIPOUTH Signal
    Uint16 CMPSS4_CTRIPOUTL:1;          // 22 Input Flag for CMPSS4.CTRIPOUTL Signal
    Uint16 CMPSS4_CTRIPOUTH:1;          // 23 Input Flag for CMPSS4.CTRIPOUTH Signal
    Uint16 CMPSS5_CTRIPOUTL:1;          // 24 Input Flag for CMPSS5.CTRIPOUTL Signal
    Uint16 CMPSS5_CTRIPOUTH:1;          // 25 Input Flag for CMPSS5.CTRIPOUTH Signal
    Uint16 CMPSS6_CTRIPOUTL:1;          // 26 Input Flag for CMPSS6.CTRIPOUTL Signal
    Uint16 CMPSS6_CTRIPOUTH:1;          // 27 Input Flag for CMPSS6.CTRIPOUTH Signal
    Uint16 CMPSS7_CTRIPOUTL:1;          // 28 Input Flag for CMPSS7.CTRIPOUTL Signal
    Uint16 CMPSS7_CTRIPOUTH:1;          // 29 Input Flag for CMPSS7.CTRIPOUTH Signal
    Uint16 CMPSS8_CTRIPOUTL:1;          // 30 Input Flag for CMPSS8.CTRIPOUTL Signal
    Uint16 CMPSS8_CTRIPOUTH:1;          // 31 Input Flag for CMPSS8.CTRIPOUTH Signal
};

union XBARFLG1_REG {
    Uint32  all;
    struct  XBARFLG1_BITS  bit;
};

struct XBARFLG2_BITS {                  // bits description
    Uint16 INPUT1:1;                    // 0 Input Flag for INPUT1 Signal
    Uint16 INPUT2:1;                    // 1 Input Flag for INPUT2 Signal
    Uint16 INPUT3:1;                    // 2 Input Flag for INPUT3 Signal
    Uint16 INPUT4:1;                    // 3 Input Flag for INPUT4 Signal
    Uint16 INPUT5:1;                    // 4 Input Flag for INPUT5 Signal
    Uint16 INPUT6:1;                    // 5 Input Flag for INPUT6 Signal
    Uint16 ADCSOCA:1;                   // 6 Input Flag for ADCSOCA Signal
    Uint16 ADCSOCB:1;                   // 7 Input Flag for ADCSOCB Signal
    Uint16 INPUT7:1;                    // 8 Input Flag for INPUT7 Signal
    Uint16 INPUT8:1;                    // 9 Input Flag for INPUT8 Signal
    Uint16 INPUT9:1;                    // 10 Input Flag for INPUT9 Signal
    Uint16 INPUT10:1;                   // 11 Input Flag for INPUT10\ Signal
    Uint16 INPUT11:1;                   // 12 Input Flag for INPUT11 Signal
    Uint16 INPUT12:1;                   // 13 Input Flag for INPUT12 Signal
    Uint16 INPUT13:1;                   // 14 Input Flag for INPUT13 Signal
    Uint16 INPUT14:1;                   // 15 Input Flag for INPUT14 Signal
    Uint16 ECAP1_OUT:1;                 // 16 Input Flag for ECAP1.OUT Signal
    Uint16 ECAP2_OUT:1;                 // 17 Input Flag for ECAP2.OUT Signal
    Uint16 ECAP3_OUT:1;                 // 18 Input Flag for ECAP3.OUT Signal
    Uint16 ECAP4_OUT:1;                 // 19 Input Flag for ECAP4.OUT Signal
    Uint16 ECAP5_OUT:1;                 // 20 Input Flag for ECAP5.OUT Signal
    Uint16 ECAP6_OUT:1;                 // 21 Input Flag for ECAP6.OUT Signal
    Uint16 EXTSYNCOUT:1;                // 22 Input Flag for EXTSYNCOUT Signal
    Uint16 ADCAEVT1:1;                  // 23 Input Flag for ADCAEVT1 Signal
    Uint16 ADCAEVT2:1;                  // 24 Input Flag for ADCAEVT2 Signal
    Uint16 ADCAEVT3:1;                  // 25 Input Flag for ADCAEVT3 Signal
    Uint16 ADCAEVT4:1;                  // 26 Input Flag for ADCAEVT4 Signal
    Uint16 ADCBEVT1:1;                  // 27 Input Flag for ADCBEVT1 Signal
    Uint16 ADCBEVT2:1;                  // 28 Input Flag for ADCBEVT2 Signal
    Uint16 ADCBEVT3:1;                  // 29 Input Flag for ADCBEVT3 Signal
    Uint16 ADCBEVT4:1;                  // 30 Input Flag for ADCBEVT4 Signal
    Uint16 ADCCEVT1:1;                  // 31 Input Flag for ADCCEVT1 Signal
};

union XBARFLG2_REG {
    Uint32  all;
    struct  XBARFLG2_BITS  bit;
};

struct XBARFLG3_BITS {                  // bits description
    Uint16 ADCCEVT2:1;                  // 0 Input Flag for ADCCEVT2 Signal
    Uint16 ADCCEVT3:1;                  // 1 Input Flag for ADCCEVT3 Signal
    Uint16 ADCCEVT4:1;                  // 2 Input Flag for ADCCEVT4 Signal
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:1;                     // 4 Reserved
    Uint16 rsvd3:1;                     // 5 Reserved
    Uint16 rsvd4:1;                     // 6 Reserved
    Uint16 SD1FLT1_COMPL:1;             // 7 Input Flag for SD1FLT1.COMPL Signal
    Uint16 SD1FLT1_COMPH:1;             // 8 Input Flag for SD1FLT1.COMPH Signal
    Uint16 SD1FLT2_COMPL:1;             // 9 Input Flag for SD1FLT2.COMPL Signal
    Uint16 SD1FLT2_COMPH:1;             // 10 Input Flag for SD1FLT2.COMPH Signal
    Uint16 SD1FLT3_COMPL:1;             // 11 Input Flag for SD1FLT3.COMPL Signal
    Uint16 SD1FLT3_COMPH:1;             // 12 Input Flag for SD1FLT3.COMPH Signal
    Uint16 SD1FLT4_COMPL:1;             // 13 Input Flag for SD1FLT4.COMPL Signal
    Uint16 SD1FLT4_COMPH:1;             // 14 Input Flag for SD1FLT4.COMPH Signal
    Uint16 rsvd5:1;                     // 15 Reserved
    Uint16 rsvd6:1;                     // 16 Reserved
    Uint16 rsvd7:1;                     // 17 Reserved
    Uint16 rsvd8:1;                     // 18 Reserved
    Uint16 rsvd9:1;                     // 19 Reserved
    Uint16 rsvd10:1;                    // 20 Reserved
    Uint16 rsvd11:1;                    // 21 Reserved
    Uint16 rsvd12:1;                    // 22 Reserved
    Uint16 ECAP7_OUT:1;                 // 23 Input Flag for ECAP7.OUT Signal
    Uint16 SD1FLT1_COMPZ:1;             // 24 Input Flag for SD1FLT1.COMPZ Signal
    Uint16 SD1FLT1_DRINT:1;             // 25 Input Flag for SD1FLT1.DRINT Signal
    Uint16 SD1FLT2_COMPZ:1;             // 26 Input Flag for SD1FLT2.COMPZ Signal
    Uint16 SD1FLT2_DRINT:1;             // 27 Input Flag for SD1FLT2.DRINT Signal
    Uint16 SD1FLT3_COMPZ:1;             // 28 Input Flag for SD1FLT3.COMPZ Signal
    Uint16 SD1FLT3_DRINT:1;             // 29 Input Flag for SD1FLT3.DRINT Signal
    Uint16 SD1FLT4_COMPZ:1;             // 30 Input Flag for SD1FLT4.COMPZ Signal
    Uint16 SD1FLT4_DRINT:1;             // 31 Input Flag for SD1FLT4.DRINT Signal
};

union XBARFLG3_REG {
    Uint32  all;
    struct  XBARFLG3_BITS  bit;
};

struct XBARFLG4_BITS {                  // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 rsvd2:1;                     // 1 Reserved
    Uint16 rsvd3:1;                     // 2 Reserved
    Uint16 rsvd4:1;                     // 3 Reserved
    Uint16 rsvd5:1;                     // 4 Reserved
    Uint16 rsvd6:1;                     // 5 Reserved
    Uint16 rsvd7:1;                     // 6 Reserved
    Uint16 rsvd8:1;                     // 7 Reserved
    Uint16 rsvd9:8;                     // 15:8 Reserved
    Uint16 rsvd10:1;                    // 16 Reserved
    Uint16 rsvd11:1;                    // 17 Reserved
    Uint16 rsvd12:1;                    // 18 Reserved
    Uint16 rsvd13:1;                    // 19 Reserved
    Uint16 rsvd14:1;                    // 20 Reserved
    Uint16 rsvd15:1;                    // 21 Reserved
    Uint16 rsvd16:1;                    // 22 Reserved
    Uint16 rsvd17:1;                    // 23 Reserved
    Uint16 rsvd18:7;                    // 30:24 Reserved
    Uint16 CLAHALT:1;                   // 31 Input Flag for CLAHALT Signal
};

union XBARFLG4_REG {
    Uint32  all;
    struct  XBARFLG4_BITS  bit;
};

struct XBARCLR1_BITS {                  // bits description
    Uint16 CMPSS1_CTRIPL:1;             // 0 Input Flag Clear for CMPSS1.CTRIPL Signal
    Uint16 CMPSS1_CTRIPH:1;             // 1 Input Flag Clear for CMPSS1.CTRIPH Signal
    Uint16 CMPSS2_CTRIPL:1;             // 2 Input Flag Clear for CMPSS2.CTRIPL Signal
    Uint16 CMPSS2_CTRIPH:1;             // 3 Input Flag Clear for CMPSS2.CTRIPH Signal
    Uint16 CMPSS3_CTRIPL:1;             // 4 Input Flag Clear for CMPSS3.CTRIPL Signal
    Uint16 CMPSS3_CTRIPH:1;             // 5 Input Flag Clear for CMPSS3.CTRIPH Signal
    Uint16 CMPSS4_CTRIPL:1;             // 6 Input Flag Clear for CMPSS4.CTRIPL Signal
    Uint16 CMPSS4_CTRIPH:1;             // 7 Input Flag Clear for CMPSS4.CTRIPH Signal
    Uint16 CMPSS5_CTRIPL:1;             // 8 Input Flag Clear for CMPSS5.CTRIPL Signal
    Uint16 CMPSS5_CTRIPH:1;             // 9 Input Flag Clear for CMPSS5.CTRIPH Signal
    Uint16 CMPSS6_CTRIPL:1;             // 10 Input Flag Clear for CMPSS6.CTRIPL Signal
    Uint16 CMPSS6_CTRIPH:1;             // 11 Input Flag Clear for CMPSS6.CTRIPH Signal
    Uint16 CMPSS7_CTRIPL:1;             // 12 Input Flag Clear for CMPSS7.CTRIPL Signal
    Uint16 CMPSS7_CTRIPH:1;             // 13 Input Flag Clear for CMPSS7.CTRIPH Signal
    Uint16 CMPSS8_CTRIPL:1;             // 14 Input Flag Clear for CMPSS8.CTRIPL Signal
    Uint16 CMPSS8_CTRIPH:1;             // 15 Input Flag Clear for CMPSS8.CTRIPH Signal
    Uint16 CMPSS1_CTRIPOUTL:1;          // 16 Input Flag Clear for CMPSS1.CTRIPOUTL Signal
    Uint16 CMPSS1_CTRIPOUTH:1;          // 17 Input Flag Clear for CMPSS1.CTRIPOUTH Signal
    Uint16 CMPSS2_CTRIPOUTL:1;          // 18 Input Flag Clear for CMPSS2.CTRIPOUTL Signal
    Uint16 CMPSS2_CTRIPOUTH:1;          // 19 Input Flag Clear for CMPSS2.CTRIPOUTH Signal
    Uint16 CMPSS3_CTRIPOUTL:1;          // 20 Input Flag Clear for CMPSS3.CTRIPOUTL Signal
    Uint16 CMPSS3_CTRIPOUTH:1;          // 21 Input Flag Clear for CMPSS3.CTRIPOUTH Signal
    Uint16 CMPSS4_CTRIPOUTL:1;          // 22 Input Flag Clear for CMPSS4.CTRIPOUTL Signal
    Uint16 CMPSS4_CTRIPOUTH:1;          // 23 Input Flag Clear for CMPSS4.CTRIPOUTH Signal
    Uint16 CMPSS5_CTRIPOUTL:1;          // 24 Input Flag Clear for CMPSS5.CTRIPOUTL Signal
    Uint16 CMPSS5_CTRIPOUTH:1;          // 25 Input Flag Clear for CMPSS5.CTRIPOUTH Signal
    Uint16 CMPSS6_CTRIPOUTL:1;          // 26 Input Flag Clear for CMPSS6.CTRIPOUTL Signal
    Uint16 CMPSS6_CTRIPOUTH:1;          // 27 Input Flag Clear for CMPSS6.CTRIPOUTH Signal
    Uint16 CMPSS7_CTRIPOUTL:1;          // 28 Input Flag Clear for CMPSS7.CTRIPOUTL Signal
    Uint16 CMPSS7_CTRIPOUTH:1;          // 29 Input Flag Clear for CMPSS7.CTRIPOUTH Signal
    Uint16 CMPSS8_CTRIPOUTL:1;          // 30 Input Flag Clear for CMPSS8.CTRIPOUTL Signal
    Uint16 CMPSS8_CTRIPOUTH:1;          // 31 Input Flag Clear for CMPSS8.CTRIPOUTH Signal
};

union XBARCLR1_REG {
    Uint32  all;
    struct  XBARCLR1_BITS  bit;
};

struct XBARCLR2_BITS {                  // bits description
    Uint16 INPUT1:1;                    // 0 Input Flag Clear for INPUT1 Signal
    Uint16 INPUT2:1;                    // 1 Input Flag Clear for INPUT2 Signal
    Uint16 INPUT3:1;                    // 2 Input Flag Clear for INPUT3 Signal
    Uint16 INPUT4:1;                    // 3 Input Flag Clear for INPUT4 Signal
    Uint16 INPUT5:1;                    // 4 Input Flag Clear for INPUT5 Signal
    Uint16 INPUT6:1;                    // 5 Input Flag Clear for INPUT6 Signal
    Uint16 ADCSOCA:1;                   // 6 Input Flag Clear for ADCSOCA Signal
    Uint16 ADCSOCB:1;                   // 7 Input Flag Clear for ADCSOCB Signal
    Uint16 INPUT7:1;                    // 8 Input Flag Clear for INPUT7 Signal
    Uint16 INPUT8:1;                    // 9 Input Flag Clear for INPUT8 Signal
    Uint16 INPUT9:1;                    // 10 Input Flag Clear for INPUT9 Signal
    Uint16 INPUT10:1;                   // 11 Input Flag Clear for INPUT10 Signal
    Uint16 INPUT11:1;                   // 12 Input Flag Clear for INPUT11 Signal
    Uint16 INPUT12:1;                   // 13 Input Flag Clear for INPUT12 Signal
    Uint16 INPUT13:1;                   // 14 Input Flag Clear for INPUT13 Signal
    Uint16 INPUT14:1;                   // 15 Input Flag Clear for INPUT14 Signal
    Uint16 ECAP1_OUT:1;                 // 16 Input Flag Clear for ECAP1.OUT Signal
    Uint16 ECAP2_OUT:1;                 // 17 Input Flag Clear for ECAP2.OUT Signal
    Uint16 ECAP3_OUT:1;                 // 18 Input Flag Clear for ECAP3.OUT Signal
    Uint16 ECAP4_OUT:1;                 // 19 Input Flag Clear for ECAP4.OUT Signal
    Uint16 ECAP5_OUT:1;                 // 20 Input Flag Clear for ECAP5.OUT Signal
    Uint16 ECAP6_OUT:1;                 // 21 Input Flag Clear for ECAP6.OUT Signal
    Uint16 EXTSYNCOUT:1;                // 22 Input Flag Clear for EXTSYNCOUT Signal
    Uint16 ADCAEVT1:1;                  // 23 Input Flag Clear for ADCAEVT1 Signal
    Uint16 ADCAEVT2:1;                  // 24 Input Flag Clear for ADCAEVT2 Signal
    Uint16 ADCAEVT3:1;                  // 25 Input Flag Clear for ADCAEVT3 Signal
    Uint16 ADCAEVT4:1;                  // 26 Input Flag Clear for ADCAEVT4 Signal
    Uint16 ADCBEVT1:1;                  // 27 Input Flag Clear for ADCBEVT1 Signal
    Uint16 ADCBEVT2:1;                  // 28 Input Flag Clear for ADCBEVT2 Signal
    Uint16 ADCBEVT3:1;                  // 29 Input Flag Clear for ADCBEVT3 Signal
    Uint16 ADCBEVT4:1;                  // 30 Input Flag Clear for ADCBEVT4 Signal
    Uint16 ADCCEVT1:1;                  // 31 Input Flag Clear for ADCCEVT1 Signal
};

union XBARCLR2_REG {
    Uint32  all;
    struct  XBARCLR2_BITS  bit;
};

struct XBARCLR3_BITS {                  // bits description
    Uint16 ADCCEVT2:1;                  // 0 Input Flag Clear for ADCCEVT2 Signal
    Uint16 ADCCEVT3:1;                  // 1 Input Flag Clear for ADCCEVT3 Signal
    Uint16 ADCCEVT4:1;                  // 2 Input Flag Clear for ADCCEVT4 Signal
    Uint16 rsvd1:1;                     // 3 Reserved
    Uint16 rsvd2:1;                     // 4 Reserved
    Uint16 rsvd3:1;                     // 5 Reserved
    Uint16 rsvd4:1;                     // 6 Reserved
    Uint16 SD1FLT1_COMPL:1;             // 7 Input Flag Clear for SD1FLT1.COMPL Signal
    Uint16 SD1FLT1_COMPH:1;             // 8 Input Flag Clear for SD1FLT1.COMPH Signal
    Uint16 SD1FLT2_COMPL:1;             // 9 Input Flag Clear for SD1FLT2.COMPL Signal
    Uint16 SD1FLT2_COMPH:1;             // 10 Input Flag Clear for SD1FLT2.COMPH Signal
    Uint16 SD1FLT3_COMPL:1;             // 11 Input Flag Clear for SD1FLT3.COMPL Signal
    Uint16 SD1FLT3_COMPH:1;             // 12 Input Flag Clear for SD1FLT3.COMPH Signal
    Uint16 SD1FLT4_COMPL:1;             // 13 Input Flag Clear for SD1FLT4.COMPL Signal
    Uint16 SD1FLT4_COMPH:1;             // 14 Input Flag Clear for SD1FLT4.COMPH Signal
    Uint16 rsvd5:1;                     // 15 Reserved
    Uint16 rsvd6:1;                     // 16 Reserved
    Uint16 rsvd7:1;                     // 17 Reserved
    Uint16 rsvd8:1;                     // 18 Reserved
    Uint16 rsvd9:1;                     // 19 Reserved
    Uint16 rsvd10:1;                    // 20 Reserved
    Uint16 rsvd11:1;                    // 21 Reserved
    Uint16 rsvd12:1;                    // 22 Reserved
    Uint16 ECAP7_OUT:1;                 // 23 Input Flag clear for ECAP7.OUT Signal
    Uint16 SD1FLT1_COMPZ:1;             // 24 Input Flag clear for SD1FLT1.COMPZ Signal
    Uint16 SD1FLT1_DRINT:1;             // 25 Input Flag clear for SD1FLT1.DRINT Signal
    Uint16 SD1FLT2_COMPZ:1;             // 26 Input Flag clear for SD1FLT2.COMPZ Signal
    Uint16 SD1FLT2_DRINT:1;             // 27 Input Flag clear for SD1FLT2.DRINT Signal
    Uint16 SD1FLT3_COMPZ:1;             // 28 Input Flag clear for SD1FLT3.COMPZ Signal
    Uint16 SD1FLT3_DRINT:1;             // 29 Input Flag clear for SD1FLT3.DRINT Signal
    Uint16 SD1FLT4_COMPZ:1;             // 30 Input Flag clear for SD1FLT4.COMPZ Signal
    Uint16 SD1FLT4_DRINT:1;             // 31 Input Flag clear for SD1FLT4.DRINT Signal
};

union XBARCLR3_REG {
    Uint32  all;
    struct  XBARCLR3_BITS  bit;
};

struct XBARCLR4_BITS {                  // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 rsvd2:1;                     // 1 Reserved
    Uint16 rsvd3:1;                     // 2 Reserved
    Uint16 rsvd4:1;                     // 3 Reserved
    Uint16 rsvd5:1;                     // 4 Reserved
    Uint16 rsvd6:1;                     // 5 Reserved
    Uint16 rsvd7:1;                     // 6 Reserved
    Uint16 rsvd8:1;                     // 7 Reserved
    Uint16 rsvd9:8;                     // 15:8 Reserved
    Uint16 rsvd10:1;                    // 16 Reserved
    Uint16 rsvd11:1;                    // 17 Reserved
    Uint16 rsvd12:1;                    // 18 Reserved
    Uint16 rsvd13:1;                    // 19 Reserved
    Uint16 rsvd14:1;                    // 20 Reserved
    Uint16 rsvd15:1;                    // 21 Reserved
    Uint16 rsvd16:1;                    // 22 Reserved
    Uint16 rsvd17:1;                    // 23 Reserved
    Uint16 rsvd18:7;                    // 30:24 Reserved
    Uint16 CLAHALT:1;                   // 31 Input Flag clear for CLAHALT Signal
};

union XBARCLR4_REG {
    Uint32  all;
    struct  XBARCLR4_BITS  bit;
};

struct XBAR_REGS {
    union   XBARFLG1_REG                     XBARFLG1;                     // X-Bar Input Flag Register 1
    union   XBARFLG2_REG                     XBARFLG2;                     // X-Bar Input Flag Register 2
    union   XBARFLG3_REG                     XBARFLG3;                     // X-Bar Input Flag Register 3
    union   XBARFLG4_REG                     XBARFLG4;                     // X-Bar Input Flag Register 4
    union   XBARCLR1_REG                     XBARCLR1;                     // X-Bar Input Flag Clear Register 1
    union   XBARCLR2_REG                     XBARCLR2;                     // X-Bar Input Flag Clear Register 2
    union   XBARCLR3_REG                     XBARCLR3;                     // X-Bar Input Flag Clear Register 3
    union   XBARCLR4_REG                     XBARCLR4;                     // X-Bar Input Flag Clear Register 4
    Uint16                                   rsvd1[16];                    // Reserved
};

//---------------------------------------------------------------------------
// XBAR External References & Function Declarations:
//
extern volatile struct XBAR_REGS XbarRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
