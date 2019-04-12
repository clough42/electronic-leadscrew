#include "UserInterface.h"


UserInterface :: UserInterface(ControlPanel *controlPanel, Core *core)
{
    this->controlPanel = controlPanel;
    this->core = core;

    this->feed = 200.0 * 8.0 / 4096.0;
    this->keys.all = 0xff;
}

void UserInterface :: init( void )
{

}

void UserInterface :: loop( void )
{
    controlPanel->setLEDs(keys.all);
    controlPanel->setValue(feed);
    controlPanel->setRPM(core->getRPM());

    keys = controlPanel->refresh();

    //
    // Respond to keypresses
    //
    if( keys.bit.UP ) {
        feed += 0.001;
        if( feed > 0.999 ) feed = 0.999;
    }
    if( keys.bit.DOWN ) {
        feed -= 0.001;
        if( feed < 0.0 ) feed = 0.0;
    }

    core->setFeed(feed);
}
