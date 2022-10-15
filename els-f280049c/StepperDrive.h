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


#ifndef __STEPPERDRIVE_H
#define __STEPPERDRIVE_H

#include "F28x_Project.h"
#include "Configuration.h"


#define STEP_PIN GPIO0
#define DIRECTION_PIN GPIO1
#define ENABLE_PIN GPIO6
#define ALARM_PIN GPIO7

#define GPIO_SET(pin) GpioDataRegs.GPASET.bit.pin = 1
#define GPIO_CLEAR(pin) GpioDataRegs.GPACLEAR.bit.pin = 1
#define GPIO_GET(pin) GpioDataRegs.GPADAT.bit.pin

#ifdef INVERT_STEP_PIN
#define GPIO_SET_STEP GPIO_CLEAR(STEP_PIN)
#define GPIO_CLEAR_STEP GPIO_SET(STEP_PIN)
#else
#define GPIO_SET_STEP GPIO_SET(STEP_PIN)
#define GPIO_CLEAR_STEP GPIO_CLEAR(STEP_PIN)
#endif

#ifdef INVERT_DIRECTION_PIN
#define GPIO_SET_DIRECTION GPIO_CLEAR(DIRECTION_PIN)
#define GPIO_CLEAR_DIRECTION GPIO_SET(DIRECTION_PIN)
#else
#define GPIO_SET_DIRECTION GPIO_SET(DIRECTION_PIN)
#define GPIO_CLEAR_DIRECTION GPIO_CLEAR(DIRECTION_PIN)
#endif

#ifdef INVERT_ENABLE_PIN
#define GPIO_SET_ENABLE GPIO_CLEAR(ENABLE_PIN)
#define GPIO_CLEAR_ENABLE GPIO_SET(ENABLE_PIN)
#else
#define GPIO_SET_ENABLE GPIO_SET(ENABLE_PIN)
#define GPIO_CLEAR_ENABLE GPIO_CLEAR(ENABLE_PIN)
#endif

#ifdef INVERT_ALARM_PIN
#define GPIO_GET_ALARM (GPIO_GET(ALARM_PIN) == 0)
#else
#define GPIO_GET_ALARM (GPIO_GET(ALARM_PIN) != 0)
#endif


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

    // for when threading to a shoulder
    bool threadingToShoulder;
    bool movingToStart;
    bool holdAtShoulder;
    int32 shoulderPosition;
    int32 startPosition;
    int32 directionToShoulder;

    Uint32 moveToStartDelay;

    //
    // current state-machine state
    // bit 0 - step signal
    // bit 1 - direction signal
    //
    Uint16 state;

    //
    // Is the drive enabled?
    //
    bool enabled;

public:
    StepperDrive();
    void initHardware( void );

    bool shoulderISR( int32 diff );
    void beginThreadToShoulder( bool start );
    void moveToStart( float stepsPerUnitPitch );
    void setShoulder( void );
    void setStart(void);
    bool isAtShoulder( void );
    bool isAtStart( void );

    void setDesiredPosition( int32 steps );
    void incrementCurrentPosition( int32 increment );
    void setCurrentPosition( int32 position );
    void setBestPosition( float stepsPerUnitPitch );

    // debug
    int32 getDistance( void );
    int32 getPosition( void );
    int32 getDesired( void );
    int32 getShoulder( void );
    int32 getStart( void );


    bool checkStepBacklog();

    void setEnabled(bool);

    bool isAlarm();

    void ISR(void);
};



inline void StepperDrive :: setDesiredPosition( int32 steps )
{
    this->desiredPosition = steps;
}

inline void StepperDrive :: incrementCurrentPosition( int32 increment )
{
    this->startPosition += increment;
    this->currentPosition += increment;
    this->shoulderPosition += increment;
}

inline void StepperDrive :: setCurrentPosition( int32 position )
{
    this->currentPosition = position;
}

inline bool StepperDrive :: checkStepBacklog()
{
    // holding and retracting are special cases where the backlog can exceed limits (this shouldn't matter since the motor is either stopped or moving at a safe value).
    if (!holdAtShoulder && !movingToStart)
    {
        if( abs(this->desiredPosition - this->currentPosition) > MAX_BUFFERED_STEPS )
        {
            setEnabled(false);
            return true;
        }
    }
    return false;
}

inline void StepperDrive :: setEnabled(bool enabled)
{
    this->enabled = enabled;
    if( this->enabled ) {
        GPIO_SET_ENABLE;
    }
    else
    {
        GPIO_CLEAR_ENABLE;
    }
}

inline bool StepperDrive :: isAlarm()
{
#ifdef USE_ALARM_PIN
    return GPIO_GET_ALARM;
#else
    return false;
#endif
}

inline void StepperDrive :: setShoulder()
{
    this->shoulderPosition = currentPosition;
}

inline void StepperDrive :: setStart()
{
    this->startPosition = this->currentPosition;
}

inline bool StepperDrive :: isAtShoulder()
{
    // note: when moving to shoulder currentPosition will stop at the shoulder position
    return (abs(currentPosition - shoulderPosition) <= backlash);
}

