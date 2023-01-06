//###########################################################################
//
// FILE:    f28004x_globalvariabledefs.c
//
// TITLE:   F28004x Global Variables and Data Section Pragmas.
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

#include "f28004x_device.h"     // F28004x Headerfile Include File

//---------------------------------------------------------------------------
// Define Global Peripheral Variables:
//
//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdcaResultFile")
#else
#pragma DATA_SECTION(AdcaResultRegs,"AdcaResultFile");
#endif
volatile struct ADC_RESULT_REGS AdcaResultRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdcbResultFile")
#else
#pragma DATA_SECTION(AdcbResultRegs,"AdcbResultFile");
#endif
volatile struct ADC_RESULT_REGS AdcbResultRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdccResultFile")
#else
#pragma DATA_SECTION(AdccResultRegs,"AdccResultFile");
#endif
volatile struct ADC_RESULT_REGS AdccResultRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdcaRegsFile")
#else
#pragma DATA_SECTION(AdcaRegs,"AdcaRegsFile");
#endif
volatile struct ADC_REGS AdcaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdcbRegsFile")
#else
#pragma DATA_SECTION(AdcbRegs,"AdcbRegsFile");
#endif
volatile struct ADC_REGS AdcbRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AdccRegsFile")
#else
#pragma DATA_SECTION(AdccRegs,"AdccRegsFile");
#endif
volatile struct ADC_REGS AdccRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AnalogSubsysRegsFile")
#else
#pragma DATA_SECTION(AnalogSubsysRegs,"AnalogSubsysRegsFile");
#endif
volatile struct ANALOG_SUBSYS_REGS AnalogSubsysRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CanaRegsFile")
#else
#pragma DATA_SECTION(CanaRegs,"CanaRegsFile");
#endif
volatile struct CAN_REGS CanaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CanbRegsFile")
#else
#pragma DATA_SECTION(CanbRegs,"CanbRegsFile");
#endif
volatile struct CAN_REGS CanbRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cla1RegsFile")
#else
#pragma DATA_SECTION(Cla1Regs,"Cla1RegsFile");
#endif
volatile struct CLA_REGS Cla1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cla1SoftIntRegsFile")
#else
#pragma DATA_SECTION(Cla1SoftIntRegs,"Cla1SoftIntRegsFile");
#endif
volatile struct CLA_SOFTINT_REGS Cla1SoftIntRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ClaPromCrc0RegsFile")
#else
#pragma DATA_SECTION(ClaPromCrc0Regs,"ClaPromCrc0RegsFile");
#endif
volatile struct CLA_PROM_CRC32_REGS ClaPromCrc0Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss1RegsFile")
#else
#pragma DATA_SECTION(Cmpss1Regs,"Cmpss1RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss2RegsFile")
#else
#pragma DATA_SECTION(Cmpss2Regs,"Cmpss2RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss3RegsFile")
#else
#pragma DATA_SECTION(Cmpss3Regs,"Cmpss3RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss3Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss4RegsFile")
#else
#pragma DATA_SECTION(Cmpss4Regs,"Cmpss4RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss4Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss5RegsFile")
#else
#pragma DATA_SECTION(Cmpss5Regs,"Cmpss5RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss5Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss6RegsFile")
#else
#pragma DATA_SECTION(Cmpss6Regs,"Cmpss6RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss6Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Cmpss7RegsFile")
#else
#pragma DATA_SECTION(Cmpss7Regs,"Cmpss7RegsFile");
#endif
volatile struct CMPSS_REGS Cmpss7Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CpuTimer0RegsFile")
#else
#pragma DATA_SECTION(CpuTimer0Regs,"CpuTimer0RegsFile");
#endif
volatile struct CPUTIMER_REGS CpuTimer0Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CpuTimer1RegsFile")
#else
#pragma DATA_SECTION(CpuTimer1Regs,"CpuTimer1RegsFile");
#endif
volatile struct CPUTIMER_REGS CpuTimer1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CpuTimer2RegsFile")
#else
#pragma DATA_SECTION(CpuTimer2Regs,"CpuTimer2RegsFile");
#endif
volatile struct CPUTIMER_REGS CpuTimer2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DacaRegsFile")
#else
#pragma DATA_SECTION(DacaRegs,"DacaRegsFile");
#endif
volatile struct DAC_REGS DacaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DacbRegsFile")
#else
#pragma DATA_SECTION(DacbRegs,"DacbRegsFile");
#endif
volatile struct DAC_REGS DacbRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Dcc0RegsFile")
#else
#pragma DATA_SECTION(Dcc0Regs,"Dcc0RegsFile");
#endif
volatile struct DCC_REGS Dcc0Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DcsmBank0Z1RegsFile")
#else
#pragma DATA_SECTION(DcsmBank0Z1Regs,"DcsmBank0Z1RegsFile");
#endif
volatile struct DCSM_BANK0_Z1_REGS DcsmBank0Z1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DcsmBank0Z2RegsFile")
#else
#pragma DATA_SECTION(DcsmBank0Z2Regs,"DcsmBank0Z2RegsFile");
#endif
volatile struct DCSM_BANK0_Z2_REGS DcsmBank0Z2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DcsmBank1Z1RegsFile")
#else
#pragma DATA_SECTION(DcsmBank1Z1Regs,"DcsmBank1Z1RegsFile");
#endif
volatile struct DCSM_BANK1_Z1_REGS DcsmBank1Z1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DcsmBank1Z2RegsFile")
#else
#pragma DATA_SECTION(DcsmBank1Z2Regs,"DcsmBank1Z2RegsFile");
#endif
volatile struct DCSM_BANK1_Z2_REGS DcsmBank1Z2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DcsmCommonRegsFile")
#else
#pragma DATA_SECTION(DcsmCommonRegs,"DcsmCommonRegsFile");
#endif
volatile struct DCSM_COMMON_REGS DcsmCommonRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DmaRegsFile")
#else
#pragma DATA_SECTION(DmaRegs,"DmaRegsFile");
#endif
volatile struct DMA_REGS DmaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap1RegsFile")
#else
#pragma DATA_SECTION(ECap1Regs,"ECap1RegsFile");
#endif
volatile struct ECAP_REGS ECap1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap2RegsFile")
#else
#pragma DATA_SECTION(ECap2Regs,"ECap2RegsFile");
#endif
volatile struct ECAP_REGS ECap2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap3RegsFile")
#else
#pragma DATA_SECTION(ECap3Regs,"ECap3RegsFile");
#endif
volatile struct ECAP_REGS ECap3Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap4RegsFile")
#else
#pragma DATA_SECTION(ECap4Regs,"ECap4RegsFile");
#endif
volatile struct ECAP_REGS ECap4Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap5RegsFile")
#else
#pragma DATA_SECTION(ECap5Regs,"ECap5RegsFile");
#endif
volatile struct ECAP_REGS ECap5Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap6RegsFile")
#else
#pragma DATA_SECTION(ECap6Regs,"ECap6RegsFile");
#endif
volatile struct ECAP_REGS ECap6Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ECap7RegsFile")
#else
#pragma DATA_SECTION(ECap7Regs,"ECap7RegsFile");
#endif
volatile struct ECAP_REGS ECap7Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Pga1RegsFile")
#else
#pragma DATA_SECTION(Pga1Regs,"Pga1RegsFile");
#endif
volatile struct PGA_REGS Pga1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Pga2RegsFile")
#else
#pragma DATA_SECTION(Pga2Regs,"Pga2RegsFile");
#endif
volatile struct PGA_REGS Pga2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Pga3RegsFile")
#else
#pragma DATA_SECTION(Pga3Regs,"Pga3RegsFile");
#endif
volatile struct PGA_REGS Pga3Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Pga4RegsFile")
#else
#pragma DATA_SECTION(Pga4Regs,"Pga4RegsFile");
#endif
volatile struct PGA_REGS Pga4Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Pga5RegsFile")
#else
#pragma DATA_SECTION(Pga5Regs,"Pga5RegsFile");
#endif
volatile struct PGA_REGS Pga5Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Pga6RegsFile")
#else
#pragma DATA_SECTION(Pga6Regs,"Pga6RegsFile");
#endif
volatile struct PGA_REGS Pga6Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Pga7RegsFile")
#else
#pragma DATA_SECTION(Pga7Regs,"Pga7RegsFile");
#endif
volatile struct PGA_REGS Pga7Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm1RegsFile")
#else
#pragma DATA_SECTION(EPwm1Regs,"EPwm1RegsFile");
#endif
volatile struct EPWM_REGS EPwm1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm2RegsFile")
#else
#pragma DATA_SECTION(EPwm2Regs,"EPwm2RegsFile");
#endif
volatile struct EPWM_REGS EPwm2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm3RegsFile")
#else
#pragma DATA_SECTION(EPwm3Regs,"EPwm3RegsFile");
#endif
volatile struct EPWM_REGS EPwm3Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm4RegsFile")
#else
#pragma DATA_SECTION(EPwm4Regs,"EPwm4RegsFile");
#endif
volatile struct EPWM_REGS EPwm4Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm5RegsFile")
#else
#pragma DATA_SECTION(EPwm5Regs,"EPwm5RegsFile");
#endif
volatile struct EPWM_REGS EPwm5Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm6RegsFile")
#else
#pragma DATA_SECTION(EPwm6Regs,"EPwm6RegsFile");
#endif
volatile struct EPWM_REGS EPwm6Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm7RegsFile")
#else
#pragma DATA_SECTION(EPwm7Regs,"EPwm7RegsFile");
#endif
volatile struct EPWM_REGS EPwm7Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwm8RegsFile")
#else
#pragma DATA_SECTION(EPwm8Regs,"EPwm8RegsFile");
#endif
volatile struct EPWM_REGS EPwm8Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EPwmXbarRegsFile")
#else
#pragma DATA_SECTION(EPwmXbarRegs,"EPwmXbarRegsFile");
#endif
volatile struct EPWM_XBAR_REGS EPwmXbarRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EQep1RegsFile")
#else
#pragma DATA_SECTION(EQep1Regs,"EQep1RegsFile");
#endif
volatile struct EQEP_REGS EQep1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EQep2RegsFile")
#else
#pragma DATA_SECTION(EQep2Regs,"EQep2RegsFile");
#endif
volatile struct EQEP_REGS EQep2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Flash0CtrlRegsFile")
#else
#pragma DATA_SECTION(Flash0CtrlRegs,"Flash0CtrlRegsFile");
#endif
volatile struct FLASH_CTRL_REGS Flash0CtrlRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Flash0EccRegsFile")
#else
#pragma DATA_SECTION(Flash0EccRegs,"Flash0EccRegsFile");
#endif
volatile struct FLASH_ECC_REGS Flash0EccRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("FsiTxaRegsFile")
#else
#pragma DATA_SECTION(FsiTxaRegs,"FsiTxaRegsFile");
#endif
volatile struct FSI_TX_REGS FsiTxaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("FsiRxaRegsFile")
#else
#pragma DATA_SECTION(FsiRxaRegs,"FsiRxaRegsFile");
#endif
volatile struct FSI_RX_REGS FsiRxaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("GpioCtrlRegsFile")
#else
#pragma DATA_SECTION(GpioCtrlRegs,"GpioCtrlRegsFile");
#endif
volatile struct GPIO_CTRL_REGS GpioCtrlRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("GpioDataRegsFile")
#else
#pragma DATA_SECTION(GpioDataRegs,"GpioDataRegsFile");
#endif
volatile struct GPIO_DATA_REGS GpioDataRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("XbarRegsFile")
#else
#pragma DATA_SECTION(XbarRegs,"XbarRegsFile");
#endif
volatile struct XBAR_REGS XbarRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("I2caRegsFile")
#else
#pragma DATA_SECTION(I2caRegs,"I2caRegsFile");
#endif
volatile struct I2C_REGS I2caRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("InputXbarRegsFile")
#else
#pragma DATA_SECTION(InputXbarRegs,"InputXbarRegsFile");
#endif
volatile struct INPUT_XBAR_REGS InputXbarRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("LinaRegsFile")
#else
#pragma DATA_SECTION(LinaRegs,"LinaRegsFile");
#endif
volatile struct LIN_REGS LinaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("LinbRegsFile")
#else
#pragma DATA_SECTION(LinbRegs,"LinbRegsFile");
#endif
volatile struct LIN_REGS LinbRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("MemCfgRegsFile")
#else
#pragma DATA_SECTION(MemCfgRegs,"MemCfgRegsFile");
#endif
volatile struct MEM_CFG_REGS MemCfgRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("AccessProtectionRegsFile")
#else
#pragma DATA_SECTION(AccessProtectionRegs,"AccessProtectionRegsFile");
#endif
volatile struct ACCESS_PROTECTION_REGS AccessProtectionRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("MemoryErrorRegsFile")
#else
#pragma DATA_SECTION(MemoryErrorRegs,"MemoryErrorRegsFile");
#endif
volatile struct MEMORY_ERROR_REGS MemoryErrorRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("NmiIntruptRegsFile")
#else
#pragma DATA_SECTION(NmiIntruptRegs,"NmiIntruptRegsFile");
#endif
volatile struct NMI_INTRUPT_REGS NmiIntruptRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("OutputXbarRegsFile")
#else
#pragma DATA_SECTION(OutputXbarRegs,"OutputXbarRegsFile");
#endif
volatile struct OUTPUT_XBAR_REGS OutputXbarRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("PieCtrlRegsFile")
#else
#pragma DATA_SECTION(PieCtrlRegs,"PieCtrlRegsFile");
#endif
volatile struct PIE_CTRL_REGS PieCtrlRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("PieVectTableFile")
#else
#pragma DATA_SECTION(PieVectTable,"PieVectTableFile");
#endif
volatile struct PIE_VECT_TABLE PieVectTable;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("PmbusaRegsFile")
#else
#pragma DATA_SECTION(PmbusaRegs,"PmbusaRegsFile");
#endif
volatile struct PMBUS_REGS PmbusaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SciaRegsFile")
#else
#pragma DATA_SECTION(SciaRegs,"SciaRegsFile");
#endif
volatile struct SCI_REGS SciaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ScibRegsFile")
#else
#pragma DATA_SECTION(ScibRegs,"ScibRegsFile");
#endif
volatile struct SCI_REGS ScibRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("Sdfm1RegsFile")
#else
#pragma DATA_SECTION(Sdfm1Regs,"Sdfm1RegsFile");
#endif
volatile struct SDFM_REGS Sdfm1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SpiaRegsFile")
#else
#pragma DATA_SECTION(SpiaRegs,"SpiaRegsFile");
#endif
volatile struct SPI_REGS SpiaRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SpibRegsFile")
#else
#pragma DATA_SECTION(SpibRegs,"SpibRegsFile");
#endif
volatile struct SPI_REGS SpibRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("WdRegsFile")
#else
#pragma DATA_SECTION(WdRegs,"WdRegsFile");
#endif
volatile struct WD_REGS WdRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DmaClaSrcSelRegsFile")
#else
#pragma DATA_SECTION(DmaClaSrcSelRegs,"DmaClaSrcSelRegsFile");
#endif
volatile struct DMA_CLA_SRC_SEL_REGS DmaClaSrcSelRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("DevCfgRegsFile")
#else
#pragma DATA_SECTION(DevCfgRegs,"DevCfgRegsFile");
#endif
volatile struct DEV_CFG_REGS DevCfgRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("ClkCfgRegsFile")
#else
#pragma DATA_SECTION(ClkCfgRegs,"ClkCfgRegsFile");
#endif
volatile struct CLK_CFG_REGS ClkCfgRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("CpuSysRegsFile")
#else
#pragma DATA_SECTION(CpuSysRegs,"CpuSysRegsFile");
#endif
volatile struct CPU_SYS_REGS CpuSysRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SysPeriphAcRegsFile")
#else
#pragma DATA_SECTION(SysPeriphAcRegs,"SysPeriphAcRegsFile");
#endif
volatile struct PERIPH_AC_REGS SysPeriphAcRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EnhancedDebugGlobalRegsFile")
#else
#pragma DATA_SECTION(EnhancedDebugGlobalRegs,"EnhancedDebugGlobalRegsFile");
#endif
volatile struct ERAD_GLOBAL_REGS EnhancedDebugGlobalRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EnhancedDebugHWBP1RegsFile")
#else
#pragma DATA_SECTION(EnhancedDebugHWBP1Regs,"EnhancedDebugHWBP1RegsFile");
#endif
volatile struct ERAD_HWBP_REGS EnhancedDebugHWBP1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EnhancedDebugHWBP2RegsFile")
#else
#pragma DATA_SECTION(EnhancedDebugHWBP2Regs,"EnhancedDebugHWBP2RegsFile");
#endif
volatile struct ERAD_HWBP_REGS EnhancedDebugHWBP2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EnhancedDebugHWBP3RegsFile")
#else
#pragma DATA_SECTION(EnhancedDebugHWBP3Regs,"EnhancedDebugHWBP3RegsFile");
#endif
volatile struct ERAD_HWBP_REGS EnhancedDebugHWBP3Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EnhancedDebugHWBP4RegsFile")
#else
#pragma DATA_SECTION(EnhancedDebugHWBP4Regs,"EnhancedDebugHWBP4RegsFile");
#endif
volatile struct ERAD_HWBP_REGS EnhancedDebugHWBP4Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EnhancedDebugHWBP5RegsFile")
#else
#pragma DATA_SECTION(EnhancedDebugHWBP5Regs,"EnhancedDebugHWBP5RegsFile");
#endif
volatile struct ERAD_HWBP_REGS EnhancedDebugHWBP5Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EnhancedDebugHWBP6RegsFile")
#else
#pragma DATA_SECTION(EnhancedDebugHWBP6Regs,"EnhancedDebugHWBP6RegsFile");
#endif
volatile struct ERAD_HWBP_REGS EnhancedDebugHWBP6Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EnhancedDebugHWBP7RegsFile")
#else
#pragma DATA_SECTION(EnhancedDebugHWBP7Regs,"EnhancedDebugHWBP7RegsFile");
#endif
volatile struct ERAD_HWBP_REGS EnhancedDebugHWBP7Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EnhancedDebugHWBP8RegsFile")
#else
#pragma DATA_SECTION(EnhancedDebugHWBP8Regs,"EnhancedDebugHWBP8RegsFile");
#endif
volatile struct ERAD_HWBP_REGS EnhancedDebugHWBP8Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EnhancedDebugCounter1RegsFile")
#else
#pragma DATA_SECTION(EnhancedDebugCounter1Regs,"EnhancedDebugCounter1RegsFile");
#endif
volatile struct ERAD_COUNTER_REGS EnhancedDebugCounter1Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EnhancedDebugCounter2RegsFile")
#else
#pragma DATA_SECTION(EnhancedDebugCounter2Regs,"EnhancedDebugCounter2RegsFile");
#endif
volatile struct ERAD_COUNTER_REGS EnhancedDebugCounter2Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EnhancedDebugCounter3RegsFile")
#else
#pragma DATA_SECTION(EnhancedDebugCounter3Regs,"EnhancedDebugCounter3RegsFile");
#endif
volatile struct ERAD_COUNTER_REGS EnhancedDebugCounter3Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("EnhancedDebugCounter4RegsFile")
#else
#pragma DATA_SECTION(EnhancedDebugCounter4Regs,"EnhancedDebugCounter4RegsFile");
#endif
volatile struct ERAD_COUNTER_REGS EnhancedDebugCounter4Regs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("SyncSocRegsFile")
#else
#pragma DATA_SECTION(SyncSocRegs,"SyncSocRegsFile");
#endif
volatile struct SYNC_SOC_REGS SyncSocRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("XintRegsFile")
#else
#pragma DATA_SECTION(XintRegs,"XintRegsFile");
#endif
volatile struct XINT_REGS XintRegs;



//===========================================================================
// End of file.
//===========================================================================

