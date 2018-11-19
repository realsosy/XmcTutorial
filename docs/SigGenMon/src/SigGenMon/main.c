/*
 * main.c
 *
 *  Created on: 2017 Aug 11 23:42:37
 *  Author: ARCLAB
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include "probe_scope.h"

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

#define AI_GAIN0 0.6522 // (R10/(R9+R10))*(1+R11/R12) = (13k/(13k+13k))*(1+9.1k/30k)
#define AI_GAIN1 0.6522 // (R14/(R13+R14))*(1+R15/R16) = (13k/(13k+13k))*(1+9.1k/30k)

#define AO_GAIN0 2.0 // (1+R19/R20) = (1+10k/10k)
#define AO_GAIN1 2.0 // (1+R19/R20) = (1+10k/10k)

void Sense_DI(void);
void Sense_AI(void);
void Actuate_DO(void);
void Actuate_AO(void);

uint32_t u32DI0State;
uint32_t u32DI1State;
float f32AI0Vol;
float f32AI1Vol;
uint32_t u32DO0State;
uint32_t u32DO1State;
float f32AO0Vol;
float f32AO1Vol;

uint32_t SysTimer_Task1m_Id;
uint32_t SysTimer_Task10m_Id;

void SysTimer_Task1m(void);
void SysTimer_Task10m(void);

int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if(status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  SysTimer_Task1m_Id = SYSTIMER_CreateTimer(1000, SYSTIMER_MODE_PERIODIC, (void*)SysTimer_Task1m, NULL);
  SysTimer_Task10m_Id = SYSTIMER_CreateTimer(10000, SYSTIMER_MODE_PERIODIC, (void*)SysTimer_Task10m, NULL);

  SYSTIMER_StartTimer(SysTimer_Task1m_Id);
  SYSTIMER_StartTimer(SysTimer_Task10m_Id);

  /* Initialize ProbeScope */
  ProbeScope_Init(1000); // 1KHz

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {

  }
}


void Sense_DI(void)
{
	u32DI0State = DIGITAL_IO_GetInput(&dhDIGITAL_IN_0);
	u32DI1State = DIGITAL_IO_GetInput(&dhDIGITAL_IN_1);
}

void Sense_AI(void)
{
	uint16_t channel0;
	uint16_t channel1;

	channel0 = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_Ch0_handle);
	channel1 = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_Ch1_handle);

	f32AI0Vol = ((float) channel0/4095.0) * 3.3 / AI_GAIN0 ;
	f32AI1Vol = ((float) channel1/4095.0) * 3.3 / AI_GAIN1 ;
}

void Actuate_DO(void)
{
	if (u32DO0State == 1)
	{
		DIGITAL_IO_SetOutputHigh(&dhDIGITAL_OUT_0);
	}
	else
	{
		DIGITAL_IO_SetOutputLow(&dhDIGITAL_OUT_0);
	}

	if (u32DO1State == 1)
	{
		DIGITAL_IO_SetOutputHigh(&dhDIGITAL_OUT_1);
	}
	else
	{
		DIGITAL_IO_SetOutputLow(&dhDIGITAL_OUT_1);
	}
}

void Actuate_AO(void)
{
	uint16_t channel0;
	uint16_t channel1;

	channel0 = (uint16_t)((f32AO0Vol/AO_GAIN0 - 0.3)*(4095.0/2.2));
	channel1 = (uint16_t)((f32AO1Vol/AO_GAIN1 - 0.3)*(4095.0/2.2));
	DAC_SingleValue_SetValue_u16(&dhDAC_0, channel0);
	DAC_SingleValue_SetValue_u16(&dhDAC_1, channel1);
}

void SysTimer_Task1m(void){
	Sense_AI();

	  /* Take a sample of the active oscilloscope channels */
	  ProbeScope_Sampling();

}


void SysTimer_Task10m(void){
	Sense_DI();
	Actuate_DO();
	Actuate_AO();
}

