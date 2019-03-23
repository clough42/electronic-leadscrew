#ifndef __ENCODER_H
#define __ENCODER_H

#include "DSP28x_Project.h"

void Encoder_Init(void);
Uint16 Encoder_GetRPM(void);

inline Uint32 Encoder_GetPosition()
{
    return EQep1Regs.QPOSCNT;
}


#endif // __ENCODER_H
