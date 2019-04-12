#include "StepperDrive.h"





StepperDrive :: StepperDrive(void)
{

}

void StepperDrive :: init(void)
{
    //
    // Set up global state variables
    //
    this->currentPosition = 0;
    this->desiredPosition = 0;

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
    this->state = 0;
}






