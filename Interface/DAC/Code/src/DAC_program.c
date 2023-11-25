/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 25/11/2023      **********************/
/***************  SWC    : DAC		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "STD_TYPES.h"		
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"
#include "file.h"

#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"



/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void HDAC_voidInit(void)
{
	/* Set DAC IO pins directions */
	MGPIO_voidSetPinDirection(DAC_PORT , DAC_BIT0_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(DAC_PORT , DAC_BIT1_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(DAC_PORT , DAC_BIT2_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(DAC_PORT , DAC_BIT3_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(DAC_PORT , DAC_BIT4_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(DAC_PORT , DAC_BIT5_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(DAC_PORT , DAC_BIT6_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(DAC_PORT , DAC_BIT7_PIN , GPIO_OUTPUT_2M_PP);
	
	/* Initialize SysTick */
	MSTK_voidInit();
	/* Interrupt every 125us , sample rate = (8000/sec) */
	MSTK_voidSetIntervalPeriodic(125, SetDac);
}

volatile u16 Dac_Index=0;
void SetDac (void)
{
	u8 Local_u8 = 0;
	Local_u8 = oka_raw[Dac_Index];
	MGPIO_voidSetPinValue(DAC_PORT , DAC_BIT0_PIN , GET_BIT(Local_u8 , 0) );
	MGPIO_voidSetPinValue(DAC_PORT , DAC_BIT1_PIN , GET_BIT(Local_u8 , 1) );
	MGPIO_voidSetPinValue(DAC_PORT , DAC_BIT2_PIN , GET_BIT(Local_u8 , 2) );
	MGPIO_voidSetPinValue(DAC_PORT , DAC_BIT3_PIN , GET_BIT(Local_u8 , 3) );
	MGPIO_voidSetPinValue(DAC_PORT , DAC_BIT4_PIN , GET_BIT(Local_u8 , 4) );
	MGPIO_voidSetPinValue(DAC_PORT , DAC_BIT5_PIN , GET_BIT(Local_u8 , 5) );
	MGPIO_voidSetPinValue(DAC_PORT , DAC_BIT6_PIN , GET_BIT(Local_u8 , 6) );
	MGPIO_voidSetPinValue(DAC_PORT , DAC_BIT7_PIN , GET_BIT(Local_u8 , 7) );
	Dac_Index++;
	if (Dac_Index == 38824 )
	{
		Dac_Index = 0;
	}
}
