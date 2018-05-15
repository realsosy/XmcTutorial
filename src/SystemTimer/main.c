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

uint32_t u32SwTimer_200ms;
uint32_t u32SwTimer_1s;

void CB_dhSYSTIMER_0_u32SwTimer_200ms(void)
{
	DIGITAL_IO_ToggleOutput(&dhDIGITAL_OUT_0);
}

void CB_dhSYSTIMER_0_u32SwTimer_1s(void)
{
	DIGITAL_IO_ToggleOutput(&dhDIGITAL_OUT_1);
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

  u32SwTimer_200ms = SYSTIMER_CreateTimer(200000, SYSTIMER_MODE_PERIODIC, CB_dhSYSTIMER_0_u32SwTimer_200ms, NULL);
  u32SwTimer_1s = SYSTIMER_CreateTimer(1000000, SYSTIMER_MODE_PERIODIC, CB_dhSYSTIMER_0_u32SwTimer_1s, NULL);

  SYSTIMER_StartTimer(u32SwTimer_200ms);
  SYSTIMER_StartTimer(u32SwTimer_1s);

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {

  }
}
