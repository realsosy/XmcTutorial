/*
 * main.c
 *
 *  Created on: 2020 Sep 24 16:12:03
 *  Author: Wootaik
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include <time.h>

 void Time_Handler(void)
 {
   DIGITAL_IO_ToggleOutput(&dhDIGITAL_IO_0);
 }

 void Alarm_Handler(void)
 {
   XMC_RTC_ALARM_t alarm_time;

   DIGITAL_IO_ToggleOutput(&dhDIGITAL_IO_1);

   RTC_GetAlarmTime(&alarm_time);     // Read the current alarm time

   alarm_time.seconds = alarm_time.seconds + 10;
   if(alarm_time.seconds > 59)
   {
       alarm_time.seconds = 0;
       alarm_time.minutes++;
   }

   if(alarm_time.minutes > 59)
   {
		 alarm_time.minutes = 0;
		 alarm_time.hours++;
   }

  RTC_SetAlarmTime(&alarm_time);     // Reconfigure alarm time for next minute
 }



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
  XMC_RTC_TIME_t timeval =
  {
	.seconds = 0U,
	.minutes = 0U,
	.hours = 0U,
	.days = 3U,
	.month = 10,
	.year = 2020U
  };

  XMC_RTC_ALARM_t alarm =
  {
     .seconds = 10U,
     .minutes = 0U,
     .hours = 0U,
     .days = 3U,
     .month = 10,
     .year = 2020U
  };


  struct tm stdtimeval;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */
  RTC_SetTime(&timeval);
  RTC_SetAlarmTime(&alarm);

  if(status != DAVE_STATUS_SUCCESS)
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
    RTC_GetTime(&timeval);
    RTC_GetStdTime(&stdtimeval);
  }
}
