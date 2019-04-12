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

    FEED_THREAD current(void);
    FEED_THREAD next(void);
    FEED_THREAD previous(void);
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

    FeedTable getInchThreads(void);
    FeedTable getInchFeeds(void);
    FeedTable getMetricThreads(void);
    FeedTable getMetricFeeds(void);
};


#endif // __TABLES_H
