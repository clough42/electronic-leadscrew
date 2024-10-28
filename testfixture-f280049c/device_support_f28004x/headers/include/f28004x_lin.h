//###########################################################################
//
// FILE:    f28004x_lin.h
//
// TITLE:   LIN Register Definitions.
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

#ifndef __F28004X_LIN_H__
#define __F28004X_LIN_H__

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// LIN Individual Register Bit Definitions:

struct SCIGCR0_BITS {                  // bits description
    bp_16 RESET:1;                     // 0 LIN Module reset bit
    bp_16 rsvd1:15;                    // 15:1 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union SCIGCR0_REG {
    bp_32  all;
    struct  SCIGCR0_BITS  bit;
};

struct SCIGCR1_BITS {                  // bits description
    bp_16 COMMMODE:1;                  // 0 SCI/LIN communications mode bit
    bp_16 TIMINGMODE:1;                // 1 SCI timing mode bit. Should be set to 1 for SCI mode.
    bp_16 PARITYENA:1;                 // 2 Parity enable
    bp_16 PARITY:1;                    // 3 SCI parity odd/even selection
    bp_16 STOP:1;                      // 4 SCI number of stop bits
    bp_16 CLK_MASTER:1;                // 5 LIN Master/Slave selection and SCI clock enable
    bp_16 LINMODE:1;                   // 6 LIN Mode enable/disable
    bp_16 SWnRST:1;                    // 7 Software reset
    bp_16 SLEEP:1;                     // 8 SCI sleep (SCI compatibility mode)
    bp_16 ADAPT:1;                     // 9 Automatic baudrate adjustment control(LIN mode)
    bp_16 MBUFMODE:1;                  // 10 Multi-buffer mode
    bp_16 CTYPE:1;                     // 11 Checksum type (LIN mode)
    bp_16 HGENCTRL:1;                  // 12 Mask filtering comparison control (LIN mode)
    bp_16 STOPEXTFRAME:1;              // 13 Stop extended frame communication (LIN mode)
    bp_16 rsvd1:2;                     // 15:14 Reserved
    bp_32 LOOPBACK:1;                  // 16 Digital loopback mode
    bp_32 CONT:1;                      // 17 Continue on suspend
    bp_32 rsvd2:6;                     // 23:18 Reserved
    bp_32 RXENA:1;                     // 24 SCI mode receiver enable
    bp_32 TXENA:1;                     // 25 SCI mode transmitter enable
    bp_32 rsvd3:6;                     // 31:26 Reserved
};

union SCIGCR1_REG {
    bp_32  all;
    struct  SCIGCR1_BITS  bit;
};

struct SCIGCR2_BITS {                  // bits description
    bp_16 POWERDOWN:1;                 // 0 Low-power mode PowerDown bit
    bp_16 rsvd1:7;                     // 7:1 Reserved
    bp_16 GENWU:1;                     // 8 Generate Wakeup
    bp_16 rsvd2:7;                     // 15:9 Reserved
    bp_32 SC:1;                        // 16 Send Checksum (LIN mode)
    bp_32 CC:1;                        // 17 Compare Checksum (LIN mode)
    bp_32 rsvd3:14;                    // 31:18 Reserved
};

union SCIGCR2_REG {
    bp_32  all;
    struct  SCIGCR2_BITS  bit;
};

