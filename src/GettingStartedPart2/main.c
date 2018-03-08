/*
 * main.c
 *
 *  Created on: 2016 Sep 11 20:28:22
 *  Author: ARCLAB
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)
volatile uint32_t u32NewFreq=1;
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

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {

  }
}

void ISR_dhPWM_0_period_match(void)
{
	PWM_ClearEvent(&dhPWM_0, PWM_INTERRUPT_PERIODMATCH); // PWM_AcknowledgeInterrupt in WEBIAR GettingStarted is old version's API. Use PWM_ClearEvent

	if (DIGITAL_IO_GetInput(&dhDIGITAL_IN_0) == 0)
	{
		PWM_Stop(&dhPWM_0);
	}
}

void ISR_dhPIN_INTERRUPT_0(void)
{
	u32NewFreq++;
	if (u32NewFreq > 10)
	{
		u32NewFreq = 1;
		PWM_Start(&dhPWM_0);
	}
	PWM_SetFreq(&dhPWM_1, u32NewFreq);
}
