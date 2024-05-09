/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/12/2023      **********************/
/***************  SWC    : ADC    	       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

/* Function to initialize ADC */
void MADC_voidInit(void);

/* Function to start ADC conversion */
void MADC_voidStartConversion(void);

/* Function to read ADC converted value */
u16 MADC_u16GetConvertedValue(void);

#endif

