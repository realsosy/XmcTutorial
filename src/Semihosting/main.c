/*
 * main.c
 *
 *  Created on: 2020 Mar 11 15:54:19
 *  Author: Wootaik Lee
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

extern void initialise_monitor_handles(void);

int main(void)
{
	DAVE_STATUS_t status;

	initialise_monitor_handles();

	status = DAVE_Init();           /* Initialization of DAVE APPs  */

	printf("printf() working\n");

	XMC_DEBUG("XMC_DEBUG working\n");

	if(status != DAVE_STATUS_SUCCESS)
	{
		/* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
		XMC_DEBUG("DAVE APPs initialization failed\n");
		while(1U)
		{	;	}
	}

	for (int var = 0; var < 10; ++var) {
		printf("increment integer %d\n", var);
	}

	/* Placeholder for user application code. The while loop below can be replaced with user application code. */
	while(1U)
	{	;	}
}
