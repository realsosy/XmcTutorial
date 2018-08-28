/*
 * Button.c
 *
 *  Created on: Sep 17, 2017
 *      Author: Wootaik
 */

#include "Button.h"

char Number;

void InitButton(void){
	DIGITAL_IO_Init(&dhDI_INC);
	DIGITAL_IO_Init(&dhDI_DEC);
	Number = 0;
}

void CheckButton(void){
	uint32_t pin1_status;
	uint32_t pin2_status;
	pin1_status = DIGITAL_IO_GetInput(&dhDI_INC);
	pin2_status = DIGITAL_IO_GetInput(&dhDI_DEC);

	if((pin1_status == 0) && (pin2_status == 1)){
		Number++;
		if(Number > 9){
			Number = 0;
		}
	}

	if((pin1_status == 1) && (pin2_status == 0)){
		Number--;
		if(Number < 0){
			Number = 9;
		}
	}
}

