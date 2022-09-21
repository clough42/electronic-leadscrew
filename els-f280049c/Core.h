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

#include "StepperDrive.h"
#include "Encoder.h"
#include "ControlPanel.h"
#include "Tables.h"


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

    bool powerOn;

public:
    Core( Encoder *encoder, StepperDrive *stepperDrive );

    void reset(void);
    void setFeed(const FEED_THREAD *feed);
    void setReverse(bool reverse);
    Uint16 getRPM(void);
    bool isAlarm();

    bool isPowerOn();
    void setPowerOn(bool);

    void setShoulder( void );
    void setStart( void );
    void threadToShoulder( bool start );
    bool isAtShoulder( void );
    bool isAtStart( void );

    // debug
    void setPosition( Uint32 newPos );
    Uint32 getEncoder(Uint32 position);
    int32 getDistance( void );
    int32 getSpindle( void );
    int32 getPosition( void );
    int32 getDesired( void );
    int32 getShoulder( void );
    int32 getStart( void );

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

inline void Core :: setPosition(Uint32 newPos)
{
    encoder->setPosition(newPos);
}

inline Uint16 Core :: getRPM(void)
{
    return encoder->getRPM();
}

inline bool Core :: isAlarm()
{
    return this->stepperDrive->isAlarm();
}

inline bool Core :: isPowerOn()
{
    return this->powerOn;
}

inline void Core :: setStart( void )
{
    stepperDrive->setStart();
}

inline void Core :: threadToShoulder(bool start)
{
    stepperDrive->threadToShoulder(start);
}

inline bool Core :: isAtShoulder( void )
{
    return stepperDrive->isAtShoulder();
}

inline bool Core :: isAtStart( void )
{
    return stepperDrive->isAtStart();
}

inline int32 Core :: getDistance()
{
    return stepperDrive->getDistance();
}

inline int32 Core :: getSpindle( void )
{
    return encoder->getPosition();
}

inline int32 Core :: getPosition( void )
{
    return stepperDrive->getPosition();
}

inline int32 Core :: getDesired( void )
{
    return stepperDrive->getDesired();
}

inline int32 Core :: getShoulder( void )
{
    return stepperDrive->getShoulder();
}

inline int32 Core :: getStart( void )
{
    return stepperDrive->getStart();
}

inline int32 Core :: feedRatio(Uint32 count)
{
#ifdef USE_FLOATING_POINT
    return ((float)count) * this->feed * feedDirection;
#else // USE_FLOATING_POINT
    return ((long long)count) * feed->numerator / feed->denominator * feedDirection;
#endif // USE_FLOATING_POINT
}


// get an encoder value that matches stepper position (but doesn't alter angular relationship)
inline Uint32 Core :: getEncoder(Uint32 position)
{
    //Uint32 pos = getPosition();
    //Uint32 frac = pos % ENCODER_RESOLUTION; // normalised 0-360 deg

    return (float) position / feed;

    //int32 desiredSteps = feedRatio(spindlePosition);
    //stepperDrive->setDesiredPosition(desiredSteps);

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
        if( spindlePosition < previousSpindlePosition && previousSpindlePosition - spindlePosition > encoder->getMaxCount()/2 )
        {
            stepperDrive->incrementCurrentPosition(-1 * feedRatio(encoder->getMaxCount()));
        }
        if( spindlePosition > previousSpindlePosition && spindlePosition - previousSpindlePosition > encoder->getMaxCount()/2 )
        {
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

        // service the stepper drive state machine
        stepperDrive->ISR();
    }
}



#endif // __CORE_H
