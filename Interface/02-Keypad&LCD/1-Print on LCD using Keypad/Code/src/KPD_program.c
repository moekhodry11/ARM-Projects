/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 13/12/2023      **********************/
/***************  SWC    : KPD             **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "GPIO_interface.h"
#include "STK_interface.h"
/* HAL */
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

const u8 KPD_Au8Keys[4][4]= KPD_KEYS;

const u8 KPD_Au8RowsPins[4]={KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R4_PIN};
const u8 KPD_Au8ColsPins[4]={KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN,KPD_u8_C4_PIN};


void HKPD_voidInit(void)
{
	/* Init. Rows as Output */
	MGPIO_voidSetPinDirection(KPD_ROWS_u8_PORT,KPD_u8_R1_PIN,GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(KPD_ROWS_u8_PORT,KPD_u8_R2_PIN,GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(KPD_ROWS_u8_PORT,KPD_u8_R3_PIN,GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(KPD_ROWS_u8_PORT,KPD_u8_R4_PIN,GPIO_OUTPUT_2M_PP);

	/* Init. Cols as Input */
	MGPIO_voidSetPinDirection(KPD_COLS_u8_PORT,KPD_u8_C1_PIN,GPIO_INPUT_PULL_UP_DOWN);
	MGPIO_voidSetPinDirection(KPD_COLS_u8_PORT,KPD_u8_C2_PIN,GPIO_INPUT_PULL_UP_DOWN);
	MGPIO_voidSetPinDirection(KPD_COLS_u8_PORT,KPD_u8_C3_PIN,GPIO_INPUT_PULL_UP_DOWN);
	MGPIO_voidSetPinDirection(KPD_COLS_u8_PORT,KPD_u8_C4_PIN,GPIO_INPUT_PULL_UP_DOWN);

	/* Init. Rows as High */
	MGPIO_voidSetPinValue(KPD_ROWS_u8_PORT,KPD_u8_R1_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(KPD_ROWS_u8_PORT,KPD_u8_R2_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(KPD_ROWS_u8_PORT,KPD_u8_R3_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(KPD_ROWS_u8_PORT,KPD_u8_R4_PIN,GPIO_HIGH);

	/* Init. cOLS as Pull-Up */
	MGPIO_voidSetPinValue(KPD_COLS_u8_PORT,KPD_u8_C1_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(KPD_COLS_u8_PORT,KPD_u8_C2_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(KPD_COLS_u8_PORT,KPD_u8_C3_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(KPD_COLS_u8_PORT,KPD_u8_C4_PIN,GPIO_HIGH);
}

u8 HKPD_u8GetKeyState(u8 * Copy_pu8ReturnedKey)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8RowsCounter,Local_u8ColsCounter,Local_u8Flag = 0;
	if(Copy_pu8ReturnedKey != NULL)
	{
		*Copy_pu8ReturnedKey = KPD_u8_KEY_NOT_PRESSED;
		/* Activate Each Row => For loop on the pins of the rows */
		for(Local_u8RowsCounter = 0; Local_u8RowsCounter <= 3 ; Local_u8RowsCounter++)
		{
			 MGPIO_voidSetPinValue(KPD_ROWS_u8_PORT,KPD_Au8RowsPins[Local_u8RowsCounter],GPIO_LOW);

			/* Check Which Input Pin Has Zero */
			for(Local_u8ColsCounter = 0; Local_u8ColsCounter <= 3 ; Local_u8ColsCounter++)
			{

				if(MGPIO_u8GetPinValue(KPD_COLS_u8_PORT,KPD_Au8ColsPins[Local_u8ColsCounter]) == 0)/* Switch is Pressed */
				{
					/* Debouncing */
					MSTK_voidSetBusyWait(20000);

					/* Check if the Pin is still equal LOW */
					while(MGPIO_u8GetPinValue(KPD_COLS_u8_PORT,KPD_Au8ColsPins[Local_u8ColsCounter]) == GPIO_LOW);
					*Copy_pu8ReturnedKey = KPD_Au8Keys[Local_u8RowsCounter][Local_u8ColsCounter];
					Local_u8Flag = 1;
					break;
				}
			}
			/* Deactivate Row */
			MGPIO_voidSetPinValue(KPD_ROWS_u8_PORT,KPD_Au8RowsPins[Local_u8RowsCounter],GPIO_HIGH);
			if(Local_u8Flag == 1)
			{	
				break;	
			}
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}
