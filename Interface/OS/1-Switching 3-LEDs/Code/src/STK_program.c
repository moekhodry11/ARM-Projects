/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 24/11/2023      **********************/
/***************  SWC    : Sys Tick        **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void MSTK_voidInit(void)

{
	#if   STK_CLK_SRC == MSTK_AHB_CLK_8
	STK_CTRL = 0x00000002;
	#elif STK_CLK_SRC == MSTK_AHB_CLK
	STK_CTRL = 0x00000004;
	#endif
}



void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	STK_LOAD = Copy_u32Ticks;
	SET_BIT(STK_CTRL,0); /* Enable SysTick (start timer) */
	while(GET_BIT(STK_CTRL,16)==0); /* Polling on the flag until the count end */
	
	/* Stop timer */
	CLR_BIT(STK_CTRL,0); 
	STK_LOAD = 0;
	STK_VAL  = 0;
}


	
	
void MSTK_voidSetIntervalSingle  (u32 Copy_u32Ticks , void (*Copy_ptr)(void) )
{
	/* Disable Timer */
	CLR_BIT(STK_CTRL , 0);
	STK_VAL = 0;
	
	STK_LOAD = Copy_u32Ticks;
	STK_CTRL |= (1<<0) | (1<<1) ; /* Start timer and enable STK Interrupt */
	MSTK_CallBack = Copy_ptr;     /* Save Callback */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
}



void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_ptr)(void) )
{
	STK_LOAD = Copy_u32Ticks;
	STK_CTRL |= (1<<0) | (1<<1) ; /* Enable SysTick and SysTick Interrupt */
	MSTK_CallBack = Copy_ptr;
	MSTK_u8ModeOfInterval = MSTK_PERIODIC_INTERVAL;

}




void MSTK_voidStopTimer(void)
{
	STK_CTRL &= ~(1<<0) & ~(1<<1) ;
	STK_LOAD = 0;
	STK_VAL  = 0;
}



u32  MSTK_u32GetElapsedTime(void)
{
	return (STK_LOAD - STK_VAL);
}


u32  MSTK_u32GetRemainingTime(void)
{
	return STK_VAL;
}


/* ISR function */
void SysTick_Handler(void)
{
	u8 Local_u8Temp = 0;
	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		STK_CTRL &= ~(1<<0) & ~(1<<1) ;
		STK_LOAD = 0;
		STK_VAL  = 0;
	}
	
	MSTK_CallBack();
	
	/* Flag Clearance */
	Local_u8Temp = GET_BIT(STK_CTRL,16);
}
	
