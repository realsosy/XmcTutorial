/******************************************************************************/
/**
 * @file         StaticScheduler.h
 *
 * @brief        Header file for StaticScheduler
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

#ifndef STATICSCHEDULER_H
#define STATICSCHEDULER_H

/**
 * @defgroup Static Scheduler
 * @{
 */

/******************************************************************************/
/* HEADER FILES                                                               */
/******************************************************************************/

#include <Dave.h>
#include "CollisionAvoidance.h"

/**** Project types & definitions ****/


/**** Miscellaneous types & definitions ****/


/******************************************************************************/
/* DEFINITIONS AND MACROS                                                     */
/******************************************************************************/


/******************************************************************************/
/* TYPEDEFS AND STRUCTURES                                                    */
/******************************************************************************/

/**** enum type definitions ***************************************************/


/**** structures type definitions ********************************************/


/**** extra type definitions ****/

/******************************************************************************/
/* EXPORTED VARIABLES                                                         */
/******************************************************************************/


/******************************************************************************/
/* EXPORTED FUNCTIONS                                                         */
/******************************************************************************/

/***************************************************************************/
/**
@brief      Initialization of the timer for scheduler
@param[in]  pParam   Pointer to the parameters structure.
@param[out] pState   Pointer to the state structure.
@param[in,out] pi32InBuf Pointer to a buffer for storing input signal
@return     void.
void Sche_InitTimer(const sScheTable_t * pParam,
                               eScheStatus_t * pState,
                               int32_t *pi32InBuf);
 */
void StaticScheduler_Init(void);
void StaticScheduler_Loop(void);

#endif

/******************************************************************************/
/*                            EOF                                             */
/******************************************************************************/

/** @} */
