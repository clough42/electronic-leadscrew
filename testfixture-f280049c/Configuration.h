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
//================================================================================

// Steps and microsteps
#define STEPPER_MICROSTEPS 8
#define STEPPER_RESOLUTION 200

// Step, direction and enable pins are normally active-high
// #define INVERT_STEP_PIN true
// #define INVERT_DIRECTION_PIN true
// #define INVERT_ENABLE_PIN true
// #define INVERT_ALARM_PIN true

// Enable servo alarm feedback
#define USE_ALARM_PIN




//================================================================================
//                                 ENCODER
//
// Define the type of encoder you are using on the spindle.  The firmware assumes
// the encoder is turning at a 1:1 ratio with the spindle.
//================================================================================
#define ENCODER_RESOLUTION 4096




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
#define UI_REFRESH_RATE_HZ 20

// RPM recalculation rate, in Hz
#define RPM_CALC_RATE_HZ 10

// Microprocessor system clock
#define CPU_CLOCK_MHZ 100
#define CPU_CLOCK_HZ (CPU_CLOCK_MHZ * 1000000)


#endif // __CONFIGURATION_H
