/*
 * main.c
 *
 *  Created on: 2017 Sep 16 23:11:00
 *  Author: Wootaik
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

char ConvertSeg(char SegValue); // function prototype
char Number = 0; // declare variables A and B
char Segment;
static void delay(uint32_t cycles);

int main(void) {
	DAVE_STATUS_t status;

	status = DAVE_Init(); /* Initialization of DAVE APPs  */

	if (status != DAVE_STATUS_SUCCESS) {
		/* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
		XMC_DEBUG("DAVE APPs initialization failed\n");

		while (1U) {

		}
	}

	/* Placeholder for user application code. The while loop below can be replaced with user application code. */

	while (1U) {
		Segment = ConvertSeg(Number);
		BUS_IO_Write(&BUS_IO_0, Segment);
		Number++;
		if(Number>9) {
			Number = 0;
		}
		delay(500);
	}
}


char ConvertSeg(char SegValue) {
	char SegByte=0x00;
	switch (SegValue) { //DP G F E D C B A
		case 0 : SegByte = 0x3F;break; // 0 0 1 1 1 1 1 1 binary
		case 1 : SegByte = 0x06;break; // 0 0 0 0 0 1 1 0 binary
		case 2 : SegByte = 0x5B;break; // 0 1 0 1 1 0 1 1 binary
		case 3 : SegByte = 0x4F;break; // 0 1 0 0 1 1 1 1 binary
		case 4 : SegByte = 0x66;break; // 0 1 1 0 0 1 1 0 binary
		case 5 : SegByte = 0x6D;break; // 0 1 1 0 1 1 0 1 binary
		case 6 : SegByte = 0x7D;break; // 0 1 1 1 1 1 0 1 binary
		case 7 : SegByte = 0x07;break; // 0 0 0 0 0 1 1 1 binary
		case 8 : SegByte = 0x7F;break; // 0 1 1 1 1 1 1 1 binary
		case 9 : SegByte = 0x6F;break; // 0 1 1 0 1 1 1 1 binary
	}
	return(SegByte);
}

static void delay(uint32_t cycles)
{
  volatile uint32_t i;

  for(i = 0UL; i < cycles ;++i)
  {
    __NOP();
  }
}

