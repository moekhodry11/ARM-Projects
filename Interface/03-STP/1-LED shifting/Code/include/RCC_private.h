/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 17/10/2023      **********************/
/***************  SWC    : RCC		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/*******************************************************************************
 *                      Registers Definitions                                  *
 *******************************************************************************/

#define	RCC_CR 				*((volatile u32*)0x40021000)
#define RCC_CFGR			*((volatile u32*)0x40021004)
#define RCC_CIR				*((volatile u32*)0x40021008)
#define RCC_APB2RSTR		*((volatile u32*)0x4002100C)
#define RCC_APB1RSTR		*((volatile u32*)0x40021010)
#define RCC_AHBENR			*((volatile u32*)0x40021014)
#define RCC_APB2ENR			*((volatile u32*)0x40021018)
#define RCC_APB1ENR			*((volatile u32*)0x4002101C)
#define RCC_BDCR			*((volatile u32*)0x40021020)
#define RCC_CSR				*((volatile u32*)0x40021024)



/*******************************************************************************
 *                      Hash Defines For Conguration                           *
 *******************************************************************************/
 
/* Clock Types  */
#define RCC_HSE_CRYSTAL		0
#define RCC_HSE_RC			1
#define RCC_HSI				2
#define RCC_PLL				3

/* PLL Options */
#define RCC_PLL_HSI_DIV_2	0
#define RCC_PLL_HSE_DIV_2	1	
#define RCC_PLL_HSE			2


#endif
