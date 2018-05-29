/*
 * main.c
 *
 *  Created on: 2017 Jan 09 17:18:26
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

SYSTIMER_STATE_t Timer_200ms_State;
SYSTIMER_STATE_t Timer_1s_State;
uint32_t Timer_200ms_Id;
uint32_t Timer_1s_Id;
uint32_t Timer_100ms_Id;

void CB_Timer_200ms(void)
{
	DIGITAL_IO_ToggleOutput(&dhDIGITAL_OUT_0);
}

void CB_Timer_1s(void)
{
	DIGITAL_IO_ToggleOutput(&dhDIGITAL_OUT_1);
}

void CB_Timer_100ms(void)
{
  Timer_200ms_State = SYSTIMER_GetTimerState(Timer_200ms_Id);
  Timer_1s_State = SYSTIMER_GetTimerState(Timer_1s_Id);

  if (DIGITAL_IO_GetInput(&dhDIGITAL_IN_0) == 0 && DIGITAL_IO_GetInput(&dhDIGITAL_IN_1) == 0)
  {
	  if (Timer_200ms_State == SYSTIMER_STATE_NOT_INITIALIZED)
	  {
		  Timer_200ms_Id = SYSTIMER_CreateTimer(200000, SYSTIMER_MODE_PERIODIC, CB_Timer_200ms, NULL);
		  SYSTIMER_StartTimer(Timer_200ms_Id);
	  }

	  if (Timer_1s_State == SYSTIMER_STATE_NOT_INITIALIZED)
	  {
		  Timer_1s_Id = SYSTIMER_CreateTimer(1000000, SYSTIMER_MODE_PERIODIC, CB_Timer_1s, NULL);
		  SYSTIMER_StartTimer(Timer_1s_Id);
	  }
  }
  else if (DIGITAL_IO_GetInput(&dhDIGITAL_IN_0) == 0)
  {
	  if (Timer_200ms_State == SYSTIMER_STATE_RUNNING)
	  {
		  SYSTIMER_StopTimer(Timer_200ms_Id);
		  SYSTIMER_DeleteTimer(Timer_200ms_Id);
	  }
  }
  else if (DIGITAL_IO_GetInput(&dhDIGITAL_IN_1) == 0)
  {
	  if (Timer_1s_State == SYSTIMER_STATE_RUNNING)
	  {
		  SYSTIMER_StopTimer(Timer_1s_Id);
		  SYSTIMER_DeleteTimer(Timer_1s_Id);
	  }
  }
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

  Timer_200ms_Id = SYSTIMER_CreateTimer(200000, SYSTIMER_MODE_PERIODIC, (void*) CB_Timer_200ms, NULL);
  Timer_1s_Id = SYSTIMER_CreateTimer(1000000, SYSTIMER_MODE_PERIODIC, (void*) CB_Timer_1s, NULL);
  Timer_100ms_Id = SYSTIMER_CreateTimer(100000, SYSTIMER_MODE_PERIODIC, (void*) CB_Timer_100ms, NULL);

  SYSTIMER_StartTimer(Timer_200ms_Id);
  SYSTIMER_StartTimer(Timer_1s_Id);
  SYSTIMER_StartTimer(Timer_100ms_Id);

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {

  }
}
