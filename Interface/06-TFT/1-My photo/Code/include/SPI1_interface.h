/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/12/2023      **********************/
/***************  SWC    : SPI1 	       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef SPI1_INTERFACE_H
#define SPI1_INTERFACE_H

#include "STD_TYPES.h"
/*******************************************************************************
 *                    Configuration structure Options 		                   *
 *******************************************************************************/

typedef enum
{
	PH_ZERO , PH_ONE
}SPI_ClkPhase;

typedef enum
{
	P_ZERO , P_ONE
}SPI_ClkPolarity;

typedef enum
{
	SLAVE , MASTER 
}SPI_Mode;

typedef enum
{
	CLK_2 , CLK_4 , CLK_8 , CLK_16 , CLK_32 , CLK_64 , CLK_128 , CLK_256
}SPI_BaudRate;

typedef enum
{
	MSB , LSB
}SPI_DataOrder;


typedef enum
{
	EIGHT , SIXTEEN
}SPI_DataSize;




/*******************************************************************************
 *                      Configuration Structure                                *
 *******************************************************************************/

typedef struct
{
	SPI_ClkPhase	cpha;
	SPI_ClkPolarity	cpol;
	SPI_Mode		mode;
	SPI_BaudRate	baud_rate;
	SPI_DataOrder	data_order;
	SPI_DataSize	data_size;
}SPI_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void MSPI_voidInit(const SPI_ConfigType *Config_ptr);
void MSPI_voidSendReceiveByteSynch(u16 Copy_u8DataToSend , u16* Copy_DataToReceive);
void MSPI_voidSendReceiveByteASynch(u16 Copy_u8DataToSend , void (*Copy_ptr) (u16) );



/* 
   for Init function argument : configuration structure address
   configuration structure is a Post-build Configuration (Configuration in Run Time)

   Example:
   SPI_ConfigType SPI_config   = {PH_ONE , P_ZERO , MASTER , CLK_2 , MSB , EIGHT };
   MSPI1_voidInit(&SPI_config);
*/


#endif

