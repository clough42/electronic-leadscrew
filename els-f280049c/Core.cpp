
#include "F28x_Project.h"
#include "Core.h"



Core :: Core( Encoder *encoder, StepperDrive *stepperDrive )
{
    this->encoder = encoder;
    this->stepperDrive = stepperDrive;

    this->feed = NULL;
    this->feedDirection = 0;

    this->previousSpindlePosition = 0;
    this->previousFeedDirection = 0;
    this->previousFeed = NULL;
}

void Core :: setReverse(bool reverse)
{
    if( reverse )
    {
        this->feedDirection = -1;
    }
    else
    {
        this->feedDirection = 1;
    }
}







