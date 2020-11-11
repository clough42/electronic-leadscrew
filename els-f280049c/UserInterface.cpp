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


#include "UserInterface.h"

const MESSAGE STARTUP_MESSAGE_2 =
{
  .message = { LETTER_E, LETTER_L, LETTER_S, DASH, ONE | POINT, THREE | POINT, ZERO, ONE },
  .displayTime = UI_REFRESH_RATE_HZ * 1.5
};

const MESSAGE STARTUP_MESSAGE_1 =
{
 .message = { LETTER_C, LETTER_L, LETTER_O, LETTER_U, LETTER_G, LETTER_H, FOUR, TWO },
 .displayTime = UI_REFRESH_RATE_HZ * 1.5,
 .next = &STARTUP_MESSAGE_2
};

MESSAGE USER_INTERFACE_STATE =
{
 .message = { LETTER_S, LETTER_T, LETTER_A, LETTER_T, LETTER_E, BLANK, BLANK, BLANK },
 .displayTime = UI_REFRESH_RATE_HZ * 2
};

const Uint16 VALUE_BLANK[4] = { BLANK, BLANK, BLANK, BLANK };

Uint16 UserInterface :: digitToSevenSegmentPattern(Uint16 digit)
{
    switch (digit)
    {
    case 0:
        return ZERO;
    case 1:
        return ONE;
    case 2:
        return TWO;
    case 3:
        return THREE;
    case 4:
        return FOUR;
    case 5:
        return FIVE;
    case 6:
        return SIX;
    case 7:
        return SEVEN;
    case 8:
        return EIGHT;
    case 9:
        return NINE;
    default:
        return DASH;
    }
}

UserInterface :: UserInterface(ControlPanel *controlPanel, Core *core, FeedTableFactory *feedTableFactory)
{
    userInterfaceState = UI_STATE_NORMAL;

    this->controlPanel = controlPanel;
    this->core = core;
    this->feedTableFactory = feedTableFactory;

    this->metric = false; // start out with imperial
    this->thread = false; // start out with feeds
    this->reverse = false; // start out going forward

    this->feedTable = NULL;

    this->keys.all = 0xff;

    // initialize the core so we start up correctly
    core->setReverse(this->reverse);
    core->setFeed(loadFeedTable());

    setMessage(&STARTUP_MESSAGE_1);
}

const FEED_THREAD *UserInterface::loadFeedTable()
{
    this->feedTable = this->feedTableFactory->getFeedTable(this->metric, this->thread);
    return this->feedTable->current();
}

LED_REG UserInterface::calculateLEDs()
{
    // get the LEDs for this feed
    LED_REG leds = feedTable->current()->leds;

    if( this->core->isPowerOn() )
    {
        // and add a few of our own
        leds.bit.POWER = 1;
        leds.bit.REVERSE = this->reverse;
        leds.bit.FORWARD = ! this->reverse;
    }
    else
    {
        // power is off
        leds.all = 0;
    }

    return leds;
}

void UserInterface :: setMessage(const MESSAGE *message)
{
    this->message = message;
    this->messageTime = message->displayTime;
}

void UserInterface :: overrideMessage( void )
{
    // see if an override message is pending
    if( this->message != NULL )
    {
        // message pending
        // see if message display has timed out
        if( this->messageTime > 0 )
        {
            // not timed out
            this->messageTime--;
            controlPanel->setMessage(this->message->message);
        }
        else
        {
            // timed out
            // reset user interface state to normal
            userInterfaceState = UI_STATE_NORMAL;

            // see if there's another message
            this->message = this->message->next;
            if( this->message == NULL )
                // no more messages
                controlPanel->setMessage(NULL);
            else
                // more messages
                // set to display next message
                this->messageTime = this->message->displayTime;
        }
    }
}

