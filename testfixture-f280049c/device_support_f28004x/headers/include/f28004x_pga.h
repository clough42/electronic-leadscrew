//###########################################################################
//
// FILE:    f28004x_pga.h
//
// TITLE:   PGA Register Definitions.
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

#ifndef __F28004X_PGA_H__
#define __F28004X_PGA_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// PGA Individual Register Bit Definitions:

struct PGACTL_BITS {                    // bits description
    Uint16 PGAEN:1;                     // 0 PGA Enable
    Uint16 FILTRESSEL:4;                // 4:1 Filter Resistor Select
    Uint16 GAIN:3;                      // 7:5 PGA gain setting
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union PGACTL_REG {
    Uint32  all;
    struct  PGACTL_BITS  bit;
};

struct PGALOCK_BITS {                   // bits description
    Uint16 PGACTL:1;                    // 0 Lock bit for PGACTL.
    Uint16 rsvd1:1;                     // 1 Reserved
    Uint16 PGAGAIN3TRIM:1;              // 2 Lock bit for PGAGAIN3TRIM.
    Uint16 PGAGAIN6TRIM:1;              // 3 Lock bit for PGAGAIN6TRIM.
    Uint16 PGAGAIN12TRIM:1;             // 4 Lock bit for PGAGAIN12TRIM.
    Uint16 PGAGAIN24TRIM:1;             // 5 Lock bit for PGAGAIN24TRIM.
    Uint16 rsvd2:1;                     // 6 Reserved
    Uint16 rsvd3:1;                     // 7 Reserved
    Uint16 rsvd4:8;                     // 15:8 Reserved
};

union PGALOCK_REG {
    Uint16  all;
    struct  PGALOCK_BITS  bit;
};

struct PGAGAIN3TRIM_BITS {              // bits description
    Uint16 GAINTRIM:8;                  // 7:0 Gain TRIM value, when gain setting is 3
    Uint16 OFFSETTRIM:8;                // 15:8 OFFSET TRIM value, when Gain setting is 3
};

union PGAGAIN3TRIM_REG {
    Uint16  all;
    struct  PGAGAIN3TRIM_BITS  bit;
};

struct PGAGAIN6TRIM_BITS {              // bits description
    Uint16 GAINTRIM:8;                  // 7:0 Gain TRIM value, when gain setting is 6
    Uint16 OFFSETTRIM:8;                // 15:8 OFFSET TRIM value, when Gain setting is 6
};

union PGAGAIN6TRIM_REG {
    Uint16  all;
    struct  PGAGAIN6TRIM_BITS  bit;
};

struct PGAGAIN12TRIM_BITS {             // bits description
    Uint16 GAINTRIM:8;                  // 7:0 Gain TRIM value, when gain setting is 12
    Uint16 OFFSETTRIM:8;                // 15:8 OFFSET TRIM value, when Gain setting is 12
};

union PGAGAIN12TRIM_REG {
    Uint16  all;
    struct  PGAGAIN12TRIM_BITS  bit;
};

struct PGAGAIN24TRIM_BITS {             // bits description
    Uint16 GAINTRIM:8;                  // 7:0 Gain TRIM value, when gain setting is 24
    Uint16 OFFSETTRIM:8;                // 15:8 OFFSET TRIM value, when Gain setting is 24
};

union PGAGAIN24TRIM_REG {
    Uint16  all;
    struct  PGAGAIN24TRIM_BITS  bit;
};

struct PGATYPE_BITS {                   // bits description
    Uint16 REV:8;                       // 7:0 PGA Revision Field
    Uint16 TYPE:8;                      // 15:8 PGA Type Field
};

union PGATYPE_REG {
    Uint16  all;
    struct  PGATYPE_BITS  bit;
};

struct PGA_REGS {
    union   PGACTL_REG                       PGACTL;                       // PGA Control Register
    union   PGALOCK_REG                      PGALOCK;                      // PGA Lock Register
    Uint16                                   rsvd1;                        // Reserved
    union   PGAGAIN3TRIM_REG                 PGAGAIN3TRIM;                 // PGA Gain Trim Register for a gain setting of 3
    union   PGAGAIN6TRIM_REG                 PGAGAIN6TRIM;                 // PGA Gain Trim Register for a gain setting of 6
    union   PGAGAIN12TRIM_REG                PGAGAIN12TRIM;                // PGA Gain Trim Register for a gain setting of 12
    union   PGAGAIN24TRIM_REG                PGAGAIN24TRIM;                // PGA Gain Trim Register for a gain setting of 24
    union   PGATYPE_REG                      PGATYPE;                      // PGA Type Register
    Uint16                                   rsvd2[7];                     // Reserved
};

//---------------------------------------------------------------------------
// PGA External References & Function Declarations:
//
extern volatile struct PGA_REGS Pga1Regs;
extern volatile struct PGA_REGS Pga2Regs;
extern volatile struct PGA_REGS Pga3Regs;
extern volatile struct PGA_REGS Pga4Regs;
extern volatile struct PGA_REGS Pga5Regs;
extern volatile struct PGA_REGS Pga6Regs;
extern volatile struct PGA_REGS Pga7Regs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
