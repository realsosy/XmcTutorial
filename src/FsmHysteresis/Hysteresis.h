/*
 * Hysteresis.h
 *
 *  Created on: Nov 7, 2017
 *      Author: Wootaik
 */

#ifndef HYSTERESIS_H_
#define HYSTERESIS_H_

#define UPPER_THRESHOLD 3.0
#define UPPER_VALUE 5.0
#define LOWER_THRESHOLD 1.0
#define LOWER_VALUE 0.0

enum Hysteresis_tag{
	LOWER_STATE,
	UPPER_STATE
};

float MyHysteresis(float input);

#endif /* HYSTERESIS_H_ */