struct SCISETINT_BITS {                // bits description
    bp_16 SETBRKDTINT:1;               // 0 Set Break-detect Interrupt (SCI compatible mode)
    bp_16 SETWAKEUPINT:1;              // 1 Set Wake-up Interrupt
    bp_16 rsvd1:2;                     // 3:2 Reserved
    bp_16 SETTIMEOUTINT:1;             // 4 Set Timeout Interrupt (LIN only)
    bp_16 rsvd2:1;                     // 5 Reserved
    bp_16 SETTOAWUSINT:1;              // 6 Set Timeout After Wakeup Signal Interrupt (LIN only)
    bp_16 SETTOA3WUSINT:1;             // 7 Set Timeout After 3 Wakeup Signals Interrupt (LIN only)
    bp_16 SETTXINT:1;                  // 8 Set Transmitter Interrupt
    bp_16 SETRXINT:1;                  // 9 Receiver Interrupt Enable
    bp_16 rsvd3:3;                     // 12:10 Reserved
    bp_16 SETIDINT:1;                  // 13 Set Identifier Interrupt (LIN only)
    bp_16 rsvd4:2;                     // 15:14 Reserved
    bp_32 rsvd5:2;                     // 17:16 Reserved
    bp_32 rsvd6:1;                     // 18 Reserved
    bp_32 rsvd7:5;                     // 23:19 Reserved
    bp_32 SETPEINT:1;                  // 24 Set Parity Interrupt
    bp_32 SETOEINT:1;                  // 25 Set Overrun-Error Interrupt
    bp_32 SETFEINT:1;                  // 26 Set Framing-Error Interrupt
    bp_32 SETNREINT:1;                 // 27 Set No-Response-Error Interrupt (LIN only)
    bp_32 SETISFEINT:1;                // 28 Set Inconsistent-Synch-Field-Error Interrupt (LIN only)
    bp_32 SETCEINT:1;                  // 29 Set Checksum-error Interrupt (LIN only)
    bp_32 SETPBEINT:1;                 // 30 Set Physical Bus Error Interrupt (LIN only)
    bp_32 SETBEINT:1;                  // 31 Set Bit Error Interrupt (LIN only)
};

union SCISETINT_REG {
    bp_32  all;
    struct  SCISETINT_BITS  bit;
};

struct SCICLEARINT_BITS {              // bits description
    bp_16 CLRBRKDTINT:1;               // 0 Clear Break-detect Interrupt (SCI compatible mode
    bp_16 CLRWAKEUPINT:1;              // 1 Clear Wake-up Interrupt
    bp_16 rsvd1:2;                     // 3:2 Reserved
    bp_16 CLRTIMEOUTINT:1;             // 4 Clear Timeout Interrupt (LIN only)
    bp_16 rsvd2:1;                     // 5 Reserved
    bp_16 CLRTOAWUSINT:1;              // 6 Clear Timeout After Wakeup Signal Interrupt (LIN only)
    bp_16 CLRTOA3WUSINT:1;             // 7 Clear Timeout After 3 Wakeup Signals Interrupt (LIN only)
    bp_16 CLRTXINT:1;                  // 8 Clear Transmitter Interrupt
    bp_16 CLRRXINT:1;                  // 9 Clear Receiver Interrupt
    bp_16 rsvd3:3;                     // 12:10 Reserved
    bp_16 CLRIDINT:1;                  // 13 Clear Identifier Interrupt (LIN only)
    bp_16 rsvd4:2;                     // 15:14 Reserved
    bp_32 rsvd5:2;                     // 17:16 Reserved
    bp_32 rsvd6:1;                     // 18 Reserved
    bp_32 rsvd7:5;                     // 23:19 Reserved
    bp_32 CLRPEINT:1;                  // 24 Clear Parity Interrupt
    bp_32 CLROEINT:1;                  // 25 Clear Overrun-Error Interrupt
    bp_32 CLRFEINT:1;                  // 26 Clear Framing-Error Interrupt
    bp_32 CLRNREINT:1;                 // 27 Clear No-Response-Error Interrupt (LIN only)
    bp_32 CLRISFEINT:1;                // 28 Clear Inconsistent-Synch-Field-Error Interrupt (LIN only)
    bp_32 CLRCEINT:1;                  // 29 Clear Checksum-error Interrupt (LIN only)
    bp_32 CLRPBEINT:1;                 // 30 Clear Physical Bus Error Interrupt (LIN only)
    bp_32 CLRBEINT:1;                  // 31 Clear Bit Error Interrupt (LIN only)
};

union SCICLEARINT_REG {
    bp_32  all;
    struct  SCICLEARINT_BITS  bit;
};

