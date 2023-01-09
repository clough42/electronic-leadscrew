//###########################################################################
//
// FILE:   F2806x_Examples.h
//
// TITLE:  F2806x Device Definitions.
//
//###########################################################################
// $TI Release:  $
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

#ifndef F2806x_EXAMPLES_H
#define F2806x_EXAMPLES_H

#ifdef __cplusplus
extern "C" {
#endif

//
// Specify the PLL control register (PLLCR) and divide select (DIVSEL) value.
//

//#define DSP28_DIVSEL   0 // Enable /4 for SYSCLKOUT
//#define DSP28_DIVSEL   1 // Disable /4 for SYSCKOUT
#define DSP28_DIVSEL   2 // Enable /2 for SYSCLKOUT
//#define DSP28_DIVSEL   3 // Enable /1 for SYSCLKOUT

//
// Uncomment for 90 MHz devices [90 MHz = (10MHz * 18)/2]
//
#define DSP28_PLLCR   18
//#define DSP28_PLLCR   17
//#define DSP28_PLLCR   16
//#define DSP28_PLLCR   15
//#define DSP28_PLLCR   14
//#define DSP28_PLLCR   13
//#define DSP28_PLLCR   12
//#define DSP28_PLLCR   11
//#define DSP28_PLLCR   10
//#define DSP28_PLLCR    9
//#define DSP28_PLLCR    8
//#define DSP28_PLLCR    7
//#define DSP28_PLLCR    6
//#define DSP28_PLLCR    5
//#define DSP28_PLLCR    4
//#define DSP28_PLLCR    3
//#define DSP28_PLLCR    2
//#define DSP28_PLLCR    1
//#define DSP28_PLLCR    0  // PLL is bypassed in this mode

//
//    Specify the clock rate of the CPU (SYSCLKOUT) in nS.
//
//    Take into account the input clock frequency and the PLL multiplier
//    selected in step 1.
//
//    Use one of the values provided, or define your own.
//    The trailing L is required tells the compiler to treat
//    the number as a 64-bit value.
//
//    Only one statement should be uncommented.
//
//    Example:   90MHz devices:
//             CLKIN is a 10 MHz crystal or internal 10 MHz oscillator
//
//             In step 1 the user specified PLLCR = 0x18 for a
//             90 MHz CPU clock (SYSCLKOUT = 90 MHz).
//
//             In this case, the CPU_RATE will be 11.111L
//             Uncomment the line: #define CPU_RATE 11.111L
//

#define CPU_RATE   11.111L   // for a 90MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE   12.500L   // for a 80MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE   16.667L   // for a 60MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE   20.000L   // for a 50MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   25.000L   // for a 40MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   33.333L   // for a 30MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   41.667L   // for a 24MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   50.000L   // for a 20MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   66.667L   // for a 15MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE  100.000L   // for a 10MHz CPU clock speed  (SYSCLKOUT)

//
// PLL2 Defines:	PLL2 output is the USB0 and HRCAP1-4 clock
//

//
// Specify input clock source to PLL2
//
//#define PLL2_PLLSRC		0x0		// PLL2 Input Osc1
//#define PLL2_PLLSRC		0x1 	// PLL2 Input Osc1
#define PLL2_PLLSRC			0x2		// PLL2 Input X1
//#define PLL2_PLLSRC		0x3		// PLL2 Input XCLKIN

//
// Specify the PLL2 control register divide select (SYSCLK2DIV2DIS) 
// and (PLL2MULT) values.
//
#define PLL2_SYSCLK2DIV2DIS   	0 	// PLL2 Output /2
//#define PLL2_SYSCLK2DIV2DIS  	1 	// PLL2 Output /1

//#define PLL2_PLLMULT   	15
//#define PLL2_PLLMULT   	14
//#define PLL2_PLLMULT   	13
//#define PLL2_PLLMULT   	12
//#define PLL2_PLLMULT   	11
//#define PLL2_PLLMULT   	10
//#define PLL2_PLLMULT    	9
//#define PLL2_PLLMULT    	8
//#define PLL2_PLLMULT    	7
#define PLL2_PLLMULT    	6	// (CLKSOURCE*6) /2 = SYSCLKOUT2
//#define PLL2_PLLMULT    	5
//#define PLL2_PLLMULT    	4
//#define PLL2_PLLMULT    	3
//#define PLL2_PLLMULT    	2
//#define PLL2_PLLMULT    	1
//#define PLL2_PLLMULT    	0	// PLL is bypassed in this mode

//
// The following pointer to a function call calibrates the ADC and 
// internal oscillators
//
#define Device_cal (void   (*)(void))0x3D7C80

//
// Included Files
//

//
// Contains Prototypes for global functions within the .c files.
//
#include "F2806x_GlobalPrototypes.h"

#include "F2806x_EPwm_defines.h"             // Macros used for PWM examples.
#include "F2806x_I2c_defines.h"              // Macros used for I2C examples.
#include "F2806x_Dma_defines.h"              // Macros used for DMA examples.
#include "F2806x_Cla_defines.h"              // Macros used for CLA examples.

//
// Defines
//
#define   PARTNO_F28062PNT		0x64
#define	  PARTNO_F28062UPNT		0x65
#define   PARTNO_F28062PZT		0x66
#define	  PARTNO_F28062UPZT		0x67

#define   PARTNO_F28063PNT		0x68
#define	  PARTNO_F28063UPNT		0x69
#define   PARTNO_F28063PZT		0x6A
#define   PARTNO_F28063UPZT    	0x6B

#define   PARTNO_F28064PNT		0x6C
#define   PARTNO_F28064UPNT		0x6D
#define   PARTNO_F28064PZT		0x6E
#define   PARTNO_F28064UPZT     0x6F

#define   PARTNO_F28065PNT		0x7C
#define	  PARTNO_F28065UPNT		0x7D
#define   PARTNO_F28065PZT		0x7E
#define	  PARTNO_F28065UPZT		0x7F

#define	  PARTNO_F28PLC95PZT	0x80
#define   PARTNO_F28PLC93PNT	0x81
#define   PARTNO_F28PLC85PZT	0x82
#define   PARTNO_F28PLC83PNT	0x83

#define   PARTNO_F28066PNT		0x84
#define   PARTNO_F28066UPNT		0x85
#define   PARTNO_F28066PZT		0x86
#define	  PARTNO_F28066UPZT		0x87

#define   PARTNO_F28067PNT		0x88
#define	  PARTNO_F28067UPNT		0x89
#define   PARTNO_F28067PZT		0x8A
#define	  PARTNO_F28067UPZT		0x8B

#define   PARTNO_F28068PNT		0x8C
#define	  PARTNO_F28068UPNT		0x8D
#define   PARTNO_F28068PZT		0x8E
#define	  PARTNO_F28068UPZT		0x8F

#define   PARTNO_F28069PNT		0x9C
#define	  PARTNO_F28069UPNT		0x9D
#define   PARTNO_F28069PZT		0x9E
#define   PARTNO_F28069UPZT		0x9F

//
// Include files not used with DSP/BIOS
//
#ifndef DSP28_BIOS
#include "F2806x_DefaultISR.h"
#endif

//
// DO NOT MODIFY THIS LINE.
//
#define DELAY_US(A)  DSP28x_usDelay(((((long double) A * 1000.0L) /\
                     (long double)CPU_RATE) - 9.0L) / 5.0L)

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of F2806x_EXAMPLES_H definition

//
// End of file
//

