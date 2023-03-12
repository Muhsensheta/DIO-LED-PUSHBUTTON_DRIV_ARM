/*
 * PB_ARM_prog.c
 *
 *  Created on: ٠٢‏/٠٣‏/٢٠٢٣
 *      Author: houras
 */

#include "STD_TYPES.h"
#include"BIT_MATH.h"

#include  "DIO_int.h"
#include  "RCC_interface.h"
#include  "PB_int.h"
void PB_void_Init(){

	M_DIO_void_setPinDir(PORTA_ID,PIN3,IN_PULL_UP_DOWN);
	M_DIO_void_setPinValue(PORTA_ID,PIN3, HIGH);

}
void PB_void_GetRead(u8 *Value)
{

	M_DIO_void_getPinValue(PORTA_ID,PIN3, Value);


}
