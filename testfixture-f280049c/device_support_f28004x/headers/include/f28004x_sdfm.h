//###########################################################################
//
// FILE:    f28004x_sdfm.h
//
// TITLE:   SDFM Register Definitions.
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

#ifndef __F28004X_SDFM_H__
#define __F28004X_SDFM_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// SDFM Individual Register Bit Definitions:

struct SDIFLG_BITS {                    // bits description
    Uint16 IFH1:1;                      // 0 High-level Interrupt flag for Ch1
    Uint16 IFL1:1;                      // 1 Low-level Interrupt flag for Ch1
    Uint16 IFH2:1;                      // 2 High-level Interrupt flag for Ch2
    Uint16 IFL2:1;                      // 3 Low-level Interrupt flag for Ch2
    Uint16 IFH3:1;                      // 4 High-level Interrupt flag for Ch3
    Uint16 IFL3:1;                      // 5 Low-level Interrupt flag for Ch3
    Uint16 IFH4:1;                      // 6 High-level Interrupt flag for Ch4
    Uint16 IFL4:1;                      // 7 Low-level Interrupt flag for Ch4
    Uint16 MF1:1;                       // 8 Modulator Failure for Filter 1
    Uint16 MF2:1;                       // 9 Modulator Failure for Filter 2
    Uint16 MF3:1;                       // 10 Modulator Failure for Filter 3
    Uint16 MF4:1;                       // 11 Modulator Failure for Filter 4
    Uint16 AF1:1;                       // 12 Acknowledge flag for Filter 1
    Uint16 AF2:1;                       // 13 Acknowledge flag for Filter 2
    Uint16 AF3:1;                       // 14 Acknowledge flag for Filter 3
    Uint16 AF4:1;                       // 15 Acknowledge flag for Filter 4
    Uint16 SDFFOVF1:1;                  // 16 FIFO Overflow Flag for Ch1.
    Uint16 SDFFOVF2:1;                  // 17 FIFO Overflow Flag for Ch2
    Uint16 SDFFOVF3:1;                  // 18 FIFO Overflow Flag for Ch3
    Uint16 SDFFOVF4:1;                  // 19 FIFO Overflow Flag for Ch4
    Uint16 SDFFINT1:1;                  // 20 SDFIFO interrupt for Ch1
    Uint16 SDFFINT2:1;                  // 21 SDFIFO interrupt for Ch2
    Uint16 SDFFINT3:1;                  // 22 SDFIFO interrupt for Ch3
    Uint16 SDFFINT4:1;                  // 23 SDFIFO interrupt for Ch4
    Uint16 rsvd1:7;                     // 30:24 Reserved
    Uint16 MIF:1;                       // 31 Master Interrupt Flag
};

union SDIFLG_REG {
    Uint32  all;
    struct  SDIFLG_BITS  bit;
};

struct SDIFLGCLR_BITS {                 // bits description
    Uint16 IFH1:1;                      // 0 High-level Interrupt flag for Ch1
    Uint16 IFL1:1;                      // 1 Low-level Interrupt flag for Ch1
    Uint16 IFH2:1;                      // 2 High-level Interrupt flag for Ch2
    Uint16 IFL2:1;                      // 3 Low-level Interrupt flag for Ch2
    Uint16 IFH3:1;                      // 4 High-level Interrupt flag for Ch3
    Uint16 IFL3:1;                      // 5 Low-level Interrupt flag for Ch3
    Uint16 IFH4:1;                      // 6 High-level Interrupt flag for Ch4
    Uint16 IFL4:1;                      // 7 Low-level Interrupt flag for Ch4
    Uint16 MF1:1;                       // 8 Modulator Failure for Filter 1
    Uint16 MF2:1;                       // 9 Modulator Failure for Filter 2
    Uint16 MF3:1;                       // 10 Modulator Failure for Filter 3
    Uint16 MF4:1;                       // 11 Modulator Failure for Filter 4
    Uint16 AF1:1;                       // 12 Acknowledge flag for Filter 1
    Uint16 AF2:1;                       // 13 Acknowledge flag for Filter 2
    Uint16 AF3:1;                       // 14 Acknowledge flag for Filter 3
    Uint16 AF4:1;                       // 15 Acknowledge flag for Filter 4
    Uint16 SDFFOVF1:1;                  // 16 SDFIFO overflow clear Ch1
    Uint16 SDFFOVF2:1;                  // 17 SDFIFO overflow clear Ch2
    Uint16 SDFFOVF3:1;                  // 18 SDFIFO overflow clear Ch3
    Uint16 SDFFOVF4:1;                  // 19 SDFIFO overflow clear Ch4
    Uint16 SDFFINT1:1;                  // 20 SDFIFO Interrupt flag-clear bit for Ch1
    Uint16 SDFFINT2:1;                  // 21 SDFIFO Interrupt flag-clear bit for Ch2
    Uint16 SDFFINT3:1;                  // 22 SDFIFO Interrupt flag-clear bit for Ch3
    Uint16 SDFFINT4:1;                  // 23 SDFIFO Interrupt flag-clear bit for Ch4
    Uint16 rsvd1:7;                     // 30:24 Reserved
    Uint16 MIF:1;                       // 31 Master Interrupt Flag
};

