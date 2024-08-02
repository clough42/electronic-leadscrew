//###########################################################################
//
// FILE:   F2806x_NmiIntrupt.h
//
// TITLE:  F2806x Device NMI Interrupt Register Definitions
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

#ifndef F2806x_NMIINTRUPT_H
#define F2806x_NMIINTRUPT_H

#ifdef __cplusplus
extern "C" {
#endif

//
//  NMI Interrupt Register Bit Definitions
//
struct NMICFG_BITS
{
    Uint16   rsvd1:1;            // 0         Reserved
    Uint16   CLOCKFAIL:1;        // 1         Fail Interrupt Enable Bits
    Uint16   rsvd2:14;           // 15:2      Reserved
};

union NMICFG_REG
{
    Uint16                         all;
    struct NMICFG_BITS             bit;
};

struct NMIFLG_BITS
{
    Uint16   NMIINT:1;           // 0         NMI Interrupt Flag
    Uint16   CLOCKFAIL:1;        // 1         Clock Fail Interrupt Flags
    Uint16   rsvd1:14;           // 15:2      Reserved
};

union NMIFLG_REG
{
    Uint16                         all;
    struct NMIFLG_BITS             bit;
};

struct NMIFLGCLR_BITS
{
    Uint16   NMIINT:1;           // 0         NMIINT Flag Clear Bit
    Uint16   CLOCKFAIL:1;        // 1         Clock Fail Flag Clear Bit
    Uint16   rsvd1:14;           // 15:2      Reserved
};

union NMIFLGCLR_REG
{
    Uint16                         all;
    struct NMIFLGCLR_BITS          bit;
};

struct NMIFLGFRC_BITS
{
    Uint16   rsvd1:1;            // 0         Reserved
    Uint16   CLOCKFAIL:1;        // 1         Clock Fail Flag Force Bit
    Uint16   rsvd2:14;           // 15:2      Reserved
};

union NMIFLGFRC_REG
{
    Uint16                         all;
    struct NMIFLGFRC_BITS          bit;
};

//
//  NMI Interrupt Register Definitions
//
struct NMIINTRUPT_REGS
{
    union  NMICFG_REG          NMICFG;
    union  NMIFLG_REG          NMIFLG;
    union  NMIFLGCLR_REG       NMIFLGCLR;
    union  NMIFLGFRC_REG       NMIFLGFRC;
    Uint16                     NMIWDCNT;
    Uint16                     NMIWDPRD;
    Uint16                     rsvd1[10];
};

//
//  NMI Interrupt External References and Function Declarations
//
extern volatile struct NMIINTRUPT_REGS NmiIntruptRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of F2806x_NMIINTRUPT_H definition

//
// End of file
//

