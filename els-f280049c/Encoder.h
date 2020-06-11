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

#ifndef __ENCODER_H
#define __ENCODER_H

#include "eqep.h"

#define _ENCODER_MAX_COUNT 0x00ffffff


class Encoder
{
private:
    Uint32 previous;
    Uint16 rpm;

public:
    Encoder( void );
    void initHardware( void );

    Uint16 getRPM( void );
    Uint32 getPosition( void );
    Uint32 getMaxCount( void );

    Uint32 base;
};

inline Uint32 Encoder :: getPosition(void)
{
    return EQEP_getPosition(this->base);
    //return ENCODER_REGS.QPOSCNT;
}

inline Uint32 Encoder :: getMaxCount(void)
{
    return _ENCODER_MAX_COUNT;
}

#endif // __ENCODER_H
