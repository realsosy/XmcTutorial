/*
 * AutoIncrement.c
 *
 *  Created on: Nov 7, 2017
 *      Author: Wootaik
 */

#include "AutoIncrement.h"

#define PERIOD    100 // msec
#define BUTTON_INTERVAL 1000/PERIOD // msec
#define PUSHED 0
#define RELEASED 1

enum AutoInc_tag{
	SIMPLE_STATE,
	AUTO_STATE
};

int32_t Button;
int32_t MyValue;

void InputButton(void){

	static enum AutoInc_tag state = SIMPLE_STATE;
	static int32_t HoldInterval = 0;
	switch(state){

	case SIMPLE_STATE:


		break;

	case AUTO_STATE:


		break;
	}
}
