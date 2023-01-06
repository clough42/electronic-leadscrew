//###########################################################################
//
// FILE:    f28004x_dcsm.h
//
// TITLE:   DCSM Register Definitions.
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

#ifndef __F28004X_DCSM_H__
#define __F28004X_DCSM_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// DCSM Individual Register Bit Definitions:

struct B0_Z1_LINKPOINTER_BITS {         // bits description
    Uint32 LINKPOINTER:29;              // 28:0 Zone1 LINK Pointer for zone Flash BANK0
    Uint16 rsvd1:3;                     // 31:29 Reserved
};

union B0_Z1_LINKPOINTER_REG {
    Uint32  all;
    struct  B0_Z1_LINKPOINTER_BITS  bit;
};

struct Z1_OTPSECLOCK_BITS {             // bits description
    Uint16 JTAGLOCK:4;                  // 3:0 Zone1 JTAG Lock.
    Uint16 PSWDLOCK:4;                  // 7:4 Zone1 Password Lock.
    Uint16 CRCLOCK:4;                   // 11:8 Zone1 CRC Lock.
    Uint16 rsvd1:4;                     // 15:12 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union Z1_OTPSECLOCK_REG {
    Uint32  all;
    struct  Z1_OTPSECLOCK_BITS  bit;
};

struct B0_Z1_LINKPOINTERERR_BITS {      // bits description
    Uint32 Z1_LINKPOINTERERR:29;        // 28:0 Error to Resolve Z1 Link pointer from OTP loaded values
    Uint16 rsvd1:3;                     // 31:29 Reserved
};

union B0_Z1_LINKPOINTERERR_REG {
    Uint32  all;
    struct  B0_Z1_LINKPOINTERERR_BITS  bit;
};

struct Z1_CR_BITS {                     // bits description
    Uint16 rsvd1:3;                     // 2:0 Reserved
    Uint16 ALLZERO:1;                   // 3 CSMPSWD All Zeros
    Uint16 ALLONE:1;                    // 4 CSMPSWD All Ones
    Uint16 UNSECURE:1;                  // 5 CSMPSWD Match CSMKEY
    Uint16 ARMED:1;                     // 6 CSM Passwords Read Status
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 rsvd3:7;                     // 14:8 Reserved
    Uint16 FORCESEC:1;                  // 15 Force Secure
};

union Z1_CR_REG {
    Uint16  all;
    struct  Z1_CR_BITS  bit;
};

struct B0_Z1_GRABSECTR_BITS {           // bits description
    Uint16 GRAB_SECT0:2;                // 1:0 Grab Flash Sector 0 in BANK0
    Uint16 GRAB_SECT1:2;                // 3:2 Grab Flash Sector 1 in BANK0
    Uint16 GRAB_SECT2:2;                // 5:4 Grab Flash Sector 2 in BANK0
    Uint16 GRAB_SECT3:2;                // 7:6 Grab Flash Sector 3 in BANK0
    Uint16 GRAB_SECT4:2;                // 9:8 Grab Flash Sector 4 in BANK0
    Uint16 GRAB_SECT5:2;                // 11:10 Grab Flash Sector 5 in BANK0
    Uint16 GRAB_SECT6:2;                // 13:12 Grab Flash Sector 6 in BANK0
    Uint16 GRAB_SECT7:2;                // 15:14 Grab Flash Sector 7 in BANK0
    Uint16 GRAB_SECT8:2;                // 17:16 Grab Flash Sector 8 in BANK0
    Uint16 GRAB_SECT9:2;                // 19:18 Grab Flash Sector 9 in BANK0
    Uint16 GRAB_SECT10:2;               // 21:20 Grab Flash Sector 10 in BANK0
    Uint16 GRAB_SECT11:2;               // 23:22 Grab Flash Sector 11 in BANK0
    Uint16 GRAB_SECT12:2;               // 25:24 Grab Flash Sector 12 in BANK0
    Uint16 GRAB_SECT13:2;               // 27:26 Grab Flash Sector 13 in BANK0
    Uint16 GRAB_SECT14:2;               // 29:28 Grab Flash Sector 14 in BANK0
    Uint16 GRAB_SECT15:2;               // 31:30 Grab Flash Sector 15 in BANK0
};

union B0_Z1_GRABSECTR_REG {
    Uint32  all;
    struct  B0_Z1_GRABSECTR_BITS  bit;
};

