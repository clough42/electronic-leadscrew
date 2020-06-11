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

#include "els.h"

NextionControlPanel::NextionControlPanel(SerialPort *serialPort)
{
    _serialPort = serialPort;
    _commandBufferUsed = 0;
    _pendingValueId = VALUE_INVALID;
    _pageId = 0;
    _commandCount = 0;
}

NextionControlPanel::~NextionControlPanel()
{
    // TODO Auto-generated destructor stub
}

void NextionControlPanel::init(IUserInterface *userInterface)
{
    this->_userInterface = userInterface;
}

void NextionControlPanel::checkForInput(void)
{
    uint32_t n = _serialPort->numberBytesReady();

    for (; n > 0; n--)
    {
        unsigned char ch = _serialPort->readByte();
        //pBuffer = charToHex(ch, pBuffer);
        _commandBuffer[_commandBufferUsed++] = ch;

        // check for command finished sequence
        if (_commandBufferUsed >= 3 &&
            _commandBuffer[_commandBufferUsed - 1] == 0xff &&
            _commandBuffer[_commandBufferUsed - 2] == 0xff &&
            _commandBuffer[_commandBufferUsed - 3] == 0xff)
        {
            processCommand();
            _commandBufferUsed = 0;
        }
    }
}

// append the current command buffer (in hex) on the status line
void NextionControlPanel::debugCommandBuffer(void)
{
    if (_commandBufferUsed < 16)
    {
        char buffer[32];
        char *pBuffer = buffer;
        for (int i = 0; i < _commandBufferUsed - 3; i++) {
            pBuffer = charToHex(_commandBuffer[i], pBuffer);
            pBuffer[0] = ':';
            pBuffer++;
        }
        appendStatus(buffer);
    }
}

//
// This is the top level command handler from the display.  When
// this is called a complete command has been received and is in
// _commandBuffer.
//
// processCommand parses the command and calls a command type
// specific handler.
//
void NextionControlPanel::processCommand(void)
{
    if (_commandBuffer[0] == NEX_TOUCH_EVENT && _commandBuffer[3] == NEX_EVENT_TOUCH_RELEASE)
    {
        processTouchEvent();
    }
    else if (_commandBuffer[0] == NEX_CURRENT_PAGE_ID)
    {
        processPageId();
    }
    else if (_commandBuffer[0] == NEX_NUMBER_DATA)
    {
        uint32_t value = 0;
        value += _commandBuffer[4];
        value <<= 8;
        value += _commandBuffer[3];
        value <<= 8;
        value += _commandBuffer[2];
        value <<= 8;
        value += _commandBuffer[1];
        if (_pendingValueId != VALUE_INVALID)
        {
            valueChanged(_pendingValueId, value);
        }
        _pendingValueId = VALUE_INVALID;
    }
}

//
// Handler for touch events to buttons or other objects on the screen.
//
void NextionControlPanel::processTouchEvent(void)
{
    //
    // We have two strategies here:
    // * for values where state is sourced on the display we query the display.
    //   the resulting *StateChanged() method will be called when the value is
    //   retrieved from the display.  This avoids getting out of sync, but does
    //   add a little latency.
    // * for buttons where there is no on-screen state we will dispatch directly
    //   from here.
    //
    switch (_commandBuffer[2])
    {
    case BUTTON_POWER:
        getValue("bt_power", VALUE_POWER_BUTTON_STATE);
        break;
    case RADIO_INCH:
    case RADIO_MM:
        getValue("rd_mm", VALUE_RADIO_MM_STATE);
        break;
    case RADIO_FEED:
    case RADIO_THREAD:
        getValue("rd_thread", VALUE_RADIO_THREAD_STATE);
        break;
    case RADIO_FORWARD:
    case RADIO_REVERSE:
        getValue("rd_reverse", VALUE_RADIO_REVERSE_STATE);
        break;
    case SCROLL_FEED:
        getValue("scroll_feed", VALUE_SCROLL_FEED_VALUE);
        break;
    case BUTTON_MINUS:
        _userInterface->downButton();
        break;
    case BUTTON_PLUS:
        _userInterface->upButton();
        break;
    }
}

//
// This handler is called when the display switches to a new page
//
void NextionControlPanel::processPageId(void)
{
    _pageId = _commandBuffer[1];
    _userInterface->pageChanged(_pageId);
}

//
// This handler is called after getValue is called on the display.
// getValue set _pendingValueId and we have to use that to figure out
// what was asked for.
//
void NextionControlPanel::valueChanged(uint32_t valueId, uint32_t value)
{
    // trigger events based on changing values
    switch (_pendingValueId)
    {
    case VALUE_POWER_BUTTON_STATE:
        powerStateChange(value);
        break;
    case VALUE_RADIO_MM_STATE:
        inchMmStateChange(value);
        break;
    case VALUE_RADIO_THREAD_STATE:
        feedThreadStateChange(value);
        break;
    case VALUE_RADIO_REVERSE_STATE:
        forwardReverseStateChange(value);
        break;
    case VALUE_SCROLL_FEED_VALUE:
        scrollFeedStateChange(value);
        break;
    }
}

void reverse(char *str, int n)
{
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
    {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;

    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverse(str, i);
}

char hexDigit(unsigned n)
{
    return (n > 9)? (n - 10) + 'a' : n + '0';
}

char *charToHex(unsigned char ch, char *string)
{
    string[0] = hexDigit(ch / 0x10);
    string[1] = hexDigit(ch % 0x10);
    string[2] = 0;
    return (string + 2);
}
