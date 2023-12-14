/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 28/11/2023      **********************/
/***************  SWC    : MAIN		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "STP_interface.h"

/* Functions declaration */

/* Global variables */

void main(void) {

	/* Init. Clocks */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2, RCC_GPIOA); // Enable perph 2(PORTA) on APB2 bus

	/* IO Pins Init. */


	/* Init. STP */
	HSTP_voidInit();

	while (1) {


		for(u8 i=0;i<8;i++){
			HSTP_voidSendSynchronous(1<<i);
			MSTK_voidSetBusyWait(300000);
		}

	}

}

/* Functions initialization */
