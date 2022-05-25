//###########################################################################
//
// FILE:   F2806x_Dma_defines.h
//
// TITLE:  #defines used in DMA examples
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

#ifndef F2806x_DMA_DEFINES_H
#define F2806x_DMA_DEFINES_H


#ifdef __cplusplus
extern "C" {
#endif

//
// Defines
//
// MODE
//
// PERINTSEL bits
#define DMA_SEQ1INT 	1
#define DMA_SEQ2INT 	2
#define DMA_XINT1   	3
#define DMA_XINT2   	4
#define DMA_XINT3   	5
#define DMA_USB0EP1RX	7
#define DMA_USB0EP1TX	8
#define DMA_USB0EP2RX	9
#define DMA_USB0EP2TX	10
#define DMA_TINT0   	11
#define DMA_TINT1   	12
#define DMA_TINT2   	13
#define DMA_MXEVTA  	14
#define DMA_MREVTA  	15
#define DMA_EPWM2A  	18
#define DMA_EPWM2B  	19
#define DMA_EPWM3A  	20
#define DMA_EPWM3B  	21
#define DMA_EPWM4A  	22
#define DMA_EPWM4B  	23
#define DMA_EPWM5A  	24
#define DMA_EPWM5B  	25
#define DMA_EPWM6A  	26
#define DMA_EPWM6B  	27
#define DMA_EPWM7A  	28
#define DMA_EPWM7B  	29
#define DMA_USB0EP3RX	30
#define DMA_USB0EP3TX	31

//
// OVERINTE bit
//
#define OVRFLOW_DISABLE 0x0
#define OVEFLOW_ENABLE  0x1

//
// PERINTE bit
//
#define PERINT_DISABLE  0x0
#define PERINT_ENABLE   0x1

//
// CHINTMODE bits
//
#define CHINT_BEGIN     0x0
#define CHINT_END       0x1

//
// ONESHOT bits
//
#define ONESHOT_DISABLE 0x0
#define ONESHOT_ENABLE  0x1

//
// CONTINOUS bit
//
#define CONT_DISABLE    0x0
#define CONT_ENABLE     0x1

//
// SYNCE bit
//
#define SYNC_DISABLE    0x0
#define SYNC_ENABLE     0x1

//
// SYNCSEL bit
//
#define SYNC_SRC        0x0
#define SYNC_DST        0x1

//
// DATASIZE bit
//
#define SIXTEEN_BIT     0x0
#define THIRTYTWO_BIT   0x1

//
// CHINTE bit
//
#define CHINT_DISABLE   0x0
#define CHINT_ENABLE    0x1

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of F2806x_DMA_DEFINES_H

//
// End of file
//

