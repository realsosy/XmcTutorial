/*
 * Hysteresis.c
 *
 *  Created on: Nov 7, 2017
 *      Author: Wootaik
 */

#include "Hysteresis.h"

float MyHysteresis(float input){

	static enum Hysteresis_tag state = LOWER_STATE;

	float output;
	switch(state){

	case LOWER_STATE:


		break;

	case UPPER_STATE:


		break;
	}
	return(output);
}

