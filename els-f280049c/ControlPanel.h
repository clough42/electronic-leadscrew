#ifndef __CONTROL_PANEL_H
#define __CONTROL_PANEL_H

#include "F28x_Project.h"

#define CONTROL_PANEL_REFRESH_US 10000

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
    Uint16 UP:2;
    Uint16 DOWN:2;
    Uint16 reservedA:1;
    Uint16 UNIT:1;
    Uint16 MODE:1;
    Uint16 SET:1;
};

typedef union KEY_REG
{
    Uint16 all;
    struct KEY_BITS bit;
} KEY_REG;


class ControlPanel
{
private:
    // Current RPM value; 4 decimal digits
    Uint16 rpm;

    // Current displayed setting value, 4 digits max
    long double value;

    // Current LED states
    LED_REG leds;

    // current key states
    KEY_REG keys;

    //
    // Derived state, calculated internally
    //
    Uint16 sevenSegmentData[8];

    // dummy register, for SPI
    Uint16 dummy;

    void decomposeRPM(void);
    void decomposeValue(void);
    KEY_REG readKeys(void);
    Uint16 lcd_char(Uint16 x);
    void sendByte(Uint16 data);
    Uint16 receiveByte(void);
    void sendData(void);
    Uint16 reverse_byte(Uint16 x);

public:
    ControlPanel(void);
    void init(void);
    KEY_REG refresh(void);
    void setRPM(Uint16 rpm);
    void setValue(long double value);
    void setLEDs(Uint16 leds);

};


inline void ControlPanel :: setRPM(Uint16 rpm)
{
    this->rpm = rpm;
}

inline void ControlPanel :: setValue(long double value)
{
    this->value = value;
}

inline void ControlPanel :: setLEDs(Uint16 leds)
{
    this->leds.all = leds;
}


#endif // __STEPPERDRIVE_H
