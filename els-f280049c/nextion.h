/*
 * nextion.h
 *
 *  Created on: Aug 25, 2020
 *      Author: Kent A. Vander Velden (kent.vandervelden@gmail.com)
 */

#ifndef NEXTION_H_
#define NEXTION_H_

#include "Tables.h"
#include "ControlPanel.h"

void nextion_init();
void nextion_wait();
void nextion_feed(const FEED_THREAD*, LED_REG leds);
void nextion_rpm(Uint16 rpm);
KEY_REG nextion_loop(bool alarm, bool &enabled, bool &at_stop, bool &init);

#endif /* NEXTION_H_ */
