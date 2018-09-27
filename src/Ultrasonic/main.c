/*
 * main.c
 *
 *  Created on: 2017 Apr 05 21:42:34
 *  Author: ARCLAB
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include "Ultrasonic.h"

//#define UR_RES 60000

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

//uint32_t u32CapturedTick;
//float fltCapturedTime;
//float fltDistance;
//uint32_t u32SwTimer_60ms;


//void CB_dhSYSTIMER_0_u32SwTimer_60ms(void)
//{
//		CAPTURE_GetCapturedTime(&dhCAPTURE_0, &u32CapturedTick);
//		fltCapturedTime = (float)u32CapturedTick * 533.33 / 1000.0;
//		fltDistance = fltCapturedTime / 58.0;
//}

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

//  u32SwTimer_60ms = SYSTIMER_CreateTimer(UR_RES, SYSTIMER_MODE_PERIODIC, (void*)CB_dhSYSTIMER_0_u32SwTimer_60ms, NULL);
//  SYSTIMER_StartTimer(u32SwTimer_60ms);
  Ultrasonic_Init();
  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {

  }
}
