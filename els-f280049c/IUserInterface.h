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

#ifndef IUSERINTERFACE_H_
#define IUSERINTERFACE_H_

// This is a set of callbacks that the UserInterface must implement for NextionControlPanel to call
//
// It is here to avoid circular dependencies in class definitions between NextionControlPanel
// and UserInterface
class IUserInterface
{
public:
    virtual void powerButton(bool on) = 0;
    virtual void upButton() = 0;
    virtual void downButton() = 0;
    virtual void selectFeed(uint32_t index) = 0;
    virtual void inchMm(bool mm) = 0;
    virtual void feedThread(bool thread) = 0;
    virtual void forwardReverse(bool reverse) = 0;
    virtual void pageChanged(uint32_t pageId) = 0;
};

#endif /* IUSERINTERFACE_H_ */
