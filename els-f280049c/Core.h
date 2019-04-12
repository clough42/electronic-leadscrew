#ifndef __CORE_H
#define __CORE_H

#include "StepperDrive.h"
#include "Encoder.h"
#include "ControlPanel.h"
#include "Tables.h"


class Core
{
private:
    Encoder *encoder;
    StepperDrive *stepperDrive;

    const FEED_THREAD *feed;
    const FEED_THREAD *previousFeed;

    Uint32 previousSpindlePosition;

    int32 Apply_Ratio(Uint32 count);

public:
    Core( Encoder *encoder, StepperDrive *stepperDrive );
    void setFeed(const FEED_THREAD *feed);
    void setReverse(bool reverse);
    Uint16 getRPM(void);
    void ISR( void );
};

inline void Core :: setFeed(const FEED_THREAD *feed)
{
    this->feed = feed;
}


inline Uint16 Core :: getRPM(void)
{
    return encoder->getRPM();
}

inline int32 Core :: Apply_Ratio(Uint32 count)
{
    return ((long long)count) * feed->numerator / feed->denominator;
}

inline void Core :: ISR( void )
{
    if( this->feed != NULL ) {
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
    }
}


#endif // __CORE_H
