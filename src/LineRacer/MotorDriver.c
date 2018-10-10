/******************************************************************************/
/**
 * file         MotorDriver.c
 *
 * brief        C file for MotorDriver
 *
 * version      1.00
 * date         Aug/22/2017
 * warning
 * note
 * ---------------------------------------------------------------------------
 *               R E V I S I O N   H I S T O R Y
 * ---------------------------------------------------------------------------
 *   Date        Version  Author  Description
 *  ----------   -------  ------  --------------------------------------------
 *  2017-08-22   1.00     ARCLab  - Creation Release
 *
 */
/******************************************************************************/

/******************************************************************************/
/* HEADER FILES                                                               */
/******************************************************************************/
#include "MotorDriver.h"

/******************************************************************************/
/* PRIVATE DEFINITIONS AND MACROS (scope: file)                               */
/******************************************************************************/
#define kNominalVol 7.4

/******************************************************************************/
/* PRIVATE TYPEDEFS AND STRUCTURES (scope: file)                              */
/******************************************************************************/

/******************************************************************************/
/* PUBLIC VARIABLES                                                           */
/******************************************************************************/

/******************************************************************************/
/* PRIVATE VARIABLES                                                          */
/******************************************************************************/
bool bEnableMotorR;
float fltMotorRVol;
bool bEnableMotorL;
float fltMotorLVol;

/******************************************************************************/
/* PRIVATE Function Prototype (scope: file)                                   */
/******************************************************************************/

/******************************************************************************/
/* PRIVATE Function Implementation (scope: file)                              */
/******************************************************************************/

/******************************************************************************/
/* PUBLIC Function Implementation                                             */
/******************************************************************************/
void Actuate_MotorDriver(void)
{

	float m1_input_vol;
	float m2_input_vol;
	uint32_t m1_duty;
	uint32_t m2_duty;

	m1_input_vol = fltMotorRVol;
	m2_input_vol = fltMotorLVol;

	if (m1_input_vol > kNominalVol)
	{
		m1_input_vol = kNominalVol;
	}

	if (m1_input_vol < -kNominalVol)
	{
		m1_input_vol = -kNominalVol;
	}

	if (m2_input_vol > kNominalVol)
	{
		m2_input_vol = kNominalVol;
	}

	if (m2_input_vol < -kNominalVol)
	{
		m2_input_vol = -kNominalVol;
	}

	if (m1_input_vol > 0.0)
	{
		DIGITAL_IO_SetOutputHigh(&dhDO_MOTOR_R_DIR);
		m1_input_vol = fltMotorRVol;
	}
	else
	{
		DIGITAL_IO_SetOutputLow(&dhDO_MOTOR_R_DIR);
		m1_input_vol = fltMotorRVol * (-1.0);
	}

	if (m2_input_vol > 0.0)
	{
		DIGITAL_IO_SetOutputHigh(&dhDO_MOTOR_L_DIR);
		m2_input_vol = fltMotorLVol;
	}
	else
	{
		DIGITAL_IO_SetOutputLow(&dhDO_MOTOR_L_DIR);
		m2_input_vol = fltMotorLVol * (-1.0);
	}

	if (bEnableMotorR == 0)
	{
		m1_duty = 0;
	}
	else
	{
		m1_duty = (uint32_t)((m1_input_vol/kNominalVol) * 10000.0);
	}

	if (bEnableMotorL == 0)
	{
		m2_duty = 0;
	}
	else
	{
		m2_duty = (uint32_t)((m2_input_vol/kNominalVol) * 10000.0);
	}

	PWM_SetDutyCycle(&dhPWM_MOTOR_R, m1_duty);
	PWM_SetDutyCycle(&dhPWM_MOTOR_L, m2_duty);
}

/******************************************************************************/
/*                                                                            */
/*                            EOF                                             */
/*                                                                            */
/******************************************************************************/
