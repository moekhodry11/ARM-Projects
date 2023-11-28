/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 17/10/2023      **********************/
/***************  SWC    : GPIO		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef  GPIO_INTERFACE_H
#define  GPIO_INTERFACE_H

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 
void MGPIO_voidSetPinDirection    ( u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Mode );
void MGPIO_voidSetPinValue	      ( u8 copy_u8Port , u8 copy_u8Pin , u8 copy_u8Value);
u8   MGPIO_u8GetPinValue	      ( u8 copy_u8Port , u8 copy_u8Pin );
void MGPIO_voidSetPortDirection   ( u8 copy_u8Port , u8 copy_u8Position , u8 copy_u8Mode );
void MGPIO_voidSetPortValue       ( u8 copy_u8Port , u8 copy_u8Position , u8 copy_u8Value);
u8   MGPIO_u8GetPortValue		  ( u8 copy_u8Port , u8 copy_u8Position);

/*******************************************************************************
 *                      	Hash Defines for User        		               *
 *******************************************************************************/
 
/* Ports */
#define GPIO_PORTA					0
#define GPIO_PORTB					1
#define GPIO_PORTC					2

/* Pins */			
#define GPIO_PIN0					0
#define GPIO_PIN1					1
#define GPIO_PIN2					2
#define GPIO_PIN3					3
#define GPIO_PIN4					4
#define GPIO_PIN5					5
#define GPIO_PIN6					6
#define GPIO_PIN7					7
#define GPIO_PIN8					8
#define GPIO_PIN9					9
#define GPIO_PIN10					10
#define GPIO_PIN11					11
#define GPIO_PIN12					12
#define GPIO_PIN13					13
#define GPIO_PIN14					14
#define GPIO_PIN15					15
		

/* Modes */	
#define GPIO_INPUT_ANALOG			0b0000
#define GPIO_INPUT_FLOATING			0b0100
#define GPIO_INPUT_PULL_UP_DOWN		0b1000
		
#define GPIO_OUTPUT_2M_PP			0b0010
#define GPIO_OUTPUT_10M_PP			0b0001
#define GPIO_OUTPUT_50M_PP			0b0011

#define GPIO_OUTPUT_2M_OD			0b0110
#define GPIO_OUTPUT_10M_OD			0b0101
#define GPIO_OUTPUT_50M_OD			0b0111

#define GPIO_OUTPUT_2M_AF_PP		0b1010
#define GPIO_OUTPUT_10M_AF_PP		0b1001
#define GPIO_OUTPUT_50M_AF_PP		0b1011

#define GPIO_OUTPUT_2M_AF_OD		0b1110
#define GPIO_OUTPUT_10M_AF_OD		0b1101
#define GPIO_OUTPUT_50M_AF_OD		0b1111

/* Values */
#define GPIO_LOW					0
#define GPIO_HIGH					1
        
/* Positions */
#define GPIO_LOW_POSITION			0
#define GPIO_HIGH_POSITION			1



#endif
