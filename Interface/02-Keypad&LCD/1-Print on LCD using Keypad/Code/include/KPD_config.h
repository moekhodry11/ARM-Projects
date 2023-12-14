/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 13/12/2023      **********************/
/***************  SWC    : KPD             **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/
#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H

/* Rows */ //Set it as Output
#define KPD_ROWS_u8_PORT             GPIO_PORTB

#define KPD_u8_R1_PIN           GPIO_PIN8
#define KPD_u8_R2_PIN           GPIO_PIN7
#define KPD_u8_R3_PIN           GPIO_PIN6
#define KPD_u8_R4_PIN           GPIO_PIN5

/* Cols */ //Set it as Input
#define KPD_COLS_u8_PORT             GPIO_PORTB

#define KPD_u8_C1_PIN           GPIO_PIN12
#define KPD_u8_C2_PIN           GPIO_PIN11
#define KPD_u8_C3_PIN           GPIO_PIN10
#define KPD_u8_C4_PIN           GPIO_PIN9

#define KPD_KEYS              {{'7','8','9','/'},   \
				  	           {'4','5','6','*'},   \
				  	           {'1','2','3','-'},   \
				  	           {'C','0','=','+'}}
				              

#endif
