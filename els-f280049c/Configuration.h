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


#ifndef __CONFIGURATION_H
#define __CONFIGURATION_H

#include "els.h"



//================================================================================
//                                  LEADSCREW
//
// Define the type and pitch of leadscrew you have in your lathe.  If you have an
// imperial leadscrew, define LEADSCREW_TPI.  If you have a metric leadscrew,
// define LEADSCREW_HMM (pitch in hundredths of a millimeter).  Do not define
// both.
//================================================================================

// For Imperial leadscrews: pitch in Threads Per Inch (TPI)
#define LEADSCREW_TPI 12

// For metric leadscrews: pitch in hundredths of a millimeter (HMM)
// Example: 200hmm = 2mm
//#define LEADSCREW_HMM 200




//================================================================================
//                                STEPPER/SERVO
//
// Define the number of steps and microsteps for your stepper motor, the pin
// polarity of the driver, and whether to use additional features, like servo
// alarm feedback.
//
// NOTE: If you are using a servo drive with something other than a 1:1 drive
// ratio, you can use the STEPPER_MICROSTEPS to compensate.  For example, if you
// have a servo configured for 1000 steps/revolution and it drives the leadscrew
// through a 3:1 reduction, you can set STEPPER_RESOLUTION to 1000 and
// STEPPER_MICROSTEPS to 3.
//================================================================================

// Steps and microsteps
#define STEPPER_MICROSTEPS 4      // 4:1 belt drive ratio
#define STEPPER_RESOLUTION 1600   // default resolution on our system

// Step, direction and enable pins are normally active-high
// #define INVERT_STEP_PIN true
#define INVERT_DIRECTION_PIN true
#define INVERT_ENABLE_PIN true
#define INVERT_ALARM_PIN true

// Enable servo alarm feedback
#define USE_ALARM_PIN




//================================================================================
//                                 ENCODER
//
// Define the type of encoder you are using on the spindle.  The firmware assumes
// the encoder is turning at a 1:1 ratio with the spindle.
//
// NOTE: the firmware is concerned with the quadrature edge count, which is
// four times the number of pulses.  For example, if you have a 1024 P/R
// encoder, you need to enter 4096 here.
//================================================================================

// Encoder resolution (counts per revolution)
#define ENCODER_RESOLUTION 1440 // 360 p/r

// Which encoder input to use
#define ENCODER_USE_EQEP1
//#define ENCODER_USE_EQEP2




//================================================================================
//                               CALCULATIONS
//
// Define how calculations should be performed.  Most users will not need to
// touch these settings.
//================================================================================

// Use floating-point math for gear ratios
#define USE_FLOATING_POINT




//================================================================================
//                                HARDWARE
//
// Define which hardware you're using:
//
//  1 - LaunchXL F280049C with ELS BoostXL v1
//  2 - LaunchXL F280049C with ELS BoostXL v2
//================================================================================

// See hardware version table above
#define HARDWARE_VERSION 2


//================================================================================
//                               CPU / TIMING
//
// Define the CPU clock, interrupt, and refresh timing.  Most users will not need
// to touch these settings.
//================================================================================

// Stepper state machine cycle time, in microseconds
// Two cycles are required per step
#define STEPPER_CYCLE_US 5

// User interface refresh rate, in Hertz
#define UI_REFRESH_RATE_HZ 100

// RPM recalculation rate, in Hz
#define RPM_CALC_RATE_HZ 10

// Microprocessor system clock
#define CPU_CLOCK_MHZ 100
#define CPU_CLOCK_HZ (CPU_CLOCK_MHZ * 1000000)

// Warning and shutoff levels for stepper speeds
#define STEPPER_WARNING_RPM 300
#define STEPPER_SHUTOFF_RPM 500

#endif // __CONFIGURATION_H
