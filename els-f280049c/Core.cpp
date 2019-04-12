
#include "F28x_Project.h"
#include "Core.h"



Core :: Core( Encoder *encoder, StepperDrive *stepperDrive )
{
    this->encoder = encoder;
    this->stepperDrive = stepperDrive;

    this->feed = NULL;

    this->previousSpindlePosition = 0;
    this->previousFeed = 0;
}

void Core :: setReverse(bool reverse)
{
    this->stepperDrive->setReverse(reverse);
}







