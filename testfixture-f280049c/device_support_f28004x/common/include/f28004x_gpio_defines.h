//###########################################################################
//
// FILE:    f28004x_gpio_defines.h
//
// TITLE:   f28004x GPIO support definitions
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

#ifndef F28004x_GPIO_DEFINES_H
#define F28004x_GPIO_DEFINES_H

//
// Defines
//

//
// CPU pin masters for GPIO_SelectPinMux()
//
#define GPIO_MUX_CPU1       0x0
#define GPIO_MUX_CPU1CLA    0x1

//
// Flags for GPIO_SetupPinOptions(). The qualification flags (SYNC, QUAL3,
// QUAL6, and ASYNC) take up two bits and must be in the order specified.
//
#define GPIO_INPUT      0
#define GPIO_OUTPUT     1
#define GPIO_PUSHPULL   0
#define GPIO_PULLUP     (1 << 0)
#define GPIO_INVERT     (1 << 1)
#define GPIO_OPENDRAIN  (1 << 2)
#define GPIO_SYNC       (0x0 << 4)
#define GPIO_QUAL3      (0x1 << 4)
#define GPIO_QUAL6      (0x2 << 4)
#define GPIO_ASYNC      (0x3 << 4)

//
// Flags for GPIO_SetupLock().
//
#define GPIO_UNLOCK     0
#define GPIO_LOCK       1

//
// Helpful constants for array-based access to GPIO registers
//
#define GPY_CTRL_OFFSET (0x40/2)
#define GPY_DATA_OFFSET (0x8/2)

#define GPYQSEL     (0x2/2)
#define GPYMUX      (0x6/2)
#define GPYDIR      (0xA/2)
#define GPYPUD      (0xC/2)
#define GPYINV      (0x10/2)
#define GPYODR      (0x12/2)
#define GPYGMUX     (0x20/2)
#define GPYCSEL     (0x28/2)
#define GPYLOCK     (0x3C/2)
#define GPYCR       (0x3E/2)

#define GPYDAT      (0x0/2)
#define GPYSET      (0x2/2)
#define GPYCLEAR    (0x4/2)
#define GPYTOGGLE   (0x6/2)

#endif  // end of F28004x_GPIO_DEFINES_H definition

//
// End of file
//


