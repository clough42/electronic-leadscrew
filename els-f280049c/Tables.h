#ifndef __TABLES_H
#define __TABLES_H

#include "ControlPanel.h"
#include "device_support_f28004x/common/include/F28x_Project.h"


typedef struct FEED_THREAD
{
    Uint16 display[4];
    union LED_REG leds;
    Uint32 numerator;
    Uint32 denominator;

} FEED_THREAD;

#endif // __TABLES_H
