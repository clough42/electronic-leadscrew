// Electronic Leadscrew
// https://github.com/alexphredorg/electronic-leadscrew
//
// Copyright (c) 2020 Alex Wetmore
//
// Derived from:
// Clough42 Electronic Leadscrew
// https://github.com/clough42/electronic-leadscrew
//
// MIT License
//
// Copyright (c) 2019 James Clough
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#ifndef __CORE_H
#define __CORE_H

#include "els.h"

class Core
{
private:
    Encoder *encoder;
    StepperDrive *stepperDrive;

#ifdef USE_FLOATING_POINT
    float feed;
    float previousFeed;
#else
    const FEED_THREAD *feed;
    const FEED_THREAD *previousFeed;
#endif // USE_FLOATING_POINT

    int16 feedDirection;
    int16 previousFeedDirection;

    Uint32 previousSpindlePosition;

    int32 feedRatio(Uint32 count);

    Uint16 leadscrewRpm;

public:
    Core( Encoder *encoder, StepperDrive *stepperDrive );

    void setFeed(const FEED_THREAD *feed);
    void setReverse(bool reverse);
    Uint16 getSpindleRPM(void);
    Uint16 getLeadscrewRPM(void);
    bool isAlarm();
    bool isOverWarningSpeed();
    bool isOverShutoffSpeed();

    void ISR( void );
};

inline void Core :: setFeed(const FEED_THREAD *feed)
{
#ifdef USE_FLOATING_POINT
    this->feed = (float)feed->numerator / feed->denominator;
#else
    this->feed = feed;
#endif // USE_FLOATING_POINT
}

inline Uint16 Core :: getSpindleRPM(void)
{
    return encoder->getRPM();
}

inline Uint16 Core :: getLeadscrewRPM(void)
{
    return leadscrewRpm;
}

inline bool Core :: isAlarm()
{
    return this->stepperDrive->isAlarm();
}

inline bool Core :: isOverWarningSpeed()
{
    return this->getLeadscrewRPM() > STEPPER_WARNING_RPM;
}

inline bool Core :: isOverShutoffSpeed()
{
    return this->getLeadscrewRPM() > STEPPER_SHUTOFF_RPM;
}

inline int32 Core :: feedRatio(Uint32 count)
{
#ifdef USE_FLOATING_POINT
    return ((float)count) * this->feed * feedDirection;
#else // USE_FLOATING_POINT
    return ((long long)count) * feed->numerator / feed->denominator * feedDirection;
#endif // USE_FLOATING_POINT
}

inline void Core :: ISR( void )
{
    if( this->feed != NULL ) {
        // read the encoder
        Uint32 spindlePosition = encoder->getPosition();

        // calculate the desired stepper position
        int32 desiredSteps = feedRatio(spindlePosition);
        stepperDrive->setDesiredPosition(desiredSteps);

        // compensate for encoder overflow/underflow
        if( spindlePosition < previousSpindlePosition && previousSpindlePosition - spindlePosition > encoder->getMaxCount()/2 ) {
            stepperDrive->incrementCurrentPosition(-1 * feedRatio(encoder->getMaxCount()));
        }
        if( spindlePosition > previousSpindlePosition && spindlePosition - previousSpindlePosition > encoder->getMaxCount()/2 ) {
            stepperDrive->incrementCurrentPosition(feedRatio(encoder->getMaxCount()));
        }

        // if the feed or direction changed, reset sync to avoid a big step
        if( feed != previousFeed || feedDirection != previousFeedDirection) {
            stepperDrive->setCurrentPosition(desiredSteps);
        }

        // remember values for next time
        previousSpindlePosition = spindlePosition;
        previousFeedDirection = feedDirection;
        previousFeed = feed;

        // compute leadscrew RPM
#ifdef USE_FLOATING_POINT
        Uint16 rpm = encoder->getRPM();
        float feed = this->feed * rpm;
        // converts feed to RPM
        float adjustment = (1.0 * ENCODER_RESOLUTION) / (STEPPER_RESOLUTION * STEPPER_MICROSTEPS);
        float leadscrewRpm = feed * adjustment;
        this->leadscrewRpm = static_cast<Uint16>(leadscrewRpm);
#else // USE_FLOATING_POINT
#warning Untested code
        long long rpm = encoder->getRPM();
        rpm *= feed->numerator / feed->denominator;
        rpm *= ENCODER_RESOLUTION;
        rpm /= STEPPER_RESOLUTION * STEPPER_MICROSTEPS;
        return static_cast<Uint16>(rpm);
#endif

        // service the stepper drive state machine
        stepperDrive->ISR();
    }
}


#endif // __CORE_H
