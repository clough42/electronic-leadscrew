#ifndef __CONTROL_PANEL_H
#define __CONTROL_PANEL_H

#include "DSP28x_Project.h"

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

union LED_REG
{
    Uint16 all;
    struct LED_BITS bit;
};

struct KEY_BITS
{
    Uint16 UP:2;
    Uint16 DOWN:2;
    Uint16 reservedA:1;
    Uint16 UNIT:1;
    Uint16 MODE:1;
    Uint16 SET:1;
};

union KEY_REG
{
    Uint16 all;
    struct KEY_BITS bit;
};

struct CONTROL_PANEL_STATE {

    // Current RPM value; 4 decimal digits
    Uint16 rpm;

    // Current displayed setting value, 4 digits max
    long double value;

    // Current LED states
    union LED_REG leds;

    // current key states
    union KEY_REG keys;

    //
    // Derived state, calculated internally
    //
    Uint16 sevenSegmentData[8];

};

extern struct CONTROL_PANEL_STATE _controlpanel_state;


void ControlPanel_Init(void);
union KEY_REG ControlPanel_Refresh();


inline void ControlPanel_SetRPM(Uint16 rpm)
{
    _controlpanel_state.rpm = rpm;
}

inline void ControlPanel_SetValue(long double value)
{
    _controlpanel_state.value = value;
}

inline void ControlPanel_SetLEDs(Uint16 leds)
{
    _controlpanel_state.leds.all = leds;
}


#endif // __STEPPERDRIVE_H
