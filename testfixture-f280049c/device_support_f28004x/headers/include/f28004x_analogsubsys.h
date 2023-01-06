//###########################################################################
//
// FILE:    f28004x_analogsubsys.h
//
// TITLE:   ANALOGSUBSYS Register Definitions.
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

#ifndef __F28004X_ANALOGSUBSYS_H__
#define __F28004X_ANALOGSUBSYS_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// ANALOGSUBSYS Individual Register Bit Definitions:

struct ANAREFPP_BITS {                  // bits description
    Uint16 ANAREFBDIS:1;                // 0 Disable ANAREFB
    Uint16 ANAREFCDIS:1;                // 1 Disable ANAREFC
    Uint16 rsvd1:14;                    // 15:2 Reserved
};

union ANAREFPP_REG {
    Uint16  all;
    struct  ANAREFPP_BITS  bit;
};

struct TSNSCTL_BITS {                   // bits description
    Uint16 ENABLE:1;                    // 0 Temperature Sensor Enable
    Uint16 rsvd1:15;                    // 15:1 Reserved
};

union TSNSCTL_REG {
    Uint16  all;
    struct  TSNSCTL_BITS  bit;
};

struct ANAREFCTL_BITS {                 // bits description
    Uint16 ANAREFASEL:1;                // 0 Analog Reference A Select
    Uint16 ANAREFBSEL:1;                // 1 Analog Reference B Select
    Uint16 ANAREFCSEL:1;                // 2 Analog Reference C Select
    Uint16 rsvd1:5;                     // 7:3 Reserved
    Uint16 ANAREFA2P5SEL:1;             // 8 Analog Reference A Select
    Uint16 ANAREFB2P5SEL:1;             // 9 Analog Reference B Select
    Uint16 ANAREFC2P5SEL:1;             // 10 Analog Reference B Select
    Uint16 rsvd2:5;                     // 15:11 Reserved
};

union ANAREFCTL_REG {
    Uint16  all;
    struct  ANAREFCTL_BITS  bit;
};

struct DCDCCTL_BITS {                   // bits description
    Uint16 DCDCEN:1;                    // 0 DCDC Enable
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:15;                    // 30:16 Reserved
    Uint16 rsvd3:1;                     // 31 Reserved
};

union DCDCCTL_REG {
    Uint32  all;
    struct  DCDCCTL_BITS  bit;
};

struct DCDCSTS_BITS {                   // bits description
    Uint16 INDDETECT:1;                 // 0 Inductor Detected
    Uint16 SWSEQDONE:1;                 // 1 Switch sequence to DC-DC done.
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:13;                    // 15:3 Reserved
};

union DCDCSTS_REG {
    Uint16  all;
    struct  DCDCSTS_BITS  bit;
};

struct CMPHPMXSEL_BITS {                // bits description
    Uint16 CMP1HPMXSEL:3;               // 2:0 CMP1HPMXSEL bits
    Uint16 CMP2HPMXSEL:3;               // 5:3 CMP2HPMXSEL bits
    Uint16 CMP3HPMXSEL:3;               // 8:6 CMP3HPMXSEL bits
    Uint16 CMP4HPMXSEL:3;               // 11:9 CMP4HPMXSEL bits
    Uint16 CMP5HPMXSEL:3;               // 14:12 CMP5HPMXSEL bits
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 CMP6HPMXSEL:3;               // 18:16 CMP6HPMXSEL bits
    Uint16 CMP7HPMXSEL:3;               // 21:19 CMP7HPMXSEL bits
    Uint16 rsvd2:10;                    // 31:22 Reserved
};

union CMPHPMXSEL_REG {
    Uint32  all;
    struct  CMPHPMXSEL_BITS  bit;
};

struct CMPLPMXSEL_BITS {                // bits description
    Uint16 CMP1LPMXSEL:3;               // 2:0 CMP1LPMXSEL bits
    Uint16 CMP2LPMXSEL:3;               // 5:3 CMP2LPMXSEL bits
    Uint16 CMP3LPMXSEL:3;               // 8:6 CMP3LPMXSEL bits
    Uint16 CMP4LPMXSEL:3;               // 11:9 CMP4LPMXSEL bits
    Uint16 CMP5LPMXSEL:3;               // 14:12 CMP5LPMXSEL bits
    Uint16 rsvd1:1;                     // 15 Reserved
    Uint16 CMP6LPMXSEL:3;               // 18:16 CMP6LPMXSEL bits
    Uint16 CMP7LPMXSEL:3;               // 21:19 CMP7LPMXSEL bits
    Uint16 rsvd2:10;                    // 31:22 Reserved
};

union CMPLPMXSEL_REG {
    Uint32  all;
    struct  CMPLPMXSEL_BITS  bit;
};

