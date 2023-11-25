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
#include "DAC_interface.h"

/* Functions declaration */


void main(void) {

	/* Init. Clocks */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2, RCC_GPIOA); // Enable perph 2(PORTA) on APB2 bus

	/* Setup */
	//MSTK_voidInit();
	HDAC_voidInit();

	while (1) {


	}

}

/* Functions initialization */
