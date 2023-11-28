/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 26/11/2023      **********************/
/***************  SWC    : EXTI		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "STD_TYPES.h"		
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"



#define NULL		(void * )0
static void (* EXTI_CallBack) (void) = NULL ;

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void MEXTI_voidInit (void)
{
	
	SET_BIT(EXTI -> IMR , EXTI_LINE);
	
	/* Enable Sense Mode */
	#if 	EXTI_SENSE_MODE == FALLING_EDGE
		SET_BIT(EXTI -> FTSR , EXTI_LINE);
		
	#elif 	EXTI_SENSE_MODE == RISING_EDGE
		SET_BIT(EXTI -> RTSR , EXTI_LINE);
		
	#elif 	EXTI_SENSE_MODE == ON_CHANGE
		SET_BIT(EXTI -> FTSR , EXTI_LINE);
		SET_BIT(EXTI -> RTSR , EXTI_LINE);
	
	#endif

}



void MEXTI_voidSetSignalLatch(u8 copy_u8SenseMode , u8 copy_u8EXTILine)
{
	
	SET_BIT(EXTI -> IMR , copy_u8EXTILine);
	
	/* Enable Sense Mode */
	switch(copy_u8SenseMode)
	{
		case EXTI_RISING_EDGE:  SET_BIT(EXTI -> RTSR , copy_u8EXTILine); break;
		case EXTI_FALLING_EDGE: SET_BIT(EXTI -> FTSR , copy_u8EXTILine); break;
		case EXTI_ON_CHANGE:    SET_BIT(EXTI -> RTSR , copy_u8EXTILine); 
								SET_BIT(EXTI -> FTSR , copy_u8EXTILine); break;
	}
}




void MEXTI_voidEnableEXTI (u8 copy_u8Line)
{	
	SET_BIT(EXTI -> IMR , copy_u8Line);
}


void MEXTI_voidDisableEXTI (u8 copy_u8Line)
{
	CLR_BIT(EXTI -> IMR , copy_u8Line);	
}



void MEXTI_voidSwTrigger (u8 copy_u8Line)
{
	
}


void MEXTI_voidSetCallBack ( void (*Copy_ptr) (void) )
{
	EXTI_CallBack = Copy_ptr;
}


void EXTI0_IRQHandler(void)
{
	EXTI_CallBack();
	/* Clear the pending bit for EXTI0 */
	SET_BIT(EXTI -> PR , 0);
}
