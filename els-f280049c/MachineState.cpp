//
// MachineState.cpp
//
// MIT License
//
// Copyright (c) 2022 Ralph Roland
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

#include "MachineState.h"
#include "EEPROM.h"

const Uint16 BIT_POWER_ON = 0x0001;
const Uint16 BIT_METRIC = 0x0002;
const Uint16 BIT_THREAD = 0x0004;
const Uint16 BIT_REVERSE = 0x0008;

MachineState :: MachineState(EEPROM *eeprom)
{
    this->eeprom = eeprom;
}

State* MachineState :: getState() {
    return &(this->state);
}

bool MachineState :: saveState()
{
    this->buffer[0] = STATE_VERSION;
    Uint16 bits = 0;
    if (this->state.powerOn) {bits |= BIT_POWER_ON;}
    if (this->state.uiState.metric) {bits |= BIT_METRIC;}
    if (this->state.uiState.thread) {bits |= BIT_THREAD;}
    if (this->state.uiState.reverse) {bits |= BIT_REVERSE;}
    this->buffer[1] = bits;
    this->buffer[2] = this->state.tabState.inchFeedRow;
    this->buffer[3] = this->state.tabState.inchThreadRow;
    this->buffer[4] = this->state.tabState.metricFeedRow;
    this->buffer[5] = this->state.tabState.metricThreadRow;
    this->buffer[6] = 0;
    this->buffer[7] = 0;
    return this->eeprom->writePage(0, this->buffer);
}

bool MachineState :: restoreState()
{
    bool statusOK = eeprom->readPage(0, this->buffer);
    if (!statusOK) {
        return false;
    }
    this->state.version = this->buffer[0];
    Uint16 bits = this->buffer[1];
    this->state.powerOn = ((bits & BIT_POWER_ON) != 0);
    this->state.uiState.metric = ((bits & BIT_METRIC) != 0);
    this->state.uiState.thread = ((bits & BIT_THREAD) != 0);
    this->state.uiState.reverse = ((bits & BIT_REVERSE) != 0);
    this->state.tabState.inchFeedRow = this->buffer[2];
    this->state.tabState.inchThreadRow = this->buffer[3];
    this->state.tabState.metricFeedRow = this->buffer[4];
    this->state.tabState.metricThreadRow = this->buffer[5];
    return true;
}

bool MachineState :: isValid()
{
    return this->state.version == STATE_VERSION;
}
