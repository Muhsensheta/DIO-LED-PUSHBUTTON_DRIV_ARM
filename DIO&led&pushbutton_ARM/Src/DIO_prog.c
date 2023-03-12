/*
 * GPIO_prog.c
 *
 *  Created on: ٠١‏/٠٣‏/٢٠٢٣
 *      Author: houras
 */

#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_priv.h"
#include "DIO_int.h"

void M_DIO_void_setPinDir(u8 Port, PIN_T Pin, Dir_T DIRECTION)
{
	/*	Range Check						*/
	if(Port<3 &&  Pin < 16 && DIRECTION < 16)
	{
		if(Pin < 8) /*	Pin0 : Pin7 ==> CRL	*/
		{
			switch(Port)
			{
				case PORTA_ID	:	GPIOA_CRL &=	~(0b1111<<(Pin * 4));		/*Clear the 4 bits */
								GPIOA_CRL |=	((DIRECTION)<<(Pin * 4));	/*Assign the 4 bits */
								break;

				case PORTB_ID	:	GPIOB_CRL &=	~(0b1111<<(Pin * 4));		/*Clear the 4 bits */
								GPIOB_CRL |=	((DIRECTION)<<(Pin * 4));	/*Assign the 4 bits */
								break;

				case PORTC_ID	:	GPIOC_CRL &=	~(0b1111<<(Pin * 4));		/*Clear the 4 bits */
								GPIOC_CRL |=	((DIRECTION)<<(Pin * 4));	/*Assign the 4 bits */
								break;
			}
		}else if(Port < 16) /*	Pin8 : Pin15 ==> CRH	*/
		{
			Pin -= 8 ;
			switch(Port)
			{
				case PORTA_ID	:	GPIOA_CRH &=	~(0b1111<<(Pin * 4));		/*Clear the 4 bits */
								GPIOA_CRH |=	((DIRECTION)<<(Pin * 4));	/*Assign the 4 bits */
								break;

				case PORTB_ID	:	GPIOB_CRH &=	~(0b1111<<(Pin * 4));		/*Clear the 4 bits */
								GPIOB_CRH |=	((DIRECTION)<<(Pin * 4));	/*Assign the 4 bits */
								break;

				case PORTC_ID	:	GPIOC_CRH &=	~(0b1111<<(Pin * 4));		/*Clear the 4 bits */
								GPIOC_CRH |=	((DIRECTION)<<(Pin * 4));	/*Assign the 4 bits */
								break;
			}
		}
		else{/*		Report Error Out of Range			*/	}
	}
	else
	{/*		Report Error 			*/}
}
void M_DIO_void_setPinValue(u8 Port, u8 Pin, VALUE_T value)
{
	/*	Range Check						*/
		if( Port<3 &&Pin < 16)
		{
			if(value == LOW)
			{
				switch( Port)
				{
					case PORTA_ID	:	CLR_BIT(GPIOA_ODR ,Pin);	break;
					case PORTB_ID	:	CLR_BIT(GPIOB_ODR ,Pin);	break;
					case PORTC_ID	:	CLR_BIT(GPIOC_ODR ,Pin);	break;
				}
			}else if(value == HIGH)
			{
				switch( Port)
				{
					case PORTA_ID	:	SET_BIT(GPIOA_ODR ,Pin);	break;
					case PORTB_ID	:	SET_BIT(GPIOB_ODR ,Pin);	break;
					case PORTC_ID	:	SET_BIT(GPIOC_ODR ,Pin);	break;
				}
			}
			else{/*		Report Error Out of Range			*/	}
		}
		else
		{/*		Report Error 			*/}
	}
void M_DIO_void_getPinValue(u8 Port, u8 Pin, u8 *pvalue)
{
	/*	Range Check						*/
	if(Port<3 &&Pin < 16)
	{
			switch(Port)
			{
				case PORTA_ID	:	*pvalue = GET_BIT(GPIOA_IDR ,Pin);	break;
				case PORTB_ID	:	*pvalue = GET_BIT(GPIOB_IDR ,Pin);	break;
				case PORTC_ID	:	*pvalue = GET_BIT(GPIOC_IDR ,Pin);	break;
			}
	}
	else
	{/*		Report Error 			*/}
}

