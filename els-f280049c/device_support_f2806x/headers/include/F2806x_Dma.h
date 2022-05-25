//###########################################################################
//
// FILE:   F2806x_Dma.h
//
// TITLE:  F2806x Device DMA Register Definitions.
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

#ifndef F2806x_DMA_H
#define F2806x_DMA_H

#ifdef __cplusplus
extern "C" {
#endif

//
// DMA Individual Register Bit Definitions:
//
struct MODE_BITS
{
    Uint16  PERINTSEL:5;        // 4:0  Peripheral Interrupt and Sync Select
    Uint16  rsvd1:2;            // 6:5  Reserved
    Uint16  OVRINTE:1;          // 7    Overflow Interrupt Enable
    Uint16  PERINTE:1;          // 8    Peripheral Interrupt Enable
    Uint16  CHINTMODE:1;        // 9    Channel Interrupt Mode
    Uint16  ONESHOT:1;          // 10   One Shot Mode Bit
    Uint16  CONTINUOUS:1;       // 11   Continuous Mode Bit
    Uint16  rsvd2:2;            // 13:12    Reserved
    Uint16  DATASIZE:1;         // 14   Data Size Mode Bit
    Uint16  CHINTE:1;           // 15   Channel Interrupt Enable Bit
};

union MODE_REG
{
    Uint16 all;
    struct MODE_BITS    bit;
};

struct CONTROL_BITS
{
    Uint16  RUN:1;          // 0    Run Bit
    Uint16  HALT:1;         // 1    Halt Bit
    Uint16  SOFTRESET:1;    // 2    Soft Reset Bit
    Uint16  PERINTFRC:1;    // 3    Interrupt Force Bit
    Uint16  PERINTCLR:1;    // 4    Interrupt Clear Bit
    Uint16  rsvd2:2;        // 6:5  Reserved
    Uint16  ERRCLR:1;       // 7    Error Clear Bit
    Uint16  PERINTFLG:1;    // 8    Interrupt Flag Bit
    Uint16  SYNCFLG:1;      // 9    Sync Flag Bit
    Uint16  SYNCERR:1;      // 10   Sync Error Flag Bit
    Uint16  TRANSFERSTS:1;  // 11   Transfer Status Bit
    Uint16  BURSTSTS:1;     // 12   Burst Status Bit
    Uint16  RUNSTS:1;       // 13   Run Status Bit
    Uint16  OVRFLG:1;       // 14   Overflow Flag Bit
    Uint16  rsvd1:1;        // 15   Reserved
};

union CONTROL_REG
{
    Uint16 all;
    struct CONTROL_BITS bit;
};

struct DMACTRL_BITS
{
    Uint16  HARDRESET:1;            // 0    Hard Reset Bit
    Uint16  PRIORITYRESET:1;        // 1    Priority Reset Bit
    Uint16  rsvd1:14;               // 15:2 Reserved
};

union DMACTRL_REG
{
    Uint16 all;
    struct DMACTRL_BITS bit;
};

struct DEBUGCTRL_BITS
{
    Uint16  rsvd1:15;       // 14:0 Reserved
    Uint16  FREE:1;         // 15   Debug Mode Bit
};

union DEBUGCTRL_REG
{
    Uint16 all;
    struct DEBUGCTRL_BITS   bit;
};

struct PRIORITYCTRL1_BITS
{
    Uint16  CH1PRIORITY:1;      // 0    Ch1 Priority Bit
    Uint16  rsvd1:15;           // 15:1 Reserved
};

union PRIORITYCTRL1_REG
{
    Uint16 all;
    struct PRIORITYCTRL1_BITS   bit;
};

struct PRIORITYSTAT_BITS
{
    Uint16  ACTIVESTS:3;        // 2:0  Active Channel Status Bits
    Uint16  rsvd1:1;            // 3    Reserved
    Uint16  ACTIVESTS_SHADOW:3; // 6:4  Active Channel Status Shadow Bits
    Uint16  rsvd2:9;            // 15:7 Reserved
};

union PRIORITYSTAT_REG
{
    Uint16 all;
    struct PRIORITYSTAT_BITS    bit;
};

struct BURST_SIZE_BITS
{
    Uint16  BURSTSIZE:5;        // 4:0  Burst Transfer Size
    Uint16  rsvd1:11;           // 15:5 Reserved
};

union BURST_SIZE_REG
{
    Uint16 all;
    struct BURST_SIZE_BITS  bit;
};

struct BURST_COUNT_BITS
{
    Uint16  BURSTCOUNT:5;       // 4:0  Burst Transfer Count
    Uint16  rsvd1:11;           // 15:5 Reserved
};

union BURST_COUNT_REG
{
    Uint16 all;
    struct BURST_COUNT_BITS bit;
};

struct CH_REGS
{
    union   MODE_REG        MODE;                   // Mode Register
    union   CONTROL_REG     CONTROL;                // Control Register
    union   BURST_SIZE_REG  BURST_SIZE;             // Burst Size Register
    union   BURST_COUNT_REG BURST_COUNT;            // Burst Count Register
    
    //
    // Source Burst Step Register
    //
    int16                   SRC_BURST_STEP;         
    
    //
    // Destination Burst Step Register
    //
    int16                   DST_BURST_STEP;         
    
    Uint16                  TRANSFER_SIZE;          // Transfer Size Register
    Uint16                  TRANSFER_COUNT;         // Transfer Count Register
    
    //
    // Source Transfer Step Register
    //
    int16                   SRC_TRANSFER_STEP;      
    
    //
    // Destination Transfer Step Register
    //
    int16                   DST_TRANSFER_STEP;      
    
    Uint16                  SRC_WRAP_SIZE;    // Source Wrap Size Register
    Uint16                  SRC_WRAP_COUNT;   // Source Wrap Count Register
    int16                   SRC_WRAP_STEP;    // Source Wrap Step Register
    Uint16                  DST_WRAP_SIZE;    // Destination Wrap Size Register
    Uint16                  DST_WRAP_COUNT;   // Destination Wrap Count Register
    int16                   DST_WRAP_STEP;    // Destination Wrap Step Register
    
    //
    // Source Begin Address Shadow Register
    //
    Uint32                  SRC_BEG_ADDR_SHADOW;    
    
    //
    // Source Address Shadow Register
    //
    Uint32                  SRC_ADDR_SHADOW;        
    
    //
    // Source Begin Address Active Register
    //
    Uint32                  SRC_BEG_ADDR_ACTIVE;    
    
    //
    // Source Address Active Register
    //
    Uint32                  SRC_ADDR_ACTIVE;        
    
    //
    // Destination Begin Address Shadow Register
    //
    Uint32                  DST_BEG_ADDR_SHADOW;    
    
    //
    // Destination Address Shadow Register
    //
    Uint32                  DST_ADDR_SHADOW;        
    
    //
    // Destination Begin Address Active Register
    //
    Uint32                  DST_BEG_ADDR_ACTIVE;    
    
    //
    // Destination Address Active Registers
    //
    Uint32                  DST_ADDR_ACTIVE;        
};

struct DMA_REGS
{
    union   DMACTRL_REG         DMACTRL;        // DMA Control Register
    union   DEBUGCTRL_REG       DEBUGCTRL;      // Debug Control Register
    Uint16                      rsvd0;          // Reserved
    Uint16                      rsvd1;          // Reserved
    union   PRIORITYCTRL1_REG   PRIORITYCTRL1;  // Priority Control 1 Register
    Uint16                      rsvd2;          // Reserved
    union   PRIORITYSTAT_REG    PRIORITYSTAT;   // Priority Status Register
    Uint16                      rsvd3[25];      // Reserved
    struct CH_REGS              CH1;            // DMA Channel 1 Registers
    struct CH_REGS              CH2;            // DMA Channel 2 Registers
    struct CH_REGS              CH3;            // DMA Channel 3 Registers
    struct CH_REGS              CH4;            // DMA Channel 4 Registers
    struct CH_REGS              CH5;            // DMA Channel 5 Registers
    struct CH_REGS              CH6;            // DMA Channel 6 Registers
};

//
// Dma External References & Function Declarations:
//
extern volatile struct DMA_REGS DmaRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of F2806x_DMA_H definition

//
// End of file
//

