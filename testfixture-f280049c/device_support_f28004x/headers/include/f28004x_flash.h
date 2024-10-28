//###########################################################################
//
// FILE:    f28004x_flash.h
//
// TITLE:   FLASH Register Definitions.
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

#ifndef __F28004X_FLASH_H__
#define __F28004X_FLASH_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// FLASH Individual Register Bit Definitions:

struct FRDCNTL_BITS {                   // bits description
    Uint16 rsvd1:8;                     // 7:0 Reserved
    Uint16 RWAIT:4;                     // 11:8 Random Read Waitstate
    Uint16 rsvd2:4;                     // 15:12 Reserved
    Uint16 rsvd3:16;                    // 31:16 Reserved
};

union FRDCNTL_REG {
    Uint32  all;
    struct  FRDCNTL_BITS  bit;
};

struct FBAC_BITS {                      // bits description
    Uint16 rsvd1:8;                     // 7:0 Reserved
    Uint16 BAGP:8;                      // 15:8 Bank Active Grace Period
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FBAC_REG {
    Uint32  all;
    struct  FBAC_BITS  bit;
};

struct FBFALLBACK_BITS {                // bits description
    Uint16 BNKPWR0:2;                   // 1:0 Bank Power Mode of BANK0
    Uint16 BNKPWR1:2;                   // 3:2 Bank Power Mode of BANK1
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FBFALLBACK_REG {
    Uint32  all;
    struct  FBFALLBACK_BITS  bit;
};

struct FBPRDY_BITS {                    // bits description
    Uint16 BANK0RDY:1;                  // 0 Flash Bank Active Power State
    Uint16 BANK1RDY:1;                  // 1 Flash Bank Active Power State
    Uint16 rsvd1:13;                    // 14:2 Reserved
    Uint16 PUMPRDY:1;                   // 15 Flash Pump Active Power Mode
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FBPRDY_REG {
    Uint32  all;
    struct  FBPRDY_BITS  bit;
};

struct FPAC1_BITS {                     // bits description
    Uint16 PMPPWR:1;                    // 0 Charge Pump Fallback Power Mode
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 PSLEEP:12;                   // 27:16 Pump Sleep Down Count
    Uint16 rsvd2:4;                     // 31:28 Reserved
};

union FPAC1_REG {
    Uint32  all;
    struct  FPAC1_BITS  bit;
};

struct FPAC2_BITS {                     // bits description
    Uint16 PAGP:16;                     // 15:0 Pump Active Grace Period
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union FPAC2_REG {
    Uint32  all;
    struct  FPAC2_BITS  bit;
};

struct FMSTAT_BITS {                    // bits description
    Uint16 rsvd1:1;                     // 0 Reserved
    Uint16 rsvd2:1;                     // 1 Reserved
    Uint16 rsvd3:1;                     // 2 Reserved
    Uint16 VOLTSTAT:1;                  // 3 Flash Pump Power Status
    Uint16 CSTAT:1;                     // 4 Command Fail Status
    Uint16 INVDAT:1;                    // 5 Invalid Data
    Uint16 PGM:1;                       // 6 Program Operation Status
    Uint16 ERS:1;                       // 7 Erase Operation Status
    Uint16 BUSY:1;                      // 8 Busy Bit
    Uint16 rsvd4:1;                     // 9 Reserved
    Uint16 EV:1;                        // 10 Erase Verify Status
    Uint16 rsvd5:1;                     // 11 Reserved
    Uint16 PGV:1;                       // 12 Programming Verify Status
    Uint16 rsvd6:1;                     // 13 Reserved
    Uint16 rsvd7:1;                     // 14 Reserved
    Uint16 rsvd8:1;                     // 15 Reserved
    Uint16 rsvd9:1;                     // 16 Reserved
    Uint16 rsvd10:1;                    // 17 Reserved
    Uint16 rsvd11:14;                   // 31:18 Reserved
};

union FMSTAT_REG {
    Uint32  all;
    struct  FMSTAT_BITS  bit;
};

struct FRD_INTF_CTRL_BITS {             // bits description
    Uint16 PREFETCH_EN:1;               // 0 Prefetch Enable
    Uint16 DATA_CACHE_EN:1;             // 1 Data Cache Enable
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FRD_INTF_CTRL_REG {
    Uint32  all;
    struct  FRD_INTF_CTRL_BITS  bit;
};

struct FLASH_CTRL_REGS {
    union   FRDCNTL_REG                      FRDCNTL;                      // Flash Read Control Register
    Uint16                                   rsvd1[28];                    // Reserved
    union   FBAC_REG                         FBAC;                         // Flash Bank Access Control Register
    union   FBFALLBACK_REG                   FBFALLBACK;                   // Flash Bank Fallback Power Register
    union   FBPRDY_REG                       FBPRDY;                       // Flash Bank Pump Ready Register
    union   FPAC1_REG                        FPAC1;                        // Flash Pump Access Control Register 1
    union   FPAC2_REG                        FPAC2;                        // Flash Pump Access Control Register 2
    Uint16                                   rsvd2[2];                     // Reserved
    union   FMSTAT_REG                       FMSTAT;                       // Flash Module Status Register
    Uint16                                   rsvd3[340];                   // Reserved
    union   FRD_INTF_CTRL_REG                FRD_INTF_CTRL;                // Flash Read Interface Control Register
};

struct ECC_ENABLE_BITS {                // bits description
    Uint16 ENABLE:4;                    // 3:0 Enable ECC
    Uint16 rsvd1:12;                    // 15:4 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union ECC_ENABLE_REG {
    Uint32  all;
    struct  ECC_ENABLE_BITS  bit;
};

struct ERR_STATUS_BITS {                // bits description
    Uint16 FAIL_0_L:1;                  // 0 Lower 64bits Single Bit Error Corrected Value 0
    Uint16 FAIL_1_L:1;                  // 1 Lower 64bits Single Bit Error Corrected Value 1
    Uint16 UNC_ERR_L:1;                 // 2 Lower 64 bits Uncorrectable error occurred
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 FAIL_0_H:1;                  // 16 Upper 64bits Single Bit Error Corrected Value 0
    Uint16 FAIL_1_H:1;                  // 17 Upper 64bits Single Bit Error Corrected Value 1
    Uint16 UNC_ERR_H:1;                 // 18 Upper 64 bits Uncorrectable error occurred
    Uint16 rsvd2:13;                    // 31:19 Reserved
};

union ERR_STATUS_REG {
    Uint32  all;
    struct  ERR_STATUS_BITS  bit;
};

struct ERR_POS_BITS {                   // bits description
    Uint16 ERR_POS_L:6;                 // 5:0 Bit Position of Single bit Error in lower 64 bits
    Uint16 rsvd1:2;                     // 7:6 Reserved
    Uint16 ERR_TYPE_L:1;                // 8 Error Type in lower 64 bits
    Uint16 rsvd2:7;                     // 15:9 Reserved
    Uint16 ERR_POS_H:6;                 // 21:16 Bit Position of Single bit Error in upper 64 bits
    Uint16 rsvd3:2;                     // 23:22 Reserved
    Uint16 ERR_TYPE_H:1;                // 24 Error Type in upper 64 bits
    Uint16 rsvd4:7;                     // 31:25 Reserved
};

union ERR_POS_REG {
    Uint32  all;
    struct  ERR_POS_BITS  bit;
};

struct ERR_STATUS_CLR_BITS {            // bits description
    Uint16 FAIL_0_L_CLR:1;              // 0 Lower 64bits Single Bit Error Corrected Value 0 Clear
    Uint16 FAIL_1_L_CLR:1;              // 1 Lower 64bits Single Bit Error Corrected Value 1 Clear
    Uint16 UNC_ERR_L_CLR:1;             // 2 Lower 64 bits Uncorrectable error occurred Clear
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 FAIL_0_H_CLR:1;              // 16 Upper 64bits Single Bit Error Corrected Value 0 Clear
    Uint16 FAIL_1_H_CLR:1;              // 17 Upper 64bits Single Bit Error Corrected Value 1 Clear
    Uint16 UNC_ERR_H_CLR:1;             // 18 Upper 64 bits Uncorrectable error occurred Clear
    Uint16 rsvd2:13;                    // 31:19 Reserved
};

union ERR_STATUS_CLR_REG {
    Uint32  all;
    struct  ERR_STATUS_CLR_BITS  bit;
};

struct ERR_CNT_BITS {                   // bits description
    Uint16 ERR_CNT:16;                  // 15:0 Error counter
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union ERR_CNT_REG {
    Uint32  all;
    struct  ERR_CNT_BITS  bit;
};

struct ERR_THRESHOLD_BITS {             // bits description
    Uint16 ERR_THRESHOLD:16;            // 15:0 Error Threshold
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union ERR_THRESHOLD_REG {
    Uint32  all;
    struct  ERR_THRESHOLD_BITS  bit;
};

struct ERR_INTFLG_BITS {                // bits description
    Uint16 SINGLE_ERR_INTFLG:1;         // 0 Single Error Interrupt Flag
    Uint16 UNC_ERR_INTFLG:1;            // 1 Uncorrectable Interrupt Flag
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union ERR_INTFLG_REG {
    Uint32  all;
    struct  ERR_INTFLG_BITS  bit;
};

struct ERR_INTCLR_BITS {                // bits description
    Uint16 SINGLE_ERR_INTCLR:1;         // 0 Single Error Interrupt Flag Clear
    Uint16 UNC_ERR_INTCLR:1;            // 1 Uncorrectable Interrupt Flag Clear
    Uint16 rsvd1:14;                    // 15:2 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union ERR_INTCLR_REG {
    Uint32  all;
    struct  ERR_INTCLR_BITS  bit;
};

struct FADDR_TEST_BITS {                // bits description
    Uint16 rsvd1:3;                     // 2:0 Reserved
    Uint16 ADDRL:13;                    // 15:3 ECC Address Low
    Uint16 ADDRH:6;                     // 21:16 ECC Address High
    Uint16 rsvd2:10;                    // 31:22 Reserved
};

union FADDR_TEST_REG {
    Uint32  all;
    struct  FADDR_TEST_BITS  bit;
};

struct FECC_TEST_BITS {                 // bits description
    Uint16 ECC:8;                       // 7:0 ECC Control Bits
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FECC_TEST_REG {
    Uint32  all;
    struct  FECC_TEST_BITS  bit;
};

struct FECC_CTRL_BITS {                 // bits description
    Uint16 ECC_TEST_EN:1;               // 0 Enable ECC Test Logic
    Uint16 ECC_SELECT:1;                // 1 ECC Bit Select
    Uint16 DO_ECC_CALC:1;               // 2 Enable ECC Calculation
    Uint16 rsvd1:13;                    // 15:3 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FECC_CTRL_REG {
    Uint32  all;
    struct  FECC_CTRL_BITS  bit;
};

struct FECC_STATUS_BITS {               // bits description
    Uint16 SINGLE_ERR:1;                // 0 Test Result is Single Bit Error
    Uint16 UNC_ERR:1;                   // 1 Test Result is Uncorrectable Error
    Uint16 DATA_ERR_POS:6;              // 7:2 Holds Bit Position of Error
    Uint16 ERR_TYPE:1;                  // 8 Holds Bit Position of 8 Check Bits of Error
    Uint16 rsvd1:7;                     // 15:9 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FECC_STATUS_REG {
    Uint32  all;
    struct  FECC_STATUS_BITS  bit;
};

struct FLASH_ECC_REGS {
    union   ECC_ENABLE_REG                   ECC_ENABLE;                   // ECC Enable
    Uint32                                   SINGLE_ERR_ADDR_LOW;          // Single Error Address Low
    Uint32                                   SINGLE_ERR_ADDR_HIGH;         // Single Error Address High
    Uint32                                   UNC_ERR_ADDR_LOW;             // Uncorrectable Error Address Low
    Uint32                                   UNC_ERR_ADDR_HIGH;            // Uncorrectable Error Address High
    union   ERR_STATUS_REG                   ERR_STATUS;                   // Error Status
    union   ERR_POS_REG                      ERR_POS;                      // Error Position
    union   ERR_STATUS_CLR_REG               ERR_STATUS_CLR;               // Error Status Clear
    union   ERR_CNT_REG                      ERR_CNT;                      // Error Control
    union   ERR_THRESHOLD_REG                ERR_THRESHOLD;                // Error Threshold
    union   ERR_INTFLG_REG                   ERR_INTFLG;                   // Error Interrupt Flag
    union   ERR_INTCLR_REG                   ERR_INTCLR;                   // Error Interrupt Flag Clear
    Uint32                                   FDATAH_TEST;                  // Data High Test
    Uint32                                   FDATAL_TEST;                  // Data Low Test
    union   FADDR_TEST_REG                   FADDR_TEST;                   // ECC Test Address
    union   FECC_TEST_REG                    FECC_TEST;                    // ECC Test Address
    union   FECC_CTRL_REG                    FECC_CTRL;                    // ECC Control
    Uint32                                   FOUTH_TEST;                   // Test Data Out High
    Uint32                                   FOUTL_TEST;                   // Test Data Out Low
    union   FECC_STATUS_REG                  FECC_STATUS;                  // ECC Status
};

//---------------------------------------------------------------------------
// FLASH External References & Function Declarations:
//
extern volatile struct FLASH_CTRL_REGS Flash0CtrlRegs;
extern volatile struct FLASH_ECC_REGS Flash0EccRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
