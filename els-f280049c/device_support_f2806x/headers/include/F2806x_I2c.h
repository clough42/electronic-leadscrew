//###########################################################################
//
// FILE:   F2806x_I2c.h
//
// TITLE:  F2806x Device I2C Register Definitions.
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

#ifndef F2806x_I2C_H
#define F2806x_I2C_H

#ifdef __cplusplus
extern "C" {
#endif

//
// I2C Individual Register Bit Definitions
//
struct I2CMDR_BITS
{
    Uint16  BC:3;           // 2:0  Bit Count
    Uint16  FDF:1;          // 3    Free Data Format
    Uint16  STB:1;          // 4    START Byte Mode
    Uint16  IRS:1;          // 5    I2C Module Reset
    Uint16  DLB:1;          // 6    Digital Loopback Mode
    Uint16  RM:1;           // 7    Repeat Mode
    Uint16  XA:1;           // 8    Expanded Address Mode
    Uint16  TRX:1;          // 9    Transmitter Mode
    Uint16  MST:1;          // 10   Master Mode
    Uint16  STP:1;          // 11   STOP Condition
    Uint16  rsvd1:1;        // 12   Reserved
    Uint16  STT:1;          // 13   START Condition
    Uint16  FREE:1;         // 14   Debug Action
    Uint16  NACKMOD:1;      // 15   NACK Mode
};

union I2CMDR_REG
{
    Uint16 all;
    struct I2CMDR_BITS  bit;
};

struct I2CEMDR_BITS
{
    Uint16  BC:1;           // 0    Backward Compatability Mode
    Uint16  rsvd1:15;       // 15:1 Reserved
};

union I2CEMDR_REG
{
    Uint16 all;
    struct I2CEMDR_BITS bit;
};

struct I2CIER_BITS
{
    Uint16  ARBL:1;         // 0    Arbitration Lost
    Uint16  NACK:1;         // 1    No Acknowledgment
    Uint16  ARDY:1;         // 2    Register Access Ready
    Uint16  RRDY:1;         // 3    Receive Data Ready
    Uint16  XRDY:1;         // 4    Transmit Data Ready
    Uint16  SCD:1;          // 5    Stop Condition Detected
    Uint16  AAS:1;          // 6    Address as Slave
    Uint16  rsvd1:9;        // 15:7 Reserved
};

union I2CIER_REG
{
    Uint16 all;
    struct I2CIER_BITS  bit;
};

struct I2CSTR_BITS
{
    Uint16  ARBL:1;         // 0    Arbitration Lost
    Uint16  NACK:1;         // 1    No Acknowledgment
    Uint16  ARDY:1;         // 2    Register Access Ready
    Uint16  RRDY:1;         // 3    Receive Data Ready
    Uint16  XRDY:1;         // 4    Transmit Data Ready
    Uint16  SCD:1;          // 5    Stop Condition Detected
    Uint16  rsvd1:2;        // 7:6  Reserved
    Uint16  AD0:1;          // 8    Address 0
    Uint16  AAS:1;          // 9    Addressed as Slave
    Uint16  XSMT:1;         // 10   Transmit Shift Register Empty
    Uint16  RSFULL:1;       // 11   Receive Shift Register Full
    Uint16  BB:1;           // 12   Bus Busy
    Uint16  NACKSNT:1;      // 13   NACK Sent
    Uint16  SDIR:1;         // 14   Slave Direction
    Uint16  rsvd2:1;        // 15   Reserved
};

union I2CSTR_REG
{
    Uint16 all;
    struct I2CSTR_BITS  bit;
};

struct I2CISRC_BITS
{
    Uint16  INTCODE:3;          // 2:0  Interrupt Code
    Uint16  rsvd1:5;            // 7:3  Reserved
    Uint16  rsvd2:4;            // 11:8 Reserved
    Uint16  rsvd3:4;            // 15:12    Reserved
};

union I2CISRC_REG
{
    Uint16 all;
    struct I2CISRC_BITS bit;
};

struct I2CPSC_BITS
{
    Uint16  IPSC:8;         // 7:0  I2C Prescaler Divide Down
    Uint16  rsvd1:8;        // 15:8 Reserved
};

union I2CPSC_REG
{
    Uint16 all;
    struct I2CPSC_BITS  bit;
};

struct I2CFFTX_BITS
{
    Uint16  TXFFIL:5;           // 4:0  Transmit FIFO Interrupt Level
    Uint16  TXFFIENA:1;         // 5    Transmit FIFO Interrupt Enable
    Uint16  TXFFINTCLR:1;       // 6    Transmit FIFO Interrupt Flag Clear
    Uint16  TXFFINT:1;          // 7    Transmit FIFO Interrupt Flag Clear
    Uint16  TXFFST:5;           // 12:8 Transmit FIFO Status
    Uint16  TXFFRST:1;          // 13   Transmit FIFO Reset
    Uint16  I2CFFEN:1;          // 14   Transmit FIFO Enable
    Uint16  rsvd1:1;            // 15   Reserved
};

union I2CFFTX_REG
{
    Uint16 all;
    struct I2CFFTX_BITS bit;
};

struct I2CFFRX_BITS
{
    Uint16  RXFFIL:5;           // 4:0  Receive FIFO Interrupt Level
    Uint16  RXFFIENA:1;         // 5    Receive FIFO Interrupt Enable
    Uint16  RXFFINTCLR:1;       // 6    Receive FIFO Interrupt Flag Clear
    Uint16  RXFFINT:1;          // 7    Receive FIFO Interrupt Flag Clear
    Uint16  RXFFST:5;           // 12:8 Receive FIFO Status
    Uint16  RXFFRST:1;          // 13   Receive FIFO Reset
    Uint16  rsvd1:2;            // 15:14    Reserved
};

union I2CFFRX_REG
{
    Uint16 all;
    struct I2CFFRX_BITS bit;
};

struct I2C_REGS
{
    Uint16              I2COAR;     // I2C Own address
    union   I2CIER_REG  I2CIER;     // I2C Interrupt Enable
    union   I2CSTR_REG  I2CSTR;     // I2C Status
    Uint16              I2CCLKL;    // I2C Clock low-time divider
    Uint16              I2CCLKH;    // I2C Clock high-time divider
    Uint16              I2CCNT;     // I2C Data count
    Uint16              I2CDRR;     // I2C Data receive
    Uint16              I2CSAR;     // I2C Slave address
    Uint16              I2CDXR;     // I2C Data Transmit
    union   I2CMDR_REG  I2CMDR;     // I2C Mode
    union   I2CISRC_REG I2CISRC;    // I2C Interrupt Source
    union   I2CEMDR_REG I2CEMDR;    // I2C Extended Mode
    union   I2CPSC_REG  I2CPSC;     // I2C Prescaler
    Uint16              rsvd1[19];  // Reserved
    union   I2CFFTX_REG I2CFFTX;    // I2C FIFO Transmit
    union   I2CFFRX_REG I2CFFRX;    // I2C FIFO Receive
};

//
// I2c External References & Function Declarations:
//
extern volatile struct I2C_REGS I2caRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of F2806x_I2C_H definition

//
// End of file
//

