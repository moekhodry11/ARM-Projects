/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 08/12/2023      **********************/
/***************  SWC    : MAIN		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "OS_interface.h"

/* Functions declaration */
void LED1(void);
void LED2(void);
void LED3(void);

/* Global variables */

void main(void) {

	/* Init. Clocks */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2, RCC_GPIOA); // Enable perph 2(PORTA) on APB2 bus

	/* IO Pins Init. */
	MGPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT_2M_PP);

	/* Init. */
	OS_voidCreateTask(0, 1000, LED1,0,TASK_READY);
	OS_voidCreateTask(1, 2000, LED2,0,TASK_READY);
	OS_voidCreateTask(2, 3000, LED3,0,TASK_READY);

	OS_voidStart();

	while (1) {

	}
}

/* Functions initialization */
void LED1(void) {
	static u8 Local_u8Pin0 = 0;
	TOG_BIT(Local_u8Pin0, 0);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, Local_u8Pin0);
}
void LED2(void) {
	static u8 Local_u8Pin1 = 0;
	TOG_BIT(Local_u8Pin1, 0);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, Local_u8Pin1);
}
void LED3(void) {
	static u8 Local_u8Pin2 = 0;
	TOG_BIT(Local_u8Pin2, 0);
	MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, Local_u8Pin2);
}
