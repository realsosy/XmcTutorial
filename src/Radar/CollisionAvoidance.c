/******************************************************************************/
/**
 * file         CollisionAvoidance.c
 *
 * brief        C file for CollisionAvoidance
 *
 * version      1.00
 * date         Aug/21/2017
 * warning
 * note
 * ---------------------------------------------------------------------------
 *               R E V I S I O N   H I S T O R Y
 * ---------------------------------------------------------------------------
 *   Date        Version  Author  Description
 *  ----------   -------  ------  --------------------------------------------
 *  2017-08-21   1.00     ARCLab  - Creation Release
 *
 */
/******************************************************************************/

/******************************************************************************/
/* HEADER FILES                                                               */
/******************************************************************************/
#include "CollisionAvoidance.h"

/******************************************************************************/
/* PRIVATE DEFINITIONS AND MACROS (scope: file)                               */
/******************************************************************************/
#define OBST_IDX_MAX 5
#define CENTER_DUTY 750.0
#define DIST_THRESHOLD 150.0

#define IC_TICK_PERIOD_NS 533.33

/******************************************************************************/
/* PRIVATE TYPEDEFS AND STRUCTURES (scope: file)                              */
/******************************************************************************/
typedef enum CaState_tag {
	CW,
	CCW
} CaState_t;

/******************************************************************************/
/* PUBLIC VARIABLES                                                           */
/******************************************************************************/

/******************************************************************************/
/* PRIVATE VARIABLES                                                          */
/******************************************************************************/
CaState_t eCaState;

int16_t i16CaArrIdx = 0;
int32_t i32CaDelayMs = 170;

float fltServoAngleArr[OBST_IDX_MAX] = { -40.0, -20.0, 0.0, 20.0, 40.0 } ;
float fltRawDistanceArr[OBST_IDX_MAX] = { 0.0 };
float fltObstacleDistanceArr[OBST_IDX_MAX] = { 0.0 };
bool bScanComplete = false;

/******************************************************************************/
/* PRIVATE Function Prototype (scope: file)                                   */
/******************************************************************************/

/******************************************************************************/
/* PRIVATE Function Implementation (scope: file)                              */
/******************************************************************************/
void ISR_dhOC_CA(void)
{
	TIMER_ClearEvent(&dhOC_CA);
	TIMER_Stop(&dhOC_CA);
	PWM_Stop(&dhPWM_US);
	PWM_Start(&dhPWM_US);
}

/******************************************************************************/
/* PUBLIC Function Implementation                                             */
/******************************************************************************/
void Sense_CollisionAvoidance(void)
{
	uint32_t servo_duty;
	uint32_t captured_tick;
	float captured_time;

	CAPTURE_GetCapturedTime(&dhIC_US, &captured_tick);
	captured_time = (float)captured_tick * IC_TICK_PERIOD_NS / 1000.0;
	fltRawDistanceArr[i16CaArrIdx] = captured_time / 58.0;

	if (fltRawDistanceArr[i16CaArrIdx] < DIST_THRESHOLD && fltRawDistanceArr[i16CaArrIdx] > 0.3)
	{
		fltObstacleDistanceArr[i16CaArrIdx] = fltRawDistanceArr[i16CaArrIdx];
	}
	else
	{
		fltObstacleDistanceArr[i16CaArrIdx] = 300.0;
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

	servo_duty = (uint32_t)(CENTER_DUTY - 5.0*fltServoAngleArr[i16CaArrIdx]);
	PWM_SetDutyCycle(&dhPWM_SERVO, servo_duty);
    TIMER_Stop(&dhOC_CA);
    TIMER_SetTimeInterval(&dhOC_CA, i32CaDelayMs*100000);
	TIMER_Start(&dhOC_CA);
}

/******************************************************************************/
/*                                                                            */
/*                            EOF                                             */
/*                                                                            */
/******************************************************************************/
