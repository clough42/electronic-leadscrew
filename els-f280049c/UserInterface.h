#ifndef __USERINTERFACE_H
#define __USERINTERFACE_H

#include "ControlPanel.h"
#include "Core.h"
#include "Tables.h"

class UserInterface
{
private:
    ControlPanel *controlPanel;
    Core *core;
    FeedTableFactory *feedTableFactory;

    bool metric;
    bool thread;
    bool reverse;

    FeedTable *feedTable;

    KEY_REG keys;

    const FEED_THREAD *loadFeedTable();
    LED_REG calculateLEDs(const FEED_THREAD *selectedFeed);

public:
    UserInterface(ControlPanel *controlPanel, Core *core, FeedTableFactory *feedTableFactory);
    void init( void );

    void loop( void );
};

#endif // __USERINTERFACE_H
