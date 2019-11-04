/*
 * AutoIncrement.h
 *
 *  Created on: Nov 7, 2017
 *      Author: Wootaik
 */

#ifndef AUTOINCREMENT_H_
#define AUTOINCREMENT_H_

#include <Dave.h>

#define PERIOD    100 // msec
#define BUTTON_INTERVAL 1000/PERIOD // msec
#define PUSHED 0
#define RELEASED 1

enum AutoInc_tag{
	SIMPLE_STATE,
	AUTO_STATE
};

extern int32_t Button;
extern int32_t MyValue;

void InputButton(void);


#endif /* AUTOINCREMENT_H_ */
