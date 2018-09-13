/*
 * LaneDetector.h
 *
 *  Created on: Aug 22, 2017
 *      Author: ARCLab
 */

#ifndef LANEDETECTOR_H_
#define LANEDETECTOR_H_

#include <Dave.h>
#include <stdbool.h>

typedef enum LANE_TYPE_t
{
		NO_LANE,
		VALID,
		INVALID,
		ALL,
} LANE_TYPE_t;

void Sense_LaneDetector(void);

#endif /* LANEDETECTOR_H_ */
