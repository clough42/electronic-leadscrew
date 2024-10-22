//###########################################################################
//
// FILE:   F2806x_Cputimers.h
//
// TITLE:  F2806x Device CPUTIMERS Register Definitions.
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

#ifndef F2806x_CPUTIMERS_H
#define F2806x_CPUTIMERS_H

#ifdef __cplusplus
extern "C" {
#endif

//
// CPUTIMERS Individual Register Bit Definitions
//
struct TCR_BITS
{
	Uint16	rsvd1:4;		// 3:0  	Reserved
	Uint16	TSS:1;			// 4	CPU-Timer Top Status Bit
	Uint16	TRB:1;			// 5	CPU-Timer Reload Bit
	Uint16	rsvd2:4;		// 9:6	Reserved
	Uint16	SOFT:1;			// 10	CPU-Timer Emulation Mode
	Uint16	FREE:1;			// 11 	CPU-Timer Emulation Mode
	Uint16	rsvd3:2;		// 13:12	Reserved
	Uint16	TIE:1;			// 14	CPU-Timer Interrupt Enable
    Uint16	TIF:1;			// 15	CPU-Timer Interrupt Flag
};

union TCR_REG
{
	Uint16 all;
	struct TCR_BITS	bit;
};

struct TPR_BITS
{
    Uint16	TDDR:8;			// 7:0  	CPU-Timer Divide-Down
    Uint16	PSC:8;			// 15:8	CPU-Timer Prescale Counter
};

union TPR_REG
{
	Uint16 all;
	struct TPR_BITS	bit;
};

struct TPRH_BITS
{
	Uint16	TDDRH:8;		// 7:0  	CPU-Timer Divide-Down High Bits
	Uint16	PSCH:8;			// 15:8	CPU-Timer Prescale Counter High Bits
};

union TPRH_REG
{
	Uint16 all;
	struct TPRH_BITS	bit;
};

//
// TIM, TIMH: Timer register definitions:
//
struct TIM_REG
{
    Uint16  LSW;
    Uint16  MSW;
};

union TIM_GROUP
{
    Uint32          all;
    struct TIM_REG  half;
};

//
// PRD, PRDH: Period register definitions
//
struct PRD_REG
{
    Uint16  LSW;
    Uint16  MSW;
};

union PRD_GROUP
{
    Uint32          all;
    struct PRD_REG  half;
};

struct CPUTIMER_REGS
{
	union TIM_GROUP 	TIM;   		// Timer counter register
   	union PRD_GROUP 	PRD;   		// Period register
	union	TCR_REG		TCR;		// CPU-Timer Control Register
	Uint16				rsvd1;		// Reserved
	union	TPR_REG		TPR;		// CPU-Timer Prescale Register
	union	TPRH_REG	TPRH;		// CPU-Timer Prescale Register High
};

//
// Cputimers External References & Function Declarations:
//

//
// CPU Timer Support Variables:
//
struct CPUTIMER_VARS
{
    volatile struct  CPUTIMER_REGS  *RegsAddr;
    Uint32    InterruptCount;
    float   CPUFreqInMHz;
    float   PeriodInUSec;
};

//
// Function prototypes and external definitions:
//
void InitCpuTimers(void);
void ConfigCpuTimer(struct CPUTIMER_VARS *Timer, float Freq, float Period);

extern volatile struct CPUTIMER_REGS CpuTimer0Regs;
extern struct CPUTIMER_VARS CpuTimer0;

extern volatile struct CPUTIMER_REGS CpuTimer1Regs;
extern volatile struct CPUTIMER_REGS CpuTimer2Regs;

extern struct CPUTIMER_VARS CpuTimer1;
extern struct CPUTIMER_VARS CpuTimer2;

//
// Usefull Timer Operations:
//

//
// Start Timer:
//
#define StartCpuTimer0()   CpuTimer0Regs.TCR.bit.TSS = 0

//
// Stop Timer:
//
#define StopCpuTimer0()   CpuTimer0Regs.TCR.bit.TSS = 1

// Reload Timer With period Value:
#define ReloadCpuTimer0() CpuTimer0Regs.TCR.bit.TRB = 1

//
// Read 32-Bit Timer Value:
//
#define ReadCpuTimer0Counter() CpuTimer0Regs.TIM.all

//
// Read 32-Bit Period Value:
//
#define ReadCpuTimer0Period() CpuTimer0Regs.PRD.all

// Start Timer:
#define StartCpuTimer1()   CpuTimer1Regs.TCR.bit.TSS = 0
#define StartCpuTimer2()   CpuTimer2Regs.TCR.bit.TSS = 0

//
// Stop Timer:
//
#define StopCpuTimer1()   CpuTimer1Regs.TCR.bit.TSS = 1
#define StopCpuTimer2()   CpuTimer2Regs.TCR.bit.TSS = 1

// Reload Timer With period Value:
#define ReloadCpuTimer1() CpuTimer1Regs.TCR.bit.TRB = 1
#define ReloadCpuTimer2() CpuTimer2Regs.TCR.bit.TRB = 1

//
// Read 32-Bit Timer Value:
//
#define ReadCpuTimer1Counter() CpuTimer1Regs.TIM.all
#define ReadCpuTimer2Counter() CpuTimer2Regs.TIM.all

//
// Read 32-Bit Period Value:
//
#define ReadCpuTimer1Period() CpuTimer1Regs.PRD.all
#define ReadCpuTimer2Period() CpuTimer2Regs.PRD.all
#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of F2806x_CPUTIMERS_H definition

//
// End of file
//

