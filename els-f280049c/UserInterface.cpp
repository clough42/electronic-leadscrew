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
  .message = { LETTER_E, LETTER_L, LETTER_S, DASH, ONE | POINT, TWO | POINT, ZERO, ZERO },
  .displayTime = UI_REFRESH_RATE_HZ * 1.5
};

const MESSAGE STARTUP_MESSAGE_1 =
{
 .message = { LETTER_C, LETTER_L, LETTER_O, LETTER_U, LETTER_G, LETTER_H, FOUR, TWO },
 .displayTime = UI_REFRESH_RATE_HZ * 1.5,
 .next = &STARTUP_MESSAGE_2
};

const MESSAGE SETTINGS_MESSAGE_SPINDLE_RPM =
{
 .message = { LETTER_S, LETTER_P, LETTER_I, LETTER_N | POINT, BLANK, LETTER_R, LETTER_P, LETTER_M },
 .displayTime = UI_REFRESH_RATE_HZ * 0.7
};

const MESSAGE SETTINGS_MESSAGE_LEADSCREW_RPM =
{
 .message = { LETTER_L, LETTER_E, LETTER_A, LETTER_D | POINT, BLANK, LETTER_R, LETTER_P, LETTER_M },
 .displayTime = UI_REFRESH_RATE_HZ * 0.7
};

const MESSAGE ALARM_MESSAGE_TOO_FAST_WARNING =
{
 .message = { LETTER_S, LETTER_P, LETTER_E, LETTER_E, LETTER_D, BLANK, LETTER_W, LETTER_N },
 .displayTime = UI_REFRESH_RATE_HZ * .2
};

const MESSAGE ALARM_MESSAGE_TOO_FAST_ERROR_2 =
{
 .message = { LETTER_P, LETTER_W, LETTER_R, BLANK, LETTER_O, LETTER_F, LETTER_F, BLANK },
 .displayTime = UI_REFRESH_RATE_HZ * 2.5
};

const MESSAGE ALARM_MESSAGE_TOO_FAST_ERROR =
{
 .message = { LETTER_S, LETTER_P, LETTER_E, LETTER_E, LETTER_D, BLANK, LETTER_E, LETTER_R },
 .displayTime = UI_REFRESH_RATE_HZ * 2.5,
 .next = &ALARM_MESSAGE_TOO_FAST_ERROR_2
};

const MESSAGE ALARM_MESSAGE_STEPPER_DRIVER =
{
 .message = { LETTER_S, LETTER_T, LETTER_P, LETTER_P, LETTER_R, BLANK, LETTER_E, LETTER_R },
 // on most drives this is permanent until shutdown, so it will restart every second
 .displayTime = UI_REFRESH_RATE_HZ * 0.7
};

UserInterface :: UserInterface(ControlPanel *controlPanel, Core *core, FeedTableFactory *feedTableFactory)
{
    this->controlPanel = controlPanel;
    this->core = core;
    this->feedTableFactory = feedTableFactory;

    this->metric = false; // start out with imperial
    this->thread = false; // start out with feeds
    this->reverse = false; // start out going forward
    this->power = true; // power on by default
    this->displaySpindleRpm = true; // start out with spindle rpm

    this->feedTable = NULL;

    this->keys.all = 0xff;

    this->checkInterval = 0;

    setMessage(&STARTUP_MESSAGE_1);
}

const FEED_THREAD *UserInterface::loadFeedTable()
{
    this->feedTable = this->feedTableFactory->getFeedTable(this->metric, this->thread);
    return this->feedTable->current();
}

LED_REG UserInterface::calculateLEDs(const FEED_THREAD *selectedFeed)
{
    // get the LEDs for this feed
    LED_REG leds = selectedFeed->leds;

    // and add a few of our own
    leds.bit.POWER = this->power;
    leds.bit.REVERSE = this->reverse;
    leds.bit.FORWARD = ! this->reverse;

    return leds;
}