struct SCISETINTLVL_BITS {             // bits description
    bp_16 SETBRKDTINTLVL:1;            // 0 Set Break-detect Interrupt Level (SCI compatible mode)
    bp_16 SETWAKEUPINTLVL:1;           // 1 Set Wake-up Interrupt Level
    bp_16 rsvd1:2;                     // 3:2 Reserved
    bp_16 SETTIMEOUTINTLVL:1;          // 4 Set Timeout Interrupt Level (LIN only)
    bp_16 rsvd2:1;                     // 5 Reserved
    bp_16 SETTOAWUSINTLVL:1;           // 6 Set Timeout After Wakeup Signal Interrupt Level (LIN only)
    bp_16 SETTOA3WUSINTLVL:1;          // 7 Set Timeout After 3 Wakeup Signals
    bp_16 SETTXINTLVL:1;               // 8 Set Transmitter Interrupt Level
    bp_16 SETRXINTOVO:1;               // 9 Receiver Interrupt Enable Level
    bp_16 rsvd3:3;                     // 12:10 Reserved
    bp_16 SETIDINTLVL:1;               // 13 Set Identifier Interrupt Level (LIN only)
    bp_16 rsvd4:2;                     // 15:14 Reserved
    bp_32 rsvd5:2;                     // 17:16 Reserved
    bp_32 rsvd6:1;                     // 18 Reserved
    bp_32 rsvd7:5;                     // 23:19 Reserved
    bp_32 SETPEINTLVL:1;               // 24 Set Parity Interrupt Level
    bp_32 SETOEINTLVL:1;               // 25 Set Overrun-Error Interrupt Level
    bp_32 SETFEINTLVL:1;               // 26 Set Framing-Error Interrupt Level
    bp_32 SETNREINTLVL:1;              // 27 Set No-Response-Error Interrupt Level (LIN only)
    bp_32 SETISFEINTLVL:1;             // 28 Set Inconsistent-Synch-Field-Error Interrupt Level
    bp_32 SETCEINTLVL:1;               // 29 Set Checksum-error Interrupt Level (LIN only)
    bp_32 SETPBEINTLVL:1;              // 30 Set Physical Bus Error Interrupt Level (LIN only)
    bp_32 SETBEINTLVL:1;               // 31 Set Bit Error Interrupt Level(LIN only)
};

union SCISETINTLVL_REG {
    bp_32  all;
    struct  SCISETINTLVL_BITS  bit;
};

struct SCICLEARINTLVL_BITS {           // bits description
    bp_16 CLRBRKDTINTLVL:1;            // 0 Clear Break-detect Interrupt Level (SCI compatible mode)
    bp_16 CLRWAKEUPINTLVL:1;           // 1 Clear Wake-up Interrupt Level
    bp_16 rsvd1:2;                     // 3:2 Reserved
    bp_16 CLRTIMEOUTINTLVL:1;          // 4  Clear Timeout Interrupt Level (LIN only)
    bp_16 rsvd2:1;                     // 5 Reserved
    bp_16 CLRTOAWUSINTLVL:1;           // 6 Clear Timeout After Wakeup Signal Interrupt Level (LIN only)
    bp_16 CLRTOA3WUSINTLVL:1;          // 7 Clear Timeout After 3 Wakeup Signals
    bp_16 CLRTXINTLVL:1;               // 8 Clear Transmitter Interrupt Level
    bp_16 CLRRXINTLVL:1;               // 9 Clear Receiver interrupt Level.
    bp_16 rsvd3:3;                     // 12:10 Reserved
    bp_16 CLRIDINTLVL:1;               // 13 Clear Identifier Interrupt Level (LIN only)
    bp_16 rsvd4:2;                     // 15:14 Reserved
    bp_32 rsvd5:2;                     // 17:16 Reserved
    bp_32 rsvd6:1;                     // 18 Reserved
    bp_32 rsvd7:5;                     // 23:19 Reserved
    bp_32 CLRPEINTLVL:1;               // 24 Clear Parity Interrupt Level
    bp_32 CLROEINTLVL:1;               // 25 Clear Overrun-Error Interrupt Level
    bp_32 CLRFEINTLVL:1;               // 26 Clear Framing-Error Interrupt Level
    bp_32 CLRNREINTLVL:1;              // 27 Clear No-Response-Error Interrupt Level (LIN only)
    bp_32 CLRISFEINTLVL:1;             // 28 Clear Inconsistent-Synch-Field-Error
    bp_32 CLRCEINTLVL:1;               // 29 Clear Checksum-error Interrupt Level (LIN only)
    bp_32 CLRPBEINTLVL:1;              // 30 Clear Physical Bus Error Interrupt Level (LIN only)
    bp_32 CLRBEINTLVL:1;               // 31 Clear Bit Error Interrupt Level (LIN only)
};

