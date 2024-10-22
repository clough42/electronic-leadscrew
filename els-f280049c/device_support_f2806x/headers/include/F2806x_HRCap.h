// TI File $
// Checkin $
//###########################################################################
//
// FILE:   F2806x_HRCap.h
//
// TITLE:  F2806x Device HRCAP Register Definitions.
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

#ifndef F2806x_HRCAP_H
#define F2806x_HRCAP_H

#ifdef __cplusplus
extern "C" {
#endif

//
// HRCAP Individual Register Bit Definitions:
//
struct HCCTL_BITS
{
    Uint16  SOFTRESET:1;            // 0    Soft reset
    Uint16  RISEINTE:1;             // 1    RISE capture interrupt enable
    Uint16  FALLINTE:1;             // 2    FALL capture interrupt enable
    Uint16  OVFINTE:1;              // 3    Counter overflow interrupt enable
    Uint16  rsvd1:4;                // 7:4  Reserved
    Uint16  HCCAPCLKSEL:1;          // 8    HRCAP Capture Clock Select Bit
    Uint16  rsvd2:7;                // 15:9 Reserved
};

union HCCTL_REG
{
    Uint16 all;
    struct HCCTL_BITS   bit;
};

struct HCIFR_BITS
{
    Uint16  INT:1;              // 0    Global interrupt flag
    Uint16  RISE:1;             // 1    RISE capture interrupt flag
    Uint16  FALL:1;             // 2    FALL capture interrupt flag
    Uint16  COUNTEROVF:1;       // 3    Counter overflow interrupt flag
    Uint16  RISEOVF:1;          // 4    RISE interrupt overflow event flag
    Uint16  rsvd1:11;           // 15:5 Reserved
};

union HCIFR_REG
{
    Uint16 all;
    struct HCIFR_BITS   bit;
};

struct HCICLR_BITS
{
    Uint16  INT:1;              // 0    Global interrupt clear
    Uint16  RISE:1;             // 1    RISE capture interrupt clear
    Uint16  FALL:1;             // 2    FALL capture interrupt clear
    Uint16  COUNTEROVF:1;       // 3    Counter overflow interrupt clear
    Uint16  RISEOVF:1;          // 4    RISE interrupt overflow event clear
    Uint16  rsvd1:11;           // 15:5 Reserved
};

union HCICLR_REG
{
    Uint16 all;
    struct HCICLR_BITS  bit;
};

struct HCIFRC_BITS
{
    Uint16  rsvd1:1;        // 0    Reserved
    Uint16  RISE:1;         // 1    RISE capture interrupt force
    Uint16  FALL:1;         // 2    FALL capture interrupt force
    Uint16  COUNTEROVF:1;   // 3    Counter overflow interrupt force
    Uint16  RISEOVF:1;      // 4    Rise Interrupt Overflow Event Flag Force Bit
    Uint16  rsvd2:11;       // 15:5 Reserved
};

union HCIFRC_REG
{
    Uint16 all;
    struct HCIFRC_BITS  bit;
};

struct HRCAP_REGS
{
    union   HCCTL_REG           HCCTL;         // HRCAP Control Register
    union   HCIFR_REG           HCIFR;         // HRCAP Interrupt Flag Register
    union   HCICLR_REG          HCICLR;        // HRCAP Interrupt Clear Register
    union   HCIFRC_REG          HCIFRC;        // HRCAP Interrupt Force Register
    Uint16                      HCCOUNTER;     // HRCAP 16-bit Counter Register
    Uint16                      rsvd1[11];     // Reserved
    
    //
    // HRCAP Capture Counter On Rising Edge 0 Register
    //
    Uint16                      HCCAPCNTRISE0;
    
    Uint16                      rsvd2;          // Reserved
    
    //
    // HRCAP Capture Counter On Falling Edge 0 Register
    //
    Uint16                      HCCAPCNTFALL0;
    
    Uint16                      rsvd3;          // Reserved
    Uint16                      rsvd4;          // Reserved
    Uint16                      rsvd5;          // Reserved
    Uint16                      rsvd6[2];       // Reserved
    
    //
    // HRCAP Capture Counter On Rising Edge 1 Register
    //
    Uint16                      HCCAPCNTRISE1;  
    
    Uint16                      rsvd7;          // Reserved
    
    //
    // HRCAP Capture Counter On Falling Edge 1 Register
    //
    Uint16                      HCCAPCNTFALL1;  
    
    Uint16                      rsvd8;          // Reserved
    Uint16                      rsvd9;          // Reserved
    Uint16                      rsvd10;         // Reserved
    Uint16                      rsvd11;         // Reserved
    Uint16                      rsvd12;         // Reserved
};

//
// Hrcap External References & Function Declarations:
//
extern volatile struct HRCAP_REGS HRCap1Regs;
extern volatile struct HRCAP_REGS HRCap2Regs;
extern volatile struct HRCAP_REGS HRCap3Regs;
extern volatile struct HRCAP_REGS HRCap4Regs;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of F2806x_HRCAP_H definition

//
// End of file
//