struct Z1_GRABRAMR_BITS {               // bits description
    Uint16 GRAB_RAM0:2;                 // 1:0 Grab RAM LS0
    Uint16 GRAB_RAM1:2;                 // 3:2 Grab RAM LS1
    Uint16 GRAB_RAM2:2;                 // 5:4 Grab RAM LS2
    Uint16 GRAB_RAM3:2;                 // 7:6 Grab RAM LS3
    Uint16 GRAB_RAM4:2;                 // 9:8 Grab RAM LS4
    Uint16 GRAB_RAM5:2;                 // 11:10 Grab RAM LS5
    Uint16 GRAB_RAM6:2;                 // 13:12 Grab RAM LS6
    Uint16 GRAB_RAM7:2;                 // 15:14 Grab RAM LS7
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union Z1_GRABRAMR_REG {
    Uint32  all;
    struct  Z1_GRABRAMR_BITS  bit;
};

struct B0_Z1_EXEONLYSECTR_BITS {        // bits description
    Uint16 EXEONLY_SECT0:1;             // 0 Execute-Only Flash Sector 0 in Flash BANK0
    Uint16 EXEONLY_SECT1:1;             // 1 Execute-Only Flash Sector 1 in Flash BANK0
    Uint16 EXEONLY_SECT2:1;             // 2 Execute-Only Flash Sector 2 in Flash BANK0
    Uint16 EXEONLY_SECT3:1;             // 3 Execute-Only Flash Sector 3 in Flash BANK0
    Uint16 EXEONLY_SECT4:1;             // 4 Execute-Only Flash Sector 4 in Flash BANK0
    Uint16 EXEONLY_SECT5:1;             // 5 Execute-Only Flash Sector 5 in Flash BANK0
    Uint16 EXEONLY_SECT6:1;             // 6 Execute-Only Flash Sector 6 in Flash BANK0
    Uint16 EXEONLY_SECT7:1;             // 7 Execute-Only Flash Sector 7 in Flash BANK0
    Uint16 EXEONLY_SECT8:1;             // 8 Execute-Only Flash Sector 8 in Flash BANK0
    Uint16 EXEONLY_SECT9:1;             // 9 Execute-Only Flash Sector 9 in Flash BANK0
    Uint16 EXEONLY_SECT10:1;            // 10 Execute-Only Flash Sector 10 in Flash BANK0
    Uint16 EXEONLY_SECT11:1;            // 11 Execute-Only Flash Sector 11 in Flash BANK0
    Uint16 EXEONLY_SECT12:1;            // 12 Execute-Only Flash Sector 12 in Flash BANK0
    Uint16 EXEONLY_SECT13:1;            // 13 Execute-Only Flash Sector 13 in Flash BANK0
    Uint16 EXEONLY_SECT14:1;            // 14 Execute-Only Flash Sector 14 in Flash BANK0
    Uint16 EXEONLY_SECT15:1;            // 15 Execute-Only Flash Sector 15 in Flash BANK0
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union B0_Z1_EXEONLYSECTR_REG {
    Uint32  all;
    struct  B0_Z1_EXEONLYSECTR_BITS  bit;
};

struct Z1_EXEONLYRAMR_BITS {            // bits description
    Uint16 EXEONLY_RAM0:1;              // 0 Execute-Only RAM LS0
    Uint16 EXEONLY_RAM1:1;              // 1 Execute-Only RAM LS1
    Uint16 EXEONLY_RAM2:1;              // 2 Execute-Only RAM LS2
    Uint16 EXEONLY_RAM3:1;              // 3 Execute-Only RAM LS3
    Uint16 EXEONLY_RAM4:1;              // 4 Execute-Only RAM LS4
    Uint16 EXEONLY_RAM5:1;              // 5 Execute-Only RAM LS5
    Uint16 EXEONLY_RAM6:1;              // 6 Execute-Only RAM LS6
    Uint16 EXEONLY_RAM7:1;              // 7 Execute-Only RAM LS7
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union Z1_EXEONLYRAMR_REG {
    Uint32  all;
    struct  Z1_EXEONLYRAMR_BITS  bit;
};

struct DCSM_BANK0_Z1_REGS {
    union   B0_Z1_LINKPOINTER_REG            B0_Z1_LINKPOINTER;            // Zone 1 Link Pointer for flash BANK0
    union   Z1_OTPSECLOCK_REG                Z1_OTPSECLOCK;                // Zone 1 OTP Secure JTAG lock
    Uint32                                   Z1_BOOTDEF_HIGH;              // Boot definition (high 32bit)
    union   B0_Z1_LINKPOINTERERR_REG         B0_Z1_LINKPOINTERERR;         // Link Pointer Error for flash BANK0
    Uint32                                   Z1_BOOTPIN_CONFIG;            // Boot Pin Configuration
    Uint32                                   Z1_GPREG2;                    // Zone1 General Purpose Register-2
    Uint32                                   Z1_BOOTDEF_LOW;               // Boot definition (low 32bit)
    Uint16                                   rsvd1[2];                     // Reserved
    Uint32                                   Z1_CSMKEY0;                   // Zone 1 CSM Key 0
    Uint32                                   Z1_CSMKEY1;                   // Zone 1 CSM Key 1
    Uint32                                   Z1_CSMKEY2;                   // Zone 1 CSM Key 2
    Uint32                                   Z1_CSMKEY3;                   // Zone 1 CSM Key 3
    Uint16                                   rsvd2;                        // Reserved
    union   Z1_CR_REG                        Z1_CR;                        // Zone 1 CSM Control Register
    union   B0_Z1_GRABSECTR_REG              B0_Z1_GRABSECTR;              // Zone 1 Grab Flash BANK0 Sectors Register
    union   Z1_GRABRAMR_REG                  Z1_GRABRAMR;                  // Zone 1 Grab RAM Blocks Register
    union   B0_Z1_EXEONLYSECTR_REG           B0_Z1_EXEONLYSECTR;           // Zone 1 Flash BANK0 Execute_Only Sector Register
    union   Z1_EXEONLYRAMR_REG               Z1_EXEONLYRAMR;               // Zone 1 RAM Execute_Only Block Register
    Uint16                                   rsvd3;                        // Reserved
};

struct B0_Z2_LINKPOINTER_BITS {         // bits description
    Uint32 LINKPOINTER:29;              // 28:0 Zone2 LINK Pointer in Flash BANK0
    Uint16 rsvd1:3;                     // 31:29 Reserved
};

union B0_Z2_LINKPOINTER_REG {
    Uint32  all;
    struct  B0_Z2_LINKPOINTER_BITS  bit;
};

struct Z2_OTPSECLOCK_BITS {             // bits description
    Uint16 JTAGLOCK:4;                  // 3:0 Zone2 JTAG Lock.
    Uint16 PSWDLOCK:4;                  // 7:4 Zone2 Password Lock.
    Uint16 CRCLOCK:4;                   // 11:8 Zone2 CRC Lock.
    Uint16 rsvd1:4;                     // 15:12 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union Z2_OTPSECLOCK_REG {
    Uint32  all;
    struct  Z2_OTPSECLOCK_BITS  bit;
};

struct B0_Z2_LINKPOINTERERR_BITS {      // bits description
    Uint32 Z2_LINKPOINTERERR:29;        // 28:0 Error to Resolve Z2 Link pointer from OTP loaded values
    Uint16 rsvd1:3;                     // 31:29 Reserved
};

union B0_Z2_LINKPOINTERERR_REG {
    Uint32  all;
    struct  B0_Z2_LINKPOINTERERR_BITS  bit;
};

struct Z2_CR_BITS {                     // bits description
    Uint16 rsvd1:3;                     // 2:0 Reserved
    Uint16 ALLZERO:1;                   // 3 CSMPSWD All Zeros
    Uint16 ALLONE:1;                    // 4 CSMPSWD All Ones
    Uint16 UNSECURE:1;                  // 5 CSMPSWD Match CSMKEY
    Uint16 ARMED:1;                     // 6 CSM Passwords Read Status
    Uint16 rsvd2:1;                     // 7 Reserved
    Uint16 rsvd3:7;                     // 14:8 Reserved
    Uint16 FORCESEC:1;                  // 15 Force Secure
};

union Z2_CR_REG {
    Uint16  all;
    struct  Z2_CR_BITS  bit;
};

struct B0_Z2_GRABSECTR_BITS {           // bits description
    Uint16 GRAB_SECT0:2;                // 1:0 Grab Flash Sector 0 in Flash BANK0
    Uint16 GRAB_SECT1:2;                // 3:2 Grab Flash Sector 1 in Flash BANK0
    Uint16 GRAB_SECT2:2;                // 5:4 Grab Flash Sector 2 in Flash BANK0
    Uint16 GRAB_SECT3:2;                // 7:6 Grab Flash Sector 3 in Flash BANK0
    Uint16 GRAB_SECT4:2;                // 9:8 Grab Flash Sector 4 in Flash BANK0
    Uint16 GRAB_SECT5:2;                // 11:10 Grab Flash Sector 5 in Flash BANK0
    Uint16 GRAB_SECT6:2;                // 13:12 Grab Flash Sector 6 in Flash BANK0
    Uint16 GRAB_SECT7:2;                // 15:14 Grab Flash Sector 7 in Flash BANK0
    Uint16 GRAB_SECT8:2;                // 17:16 Grab Flash Sector 8 in Flash BANK0
    Uint16 GRAB_SECT9:2;                // 19:18 Grab Flash Sector 9 in Flash BANK0
    Uint16 GRAB_SECT10:2;               // 21:20 Grab Flash Sector 10 in Flash BANK0
    Uint16 GRAB_SECT11:2;               // 23:22 Grab Flash Sector 11 in Flash BANK0
    Uint16 GRAB_SECT12:2;               // 25:24 Grab Flash Sector 12 in Flash BANK0
    Uint16 GRAB_SECT13:2;               // 27:26 Grab Flash Sector 13 in Flash BANK0
    Uint16 GRAB_SECT14:2;               // 29:28 Grab Flash Sector 14 in Flash BANK0
    Uint16 GRAB_SECT15:2;               // 31:30 Grab Flash Sector 15 in Flash BANK0
};

union B0_Z2_GRABSECTR_REG {
    Uint32  all;
    struct  B0_Z2_GRABSECTR_BITS  bit;
};

struct Z2_GRABRAMR_BITS {               // bits description
    Uint16 GRAB_RAM0:2;                 // 1:0 Grab RAM LS0
    Uint16 GRAB_RAM1:2;                 // 3:2 Grab RAM LS1
    Uint16 GRAB_RAM2:2;                 // 5:4 Grab RAM LS2
    Uint16 GRAB_RAM3:2;                 // 7:6 Grab RAM LS3
    Uint16 GRAB_RAM4:2;                 // 9:8 Grab RAM LS4
    Uint16 GRAB_RAM5:2;                 // 11:10 Grab RAM LS5
    Uint16 GRAB_RAM6:2;                 // 13:12 Grab RAM LS6
    Uint16 GRAB_RAM7:2;                 // 15:14 Grab RAM LS7
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union Z2_GRABRAMR_REG {
    Uint32  all;
    struct  Z2_GRABRAMR_BITS  bit;
};

struct B0_Z2_EXEONLYSECTR_BITS {        // bits description
    Uint16 EXEONLY_SECT0:1;             // 0 Execute-Only Flash Sector 0 in Flash BANK0
    Uint16 EXEONLY_SECT1:1;             // 1 Execute-Only Flash Sector 1 in Flash BANK0
    Uint16 EXEONLY_SECT2:1;             // 2 Execute-Only Flash Sector 2 in Flash BANK0
    Uint16 EXEONLY_SECT3:1;             // 3 Execute-Only Flash Sector 3 in Flash BANK0
    Uint16 EXEONLY_SECT4:1;             // 4 Execute-Only Flash Sector 4 in Flash BANK0
    Uint16 EXEONLY_SECT5:1;             // 5 Execute-Only Flash Sector 5 in Flash BANK0
    Uint16 EXEONLY_SECT6:1;             // 6 Execute-Only Flash Sector 6 in Flash BANK0
    Uint16 EXEONLY_SECT7:1;             // 7 Execute-Only Flash Sector 7 in Flash BANK0
    Uint16 EXEONLY_SECT8:1;             // 8 Execute-Only Flash Sector 8 in Flash BANK0
    Uint16 EXEONLY_SECT9:1;             // 9 Execute-Only Flash Sector 9 in Flash BANK0
    Uint16 EXEONLY_SECT10:1;            // 10 Execute-Only Flash Sector 10 in Flash BANK0
    Uint16 EXEONLY_SECT11:1;            // 11 Execute-Only Flash Sector 11 in Flash BANK0
    Uint16 EXEONLY_SECT12:1;            // 12 Execute-Only Flash Sector 12 in Flash BANK0
    Uint16 EXEONLY_SECT13:1;            // 13 Execute-Only Flash Sector 13 in Flash BANK0
    Uint16 EXEONLY_SECT14:1;            // 14 Execute-Only Flash Sector 14 in Flash BANK0
    Uint16 EXEONLY_SECT15:1;            // 15 Execute-Only Flash Sector 15 in Flash BANK0
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union B0_Z2_EXEONLYSECTR_REG {
    Uint32  all;
    struct  B0_Z2_EXEONLYSECTR_BITS  bit;
};

struct Z2_EXEONLYRAMR_BITS {            // bits description
    Uint16 EXEONLY_RAM0:1;              // 0 Execute-Only RAM LS0
    Uint16 EXEONLY_RAM1:1;              // 1 Execute-Only RAM LS1
    Uint16 EXEONLY_RAM2:1;              // 2 Execute-Only RAM LS2
    Uint16 EXEONLY_RAM3:1;              // 3 Execute-Only RAM LS3
    Uint16 EXEONLY_RAM4:1;              // 4 Execute-Only RAM LS4
    Uint16 EXEONLY_RAM5:1;              // 5 Execute-Only RAM LS5
    Uint16 EXEONLY_RAM6:1;              // 6 Execute-Only RAM LS6
    Uint16 EXEONLY_RAM7:1;              // 7 Execute-Only RAM LS7
    Uint16 rsvd1:8;                     // 15:8 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union Z2_EXEONLYRAMR_REG {
    Uint32  all;
    struct  Z2_EXEONLYRAMR_BITS  bit;
};

struct DCSM_BANK0_Z2_REGS {
    union   B0_Z2_LINKPOINTER_REG            B0_Z2_LINKPOINTER;            // Zone 2 Link Pointer for flash BANK0
    union   Z2_OTPSECLOCK_REG                Z2_OTPSECLOCK;                // Zone 2 OTP Secure JTAG lock
    Uint16                                   rsvd1[2];                     // Reserved
    union   B0_Z2_LINKPOINTERERR_REG         B0_Z2_LINKPOINTERERR;         // Link Pointer Error for flash BANK0
    Uint16                                   rsvd2[8];                     // Reserved
    Uint32                                   Z2_CSMKEY0;                   // Zone 2 CSM Key 0
    Uint32                                   Z2_CSMKEY1;                   // Zone 2 CSM Key 1
    Uint32                                   Z2_CSMKEY2;                   // Zone 2 CSM Key 2
    Uint32                                   Z2_CSMKEY3;                   // Zone 2 CSM Key 3
    Uint16                                   rsvd3;                        // Reserved
    union   Z2_CR_REG                        Z2_CR;                        // Zone 2 CSM Control Register
    union   B0_Z2_GRABSECTR_REG              B0_Z2_GRABSECTR;              // Zone 2 Grab Flash BANK0 Sectors Register
    union   Z2_GRABRAMR_REG                  Z2_GRABRAMR;                  // Zone 2 Grab RAM Blocks Register
    union   B0_Z2_EXEONLYSECTR_REG           B0_Z2_EXEONLYSECTR;           // Zone 2 Flash BANK0 Execute_Only Sector Register
    union   Z2_EXEONLYRAMR_REG               Z2_EXEONLYRAMR;               // Zone 2 RAM Execute_Only Block Register
    Uint16                                   rsvd4;                        // Reserved
};

struct FLSEM_BITS {                     // bits description
    Uint16 SEM:2;                       // 1:0 Flash Semaphore Bit
    Uint16 rsvd1:6;                     // 7:2 Reserved
    Uint16 KEY:8;                       // 15:8 Semaphore Key
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union FLSEM_REG {
    Uint32  all;
    struct  FLSEM_BITS  bit;
};

struct B0_SECTSTAT_BITS {               // bits description
    Uint16 STATUS_SECT0:2;              // 1:0 Zone Status Flash BANK0 Sector 0
    Uint16 STATUS_SECT1:2;              // 3:2 Zone Status Flash BANK0 sector 1
    Uint16 STATUS_SECT2:2;              // 5:4 Zone Status Flash BANK0 Sector 2
    Uint16 STATUS_SECT3:2;              // 7:6 Zone Status Flash BANK0 Sector 3
    Uint16 STATUS_SECT4:2;              // 9:8 Zone Status Flash BANK0 Sector 4
    Uint16 STATUS_SECT5:2;              // 11:10 Zone Status Flash BANK0 Sector 5
    Uint16 STATUS_SECT6:2;              // 13:12 Zone Status Flash BANK0 Sector 6
    Uint16 STATUS_SECT7:2;              // 15:14 Zone Status Flash BANK0 Sector 7
    Uint16 STATUS_SECT8:2;              // 17:16 Zone Status Flash BANK0 sector 8
    Uint16 STATUS_SECT9:2;              // 19:18 Zone Status Flash BANK0 Sector 9
    Uint16 STATUS_SECT10:2;             // 21:20 Zone Status Flash BANK0 Sector 10
    Uint16 STATUS_SECT11:2;             // 23:22 Zone Status Flash BANK0 Sector 11
    Uint16 STATUS_SECT12:2;             // 25:24 Zone Status Flash BANK0 Sector 12
    Uint16 STATUS_SECT13:2;             // 27:26 Zone Status Flash BANK0 Sector 13
    Uint16 STATUS_SECT14:2;             // 29:28 Zone Status Flash BANK0 Sector 14
    Uint16 STATUS_SECT15:2;             // 31:30 Zone Status Flash BANK0 Sector 15
};

union B0_SECTSTAT_REG {
    Uint32  all;
    struct  B0_SECTSTAT_BITS  bit;
};

struct RAMSTAT_BITS {                   // bits description
    Uint16 STATUS_RAM0:2;               // 1:0 Zone Status RAM LS0
    Uint16 STATUS_RAM1:2;               // 3:2 Zone Status RAM LS1
    Uint16 STATUS_RAM2:2;               // 5:4 Zone Status RAM LS2
    Uint16 STATUS_RAM3:2;               // 7:6 Zone Status RAM LS3
    Uint16 STATUS_RAM4:2;               // 9:8 Zone Status RAM LS4
    Uint16 STATUS_RAM5:2;               // 11:10 Zone Status RAM LS5
    Uint16 STATUS_RAM6:2;               // 13:12 Zone Status RAM LS6
    Uint16 STATUS_RAM7:2;               // 15:14 Zone Status RAM LS7
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union RAMSTAT_REG {
    Uint32  all;
    struct  RAMSTAT_BITS  bit;
};

struct B1_SECTSTAT_BITS {               // bits description
    Uint16 STATUS_SECT0:2;              // 1:0 Zone Status Flash BANK1 Sector 0
    Uint16 STATUS_SECT1:2;              // 3:2 Zone Status Flash BANK1 sector 1
    Uint16 STATUS_SECT2:2;              // 5:4 Zone Status Flash BANK1 Sector 2
    Uint16 STATUS_SECT3:2;              // 7:6 Zone Status Flash BANK1 Sector 3
    Uint16 STATUS_SECT4:2;              // 9:8 Zone Status Flash BANK1 Sector 4
    Uint16 STATUS_SECT5:2;              // 11:10 Zone Status Flash BANK1 Sector 5
    Uint16 STATUS_SECT6:2;              // 13:12 Zone Status Flash BANK1 Sector 6
    Uint16 STATUS_SECT7:2;              // 15:14 Zone Status Flash BANK1 Sector 7
    Uint16 STATUS_SECT8:2;              // 17:16 Zone Status Flash BANK1 sector 8
    Uint16 STATUS_SECT9:2;              // 19:18 Zone Status Flash BANK1 Sector 9
    Uint16 STATUS_SECT10:2;             // 21:20 Zone Status Flash BANK1 Sector 10
    Uint16 STATUS_SECT11:2;             // 23:22 Zone Status Flash BANK1 Sector 11
    Uint16 STATUS_SECT12:2;             // 25:24 Zone Status Flash BANK1 Sector 12
    Uint16 STATUS_SECT13:2;             // 27:26 Zone Status Flash BANK1 Sector 13
    Uint16 STATUS_SECT14:2;             // 29:28 Zone Status Flash BANK1 Sector 14
    Uint16 STATUS_SECT15:2;             // 31:30 Zone Status Flash BANK1 Sector 15
};

union B1_SECTSTAT_REG {
    Uint32  all;
    struct  B1_SECTSTAT_BITS  bit;
};

struct SECERRSTAT_BITS {                // bits description
    Uint16 ERR:1;                       // 0 Security Configuration load Error Status
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SECERRSTAT_REG {
    Uint32  all;
    struct  SECERRSTAT_BITS  bit;
};

struct SECERRCLR_BITS {                 // bits description
    Uint16 ERR:1;                       // 0 Clear Security Configuration Load Error Status Bit
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SECERRCLR_REG {
    Uint32  all;
    struct  SECERRCLR_BITS  bit;
};

struct SECERRFRC_BITS {                 // bits description
    Uint16 ERR:1;                       // 0 Set Security Configuration Load Error Status Bit
    Uint16 rsvd1:15;                    // 15:1 Reserved
    Uint16 rsvd2:16;                    // 31:16 Reserved
};

union SECERRFRC_REG {
    Uint32  all;
    struct  SECERRFRC_BITS  bit;
};

struct DCSM_COMMON_REGS {
    union   FLSEM_REG                        FLSEM;                        // Flash Wrapper Semaphore Register
    union   B0_SECTSTAT_REG                  B0_SECTSTAT;                  // Flash BANK0 Sectors Status Register
    union   RAMSTAT_REG                      RAMSTAT;                      // RAM Status Register
    Uint16                                   rsvd1[2];                     // Reserved
    union   B1_SECTSTAT_REG                  B1_SECTSTAT;                  // Flash BANK1 Sectors Status Register
    union   SECERRSTAT_REG                   SECERRSTAT;                   // Security Error Status Register
    union   SECERRCLR_REG                    SECERRCLR;                    // Security Error Clear Register
    union   SECERRFRC_REG                    SECERRFRC;                    // Security Error Force Register
};

struct B1_Z1_LINKPOINTER_BITS {         // bits description
    Uint32 LINKPOINTER:29;              // 28:0 Zone1 LINK Pointer in Flash BANK1
    Uint16 rsvd1:3;                     // 31:29 Reserved
};

union B1_Z1_LINKPOINTER_REG {
    Uint32  all;
    struct  B1_Z1_LINKPOINTER_BITS  bit;
};

struct B1_Z1_LINKPOINTERERR_BITS {      // bits description
    Uint32 Z1_LINKPOINTERERR:29;        // 28:0 Error to Resolve Z1 Link pointer from OTP loaded values
    Uint16 rsvd1:3;                     // 31:29 Reserved
};

union B1_Z1_LINKPOINTERERR_REG {
    Uint32  all;
    struct  B1_Z1_LINKPOINTERERR_BITS  bit;
};

struct B1_Z1_GRABSECTR_BITS {           // bits description
    Uint16 GRAB_SECT0:2;                // 1:0 Grab Flash Sector 0 in BANK1
    Uint16 GRAB_SECT1:2;                // 3:2 Grab Flash Sector 1 in BANK1
    Uint16 GRAB_SECT2:2;                // 5:4 Grab Flash Sector 2 in BANK1
    Uint16 GRAB_SECT3:2;                // 7:6 Grab Flash Sector 3 in BANK1
    Uint16 GRAB_SECT4:2;                // 9:8 Grab Flash Sector 4 in BANK1
    Uint16 GRAB_SECT5:2;                // 11:10 Grab Flash Sector 5 in BANK1
    Uint16 GRAB_SECT6:2;                // 13:12 Grab Flash Sector 6 in BANK1
    Uint16 GRAB_SECT7:2;                // 15:14 Grab Flash Sector 7 in BANK1
    Uint16 GRAB_SECT8:2;                // 17:16 Grab Flash Sector 8 in BANK1
    Uint16 GRAB_SECT9:2;                // 19:18 Grab Flash Sector 9 in BANK1
    Uint16 GRAB_SECT10:2;               // 21:20 Grab Flash Sector 10 in BANK1
    Uint16 GRAB_SECT11:2;               // 23:22 Grab Flash Sector 11 in BANK1
    Uint16 GRAB_SECT12:2;               // 25:24 Grab Flash Sector 12 in BANK1
    Uint16 GRAB_SECT13:2;               // 27:26 Grab Flash Sector 13 in BANK1
    Uint16 GRAB_SECT14:2;               // 29:28 Grab Flash Sector 14 in BANK1
    Uint16 GRAB_SECT15:2;               // 31:30 Grab Flash Sector 15 in BANK1
};

union B1_Z1_GRABSECTR_REG {
    Uint32  all;
    struct  B1_Z1_GRABSECTR_BITS  bit;
};

struct B1_Z1_EXEONLYSECTR_BITS {        // bits description
    Uint16 EXEONLY_SECT0:1;             // 0 Execute-Only Flash Sector 0 in Flash BANK1
    Uint16 EXEONLY_SECT1:1;             // 1 Execute-Only Flash Sector 1 in Flash BANK1
    Uint16 EXEONLY_SECT2:1;             // 2 Execute-Only Flash Sector 2 in Flash BANK1
    Uint16 EXEONLY_SECT3:1;             // 3 Execute-Only Flash Sector 3 in Flash BANK1
    Uint16 EXEONLY_SECT4:1;             // 4 Execute-Only Flash Sector 4 in Flash BANK1
    Uint16 EXEONLY_SECT5:1;             // 5 Execute-Only Flash Sector 5 in Flash BANK1
    Uint16 EXEONLY_SECT6:1;             // 6 Execute-Only Flash Sector 6 in Flash BANK1
    Uint16 EXEONLY_SECT7:1;             // 7 Execute-Only Flash Sector 7 in Flash BANK1
    Uint16 EXEONLY_SECT8:1;             // 8 Execute-Only Flash Sector 8 in Flash BANK1
    Uint16 EXEONLY_SECT9:1;             // 9 Execute-Only Flash Sector 9 in Flash BANK1
    Uint16 EXEONLY_SECT10:1;            // 10 Execute-Only Flash Sector 10 in Flash BANK1
    Uint16 EXEONLY_SECT11:1;            // 11 Execute-Only Flash Sector 11 in Flash BANK1
    Uint16 EXEONLY_SECT12:1;            // 12 Execute-Only Flash Sector 12 in Flash BANK1
    Uint16 EXEONLY_SECT13:1;            // 13 Execute-Only Flash Sector 13 in Flash BANK1
    Uint16 EXEONLY_SECT14:1;            // 14 Execute-Only Flash Sector 14 in Flash BANK1
    Uint16 EXEONLY_SECT15:1;            // 15 Execute-Only Flash Sector 15 in Flash BANK1
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union B1_Z1_EXEONLYSECTR_REG {
    Uint32  all;
    struct  B1_Z1_EXEONLYSECTR_BITS  bit;
};

struct DCSM_BANK1_Z1_REGS {
    union   B1_Z1_LINKPOINTER_REG            B1_Z1_LINKPOINTER;            // Zone 1 Link Pointer for flash BANK1
    Uint16                                   rsvd1[4];                     // Reserved
    union   B1_Z1_LINKPOINTERERR_REG         B1_Z1_LINKPOINTERERR;         // Link Pointer Error for flash BANK1
    Uint16                                   rsvd2[18];                    // Reserved
    union   B1_Z1_GRABSECTR_REG              B1_Z1_GRABSECTR;              // Zone 1 Grab Flash BANK1 Sectors Register
    Uint16                                   rsvd3[2];                     // Reserved
    union   B1_Z1_EXEONLYSECTR_REG           B1_Z1_EXEONLYSECTR;           // Zone 1 Flash BANK1 Execute_Only Sector Register
    Uint16                                   rsvd4[3];                     // Reserved
};

struct B1_Z2_LINKPOINTER_BITS {         // bits description
    Uint32 LINKPOINTER:29;              // 28:0 Zone2 LINK Pointer in Flash BANK1
    Uint16 rsvd1:3;                     // 31:29 Reserved
};

union B1_Z2_LINKPOINTER_REG {
    Uint32  all;
    struct  B1_Z2_LINKPOINTER_BITS  bit;
};

struct B1_Z2_LINKPOINTERERR_BITS {      // bits description
    Uint32 Z2_LINKPOINTERERR:29;        // 28:0 Error to Resolve Z2 Link pointer from OTP loaded values
    Uint16 rsvd1:3;                     // 31:29 Reserved
};

union B1_Z2_LINKPOINTERERR_REG {
    Uint32  all;
    struct  B1_Z2_LINKPOINTERERR_BITS  bit;
};

struct B1_Z2_GRABSECTR_BITS {           // bits description
    Uint16 GRAB_SECT0:2;                // 1:0 Grab Flash Sector 0 in Flash BANK1
    Uint16 GRAB_SECT1:2;                // 3:2 Grab Flash Sector 1 in Flash BANK1
    Uint16 GRAB_SECT2:2;                // 5:4 Grab Flash Sector 2 in Flash BANK1
    Uint16 GRAB_SECT3:2;                // 7:6 Grab Flash Sector 3 in Flash BANK1
    Uint16 GRAB_SECT4:2;                // 9:8 Grab Flash Sector 4 in Flash BANK1
    Uint16 GRAB_SECT5:2;                // 11:10 Grab Flash Sector 5 in Flash BANK1
    Uint16 GRAB_SECT6:2;                // 13:12 Grab Flash Sector 6 in Flash BANK1
    Uint16 GRAB_SECT7:2;                // 15:14 Grab Flash Sector 7 in Flash BANK1
    Uint16 GRAB_SECT8:2;                // 17:16 Grab Flash Sector 8 in Flash BANK1
    Uint16 GRAB_SECT9:2;                // 19:18 Grab Flash Sector 9 in Flash BANK1
    Uint16 GRAB_SECT10:2;               // 21:20 Grab Flash Sector 10 in Flash BANK1
    Uint16 GRAB_SECT11:2;               // 23:22 Grab Flash Sector 11 in Flash BANK1
    Uint16 GRAB_SECT12:2;               // 25:24 Grab Flash Sector 12 in Flash BANK1
    Uint16 GRAB_SECT13:2;               // 27:26 Grab Flash Sector 13 in Flash BANK1
    Uint16 GRAB_SECT14:2;               // 29:28 Grab Flash Sector 14 in Flash BANK1
    Uint16 GRAB_SECT15:2;               // 31:30 Grab Flash Sector 15 in Flash BANK1
};

union B1_Z2_GRABSECTR_REG {
    Uint32  all;
    struct  B1_Z2_GRABSECTR_BITS  bit;
};

struct B1_Z2_EXEONLYSECTR_BITS {        // bits description
    Uint16 EXEONLY_SECT0:1;             // 0 Execute-Only Flash Sector 0 in Flash BANK1
    Uint16 EXEONLY_SECT1:1;             // 1 Execute-Only Flash Sector 1 in Flash BANK1
    Uint16 EXEONLY_SECT2:1;             // 2 Execute-Only Flash Sector 2 in Flash BANK1
    Uint16 EXEONLY_SECT3:1;             // 3 Execute-Only Flash Sector 3 in Flash BANK1
    Uint16 EXEONLY_SECT4:1;             // 4 Execute-Only Flash Sector 4 in Flash BANK1
    Uint16 EXEONLY_SECT5:1;             // 5 Execute-Only Flash Sector 5 in Flash BANK1
    Uint16 EXEONLY_SECT6:1;             // 6 Execute-Only Flash Sector 6 in Flash BANK1
    Uint16 EXEONLY_SECT7:1;             // 7 Execute-Only Flash Sector 7 in Flash BANK1
    Uint16 EXEONLY_SECT8:1;             // 8 Execute-Only Flash Sector 8 in Flash BANK1
    Uint16 EXEONLY_SECT9:1;             // 9 Execute-Only Flash Sector 9 in Flash BANK1
    Uint16 EXEONLY_SECT10:1;            // 10 Execute-Only Flash Sector 10 in Flash BANK1
    Uint16 EXEONLY_SECT11:1;            // 11 Execute-Only Flash Sector 11 in Flash BANK1
    Uint16 EXEONLY_SECT12:1;            // 12 Execute-Only Flash Sector 12 in Flash BANK1
    Uint16 EXEONLY_SECT13:1;            // 13 Execute-Only Flash Sector 13 in Flash BANK1
    Uint16 EXEONLY_SECT14:1;            // 14 Execute-Only Flash Sector 14 in Flash BANK1
    Uint16 EXEONLY_SECT15:1;            // 15 Execute-Only Flash Sector 15 in Flash BANK1
    Uint16 rsvd1:16;                    // 31:16 Reserved
};

union B1_Z2_EXEONLYSECTR_REG {
    Uint32  all;
    struct  B1_Z2_EXEONLYSECTR_BITS  bit;
};

struct DCSM_BANK1_Z2_REGS {
    union   B1_Z2_LINKPOINTER_REG            B1_Z2_LINKPOINTER;            // Zone 2 Link Pointer for flash BANK1
    Uint16                                   rsvd1[4];                     // Reserved
    union   B1_Z2_LINKPOINTERERR_REG         B1_Z2_LINKPOINTERERR;         // Link Pointer Error for flash BANK1
    Uint16                                   rsvd2[18];                    // Reserved
    union   B1_Z2_GRABSECTR_REG              B1_Z2_GRABSECTR;              // Zone 2 Grab Flash BANK1 Sectors Register
    Uint16                                   rsvd3[2];                     // Reserved
    union   B1_Z2_EXEONLYSECTR_REG           B1_Z2_EXEONLYSECTR;           // Zone 2 Flash BANK1 Execute_Only Sector Register
    Uint16                                   rsvd4[3];                     // Reserved
};

//---------------------------------------------------------------------------
// DCSM External References & Function Declarations:
//
extern volatile struct DCSM_BANK0_Z1_REGS DcsmBank0Z1Regs;
extern volatile struct DCSM_BANK0_Z2_REGS DcsmBank0Z2Regs;
extern volatile struct DCSM_COMMON_REGS DcsmCommonRegs;
extern volatile struct DCSM_BANK1_Z1_REGS DcsmBank1Z1Regs;
extern volatile struct DCSM_BANK1_Z2_REGS DcsmBank1Z2Regs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
