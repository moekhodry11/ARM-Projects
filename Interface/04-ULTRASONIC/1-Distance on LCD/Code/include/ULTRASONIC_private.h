/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 12/12/2023      **********************/
/***************  SWC    : ULTRASONIC      **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef ULTRASONIC_PRIVATE_H
#define ULTRASONIC_PRIVATE_H

/*******************************************************************************
 *                      Private Functions Prototypes                           *
 *******************************************************************************/

static volatile u32 Time_Start = 0;
static volatile u32 Time_End = 0;
static volatile u32 Time_Diff = 0;

static volatile u8 TimeOutFlag = 0;

static void HULTRASONIC_voidNOP(void);

#endif
