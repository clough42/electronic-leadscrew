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

#ifndef NEXTIONCONTROLPANEL_H_
#define NEXTIONCONTROLPANEL_H_

#include "els.h"

// first byte of command
#define NEX_INVALID_CMD                     0x00
#define NEX_SUCCESSFUL                      0x01
#define NEX_INVALID_COMPONENT_ID            0x02
#define NEX_INVALID_PAGE_ID                 0x03
#define NEX_INVALID_PICTURE_ID              0x04
#define NEX_INVALID_FONT_ID                 0x05
#define NEX_INVALID_BAUD                    0x11
#define NEX_INVALID_VARIABLE                0x1A
#define NEX_INVALID_OPERATION               0x1B
#define NEX_TOUCH_EVENT                     0x65
#define NEX_CURRENT_PAGE_ID                 0x66
#define NEX_TOUCH_COORDINATE_AWAKE          0x67
#define NEX_TOUCH_COORDINATE_SLEEP          0x68
#define NEX_STRING_DATA                     0x70
#define NEX_NUMBER_DATA                     0x71
#define NEX_READY                           0x88
#define NEX_START_UPGRADE                   0x89

// touch type
#define NEX_EVENT_TOUCH_RELEASE             0x00            // touch release
#define NEX_EVENT_TOUCH_PRESS               0x01            // touch press

// button IDs
#define BUTTON_POWER                        17
#define BUTTON_MINUS                        20
#define BUTTON_PLUS                         21
#define RADIO_INCH                          5
#define RADIO_MM                            6
#define RADIO_FEED                          9
#define RADIO_THREAD                        10
#define RADIO_FORWARD                       13
#define RADIO_REVERSE                       14
#define SCROLL_FEED                         22

// indexes into value array
#define VALUE_POWER_BUTTON_STATE            0
#define VALUE_RADIO_MM_STATE                1
#define VALUE_RADIO_THREAD_STATE            2
#define VALUE_RADIO_REVERSE_STATE           3
#define VALUE_SCROLL_FEED_VALUE             4
#define VALUE_COUNT                         5
#define VALUE_INVALID                       0xffffffff

#define SCROLL_MAXVAL                       200

#define NEXTION_PAGE_ABOUT                  0
#define NEXTION_PAGE_FEED                   1
#define NEXTION_PAGE_THREAD                 2
#define NEXTION_PAGE_SETTINGS               3

//
// Nextion Control Panel abstracts the interactions with the Nextion HMI touch
// control panel.  It does depend on the Nextion being configured with the
// matching configuration stored in ..\nextion
//
class NextionControlPanel
{
public:
    NextionControlPanel(SerialPort *serialPort);
    virtual ~NextionControlPanel();

    // initialize with pointer back to user interface class
    void init(IUserInterface *userInterface);

    // select a specific user interface page
    void selectPage(const uint32_t pageNumber);

    // write to the status line
    void setStatus(const char *value) { this->setTextField("text_status", value); }
    void appendStatus(const char *value) { this->appendTextField("text_status", value); }

    // set the spindle RPM field
    void setSpindleRpm(const int rpm) { this->setTextField("text_rpm", rpm); }

    // set the feed rate field
    void setFeedRate(Uint16 index, const FEED_THREAD *feed);

    // set state on binary fields on the display
    void setState(bool mm, bool thread, bool reverse, bool power);

    // Force the power button into an off state.
    void setPowerOff() { this->setValue("bt_power", 0); }

    // This is used to set the number of items that the scroll bar is used to select
    // from
    void setScrollLimit(uint32_t maxIndex);

    // check for input from the device
    void checkForInput();

    void setTextField(const char *fieldName, const int value);

private:
    SerialPort *_serialPort;                        // serial port that we use for display communication
    IUserInterface *_userInterface;                 // callback to UserInterface

    // output helpers
    void finishCommand() { const char *finishSequence = "\xFF\xFF\xFF"; _serialPort->send(finishSequence); }
    void setTextField(const char *fieldName, const char *value);
    void appendTextField(const char *fieldName, const char *value);
    void setFeed(const char *feed) { this->setTextField("text_feed", feed); }
    void setValue(const char *fieldName, const int value);

    // input helpers
    void processCommand();                          // top level manager for all incoming commands
    void processTouchEvent();                       // handler for touch/button events
    void processPageId();                           // handler for page change events