struct CMPHNMXSEL_BITS {                // bits description
    Uint16 CMP1HNMXSEL:1;               // 0 CMP1HNMXSEL bits
    Uint16 CMP2HNMXSEL:1;               // 1 CMP2HNMXSEL bits
    Uint16 CMP3HNMXSEL:1;               // 2 CMP3HNMXSEL bits
    Uint16 CMP4HNMXSEL:1;               // 3 CMP4HNMXSEL bits
    Uint16 CMP5HNMXSEL:1;               // 4 CMP5HNMXSEL bits
    Uint16 CMP6HNMXSEL:1;               // 5 CMP6HNMXSEL bits
    Uint16 CMP7HNMXSEL:1;               // 6 CMP7HNMXSEL bits
    Uint16 rsvd1:9;                     // 15:7 Reserved
};

union CMPHNMXSEL_REG {
    Uint16  all;
    struct  CMPHNMXSEL_BITS  bit;
};

struct CMPLNMXSEL_BITS {                // bits description
    Uint16 CMP1LNMXSEL:1;               // 0 CMP1LNMXSEL bits
    Uint16 CMP2LNMXSEL:1;               // 1 CMP2LNMXSEL bits
    Uint16 CMP3LNMXSEL:1;               // 2 CMP3LNMXSEL bits
    Uint16 CMP4LNMXSEL:1;               // 3 CMP4LNMXSEL bits
    Uint16 CMP5LNMXSEL:1;               // 4 CMP5LNMXSEL bits
    Uint16 CMP6LNMXSEL:1;               // 5 CMP6LNMXSEL bits
    Uint16 CMP7LNMXSEL:1;               // 6 CMP7LNMXSEL bits
    Uint16 rsvd1:9;                     // 15:7 Reserved
};

union CMPLNMXSEL_REG {
    Uint16  all;
    struct  CMPLNMXSEL_BITS  bit;
};

struct LOCK_BITS {                      // bits description
    Uint16 TSNSCTL:1;                   // 0 TSNSCTL Register lock bit
    Uint16 ANAREFCTL:1;                 // 1 ANAREFCTL Register lock bit
    Uint16 VMONCTL:1;                   // 2 VMONCTL Register lock bit
    Uint16 DCDCCTL:1;                   // 3 DCDCCTL Register lock bit
    Uint16 ADCINMXSEL:1;                // 4 ADCINMXSEL Register lock bit
    Uint16 CMPHPMXSEL:1;                // 5 CMPHPMXSEL Register lock bit
    Uint16 CMPLPMXSEL:1;                // 6 CMPLPMXSEL Register lock bit
    Uint16 CMPHNMXSEL:1;                // 7 CMPHNMXSEL Register lock bit
    Uint16 CMPLNMXSEL:1;                // 8 CMPLNMXSEL Register lock bit
    Uint16 VREGCTL:1;                   // 9 VREGCTL Register lock bit
    Uint16 rsvd1:6;                     // 15:10 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union LOCK_REG {
    Uint32  all;
    struct  LOCK_BITS  bit;
};

struct ANALOG_SUBSYS_REGS {
    Uint16                                   rsvd1[30];                    // Reserved
    union   ANAREFPP_REG                     ANAREFPP;                     // ADC Analog Reference Peripheral Properties register
    Uint16                                   rsvd2[65];                    // Reserved
    union   TSNSCTL_REG                      TSNSCTL;                      // Temperature Sensor Control Register
    Uint16                                   rsvd3[7];                     // Reserved
    union   ANAREFCTL_REG                    ANAREFCTL;                    // Analog Reference Control Register
    Uint16                                   rsvd4[15];                    // Reserved
    union   DCDCCTL_REG                      DCDCCTL;                      // DC-DC control register.
    union   DCDCSTS_REG                      DCDCSTS;                      // DC-DC status register.
    Uint16                                   rsvd5[7];                     // Reserved
    union   CMPHPMXSEL_REG                   CMPHPMXSEL;                   // Bits to select one of the many sources on CopmHP inputs. Refer to Pimux diagram for details.
    union   CMPLPMXSEL_REG                   CMPLPMXSEL;                   // Bits to select one of the many sources on CopmLP inputs. Refer to Pimux diagram for details.
    union   CMPHNMXSEL_REG                   CMPHNMXSEL;                   // Bits to select one of the many sources on CopmHN inputs. Refer to Pimux diagram for details.
    union   CMPLNMXSEL_REG                   CMPLNMXSEL;                   // Bits to select one of the many sources on CopmLN inputs. Refer to Pimux diagram for details.
    Uint16                                   rsvd6[6];                     // Reserved
    union   LOCK_REG                         LOCK;                         // Lock Register
};

//---------------------------------------------------------------------------
// ANALOGSUBSYS External References & Function Declarations:
//
extern volatile struct ANALOG_SUBSYS_REGS AnalogSubsysRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
