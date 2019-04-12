#ifndef __TABLES_H
#define __TABLES_H

#include "F28x_Project.h"
#include "ControlPanel.h"



typedef struct FEED_THREAD
{
    Uint16 display[4];
    union LED_REG leds;
    Uint32 numerator;
    Uint32 denominator;
} FEED_THREAD;



class FeedTable
{
private:
    const FEED_THREAD *table;
    Uint16 selectedRow;
    Uint16 numRows;

public:
    FeedTable(const FEED_THREAD *table, Uint16 numRows);

    const FEED_THREAD *current(void);
    const FEED_THREAD *next(void);
    const FEED_THREAD *previous(void);
};


class FeedTableFactory
{
private:
    FeedTable inchThreads;
    FeedTable inchFeeds;
    FeedTable metricThreads;
    FeedTable metricFeeds;

public:
    FeedTableFactory(void);

    FeedTable *getFeedTable(bool metric, bool thread);
};


#endif // __TABLES_H
