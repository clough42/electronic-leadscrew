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
  .message = { LETTER_E, LETTER_L, LETTER_S, DASH, ONE | POINT, FIVE | POINT, ZERO, ZERO },
  .displayTime = UI_REFRESH_RATE_HZ * 0.5
};

const MESSAGE STARTUP_MESSAGE_1 =
{
 .message = { LETTER_C, LETTER_L, LETTER_O, LETTER_U, LETTER_G, LETTER_H, FOUR, TWO },
 .displayTime = UI_REFRESH_RATE_HZ * 0.5,
 .next = &STARTUP_MESSAGE_2
};

const MESSAGE CUSTOM_THREAD =
{
 .message = { LETTER_C, LETTER_U, LETTER_S, LETTER_T, BLANK, LETTER_T, LETTER_H, LETTER_D },
 .displayTime = UI_REFRESH_RATE_HZ * 2.0
};

const MESSAGE THREAD_TO_SHOULDER =
{
 .message = { LETTER_S, LETTER_H, LETTER_O, LETTER_U, LETTER_L, LETTER_D, LETTER_E, LETTER_R },
 .displayTime = UI_REFRESH_RATE_HZ * 2.0
};

const MESSAGE END =
{
 .message = { LETTER_E, LETTER_N, LETTER_D, BLANK, BLANK, BLANK, BLANK, BLANK },
 .displayTime = UI_REFRESH_RATE_HZ * 2.0
};

const MESSAGE STOP =
{
 .message = { LETTER_S, LETTER_T, LETTER_O, LETTER_P, BLANK, BLANK, BLANK, BLANK },
 .displayTime = UI_REFRESH_RATE_HZ * 2.0
};

const MESSAGE THREAD =
{
 .message = { LETTER_T, LETTER_H, LETTER_R, LETTER_E, LETTER_A, LETTER_D, BLANK, BLANK },
 .displayTime = UI_REFRESH_RATE_HZ * 1.0
};

const MESSAGE BEGIN =
{
 .message = { LETTER_B, LETTER_E, LETTER_G, LETTER_I, LETTER_N, BLANK, BLANK, BLANK },
 .displayTime = UI_REFRESH_RATE_HZ * 1.0
};

const MESSAGE GO_SHOULDER =
{
 .message = { LETTER_G, LETTER_O, BLANK, LETTER_S, LETTER_H, LETTER_L, LETTER_D, LETTER_R },
 .displayTime = UI_REFRESH_RATE_HZ * 2.0
};

const MESSAGE GO_START =
{
 .message = { LETTER_G, LETTER_O, BLANK, LETTER_S, LETTER_T, LETTER_A, LETTER_R, LETTER_T },
 .displayTime = UI_REFRESH_RATE_HZ * 2.0
};

const MESSAGE GO_END =
{
 .message = { LETTER_G, LETTER_O, BLANK, LETTER_E, LETTER_N, LETTER_D, BLANK, BLANK },
 .displayTime = UI_REFRESH_RATE_HZ * 2.0
};

const MESSAGE RETRACT =
{
 .message = { LETTER_R, LETTER_E, LETTER_T, LETTER_R, LETTER_A, LETTER_C, LETTER_T, BLANK },
 .displayTime = UI_REFRESH_RATE_HZ * 2.0
};

const MESSAGE POSITION =
{
 .message = { LETTER_P, LETTER_O, LETTER_S, LETTER_I, LETTER_T, LETTER_I, LETTER_O, LETTER_N },
 .displayTime = UI_REFRESH_RATE_HZ * 2.0
};

const MESSAGE RPM =
{
 .message = { LETTER_R, LETTER_P, LETTER_M, BLANK, BLANK, BLANK, BLANK, BLANK },
 .displayTime = UI_REFRESH_RATE_HZ * 2.0
};

