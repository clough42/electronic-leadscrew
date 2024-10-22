//###########################################################################
//
// FILE:   F2806x_GlobalPrototypes.h
//
// TITLE:  Global prototypes for F2806x Examples
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

#ifndef F2806x_GLOBALPROTOTYPES_H
#define F2806x_GLOBALPROTOTYPES_H

#ifdef __cplusplus
extern "C" {
#endif
//
// Global Function Prototypes
//
extern void InitAdc(void);
extern void InitAdcAio(void);
extern void AdcOffsetSelfCal(void);
extern void AdcChanSelect(Uint16 ch_no);
extern Uint16 AdcConversion (void);
extern void InitPeripherals(void);
extern void DMAInitialize(void);

//
// DMA Channel 1
//
extern void DMACH1AddrConfig(volatile Uint16 *DMA_Dest,
                             volatile Uint16 *DMA_Source);
extern void DMACH1BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep);
extern void DMACH1TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep);
extern void DMACH1WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, 
                             int16 deswstep);
extern void DMACH1ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, 
                             Uint16 cont, Uint16 synce, Uint16 syncsel, 
                             Uint16 ovrinte, Uint16 datasize, Uint16 chintmode,
                             Uint16 chinte);
extern void StartDMACH1(void);

//
// DMA Channel 2
//
extern void DMACH2AddrConfig(volatile Uint16 *DMA_Dest,
                             volatile Uint16 *DMA_Source);
extern void DMACH2BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep);
extern void DMACH2TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep);
extern void DMACH2WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, 
                             int16 deswstep);
extern void DMACH2ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, 
                             Uint16 cont, Uint16 synce, Uint16 syncsel, 
                             Uint16 ovrinte, Uint16 datasize, Uint16 chintmode,
                             Uint16 chinte);
extern void StartDMACH2(void);

//
// DMA Channel 3
//
extern void DMACH3AddrConfig(volatile Uint16 *DMA_Dest,
                             volatile Uint16 *DMA_Source);
extern void DMACH3BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep);
extern void DMACH3TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep);
extern void DMACH3WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize,
                             int16 deswstep);
extern void DMACH3ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, 
                             Uint16 cont, Uint16 synce, Uint16 syncsel,
                             Uint16 ovrinte, Uint16 datasize, Uint16 chintmode,
                             Uint16 chinte);
extern void StartDMACH3(void);

//
// DMA Channel 4
//
extern void DMACH4AddrConfig(volatile Uint16 *DMA_Dest,
                             volatile Uint16 *DMA_Source);
extern void DMACH4BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep);
extern void DMACH4TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep);
extern void DMACH4WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize,
                             int16 deswstep);
extern void DMACH4ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot,
                             Uint16 cont, Uint16 synce, Uint16 syncsel,
                             Uint16 ovrinte, Uint16 datasize, Uint16 chintmode,
                             Uint16 chinte);
extern void StartDMACH4(void);

//
// DMA Channel 5
//
extern void DMACH5AddrConfig(volatile Uint16 *DMA_Dest,
                             volatile Uint16 *DMA_Source);
extern void DMACH5BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep);
extern void DMACH5TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep);
extern void DMACH5WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize,
                             int16 deswstep);
extern void DMACH5ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot,
                             Uint16 cont, Uint16 synce, Uint16 syncsel, 
                             Uint16 ovrinte, Uint16 datasize, Uint16 chintmode,
                             Uint16 chinte);
extern void StartDMACH5(void);

//
// DMA Channel 6
//
extern void DMACH6AddrConfig(volatile Uint16 *DMA_Dest,
                             volatile Uint16 *DMA_Source);
extern void DMACH6BurstConfig(Uint16 bsize,Uint16 srcbstep, int16 desbstep);
extern void DMACH6TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep);
extern void DMACH6WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize,
                             int16 deswstep);
extern void DMACH6ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot,
                             Uint16 cont, Uint16 synce, Uint16 syncsel,
                             Uint16 ovrinte, Uint16 datasize, Uint16 chintmode,
                             Uint16 chinte);
extern void StartDMACH6(void);

extern void InitECap(void);
extern void InitECapGpio(void);

#if DSP28_ECAP1
extern void InitECap1Gpio(void);
#endif // endif DSP28_ECAP1
#if DSP28_ECAP2
extern void InitECap2Gpio(void);
#endif // endif DSP28_ECAP2
#if DSP28_ECAP3
extern void InitECap3Gpio(void);
#endif // endif DSP28_ECAP3

extern void InitComp(void);
extern void InitCompGpio(void);
#if DSP28_COMP1
extern void InitComp1Gpio(void);
#endif // endif DSP28_COMP1
#if DSP28_COMP2
extern void InitComp2Gpio(void);
#endif // endif DSP28_COMP2
#if DSP28_COMP3
extern void InitComp3Gpio(void);
#endif // endif DSP28_COMP3

