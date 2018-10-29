/******************************************************************************/
/**
 * file         StopLight.c
 *
 * brief        C file for StopLight
 *
 * version      1.00
 * date         Feb/18/2010
 * warning
 * note
 * ---------------------------------------------------------------------------
 *               R E V I S I O N   H I S T O R Y
 * ---------------------------------------------------------------------------
 *   Date        Version  Author  Description
 *  ----------   -------  ------  --------------------------------------------
 *  2010-02-18   1.00             - Creation Release
 *
 */
/******************************************************************************/

/******************************************************************************/
/* HEADER FILES                                                               */
/******************************************************************************/
#include <stdbool.h>
#include "StopLight.h"


/******************************************************************************/
/* PRIVATE DEFINITIONS AND MACROS (scope: file)                               */
/******************************************************************************/


/******************************************************************************/
/* PRIVATE TYPEDEFS AND STRUCTURES (scope: file)                              */
/******************************************************************************/


/******************************************************************************/
/* PUBLIC VARIABLES                                                           */
/******************************************************************************/
Light_t Light;
StopLightState_t StopLightState = 0;

/******************************************************************************/
/* PRIVATE VARIABLES                                                          */
/******************************************************************************/

// Variables for test purpose *****************************************/
bool evGo = false;
bool evStop = false;
bool evTimeout = false;


/******************************************************************************/
/* PRIVATE Function Prototype (scope: file)                                   */
/******************************************************************************/


/******************************************************************************/
/* PRIVATE Function Implementation (scope: file)                              */
/******************************************************************************/


/******************************************************************************/
/* PUBLIC Function Implementation                                             */
/******************************************************************************/
void StopLight()
{
    switch(StopLightState){
   
    case STOPLIGHT_INIT:
    	StopLightState = STOPLIGHT_RED;
    	break;

    case STOPLIGHT_RED:
    	Light = LIGHT_RED_ONLY;
    	if(evGo == true){
        	StopLightState = STOPLIGHT_GREEN;
    	}
    	break;

    case STOPLIGHT_GREEN:

    	break;

    case STOPLIGHT_YELLOW:

    	break;
    default :
    	;

    }
}

/******************************************************************************/
/*                                                                            */
/*                            EOF                                             */
/*                                                                            */
/******************************************************************************/


