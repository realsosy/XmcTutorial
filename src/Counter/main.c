/*
 * main.c
 *
 *  Created on: 2017 Jan 07 15:16:59
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

  uint16_t counter_value;

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
	  if (DIGITAL_IO_GetInput(&dhDIGITAL_IN_0) == 0)
	  {
		  DIGITAL_IO_SetOutputHigh(&dhDIGITAL_OUT_0);
	  }
	  else
	  {
		  DIGITAL_IO_SetOutputLow(&dhDIGITAL_OUT_0);
	  }

	  counter_value = COUNTER_GetCurrentCount(&dhCOUNTER_0);
  }
}

void dhCOUNTER_0_count_match(void)
{
	COUNTER_ClearEvent(&dhCOUNTER_0, COUNTER_EVENT_COUNT_MATCH);
	COUNTER_ResetCounter(&dhCOUNTER_0);
}