union SDIFLGCLR_REG {
    Uint32  all;
    struct  SDIFLGCLR_BITS  bit;
};

struct SDCTL_BITS {                     // bits description
    Uint16 HZ1:1;                       // 0 High-level Threshold crossing (Z) flag Ch1
    Uint16 HZ2:1;                       // 1 High-level Threshold crossing (Z) flag Ch2
    Uint16 HZ3:1;                       // 2 High-level Threshold crossing (Z) flag Ch3
    Uint16 HZ4:1;                       // 3 High-level Threshold crossing (Z) flag Ch4
    Uint16 rsvd1:9;                     // 12:4 Reserved
    Uint16 MIE:1;                       // 13 Master SDy_ERR Interrupt enable
    Uint16 rsvd2:1;                     // 14 Reserved
    Uint16 rsvd3:1;                     // 15 Reserved
};

union SDCTL_REG {
    Uint16  all;
    struct  SDCTL_BITS  bit;
};

struct SDMFILEN_BITS {                  // bits description
    Uint16 rsvd1:4;                     // 3:0 Reserved
    Uint16 rsvd2:3;                     // 6:4 Reserved
    Uint16 rsvd3:2;                     // 8:7 Reserved
    Uint16 rsvd4:1;                     // 9 Reserved
    Uint16 rsvd5:1;                     // 10 Reserved
    Uint16 MFE:1;                       // 11 Master Filter Enable.
    Uint16 rsvd6:1;                     // 12 Reserved
    Uint16 rsvd7:3;                     // 15:13 Reserved
};

union SDMFILEN_REG {
    Uint16  all;
    struct  SDMFILEN_BITS  bit;
};

struct SDSTATUS_BITS {                  // bits description
    Uint16 HZ1:1;                       // 0 High-level Threshold crossing (Z) flag Ch1
    Uint16 HZ2:1;                       // 1 High-level Threshold crossing (Z) flag Ch2
    Uint16 HZ3:1;                       // 2 High-level Threshold crossing (Z) flag Ch3
    Uint16 HZ4:1;                       // 3 High-level Threshold crossing (Z) flag Ch4
    Uint16 rsvd1:4;                     // 7:4 Reserved
    Uint16 rsvd2:1;                     // 8 Reserved
    Uint16 rsvd3:1;                     // 9 Reserved
    Uint16 rsvd4:1;                     // 10 Reserved
    Uint16 rsvd5:1;                     // 11 Reserved
    Uint16 rsvd6:1;                     // 12 Reserved
    Uint16 rsvd7:1;                     // 13 Reserved
    Uint16 rsvd8:1;                     // 14 Reserved
    Uint16 rsvd9:1;                     // 15 Reserved
};

union SDSTATUS_REG {
    Uint16  all;
    struct  SDSTATUS_BITS  bit;
};

struct SDCTLPARM1_BITS {                // bits description
    Uint16 MOD:2;                       // 1:0 Modulator clocking modes
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:1;                     // 4 Reserved
    Uint16 rsvd4:11;                    // 15:5 Reserved
};

union SDCTLPARM1_REG {
    Uint16  all;
    struct  SDCTLPARM1_BITS  bit;
};

struct SDDFPARM1_BITS {                 // bits description
    Uint16 DOSR:8;                      // 7:0 Data Filter Oversample Ratio= DOSR+1
    Uint16 FEN:1;                       // 8 Filter Enable
    Uint16 AE:1;                        // 9 Ack Enable
    Uint16 SST:2;                       // 11:10 Data filter Structure (SincFast/1/2/3)
    Uint16 SDSYNCEN:1;                  // 12 Data Filter Reset Enable
    Uint16 rsvd1:3;                     // 15:13 Reserved
};

union SDDFPARM1_REG {
    Uint16  all;
    struct  SDDFPARM1_BITS  bit;
};

