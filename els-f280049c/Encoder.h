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


#ifndef __ENCODER_H
#define __ENCODER_H

#include "F28x_Project.h"
#include "Configuration.h"

#ifdef ENCODER_USE_EQEP1
#define ENCODER_REGS EQep1Regs
#endif
#ifdef ENCODER_USE_EQEP2
#define ENCODER_REGS EQep2Regs
#endif

// define _ENCODER_MAX_COUNT as a multiple of ENCODER_RESOLUTION so that the modulo function in getSPosition() overflows correctly (8,092 * 1,024)
#define _ENCODER_MAX_COUNT 0x7E7000


class Encoder
{
private:
    Uint32 previous;
    Uint16 rpm;
    Uint32 sposition;

public:
    Encoder( void );
    void initHardware( void );

    Uint16 getRPM( void );
    Uint16 getSPosition(void);
    Uint32 getPosition( void );
    Uint32 getMaxCount( void );
};


inline Uint32 Encoder :: getPosition(void)
{
    return ENCODER_REGS.QPOSCNT;
}

inline Uint32 Encoder :: getMaxCount(void)
{
    return _ENCODER_MAX_COUNT;
}



#endif // __ENCODER_H
