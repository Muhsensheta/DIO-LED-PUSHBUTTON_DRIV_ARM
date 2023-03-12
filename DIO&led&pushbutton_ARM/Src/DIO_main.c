#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include	"RCC_interface.h"
#include	"DIO_int.h"
#include  "PB_int.h"


void	Delay(void)
{
	for(u32 i = 0; i < 500000 ; i++)
	{
		asm("NOP");
	}
}

int	main(void)
{

	u8 Read=0;
	/*	Initialization Part		*/
	
	/*	System Clk init			*/
	MRCC_voidSysClkInit();
	
	/*	Toggle Led C13	GPIOC	*/
	/*	1- Enable Per Clk "RCC" Port C		*/
	MRCC_voidEnablePerClk(RCC_APB2,2);
	MRCC_voidEnablePerClk(RCC_APB2,4);
	
	 PB_void_Init();
	/*	Direction for C13 is output Push Pull */
	M_DIO_void_setPinDir(PORTA_ID, PIN0, OUT_2MHZ_PP);
	
	M_DIO_void_setPinValue(PORTA_ID, PIN0, HIGH);
	Delay();
	M_DIO_void_setPinValue(PORTA_ID, PIN0, LOW);
	Delay();

	while(1)
	{
		/*	Toggle led */
		//PB_void_GetRead(&Read);
		M_DIO_void_getPinValue(PORTA_ID, PIN3, &Read);

		if(Read==LOW)
		{

		//M_DIO_void_setPinValue(PORTC_ID, PIN13, HIGH);

	//	M_DIO_void_setPinValue(PORTA_ID, PIN0, LOW);
		//Delay();
		M_DIO_void_setPinValue(PORTA_ID, PIN0, HIGH);
		Delay();

	   }
		else if(Read==HIGH)
		{
			M_DIO_void_setPinValue(PORTA_ID, PIN0, LOW);
			Delay();

		}
	}
	return 0;
}