void UserInterface :: loop( void )
{
    Uint16 number;

    // read the RPM up front so we can use it to make decisions
    Uint16 currentRpm = core->getRPM();

    // display an override message, if there is one
    overrideMessage();

    // read keypresses from the control panel
    keys = controlPanel->getKeys();

    // respond to keypresses
    if( currentRpm == 0 )
    {
        // these keys should only be sensitive when the machine is stopped
        if( keys.bit.POWER )
        {
            this->core->setPowerOn(!this->core->isPowerOn());

            userInterfaceState = UI_STATE_NORMAL;
        }

        // these should only work when the power is on
        if( this->core->isPowerOn() )
        {
            if( keys.bit.IN_MM )
            {
                this->metric = ! this->metric;
                core->setFeed(loadFeedTable());
            }
            if( keys.bit.FEED_THREAD )
            {
                this->thread = ! this->thread;
                core->setFeed(loadFeedTable());
            }
            if( keys.bit.FWD_REV )
            {
                this->reverse = ! this->reverse;
                core->setReverse(this->reverse);
            }
            if( keys.bit.SET )
            {
                switch (userInterfaceState)
                {
                case UI_STATE_NORMAL:
                    userInterfaceState = UI_STATE_ADJ_BRT;

                    USER_INTERFACE_STATE.message[0] = LETTER_B;
                    USER_INTERFACE_STATE.message[1] = LETTER_r;
                    USER_INTERFACE_STATE.message[2] = LETTER_t;
                    USER_INTERFACE_STATE.message[3] = BLANK;
                    USER_INTERFACE_STATE.message[4] = BLANK;
                    USER_INTERFACE_STATE.message[5] = BLANK;
                    USER_INTERFACE_STATE.message[6] = BLANK;
                    USER_INTERFACE_STATE.message[7] = digitToSevenSegmentPattern(controlPanel->getBrightness());
                    setMessage(&USER_INTERFACE_STATE);
                break;

                case UI_STATE_ADJ_BRT:
                    userInterfaceState = UI_STATE_uSTPS;

                    USER_INTERFACE_STATE.message[0] = LETTER_L;
                    USER_INTERFACE_STATE.message[1] = LETTER_E;
                    USER_INTERFACE_STATE.message[2] = LETTER_A;
                    USER_INTERFACE_STATE.message[3] = LETTER_D;
                    USER_INTERFACE_STATE.message[4] = BLANK;
                    USER_INTERFACE_STATE.message[5] = BLANK;
                    USER_INTERFACE_STATE.message[6] = digitToSevenSegmentPattern(LEADSCREW_TPI / 10);
                    USER_INTERFACE_STATE.message[7] = digitToSevenSegmentPattern(LEADSCREW_TPI % 10);
                    setMessage(&USER_INTERFACE_STATE);
                break;

                case UI_STATE_uSTPS:
                    userInterfaceState = UI_STATE_STEPPER_RES;

                    USER_INTERFACE_STATE.message[0] = LETTER_u;
                    USER_INTERFACE_STATE.message[1] = LETTER_S;
                    USER_INTERFACE_STATE.message[2] = LETTER_T;
                    USER_INTERFACE_STATE.message[3] = LETTER_P;
                    USER_INTERFACE_STATE.message[4] = LETTER_S;
                    USER_INTERFACE_STATE.message[5] = BLANK;
                    USER_INTERFACE_STATE.message[6] = BLANK;
                    USER_INTERFACE_STATE.message[7] = digitToSevenSegmentPattern(STEPPER_MICROSTEPS);
                    setMessage(&USER_INTERFACE_STATE);
                break;

                case UI_STATE_STEPPER_RES:
                    userInterfaceState = UI_STATE_ENCODER_RES;

                    USER_INTERFACE_STATE.message[0] = LETTER_S | POINT;
                    USER_INTERFACE_STATE.message[1] = LETTER_r;
                    USER_INTERFACE_STATE.message[2] = LETTER_E;
                    USER_INTERFACE_STATE.message[3] = LETTER_S;
                    number = STEPPER_RESOLUTION;
                    // note the next four are in reverse order
                    USER_INTERFACE_STATE.message[7] = digitToSevenSegmentPattern( number % 10 );
                    USER_INTERFACE_STATE.message[6] = digitToSevenSegmentPattern( (number = number / 10) % 10 );
                    USER_INTERFACE_STATE.message[5] = digitToSevenSegmentPattern( (number = number / 10) % 10 );
                    USER_INTERFACE_STATE.message[4] = digitToSevenSegmentPattern( (number = number / 10) % 10 );
                    setMessage(&USER_INTERFACE_STATE);
                break;

                case UI_STATE_ENCODER_RES:
                    userInterfaceState = UI_STATE_NORMAL;

                    USER_INTERFACE_STATE.message[0] = LETTER_E | POINT;
                    USER_INTERFACE_STATE.message[1] = LETTER_r;
                    USER_INTERFACE_STATE.message[2] = LETTER_E;
                    USER_INTERFACE_STATE.message[3] = LETTER_S;
                    number = ENCODER_RESOLUTION;
                    // note the next four are in reverse order
                    USER_INTERFACE_STATE.message[7] = digitToSevenSegmentPattern( number % 10 );
                    USER_INTERFACE_STATE.message[6] = digitToSevenSegmentPattern( (number = number / 10) % 10 );
                    USER_INTERFACE_STATE.message[5] = digitToSevenSegmentPattern( (number = number / 10) % 10 );
                    USER_INTERFACE_STATE.message[4] = digitToSevenSegmentPattern( (number = number / 10) % 10 );
                    setMessage(&USER_INTERFACE_STATE);
                break;

                default:
                    userInterfaceState = UI_STATE_NORMAL;
                }
            }
        }
    }

#ifdef IGNORE_ALL_KEYS_WHEN_RUNNING
    if( currentRpm == 0 )
        {
#endif // IGNORE_ALL_KEYS_WHEN_RUNNING

        // these should only work when the power is on
        if( this->core->isPowerOn() )
        {
            // these keys can be operated when the machine is running
            switch (userInterfaceState)
            {
            case UI_STATE_NORMAL:
                if( keys.bit.UP )
                {
                    core->setFeed(feedTable->next());
                }
                if( keys.bit.DOWN )
                {
                    core->setFeed(feedTable->previous());
                }
            break;

            case UI_STATE_ADJ_BRT:
                if( keys.bit.UP )
                {
                    controlPanel->increaseBrightness();

                    USER_INTERFACE_STATE.message[7] = digitToSevenSegmentPattern(controlPanel->getBrightness());
                    setMessage(&USER_INTERFACE_STATE);
                }

                if( keys.bit.DOWN )
                {
                    controlPanel->decreaseBrightness();

                    USER_INTERFACE_STATE.message[7] = digitToSevenSegmentPattern(controlPanel->getBrightness());
                    setMessage(&USER_INTERFACE_STATE);
                }
            break;

            }
        }

#ifdef IGNORE_ALL_KEYS_WHEN_RUNNING
    }
#endif // IGNORE_ALL_KEYS_WHEN_RUNNING

    // update the control panel
    controlPanel->setLEDs(calculateLEDs());
    controlPanel->setValue(feedTable->current()->display);
    controlPanel->setRPM(currentRpm);

    if( ! core->isPowerOn() )
    {
        controlPanel->setValue(VALUE_BLANK);
    }

    controlPanel->refresh();
}
