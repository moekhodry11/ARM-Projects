/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/12/2023      **********************/
/***************  SWC    : ADC     	       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define ADC_BASE_ADDRESS 0x40012400

#define ADC_CR1           *((volatile u32 *)(ADC_BASE_ADDRESS + 0x04))
#define ADC_CR2           *((volatile u32 *)(ADC_BASE_ADDRESS + 0x08))
#define ADC_DR            *((volatile u32 *)(ADC_BASE_ADDRESS + 0x4C))
#define ADC_SR            *((volatile u32 *)(ADC_BASE_ADDRESS + 0x00))
#define ADC_SQR1          *((volatile u32 *)(ADC_BASE_ADDRESS + 0x2C))
#define ADC_SQR2          *((volatile u32 *)(ADC_BASE_ADDRESS + 0x30))
#define ADC_SQR3          *((volatile u32 *)(ADC_BASE_ADDRESS + 0x34))


#endif
