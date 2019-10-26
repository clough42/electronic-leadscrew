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


#ifndef __CONTROL_PANEL_H
#define __CONTROL_PANEL_H

#include "F28x_Project.h"
#include "SPIBus.h"


struct LED_BITS
{
    Uint16 VREG_RED:1;
    Uint16 VREG_GREEN:1;
    Uint16 STEP_RED:1;
    Uint16 STEP_GREEN:1;
    Uint16 ALM_RED:1;
    Uint16 ALM_GREEN:1;
    Uint16 EEPROM_RED:1;
    Uint16 EEPROM_GREEN:1;
    Uint16 A:1;
    Uint16 B:1;
    Uint16 C:1;
    Uint16 D:1;
};

typedef union LED_REG
{
    Uint16 all;
    struct LED_BITS bit;
} LED_REG;

struct KEY_BITS
{
    Uint16 KS6X:1;
    Uint16 KS6K1:1;
    Uint16 KS6K2:1;
    Uint16 KS6K3:1;
    Uint16 KS5X:1;
    Uint16 KS5K1:1;
    Uint16 KS5K2:1;
    Uint16 KS5K3:1;
};

typedef union KEY_REG
{
    Uint16 all;
    struct KEY_BITS bit;
} KEY_REG;

class ControlPanel
{
private:
    // Common SPI Bus
    SPIBus *spiBus;

    // Current LED states
    LED_REG leds;

    // current key states
    KEY_REG keys;

    // brightness, levels 1-8, 0=off
    Uint16 brightness;

    // decomposed display data
    Uint16 displayData[16];

    // dummy register, for SPI
    Uint16 dummy;

    KEY_REG readKeys(void);
    void sendByte(Uint16 data);
    Uint16 receiveByte(void);
    void sendData(void);
    Uint16 reverse_byte(Uint16 x);
    void initSpi();
    void configureSpiBus(void);

public:
    ControlPanel(SPIBus *spiBus);

    // initialize the hardware for operation
    void initHardware(void);

    KEY_REG getKeys(void);

    void setLeds(LED_REG leds);

    // set a brightness value, 0 (off) to 8 (max)
    void setBrightness(Uint16 brightness);

    // refresh the hardware display
    void refresh(void);
};


#endif // __CONTROL_PANEL_H