inline bool StepperDrive :: isAtStart( void )
{
    // when moving to start we can overshoot it by the time this function is called so need to allow for this
    if (this->directionToShoulder >= 0)
        return (this->startPosition - this->desiredPosition) < 0;
    else
        return (this->startPosition - this->desiredPosition) >= 0;
}


inline void StepperDrive :: beginThreadToShoulder(bool start)
{
    this->threadingToShoulder = start;
    this->directionToShoulder = this->startPosition - this->shoulderPosition;
    holdAtShoulder = false;
}

inline int32 StepperDrive :: getDistance(void)
{
    return desiredPosition - shoulderPosition;
}

inline int32 StepperDrive :: getPosition( void )
{
    return currentPosition;
}

inline int32 StepperDrive :: getDesired( void )
{
    return desiredPosition;
}

inline int32 StepperDrive :: getShoulder( void )
{
    return shoulderPosition;
}

inline int32 StepperDrive :: getStart( void )
{
    return this->startPosition;
}



extern int32 debugVals[];

// we have a desired position that's behind the shoulder, calculate a currentPosition that moves us within 1 thread of the shoulder whilst still maintaining the angular relationship
inline void StepperDrive :: setBestPosition( float stepsPerUnitPitch )
{
    // total steps we've overshot by
    float diff = (float) (this->desiredPosition - this->currentPosition);

    // number of full threads we need to traverse to close up the gap
    int32 ival = diff / stepsPerUnitPitch;

    // multiply threads by steps per pitch to get total steps
    ival = ival * stepsPerUnitPitch;

    this->incrementCurrentPosition(ival);
}


// auto retract to start
inline void StepperDrive :: moveToStart( float stepsPerUnitPitch )
{
    // total steps from where we think we are to the start
    float diff = (float) (this->desiredPosition - this->startPosition);

    // calculate the number of complete rotations of the leadscrew that will take us to the start (+1 to ensure we pass it)
    // (we need complete rotations to maintain the phase relationship between the spindle and leadscrew)
    int32 ival = diff / stepsPerUnitPitch;
    ival += diff < 0 ? -1 : +1;
    diff = ival * stepsPerUnitPitch;

    this->incrementCurrentPosition( diff );

    movingToStart = true;
}

// handle the shoulder during the ISR. Returns true to block stepper movement
inline bool StepperDrive :: shoulderISR(int32 diff)
{
    // handle threading to shoulder (and auto-retraction to start)
    if (threadingToShoulder)
    {
        // Only do this on the beginning of a clock pulse (allow pulses that have been started to complete)
        if (this->state < 2)
        {
            // if we're auto retracting then accelerate the motor to max speed and flag when we get to the start to allow the state machine to continue
            if (movingToStart)
            {
                moveToStartDelay++;
                if (moveToStartDelay > 63)
                {
                    moveToStartDelay = 0;

                    // when moving to start we've set the desiredPosition to the start so once currentPosition is the same then we're there.
                    if (abs(diff) <= backlash)
                        movingToStart = false;
                }
                else
                    return true;
            }
            else
            // check if we've reached the shoulder, if so then prevent any further indexing of the stepper
            {
                int32 dist = getDistance();

                if (directionToShoulder >= 0)
                {
                    if (dist <= 0)
                    {
                        holdAtShoulder = true;
                        return true;
                    }
                }
                else
                {
                    if (dist >= 0)
                    {
                        holdAtShoulder = true;
                        return true;
                    }
                }

                holdAtShoulder = false;
            }
        }
    }
    return false;
}


inline void StepperDrive :: ISR(void)
{
    int32 diff = this->desiredPosition - this->currentPosition;

    if (shoulderISR(diff))
        return;

    debugVals[0] = diff;
    debugVals[1] = abs(currentPosition - shoulderPosition);     // shoulder
    debugVals[2] = directionToShoulder;
    debugVals[3] = this->startPosition - this->desiredPosition;


    // generate step
    if(enabled)
    {
        switch( this->state )
        {
        case 0:
            // Step = 0; Dir = 0
            if( diff <= -backlash )
            {
                GPIO_SET_STEP;
                this->state = 2;
            }
            else if( diff >= backlash )
            {
                GPIO_SET_DIRECTION;
                this->state = 1;
            }
            break;

        case 1:
            // Step = 0; Dir = 1
            if( diff >= backlash )
            {
                GPIO_SET_STEP;
                this->state = 3;
            }
            else if( diff <= -backlash )
            {
                GPIO_CLEAR_DIRECTION;
                this->state = 0;
            }
            break;

        case 2:
            // Step = 1; Dir = 0
            GPIO_CLEAR_STEP;
            this->currentPosition--;
            this->state = 0;
            break;

        case 3:
            // Step = 1; Dir = 1
            GPIO_CLEAR_STEP;
            this->currentPosition++;
            this->state = 1;
            break;
        }
    }
    else
    {
        // not enabled; just keep current position in sync
        this->currentPosition = this->desiredPosition;
    }
}

#endif // __STEPPERDRIVE_H
