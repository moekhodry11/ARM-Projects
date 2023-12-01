/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/12/2023      **********************/
/***************  SWC    : SPI1 	       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include <SPI1_config.h>
#include <SPI1_interface.h>
#include <SPI1_private.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void MSPI_voidInit(const SPI_ConfigType *Config_ptr)
{
	if((Config_ptr -> mode) == MASTER)
	{
		/******** Configure SPI1 Master Pins *********
		* SCK(PA5)  --> Output
		* MISO(PA6) --> Input
		* MOSI(PA7) --> Output 
		* SS(Normal DIO pin) --> Output
		********************************************/
		MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN5 , GPIO_OUTPUT_10M_AF_PP);
		MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN6 , GPIO_INPUT_FLOATING);
		MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN7 , GPIO_OUTPUT_10M_AF_PP);
		MGPIO_voidSetPinDirection(SPI1_MASTER_SS_PORT , SPI1_MASTER_SS_PIN , GPIO_OUTPUT_2M_PP);
	}
	else if((Config_ptr -> mode) == SLAVE)
	{
		/******** Configure SPI1 Slave Pins *********
		* NSS(PA4)  --> Input
		* SCK(PA5)  --> Input
		* MISO(PA6) --> Output
		* MOSI(PA7) --> Input 
		********************************************/
		MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN4 , GPIO_INPUT_FLOATING);
		MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN5 , GPIO_INPUT_FLOATING);
		MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN6 , GPIO_OUTPUT_2M_PP);
		MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN7 , GPIO_INPUT_FLOATING);
	}
	
	/*************************** CR1 Description *******************************
	* [0]CPHA = Zero or One (configured)
	* [1]CPOL = Zero or One (configured)
	* [2]MSTR = Mode selection master or slave (configured)
	* [3],[4],[5]BR = Baud Rate Prescaler control (configured)
	* [6]SPE = 1 (Spi Enable) 
	* [7]LSBFIRST = Data order LSB or MSB first (configured)
	* [8]SSI = set or clear slave pin (when managed by SW) (configured)
	*		   {0-> slave (NSS select slave) , 1-> master(NSS is not selected)} 
	* [9]SSM = 1 (Enable SW slave management)
	* [10]RXONLY = 0 (Full duplex Send and Receive)
	* [11]DFF = Data Frame format or Data Size (8-bit or 16-bit) (configured)
	* [12]CRCNEXT = 0 (won't use CRC)
	* [13]CRCEN = 0 (disable CRC)
	* [14]BIDIOE = 0 (won't use Bidirectional Mode)
	* [15]BIDIMODE = 0 (disable Bidirectional Mode) 
	******************************************************************************/
	
	/* insert the required Clock Phase in [CPHA] bit of CR1 Register */
	SPI1 -> CR1 = ((SPI1 -> CR1) & (0xFFFE)) | ((Config_ptr -> cpha)<<0);
	
	/* insert the required Clock Polarity in [CPOL] bit of CR1 Register */
	SPI1 -> CR1 = ((SPI1 -> CR1) & (0xFFFD)) | ((Config_ptr -> cpol)<<1);
	
	/* insert the required Mode in [MSTR] bit of CR1 Register */
	SPI1 -> CR1 = ((SPI1 -> CR1) & (0xFFFB)) | ((Config_ptr -> mode)<<2);
	
	/* insert the required Baud Rate in [BR] bits of CR1 Register */
	SPI1 -> CR1 = ((SPI1 -> CR1) & (0xFFC7)) | ((Config_ptr -> baud_rate)<<3);
	
	/* insert the required Data order in [LSBFIRST] bit of CR1 Register */
	SPI1 -> CR1 = ((SPI1 -> CR1) & (0xFF7F)) | ((Config_ptr -> data_order)<<7);
	
	/* set or clear SSI[8] bit according to The mode (master(1) or slave(0))  */
	SPI1 -> CR1 = ((SPI1 -> CR1) & (0xFEFF)) | ((Config_ptr -> mode)<<8);

	/* Enable SW slave Management [9]SSM */
	SET_BIT(SPI1 -> CR1 , 9);
		
	/* insert the required Data Size in [DFF] bit of CR1 Register */
	SPI1 -> CR1 = ((SPI1 -> CR1) & (0xF7FF)) | ((Config_ptr -> data_size)<<11);

	/* Enable SPI [6]SPE */
	SET_BIT(SPI1 -> CR1 , 6);
}


void MSPI_voidSendReceiveByteSynch(u16 Copy_u16DataToSend , u16* Copy_DataToReceive)
{
	/* Clear for slave select pin */
	MGPIO_voidSetPinValue(SPI1_MASTER_SS_PORT , SPI1_MASTER_SS_PIN , GPIO_LOW);
	
	/* Send Data On Data Register*/
	SPI1 -> DR = Copy_u16DataToSend;
	
	/* Polling on [7]BSY flag of SR Register until SPI communication is not busy */
	while(GET_BIT(SPI1 -> SR , 7) == 1);
	
	/* Receive Data from Data Register */
	*Copy_DataToReceive = SPI1 -> DR;
	
	/* Set for slave select pin */
	MGPIO_voidSetPinValue(SPI1_MASTER_SS_PORT , SPI1_MASTER_SS_PIN , GPIO_HIGH);
}


void MSPI_voidSendReceiveByteASynch(u16 Copy_u16DataToSend , void (*Copy_ptr) (u16) )
{	
	/* Set SPI Call Back */
	SPI1_CallBack = Copy_ptr;

	/* Enable Receive Interrupt */
	SET_BIT(SPI1 -> CR2 , 6);
	
	/* Clear for slave select pin */
	MGPIO_voidSetPinValue(SPI1_MASTER_SS_PORT , SPI1_MASTER_SS_PIN , GPIO_LOW);
	
	/* Send Data On Data Register*/
	SPI1 -> DR = Copy_u16DataToSend;	
}


void SPI1_IRQHandler(void)
{
	/* Send the received value to the Call back function */
//	SPI1_CallBack(SPI1 -> DR);
	
	/* Set for slave select pin */
	MGPIO_voidSetPinValue(SPI1_MASTER_SS_PORT , SPI1_MASTER_SS_PIN , GPIO_HIGH);
}
