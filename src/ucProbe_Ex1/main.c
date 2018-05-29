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

#define TICKS_PER_SECOND (1000U)

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

  Timer_1ms_Id = SYSTIMER_CreateTimer(1000, SYSTIMER_MODE_PERIODIC, (void*) CB_Timer_1ms, NULL);

  SYSTIMER_StartTimer(Timer_1ms_Id);

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {

  }
}
