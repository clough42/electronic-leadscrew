#ifndef __CONTROL_PANEL_H
#define __CONTROL_PANEL_H

#include "DSP28x_Project.h"

#define CONTROL_PANEL_REFRESH_US 10000

struct LED_BITS
{
    Uint16 TPI:1;
    Uint16 INCH:1;
    Uint16 MM:1;
    Uint16 reservedA:1;
    Uint16 THREAD:1;
    Uint16 FEED:1;
    Uint16 reservedB:1;
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
    Uint16 value;

    // Current LED states
    union LED_REG leds;

    // current key states
    union KEY_REG keys;

};

extern struct CONTROL_PANEL_STATE _controlpanel_state;


void ControlPanel_Init(void);
void ControlPanel_Refresh(void);

inline void ControlPanel_SetRPM(Uint16 rpm)
{
    _controlpanel_state.rpm = rpm;
}

inline void ControlPanel_SetValue(Uint16 value)
{
    _controlpanel_state.value = value;
}

inline union KEY_REG ControlPanel_GetKeys()
{
    return _controlpanel_state.keys;
}


#endif // __STEPPERDRIVE_H
