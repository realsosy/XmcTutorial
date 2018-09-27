/*
 * Control.c
 *
 *  Created on: Sep 2, 2017
 *      Author: ARCLab
 */

#include "Algorithm.h"

#define OBST_IDX_MAX 5
#define DIST_THRESHOLD 150.0
#define STOP_DISTANCE 45.0
#define NO_LANE_COUNTER_MAX 100

float fltRamp(float state, float input, float delta);

extern int32_t i32LaneOffset;
extern LANE_TYPE_t eLaneType;

extern bool bEnableMotorR;
extern bool bEnableMotorL;
extern float fltMotorRVol;
extern float fltMotorLVol;

extern bool bScanComplete;
extern float fltObstacleDistanceArr[OBST_IDX_MAX];

bool bObstacleBeing;

bool bSubSystemTest = false;

typedef enum {
	STOP,
	RUN
} eControlState_t;

eControlState_t eControlState = STOP;
float kRampVol = 1.0;
float kLowVol = -5.0;
float kMiddleVol = -0.5;
float kHighVol = 5.0;

void ControlLineRacer(void)
{
	float motor_r_ref;
	float motor_l_ref;

	static uint32_t no_lane_counter;

	if (bSubSystemTest == true)
	{
		return;
	}

	switch(eControlState){
	case STOP:
		if( (bObstacleBeing == false) && (eLaneType == VALID)){
			eControlState = RUN;
			bEnableMotorR = true;
			bEnableMotorL = true;
		}

		break;
	case RUN:
		if(eLaneType == NO_LANE){
			no_lane_counter++;
		}else{
			no_lane_counter = 0;
		}

		if( (bObstacleBeing == true) || (no_lane_counter > NO_LANE_COUNTER_MAX)){
			eControlState = STOP;
			bEnableMotorR = false;
			bEnableMotorL = false;
		}
		break;
	default:
		bEnableMotorR = false;
		bEnableMotorL = false;

		break;
	}

	if (i32LaneOffset == 0)
	{
		motor_r_ref = kHighVol;
		motor_l_ref = kHighVol;
	}
	else if (i32LaneOffset == 10)
	{
		motor_r_ref = kMiddleVol;
		motor_l_ref = kHighVol;
	}
	else if (i32LaneOffset == 20)
	{
		motor_r_ref = kLowVol;
		motor_l_ref = kHighVol;
	}
	else if (i32LaneOffset == -10)
	{
		motor_r_ref = kHighVol;
		motor_l_ref = kMiddleVol;
	}
	else if (i32LaneOffset == -20)
	{
		motor_r_ref = kHighVol;
		motor_l_ref = kLowVol;
	}

	fltMotorRVol = fltRamp(fltMotorRVol, motor_r_ref, kRampVol);
	fltMotorLVol = fltRamp(fltMotorLVol, motor_l_ref, kRampVol);

}

void DetectObstacle(void)
{

	if (bScanComplete == false){
		bObstacleBeing = true;
		return;
	}

	if( (i32LaneOffset < -15) ){
		if( (fltObstacleDistanceArr[0] < STOP_DISTANCE)
			|| (fltObstacleDistanceArr[1] < STOP_DISTANCE)
			|| (fltObstacleDistanceArr[2] < STOP_DISTANCE) )
		{
			bObstacleBeing = true;
		}
		else{
			bObstacleBeing = false;
		}
	} else	if( (i32LaneOffset > -15) && (i32LaneOffset < 15) ){
		if( (fltObstacleDistanceArr[1] < STOP_DISTANCE)
			|| (fltObstacleDistanceArr[2] < STOP_DISTANCE)
			|| (fltObstacleDistanceArr[3] < STOP_DISTANCE) )
		{
			bObstacleBeing = true;
		}
		else{
			bObstacleBeing = false;
		}
	} else if( (i32LaneOffset < 15) ){
		if( (fltObstacleDistanceArr[2] < STOP_DISTANCE)
			|| (fltObstacleDistanceArr[3] < STOP_DISTANCE)
			|| (fltObstacleDistanceArr[4] < STOP_DISTANCE) )
		{
			bObstacleBeing = true;
		}
		else{
			bObstacleBeing = false;
		}
	} else {
		bObstacleBeing = false;
	}

}

float fltRamp(float state, float input, float delta){
	float diff = input - state;
	if (diff >= 0.0)	{
		if (diff < delta){
			state = input;
		}
		else{
			state = state + delta;
		}
	}
	else{
		if (diff > -delta) {
			state = input;
		}
		else{
			state = state - delta;
		}
	}
	return(state);
}
