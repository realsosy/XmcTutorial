/*
 * main.c
 *
 *  Created on: 2016 Oct 13 16:33:16
 *  Author: ARCLAB
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */
uint32_t SYSTIMER_0_u32Tick1ms;
uint32_t SYSTIMER_0_u32Tick100ms;

uint32_t dhDIGITAL_IN_0_u32Value;
uint32_t dhDIGITAL_IN_1_u32Value;
uint32_t dhDIGITAL_IN_2_u32Value;
uint32_t dhDIGITAL_IN_3_u32Value;

uint32_t dhDIGITAL_OUT_0_u32Value;
uint32_t dhDIGITAL_OUT_1_u32Value;
uint32_t dhDIGITAL_OUT_2_u32Value;
uint32_t dhDIGITAL_OUT_3_u32Value;

uint32_t dhPWM_0_u32Frequency;
uint32_t dhPWM_0_u32Duty;

uint16_t dhDAC_0_u16Value;
uint16_t dhDAC_1_u16Value;

float dhDAC_0_fltValue;
float dhDAC_1_fltValue;

uint16_t dhADC_0_u16ChAValue;
uint16_t dhADC_0_u16ChBValue;
uint16_t dhADC_0_u16ChCValue;
uint16_t dhADC_0_u16ChDValue;

float dhADC_0_fltChAValue;
float dhADC_0_fltChBValue;
float dhADC_0_fltChCValue;
float dhADC_0_fltChDValue;

void CB_SYSTIMER_0_timer_1ms(void)
{
	SYSTIMER_0_u32Tick1ms++;
	if(SYSTIMER_0_u32Tick1ms >= 1000){
		SYSTIMER_0_u32Tick1ms = 0;
	}

	if(dhDAC_0_fltValue > 2.5f){
		dhDAC_0_fltValue = 2.5f;
	}
	else if (dhDAC_0_fltValue < 0.3f){
		dhDAC_0_fltValue = 0.3f;
	}
	else{
		;
	}

	if(dhDAC_1_fltValue > 2.5f){
		dhDAC_1_fltValue = 2.5f;
	}
	else if (dhDAC_1_fltValue < 0.3f){
		dhDAC_1_fltValue = 0.3f;
	}
	else{
		;
	}

	dhDAC_0_u16Value = (uint16_t)(((dhDAC_0_fltValue - 0.3)/2.2) * 4095.0);
	dhDAC_1_u16Value = (uint16_t)(((dhDAC_1_fltValue - 0.3)/2.2) * 4095.0);

	DAC_SingleValue_SetValue_u16(&dhDAC_0, dhDAC_0_u16Value);
	DAC_SingleValue_SetValue_u16(&dhDAC_1, dhDAC_1_u16Value);

	DIGITAL_IO_ToggleOutput(&dhDIGITAL_OUT_4);
}

void CB_SYSTIMER_0_timer_100ms(void)
{
	SYSTIMER_0_u32Tick100ms++;
	if(SYSTIMER_0_u32Tick100ms >= 10){
		SYSTIMER_0_u32Tick100ms = 0;
	}

	dhADC_0_u16ChAValue = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_Channel_A);
	dhADC_0_u16ChBValue = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_Channel_B);
	dhADC_0_u16ChCValue = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_Channel_C);
	dhADC_0_u16ChDValue = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_Channel_D);

	dhADC_0_fltChAValue = ((float)dhADC_0_u16ChAValue / 4096.0) * 3.3;
	dhADC_0_fltChBValue = ((float)dhADC_0_u16ChBValue / 4096.0) * 3.3;
	dhADC_0_fltChCValue = ((float)dhADC_0_u16ChCValue / 4096.0) * 3.3;
	dhADC_0_fltChDValue = ((float)dhADC_0_u16ChDValue / 4096.0) * 3.3;

	PWM_SetFreqAndDutyCycle(&dhPWM_0, dhPWM_0_u32Frequency, dhPWM_0_u32Duty);

	dhDIGITAL_IN_0_u32Value = DIGITAL_IO_GetInput(&dhDIGITAL_IN_0);
	dhDIGITAL_IN_1_u32Value = DIGITAL_IO_GetInput(&dhDIGITAL_IN_1);
	dhDIGITAL_IN_2_u32Value = DIGITAL_IO_GetInput(&dhDIGITAL_IN_2);
	dhDIGITAL_IN_3_u32Value = DIGITAL_IO_GetInput(&dhDIGITAL_IN_3);

	if (dhDIGITAL_OUT_0_u32Value == 0){
		DIGITAL_IO_SetOutputLow(&dhDIGITAL_OUT_0);
	}
	else{
		DIGITAL_IO_SetOutputHigh(&dhDIGITAL_OUT_0);
	}

	if (dhDIGITAL_OUT_1_u32Value == 0){
		DIGITAL_IO_SetOutputLow(&dhDIGITAL_OUT_1);
	}
	else{
		DIGITAL_IO_SetOutputHigh(&dhDIGITAL_OUT_1);
	}

	if (dhDIGITAL_OUT_2_u32Value == 0){
		DIGITAL_IO_SetOutputLow(&dhDIGITAL_OUT_2);
	}
	else{
		DIGITAL_IO_SetOutputHigh(&dhDIGITAL_OUT_2);
	}

	if (dhDIGITAL_OUT_3_u32Value == 0){
		DIGITAL_IO_SetOutputLow(&dhDIGITAL_OUT_3);
	}
	else{
		DIGITAL_IO_SetOutputHigh(&dhDIGITAL_OUT_3);
	}

	DIGITAL_IO_ToggleOutput(&dhDIGITAL_OUT_5);
}

int main(void)
{
	DAVE_STATUS_t status;

	uint32_t timer_1ms;
	uint32_t timer_100ms;

	status = DAVE_Init();           /* Initialization of DAVE APPs  */
	if(status != DAVE_STATUS_SUCCESS)
	{
		/* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
		XMC_DEBUG("DAVE APPs initialization failed\n");

		while(1U)
		{

		}
	}

	dhDIGITAL_OUT_0_u32Value = 0;
	dhDIGITAL_OUT_1_u32Value = 0;
	dhDIGITAL_OUT_2_u32Value = 0;
	dhDIGITAL_OUT_3_u32Value = 0;

	dhPWM_0_u32Frequency = 10;
	dhPWM_0_u32Duty = 5000;

	dhDAC_0_u16Value = 0;
	dhDAC_1_u16Value = 0;

	timer_1ms = SYSTIMER_CreateTimer(1000, SYSTIMER_MODE_PERIODIC, (void*)CB_SYSTIMER_0_timer_1ms, NULL);
	timer_100ms = SYSTIMER_CreateTimer(100000, SYSTIMER_MODE_PERIODIC, (void*)CB_SYSTIMER_0_timer_100ms, NULL);

	SYSTIMER_StartTimer(timer_1ms);
	SYSTIMER_StartTimer(timer_100ms);

	/* Placeholder for user application code. The while loop below can be replaced with user application code. */
	while(1U)
	{

	}
}
