/*
 * Control.h
 *
 *  Created on: Sep 2, 2017
 *      Author: ARCLab
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "CollisionAvoidance.h"
#include "LaneDetector.h"
#include "MotorDriver.h"
#include <stdbool.h>

void ControlLineRacer(void);
void DetectObstacle(void);

#endif /* ALGORITHM_H_ */
