/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 19/10/2023      **********************/
/***************  SWC    : USART1	       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "USART1_private.h"
#include "USART1_interface.h"
#include "USART1_config.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void MUSART1_voidInit()
{	
	/* USART Tx & Rx pins setup */
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN9 , GPIO_OUTPUT_2M_PP);
	MGPIO_voidSetPinDirection(GPIO_PORTA , GPIO_PIN10, GPIO_INPUT_FLOATING);

	/*************************** CR1 Description ***************************
	* [0]SBK 	= 0 (No break)
	* [1]RWU 	= 0 (Receiver in active Mode)
	* [2]RE  	= 1 (Receiver Enable)
	* [3]TE  	= 1 (Transmitter Enable)
	* [4]IDLEIE = 0 (IDLE Interrupt Disable) 
	* [5]RXNEIE = Enable or Disable RXNE interrupt (configured)
	* [6]TCIE   = 0 (Transmission complete interrupt interrupt Disable)
	* [7]TXEIE  = 0 (TXE interrupt Disable)
	* [8]PEIE   = 0 (PE interrupt Disable)
	* [9]PS     = Even or Odd Parity (configured)
	* [10]PCE   = Enable or Disable Parity (configured)
	* [11]WAKE  = 0 (Idle Line)
	* [12]M     = 8-bit or 9-bit Data Size (configured)
	* [13]UE    = 1 (USART Enable) 
	***********************************************************************/
	
	/* Receiver Enable 
	   Transmitter Enable
	   USART Enable	       */
	USART1 -> CR1 = (1<<2) | (1<<3) | (1<<13);
	
//	/* Enable or Disable RXNE interrupt in bit (5) of CR1 Register */
//	USART1 -> CR1 = ((USART1 -> CR1) & (0x3FDF)) | ((Config_Ptr-> recieve_int) << 5);
//
//	/* insert the required number of data-bits in "M" bit (12) of CR1 Register*/
//	USART1 -> CR1 = ((USART1 -> CR1) & (0x2FFF)) | ((Config_Ptr-> data_size) << 12);
//
//	/* insert the required parity state in "PCE" bit (10) of CR1 Register */
//	USART1 -> CR1 = ((USART1 -> CR1) & (0x3BFF)) | ((Config_Ptr-> parity_state) << 10);
//
//	/* insert the required parity type in "PS" bit (9) of CR1 Register */
//	USART1 -> CR1 = ((USART1 -> CR1) & (0x3DFF)) | ((Config_Ptr-> parity_type) << 9);
//
//	/*************************** CR2 Description ***************************
//	* [12],[13]STOP = number of Stop bits (configured)
//	* Remaining bits are neglected
//	***********************************************************************/
//	/* insert the required number of stop bits in "STOP" bits(12,13) of CR2 Register */
//	USART1 -> CR2 = ((USART1 -> CR2) & (0x17FF)) | ((Config_Ptr-> stop_bit) << 12);
	
	/*************************** CR2 Description ***************************
	*			 Fractional baud rate generation Equation:
	*		USART_DIV = F_CPU / (Tx/Rx required Baud Rate) *16
	*
	* DIV_Fraction[3:0]  = USART_DIV fraction part * 16 (Then Approximate the value)
	* DIV_Mantissa[11:0] = USART_DIV Decimal part 
	* Note : if DIV_Fraction equation result >= 16 You should Assign DIV_Fraction bits --> Zeros
	* and the carry should be added to DIV_Mantissa bits 
	***********************************************************************/
	/* for baud rate = 9600 and F_CPU = 8Mhz */
	USART1 -> BRR = 0x341;
	
}




void MUSART1_voidSendByte(const u8 Copy_u8Data)
{
	/* Polling on TXE[7] flag of SR register
	 * until the transmission register USART_DR is empty
	 * and it's ready to receive new data
	 */
	while(GET_BIT(USART1 -> SR , 7) == 0);
	
	/* Write the data byte in USART_DR start transmitting the frame 
       and clear TXE flag
	*/
	USART1 -> DR = Copy_u8Data;
	
	/************************* Another Method ****************************************************
	USART1 -> DR = Copy_u8Data; //Write the data byte in USART_DR and start transmitting the frame
	while(GET_BIT(USART1 -> SR , 6) == 0); // Polling until the byte transmission is complete
	CLR_BIT(USART1 -> SR , 6); // Clear the TC flag
	**********************************************************************************************/
}



u8 MUSART1_u8ReceiveByteSynch(void)
{
	/* Polling until the byte is received 
	   the flag is cleared automatically by HW 
	   when byte is received                   */
	while (GET_BIT(USART1 -> SR , 5) == 0);

	/* Read the byte */
	return(0xFF & (USART1 -> DR) );
}

void MUSART1_u8ReceiveByteAsynch(void (*Copy_ptr)(u8))
{
	USART1_CallBack = Copy_ptr;
}


void MUSART1_voidSendString(const u8 *Copy_Str)
{
	u8 i = 0;
	while(Copy_Str[i] != '\0')
	{
		MUSART1_voidSendByte(Copy_Str[i]);
		i++;
	}
}

void MUSART1_voidReceiveStringSynch(u8 *Copy_Str)
{
	u8 i = 0;
	
	Copy_Str[i] = MUSART1_u8ReceiveByte();
		
	/* Receive the whole string until the '#' */
	while(Copy_Str[i] != '#')
	{
		i++;
		Copy_Str[i] = MUSART1_u8ReceiveByte();
	}
	
	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	Copy_Str[i] = '\0';
}

void USART1_IRQHandler(void)
{
	if(USART1_CallBack != NULL)
	{
		/* call back function (and pass the DR value),  Clear RXNE flag */
		USART1_CallBack(USART1 -> DR);
	}
}
