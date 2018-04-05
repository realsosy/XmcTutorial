/*
 * main.c
 *
 *  Created on: 2018 Apr 05 15:56:50
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

#include "PolarCartesian.h"

#define PI 3.141592

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

  polar_t my_polar, result_polar;
  xy_t my_xy, result_xy;

  my_xy.x = 1.0;
  my_xy.y = 1.732;

  my_polar.mag = 2.0;
  my_polar.angle = 60.0 * PI / 180;

  xy2polar(&my_xy, &result_polar);

  //polar2xy(       );  /* <--Need to modify */

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {

  }
}

