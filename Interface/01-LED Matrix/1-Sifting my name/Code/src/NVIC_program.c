/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 24/11/2023      **********************/
/***************  SWC    : NVIC		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/* Note : In Embedded System Architecture you shouldn't use another periphral register like this */
/* This function used to set the priority bits (group and sub) */
void MNVIC_voidInit(void)
{
	#define SCB_AIRCR	*(( u32*)0xE000ED0C)
	SCB_AIRCR  = NVIC_GROUP_DISTRIBUTION;	
}



void MNVIC_voidEnableInterrupt(u8 copy_u8PeripheralInt)
{
	if(copy_u8PeripheralInt <= 31)
	{
		NVIC_ISER0 = (1<<copy_u8PeripheralInt);
	}
	
	else if(copy_u8PeripheralInt <= 59)
	{
		copy_u8PeripheralInt -= 32;
		NVIC_ISER1 = (1<<copy_u8PeripheralInt);
	}
}



void MNVIC_voidDisableInterrupt(u8 copy_u8PeripheralInt)
{
	if(copy_u8PeripheralInt <= 31)
	{
		NVIC_ICER0 = (1<<copy_u8PeripheralInt);
	}
	
	else if(copy_u8PeripheralInt <= 59)
	{
		copy_u8PeripheralInt -= 32;
		NVIC_ICER1 = (1<<copy_u8PeripheralInt);
	}
}



void MNVIC_voidSetPendingFlag(u8 copy_u8PeripheralInt)
{
	if(copy_u8PeripheralInt <= 31)
	{
		NVIC_ISPR0 = (1<<copy_u8PeripheralInt);
	}
	
	else if(copy_u8PeripheralInt <= 59)
	{
		copy_u8PeripheralInt -= 32;
		NVIC_ISPR1 = (1<<copy_u8PeripheralInt);
	}
}



void MNVIC_voidClearPendingFlag(u8 copy_u8PeripheralInt)
{
	if(copy_u8PeripheralInt <= 31)
	{
		NVIC_ICPR0 = (1<<copy_u8PeripheralInt);
	}
	
	else if(copy_u8PeripheralInt <= 59)
	{
		copy_u8PeripheralInt -= 32;
		NVIC_ICPR1 = (1<<copy_u8PeripheralInt);
	}
}




u8 MNVIC_u8GetActiveFlag(u8 copy_u8PeripheralInt)
{
	u8 Local_u8Result=0;
	if(copy_u8PeripheralInt <= 31)
	{
		Local_u8Result = GET_BIT( NVIC_IABR0 , copy_u8PeripheralInt );
	}
	
	else if(copy_u8PeripheralInt <= 59)
	{
		copy_u8PeripheralInt -= 32;
		Local_u8Result = GET_BIT( NVIC_IABR1 , copy_u8PeripheralInt );
	}
	
	return Local_u8Result;
}


void MNVIC_voidSetPriority (u8 copy_u8PeripheralInt , u8 copy_u8GroupPriority , u8 copy_u8SubPriority)
{
	if(copy_u8PeripheralInt <= 59)
	{
	u8 Local_u8Priority = copy_u8SubPriority | (copy_u8GroupPriority << ( (NVIC_GROUP_DISTRIBUTION - 0x05FA0300)/256) ) ;
	
	NVIC_IPR[copy_u8PeripheralInt] = Local_u8Priority << 4;
	}
	
	else
	{
		/* Return Error */
	} 
	
}



