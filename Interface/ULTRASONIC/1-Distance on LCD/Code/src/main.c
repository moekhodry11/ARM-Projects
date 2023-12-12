/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 12/12/2023      **********************/
/***************  SWC    : MAIN		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "LCD_interface.h"
#include "ULTRASONIC_interface.h"

/* Functions Declaration */

void main(void) {

	/* Init. Clocks */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2, RCC_GPIOA); // Enable perph. 2(PORTA) on APB2 bus
	MRCC_voidEnableClock(RCC_APB2, RCC_GPIOB); // Enable perph. 3(PORTB) on APB2 bus

	/* IO Pins Init. */

	/* Init. */
	MSTK_voidInit();
	HLCD_voidInit();
	HULTRASONIC_voidInit();

	/* Local Variables */
	u16 distance;

	while (1) {

		/* Get Distance */
		distance = HULTRASONIC_u16GetDistance();

		/* Display distance on LCD */
		HLCD_voidGotoxy(0, 0);
		if (distance < 401) {
			HLCD_voidSendIntger((u32) distance);
			HLCD_voidSendString("cm   ");
		} else
			HLCD_voidSendString("OUT OF RANGE");

		/* Delay */
		MSTK_voidSetBusyWait(1000000);

		/* Clear LCD */
		HLCD_voidSendCmnd(LCD_CLEAR);
	}
}

/* Functions initialization */
