/*
 * Hysteresis.c
 *
 *  Created on: Nov 7, 2017
 *      Author: Wootaik
 */

#include "Hysteresis.h"

#define UPPER_THRESHOLD 3.0
#define UPPER_VALUE 5.0
#define LOWER_THRESHOLD 1.0
#define LOWER_VALUE 0.0

enum Hysteresis_tag{
	FALLING,
	RISING
};


float MyHysteresis(float input){

	static enum Hysteresis_tag state = FALLING;

	float output = 0.0;
	switch(state){

	case FALLING:


		break;

	case RISING:


		break;
	}
	return(output);
}

