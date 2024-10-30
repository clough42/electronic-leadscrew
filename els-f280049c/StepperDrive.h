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
    bool    threadingToShoulder;
    bool    movingToStart;
    bool    holdAtShoulder;
    int32   shoulderPosition;
    int32   startPosition;
    int32   directionToShoulder;

    Uint32  moveToStartDelay;
    Uint32  moveToStartSpeed;
    int     accelTime;

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
    void moveToStart( int32 stepsPerUnitPitch );
    void setShoulder( void )                            { this->shoulderPosition = currentPosition; }
    void setStart(void)                                 { this->startPosition = this->currentPosition; }
    void setStartOffset( int32 startOffset );
    bool isAtShoulder( void );
    bool isAtStart( void );
    void resetToShoulder( float stepsPerUnitPitch );
    int32 getDistanceToShoulder( void )                 { return desiredPosition - shoulderPosition; }

    void setDesiredPosition( int32 steps )              { this->desiredPosition = steps; }
    void incrementCurrentPosition( int32 increment );
    void setCurrentPosition( int32 position )           { this->currentPosition = position; }

    bool checkStepBacklog();

    void setEnabled(bool);

    bool isAlarm();

    void ISR(void);
};


inline void StepperDrive :: incrementCurrentPosition( int32 increment )
{
    this->currentPosition += increment;
    this->startPosition += increment;
    this->shoulderPosition += increment;
}

inline bool StepperDrive :: checkStepBacklog()
{
    // holding and retracting are special cases where the backlog can exceed limits (this shouldn't matter since the motor is either stopped or moving at a safe value).
    if (!(holdAtShoulder || movingToStart))
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


inline bool StepperDrive :: isAtShoulder()
{
    // note: when moving to shoulder currentPosition will stop at the shoulder position
    return (labs(currentPosition - shoulderPosition) <= backlash);
}

inline bool StepperDrive :: isAtStart( void )
{
    // when moving to start we can have overshot it by the time this function is called so need to allow for this
    if (this->directionToShoulder < 0)
        return (this->currentPosition - this->startPosition) >= -backlash;
    else
        return (this->currentPosition - this->startPosition) <= backlash;
}


inline void StepperDrive :: beginThreadToShoulder(bool start)
{
    this->threadingToShoulder = start;
    this->directionToShoulder = this->shoulderPosition - this->startPosition;

    // quitting? If so reset current position.
    if (!start)
        this->currentPosition = this->desiredPosition;

    holdAtShoulder = false;
}


// we have a desired position that's behind the shoulder, calculate a currentPosition that moves us within 1 thread of the shoulder whilst still maintaining the angular relationship
inline void StepperDrive :: resetToShoulder( float stepsPerUnitPitch )
{
    // total steps we've overshot by
    float diff = this->desiredPosition - this->currentPosition;

    // discard the fractional part to get the number of full threads we need to traverse to close up the gap
    int32 ival = diff / stepsPerUnitPitch;
    ival = ival * stepsPerUnitPitch;

    this->incrementCurrentPosition(ival);
}

inline void StepperDrive :: setStartOffset( int32 startOffset )
{
    if (this->directionToShoulder > 0)
        startOffset = -startOffset;

    incrementCurrentPosition(startOffset);
}

// auto retract to start
inline void StepperDrive :: moveToStart( int32 stepsPerUnitPitch )
{
    int32 diff = this->desiredPosition - this->startPosition;

    int32 ival = diff / stepsPerUnitPitch;
    ival += diff < 0 ? -1 : +1;
    diff = ival * stepsPerUnitPitch;

    this->incrementCurrentPosition( diff );

    moveToStartSpeed = retractSpeed * 5;   // start at 1/5th max speed
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
                int32 dist = labs(diff);

                // rate of acceleration/deceleration
                if (!(++accelTime & 0x1ff))
                {
                    // if we're nearly at the start then start decelerating
                    if (dist < (STEPPER_MICROSTEPS * STEPPER_RESOLUTION / 3))
                    {
                        if (moveToStartSpeed < retractSpeed * 10)
                            moveToStartSpeed++;
                    }
                    else
                    {
                        if (moveToStartSpeed > retractSpeed)
                            moveToStartSpeed--;
                    }
                }

                // index motor at preset rate
                if (++moveToStartDelay > moveToStartSpeed)
                {
                    moveToStartDelay = 0;

                    // when moving to start we've set the desiredPosition to the start so once currentPosition is the same then we're done.
                    movingToStart = (dist > backlash);
                }
                else
                    return true;
            }
            else
            // check if we've reached the shoulder, if so then prevent any further indexing of the stepper
            // note: we use the desiredPosition since this allows manual rotation away from the shoulder to remove the block on motor movement
            {
                int32 dist = getDistanceToShoulder();

                if ((directionToShoulder >= 0 && dist > 0) ||
                    (directionToShoulder < 0 && dist < 0))
                {
                    holdAtShoulder = true;
                    return true;
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
