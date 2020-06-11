// Electronic Leadscrew
// https://github.com/alexphredorg/electronic-leadscrew
//
// Copyright (c) 2020 Alex Wetmore
//
// Derived from:
// Clough42 Electronic Leadscrew
// https://github.com/clough42/electronic-leadscrew
//
// MIT License
//
// Copyright (c) 2019 James Clough
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef ELS_H_
#define ELS_H_

// Non-standard data types used heavily in the clough42 derived code
#if (!defined(F28_DATA_TYPES) && !defined(DSP28_DATA_TYPES))
#define F28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef short                                   int16;
typedef long                                    int32;
typedef unsigned char                           Uint8;
typedef unsigned short                          Uint16;
typedef unsigned long                           Uint32;
typedef float                                   float32;
typedef long double                             float64;
typedef struct { Uint32 low32; Uint32 high32; } Uint64;
typedef struct { int32  low32; int32  high32; } int64;
#else
#error f28004x_Cla_Typedefs.h must be included before f28004x_Device.h or any other header \
file that redefines data types using the guard macros F28_DATA_TYPES or DSP28_DATA_TYPES
#endif //(!defined(F28_DATA_TYPES) && !defined(DSP28_DATA_TYPES))

// helper functions for int to text
void reverse(char *str, int n);
void itoa(int num, char* str, int base);
char hexDigit(unsigned n);
char *charToHex(unsigned char ch, char *string);

// All project headers
#include <stdlib.h>
#include <string.h>
#include "driverlib.h"
#include "device.h"
#include "Configuration.h"
#include "EEPROM.h"
#include "StepperDrive.h"
#include "Encoder.h"
#include "SerialPort.h"
#include "Tables.h"
#include "IUserInterface.h"
#include "NextionControlPanel.h"
#include "Core.h"
#include "UserInterface.h"
#include "Debug.h"

#endif /* ELS_H_ */