union SCICLEARINTLVL_REG {
    bp_32  all;
    struct  SCICLEARINTLVL_BITS  bit;
};

struct SCIFLR_BITS {                   // bits description
    bp_16 BRKDT:1;                     // 0 Break-detect Flag (SCI compatible mode)
    bp_16 WAKEUP:1;                    // 1 Wake-up Flag
    bp_16 IDLE:1;                      // 2 SCI receiver in idle state (SCI compatible mode)
    bp_16 BUSY:1;                      // 3 Busy Flag
    bp_16 TIMEOUT:1;                   // 4 LIN Bus IDLE timeout Flag (LIN only)
    bp_16 rsvd1:1;                     // 5 Reserved
    bp_16 TOAWUS:1;                    // 6 Timeout After Wakeup Signal Flag (LIN only)
    bp_16 TOA3WUS:1;                   // 7 Timeout After 3 Wakeup Signals Flag (LIN only)
    bp_16 TXRDY:1;                     // 8 Transmitter Buffer Ready Flag
    bp_16 RXRDY:1;                     // 9 Receiver Buffer Ready Flag
    bp_16 TXWAKE:1;                    // 10 SCI Transmitter Wakeup Method Select
    bp_16 TXEMPTY:1;                   // 11 Transmitter Empty Clag
    bp_16 RXWAKE:1;                    // 12 Receiver Wakeup Detect Flag
    bp_16 IDTXFLAG:1;                  // 13 Identifier On Transmit Flag (LIN only)
    bp_16 IDRXFLAG:1;                  // 14 Identifier on Receive Flag
    bp_16 rsvd2:1;                     // 15 Reserved
    bp_32 rsvd3:8;                     // 23:16 Reserved
    bp_32 PE:1;                        // 24 Parity Error Flag
    bp_32 OE:1;                        // 25 Overrun Error Flag
    bp_32 FE:1;                        // 26 Framing Error Flag
    bp_32 NRE:1;                       // 27 No-Response Error Flag (LIN only)
    bp_32 ISFE:1;                      // 28 Inconsistent Synch Field Error Flag (LIN only)
    bp_32 CE:1;                        // 29 Checksum Error Flag (LIN only)
    bp_32 PBE:1;                       // 30 Physical Bus Error Flag (LIN only)
    bp_32 BE:1;                        // 31 Bit Error Flag (LIN only)
};

union SCIFLR_REG {
    bp_32  all;
    struct  SCIFLR_BITS  bit;
};

struct SCIINTVECT0_BITS {              // bits description
    bp_16 INTVECT0:5;                  // 4:0 LIN Module reset bit
    bp_16 rsvd1:11;                    // 15:5 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union SCIINTVECT0_REG {
    bp_32  all;
    struct  SCIINTVECT0_BITS  bit;
};

struct SCIINTVECT1_BITS {              // bits description
    bp_16 INTVECT1:5;                  // 4:0 LIN Module reset bit
    bp_16 rsvd1:11;                    // 15:5 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union SCIINTVECT1_REG {
    bp_32  all;
    struct  SCIINTVECT1_BITS  bit;
};

struct SCIFORMAT_BITS {                // bits description
    bp_16 CHAR:5;                      // 4:0 Character Length Control Bits
    bp_16 rsvd1:11;                    // 15:5 Reserved
    bp_32 LENGTH:3;                    // 18:16 Frame Length Control Bits
    bp_32 rsvd2:13;                    // 31:19 Reserved
};

union SCIFORMAT_REG {
    bp_32  all;
    struct  SCIFORMAT_BITS  bit;
};