extern const MESSAGE BACKLOG_PANIC_MESSAGE_2;
const MESSAGE BACKLOG_PANIC_MESSAGE_1 =
{
 .message = { LETTER_T, LETTER_O, LETTER_O, BLANK, LETTER_F, LETTER_A, LETTER_S, LETTER_T },
 .displayTime = UI_REFRESH_RATE_HZ * .5,
 .next = &BACKLOG_PANIC_MESSAGE_2
};
const MESSAGE BACKLOG_PANIC_MESSAGE_2 =
{
 .message = { BLANK, LETTER_R, LETTER_E, LETTER_S, LETTER_E, LETTER_T, BLANK, BLANK },
 .displayTime = UI_REFRESH_RATE_HZ * .5,
 .next = &BACKLOG_PANIC_MESSAGE_1
};



const Uint16 VALUE_BLANK[4] = { BLANK, BLANK, BLANK, BLANK };

UserInterface :: UserInterface(ControlPanel *controlPanel, Core *core, FeedTableFactory *feedTableFactory, Encoder *encoder)
{
    this->controlPanel = controlPanel;
    this->core = core;
    this->feedTableFactory = feedTableFactory;
    this->encoder = encoder;

    this->metric = true; // start out with metric
    this->thread = false; // start out with feeds
    this->reverse = false; // start out going forward
    this->showAngle = false; // start out showing RPM

    this->feedTable = NULL;

    this->keys.all = 0xff;

    this->isInMenu = false;

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

void UserInterface :: clearMessage( void )
{
    this->message = NULL;
    this->messageTime = 0;
    controlPanel->setMessage(NULL);
}

void UserInterface :: panicStepBacklog( void )
{
    setMessage(&BACKLOG_PANIC_MESSAGE_1);
}

void UserInterface :: loop( void )
{
    // read the RPM up front so we can use it to make decisions
    Uint16 currentRpm = core->getRPM();

    // read the current spindle position to keep this up to date
    Uint16 currentSpindleAngle = encoder->getSpindleAngle();

    // display an override message, if there is one
    overrideMessage();

    // read keypresses from the control panel
    keys = controlPanel->getKeys();

    // handle appropriate loop
    if (isInMenu)
        menuLoop(currentRpm);
    else
        mainLoop(currentRpm);

    // update the control panel
    controlPanel->setLEDs(calculateLEDs());
    controlPanel->setValue(feedTable->current()->display);
    controlPanel->setRPM(currentRpm);
    controlPanel->setSpindleAngle(currentSpindleAngle);

    if( ! core->isPowerOn() )
    {
        controlPanel->setValue(VALUE_BLANK);
    }

    controlPanel->refresh(showAngle);
}


void UserInterface :: mainLoop( Uint16 currentRpm )
{
    // respond to keypresses
    if( currentRpm == 0 )
    {
        // these keys should only be sensitive when the machine is stopped
        if( keys.bit.POWER ) {
            this->core->setPowerOn(!this->core->isPowerOn());
            clearMessage();
        }

        // these should only work when the power is on
        if( this->core->isPowerOn() ) {
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
                beginMenu();
            }
        }
    }

#ifdef IGNORE_ALL_KEYS_WHEN_RUNNING
    if( currentRpm == 0 )
        {
#endif // IGNORE_ALL_KEYS_WHEN_RUNNING

        // these should only work when the power is on
        if( this->core->isPowerOn() ) {
            // these keys can be operated when the machine is running
            if( keys.bit.UP )
            {
                core->setFeed(feedTable->next());
            }
            if( keys.bit.DOWN )
            {
                core->setFeed(feedTable->previous());
            }
        }

#ifdef IGNORE_ALL_KEYS_WHEN_RUNNING
    }
#endif // IGNORE_ALL_KEYS_WHEN_RUNNING

}


// menu loop code

void UserInterface :: beginMenu()
{
    this->isInMenu = true;
    this->menuState = 0;
    this->menuSubState = 0;
}


// 'set' menu states, note spacing to allow for 'sub-states'.
enum menuStates {kCustomThread = 0, kThreadToShoulder = 0x10, kShowPosition = 0x20,  kQuitMenu = 0x100};

