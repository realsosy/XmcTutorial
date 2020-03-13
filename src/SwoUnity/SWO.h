/*
 * SWO.h
 *
 *  Created on: Mar 13, 2020
 *      Author: Wootaik Lee
 */

#ifndef SWO_H_
#define SWO_H_

/*********************************************************************
*
*       Prototypes (to be placed in a header file such as SWO.h)
*/

#include "xmc_common.h"

#define SWO_PrintChar(c) ITM_SendChar(c)
//void SWO_PrintChar  (char c);

void SWO_PrintString(const char *s);


#endif /* SWO_H_ */
