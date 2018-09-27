/******************************************************************************/
/**
 * file         Ultrasonic.h
 *
 * brief        Header file for Ultrasonic
 *
 * version      1.00
 * date         Feb/27/2018
 * warning
 * note
 * ---------------------------------------------------------------------------
 *               R E V I S I O N   H I S T O R Y
 * ---------------------------------------------------------------------------
 *   Date        Version  Author  Description
 *  ----------   -------  ------  --------------------------------------------
 *  2018-09-27   1.00             - Creation Release
 *
 */
/******************************************************************************/

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

/******************************************************************************/
/* Include                                                                    */
/******************************************************************************/
#include <Dave.h>

/******************************************************************************/
/* PUBLIC DEFINITIONS AND MACROS                                              */
/******************************************************************************/
#define UR_RES 60000

/******************************************************************************/
/* PUBLIC TYPEDEFS AND STRUCTURES                                             */
/******************************************************************************/


/******************************************************************************/
/* PUBLIC VARIABLES                                                           */
/******************************************************************************/
extern uint32_t u32CapturedTick;
extern float fltCapturedTime;
extern float fltDistance;
extern uint32_t u32SwTimer_60ms;

/******************************************************************************/
/* PUBLIC FUNCTIONS                                                           */
/******************************************************************************/
void CB_dhSYSTIMER_0_u32SwTimer_60ms(void);
void Ultrasonic_Init(void);

/***************************************************************************/
/**
brief      Initialization of the timer for scheduler
param[in]  pParam   Pointer to the parameters structure.
param[out] pState   Pointer to the state structure.
param[in,out] pi32InBuf Pointer to a buffer for storing input signal
return     void.

void Sche_InitTimer(const sScheTable_t * pParam,
                               eScheStatus_t * pState,
                               int32_t *pi32InBuf);
 */


#endif

/******************************************************************************/
/*                            EOF                                             */
/******************************************************************************/
