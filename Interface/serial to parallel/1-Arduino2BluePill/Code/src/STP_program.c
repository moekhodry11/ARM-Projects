/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 28/11/2023      **********************/
/***************  SWC    : STP		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "STD_TYPES.h"		
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"



/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void HSTP_voidInit(void)
{
	MGPIO_voidSetPinDirection(STP_PORT, STP_SERIAL_DATA_PIN   , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(STP_PORT, STP_SHIFT_CLOCK_PIN   , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(STP_PORT, STP_STORAGE_CLOCK_PIN , GPIO_OUTPUT_2M_PP);
}


void HSTP_voidSendSynchronous(u32 Copy_u8DataToSend)
{
	s8 Local_s8Counter = 0;
	u8 Local_u8Bit = 0;
	/* Send bit by bit starting from MSB */
	for(Local_s8Counter= ( 7*STP_NUM_OF_IC_S + STP_NUM_OF_IC_S - 1 ) ; Local_s8Counter >= 0 ; Local_s8Counter--)
	{
		Local_u8Bit = GET_BIT(Copy_u8DataToSend , Local_s8Counter);
		MGPIO_voidSetPinValue(STP_PORT , STP_SERIAL_DATA_PIN , Local_u8Bit);
		
		/* Send a pulse to shitf clock */
		MGPIO_voidSetPinValue(STP_PORT , STP_SHIFT_CLOCK_PIN , GPIO_HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(STP_PORT , STP_SHIFT_CLOCK_PIN , GPIO_LOW);
		MSTK_voidSetBusyWait(1);
	}
	
	/* Send a pulse to storage clock */
	MGPIO_voidSetPinValue(STP_PORT , STP_STORAGE_CLOCK_PIN , GPIO_HIGH);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(STP_PORT , STP_STORAGE_CLOCK_PIN , GPIO_LOW);
	MSTK_voidSetBusyWait(1);	
}
