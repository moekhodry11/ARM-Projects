/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/12/2023      **********************/
/***************  SWC    : MAIN		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"

/* Functions declaration */

/* Global variables */

void main(void) {

	/* Init. Clocks */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2, RCC_GPIOA); // Enable perph 2(PORTA) on APB2 bus
	MRCC_voidEnableClock(RCC_APB2, RCC_GPIOB); // Enable perph 3(PORTB) on APB2 bus

	/* IO Pins Init. */

	/* Init. */
	MSTK_voidInit();
	HLCD_voidInit();
	HKPD_voidInit();

	while (1) {

		u8 Local_u8Key = 0;
		HKPD_u8GetKeyState(&Local_u8Key);

		if (Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
			HLCD_voidSendChar(Local_u8Key);

	}
}

/* Functions initialization */