    // async functions to get a value back from the display
    void getValue(const char *variable, uint32_t valueId);
    void valueChanged(uint32_t valueId, uint32_t value);

    // state changes that we learn through getValue/valueChanged
    void powerStateChange(uint32_t value);
    void inchMmStateChange(uint32_t value);
    void feedThreadStateChange(uint32_t value);
    void forwardReverseStateChange(uint32_t value);
    void scrollFeedStateChange(uint32_t value);

    // debugging help
    void debugCommandBuffer();

    // nextion state
    unsigned char _commandBuffer[64];               // command buffer from display to buffer partial commands
    uint32_t _commandBufferUsed;                    // bytes used in _commandBuffer
    uint32_t _pendingValueId;                       // value ID we are waiting on.  used between getValue() and valueChanged()
    uint32_t _pageId;                               // current nextion page 1
    uint32_t _commandCount;

    uint32_t _feedMax;                              // max value that UserInterface accepts on selectFeed
};

inline void NextionControlPanel::scrollFeedStateChange(uint32_t scrollIndex)
{
    uint32_t feedIndex = (scrollIndex * _feedMax) / SCROLL_MAXVAL;
    this->_userInterface->selectFeed(feedIndex);
}

inline void NextionControlPanel::powerStateChange(uint32_t value)
{
    _userInterface->powerButton(value != 0);
}

inline void NextionControlPanel::inchMmStateChange(uint32_t value)
{
    _userInterface->inchMm(value != 0);
}

inline void NextionControlPanel::feedThreadStateChange(uint32_t value)
{
    _userInterface->feedThread(value != 0);
}

inline void NextionControlPanel::forwardReverseStateChange(uint32_t value)
{
    _userInterface->forwardReverse(value != 0);
}

inline void NextionControlPanel::setFeedRate(Uint16 feedIndex, const FEED_THREAD *feed)
{
    uint32_t scrollIndex = (feedIndex * SCROLL_MAXVAL) / _feedMax;
    this->setValue("scroll_feed", scrollIndex);
    this->setFeed(feed->display);
}

inline void NextionControlPanel::setState(bool mm, bool thread, bool reverse, bool power)
{
    this->setValue("rd_inch", !mm);
    this->setValue("rd_mm", mm);
    this->setValue("rd_feed", !thread);
    this->setValue("rd_thread", thread);
    this->setValue("rd_forward", !reverse);
    this->setValue("rd_reverse", reverse);
    this->setValue("bt_power", power);
}

inline void NextionControlPanel::selectPage(const uint32_t pageNumber)
{
    char pageString[20];
    _serialPort->send("page ");
    itoa(pageNumber, pageString, 10);
    _serialPort->send(pageString);
    finishCommand();
}

inline void NextionControlPanel::setTextField(const char *fieldName, const char *value)
{
    _serialPort->send(fieldName);
    _serialPort->send(".txt=\"");
    _serialPort->send(value);
    _serialPort->send("\"");
    finishCommand();
}

inline void NextionControlPanel::appendTextField(const char *fieldName, const char *value)
{
    _serialPort->send(fieldName);
    _serialPort->send(".txt+=\"");
    _serialPort->send(value);
    _serialPort->send("\"");
    finishCommand();
}

inline void NextionControlPanel::setTextField(const char *fieldName, int value)
{
    char numberString[20];
    itoa(value, numberString, 10);
    _serialPort->send(fieldName);
    _serialPort->send(".txt=\"");
    _serialPort->send(numberString);
    _serialPort->send("\"");
    finishCommand();
}

inline void NextionControlPanel::setValue(const char *fieldName, int value)
{
    char numberString[20];
    itoa(value, numberString, 10);
    _serialPort->send(fieldName);
    _serialPort->send(".val=");
    _serialPort->send(numberString);
    finishCommand();
}

inline void NextionControlPanel::getValue(const char *variable, uint32_t valueId)
{
    _pendingValueId = valueId;
    _serialPort->send("get ");
    _serialPort->send(variable);
    _serialPort->send(".val");
    finishCommand();
}

inline void NextionControlPanel::setScrollLimit(uint32_t maxIndex)
{
    _feedMax = maxIndex;
}

#endif /* NEXTIONCONTROLPANEL_H_ */
