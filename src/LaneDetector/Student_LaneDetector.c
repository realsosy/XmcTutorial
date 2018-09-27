/*
 * LaneDetector.c
 *
 *  Created on: Aug 22, 2017
 *      Author: ARCLab
 */

#include "LaneDetector.h"

uint32_t LeftSensor;
uint32_t RightSensor;
uint32_t CenterSensor;

float fltLeftVol;
float fltCenterVol;
float fltRightVol;

LANE_TYPE_t eLaneType;
int32_t i32LaneOffset;

void Sense_LaneDetector(void)
{

	uint32_t sensor_state;

	uint16_t left_adc_result;
	uint16_t center_adc_result;
	uint16_t right_adc_result;

	LeftSensor = DIGITAL_IO_GetInput(&dhDI_LANE_L);
	CenterSensor = DIGITAL_IO_GetInput(&dhDI_LANE_C);
	RightSensor = DIGITAL_IO_GetInput(&dhDI_LANE_R);

	/**************************************************/
	/* Bit Mask 를 사용해서 LeftSensor,... 을 합쳐보세요 */
	/**************************************************/
	sensor_state = 0;

	switch (sensor_state)
	{
		case 0:
			eLaneType = NO_LANE;
			break;

		case 1:
			eLaneType = VALID;
			i32LaneOffset = 20;
			break;
		/**************************************************/
		/* 다른 case 에 대해서도 프로그래밍 하세요.          */
		/**************************************************/


		default:
	}

	left_adc_result = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_ChLeft_handle);
	center_adc_result = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_ChCenter_handle);
	right_adc_result = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_ChRight_handle);

	fltLeftVol = (float)((left_adc_result/4095.0)*3.3);
	fltCenterVol = (float)((center_adc_result/4095.0)*3.3);
	fltRightVol = (float)((right_adc_result/4095.0)*3.3);

}
