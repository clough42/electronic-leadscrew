//###########################################################################
//
// FILE:   F28004x_device.h
//
// TITLE:  F28004x Device Definitions.
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

#ifndef F28004X_DEVICE_H
#define F28004X_DEVICE_H

#ifdef __cplusplus
extern "C" {
#endif

//
// Common CPU Definitions:
//
#ifdef __TMS320C28XX_CLA__
//
// There are only two assembly instructions that can access the MSTF register
// - MMOV32 mem32, MSTF
// - MMOV32 mem32, MSTF
// The CLA C compiler allows 'C' access to this control register through the __cregister
// keyword. In order to access the register's contents, the user must copy it to the
// shadow object defined below
// Note that _MSTF is the only __cregister recognized by the CLA C compiler; IER and IFR
// are not accessible (therefore not recognized), therefore __cregister must be redefined to
// null to prevent a cla C compiler error
//
struct MSTF_SHADOW_BITS {     // bits description
    unsigned short LVF:1;     // 0    Latched Overflow Flag
    unsigned short LUF:1;     // 1    Latched Underflow Flag
    unsigned short NF:1;      // 2    Negative Float Flag
    unsigned short ZF:1;      // 3    Zero Float Flag
    unsigned short rsvd1:2;   // 5:4  Reserved
    unsigned short TF:1;      // 6    Test Flag
    unsigned short rsvd2:2;   // 8:7  Reserved
    unsigned short RNDF32:1;  // 9    Rounding Mode
    unsigned short rsvd3:1;   // 10   Reserved
    unsigned short MEALLOW:1; // 11   MEALLOW Status
    unsigned short RPCL:4;    // 15:12    Return PC: Low Portion
    unsigned short RPCH:12;   // 27:16    Return PC: High Portion
    unsigned short rsvd4:4;   // 31:28    Reserved
};
extern __cregister volatile unsigned int MSTF;
#endif //__TMS320C28XX_CLA__

#ifndef __TMS320C28XX__
#define __cregister
#endif  //__TMS320C28xx__

extern __cregister volatile unsigned int IFR;
extern __cregister volatile unsigned int IER;

#define  EINT   __asm(" clrc INTM")
#define  DINT   __asm(" setc INTM")
#define  ERTM   __asm(" clrc DBGM")
#define  DRTM   __asm(" setc DBGM")
#define  EALLOW __eallow()
#define  EDIS   __edis()
#define  ESTOP0 __asm(" ESTOP0")

#define M_INT1  0x0001
#define M_INT2  0x0002
#define M_INT3  0x0004
#define M_INT4  0x0008
#define M_INT5  0x0010
#define M_INT6  0x0020
#define M_INT7  0x0040
#define M_INT8  0x0080
#define M_INT9  0x0100
#define M_INT10 0x0200
#define M_INT11 0x0400
#define M_INT12 0x0800
#define M_INT13 0x1000
#define M_INT14 0x2000
#define M_DLOG  0x4000
#define M_RTOS  0x8000

#define BIT0    0x00000001
#define BIT1    0x00000002
#define BIT2    0x00000004
#define BIT3    0x00000008
#define BIT4    0x00000010
#define BIT5    0x00000020
#define BIT6    0x00000040
#define BIT7    0x00000080
#define BIT8    0x00000100
#define BIT9    0x00000200
#define BIT10   0x00000400
#define BIT11   0x00000800
#define BIT12   0x00001000
#define BIT13   0x00002000
#define BIT14   0x00004000
#define BIT15   0x00008000
#define BIT16   0x00010000
#define BIT17   0x00020000
#define BIT18   0x00040000
#define BIT19   0x00080000
#define BIT20   0x00100000
#define BIT21   0x00200000
#define BIT22   0x00400000
#define BIT23   0x00800000
#define BIT24   0x01000000
#define BIT25   0x02000000
#define BIT26   0x04000000
#define BIT27   0x08000000
#define BIT28   0x10000000
#define BIT29   0x20000000
#define BIT30   0x40000000
#define BIT31   0x80000000

//
// For Portability, User Is Recommended To Use the C99 Standard integer types
//
#if !defined(__TMS320C28XX_CLA__)
#include <assert.h>
#include <stdarg.h>
#endif //__TMS320C28XX_CLA__
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

//
// C99 defines boolean type to be _Bool, but this doesn't match the format of
// the other standard integer types.  bool_t has been defined to fill this gap.
//
typedef _Bool bool_t;

//
// Used for a bool function return status
//
typedef _Bool status_t;

#ifndef SUCCESS
#define SUCCESS     true
#endif

#ifndef FAIL
#define FAIL        false
#endif

//
// The following data types are included for compatibility with legacy code,
// they are not recommended for use in new software.  Please use the C99
// types included above
//
#if (!defined(DSP28_DATA_TYPES) && !defined(F28_DATA_TYPES))
#define DSP28_DATA_TYPES
#define F28_DATA_TYPES

#ifdef __TMS320C28XX_CLA__
typedef short                                   int16;
typedef long                                    int32;
typedef unsigned char                           Uint8;
typedef unsigned short                          Uint16;
typedef unsigned long                           Uint32;
typedef float                                   float32;
typedef long double                             float64;
typedef struct { Uint32 low32; Uint32 high32; } Uint64;
typedef struct { int32  low32; int32  high32; } int64;
#else // __TMS320C28XX__
typedef int                                     int16;
typedef long                                    int32;
typedef long long                               int64;
typedef unsigned int                            Uint16;
typedef unsigned long                           Uint32;
typedef unsigned long long                      Uint64;
typedef float                                   float32;
typedef long double                             float64;
#endif //__TMS320C28XX_CLA__

#endif //(!defined(DSP28_DATA_TYPES) && !defined(F28_DATA_TYPES))

//
// The following data types are for use with byte addressable peripherals.
// See compiler documentation on the byte_peripheral type attribute.
//
#ifndef __TMS320C28XX_CLA__
typedef unsigned int bp_16 __attribute__((byte_peripheral));
typedef unsigned long bp_32 __attribute__((byte_peripheral));
#endif

//
// Include All Peripheral Header Files:
//
#include "f28004x_adc.h"
#include "f28004x_analogsubsys.h"
#include "f28004x_cla.h"
#include "f28004x_cla_prom_crc32.h"
#include "f28004x_cmpss.h"
#include "f28004x_cputimer.h"
#include "f28004x_dac.h"
#include "f28004x_dcsm.h"
#include "f28004x_dma.h"
#include "f28004x_ecap.h"
#include "f28004x_epwm.h"
#include "f28004x_epwm_xbar.h"
#include "f28004x_eqep.h"
#include "f28004x_erad.h"
#include "f28004x_flash.h"
#include "f28004x_fsi.h"
#include "f28004x_gpio.h"
#include "f28004x_i2c.h"
#include "f28004x_input_xbar.h"
#include "f28004x_memconfig.h"
#include "f28004x_nmiintrupt.h"
#include "f28004x_output_xbar.h"
#include "f28004x_pga.h"
#include "f28004x_piectrl.h"
#include "f28004x_pievect.h"
#include "f28004x_pmbus.h"
#include "f28004x_sci.h"
#include "f28004x_sdfm.h"
#include "f28004x_spi.h"
#include "f28004x_sysctrl.h"
#include "f28004x_xbar.h"
#include "f28004x_xint.h"

//
// byte_peripheral attribute is only supported on the C28
//
#ifndef __TMS320C28XX_CLA__
#include "f28004x_can.h"
#include "f28004x_dcc.h"
#include "f28004x_lin.h"
#endif

#ifdef __cplusplus
}
#endif                                  /* extern "C" */

#endif                                  // end of F28004X_DEVICE_H definition

//===========================================================================
// End of file.
//===========================================================================
