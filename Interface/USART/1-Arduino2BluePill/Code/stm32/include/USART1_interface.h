/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 19/10/2023      **********************/
/***************  SWC    : USART1	       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef USART1_INTERFACE_H
#define USART1_INTERFACE_H


/*******************************************************************************
 *                    Configuration structure Options 		                   *
 *******************************************************************************/
typedef enum
{
	INT_DISABLE, INT_ENABLE
}USART_RecieveInt;

typedef enum
{
	EIGHT, NINE
}USART_DataSize;

typedef enum
{
	DISABLED, ENABLED
}USART_ParityState;

typedef enum
{
	NOPARITY , EVEN = 0 , ODD
}USART_ParityType;

typedef enum
{
	ONE,HALF,TWO,ONEHALF
}USART_StopBit;


/*******************************************************************************
 *                      Configuration Structure                                *
 *******************************************************************************/

typedef struct
{
	USART_RecieveInt  recieve_int;
	USART_DataSize 	  data_size;
	USART_ParityState parity_state;
	USART_ParityType  parity_type;
	USART_StopBit 	  stop_bit;
}USART_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 
void MUSART1_voidInit   	   		();
void MUSART1_voidSendByte     		(const u8 Copy_u8Data);
u8	 MUSART1_u8ReceiveByteSynch		(void);
void MUSART1_u8ReceiveByteAsynch	(void (*Copy_ptr)(u8));
void MUSART1_voidSendString	   		(const u8 *Copy_Str);
void MUSART1_voidReceiveStringSynch (u8 *Copy_Str);




#endif

