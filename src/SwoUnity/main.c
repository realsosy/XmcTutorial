/*
 * main.c
 *
 *  Created on: 2020 Mar 13 18:00:48
 *  Author: Wootaik Lee
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

#include "SWO.h"
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

  ITM_SendChar('I');
  ITM_SendChar('T');
  ITM_SendChar('M');
  ITM_SendChar('_');
  ITM_SendChar('S');
  ITM_SendChar('e');
  ITM_SendChar('n');
  ITM_SendChar('d');
  ITM_SendChar('C');
  ITM_SendChar('h');
  ITM_SendChar('a');
  ITM_SendChar('r');
  ITM_SendChar(' ');
  ITM_SendChar('T');
  ITM_SendChar('e');
  ITM_SendChar('s');
  ITM_SendChar('t');
  ITM_SendChar('!');
  ITM_SendChar('\n');

  SWO_PrintChar('S');
  SWO_PrintChar('W');
  SWO_PrintChar('O');
  SWO_PrintChar('_');
  SWO_PrintChar('P');
  SWO_PrintChar('r');
  SWO_PrintChar('i');
  SWO_PrintChar('n');
  SWO_PrintChar('t');
  SWO_PrintChar('C');
  SWO_PrintChar('h');
  SWO_PrintChar('a');
  SWO_PrintChar('r');
  SWO_PrintChar('\n');

  SWO_PrintString("SWO_PrintString\n");

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {

  }
}
