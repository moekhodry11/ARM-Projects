/********************************************************************************/
/* Author		: Omar Ashraf							     					*/
/* Date 		: 24 AUG 2023								 					*/
/* Version		: V02										 					*/
/********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"

#include "GPIO_config.h"

void MGPIO_voidSetPinDirection(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Mode)
{
	switch(copy_u8Port)
	{
	case GPIO_PORTA:
		if(copy_u8Pin <= 7)
		{
			GPIOA_CRL &= ~( (0b1111) << (copy_u8Pin * 4) );
			GPIOA_CRL |= copy_u8Mode << (copy_u8Pin * 4);
		}
		else if(copy_u8Pin <= 15)
		{
			copy_u8Pin -= 8;
			GPIOA_CRH &= ~( (0b1111) << (copy_u8Pin * 4) );
			GPIOA_CRH |= copy_u8Mode << (copy_u8Pin * 4);
		}
		break;
		
	case GPIO_PORTB:
		if(copy_u8Pin <= 7)
		{
			GPIOB_CRL &= ~( (0b1111) << (copy_u8Pin * 4) );
			GPIOB_CRL |= copy_u8Mode << (copy_u8Pin * 4);
		}       
		else if(copy_u8Pin <= 15)
		{   
			copy_u8Pin -= 8;
			GPIOB_CRH &= ~( (0b1111) << (copy_u8Pin * 4) );
			GPIOB_CRH |= copy_u8Mode << (copy_u8Pin * 4);
		}
		break;
		
	case GPIO_PORTC:
		if(copy_u8Pin <= 7)
		{
			GPIOC_CRL &= ~( (0b1111) << (copy_u8Pin * 4) );
			GPIOC_CRL |= copy_u8Mode << (copy_u8Pin * 4);
		}       
		else if(copy_u8Pin <= 15)
		{   
			copy_u8Pin -= 8;
			GPIOC_CRH &= ~( (0b1111) << (copy_u8Pin * 4) );
			GPIOC_CRH |= copy_u8Mode << (copy_u8Pin * 4);
		}
		break;
	}
	
}

void MGPIO_voidSetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Value)
{
	switch(copy_u8Port)
	{
	case GPIO_PORTA:
		switch(copy_u8Value)
		{
		case GPIO_HIGH:
			SET_BIT(GPIOA_ODR, copy_u8Pin);
			break;
		case GPIO_LOW:
			CLR_BIT(GPIOA_ODR, copy_u8Pin);
			break;
		}
		break;
		
	case GPIO_PORTB:
		switch(copy_u8Value)
		{
		case GPIO_HIGH:
			SET_BIT(GPIOB_ODR, copy_u8Pin);
			break;
		case GPIO_LOW:
			CLR_BIT(GPIOB_ODR, copy_u8Pin);
			break;		
		}
		break;
			
	case GPIO_PORTC:
		switch(copy_u8Value)
		{
		case GPIO_HIGH:
			SET_BIT(GPIOC_ODR, copy_u8Pin);
			break;
		case GPIO_LOW:
			CLR_BIT(GPIOC_ODR, copy_u8Pin);
			break;		
		}
		break;
					
	}
}


u8 MGPIO_u8GetPinValue(u8 copy_u8Port, u8 copy_u8Pin)
{
	u8 LOC_u8Result = 0;
	switch(copy_u8Port)
	{
	case GPIO_PORTA: LOC_u8Result = GET_BIT(GPIOA_IDR, copy_u8Pin);
				break;
				
	case GPIO_PORTB: LOC_u8Result = GET_BIT(GPIOB_IDR, copy_u8Pin);
				break;
				
	case GPIO_PORTC: LOC_u8Result = GET_BIT(GPIOC_IDR, copy_u8Pin);
				break;

	}
	return LOC_u8Result;
}




void MGPIO_voidSetPortDirection(u8 copy_u8Port, u8 copy_u8Position ,u8 copy_u8Mode)
{
	switch(copy_u8Port)
	{
	case GPIO_PORTA:
		switch(copy_u8Position)
		{
			case GPIO_LOW_POSITION:
				 GPIOA_CRL = 0;
			     GPIOA_CRL = (0x11111111 * copy_u8Mode);
				 break;
				 
			case GPIO_HIGH_POSITION:
				 GPIOA_CRH = 0;
		         GPIOA_CRH = (0x11111111 * copy_u8Mode);
				 break;
		}
		break;
		
	case GPIO_PORTB:
		switch(copy_u8Position)
		{
			case GPIO_LOW_POSITION:
				 GPIOB_CRL = 0;
			     GPIOB_CRL = (0x11111111 * copy_u8Mode);
				 break;
				 
			case GPIO_HIGH_POSITION:
				 GPIOB_CRH = 0;
		         GPIOB_CRH = (0x11111111 * copy_u8Mode);
				 break;
		}
		break;
		
	case GPIO_PORTC:
		switch(copy_u8Position)
		{
			case GPIO_LOW_POSITION:
				 GPIOC_CRL = 0;
			     GPIOC_CRL = (0x11111111 * copy_u8Mode);
				 break;
				 
			case GPIO_HIGH_POSITION:
				 GPIOC_CRH = 0;
		         GPIOC_CRH = (0x11111111 * copy_u8Mode);
				 break;
		}
		break;
	}	
}

void MGPIO_voidSetPortValue(u8 copy_u8Port, u8 copy_u8Position , u8 copy_u8Value)
{
	switch(copy_u8Port)
	{
	case GPIO_PORTA:
		if(copy_u8Position == GPIO_LOW_POSITION)
		{
			switch(copy_u8Value)
			{
			case GPIO_HIGH: GPIOA_ODR |= 0x00FF;
			break;
			case GPIO_LOW:  GPIOA_ODR &= 0xFF00;
			break;
			}
		}
		else if(copy_u8Position == GPIO_HIGH_POSITION)
		{
			switch(copy_u8Value)
			{
			case GPIO_HIGH: GPIOA_ODR |= 0xFF00;
			break;
			case GPIO_LOW:  GPIOA_ODR &= 0x00FF;
			break;
			}
		}
		break;
		
	case GPIO_PORTB:
		if(copy_u8Position == GPIO_LOW_POSITION)
		{
			switch(copy_u8Value)
			{
			case GPIO_HIGH: GPIOB_ODR |= 0x00FF;
			break;
			case GPIO_LOW:  GPIOB_ODR &= 0xFF00;
			break;
			}
		}
		else if(copy_u8Position == GPIO_HIGH_POSITION)
		{
			switch(copy_u8Value)
			{
			case GPIO_HIGH: GPIOB_ODR |= 0xFF00;
			break;
			case GPIO_LOW:  GPIOB_ODR &= 0x00FF;
			break;
			}
		}
		break;
			
	case GPIO_PORTC:
		if(copy_u8Position == GPIO_LOW_POSITION)
		{
			switch(copy_u8Value)
			{
			case GPIO_HIGH: GPIOC_ODR |= 0x00FF;
			break;
			case GPIO_LOW:  GPIOC_ODR &= 0xFF00;
			break;
			}
		}
		else if(copy_u8Position == GPIO_HIGH_POSITION)
		{
			switch(copy_u8Value)
			{
			case GPIO_HIGH: GPIOC_ODR |= 0xFF00;
			break;
			case GPIO_LOW:  GPIOC_ODR &= 0x00FF;
			break;
			}
		}
		break;			
	}
		
}

u8 MGPIO_u8GetPortValue(u8 copy_u8Port, u8 copy_u8Position)
{
	u8 Local_u8Result = 0;
	switch(copy_u8Port)
	{
	case GPIO_PORTA: 
		if(copy_u8Position == GPIO_LOW_POSITION)
		{
			Local_u8Result = GPIOA_IDR;
		}
		else if(copy_u8Position == GPIO_HIGH_POSITION)
		{
			Local_u8Result = GPIOA_IDR >> 8 ;
		}
		break;
		
	case GPIO_PORTB:
		if(copy_u8Position == GPIO_LOW_POSITION)
		{
			Local_u8Result = GPIOB_IDR;
		}
		else if(copy_u8Position == GPIO_HIGH_POSITION)
		{
			Local_u8Result = GPIOB_IDR >> 8 ;
		}
		break;
				
	case GPIO_PORTC:
		if(copy_u8Position == GPIO_LOW_POSITION)
		{
			Local_u8Result = GPIOA_IDR;
		}
		else if(copy_u8Position == GPIO_HIGH_POSITION)
		{
			Local_u8Result = GPIOA_IDR >> 8 ;
		}
		break;
	}
	return Local_u8Result;
}



