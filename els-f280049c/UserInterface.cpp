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

#include "UserInterface.h"

UserInterface :: UserInterface(NextionControlPanel *controlPanel, Core *core, FeedTableFactory *feedTableFactory)
{
    this->controlPanel = controlPanel;
    this->core = core;
    this->feedTableFactory = feedTableFactory;

    this->metric = false;           // start out with imperial
    this->thread = false;           // start out with feeds
    this->reverse = false;          // start out going forward
    this->power = false;            // power on by default
    this->messageClearCount = 2 * UI_REFRESH_RATE_HZ;
    this->welcomePage = true;       // we're showing the logo page

    this->feedTable = NULL;

    this->checkInterval = 0;
}

const FEED_THREAD *UserInterface::loadFeedTable()
{
    // load the feed table
    this->feedTable = this->feedTableFactory->getFeedTable(this->metric, this->thread);
    // configure the user interface to handle this feed table
    this->controlPanel->setScrollLimit(this->feedTable->count() - 1);
    this->controlPanel->setFeedRate(this->feedTable->index(), this->feedTable->current());
    // return selected entry to user
    return this->feedTable->current();
}

void UserInterface::setStatus(const char *msg, uint32_t seconds)
{
    controlPanel->setStatus(msg);
    this->messageClearCount = seconds * UI_REFRESH_RATE_HZ;
}

//
// Core user interface loop.  This is called at UI_REFRESH_RATE_HZ
void UserInterface :: loop( void )
{
    // clear status if it's time
    if (this->messageClearCount > 0)
    {
        this->messageClearCount--;
        if (this->messageClearCount == 0)
        {
            if (this->welcomePage)
            {
                controlPanel->selectPage(1);
                this->welcomePage = false;
                loadFeedTable();
                this->setStatus("version 2.0", 5);
            }

            this->setStatus("ready", 0);
        }
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
            this->setStatus("Alarm on stepper drive", 5);
            controlPanel->setPowerOff();
        }
        else if (core->isOverShutoffSpeed())
        {
            this->setStatus("Error: Too fast", 5);
            controlPanel->setPowerOff();
        }
        else if (core->isOverWarningSpeed())
        {
            this->setStatus("Warning: Close to speed limit", 1);
        }
    }

    // update the RPM display
    uint16_t spindleRpm = core->getSpindleRPM();
    controlPanel->setSpindleRpm(spindleRpm);

    // put useful status on the status line when it's otherwise idle
    if (messageClearCount == 0)
    {
        if (!this->power)
        {
            controlPanel->setStatus("leadscrew off");
        }
        else if (spindleRpm == 0)
        {
            controlPanel->setStatus("idle");
        }
        else
        {
            char buffer[32];
            itoa(core->getLeadscrewRPM(), buffer, 10);
            controlPanel->setStatus("leadscrew rpm: ");
            controlPanel->appendStatus(buffer);
        }
    }

    // read input from the control panel
    controlPanel->checkForInput();

    /*
    if (this->power != controlPanel->_stepperPower)
    {
        this->power = controlPanel->_stepperPower;
        GPIO_CLEAR_STEP;
        GPIO_CLEAR_DIRECTION;
        if (this->power)
        {
            GPIO_SET_ENABLE;
            this->messageClearCount = 0;
        }
        else
        {
            GPIO_CLEAR_ENABLE;
        }
    }

    if (this->metric != controlPanel->_mm)
    {
        this->metric = controlPanel->_mm;
        newFeed = loadFeedTable();
    }

    if (this->thread != controlPanel->_thread)
    {
        this->thread = controlPanel->_thread;
        newFeed = loadFeedTable();
    }

    if (this->reverse != controlPanel->_reverse)
    {
        this->reverse = controlPanel->_reverse;
        core->setReverse(this->reverse);
    }
    */

    /*
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
    */

    /*
    // if we have changed the feed
    if( newFeed != NULL ) {
        // update the display
        controlPanel->setFeedTable(this->feedTable);

        // update the core
        core->setFeed(newFeed);
        core->setReverse(this->reverse);
    }*/

}

void UserInterface::powerButton(bool powerOn)
{
    this->power = powerOn;
    GPIO_CLEAR_STEP;
    GPIO_CLEAR_DIRECTION;
    if (this->power)
    {
        GPIO_SET_ENABLE;
        this->messageClearCount = 0;
    }
    else
    {
        GPIO_CLEAR_ENABLE;
    }
}

void UserInterface::upButton(void)
{
    const FEED_THREAD *feed = this->feedTable->next();
    controlPanel->setFeedRate(this->feedTable->index(), this->feedTable->current());
}

void UserInterface::downButton(void)
{
    const FEED_THREAD *feed = this->feedTable->previous();
    controlPanel->setFeedRate(this->feedTable->index(), this->feedTable->current());
}

void UserInterface::selectFeed(uint32_t index)
{
    const FEED_THREAD *feed = this->feedTable->select(index);
    controlPanel->setFeedRate(this->feedTable->index(), this->feedTable->current());
}

void UserInterface::inchMm(bool metric)
{
    // toggles metric or inch mode
    this->metric = metric;
    const FEED_THREAD *newFeed = loadFeedTable();
    core->setFeed(newFeed);
}

void UserInterface::feedThread(bool thread)
{
    // toggles feed or threading mode
    this->thread = thread;
    const FEED_THREAD *newFeed = loadFeedTable();
    core->setFeed(newFeed);
}

void UserInterface::forwardReverse(bool reverse)
{
    // toggles forward or reverse
    this->reverse = reverse;
    const FEED_THREAD *newFeed = loadFeedTable();
    core->setFeed(newFeed);
    core->setReverse(this->reverse);
}

void UserInterface::pageChanged(uint32_t pageId)
{
    if (pageId == 1)
    {
        controlPanel->setState(this->metric, this->thread, this->reverse, this->power);
        if (this->feedTable == NULL)
        {
            this->loadFeedTable();
        }
        else
        {
            this->controlPanel->setFeedRate(this->feedTable->index(), this->feedTable->current());
        }
        controlPanel->setSpindleRpm(core->getSpindleRPM());
        this->setStatus("version 2.0", 5);
    }
}
