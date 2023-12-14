/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 19/10/2023      **********************/
/***************  SWC    : USART1	       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef USART1_PRIVATE_H
#define USART1_PRIVATE_H

#define NULL	(void * )0

/*******************************************************************************
 *                      Global variables Definitions                           *
 *******************************************************************************/

static volatile void (*USART1_CallBack)(u8) = NULL;

/*******************************************************************************
 *                      Registers Definitions                                  *
 *******************************************************************************/

typedef struct 
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;	
}USART_t;


#define USART1 ((volatile USART_t *) 0x40013800)



#endif
