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
		output = LOWER_VALUE;
		if(input > UPPER_THRESHOLD){
			output = UPPER_VALUE;
			state = UPPER_STATE;
		}
		break;

	case UPPER_STATE:
		output = UPPER_VALUE;
		if(input < LOWER_THRESHOLD){
			output = LOWER_VALUE;
			state = LOWER_STATE;
		}
		break;
	}
	return(output);
}

