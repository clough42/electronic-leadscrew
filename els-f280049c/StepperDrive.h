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
    bool holdAtShoulder;
    int32 shoulderPosition;
    int32 startPosition;
    int32 directionToShoulder;

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

    void threadToShoulder(bool start);
    void setShoulder( void );
    void setStart(void);
    bool isAtShoulder( void );
    bool isAtStart( void );

    void setDesiredPosition(int32 steps);
    void incrementCurrentPosition(int32 increment);
    void setCurrentPosition(int32 position);

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



inline void StepperDrive :: setDesiredPosition(int32 steps)
{
    this->desiredPosition = steps;
}

inline void StepperDrive :: incrementCurrentPosition(int32 increment)
{
    this->startPosition += increment;
    this->currentPosition += increment;
    this->shoulderPosition += increment;
}

inline void StepperDrive :: setCurrentPosition(int32 position)
{
    this->currentPosition = position;
}

inline bool StepperDrive :: checkStepBacklog()
{
    if (!holdAtShoulder)
    {
        if( abs(this->desiredPosition - this->currentPosition) > MAX_BUFFERED_STEPS ) {
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
//    this->currentPosition = steps;
//    this->desiredPosition = steps;

    this->shoulderPosition = currentPosition;
}

inline void StepperDrive :: setStart()
{
    this->startPosition = this->currentPosition;
}

inline void StepperDrive :: threadToShoulder(bool start)
{
    this->threadingToShoulder = start;
    this->directionToShoulder = this->currentPosition - this->shoulderPosition;
}


inline bool StepperDrive :: isAtShoulder()
{
    return holdAtShoulder;
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


inline bool StepperDrive :: isAtStart( void )
{
    if (directionToShoulder > 0)
        return this->desiredPosition > this->startPosition;
    else
        return this->desiredPosition < this->startPosition;
}


// backlash value
// This fixes an issue (which may only apply to me) in that the encoder at certain positions 'dithered' causing the stepper to 'vibrate' resulting in noise when the lathe was stopped.
// This value effectively adds backlash to the system so that the minimum number of steps have to be issued before the motor will move
// set to zero if not required.
#define backlash 4


inline void StepperDrive :: ISR(void)
{
    int32 diff = this->desiredPosition - this->currentPosition;

    holdAtShoulder = false;
    if (threadingToShoulder)
    {
        int32 dist = getDistance();

        if (directionToShoulder >= 0)
        {
            if (dist <= backlash)
            {
                holdAtShoulder = true;
            }
        }
        else
        {
            if (dist >= backlash)
            {
                holdAtShoulder = true;
            }
        }
    }


    if(enabled)
    {
        if (!holdAtShoulder)
        {
            switch( this->state )
            {
            case 0:
                // Step = 0; Dir = 0
                if( diff < -backlash )
                {
                    GPIO_SET_STEP;
                    this->state = 2;
                }
                else if( diff > backlash )
                {
                    GPIO_SET_DIRECTION;
                    this->state = 1;
                }
                break;

            case 1:
                // Step = 0; Dir = 1
                if( diff > backlash )
                {
                    GPIO_SET_STEP;
                    this->state = 3;
                }
                else if( diff < -backlash )
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
    }
    else
    {
        // not enabled; just keep current position in sync
        this->currentPosition = this->desiredPosition;
    }
}

#endif // __STEPPERDRIVE_H
