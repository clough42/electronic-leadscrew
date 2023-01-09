//###########################################################################
//
// FILE:   F2806x_DevEmu.h
//
// TITLE:  F2806x Device DEVEMU Register Definitions.
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

#ifndef F2806x_DEVEMU_H
#define F2806x_DEVEMU_H

#ifdef __cplusplus
extern "C" {
#endif

//
// DEVEMU Individual Register Bit Definitions:
//
struct DEVICECNF_BITS
{     
	Uint16	rsvd1:3;			// 2:0	Reserved
	Uint16	VMAPS:1;			// 3	VMAP Configure Status
	Uint16	rsvd2:1;			// 4	Reserved
	Uint16	XRSn:1;				// 5	Reset Input Signal Status
	Uint16	rsvd3:10;			// 15:6	Reserved
	Uint16  rsvd4:3;			// 18:16 Reserved
	Uint16	ENPROT:1;			// 19	Enable Write-Read Protection Mode Bit
	Uint16	rsvd5:7;			// 26:20 Reserved
	Uint16	TRSTn:1;			// 27	Read Status of TRSTn Signal
	Uint16	rsvd6:2;			// 29:28 Reserved
	Uint16	SYSCLK2DIV2DIS:1;	// 30 	SYSCLK2 Clock Divide by 2 Disable Bit
	Uint16	rsvd8:1;			// 31	Reserved
};

union DEVICECNF_REG 
{
	Uint32 all;
	struct DEVICECNF_BITS	bit;
};

//
// CLASSID
//
struct CLASSID_BITS
{
    Uint16 CLASSNO:8;            // 7:0   Class Number
    Uint16 PARTTYPE:8;           // 15:8  Part Type
};

union CLASSID_REG
{
    Uint16               all;
    struct CLASSID_BITS  bit;
};

struct DEV_EMU_REGS
{
    union DEVICECNF_REG DEVICECNF;  // Device Configuration
    union CLASSID_REG   CLASSID;    // Class ID
    Uint16              REVID;      // Device ID
};

//
// PARTID
//
struct PARTID_BITS
{
    Uint16 PARTNO:8;     // 7:0   Part Number
    Uint16 PARTTYPE:8;   // 15:8  Part Type
};

union PARTID_REG
{
    Uint16               all;
    struct PARTID_BITS   bit;
};

struct PARTID_REGS
{
    union PARTID_REG PARTID; // Part ID
};

//
// Devemu External References & Function Declarations:
//
extern volatile struct DEV_EMU_REGS DevEmuRegs;
extern volatile struct PARTID_REGS PartIdRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of F2806x_DEVEMU_H definition

//
// End of file
//

