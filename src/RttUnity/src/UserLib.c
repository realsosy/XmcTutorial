/***************************************************************************//*!
*
* @file     UserLib.c
*
* @author
*
* @version
*
* @date
*
* @brief    Source file containing routines ....
*
******************************************************************************/

/******************************************************************************
| Includes
-----------------------------------------------------------------------------*/
#include "UserLib.h"


/******************************************************************************
| External declarations
-----------------------------------------------------------------------------*/

/******************************************************************************
| Defines and macros            (scope: module-local)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Typedefs and structures       (scope: module-local)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Global variable definitions   (scope: module-exported)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Global variable definitions   (scope: module-local)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Function prototypes           (scope: module-local)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Function implementations      (scope: module-local)
-----------------------------------------------------------------------------*/

/******************************************************************************
| Function implementations      (scope: module-exported)
-----------------------------------------------------------------------------*/

float UserLib_Hyst(float fltIn, UserLib_Hyst_t* pParam)
{
	/*lint --e(64, 530) */
	float  flt_temp;

    flt_temp = (fltIn < pParam->fltHystOn) ? pParam->fltOutState : pParam->fltOutOn ;

    pParam->fltOutState = (fltIn <= pParam->fltHystOff) ? pParam->fltOutOff : flt_temp ;

    return(pParam->fltOutState);

}

float UserLib_Ramp(float fltIn, UserLib_Ramp_t* pParam)
{

    float  flt_state;
    float  flt_inc;
    float  flt_dec;

    flt_inc = pParam->fltState + pParam->fltIncrement;
    flt_dec = pParam->fltState + pParam->fltDecrement;

    flt_state = (pParam->fltState <= fltIn) ? flt_inc : flt_dec;

    pParam->fltState = (((flt_state >= fltIn) && (pParam->fltState <= fltIn)) ||
                       ((flt_state <= fltIn) && (pParam->fltState > fltIn))) ?
                        fltIn : flt_state;
    return(pParam->fltState);

}


/* End of file */

