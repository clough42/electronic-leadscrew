#ifndef __ENCODER_H
#define __ENCODER_H

#include "DSP28x_Project.h"


#define RPM_CALC_RATE_HZ 10



void Encoder_Init(void);
Uint16 Encoder_GetRPM(void);

inline Uint32 Encoder_GetPosition()
{
    return EQep1Regs.QPOSCNT;
}


#endif // __ENCODER_H
