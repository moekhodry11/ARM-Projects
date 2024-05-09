/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 01/12/2023      **********************/
/***************  SWC    : ADC     	       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H
/* ADC Configuration */
#define ADC_PRESCALER_DIV2          0
#define ADC_PRESCALER_DIV4          1
#define ADC_PRESCALER_DIV6          2
#define ADC_PRESCALER_DIV8          3

#define ADC_PRESCALER               ADC_PRESCALER_DIV2

/* ADC Channel Configuration */
#define ADC_CHANNEL                 2 /* Change to pin 2 for ADC */

/* ADC Resolution */
#define ADC_RESOLUTION_12BIT        0
#define ADC_RESOLUTION_10BIT        1
#define ADC_RESOLUTION_8BIT         2
#define ADC_RESOLUTION_6BIT         3

#define ADC_RESOLUTION              ADC_RESOLUTION_12BIT /* Set ADC resolution to 12-bit */

/* ADC Sampling Time */
#define ADC_SAMPLING_TIME_1_5_CYCLES       0
#define ADC_SAMPLING_TIME_7_5_CYCLES       1
#define ADC_SAMPLING_TIME_13_5_CYCLES      2
#define ADC_SAMPLING_TIME_28_5_CYCLES      3
#define ADC_SAMPLING_TIME_41_5_CYCLES      4
#define ADC_SAMPLING_TIME_55_5_CYCLES      5
#define ADC_SAMPLING_TIME_71_5_CYCLES      6
#define ADC_SAMPLING_TIME_239_5_CYCLES     7

#define ADC_SAMPLING_TIME           ADC_SAMPLING_TIME_55_5_CYCLES /* Set ADC sampling time */

/* ADC Alignment */
#define ADC_ALIGN_RIGHT             0
#define ADC_ALIGN_LEFT              1

#define ADC_ALIGNMENT               ADC_ALIGN_RIGHT /* Set ADC alignment to right */

/* ADC Reference Voltage */
#define ADC_REF_VOLTAGE_5V          5.0 /* Set ADC reference voltage to 5V */

#endif
