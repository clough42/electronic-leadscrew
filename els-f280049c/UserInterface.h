#ifndef __USERINTERFACE_H
#define __USERINTERFACE_H

#include "ControlPanel.h"
#include "Core.h"

class UserInterface
{
private:
    ControlPanel *controlPanel;
    Core *core;

    long double feed;
    KEY_REG keys;

public:
    UserInterface(ControlPanel *controlPanel, Core *core);
    void init( void );

    void loop( void );
};

#endif // __USERINTERFACE_H
