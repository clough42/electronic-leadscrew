//###########################################################################
//
// FILE:    f28004x_cla_prom_crc32.h
//
// TITLE:   CLA_PROM_CRC32 Register Definitions.
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

#ifndef __F28004X_CLA_PROM_CRC32_H__
#define __F28004X_CLA_PROM_CRC32_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// CLA_PROM_CRC32 Individual Register Bit Definitions:

struct CRC32_CONTROLREG_BITS {          // bits description
    Uint16 START:1;                     // 0 Start Bit
    Uint16 rsvd1:3;                     // 3:1 Reserved
    Uint16 FREE_SOFT:1;                 // 4 emulation control bit
    Uint16 rsvd2:3;                     // 7:5 Reserved
    Uint16 HALT:1;                      // 8 Halt Bit
    Uint16 rsvd3:7;                     // 15:9 Reserved
    Uint16 BLOCKSIZE:7;                 // 22:16 Block size of ROM for which CRC is to be calculated
    Uint16 rsvd4:9;                     // 31:23 Reserved
};

union CRC32_CONTROLREG_REG {
    Uint32  all;
    struct  CRC32_CONTROLREG_BITS  bit;
};

struct CRC32_STATUSREG_BITS {           // bits description
    Uint16 CURRENTADDR:16;              // 15:0 Point to the data fetch unit current address
    Uint16 rsvd1:7;                     // 22:16 Reserved
    Uint16 CRCCHECKSTATUS:1;            // 23 CRC active status
    Uint16 rsvd2:7;                     // 30:24 Reserved
    Uint16 RUNSTATUS:1;                 // 31 CRC active status
};

union CRC32_STATUSREG_REG {
    Uint32  all;
    struct  CRC32_STATUSREG_BITS  bit;
};

struct CRC32_INTEN_BITS {               // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 CRCDONE:1;                   // 1 CRCDONE interrupt enable register
    Uint16 rsvd2:14;                    // 15:2 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union CRC32_INTEN_REG {
    Uint32  all;
    struct  CRC32_INTEN_BITS  bit;
};

struct CRC32_FLG_BITS {                 // bits description
    Uint16 INT:1;                       // 0 Global Interrupt status flag
    Uint16 CRCDONE:1;                   // 1 CRCDONE Interrupt status flag
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CRC32_FLG_REG {
    Uint32  all;
    struct  CRC32_FLG_BITS  bit;
};

struct CRC32_CLR_BITS {                 // bits description
    Uint16 INT:1;                       // 0 Global Interrupt clear
    Uint16 CRCDONE:1;                   // 1 CRCDONE Interrupt clear
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union CRC32_CLR_REG {
    Uint32  all;
    struct  CRC32_CLR_BITS  bit;
};

struct CRC32_FRC_BITS {                 // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 CRCDONE:1;                   // 1 CRCDONE Interrupt force
    Uint16 rsvd2:14;                    // 15:2 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union CRC32_FRC_REG {
    Uint32  all;
    struct  CRC32_FRC_BITS  bit;
};

struct CLA_PROM_CRC32_REGS {
    union   CRC32_CONTROLREG_REG             CRC32_CONTROLREG;             // CRC32-Control Register
    Uint32                                   CRC32_STARTADDRESS;           // CRC32-Start address register
    Uint32                                   CRC32_SEED;                   // CRC32-Seed Register
    union   CRC32_STATUSREG_REG              CRC32_STATUSREG;              // CRC32-Status Register
    Uint32                                   CRC32_CRCRESULT;              // CRC32-CRC result Register
    Uint32                                   CRC32_GOLDENCRC;              // CRC32-Golden CRC register
    Uint16                                   rsvd1[12];                    // Reserved
    union   CRC32_INTEN_REG                  CRC32_INTEN;                  // CRC32-Interrupt enable register
    union   CRC32_FLG_REG                    CRC32_FLG;                    // CRC32-Interrupt Flag Register
    union   CRC32_CLR_REG                    CRC32_CLR;                    // CRC32-Interrupt Clear Register
    union   CRC32_FRC_REG                    CRC32_FRC;                    // CRC32-Interrupt Force Register
};

//---------------------------------------------------------------------------
// CLA_PROM_CRC32 External References & Function Declarations:
//
extern volatile struct CLA_PROM_CRC32_REGS ClaPromCrc0Regs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