struct BRSR_BITS {                     // bits description
    bp_16 SCI_LIN_PSL:16;              // 15:0 Character Length Control Bits
    bp_32 SCI_LIN_PSH:8;               // 23:16 24-Bit Integer Prescaler Select
    bp_32 M:4;                         // 27:24 Frame Length Control Bits
    bp_32 rsvd1:4;                     // 31:28 Reserved
};

union BRSR_REG {
    bp_32  all;
    struct  BRSR_BITS  bit;
};

struct SCIED_BITS {                    // bits description
    bp_16 ED:8;                        // 7:0 Receiver Emulation Data.
    bp_16 rsvd1:8;                     // 15:8 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union SCIED_REG {
    bp_32  all;
    struct  SCIED_BITS  bit;
};

struct SCIRD_BITS {                    // bits description
    bp_16 RD:8;                        // 7:0 Received Data.
    bp_16 rsvd1:8;                     // 15:8 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union SCIRD_REG {
    bp_32  all;
    struct  SCIRD_BITS  bit;
};

struct SCITD_BITS {                    // bits description
    bp_16 TD:8;                        // 7:0 Transmit data
    bp_16 rsvd1:8;                     // 15:8 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union SCITD_REG {
    bp_32  all;
    struct  SCITD_BITS  bit;
};

struct SCIPIO0_BITS {                  // bits description
    bp_16 rsvd1:1;                     // 0 Reserved
    bp_16 RXFUNC:1;                    // 1 LINRX pin function
    bp_16 TXFUNC:1;                    // 2 LINTX pin function
    bp_16 rsvd2:13;                    // 15:3 Reserved
    bp_32 rsvd3:16;                    // 31:16 Reserved
};

union SCIPIO0_REG {
    bp_32  all;
    struct  SCIPIO0_BITS  bit;
};

struct SCIPIO2_BITS {                  // bits description
    bp_16 rsvd1:1;                     // 0 Reserved
    bp_16 RXIN:1;                      // 1 SCIRX pin value
    bp_16 TXIN:1;                      // 2 SCITX pin value
    bp_16 rsvd2:13;                    // 15:3 Reserved
    bp_32 rsvd3:16;                    // 31:16 Reserved
};

union SCIPIO2_REG {
    bp_32  all;
    struct  SCIPIO2_BITS  bit;
};

struct LINCOMP_BITS {                  // bits description
    bp_16 SBREAK:3;                    // 2:0 Synch Break Extend
    bp_16 rsvd1:5;                     // 7:3 Reserved
    bp_16 SDEL:2;                      // 9:8 Sync Delimiter Compare
    bp_16 rsvd2:6;                     // 15:10 Reserved
    bp_32 rsvd3:16;                    // 31:16 Reserved
};

union LINCOMP_REG {
    bp_32  all;
    struct  LINCOMP_BITS  bit;
};

struct LINRD0_BITS {                   // bits description
    bp_16 RD3:8;                       // 7:0 Receive Buffer 3
    bp_16 RD2:8;                       // 15:8 Receive Buffer 2
    bp_32 RD1:8;                       // 23:16 Receive Buffer 1
    bp_32 RD0:8;                       // 31:24 Receive Buffer 0
};

union LINRD0_REG {
    bp_32  all;
    struct  LINRD0_BITS  bit;
};

struct LINRD1_BITS {                   // bits description
    bp_16 RD7:8;                       // 7:0 Receive Buffer 3
    bp_16 RD6:8;                       // 15:8 Receive Buffer 2
    bp_32 RD5:8;                       // 23:16 Receive Buffer 1
    bp_32 RD4:8;                       // 31:24 Receive Buffer 0
};

union LINRD1_REG {
    bp_32  all;
    struct  LINRD1_BITS  bit;
};

struct LINMASK_BITS {                  // bits description
    bp_16 TXIDMASK:8;                  // 7:0 TX ID Mask bits (LIN only)
    bp_16 rsvd1:8;                     // 15:8 Reserved
    bp_32 RXIDMASK:8;                  // 23:16 RX ID Mask bits (LIN only)
    bp_32 rsvd2:8;                     // 31:24 Reserved
};

