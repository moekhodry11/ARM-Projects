/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/12/2023      **********************/
/***************  SWC    : SPI1 	       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef SPI1_PRIVATE_H
#define SPI1_PRIVATE_H
#include "STD_TYPES.h"
#define NULL	(void * )0

/*******************************************************************************
 *                      Global variables Definitions                           *
 *******************************************************************************/
 
static void (* SPI1_CallBack) (void) = NULL ;

/*******************************************************************************
 *                      Registers Definitions                                  *
 *******************************************************************************/

typedef struct 
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;	
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
}SPI_t;


#define SPI1 ((volatile SPI_t *) 0x40013000)




#endif
