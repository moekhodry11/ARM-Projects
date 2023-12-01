/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/12/2023      **********************/
/***************  SWC    : TFT  	       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include <SPI1_interface.h>
#include "STD_TYPES.h"		
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"



#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void HTFT_voidInit(void)
{
	/* Set IO pins direction */
	MGPIO_voidSetPinDirection(TFT_RST_PORT , TFT_RST_PIN , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(TFT_A0_PORT  , TFT_A0_PIN  , GPIO_OUTPUT_2M_PP);


	/* Reset Pulse  */
	MGPIO_voidSetPinValue(TFT_RST_PORT, TFT_RST_PIN , GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PORT, TFT_RST_PIN , GPIO_LOW);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(TFT_RST_PORT, TFT_RST_PIN , GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PORT, TFT_RST_PIN , GPIO_LOW);
	MSTK_voidSetBusyWait(100);	
	MGPIO_voidSetPinValue(TFT_RST_PORT, TFT_RST_PIN , GPIO_HIGH);
	MSTK_voidSetBusyWait(120000);	
	
	/* Sleep out Command */
	WriteCommand(SLPOUT);
	
	/* Wait 150ms */
	MSTK_voidSetBusyWait(120000);	
	
	/* Color Mode Command */
	WriteCommand(COLMOD);
	/* Color Mode Parameter */
	WriteData(RGB565);
	
	/* Display On Command */
	WriteCommand(DISPON);

}



void HTFT_voidImageDisplay(const u16* Copy_Image)
{
	u16 Local_u16Counter = 0;
	/* Set X Address */
	WriteCommand(SET_X_ADDRESS);
	WriteData(0);
	WriteData(0);
	WriteData(0);
	WriteData(127);
	
	/* Set Y Address */
	WriteCommand(SET_Y_ADDRESS);
	WriteData(0);
	WriteData(0);
	WriteData(0);
	WriteData(159);

	/* RAM write */
	WriteCommand(RAM_WRITE);
	for(Local_u16Counter=0 ; Local_u16Counter<20480 ; Local_u16Counter++)
	{
		/* Write the high byte */
		WriteData (Copy_Image[Local_u16Counter] >> 8);

		/* Write the low byte */
		WriteData (Copy_Image[Local_u16Counter] & (0x00FF));
	}
}



static void WriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp = 0;
	
	/* Set A0 pin to Low */
	MGPIO_voidSetPinValue(TFT_A0_PORT, TFT_A0_PIN , GPIO_LOW);
	
	/* Send Command over SPI */
	MSPI_voidSendReceiveByteSynch(Copy_u8Command, &Local_u8Temp);
}



static void WriteData(u8 Copy_u8Data)
{
	u8 Local_u8Temp = 0;
	
	/* Set A0 pin to High */
	MGPIO_voidSetPinValue(TFT_A0_PORT, TFT_A0_PIN , GPIO_HIGH);
	
	/* Send Data over SPI */
	MSPI_voidSendReceiveByteSynch(Copy_u8Data, &Local_u8Temp);
}
	