void UserInterface :: setMessage(const MESSAGE *message)
{
    this->message = message;
    this->messageTime = message->displayTime;
}

void UserInterface :: overrideMessage( void )
{
    if( this->message != NULL )
    {
        if( this->messageTime > 0 ) {
            this->messageTime--;
            controlPanel->setMessage(this->message->message);
        }
        else {
            this->message = this->message->next;
            if( this->message == NULL )
                controlPanel->setMessage(NULL);
            else
                this->messageTime = this->message->displayTime;
        }
    }
}

void UserInterface :: loop( void )
{
    const FEED_THREAD *newFeed = NULL;

    // display an override message, if there is one
    overrideMessage();

    // just in case, initialize the first time through
    if( feedTable == NULL ) {
        newFeed = loadFeedTable();
    }

    // do periodic checks
    //
    // this is done once per second because failures can override the
    // message to blink in warnings or errors
    this->checkInterval++;
    if (this->checkInterval == UI_REFRESH_RATE_HZ)
    {
        this->checkInterval = 0;

        if (core->isAlarm())
        {
            setMessage(&ALARM_MESSAGE_STEPPER_DRIVER);
        }
        else if (core->isOverShutoffSpeed())
        {
            setMessage(&ALARM_MESSAGE_TOO_FAST_ERROR);
            // turn off the stepper drive
            this->power = false;
            GPIO_CLEAR_ENABLE;
            // feed table hasn't changed, but we need to trigger an update
            newFeed = loadFeedTable();
        }
        else if (core->isOverWarningSpeed())
        {
            setMessage(&ALARM_MESSAGE_TOO_FAST_WARNING);
        }
    }

    // read keypresses from the control panel
    keys = controlPanel->getKeys();

    // respond to keypresses
    if( keys.bit.IN_MM )
    {
        // toggles metric or inch mode
        this->metric = ! this->metric;
        newFeed = loadFeedTable();
    }
    if( keys.bit.FEED_THREAD )
    {
        // toggles threading or feed mode
        this->thread = ! this->thread;
        newFeed = loadFeedTable();
    }
    if( keys.bit.FWD_REV )
    {
        // toggles stepper direction
        this->reverse = ! this->reverse;
        // feed table hasn't changed, but we need to trigger an update
        newFeed = loadFeedTable();
    }
    if( keys.bit.UP )
    {
        // changes feed rate
        newFeed = feedTable->next();
    }
    if( keys.bit.DOWN )
    {
        // changes feed rate
        newFeed = feedTable->previous();
    }
    if( keys.bit.SET )
    {
        // toggles showing spindle or leadscrew RPM
        this->displaySpindleRpm = !this->displaySpindleRpm;
        setMessage((this->displaySpindleRpm) ? &SETTINGS_MESSAGE_SPINDLE_RPM : &SETTINGS_MESSAGE_LEADSCREW_RPM);
    }
    if( keys.bit.POWER )
    {
        // toggles stepper enable
        this->power = !this->power;
        GPIO_CLEAR_STEP;
        GPIO_CLEAR_DIRECTION;
        if (this->power)
        {
            GPIO_SET_ENABLE;
        }
        else
        {
            GPIO_CLEAR_ENABLE;
        }
        EDIS;
        // feed table hasn't changed, but we need to trigger an update
        newFeed = loadFeedTable();
    }

    // if we have changed the feed
    if( newFeed != NULL ) {
        // update the display
        LED_REG leds = this->calculateLEDs(newFeed);
        controlPanel->setLEDs(leds);
        controlPanel->setValue(newFeed->display);

        // update the core
        core->setFeed(newFeed);
        core->setReverse(this->reverse);
    }

    // update the RPM display
    controlPanel->setRPM((this->displaySpindleRpm) ? core->getSpindleRPM() : core->getLeadscrewRPM());

    // write data out to the display
    controlPanel->refresh();
}
