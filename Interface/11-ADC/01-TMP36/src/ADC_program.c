/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/12/2023      **********************/
/***************  SWC    : ADC 		 	       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"

void MADC_voidInit(void) {
    /* Enable ADC */
    SET_BIT(ADC_CR2, 0); // ADON bit

    /* Set ADC prescaler */
    ADC_CR2 |= (ADC_PRESCALER << 14); // ADCPRE bits
}

void MADC_voidStartConversion(void) {
    /* Enable ADC */
    SET_BIT(ADC_CR2, 0); // ADON bit

    /* Set channel sequence */
    ADC_SQR1 |= ((ADC_CHANNEL - 1) << 20);
    ADC_SQR3 = (ADC_SQR3 & ~(0x1F)) | ADC_CHANNEL;

    /* Start ADC conversion */
    SET_BIT(ADC_CR2, 0); // ADON bit
    SET_BIT(ADC_CR2, 22); // Start conversion
}

u16 MADC_u16GetConvertedValue(void) {
    /* Wait for ADC conversion to complete */
    while (!(GET_BIT(ADC_SR, 1))); // EOC bit

    /* Read ADC converted value */
    return (u16)ADC_DR;
}
