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

#include <stdio.h>
#include <math.h>

#define PI 3.141592

float xy2mag(float x, float y);
float xy2angle(float x, float y);
float polar2x(float mag, float angle);
float polar2y(float mag, float angle);


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

  float x = 1.0;
  float y = 1.732;
  float result_x;
  float result_y;

  float mag = 2.0;
  float angle = 60.0 * PI / 180;
  float result_mag;
  float result_angle;

  result_mag = xy2mag(x,y);
  result_angle = xy2angle(x,y);

  result_x = polar2x(mag, angle);
  result_y = polar2y(mag, angle);

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {

  }
}

float xy2mag(float x, float y){
    float mag;
    mag = sqrt(pow(x,2.0) + pow(y,2.0));
    return mag;
}

float xy2angle(float x, float y){
    float angle;
    angle = atan(y/x);
    return angle;
}

float polar2x(float mag, float angle){
    float x;
    x = mag * cos(angle);
    return x;
}

float polar2y(float mag, float angle){
    float y;
    y = mag * sin(angle);
    return y;
}
