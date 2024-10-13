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


#ifndef __USERINTERFACE_H
#define __USERINTERFACE_H

#include "ControlPanel.h"
#include "Core.h"
#include "Tables.h"

typedef struct MESSAGE
{
    Uint16 message[8];
    Uint16 displayTime;
    const MESSAGE *next;
} MESSAGE;

class UserInterface
{
private:
    ControlPanel *controlPanel;
    Core *core;
    Encoder *encoder;
    FeedTableFactory *feedTableFactory;

    bool metric;
    bool thread;
    bool reverse;
    bool showAngle;

    bool isInMenu;
    Uint16 menuState, menuSubState;

    int numStarts, currentStart;

    FeedTable *feedTable;

    KEY_REG keys;

    const MESSAGE *message;
    Uint16 messageTime;

    const FEED_THREAD *loadFeedTable();
    LED_REG calculateLEDs();
    void setMessage(const MESSAGE *message);
    void overrideMessage( void );
    void clearMessage( void );

    void cycleOptions(Uint16 next, Uint16 prev); // cycle menu options

public:
    UserInterface(ControlPanel *controlPanel, Core *core, FeedTableFactory *feedTableFactory, Encoder *encoder);

    void loop( void );

    void mainLoop( Uint16 currentRpm );
    void menuLoop( Uint16 currentRpm );
    void beginMenu( void );
    void customThreadLoop( Uint16 currentRpm );
    void threadToShoulderLoop( Uint16 currentRpm );

    void panicStepBacklog( void );
};

#endif // __USERINTERFACE_H
