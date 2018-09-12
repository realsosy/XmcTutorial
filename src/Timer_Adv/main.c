/*
 * main.c
 *
 *  Created on: 2017 Jan 07 16:14:39
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

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {

  }
}

void ISR_dhTIMER_0_time_interval(void)
{
	DIGITAL_IO_ToggleOutput(&dhDIGITAL_OUT_0);
}

void ISR_dhTIMER_1_time_interval(void)
{
	if (DIGITAL_IO_GetInput(&dhDIGITAL_IN_0) == 0)
	{
		TIMER_Stop(&dhTIMER_0);
	}
	else
	{
		TIMER_Start(&dhTIMER_0);
	}
}
