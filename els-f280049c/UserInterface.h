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

#ifndef __USERINTERFACE_H
#define __USERINTERFACE_H

#include "NextionControlPanel.h"
#include "Core.h"
#include "Tables.h"

#define VERSION_STRING "version 2.0"

class UserInterface : IUserInterface
{
public:
    UserInterface(NextionControlPanel *controlPanel, Core *core, FeedTableFactory *feedTableFactory);

    void loop(void);

private:
    NextionControlPanel *controlPanel;
    Core *core;
    FeedTableFactory *feedTableFactory;

    bool metric;
    bool thread;
    bool reverse;
    bool power;
    bool displaySpindleRpm;
    uint32_t messageClearCount;
    Uint16 checkInterval;
    bool welcomePage;

    FeedTable *feedTable;

    const FEED_THREAD *loadFeedTable();

    void setStatus(const char *msg, uint32_t seconds);
    void setFeedTable();

    // from IUserInterface
    virtual void powerButton(bool on);
    virtual void upButton();
    virtual void downButton();
    virtual void selectFeed(uint32_t index);
    virtual void inchMm(bool mm);
    virtual void feedThread(bool thread);
    virtual void forwardReverse(bool reverse);
    virtual void pageChanged(uint32_t pageId);
};

inline void UserInterface::setStatus(const char *msg, uint32_t seconds)
{
    controlPanel->setStatus(msg);
    this->messageClearCount = seconds * UI_REFRESH_RATE_HZ;
}


#endif // __USERINTERFACE_H
