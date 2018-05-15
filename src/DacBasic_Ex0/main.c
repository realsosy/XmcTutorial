/*
 * main.c
 *
 *  Created on: 2017 Jan 04 14:23:29
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

int main(void)
{
  DAVE_STATUS_t status;

  DAC_VSS_t e_amplitude;
  uint32_t u32_frequency;
  int16_t i16_dc_offset_mv;
  int16_t i16_single_value;

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
  e_amplitude = DAC_VSS_1100_mV;
  u32_frequency = 10;
  i16_dc_offset_mv = 1400;

  i16_single_value = 0;

  while(1U)
  {
	  DAC_Pattern_SetAmplitude(&dhDAC_0, e_amplitude);
	  DAC_Pattern_SetFrequency(&dhDAC_0, u32_frequency);
	  DAC_Pattern_SetOffset(&dhDAC_0, i16_dc_offset_mv);

	  DAC_SingleValue_SetValue_s16(&dhDAC_1, i16_single_value);
  }
}
