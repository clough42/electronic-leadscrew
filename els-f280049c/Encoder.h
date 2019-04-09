#ifndef __ENCODER_H
#define __ENCODER_H

#include "F28x_Project.h"


#define _ENCODER_MAX_COUNT 0x00ffffff


void Encoder_Init(void);
Uint16 Encoder_GetRPM(void);

inline Uint32 Encoder_GetPosition(void)
{
    return EQep1Regs.QPOSCNT;
}

inline Uint32 Encoder_GetMaxCount(void)
{
    return _ENCODER_MAX_COUNT;
}

#endif // __ENCODER_H
