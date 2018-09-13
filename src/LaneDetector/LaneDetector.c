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

float f32LeftVol;
float f32CenterVol;
float f32RightVol;

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

	sensor_state = 0;
	sensor_state = sensor_state | (LeftSensor << 2);
	sensor_state = sensor_state | (CenterSensor << 1);
	sensor_state = sensor_state | (RightSensor);

	switch (sensor_state)
	{
		case 0:
			eLaneType = NO_LANE;
			break;

		case 1:
			eLaneType = VALID;
			i32LaneOffset = 20;
			break;

		case 2:
			eLaneType = VALID;
			i32LaneOffset = 0;
			break;

		case 3:
			eLaneType = VALID;
			i32LaneOffset = 10;
			break;

		case 4:
			eLaneType = VALID;
			i32LaneOffset = -20;
			break;

		case 5:
			eLaneType = INVALID;
			break;

		case 6:
			eLaneType = VALID;
			i32LaneOffset = -10;
			break;

		case 7:
			eLaneType = ALL;
			break;

	}

	left_adc_result = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_ChLeft_handle);
	center_adc_result = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_ChCenter_handle);
	right_adc_result = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_ChRight_handle);

	f32LeftVol = (float)((left_adc_result/4095.0)*3.3);
	f32CenterVol = (float)((center_adc_result/4095.0)*3.3);
	f32RightVol = (float)((right_adc_result/4095.0)*3.3);

}
