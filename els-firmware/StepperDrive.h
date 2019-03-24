#ifndef __STEPPERDRIVE_H
#define __STEPPERDRIVE_H

#include "DSP28x_Project.h"



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

inline void StepperDrive_IncrementCurrentPosition(int32 increment)
{
    _stepperdrive_state.currentPosition += increment;
}

inline void StepperDrive_SetCurrentPosition(int32 position)
{
    _stepperdrive_state.currentPosition = position;
}


#endif // __STEPPERDRIVE_H
