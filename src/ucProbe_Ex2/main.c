/*
 * main.c
 *
 *  Created on: 2017 Jan 09 17:18:26
 *  Author: ARCLAB
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include <probe_scope.h>

#include <math.h>
/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

#define TICKS_PER_SECOND (1000U)
#define SECONDS_PER_TICK (1.0F / (float)TICKS_PER_SECOND)

/******************************************************************************
 * ENUMS
 *****************************************************************************/
typedef enum  CHANNEL_WAVEFORM
{
	CHANNEL_WAVEFORM_SIN = 0,
	CHANNEL_WAVEFORM_SQUARE = 1,
	CHANNEL_WAVEFORM_TRIANGLE = 2,
} CHANNEL_WAVEFORM_t;

/******************************************************************************
 * DATA STRUCTURES
 *****************************************************************************/
typedef struct channel
{
	uint32_t frequency;
	float offset;
	float amplitude;
	float radians;
	float value;
	CHANNEL_WAVEFORM_t waveform;
} channel_t;

/******************************************************************************
 * GLOBAL DATA
 *****************************************************************************/
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

/******************************************************************************
 * LOCAL ROUTINES
 *****************************************************************************/
void generate_channel_sample(channel_t *const channel, uint32_t ticks)
{
	float elapsed_time = 0.0F;
	int32_t tick_period = 0;
	tick_period = TICKS_PER_SECOND/channel->frequency;
	ticks = ticks % tick_period;

	switch (channel->waveform)
	{
	case CHANNEL_WAVEFORM_SIN:
		// Compute the elapsed time in decimal seconds, in floating point format.
		elapsed_time = (float)ticks * SECONDS_PER_TICK;
		// Convert the time to radians
		channel->radians = elapsed_time * 2.0F * 3.141592F * (float)channel->frequency;
		channel->value = sin(channel->radians);
		break;

	case CHANNEL_WAVEFORM_SQUARE:
		if(ticks < tick_period/2){
			channel->value = -1.0;
		}
		else{
			channel->value = 1.0;
		}
		break;

	case CHANNEL_WAVEFORM_TRIANGLE:
		if(ticks < tick_period/2){
			channel->value = -1.0 + 4.0* (float)ticks/(float)tick_period;
		}
		else{
			channel->value = 3.0 - 4.0* (float)ticks/(float)tick_period;
		}
		break;

	default:
		break;
	}

	channel->value *= channel->amplitude * 0.5F;
	channel->value += channel->offset;
}

uint8_t g_var;

uint32_t Timer_1ms_Id;

void CB_Timer_1ms(void)
{
	static uint32_t ticks = 0;

	ticks++;

	if (ticks == TICKS_PER_SECOND)
	{
		ticks = 0;

		DIGITAL_IO_ToggleOutput(&dhDIGITAL_OUT_0);
		g_var++;
	}
	generate_channel_sample(&channel_0, ticks);
	generate_channel_sample(&channel_1, ticks);

	/* Take a sample of the active oscilloscope channels */
	ProbeScope_Sampling();

}

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

	g_var = 0;

	/* Initialize ProbeScope */
	ProbeScope_Init(SystemCoreClock / TICKS_PER_SECOND);

	Timer_1ms_Id = SYSTIMER_CreateTimer(1000, SYSTIMER_MODE_PERIODIC, (void*) CB_Timer_1ms, NULL);
	SYSTIMER_StartTimer(Timer_1ms_Id);

	/* Placeholder for user application code. The while loop below can be replaced with user application code. */
	while(1U)
	{

	}
}
