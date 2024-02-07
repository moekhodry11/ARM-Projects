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
#include "NVIC_interface.h"

/* Functions declaration */
void delay(void);

void main(void) {

	/* Init. Clocks */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2, RCC_GPIOA); // Enable perph 2(PORTA) on APB2 bus

	/* Setup */
	MGPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN4, GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN5, GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN6, GPIO_OUTPUT_2M_PP);

	MNVIC_voidSetPriority(NVIC_EXTI0, 12, 0);//group 1, sub 0
	MNVIC_voidSetPriority(NVIC_EXTI1, 0, 0);//group 0, sub 0

	MNVIC_voidEnableInterrupt(NVIC_EXTI0);
	MNVIC_voidEnableInterrupt(NVIC_EXTI1);

	MNVIC_voidSetPendingFlag(NVIC_EXTI0);

	while (1) {

	}

}

void EXTI0_IRQHandler(void) {
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN4, GPIO_HIGH);
	delay();
	MNVIC_voidSetPendingFlag(NVIC_EXTI1);
	delay();
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_HIGH);
}

void EXTI1_IRQHandler(void) {
	delay();
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN6, GPIO_HIGH);
	delay();
}

/* Functions initialization */
void delay(void) {
	for (u8 i = 0; i < 255; i++) {
		for (u8 i = 0; i < 255; i++) {
			for (u8 i = 0; i < 5; i++) {
				asm("NOP");
			}
		}
	}
}
