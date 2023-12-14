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
#include "LEDMRX_interface.h"
#include<stdio.h>

/* Functions declaration */


u8 originalArray[]={126, 8, 20, 98, 0, 126, 16, 112, 0, 24, 36, 36, 24, 0, 120, 72, 126, 0, 126, 8, 4, 0, 70, 72, 126, 0,0};//array i want to display

void main(void) {

	/* Init. Clocks */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2, RCC_GPIOA); // Enable perph 2(PORTA) on APB2 bus
	MRCC_voidEnableClock(RCC_APB2, RCC_GPIOB); // Enable perph 3(PORTb) on APB2 bus

	/* Setup */
	MSTK_voidInit();
	HLEDMRX_voidInit();


	u8 modifiedArray[]={0};//empty array to store the modified array
	u8 size = sizeof(originalArray)/sizeof(originalArray[0]);//get the array size


	HLEDMRX_voidModifyArray(originalArray,size, modifiedArray);//modify array to display it


	while (1) {
		HLEDMRX_voidShifting(modifiedArray,size,100000);//display the modified array
	}
}

/* Functions initialization */
