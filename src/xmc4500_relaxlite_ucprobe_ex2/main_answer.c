/*
 * main.c
 *
 *  Created on: 2017 Jan 11 13:20:54
 *  Author: Wootaik
 */

/*********************************************************************************************************************
 * HEADER FILES
 ********************************************************************************************************************/
#include <DAVE.h>
#include <xmc_gpio.h>
#include "probe_scope.h"

/*********************************************************************************************************************
 * MACROS
 ********************************************************************************************************************/
/* Timer frequency (Hz) */
#define TICKS_PER_SECOND (10000U)
#define SECONDS_PER_TICK (1.0F / (float)TICKS_PER_SECOND)

#define LED1 P1_1

/*********************************************************************************************************************
 * ENUMS
 ********************************************************************************************************************/
typedef enum  CHANNEL_WAVEFORM
{
  CHANNEL_WAVEFORM_SIN = 0,
  CHANNEL_WAVEFORM_SQUARE = 1,
  CHANNEL_WAVEFORM_TRIANGLE = 2,
} CHANNEL_WAVEFORM_t;

/*********************************************************************************************************************
 * DATA STRUCTURES
 ********************************************************************************************************************/
typedef struct channel
{
  uint32_t frequency;
  float offset;
  float amplitude;
  float radians;
  float value;
  CHANNEL_WAVEFORM_t waveform;
} channel_t;

/*********************************************************************************************************************
 * GLOBAL DATA
 ********************************************************************************************************************/
channel_t channel_0 =
{
  .frequency = 1,
  .offset = 0.0F,
  .amplitude = 1.0F,
  .waveform = CHANNEL_WAVEFORM_SIN,
  .value = 0.0F
};

channel_t channel_1 =
{
  .frequency = 1,
  .offset = 0.0F,
  .amplitude = 1.0F,
  .waveform = CHANNEL_WAVEFORM_SQUARE,
  .value = 0.0F
};

/*********************************************************************************************************************
 * LOCAL ROUTINES
 ********************************************************************************************************************/
__STATIC_INLINE void generate_channel_sample(channel_t *const channel, uint32_t ticks)
{
  int32_t i;
  float elapsed_time = 0.0F;

  // Compute the elapsed time in decimal seconds, in floating point format.
  elapsed_time = (float)ticks * SECONDS_PER_TICK;

  // Convert the time to radians
  channel->radians = elapsed_time * 2.0F * PI * (float)channel->frequency;

  switch (channel->waveform)
  {
    case CHANNEL_WAVEFORM_SIN:
      channel->value = arm_sin_f32(channel->radians);
      break;

	case CHANNEL_WAVEFORM_SQUARE:
	  channel->value = arm_sin_f32(channel->radians);
	  for (i = 3; i < 11; i += 2)
	  {
		  channel->value += (1 / (float)i) * arm_sin_f32(channel->radians * (float)i);
	  }
	  channel->value *= (4.0F / PI);
	  break;

	case CHANNEL_WAVEFORM_TRIANGLE:
	  channel->value = arm_sin_f32(channel->radians);
	  for (i = 3; i < 11; i += 4)
	  {
		channel->value -= (1 / (float)(i * i)) * arm_sin_f32(channel->radians * (float)i);
	  }

	  for (i = 5; i < 13; i += 4)
	  {
		channel->value += (1 / (float)(i * i)) * arm_sin_f32(channel->radians * (float)i);
	  }
	  channel->value *= (8.0F / (PI * PI));
	  break;

	default:
	  break;
  }

  channel->value *= channel->amplitude * 0.5F;
  channel->value += channel->offset;
}

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if(status == DAVE_STATUS_FAILURE)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  XMC_GPIO_SetMode(LED1, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);

  /* Initialize ProbeScope */
  ProbeScope_Init(SystemCoreClock / TICKS_PER_SECOND);

  /* Initialize timer */
  SysTick_Config(SystemCoreClock / TICKS_PER_SECOND);

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U);
}

void SysTick_Handler(void)
{
  static uint32_t ticks = 0;

  ticks++;

  if ((ticks % TICKS_PER_SECOND) == 0)
  {
	  ticks = 0;
	  XMC_GPIO_ToggleOutput(LED1);
  }

  generate_channel_sample(&channel_0, ticks);
  generate_channel_sample(&channel_1, ticks);

  /* Take a sample of the active oscilloscope channels */
  ProbeScope_Sampling();
}
