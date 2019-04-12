#ifndef __STEPPERDRIVE_H
#define __STEPPERDRIVE_H

#include "F28x_Project.h"


#define STEP_PIN GPIO0
#define DIR_PIN GPIO1
#define ISR_PIN GPIO6

#define GPIO_SET(pin) GpioDataRegs.GPASET.bit.pin = 1
#define GPIO_CLEAR(pin) GpioDataRegs.GPACLEAR.bit.pin = 1


class StepperDrive
{
private:
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

public:
    StepperDrive();

    void init(void);
    void setDesiredPosition(int32 steps);
    void incrementCurrentPosition(int32 increment);
    void setCurrentPosition(int32 position);

    void ISR(void);
};

inline void StepperDrive :: setDesiredPosition(int32 steps)
{
    this->desiredPosition = steps;
}

inline void StepperDrive :: incrementCurrentPosition(int32 increment)
{
    this->currentPosition += increment;
}

inline void StepperDrive :: setCurrentPosition(int32 position)
{
    this->currentPosition = position;
}


inline void StepperDrive :: ISR(void)
{
    switch( this->state ) {

    case 0:
        // Step = 0; Dir = 0
        if( this->desiredPosition < this->currentPosition ) {
            GPIO_SET(STEP_PIN);
            this->state = 2;
        }
        else if( this->desiredPosition > this->currentPosition ) {
            GPIO_SET(DIR_PIN);
            this->state = 1;
        }
        break;

    case 1:
        // Step = 0; Dir = 1
        if( this->desiredPosition > this->currentPosition ) {
            GPIO_SET(STEP_PIN);
            this->state = 3;
        }
        else if( this->desiredPosition < this->currentPosition ) {
            GPIO_CLEAR(DIR_PIN);
            this->state = 0;
        }
        break;

    case 2:
        // Step = 1; Dir = 0
        GPIO_CLEAR(STEP_PIN);
        this->currentPosition--;
        this->state = 0;
        break;

    case 3:
        // Step = 1; Dir = 1
        GPIO_CLEAR(STEP_PIN);
        this->currentPosition++;
        this->state = 1;
        break;
    }
}

#endif // __STEPPERDRIVE_H
