#include "StepperDrive.h"


struct STEPPERDRIVE_STATE _stepperdrive_state;

#define DESIRED _stepperdrive_state.desiredPosition
#define CURRENT _stepperdrive_state.currentPosition
#define STEP_PIN GPIO0
#define DIR_PIN GPIO1
#define ISR_PIN GPIO6

#define GPIO_SET(pin) GpioDataRegs.GPASET.bit.pin = 1
#define GPIO_CLEAR(pin) GpioDataRegs.GPACLEAR.bit.pin = 1


void StepperDrive_Init(void)
{
    //
    // Set up global state variables
    //
    _stepperdrive_state.currentPosition = 0;
    _stepperdrive_state.desiredPosition = 0;

    //
    // Configure GPIO pins for output
    // GPIO0 = Step
    // GPIO1 = Direction
    // GPIO6 - Enable
    //
    EALLOW;
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0;
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 0;

    GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO1 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO6 = 1;

    GpioDataRegs.GPACLEAR.bit.GPIO0 = 1; // step active-high
    GpioDataRegs.GPACLEAR.bit.GPIO1 = 1; // direction active high
    GpioDataRegs.GPACLEAR.bit.GPIO6 = 1; // enable active low
    EDIS;

    //
    // State machine starts at state zero
    //
    _stepperdrive_state.state = 0;
}

void StepperDrive_Service_ISR(void)
{
    switch( _stepperdrive_state.state ) {

    case 0:
        // Step = 0; Dir = 0
        if( DESIRED < CURRENT ) {
            GPIO_SET(STEP_PIN);
            _stepperdrive_state.state = 2;
        }
        else if( DESIRED > CURRENT ) {
            GPIO_SET(DIR_PIN);
            _stepperdrive_state.state = 1;
        }
        break;

    case 1:
        // Step = 0; Dir = 1
        if( DESIRED > CURRENT ) {
            GPIO_SET(STEP_PIN);
            _stepperdrive_state.state = 3;
        }
        else if( DESIRED < CURRENT ) {
            GPIO_CLEAR(DIR_PIN);
            _stepperdrive_state.state = 0;
        }
        break;

    case 2:
        // Step = 1; Dir = 0
        GPIO_CLEAR(STEP_PIN);
        CURRENT--;
        _stepperdrive_state.state = 0;
        break;

    case 3:
        // Step = 1; Dir = 1
        GPIO_CLEAR(STEP_PIN);
        CURRENT++;
        _stepperdrive_state.state = 1;
        break;
    }
}





