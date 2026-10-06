/*
 * software_timer.h
 *
 *  Created on: Sep 27, 2026
 *      Author: admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

extern int timer0_flag;
extern int timer1_flag;
extern int timer2_flag;

void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);

void timer_run(void);

#endif /* INC_SOFTWARE_TIMER_H_ */
