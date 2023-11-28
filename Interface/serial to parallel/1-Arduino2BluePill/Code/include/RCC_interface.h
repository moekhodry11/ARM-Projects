/****************************************************************/
/***************  Name   : Mohamed Khodary **********************/
/***************  Date   : 17/10/2023      **********************/
/***************  SWC    : RCC		       **********************/
/*************** Version : 1.0             **********************/
/****************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void MRCC_voidInitSysClock(void);
void MRCC_voidEnableClock (u8 Copy_u8BusId , u8 Copy_u8PerId);
void MRCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PerId);


/*******************************************************************************
 *                      	Hash Defines for User        		               *
 *******************************************************************************/
/* BusId */
#define	RCC_AHB				0
#define RCC_APB1			1	
#define	RCC_APB2			2

/* PerId */

/* AHB Peripherals */
#define RCC_DMA1			0
#define RCC_DMA2			1
#define RCC_SRAM			2
#define RCC_FLITF			4
#define RCC_CRC				6
#define RCC_FSMC			8
#define RCC_SDIO			10
/* APB1 Peripherals */
#define RCC_TIM2			0
#define RCC_TIM3			1
#define RCC_TIM4			2
#define RCC_TIM5			3
#define RCC_TIM6			4
#define RCC_TIM7			5
#define RCC_TIM12			6
#define RCC_TIM13			7
#define RCC_TIM14			8
#define RCC_WWDG			11
#define RCC_SPI2			14
#define RCC_SPI3			15
#define RCC_USART2			17
#define RCC_USART3			18
#define RCC_UART4			19
#define RCC_UART5			20
#define RCC_I2C1			21
#define RCC_I2C2			22
#define RCC_USB				23
#define RCC_CAN				25
#define RCC_BKP				27
#define RCC_PWR				28
#define RCC_DAC				29
/* APB2 Peripherals */
#define RCC_AFIO			0
#define RCC_GPIOA			2
#define RCC_GPIOB			3
#define RCC_GPIOC			4
#define RCC_GPIOD			5
#define RCC_GPIOE			6
#define RCC_GPIOF			7
#define RCC_GPIOG			8
#define RCC_ADC1			9
#define RCC_ADC2			10
#define RCC_TIM1			11
#define RCC_SPI1			12
#define RCC_TIM8			13
#define RCC_USART1			14
#define RCC_ADC3			15
#define RCC_TIM9			19
#define RCC_TIM10			20
#define RCC_TIM11			21



#endif
