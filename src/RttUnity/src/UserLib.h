/***************************************************************************/
/**
 * @file     UserLib.h
 *
 * @brief       Header file for IntMath
 *
 * @version     1.00
 * @date        Feb/18/2010
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

#ifndef USERLIB_H_
#define USERLIB_H_

/**
 * @defgroup UserLib UserLib
 * @{
 */

/******************************************************************************/
/* HEADER FILES                                                               */
/******************************************************************************/

#include "PlatformTypes.h"

/******************************************************************************
| Defines and macros            (scope: module-local)
-----------------------------------------------------------------------------*/
#define USERLIB_RAMP_DEFAULT    {0.0, 0.0, 0.0}

#define USERLIB_HYST_DEFAULT    {0.0, 0.0, 0.0, 0.0, 0.0}

/******************************************************************************
| Typedefs and structures       (scope: module-local)
-----------------------------------------------------------------------------*/

typedef struct
{
    float   fltHystOn;
    float   fltHystOff;
    float   fltOutOn;
    float   fltOutOff;
    float   fltOutState;
} UserLib_Hyst_t;

typedef struct
{
    float   fltState;
    float   fltIncrement;
    float   fltDecrement;
} UserLib_Ramp_t;


/******************************************************************************
| Exported Variables
-----------------------------------------------------------------------------*/


/******************************************************************************
| Exported function prototypes
-----------------------------------------------------------------------------*/

/**************************************************************************//*!

@brief      Hysteresis function

@param[in]   fltIn      Input argument
@param[out]  *pParam    Pointer to parameters

@return     The function returns f32 value, which represents
            the actual output value

@details

@note       All parameters and states, used by the function, can be reset...
******************************************************************************/
float UserLib_Hyst(float flt_in, UserLib_Hyst_t* );

/**************************************************************************//*!

@brief      The function calculates the Increment/decrement ramp

@param[in]    fltIn      Input argument representing the desired output value.
@param[out]  *pParam     Pointer to parameters

@return     The function returns f32 value, which represents
            the actual ramp output value

@details

@note       All parameters and states, used by the function, can be reset...
******************************************************************************/
float UserLib_Ramp(float flt_in, UserLib_Ramp_t* );

/** @} */

#endif /* USERLIB_H_ */
