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

#ifndef __SANITYCHECK_H
#define __SANITYCHECK_H

// Sanity checks to check for common configuration errors

#if STEPPER_CYCLE_US < 5 || STEPPER_CYCLE_US > 100
#error STEPPER_CYCLE_US must be between 5ms and 100ms
#endif

#if UI_REFRESH_RATE_HZ < 3 || UI_REFRESH_RATE_HZ > 100
#error UI_REFRESH_RATE_HZ must be between 1Hz and 100Hz
#endif

#if RPM_CALC_RATE_HZ < 1 || RPM_CALC_RATE_HZ > 10
#error RPM_CALC_RATE_HZ must be between 1Hz and 10Hz
#endif

#if CPU_CLOCK_HZ < 1000000 || CPU_CLOCK_HZ > 500000000
#error CPU_CLOCK_HZ must be between 1MHz and 500MHz
#endif

#if STEPPER_MICROSTEPS < 1 || STEPPER_MICROSTEPS > 256
#error STEPPER_MICROSTEPS must be between 1 and 256
#endif

#if STEPPER_RESOLUTION < 1 || STEPPER_RESOLUTION > 2000
#error STEPPER_RESOLUTION must be between 100 and 2000
#endif

#if ENCODER_RESOLUTION < 100 || ENCODER_RESOLUTION > 10000
#error ENCODER_RESOLUTION must be between 100 and 10000
#endif

#if defined(LEADSCREW_TPI) && defined(LEADSCREW_HMM)
#error LEADSCREW_TPI and LEADSCREW_HMM may not both be defined.  Choose only one.
#endif

#if defined(LEADSCREW_TPI)
#if LEADSCREW_TPI < 4 || LEADSCREW_TPI > 40
#error LEADSCREW_TPI must be between 4 and 40
#endif
#endif

#if defined(LEADSCREW_HMM)
#if LEADSCREW_HMM < 50 || LEADSCREW_HMM > 700
#error LEADSCREW_HMM must be between 50 (0.5mm) and 700 (7mm)
#endif
#endif

#if defined(ENCODER_USE_EQEP1) && defined (ENCODER_USE_EQEP2)
#error Define only one of ENCODER_USE_EQEP1 or ENCODER_USE_EQEP2
#endif



#endif // __SANITYCHECK_H
