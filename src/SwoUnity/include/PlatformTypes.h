/******************************************************************************/
/**
 * @file         PlatformTypes.h
 *
 * @brief        Platform Data Type Header
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

#ifndef PLATFORMTYPES_H
#define PLATFORMTYPES_H

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*
 * File version information
 */
#define PLATFORM_MAJOR_VERSION 1
#define PLATFORM_MINOR_VERSION 0

#define MINGW32 	0
#define DAVE		1

#if COMPILER == MINGW32
	#include "PlatformMingw32.h"
#elif COMPILER == DAVE
	//#include <DAVE.h>
	#include "xmc_common.h"
#else
	#error COMPILER is NOT defined. Add -d [compiler_selection] in command line.
#endif


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*
 * AUTOSAR integer data types
 */
typedef signed char    sint8;               /*        -128 .. +127            */
typedef unsigned char  uint8;               /*           0 .. 255             */
typedef signed short   sint16;              /*      -32768 .. +32767          */
typedef unsigned short uint16;              /*           0 .. 65535           */
typedef signed long    sint32;              /* -2147483648 .. +2147483647     */
typedef unsigned long  uint32;              /*           0 .. 4294967295      */
typedef float          float32;
typedef double         float64;

typedef unsigned long  uint8_least;         /* At least 8 bit                 */
typedef unsigned long  uint16_least;        /* At least 16 bit                */
typedef unsigned long  uint32_least;        /* At least 32 bit                */
typedef signed long    sint8_least;         /* At least 7 bit + 1 bit sign    */
typedef signed long    sint16_least;        /* At least 15 bit + 1 bit sign   */
typedef signed long    sint32_least;        /* At least 31 bit + 1 bit sign   */

typedef unsigned char  boolean;             /* for use with TRUE/FALSE        */

#ifndef TRUE                                /* conditional check */
#define TRUE  1
#endif

#ifndef FALSE                                            /* conditional check */
#define FALSE 0
#endif

/*******************************************************************************
**                      Global Type attribute modification                    **
*******************************************************************************/

#define EXTERN extern

#ifdef DEBUG
	#define STATIC
	#define CONST
#else
	#define STATIC static
	#define CONST const
#endif

#endif