void UserInterface :: cycleOptions(Uint16 next, Uint16 prev)
{
    // if set then start loop
    if ( keys.bit.SET )
        this->menuState++;

    // if down then next option on menu
    else if (keys.bit.DOWN)
    {
        this->menuState = next;
        this->menuSubState = 0;
    }

    // if up then prev option on menu
    else if (keys.bit.UP)
    {
        this->menuState = prev;
        this->menuSubState = 0;
    }

    // if timeout then end menu
    else if (this->messageTime == 0)
        this->menuState = kQuitMenu;
}


void UserInterface :: menuLoop( Uint16 currentRpm )
{
    switch (this->menuState)
    {
        // custom threads
    case kCustomThread:     // init
        setMessage(&CUSTOM_THREAD);
        this-menuState++;
        break;
    case kCustomThread+1:   // wait for keypress, either select this option, move to new or timeout
        cycleOptions(kShowPosition, kThreadToShoulder);  // link any other menu options here
        break;
    case kCustomThread+2:   // run loop
        customThreadLoop(currentRpm);
        break;

        // Thread to shoulder
    case kThreadToShoulder:     // init
        setMessage(&THREAD_TO_SHOULDER);
        this-menuState++;
        break;
    case kThreadToShoulder+1:   // wait for keypress, either select this option, move to new or timeout
        cycleOptions(kCustomThread, kShowPosition);  // link any other menu options here
        break;
    case kThreadToShoulder+2:   // run loop
        threadToShoulderLoop(currentRpm);
        break;

        // Spindle position / RPM
    case kShowPosition:     // init
        setMessage(showAngle ? &RPM : &POSITION);
        this-menuState++;
        break;
    case kShowPosition+1:   // wait for keypress, either select this option, move to new or timeout
        cycleOptions(kThreadToShoulder, kCustomThread);  // link any other menu options here
        break;
    case kShowPosition+2:   // run loop
        showAngle = !showAngle;
        clearMessage();
        this->menuState = kQuitMenu;
        break;

    // exit setup
    case kQuitMenu:
        this->isInMenu = false;
        break;
    }
}


void UserInterface :: customThreadLoop( Uint16 currentRpm )
{
    switch (this->menuSubState)
    {
    // initialise
    case 0:
        clearMessage();
        feedTableFactory->useCustomPitch = true;
        this->menuSubState = 1;
        break;

        // edit custom pitch 100's
    case 1:
        feedTableFactory->flashCustomDigit(1);

        if( keys.bit.UP )
            feedTableFactory->incCustomDigit(1);
        if( keys.bit.DOWN )
            feedTableFactory->decCustomDigit(1);

        if ( keys.bit.SET )
            this->menuSubState = 2;
        break;

        // edit custom pitch 10's
    case 2:
        feedTableFactory->flashCustomDigit(2);

        if( keys.bit.UP )
            feedTableFactory->incCustomDigit(2);
        if( keys.bit.DOWN )
            feedTableFactory->decCustomDigit(2);

        if ( keys.bit.SET )
            this->menuSubState = 3;
        break;

        // edit custom pitch 1's
    case 3:
        feedTableFactory->flashCustomDigit(3);

        if( keys.bit.UP )
            feedTableFactory->incCustomDigit(3);
        if( keys.bit.DOWN )
            feedTableFactory->decCustomDigit(3);

        if ( keys.bit.SET )
            this->menuSubState = 4;
        break;

    case 4:
        feedTableFactory->flashCustomOff();
        core->setFeed(loadFeedTable());

        this->isInMenu = false;
        break;
    }
}


MESSAGE DEBUG =
{
  .message = { DASH, DASH, DASH, DASH, DASH, DASH, DASH, DASH },
  .displayTime = UI_REFRESH_RATE_HZ * 1.5
};


