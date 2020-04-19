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

#include "Configuration.h"
#include "F28x_Project.h"
#include "SPIBus.h"


#define ZERO    0b1111110000000000 // 0
#define ONE     0b0110000000000000 // 1
#define TWO     0b1101101000000000 // 2
#define THREE   0b1111001000000000 // 3
#define FOUR    0b0110011000000000 // 4
#define FIVE    0b1011011000000000 // 5
#define SIX     0b1011111000000000 // 6
#define SEVEN   0b1110000000000000 // 7
#define EIGHT   0b1111111000000000 // 8
#define NINE    0b1111011000000000 // 9
#define POINT   0b0000000100000000 // .
#define BLANK   0b0000000000000000

#define LETTER_A 0b1110111000000000
#define LETTER_B 0b0011111000000000
#define LETTER_C 0b1001110000000000
#define LETTER_D 0b0111101000000000
#define LETTER_E 0b1001111000000000
#define LETTER_F 0b1000111000000000
#define LETTER_G 0b1011110000000000
#define LETTER_H 0b0110111000000000
#define LETTER_I 0b0000110000000000
#define LETTER_J 0b0111100000000000
#define LETTER_K 0b1010111000000000
#define LETTER_L 0b0001110000000000
#define LETTER_M 0b1010100000000000
#define LETTER_N 0b1110110000000000
#define LETTER_O 0b1111110000000000
#define LETTER_P 0b1100111000000000
#define LETTER_Q 0b1110011000000000
#define LETTER_R 0b1100110000000000
#define LETTER_S 0b1011011000000000
#define LETTER_T 0b0001111000000000
#define LETTER_U 0b0111110000000000
#define LETTER_V 0b0111010000000000
#define LETTER_W 0b0101010000000000
#define LETTER_X 0b0110110000000000
#define LETTER_Y 0b0111011000000000
#define LETTER_Z 0b1101001000000000

#define DASH 0b0000001000000000

#define LED_TPI 1
#define LED_INCH (1<<1)
#define LED_MM (1<<2)
#define LED_THREAD (1<<3)
#define LED_FEED (1<<4)
#define LED_REVERSE (1<<5)
#define LED_FORWARD (1<<6)
#define LED_POWER (1<<7)

struct LED_BITS
{
    Uint16 TPI:1;
    Uint16 INCH:1;
    Uint16 MM:1;
    Uint16 THREAD:1;
    Uint16 FEED:1;
    Uint16 REVERSE:1;
    Uint16 FORWARD:1;
    Uint16 POWER:1;
};

typedef union LED_REG
{
    Uint16 all;
    struct LED_BITS bit;
} LED_REG;

struct KEY_BITS
{
    Uint16 UP:1;
    Uint16 reserved1:1;
    Uint16 DOWN:1;
    Uint16 IN_MM:1;
    Uint16 FEED_THREAD:1;
    Uint16 FWD_REV:1;
    Uint16 SET:1;
    Uint16 POWER:1;
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

    // Current RPM value; 4 decimal digits
    Uint16 rpm;

    // RPM Samples
    Uint16 rpm_samples[RPM_DISPLAY_SAMPLE_SIZE];

    // Current displayed setting value, 4 digits
    const Uint16 *value;

    // Current LED states
    LED_REG leds;

    // current key states
    KEY_REG keys;

    // current override message, or NULL if none
    const Uint16 *message;

    // brightness, levels 1-8, 0=off
    Uint16 brightness;

    // Derived state, calculated internally
    Uint16 sevenSegmentData[8];

    // dummy register, for SPI
    Uint16 dummy;

    void resetRPMSamples(void);
    void decomposeRPM(void);
    void decomposeValue(void);
    KEY_REG readKeys(void);
    Uint16 lcd_char(Uint16 x);
    void sendByte(Uint16 data);
    Uint16 receiveByte(void);
    void sendData(void);
    Uint16 reverse_byte(Uint16 x);
    void initSpi();
    void configureSpiBus(void);
    Uint16 addRPMSample(Uint16 rpmSample);

public:
    ControlPanel(SPIBus *spiBus);

    // initialize the hardware for operation
    void initHardware(void);

    // poll the keys and return a mask
    KEY_REG getKeys(void);

    // set the RPM value to display
    void setRPM(Uint16 rpm);

    // set the value to display
    void setValue(const Uint16 *value);

    // set the LED states
    void setLEDs(LED_REG leds);

    // set a message that overrides the display, 8 characters required
    void setMessage(const Uint16 *message);

    // set a brightness value, 0 (off) to 8 (max)
    void setBrightness(Uint16 brightness);

    // refresh the hardware display
    void refresh(void);
};


inline void ControlPanel :: setRPM(Uint16 rpm)
{
    this->rpm = this->addRPMSample(rpm);
}

inline void ControlPanel :: setValue(const Uint16 *value)
{
    this->value = value;
}

inline void ControlPanel :: setLEDs(LED_REG leds)
{
    this->leds = leds;
}


#endif // __CONTROL_PANEL_H
