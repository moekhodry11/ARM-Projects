/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/12/2023      **********************/
/***************  SWC    : MAIN		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "ADC_interface.h"
#include "LCD_interface.h"

/* Functions declaration */

/* Global variables */

void main(void){

	/* Init. Clocks */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2, RCC_GPIOA); // Enable perph 2(PORTA) on APB2 bus
	// enable adc1 clock
	MRCC_voidEnableClock(RCC_APB2, RCC_ADC1);

	/* IO Pins Init. */
	MGPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT_ANALOG);

	/* Init. */
	MSTK_voidInit();
	HLCD_voidInit();
	// init adc
	MADC_voidInit();

	while (1){
		u16 adcValue;

		/* Start ADC conversion */
		MADC_voidStartConversion();

		/* Read ADC converted value */
		adcValue = MADC_u16GetConvertedValue();

		float mv = adcValue * (5.0 / 4096.0);
		float cel = (mv - 0.5) * 100;

		/* Clear LCD */
		HLCD_voidSendCmnd(LCD_CLEAR);
		HLCD_voidGotoxy(0, 0);
		HLCD_voidSendString("ADC Value = ");

		HLCD_voidSendFloat(cel);

		/* Delay for readability */
		MSTK_voidSetBusyWait(1000000);
	}
}

/* Functions initialization */
