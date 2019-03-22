#ifndef __STEPPERDRIVE_H
#define __STEPPERDRIVE_H

#include "DSP28x_Project.h"

#define STEPPER_CYCLE_US 50

struct STEPPERDRIVE_STATE {

    //
    // Current position of the motor, in steps
    //
    int32 currentPosition;

    //
    // Desired position of the motor, in steps
    //
    int32 desiredPosition;

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


inline void StepperDrive_SetDesiredPosition(int32 steps)
{
    _stepperdrive_state.desiredPosition = steps;
}


#endif // __STEPPERDRIVE_H
