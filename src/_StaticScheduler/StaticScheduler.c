/******************************************************************************/
/**
 * @file         StaticScheduler.c
 *
 * @brief        C file for StaticScheduler
 *
 * @version      1.00
 * @date         Feb/18/2010
 * @warning
 * @note
 * <pre>
 * ---------------------------------------------------------------------------
 *               R E V I S I O N   H I S T O R Y
 * ---------------------------------------------------------------------------
 *   Date        Version  Author  Description
 *  ----------   -------  ------  --------------------------------------------
 *  2010-02-18   1.00             - Creation Release
 * </pre>
 *
 */
/******************************************************************************/

#ifndef STATICSCHEDULER_C
#define STATICSCHEDULER_C

/**
 * @defgroup STATICSCHEDULER
 * @{
 */

/******************************************************************************/
/* HEADER FILES                                                               */
/******************************************************************************/

/**** Standard types & definitions ****/

/**** Project types & definitions ****/
#include "probe_scope.h"

/**** Miscellaneous types & definitions ****/
#include "StaticScheduler.h"

/******************************************************************************/
/* DEFINITIONS AND MACROS (scope: file)                                       */
/******************************************************************************/


/******************************************************************************/
/* TYPEDEFS AND STRUCTURES (scope: file)                                      */
/******************************************************************************/

/**** enum type definitions ***************************************************/


/**** structures type definitions ********************************************/

/**** extra type definitions ****/

/******************************************************************************/
/* EXPORTED VARIABLES (scope: exported)                                       */
/******************************************************************************/


/******************************************************************************/
/* FILE VARIABLES (scope: file)                                               */
/******************************************************************************/
static uint32_t TaskId1ms=0;
static uint32_t TickCounter = 0;
static bool Task1msFlag = false;
static bool Task10msFlag = false;
static bool Task100msFlag = false;
static bool Task1000msFlag = false;

/******************************************************************************/
/* Function Prototype (scope: file)                                           */
/******************************************************************************/
static void TaskInit(void);
static void TaskIdle(void);
static void Task1ms(void);
static void Task10ms(void);
static void Task100ms(void);
static void Task1000ms(void);

/******************************************************************************/
/* Function Implementation (scope: file)                                  */
/******************************************************************************/

static void TaskInit(void){
    /* Initialize ProbeScope */
    ProbeScope_Init(1000); /* 1 KHz */
}

uint32_t Ticks1ms = 0;
static void Task1ms(void){
	Ticks1ms++;
	if(Ticks1ms%1000 == 0){
		Ticks1ms = 0;
	}
	/* Take a sample of the active oscilloscope channels */
	ProbeScope_Sampling();

}

uint32_t Ticks10ms = 0;
static void Task10ms(void){
	Ticks10ms++;
	if(Ticks10ms%100 == 0){
		Ticks10ms = 0;
	}

}

static void Task100ms(void){
	DIGITAL_IO_ToggleOutput(&dhDO_100ms);
}

static void Task1000ms(void){

}

void TaskIdle(){


}

void CallBack1ms(){
	TickCounter++;
	if(TickCounter == 1000){
		TickCounter = 0;
	}
	if(TickCounter%1 == 0){
		Task1msFlag = true;
	}
	if(TickCounter%10 == 1){
		Task10msFlag = true;
	}
	if(TickCounter%100 == 2){
		Task100msFlag = true;
	}
	if(TickCounter%1000 == 3){
		Task1000msFlag = true;
	}
}

/******************************************************************************/
/* Function Implementation (scope: exported)                                  */
/******************************************************************************/
void StaticScheduler_Init(void){

	TaskId1ms = SYSTIMER_CreateTimer(1000, SYSTIMER_MODE_PERIODIC, CallBack1ms, NULL);

	TaskInit();

	SYSTIMER_StartTimer(TaskId1ms);

}

void StaticScheduler_Loop(void){

	if(Task1msFlag == true){
		Task1ms();
		Task1msFlag = false;
	}

	if(Task10msFlag == true){
		Task10ms();
		Task10msFlag = false;
	}

	if(Task100msFlag == true){
		Task100ms();
		Task100msFlag = false;
	}

	if(Task1000msFlag == true){
		Task1000ms();
		Task1000msFlag = false;
	}

	TaskIdle();
}


/******************************************************************************/
/*                                                                            */
/*                            EOF                                             */
/*                                                                            */
/******************************************************************************/

/** @} */
#endif
