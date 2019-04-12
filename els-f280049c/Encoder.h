#ifndef __ENCODER_H
#define __ENCODER_H

#include "F28x_Project.h"

#define _ENCODER_MAX_COUNT 0x00ffffff


class Encoder
{
private:
    Uint32 previous;
    Uint16 rpm;

public:
    Encoder( void );
    void init( void );
    Uint16 getRPM( void );
    Uint32 getPosition( void );
    Uint32 getMaxCount( void );
};


inline Uint32 Encoder :: getPosition(void)
{
    return EQep1Regs.QPOSCNT;
}

inline Uint32 Encoder :: getMaxCount(void)
{
    return _ENCODER_MAX_COUNT;
}



#endif // __ENCODER_H