union LINMASK_REG {
    bp_32  all;
    struct  LINMASK_BITS  bit;
};

struct LINID_BITS {                    // bits description
    bp_16 IDBYTE:8;                    // 7:0 LIN message ID (LIN only)
    bp_16 IDSLAVETASKBYTE:8;           // 15:8 Received ID comparison ID (LIN only)
    bp_32 RECEIVEDID:8;                // 23:16 Current Message ID (LIN only)
    bp_32 rsvd1:8;                     // 31:24 Reserved
};

union LINID_REG {
    bp_32  all;
    struct  LINID_BITS  bit;
};

struct LINTD0_BITS {                   // bits description
    bp_16 TD3:8;                       // 7:0 TRANSMIT Buffer 3
    bp_16 TD2:8;                       // 15:8 TRANSMIT Buffer 2
    bp_32 TD1:8;                       // 23:16 TRANSMIT Buffer 1
    bp_32 TD0:8;                       // 31:24 TRANSMIT Buffer 0
};

union LINTD0_REG {
    bp_32  all;
    struct  LINTD0_BITS  bit;
};

struct LINTD1_BITS {                   // bits description
    bp_16 TD7:8;                       // 7:0 TRANSMIT Buffer 7
    bp_16 TD6:8;                       // 15:8 TRANSMIT Buffer 6
    bp_32 TD5:8;                       // 23:16 TRANSMIT Buffer 5
    bp_32 TD4:8;                       // 31:24 TRANSMIT Buffer 4
};

union LINTD1_REG {
    bp_32  all;
    struct  LINTD1_BITS  bit;
};

struct MBRSR_BITS {                    // bits description
    bp_16 MBR:13;                      // 12:0 Received Data.
    bp_16 rsvd1:3;                     // 15:13 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union MBRSR_REG {
    bp_32  all;
    struct  MBRSR_BITS  bit;
};

struct IODFTCTRL_BITS {                // bits description
    bp_16 RXPENA:1;                    // 0 Analog Loopback Via Receive Pin Enable
    bp_16 LPBENA:1;                    // 1 Module Loopback Enable
    bp_16 rsvd1:6;                     // 7:2 Reserved
    bp_16 IODFTENA:4;                  // 11:8 IO DFT Enable Key
    bp_16 rsvd2:4;                     // 15:12 Reserved
    bp_32 TXSHIFT:3;                   // 18:16 Transmit Delay Shift
    bp_32 PINSAMPLEMASK:2;             // 20:19 TX Pin Sample Mask
    bp_32 rsvd3:3;                     // 23:21 Reserved
    bp_32 BRKDTERRENA:1;               // 24 Break Detect Error Enable (SCI compatibility mode)
    bp_32 PERRENA:1;                   // 25 Parity Error Enable (SCI compatibility mode)
    bp_32 FERRENA:1;                   // 26 Frame Error Enable (SCI compatibility mode)
    bp_32 rsvd4:1;                     // 27 Reserved
    bp_32 ISFERRENA:1;                 // 28 Inconsistent Synch Field Error Enable (LIN mode)
    bp_32 CERRENA:1;                   // 29 Checksum Error Enable(LIN mode)
    bp_32 PBERRENA:1;                  // 30 Physical Bus Error Enable (LIN mode)
    bp_32 BERRENA:1;                   // 31 Bit Error Enable (LIN mode)
};

union IODFTCTRL_REG {
    bp_32  all;
    struct  IODFTCTRL_BITS  bit;
};

struct LIN_GLB_INT_EN_BITS {           // bits description
    bp_16 GLBINT0_EN:1;                // 0 Global Interrupt Enable for  LIN INT0
    bp_16 GLBINT1_EN:1;                // 1 Global Interrupt Enable for  LIN INT1
    bp_16 rsvd1:14;                    // 15:2 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union LIN_GLB_INT_EN_REG {
    bp_32  all;
    struct  LIN_GLB_INT_EN_BITS  bit;
};

