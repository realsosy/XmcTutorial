/*
 * CollisionAvoidance.c
 *
 *  Created on: Aug 21, 2017
 *      Author: ARCLab
 */

#include "CollisionAvoidance.h"

#define OBST_IDX_MAX 5
#define CENTER_DUTY 750.0
#define DIST_THRESHOLD 150.0

#define IC_TICK_PERIOD_NS 533.33

typedef enum CaState_tag {
	CW,
	CCW
} CaState_t;

CaState_t eCaState;

int16_t i16CaArrIdx = 0;
int32_t i32CaDelayMs = 170;

float f32ServoAngleArr[OBST_IDX_MAX] = { -40.0, -20.0, 0.0, 20.0, 40.0 } ;
float f32RawDistanceArr[OBST_IDX_MAX] = { 0.0 };
float f32ObstacleDistanceArr[OBST_IDX_MAX] = { 0.0 };
bool bScanComplete = false;

void Sense_CollisionAvoidance(void)
{
	uint32_t servo_duty;
	uint32_t captured_tick;
	float captured_time;

	CAPTURE_GetCapturedTime(&dhIC_US, &captured_tick);
	captured_time = (float)captured_tick * IC_TICK_PERIOD_NS / 1000.0;
	f32RawDistanceArr[i16CaArrIdx] = captured_time / 58.0;

	if (f32RawDistanceArr[i16CaArrIdx] < DIST_THRESHOLD && f32RawDistanceArr[i16CaArrIdx] > 0.3)
	{
		f32ObstacleDistanceArr[i16CaArrIdx] = f32RawDistanceArr[i16CaArrIdx];
	}
	else
	{
		f32ObstacleDistanceArr[i16CaArrIdx] = 300.0;
	}

	switch (eCaState)
	{
		case CW:
			++i16CaArrIdx;
			if (i16CaArrIdx > 4){
				eCaState = CCW;
				i16CaArrIdx = 3;
				bScanComplete = true;
			}
			break;

		case CCW:
			--i16CaArrIdx;
			if (i16CaArrIdx < 0)
			{
				eCaState = CW;
				i16CaArrIdx = 1;
			}
			break;
	}

	servo_duty = (uint32_t)(CENTER_DUTY - 5.0*f32ServoAngleArr[i16CaArrIdx]);
	PWM_SetDutyCycle(&dhPWM_SERVO, servo_duty);
    TIMER_Stop(&dhOC_CA);
    TIMER_SetTimeInterval(&dhOC_CA, i32CaDelayMs*100000);
	TIMER_Start(&dhOC_CA);

}

void ISR_dhOC_CA(void)
{
	TIMER_ClearEvent(&dhOC_CA);
	TIMER_Stop(&dhOC_CA);
	PWM_Stop(&dhPWM_US);
	PWM_Start(&dhPWM_US);
}
