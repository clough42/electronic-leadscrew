
#include "F28x_Project.h"
#include "Core.h"



Core :: Core( Encoder *encoder, StepperDrive *stepperDrive )
{
    this->encoder = encoder;
    this->stepperDrive = stepperDrive;

    this->feed = 200.0 * 8.0 / 4096.0;
    this->previousSpindlePosition = 0;
    this->previousFeed = 0;
}