struct LIN_GLB_INT_FLG_BITS {          // bits description
    bp_16 INT0_FLG:1;                  // 0 Global Interrupt Flag for LIN INT0
    bp_16 INT1_FLG:1;                  // 1 Global Interrupt Flag for LIN INT1
    bp_16 rsvd1:14;                    // 15:2 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union LIN_GLB_INT_FLG_REG {
    bp_32  all;
    struct  LIN_GLB_INT_FLG_BITS  bit;
};

struct LIN_GLB_INT_CLR_BITS {          // bits description
    bp_16 INT0_FLG_CLR:1;              // 0 Global Interrupt flag clear for LIN INT0
    bp_16 INT1_FLG_CLR:1;              // 1 Global Interrupt flag  clear for LIN INT1
    bp_16 rsvd1:14;                    // 15:2 Reserved
    bp_32 rsvd2:16;                    // 31:16 Reserved
};

union LIN_GLB_INT_CLR_REG {
    bp_32  all;
    struct  LIN_GLB_INT_CLR_BITS  bit;
};

struct LIN_REGS {
    union   SCIGCR0_REG                      SCIGCR0;                      // Global Control Register 0
    union   SCIGCR1_REG                      SCIGCR1;                      // Global Control Register 1
    union   SCIGCR2_REG                      SCIGCR2;                      // Global Control Register 2
    union   SCISETINT_REG                    SCISETINT;                    // Interrupt Enable Register
    union   SCICLEARINT_REG                  SCICLEARINT;                  // Interrupt Disable Register
    union   SCISETINTLVL_REG                 SCISETINTLVL;                 // Set Interrupt Level Register
    union   SCICLEARINTLVL_REG               SCICLEARINTLVL;               // Clear Interrupt Level Register
    union   SCIFLR_REG                       SCIFLR;                       // Flag Register
    union   SCIINTVECT0_REG                  SCIINTVECT0;                  // Interrupt Vector Offset Register 0
    union   SCIINTVECT1_REG                  SCIINTVECT1;                  // Interrupt Vector Offset Register 1
    union   SCIFORMAT_REG                    SCIFORMAT;                    // Length Control Register
    union   BRSR_REG                         BRSR;                         // Baud Rate Selection Register
    union   SCIED_REG                        SCIED;                        // Emulation buffer Register
    union   SCIRD_REG                        SCIRD;                        // Receiver data buffer Register
    union   SCITD_REG                        SCITD;                        // Transmit data buffer Register
    union   SCIPIO0_REG                      SCIPIO0;                      // Pin control Register 0
    uint32_t                                 rsvd1[2];                     // Reserved
    union   SCIPIO2_REG                      SCIPIO2;                      // Pin control Register 2
    uint32_t                                 rsvd2[12];                    // Reserved
    union   LINCOMP_REG                      LINCOMP;                      // Compare register
    union   LINRD0_REG                       LINRD0;                       // Receive data register 0
    union   LINRD1_REG                       LINRD1;                       // Receive data register 1
    union   LINMASK_REG                      LINMASK;                      // Acceptance mask register
    union   LINID_REG                        LINID;                        // LIN ID Register
    union   LINTD0_REG                       LINTD0;                       // Transmit Data Register 0
    union   LINTD1_REG                       LINTD1;                       // Transmit Data Register 1
    union   MBRSR_REG                        MBRSR;                        // Baud Rate Selection Register
    uint32_t                                 rsvd3[8];                     // Reserved
    union   IODFTCTRL_REG                    IODFTCTRL;                    // IODFT for LIN
    uint32_t                                 rsvd4[38];                    // Reserved
    union   LIN_GLB_INT_EN_REG               LIN_GLB_INT_EN;               // LIN Global Interrupt Enable Register
    union   LIN_GLB_INT_FLG_REG              LIN_GLB_INT_FLG;              // LIN Global Interrupt Flag Register
    union   LIN_GLB_INT_CLR_REG              LIN_GLB_INT_CLR;              // LIN Global Interrupt Clear Register
};

//---------------------------------------------------------------------------
// LIN External References & Function Declarations:
//
extern volatile struct LIN_REGS LinaRegs;
extern volatile struct LIN_REGS LinbRegs;
#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif

//===========================================================================
// End of file.
//===========================================================================
