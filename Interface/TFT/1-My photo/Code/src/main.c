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
#include "SPI1_interface.h"
#include "TFT_interface.h"
#include "image.h"

/* Functions declaration */

/* Global variables */

SPI_ConfigType SPI_config   = {PH_ONE , P_ONE , MASTER , CLK_2 , MSB , EIGHT };

void main(void) {

	/* Init. Clocks */
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_APB2, RCC_GPIOA); // Enable perph 2(PORTA) on APB2 bus
	MRCC_voidEnableClock(RCC_APB2, RCC_SPI1); // Enable perph 2(PORTA) on APB2 bus

	/* IO Pins Init. */
//	MGPIO_voidSetPinDirection(GPIO_PORTA,1,0b0010);
//	MGPIO_voidSetPinDirection(GPIO_PORTA,2,0b0010);
//	MGPIO_voidSetPinDirection(GPIO_PORTA,5,0b1001);
//	MGPIO_voidSetPinDirection(GPIO_PORTA,7,0b1001);

	/* Init. */
	MSTK_voidInit();
	MSPI_voidInit(&SPI_config);
	HTFT_voidInit();

	HTFT_voidImageDisplay(image2);

	while (1) {






	}
}

/* Functions initialization */
