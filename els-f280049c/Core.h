#ifndef __CORE_H
#define __CORE_H

#include "StepperDrive.h"
#include "Encoder.h"
#include "ControlPanel.h"


class Core
{
private:
    Encoder *encoder;
    StepperDrive *stepperDrive;

    long double feed;
    Uint32 previousSpindlePosition;
    long double previousFeed;

    int32 Apply_Ratio(Uint32 count);

public:
    Core( Encoder *encoder, StepperDrive *stepperDrive );

    void ISR( void );
};

inline int32 Core :: Apply_Ratio(Uint32 count)
{
    //return ((long long)count) * numerator / denominator;
    return count * feed;
}

inline void Core :: ISR( void )
{
    //
    // Calculate the correct stepper position
    //
    Uint32 spindlePosition = encoder->getPosition();
    int32 desiredSteps = Apply_Ratio(spindlePosition);

    // overflow
    if( spindlePosition < previousSpindlePosition && previousSpindlePosition - spindlePosition > encoder->getMaxCount()/2 ) {
        stepperDrive->incrementCurrentPosition(-1 * Apply_Ratio(encoder->getMaxCount()));
    }
    // underflow
    if( spindlePosition > previousSpindlePosition && spindlePosition - previousSpindlePosition > encoder->getMaxCount()/2 ) {
        stepperDrive->incrementCurrentPosition(Apply_Ratio(encoder->getMaxCount()));
    }

    stepperDrive->setDesiredPosition(desiredSteps);

    // if the feed changed, we want to reset and avoid a big step
    if( feed != previousFeed ) {
        stepperDrive->setCurrentPosition(desiredSteps);
    }

    previousSpindlePosition = spindlePosition;
    previousFeed = feed;

    //
    // Service the stepper driver
    //
    stepperDrive->ISR();

    ControlPanel_SetRPM(encoder->getRPM());
}


#endif // __CORE_H
