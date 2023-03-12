/*
 * GPIO_int.h
 *
 *  Created on: ٠١‏/٠٣‏/٢٠٢٣
 *      Author: houras
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_


#define	PORTA_ID  1
#define	PORTB_ID  2
#define	PORTC_ID  3
#define	PORTD_ID  4

typedef enum{
	PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,PIN8,PIN9,PIN10,PIN11,PIN12,PIN13,PIN14,PIN15
}PIN_T;



typedef enum{
	IN,OUT
}Dir_T;


typedef enum{
	LOW,HIGH
}VALUE_T;


/****************  Function Prototypes  ****************/
void M_DIO_void_setPinDir(u8 Port, PIN_T Pin, Dir_T Dir);
void M_DIO_void_setPinValue(u8 Port, PIN_T Pin, VALUE_T value);
void M_DIO_void_getPinValue(u8 Port, PIN_T Pin, u8 *pvalue);
void M_DIO_void_TogPinValue(u8 Port, PIN_T Pin);
void M_DIO_void_setPortValue(u8 Port, VALUE_T value);
//void M_DIO_void_getPinValue(u8 Port,  u8 *pvalue);

#define		IN_ANALOG					0b0000
#define		IN_FLOATING					0b0100
#define		IN_PULL_UP_DOWN				0b1000

#define		OUT_10MHZ_PP				0b0001
#define		OUT_10MHZ_OD				0b0101
#define		OUT_10MHZ_AF_PP				0b1001
#define		OUT_10MHZ_AF_OD				0b1101

#define		OUT_2MHZ_PP					0b0010
#define		OUT_2MHZ_OD					0b0110
#define		OUT_2MHZ_AF_PP				0b1010
#define		OUT_2MHZ_AF_OD				0b1110

#define		OUT_50MHZ_PP				0b0011
#define		OUT_50MHZ_OD				0b0111
#define		OUT_50MHZ_AF_PP				0b1011
#define		OUT_50MHZ_AF_OD				0b1111




#endif /* DIO_INT_H_ */
