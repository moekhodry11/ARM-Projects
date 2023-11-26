/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 24/11/2023      **********************/
/***************  SWC    : MAIN		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"

/* Functions declaration */

/* Global variables */

void main(void) {

	/* Init. Clocks */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2, RCC_GPIOA); // Enable perph 2(PORTA) on APB2 bus

	/* IO Pins Init. */
	MGPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT_2M_PP); //Red LED
	MGPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT_2M_PP); //Green LED
	MGPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN3, GPIO_OUTPUT_2M_PP); //Blue LED

	/* Init. IR */
	HIR_voidInit();

	while (1) {

		u8 IR_Value = HIR_u8GetCodeDecimal();
		if (IR_Value) {

			switch (IR_Value) {
			case 69:
				MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
				break;

			case 68:
				MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
				break;

			case 70:
				MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
				break;

			case 64:
				MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);
				break;

			case 71:
				MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_HIGH);
				break;

			case 67:
				MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN3, GPIO_LOW);
				break;

			default:
				break;
			}

		}
	}

}

/* Functions initialization */
