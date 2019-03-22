#ifndef __STEPPERDRIVE_H
#define __STEPPERDRIVE_H

#include "DSP28x_Project.h"

#define STEPPER_CYCLE_US 50

struct STEPPERDRIVE_STATE {
    int32 currentPosition;
    int32 desiredPosition;
    //
    // 0 = disabled; no stepping
    // 1 = enabled; active
    //
    Uint16 enabled;

    //
    // current state-machine state
    // bit 0 - step signal
    // bit 1 - direction signal
    //
    Uint16 state;
};

extern struct STEPPERDRIVE_STATE _stepperdrive_state;


void StepperDrive_Init(void);
void StepperDrive_Service_ISR(void);


inline void StepperDrive_Start(void)
{
    _stepperdrive_state.enabled = 1;
}

inline void StepperDrive_Stop(void)
{
    _stepperdrive_state.enabled = 0;
}

inline void StepperDrive_SetDesiredPosition(int32 steps)
{
    _stepperdrive_state.desiredPosition = steps;
}


#endif // __STEPPERDRIVE_H
