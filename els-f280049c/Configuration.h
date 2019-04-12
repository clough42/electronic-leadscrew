#ifndef __CONFIGURATION_H
#define __CONFIGURATION_H

#ifdef __cplusplus
extern "C" {
#endif

//
// Stepper cycle servicing time, in microseconds
// Two cycles are required to complete one pulse
//
#define STEPPER_CYCLE_US 25

//
// RPM recalculation rate, in Hz
// This must be slow enough to get enough pulses from the
// encoder for the desired resolution, but fast enough to
// feel responsive to the user.
//
#define RPM_CALC_RATE_HZ 10

//
// Microprocessor system clock
// This is used to set up the eQEP timers for RPM
// calculations.
//
#define CPU_CLOCK_MHZ 100
#define CPU_CLOCK_HZ (CPU_CLOCK_MHZ * 1000000)

#ifdef __cplusplus
}
#endif

#endif // __CONFIGURATION_H