struct SDDPARM1_BITS {                  // bits description
    Uint16 rsvd1:10;                    // 9:0 Reserved
    Uint16 DR:1;                        // 10 Data Representation (0/1 = 16/32b 2's complement)
    Uint16 SH:5;                        // 15:11 Shift Control (# bits to shift in 16b mode)
};

union SDDPARM1_REG {
    Uint16  all;
    struct  SDDPARM1_BITS  bit;
};

struct SDCMPH1_BITS {                   // bits description
    Uint16 HLT:15;                      // 14:0 High-level threshold for the comparator filter output
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPH1_REG {
    Uint16  all;
    struct  SDCMPH1_BITS  bit;
};

struct SDCMPL1_BITS {                   // bits description
    Uint16 LLT:15;                      // 14:0 Low-level threshold for the comparator filter output
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPL1_REG {
    Uint16  all;
    struct  SDCMPL1_BITS  bit;
};

struct SDCPARM1_BITS {                  // bits description
    Uint16 COSR:5;                      // 4:0 Comparator Oversample Ratio. Actual rate COSR+1
    Uint16 IEH:1;                       // 5 High-level Interrupt enable.
    Uint16 IEL:1;                       // 6 Low-level interrupt enable
    Uint16 CS1_CS0:2;                   // 8:7 Comparator Filter Structure (SincFast/1/2/3)
    Uint16 MFIE:1;                      // 9 Modulator Failure Interrupt enable
    Uint16 HZEN:1;                      // 10 High level (Z) Threshold crossing output enable
    Uint16 rsvd1:2;                     // 12:11 Reserved
    Uint16 CEN:1;                       // 13 Comparator Enable
    Uint16 rsvd2:2;                     // 15:14 Reserved
};

union SDCPARM1_REG {
    Uint16  all;
    struct  SDCPARM1_BITS  bit;
};

struct SDDATA1_BITS {                   // bits description
    Uint16 DATA16:16;                   // 15:0 Lo-order 16b in 32b mode
    Uint16 DATA32HI:16;                 // 31:16 Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATA1_REG {
    Uint32  all;
    struct  SDDATA1_BITS  bit;
};

struct SDDATFIFO1_BITS {                // bits description
    Uint16 DATA16:16;                   // 15:0 Lo-order 16b in 32b mode
    Uint16 DATA32HI:16;                 // 31:16 Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATFIFO1_REG {
    Uint32  all;
    struct  SDDATFIFO1_BITS  bit;
};

struct SDCMPHZ1_BITS {                  // bits description
    Uint16 HLTZ:15;                     // 14:0 High-level threshold (Z) for the comparator filter output
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPHZ1_REG {
    Uint16  all;
    struct  SDCMPHZ1_BITS  bit;
};

struct SDFIFOCTL1_BITS {                // bits description
    Uint16 SDFFIL:5;                    // 4:0 SDFIFO Interrupt Level
    Uint16 rsvd1:1;                     // 5 Reserved
    Uint16 SDFFST:5;                    // 10:6 SDFIFO Status
    Uint16 rsvd2:1;                     // 11 Reserved
    Uint16 FFIEN:1;                     // 12 SDFIFO data ready Interrupt Enable
    Uint16 FFEN:1;                      // 13 SDFIFO Enable
    Uint16 DRINTSEL:1;                  // 14 Data-Ready Interrupt Source Select
    Uint16 OVFIEN:1;                    // 15 SDFIFO Overflow interrupt enable
};

union SDFIFOCTL1_REG {
    Uint16  all;
    struct  SDFIFOCTL1_BITS  bit;
};

struct SDSYNC1_BITS {                   // bits description
    Uint16 SYNCSEL:6;                   // 5:0 SDSYNC Source Select
    Uint16 WTSYNCEN:1;                  // 6 Wait-for-Sync Enable
    Uint16 WTSYNFLG:1;                  // 7 Wait-for-Sync Flag
    Uint16 WTSYNCLR:1;                  // 8 Wait-for-Sync Flag Clear
    Uint16 FFSYNCCLREN:1;               // 9 FIFO Clear-on-SDSYNC Enable
    Uint16 WTSCLREN:1;                  // 10 WTSYNFLG Clear-on-FIFOINT Enable
    Uint16 rsvd1:5;                     // 15:11 Reserved
};

union SDSYNC1_REG {
    Uint16  all;
    struct  SDSYNC1_BITS  bit;
};

struct SDCTLPARM2_BITS {                // bits description
    Uint16 MOD:2;                       // 1:0 Modulator clocking modes
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:1;                     // 4 Reserved
    Uint16 rsvd4:11;                    // 15:5 Reserved
};

union SDCTLPARM2_REG {
    Uint16  all;
    struct  SDCTLPARM2_BITS  bit;
};

struct SDDFPARM2_BITS {                 // bits description
    Uint16 DOSR:8;                      // 7:0 Data Filter Oversample Ratio= DOSR+1
    Uint16 FEN:1;                       // 8 Filter Enable
    Uint16 AE:1;                        // 9 Ack Enable
    Uint16 SST:2;                       // 11:10 Data filter Structure (SincFast/1/2/3)
    Uint16 SDSYNCEN:1;                  // 12 Data Filter Reset Enable
    Uint16 rsvd1:3;                     // 15:13 Reserved
};

union SDDFPARM2_REG {
    Uint16  all;
    struct  SDDFPARM2_BITS  bit;
};

struct SDDPARM2_BITS {                  // bits description
    Uint16 rsvd1:10;                    // 9:0 Reserved
    Uint16 DR:1;                        // 10 Data Representation (0/1 = 16/32b 2's complement)
    Uint16 SH:5;                        // 15:11 Shift Control (# bits to shift in 16b mode)
};

union SDDPARM2_REG {
    Uint16  all;
    struct  SDDPARM2_BITS  bit;
};

struct SDCMPH2_BITS {                   // bits description
    Uint16 HLT:15;                      // 14:0 High-level threshold for the comparator filter output
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPH2_REG {
    Uint16  all;
    struct  SDCMPH2_BITS  bit;
};

struct SDCMPL2_BITS {                   // bits description
    Uint16 LLT:15;                      // 14:0 Low-level threshold for the comparator filter output
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPL2_REG {
    Uint16  all;
    struct  SDCMPL2_BITS  bit;
};

struct SDCPARM2_BITS {                  // bits description
    Uint16 COSR:5;                      // 4:0 Comparator Oversample Ratio. Actual rate COSR+1
    Uint16 IEH:1;                       // 5 High-level Interrupt enable.
    Uint16 IEL:1;                       // 6 Low-level interrupt enable
    Uint16 CS1_CS0:2;                   // 8:7 Comparator Filter Structure (SincFast/1/2/3)
    Uint16 MFIE:1;                      // 9 Modulator Failure Interrupt enable
    Uint16 HZEN:1;                      // 10 High level (Z) Threshold crossing output enable
    Uint16 rsvd1:2;                     // 12:11 Reserved
    Uint16 CEN:1;                       // 13 Comparator Enable
    Uint16 rsvd2:2;                     // 15:14 Reserved
};

union SDCPARM2_REG {
    Uint16  all;
    struct  SDCPARM2_BITS  bit;
};

struct SDDATA2_BITS {                   // bits description
    Uint16 DATA16:16;                   // 15:0 Lo-order 16b in 32b mode
    Uint16 DATA32HI:16;                 // 31:16 Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATA2_REG {
    Uint32  all;
    struct  SDDATA2_BITS  bit;
};

struct SDDATFIFO2_BITS {                // bits description
    Uint16 DATA16:16;                   // 15:0 Lo-order 16b in 32b mode
    Uint16 DATA32HI:16;                 // 31:16 Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATFIFO2_REG {
    Uint32  all;
    struct  SDDATFIFO2_BITS  bit;
};

struct SDCMPHZ2_BITS {                  // bits description
    Uint16 HLTZ:15;                     // 14:0 High-level threshold (Z) for the comparator filter output
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPHZ2_REG {
    Uint16  all;
    struct  SDCMPHZ2_BITS  bit;
};

struct SDFIFOCTL2_BITS {                // bits description
    Uint16 SDFFIL:5;                    // 4:0 SDFIFO Interrupt Level
    Uint16 rsvd1:1;                     // 5 Reserved
    Uint16 SDFFST:5;                    // 10:6 SDFIFO Status
    Uint16 rsvd2:1;                     // 11 Reserved
    Uint16 FFIEN:1;                     // 12 SDFIFO data ready Interrupt Enable
    Uint16 FFEN:1;                      // 13 SDFIFO Enable
    Uint16 DRINTSEL:1;                  // 14 Data-Ready Interrupt Source Select
    Uint16 OVFIEN:1;                    // 15 SDFIFO Overflow interrupt enable
};

union SDFIFOCTL2_REG {
    Uint16  all;
    struct  SDFIFOCTL2_BITS  bit;
};

struct SDSYNC2_BITS {                   // bits description
    Uint16 SYNCSEL:6;                   // 5:0 SDSYNC Source Select
    Uint16 WTSYNCEN:1;                  // 6 Wait-for-Sync Enable
    Uint16 WTSYNFLG:1;                  // 7 Wait-for-Sync Flag
    Uint16 WTSYNCLR:1;                  // 8 Wait-for-Sync Flag Clear
    Uint16 FFSYNCCLREN:1;               // 9 FIFO Clear-on-SDSYNC Enable
    Uint16 WTSCLREN:1;                  // 10 WTSYNFLG Clear-on-FIFOINT Enable
    Uint16 rsvd1:5;                     // 15:11 Reserved
};

union SDSYNC2_REG {
    Uint16  all;
    struct  SDSYNC2_BITS  bit;
};

struct SDCTLPARM3_BITS {                // bits description
    Uint16 MOD:2;                       // 1:0 Modulator clocking modes
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:1;                     // 4 Reserved
    Uint16 rsvd4:11;                    // 15:5 Reserved
};

union SDCTLPARM3_REG {
    Uint16  all;
    struct  SDCTLPARM3_BITS  bit;
};

struct SDDFPARM3_BITS {                 // bits description
    Uint16 DOSR:8;                      // 7:0 Data Filter Oversample Ratio= DOSR+1
    Uint16 FEN:1;                       // 8 Filter Enable
    Uint16 AE:1;                        // 9 Ack Enable
    Uint16 SST:2;                       // 11:10 Data filter Structure (SincFast/1/2/3)
    Uint16 SDSYNCEN:1;                  // 12 Data Filter Reset Enable
    Uint16 rsvd1:3;                     // 15:13 Reserved
};

union SDDFPARM3_REG {
    Uint16  all;
    struct  SDDFPARM3_BITS  bit;
};

struct SDDPARM3_BITS {                  // bits description
    Uint16 rsvd1:10;                    // 9:0 Reserved
    Uint16 DR:1;                        // 10 Data Representation (0/1 = 16/32b 2's complement)
    Uint16 SH:5;                        // 15:11 Shift Control (# bits to shift in 16b mode)
};

union SDDPARM3_REG {
    Uint16  all;
    struct  SDDPARM3_BITS  bit;
};

struct SDCMPH3_BITS {                   // bits description
    Uint16 HLT:15;                      // 14:0 High-level threshold for the comparator filter output
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPH3_REG {
    Uint16  all;
    struct  SDCMPH3_BITS  bit;
};

struct SDCMPL3_BITS {                   // bits description
    Uint16 LLT:15;                      // 14:0 Low-level threshold for the comparator filter output
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPL3_REG {
    Uint16  all;
    struct  SDCMPL3_BITS  bit;
};

struct SDCPARM3_BITS {                  // bits description
    Uint16 COSR:5;                      // 4:0 Comparator Oversample Ratio. Actual rate COSR+1
    Uint16 IEH:1;                       // 5 High-level Interrupt enable.
    Uint16 IEL:1;                       // 6 Low-level interrupt enable
    Uint16 CS1_CS0:2;                   // 8:7 Comparator Filter Structure (SincFast/1/2/3)
    Uint16 MFIE:1;                      // 9 Modulator Failure Interrupt enable
    Uint16 HZEN:1;                      // 10 High level (Z) Threshold crossing output enable
    Uint16 rsvd1:2;                     // 12:11 Reserved
    Uint16 CEN:1;                       // 13 Comparator Enable
    Uint16 rsvd2:2;                     // 15:14 Reserved
};

union SDCPARM3_REG {
    Uint16  all;
    struct  SDCPARM3_BITS  bit;
};

struct SDDATA3_BITS {                   // bits description
    Uint16 DATA16:16;                   // 15:0 Lo-order 16b in 32b mode
    Uint16 DATA32HI:16;                 // 31:16 Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATA3_REG {
    Uint32  all;
    struct  SDDATA3_BITS  bit;
};

struct SDDATFIFO3_BITS {                // bits description
    Uint16 DATA16:16;                   // 15:0 Lo-order 16b in 32b mode
    Uint16 DATA32HI:16;                 // 31:16 Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATFIFO3_REG {
    Uint32  all;
    struct  SDDATFIFO3_BITS  bit;
};

struct SDCMPHZ3_BITS {                  // bits description
    Uint16 HLTZ:15;                     // 14:0 High-level threshold (Z) for the comparator filter output
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPHZ3_REG {
    Uint16  all;
    struct  SDCMPHZ3_BITS  bit;
};

struct SDFIFOCTL3_BITS {                // bits description
    Uint16 SDFFIL:5;                    // 4:0 SDFIFO Interrupt Level
    Uint16 rsvd1:1;                     // 5 Reserved
    Uint16 SDFFST:5;                    // 10:6 SDFIFO Status
    Uint16 rsvd2:1;                     // 11 Reserved
    Uint16 FFIEN:1;                     // 12 SDFIFO data ready Interrupt Enable
    Uint16 FFEN:1;                      // 13 SDFIFO Enable
    Uint16 DRINTSEL:1;                  // 14 Data-Ready Interrupt Source Select
    Uint16 OVFIEN:1;                    // 15 SDFIFO Overflow interrupt enable
};

union SDFIFOCTL3_REG {
    Uint16  all;
    struct  SDFIFOCTL3_BITS  bit;
};

struct SDSYNC3_BITS {                   // bits description
    Uint16 SYNCSEL:6;                   // 5:0 SDSYNC Source Select
    Uint16 WTSYNCEN:1;                  // 6 Wait-for-Sync Enable
    Uint16 WTSYNFLG:1;                  // 7 Wait-for-Sync Flag
    Uint16 WTSYNCLR:1;                  // 8 Wait-for-Sync Flag Clear
    Uint16 FFSYNCCLREN:1;               // 9 FIFO Clear-on-SDSYNC Enable
    Uint16 WTSCLREN:1;                  // 10 WTSYNFLG Clear-on-FIFOINT Enable
    Uint16 rsvd1:5;                     // 15:11 Reserved
};

union SDSYNC3_REG {
    Uint16  all;
    struct  SDSYNC3_BITS  bit;
};

struct SDCTLPARM4_BITS {                // bits description
    Uint16 MOD:2;                       // 1:0 Modulator clocking modes
    Uint16 rsvd1:1;                     // 2 Reserved
    Uint16 rsvd2:1;                     // 3 Reserved
    Uint16 rsvd3:1;                     // 4 Reserved
    Uint16 rsvd4:11;                    // 15:5 Reserved
};

union SDCTLPARM4_REG {
    Uint16  all;
    struct  SDCTLPARM4_BITS  bit;
};

struct SDDFPARM4_BITS {                 // bits description
    Uint16 DOSR:8;                      // 7:0 Data Filter Oversample Ratio= DOSR+1
    Uint16 FEN:1;                       // 8 Filter Enable
    Uint16 AE:1;                        // 9 Ack Enable
    Uint16 SST:2;                       // 11:10 Data filter Structure (SincFast/1/2/3)
    Uint16 SDSYNCEN:1;                  // 12 Data Filter Reset Enable
    Uint16 rsvd1:3;                     // 15:13 Reserved
};

union SDDFPARM4_REG {
    Uint16  all;
    struct  SDDFPARM4_BITS  bit;
};

struct SDDPARM4_BITS {                  // bits description
    Uint16 rsvd1:10;                    // 9:0 Reserved
    Uint16 DR:1;                        // 10 Data Representation (0/1 = 16/32b 2's complement)
    Uint16 SH:5;                        // 15:11 Shift Control (# bits to shift in 16b mode)
};

union SDDPARM4_REG {
    Uint16  all;
    struct  SDDPARM4_BITS  bit;
};

struct SDCMPH4_BITS {                   // bits description
    Uint16 HLT:15;                      // 14:0 High-level threshold for the comparator filter output
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPH4_REG {
    Uint16  all;
    struct  SDCMPH4_BITS  bit;
};

struct SDCMPL4_BITS {                   // bits description
    Uint16 LLT:15;                      // 14:0 Low-level threshold for the comparator filter output
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPL4_REG {
    Uint16  all;
    struct  SDCMPL4_BITS  bit;
};

struct SDCPARM4_BITS {                  // bits description
    Uint16 COSR:5;                      // 4:0 Comparator Oversample Ratio. Actual rate COSR+1
    Uint16 IEH:1;                       // 5 High-level Interrupt enable.
    Uint16 IEL:1;                       // 6 Low-level interrupt enable
    Uint16 CS1_CS0:2;                   // 8:7 Comparator Filter Structure (SincFast/1/2/3)
    Uint16 MFIE:1;                      // 9 Modulator Failure Interrupt enable
    Uint16 HZEN:1;                      // 10 High level (Z) Threshold crossing output enable
    Uint16 rsvd1:2;                     // 12:11 Reserved
    Uint16 CEN:1;                       // 13 Comparator Enable
    Uint16 rsvd2:2;                     // 15:14 Reserved
};

union SDCPARM4_REG {
    Uint16  all;
    struct  SDCPARM4_BITS  bit;
};

struct SDDATA4_BITS {                   // bits description
    Uint16 DATA16:16;                   // 15:0 Lo-order 16b in 32b mode
    Uint16 DATA32HI:16;                 // 31:16 Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATA4_REG {
    Uint32  all;
    struct  SDDATA4_BITS  bit;
};

struct SDDATFIFO4_BITS {                // bits description
    Uint16 DATA16:16;                   // 15:0 Lo-order 16b in 32b mode
    Uint16 DATA32HI:16;                 // 31:16 Hi-order 16b in 32b mode, 16-bit Data in 16b mode
};

union SDDATFIFO4_REG {
    Uint32  all;
    struct  SDDATFIFO4_BITS  bit;
};

struct SDCMPHZ4_BITS {                  // bits description
    Uint16 HLTZ:15;                     // 14:0 High-level threshold (Z) for the comparator filter output
    Uint16 rsvd1:1;                     // 15 Reserved
};

union SDCMPHZ4_REG {
    Uint16  all;
    struct  SDCMPHZ4_BITS  bit;
};

struct SDFIFOCTL4_BITS {                // bits description
    Uint16 SDFFIL:5;                    // 4:0 SDFIFO Interrupt Level
    Uint16 rsvd1:1;                     // 5 Reserved
    Uint16 SDFFST:5;                    // 10:6 SDFIFO Status
    Uint16 rsvd2:1;                     // 11 Reserved
    Uint16 FFIEN:1;                     // 12 SDFIFO data ready Interrupt Enable
    Uint16 FFEN:1;                      // 13 SDFIFO Enable
    Uint16 DRINTSEL:1;                  // 14 Data-Ready Interrupt Source Select
    Uint16 OVFIEN:1;                    // 15 SDFIFO Overflow interrupt enable
};

union SDFIFOCTL4_REG {
    Uint16  all;
    struct  SDFIFOCTL4_BITS  bit;
};

struct SDSYNC4_BITS {                   // bits description
    Uint16 SYNCSEL:6;                   // 5:0 SDSYNC Source Select
    Uint16 WTSYNCEN:1;                  // 6 Wait-for-Sync Enable
    Uint16 WTSYNFLG:1;                  // 7 Wait-for-Sync Flag
    Uint16 WTSYNCLR:1;                  // 8 Wait-for-Sync Flag Clear
    Uint16 FFSYNCCLREN:1;               // 9 FIFO Clear-on-SDSYNC Enable
    Uint16 WTSCLREN:1;                  // 10 WTSYNFLG Clear-on-FIFOINT Enable
    Uint16 rsvd1:5;                     // 15:11 Reserved
};

union SDSYNC4_REG {
    Uint16  all;
    struct  SDSYNC4_BITS  bit;
};

struct SDFM_REGS {
    union   SDIFLG_REG                       SDIFLG;                       // SD Interrupt Flag Register
    union   SDIFLGCLR_REG                    SDIFLGCLR;                    // SD Interrupt Flag Clear Register
    union   SDCTL_REG                        SDCTL;                        // SD Control Register
    Uint16                                   rsvd1;                        // Reserved
    union   SDMFILEN_REG                     SDMFILEN;                     // SD Master Filter Enable
    union   SDSTATUS_REG                     SDSTATUS;                     // SD Status Register
    Uint16                                   rsvd2[8];                     // Reserved
    union   SDCTLPARM1_REG                   SDCTLPARM1;                   // Control Parameter Register for Ch1
    union   SDDFPARM1_REG                    SDDFPARM1;                    // Data Filter Parameter Register for Ch1
    union   SDDPARM1_REG                     SDDPARM1;                     // Data Parameter Register for Ch1
    union   SDCMPH1_REG                      SDCMPH1;                      // High-level Threshold Register for Ch1
    union   SDCMPL1_REG                      SDCMPL1;                      // Low-level Threshold Register for Ch1
    union   SDCPARM1_REG                     SDCPARM1;                     // Comparator Filter Parameter Register for Ch1
    union   SDDATA1_REG                      SDDATA1;                      // Data Filter Data Register (16 or 32bit) for Ch1
    union   SDDATFIFO1_REG                   SDDATFIFO1;                   // Filter Data FIFO Output(32b) for Ch1
    Uint16                                   SDCDATA1;                     // Comparator Filter Data Register (16b) for Ch1
    Uint16                                   rsvd3;                        // Reserved
    union   SDCMPHZ1_REG                     SDCMPHZ1;                     // High-level (Z) Threshold Register for Ch1
    union   SDFIFOCTL1_REG                   SDFIFOCTL1;                   // FIFO Control Register for Ch1
    union   SDSYNC1_REG                      SDSYNC1;                      // SD Filter Sync control for Ch1
    Uint16                                   rsvd4;                        // Reserved
    union   SDCTLPARM2_REG                   SDCTLPARM2;                   // Control Parameter Register for Ch2
    union   SDDFPARM2_REG                    SDDFPARM2;                    // Data Filter Parameter Register for Ch2
    union   SDDPARM2_REG                     SDDPARM2;                     // Data Parameter Register for Ch2
    union   SDCMPH2_REG                      SDCMPH2;                      // High-level Threshold Register for Ch2
    union   SDCMPL2_REG                      SDCMPL2;                      // Low-level Threshold Register for Ch2
    union   SDCPARM2_REG                     SDCPARM2;                     // Comparator Filter Parameter Register for Ch2
    union   SDDATA2_REG                      SDDATA2;                      // Data Filter Data Register (16 or 32bit) for Ch2
    union   SDDATFIFO2_REG                   SDDATFIFO2;                   // Filter Data FIFO Output(32b) for Ch2
    Uint16                                   SDCDATA2;                     // Comparator Filter Data Register (16b) for Ch2
    Uint16                                   rsvd5;                        // Reserved
    union   SDCMPHZ2_REG                     SDCMPHZ2;                     // High-level (Z) Threshold Register for Ch2
    union   SDFIFOCTL2_REG                   SDFIFOCTL2;                   // FIFO Control Register for Ch2
    union   SDSYNC2_REG                      SDSYNC2;                      // SD Filter Sync control for Ch2
    Uint16                                   rsvd6;                        // Reserved
    union   SDCTLPARM3_REG                   SDCTLPARM3;                   // Control Parameter Register for Ch3
    union   SDDFPARM3_REG                    SDDFPARM3;                    // Data Filter Parameter Register for Ch3
    union   SDDPARM3_REG                     SDDPARM3;                     // Data Parameter Register for Ch3
    union   SDCMPH3_REG                      SDCMPH3;                      // High-level Threshold Register for Ch3
    union   SDCMPL3_REG                      SDCMPL3;                      // Low-level Threshold Register for Ch3
    union   SDCPARM3_REG                     SDCPARM3;                     // Comparator Filter Parameter Register for Ch3
    union   SDDATA3_REG                      SDDATA3;                      // Data Filter Data Register (16 or 32bit) for Ch3
    union   SDDATFIFO3_REG                   SDDATFIFO3;                   // Filter Data FIFO Output(32b) for Ch3
    Uint16                                   SDCDATA3;                     // Comparator Filter Data Register (16b) for Ch3
    Uint16                                   rsvd7;                        // Reserved
    union   SDCMPHZ3_REG                     SDCMPHZ3;                     // High-level (Z) Threshold Register for Ch3
    union   SDFIFOCTL3_REG                   SDFIFOCTL3;                   // FIFO Control Register for Ch3
    union   SDSYNC3_REG                      SDSYNC3;                      // SD Filter Sync control for Ch3
    Uint16                                   rsvd8;                        // Reserved
    union   SDCTLPARM4_REG                   SDCTLPARM4;                   // Control Parameter Register for Ch4
    union   SDDFPARM4_REG                    SDDFPARM4;                    // Data Filter Parameter Register for Ch4
    union   SDDPARM4_REG                     SDDPARM4;                     // Data Parameter Register for Ch4
    union   SDCMPH4_REG                      SDCMPH4;                      // High-level Threshold Register for Ch4
    union   SDCMPL4_REG                      SDCMPL4;                      // Low-level Threshold Register for Ch4
    union   SDCPARM4_REG                     SDCPARM4;                     // Comparator Filter Parameter Register for Ch4
    union   SDDATA4_REG                      SDDATA4;                      // Data Filter Data Register (16 or 32bit) for Ch4
    union   SDDATFIFO4_REG                   SDDATFIFO4;                   // Filter Data FIFO Output(32b) for Ch4
    Uint16                                   SDCDATA4;                     // Comparator Filter Data Register (16b) for Ch4
    Uint16                                   rsvd9;                        // Reserved
    union   SDCMPHZ4_REG                     SDCMPHZ4;                     // High-level (Z) Threshold Register for Ch4
    union   SDFIFOCTL4_REG                   SDFIFOCTL4;                   // FIFO Control Register for Ch4
    union   SDSYNC4_REG                      SDSYNC4;                      // SD Filter Sync control for Ch4
    Uint16                                   rsvd10[33];                   // Reserved
};

//---------------------------------------------------------------------------
// SDFM External References & Function Declarations:
//
extern volatile struct SDFM_REGS Sdfm1Regs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