#if DSP28_ECANA
extern void InitECan(void);
extern void InitECana(void);
extern void InitECanGpio(void);
extern void InitECanaGpio(void);
#endif // endif DSP28_ECANA

extern void InitEPwm(void);
extern void InitEPwmGpio(void);
#if DSP28_EPWM1
extern void InitEPwm1Gpio(void);
#endif // endif DSP28_EPWM1
#if DSP28_EPWM2
extern void InitEPwm2Gpio(void);
#endif // endif DSP28_EPWM2
#if DSP28_EPWM3
extern void InitEPwm3Gpio(void);
#endif // endif DSP28_EPWM3
#if DSP28_EPWM4
extern void InitEPwm4Gpio(void);
#endif // endif DSP28_EPWM4
#if DSP28_EPWM5
extern void InitEPwm5Gpio(void);
#endif // endif DSP28_EPWM5
#if DSP28_EPWM6
extern void InitEPwm6Gpio(void);
#endif // endif DSP28_EPWM6
#if DSP28_EPWM7
extern void InitEPwm7Gpio(void);
#endif // endif DSP28_EPWM7
#if DSP28_EPWM8
extern void InitEPwm8Gpio(void);
#endif // endif DSP28_EPWM8

extern void InitEQep(void);
extern void InitEQepGpio(void);
#if DSP28_EQEP1
extern void InitEQep1Gpio(void);
#endif // endif DSP28_EQEP1
#if DSP28_EQEP2
extern void InitEQep2Gpio(void);
#endif // endif DSP28_EQEP2

extern void InitGpio(void);

extern void InitHRCap(void);
extern void InitHRCapGpio(void);
#if DSP28_HRCAP1
extern void InitHRCap1Gpio(void);
#endif
#if DSP28_HRCAP2
extern void InitHRCap2Gpio(void);
#endif
#if DSP28_HRCAP3
extern void InitHRCap3Gpio(void);
#endif
#if DSP28_HRCAP4
extern void InitHRCap4Gpio(void);
#endif

#if DSP28_I2CA
extern void InitI2C(void);
extern void InitI2CGpio(void);
#endif // endif DSP28_I2CA

#if DSP28_MCBSPA
extern void InitMcbsp(void);
extern void InitMcbspa(void);
extern void delay_loop(void);
extern void clkg_delay_loop(void);
extern void InitMcbspGpio(void);
extern void InitMcbspaGpio(void);
extern void InitMcbspa8bit(void);
extern void InitMcbspa12bit(void);
extern void InitMcbspa16bit(void);
extern void InitMcbspa20bit(void);
extern void InitMcbspa24bit(void);
extern void InitMcbspa32bit(void);
#endif // endif DSP28_MCBSPA

extern void InitPieCtrl(void);
extern void InitPieVectTable(void);

extern void InitSci(void);
extern void InitSciGpio(void);
#if DSP28_SCIA
extern void InitSciaGpio(void);
#endif // endif DSP28_SCIA
#if DSP28_SCIB
extern void InitScibGpio(void);
#endif // endif DSP28_SCIB

extern void InitSpi(void);
extern void InitSpiGpio(void);
#if DSP28_SPIA
extern void InitSpiaGpio(void);
#endif // endif DSP28_SPIA
#if DSP28_SPIB
extern void InitSpibGpio(void);
#endif // endif DSP28_SPIB

extern void InitSysCtrl(void);
extern void InitTzGpio(void);
extern void InitXIntrupt(void);
extern void InitPll(Uint16 pllcr, Uint16 clkindiv);
extern void InitPll2(Uint16 clksrc, Uint16 pllmult, Uint16 clkdiv);
extern void InitPeripheralClocks(void);
extern void EnableInterrupts(void);
extern void DSP28x_usDelay(Uint32 Count);

#define KickDog ServiceDog     // For compatiblity with previous versions
extern void ServiceDog(void);
extern void DisableDog(void);

extern Uint16 CsmUnlock(void);
extern void IntOsc1Sel (void);
extern void IntOsc2Sel (void);
extern void XtalOscSel (void);
extern void ExtOscSel (void);

extern int16 GetTemperatureC(int16 sensorSample); // returns temp in deg. C
extern int16 GetTemperatureK(int16 sensorSample); // returns temp in deg. K
extern void Osc1Comp(int16 sensorSample);
extern void Osc2Comp(int16 sensorSample);

//
// DSP28_DBGIER.asm
//
extern void SetDBGIER(Uint16 dbgier);

//
// CAUTION - This function MUST be executed out of RAM. Executing it
// out of OTP/Flash will yield unpredictable results
//
extern void InitFlash(void);

//
// External symbols created by the linker cmd file
// DSP28 examples will use these to relocate code from one LOAD location
// in Flash to a different RUN location in internal RAM
//
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsRunStart;
extern Uint16 RamfuncsLoadSize;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of F2806x_GLOBALPROTOTYPES_H

//
// End of file
//

