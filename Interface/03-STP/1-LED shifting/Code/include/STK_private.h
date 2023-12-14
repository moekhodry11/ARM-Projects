/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 24/11/2023      **********************/
/***************  SWC    : Sys Tick        **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/*******************************************************************************
 *                      Global variables Definitions                           *
 *******************************************************************************/

static void (*MSTK_CallBack)(void);
static u8 MSTK_u8ModeOfInterval;

/*******************************************************************************
 *                      Registers Definitions                                  *
 *******************************************************************************/

#define STK_CTRL		*((volatile u32*)0xE000E010)
#define STK_LOAD		*((volatile u32*)0xE000E014)
#define STK_VAL			*((volatile u32*)0xE000E018)
#define STK_CALIB		*((volatile u32*)0xE000E01C)

/*******************************************************************************
 *                      Hash Defines For Conguration                           *
 *******************************************************************************/

#define MSTK_SINGLE_INTERVAL		0
#define MSTK_PERIODIC_INTERVAL		1

/* For SysTick Clock */
#define MSTK_AHB_CLK_8				0
#define MSTK_AHB_CLK				1



#endif
