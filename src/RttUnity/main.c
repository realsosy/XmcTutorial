/*
 * main.c
 *
 *  Created on: 2020 Mar 13 16:49:45
 *  Author: Wootaik Lee
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include "SEGGER_RTT.h"

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

  SEGGER_RTT_PutChar(0, 'P');
  SEGGER_RTT_PutChar(0, 'u');
  SEGGER_RTT_PutChar(0, 't');
  SEGGER_RTT_PutChar(0, 'C');
  SEGGER_RTT_PutChar(0, 'h');
  SEGGER_RTT_PutChar(0, 'a');
  SEGGER_RTT_PutChar(0, 'r');
  SEGGER_RTT_PutChar(0, ' ');
  SEGGER_RTT_PutChar(0, 'T');
  SEGGER_RTT_PutChar(0, 'e');
  SEGGER_RTT_PutChar(0, 's');
  SEGGER_RTT_PutChar(0, 't');
  SEGGER_RTT_PutChar(0, '\n');

  SEGGER_RTT_Write(0, "Write Test\n", 11);
  SEGGER_RTT_WriteString(0, "Hello World from XMC using SEGGER_RTT!\r\n");

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  int my_char;
  while(1U)
  {
	  my_char = SEGGER_RTT_GetKey();
	  if(my_char>=0){
		  SEGGER_RTT_PutChar(0, my_char);
	  }
  }
}