void UserInterface :: threadToShoulderLoop( Uint16 currentRpm )
{
    int32 dist;

    // check for exit from thread to shoulder
    if (keys.bit.POWER)
        this->menuSubState = 10;

    // debug
    if (keys.bit.IN_MM)
    {
        if (this->menuSubState < 22)
            this->menuSubState = 22;
        else
            this->menuSubState = 1;
    }

    switch (this->menuSubState)
    {
        // prompt user to 'go to shoulder'
    case 0:
        setMessage(&GO_SHOULDER);
        if (keys.bit.SET)
        {
            core->setShoulder();
            this->menuSubState = 1;
        }
        break;

        // prompt user to 'go to start'
    case 1:
        setMessage(&GO_START);
        if (keys.bit.SET)
        {
            core->setStart();
            core->threadToShoulder(true);
            setMessage(&BEGIN);
            this->menuSubState = 2;
        }
        break;

        // todo: ask for number of thread starts?
    case 2:
        this->menuSubState = 3;
        break;

        // begin threading
    case 3:
        setMessage(&BEGIN);
        this->menuSubState = 4;
        break;

        // wait until we reach the shoulder
    case 4:
        if (core->isAtShoulder())
            this->menuSubState = 5;
        break;

        // at shoulder, wait for user to stop machine
    case 5:
        if (currentRpm == 0)
            this->menuSubState = 6;
        else
            setMessage(&STOP);
        break;

        // stopped wait for retract
    case 6:
        setMessage(&RETRACT);
        if (keys.bit.SET)
            this->menuSubState = 7;

        if (core->isAtStart())
        {
            this->menuSubState = 3;
        }
        break;

        // automatically move to start and repeat
    case 7:
        this->menuSubState = 3;
        break;

        // finished so quit
    case 10:
        clearMessage();
        core->threadToShoulder(false);
        this->isInMenu = false;
        break;


        // debug display
    case 22:
        dist = core->getDistance();
        DEBUG.message[0] = feedTableFactory->valueToDigit(dist >> 28 & 0xf) | POINT;
        DEBUG.message[1] = feedTableFactory->valueToDigit(dist >> 24 & 0xf);
        DEBUG.message[2] = feedTableFactory->valueToDigit(dist >> 20 & 0xf);
        DEBUG.message[3] = feedTableFactory->valueToDigit(dist >> 16 & 0xf);
        DEBUG.message[4] = feedTableFactory->valueToDigit(dist >> 12 & 0xf);
        DEBUG.message[5] = feedTableFactory->valueToDigit(dist >> 8 & 0xf);
        DEBUG.message[6] = feedTableFactory->valueToDigit(dist >> 4 & 0xf);
        DEBUG.message[7] = feedTableFactory->valueToDigit(dist & 0xf);
        setMessage(&DEBUG);

        if (keys.bit.DOWN)
            menuSubState = 2;
        if (keys.bit.UP)
            menuSubState = 23;
        break;

    case 23:
        dist = core->getSpindle();
        DEBUG.message[0] = feedTableFactory->valueToDigit(dist >> 28 & 0xf);
        DEBUG.message[1] = feedTableFactory->valueToDigit(dist >> 24 & 0xf) | POINT;
        DEBUG.message[2] = feedTableFactory->valueToDigit(dist >> 20 & 0xf);
        DEBUG.message[3] = feedTableFactory->valueToDigit(dist >> 16 & 0xf);
        DEBUG.message[4] = feedTableFactory->valueToDigit(dist >> 12 & 0xf);
        DEBUG.message[5] = feedTableFactory->valueToDigit(dist >> 8 & 0xf);
        DEBUG.message[6] = feedTableFactory->valueToDigit(dist >> 4 & 0xf);
        DEBUG.message[7] = feedTableFactory->valueToDigit(dist & 0xf);
        setMessage(&DEBUG);

        if (keys.bit.UP)
            menuSubState = 24;
        if (keys.bit.DOWN)
            menuSubState = 22;
        break;

    case 24:
        dist = core->getShoulder();
        DEBUG.message[0] = feedTableFactory->valueToDigit(dist >> 28 & 0xf);
        DEBUG.message[1] = feedTableFactory->valueToDigit(dist >> 24 & 0xf);
        DEBUG.message[2] = feedTableFactory->valueToDigit(dist >> 20 & 0xf) | POINT;
        DEBUG.message[3] = feedTableFactory->valueToDigit(dist >> 16 & 0xf);
        DEBUG.message[4] = feedTableFactory->valueToDigit(dist >> 12 & 0xf);
        DEBUG.message[5] = feedTableFactory->valueToDigit(dist >> 8 & 0xf);
        DEBUG.message[6] = feedTableFactory->valueToDigit(dist >> 4 & 0xf);
        DEBUG.message[7] = feedTableFactory->valueToDigit(dist & 0xf);
        setMessage(&DEBUG);

        if (keys.bit.UP)
            menuSubState = 25;
        if (keys.bit.DOWN)
            menuSubState = 23;
        break;

    case 25:
        dist = core->getPosition();
        DEBUG.message[0] = feedTableFactory->valueToDigit(dist >> 28 & 0xf);
        DEBUG.message[1] = feedTableFactory->valueToDigit(dist >> 24 & 0xf);
        DEBUG.message[2] = feedTableFactory->valueToDigit(dist >> 20 & 0xf);
        DEBUG.message[3] = feedTableFactory->valueToDigit(dist >> 16 & 0xf) | POINT;
        DEBUG.message[4] = feedTableFactory->valueToDigit(dist >> 12 & 0xf);
        DEBUG.message[5] = feedTableFactory->valueToDigit(dist >> 8 & 0xf);
        DEBUG.message[6] = feedTableFactory->valueToDigit(dist >> 4 & 0xf);
        DEBUG.message[7] = feedTableFactory->valueToDigit(dist & 0xf);
        setMessage(&DEBUG);

        if (keys.bit.UP)
            menuSubState = 26;
        if (keys.bit.DOWN)
            menuSubState = 24;
        break;

    case 26:
        dist = core->getDesired();
        DEBUG.message[0] = feedTableFactory->valueToDigit(dist >> 28 & 0xf);
        DEBUG.message[1] = feedTableFactory->valueToDigit(dist >> 24 & 0xf);
        DEBUG.message[2] = feedTableFactory->valueToDigit(dist >> 20 & 0xf);
        DEBUG.message[3] = feedTableFactory->valueToDigit(dist >> 16 & 0xf);
        DEBUG.message[4] = feedTableFactory->valueToDigit(dist >> 12 & 0xf) | POINT;
        DEBUG.message[5] = feedTableFactory->valueToDigit(dist >> 8 & 0xf);
        DEBUG.message[6] = feedTableFactory->valueToDigit(dist >> 4 & 0xf);
        DEBUG.message[7] = feedTableFactory->valueToDigit(dist & 0xf);
        setMessage(&DEBUG);

        if (keys.bit.UP)
            menuSubState = 27;
        if (keys.bit.DOWN)
            menuSubState = 25;
        break;

    case 27:
        dist = core->getStart();
        DEBUG.message[0] = feedTableFactory->valueToDigit(dist >> 28 & 0xf);
        DEBUG.message[1] = feedTableFactory->valueToDigit(dist >> 24 & 0xf);
        DEBUG.message[2] = feedTableFactory->valueToDigit(dist >> 20 & 0xf);
        DEBUG.message[3] = feedTableFactory->valueToDigit(dist >> 16 & 0xf);
        DEBUG.message[4] = feedTableFactory->valueToDigit(dist >> 12 & 0xf);
        DEBUG.message[5] = feedTableFactory->valueToDigit(dist >> 8 & 0xf) | POINT;
        DEBUG.message[6] = feedTableFactory->valueToDigit(dist >> 4 & 0xf);
        DEBUG.message[7] = feedTableFactory->valueToDigit(dist & 0xf);
        setMessage(&DEBUG);

        if (keys.bit.DOWN)
            menuSubState = 26;
        break;
    }
}
