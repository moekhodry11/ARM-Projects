/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 17/10/2023      **********************/
/***************  SWC    : MAIN		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

/* Libraries */
#include <STD_TYPES.h>
#include <BIT_MATH.h>

/* Header files */
#include "stm32f10x.h"
#include <RCC_interface.h>
#include <GPIO_interface.h>

/* Functions declaration */
void delay_ms(uint32_t ms);

/* Main function */
void main(void){

	/* MCAL initialization */
	MRCC_voidInitSysClock();

	/* Setup */
	MRCC_voidEnableClock(RCC_APB2,RCC_GPIOA); //Enable clock on APB2 bus (GPIOA perph.)
	MGPIO_voidSetPinDirection(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUT_2M_PP);

	while(1){

		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);
		delay_ms(1000);
		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);
		delay_ms(1000);

	}
}

/* Functions initialization */
void delay_ms(uint32_t ms) {
	volatile uint32_t delay = ms * (SystemCoreClock / 1000 / 8);

	SysTick->LOAD = delay - 1;
	SysTick->VAL = 0;
	SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;

	while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)) {
	}

	SysTick->CTRL = 0;
}
