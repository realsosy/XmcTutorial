/*
 * main.c
 *
 *  Created on: 2017 Jan 11 13:12:09
 *  Author: Wootaik
 */

/*********************************************************************************************************************
 * HEADER FILES
 ********************************************************************************************************************/
#include <xmc_common.h>
#include <xmc_gpio.h>

/*********************************************************************************************************************
 * MACROS
 ********************************************************************************************************************/
/* 1ms tick */
#define TICKS_PER_SECOND (1000U)
#define SECONDS_PER_TICK (1.0F / (float)TICKS_PER_SECOND)

#define LED1 P1_1

/*********************************************************************************************************************
 * GLOBAL DATA
 ********************************************************************************************************************/
uint8_t g_var;

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code.
 */

int main(void)
{
  g_var = 0;

  XMC_GPIO_SetMode(LED1, XMC_GPIO_MODE_OUTPUT_PUSH_PULL);

  SysTick_Config(SystemCoreClock / TICKS_PER_SECOND);

  while(1U);
}

void SysTick_Handler(void)
{
  static uint32_t ticks = 0;

  ticks++;

  if (ticks == TICKS_PER_SECOND)
  {
	ticks = 0;

	XMC_GPIO_ToggleOutput(LED1);
	g_var++;
  }

}
