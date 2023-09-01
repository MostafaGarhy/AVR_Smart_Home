/************************************************************************************/
/*   Authors	:	Bassem Hussien 	- 	Nada Mohammed 	 							*/
/*   				Sama Saleh	   	- 	Mostafa Ahmed 								*/
/*   Date		:	3rd Sep	2032													*/
/*   Project	:	Smart Home														*/
/*   Version	:	V1.0															*/
/************************************************************************************/
/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "delay.h"

/* MCAL */
#include "DIO_Interface.h"

/*********************************		Application		********************************/
int main()
{
	DIO_VidInit();

	while(1)
	{
		DIO_VidSetPinValue(DIO_U8_PORTA, DIO_U8_PIN3, DIO_PIN_HIGH);
		delay_ms(1000);
		DIO_VidSetPinValue(DIO_U8_PORTA, DIO_U8_PIN3, DIO_PIN_LOW);
		delay_ms(1000);
	}
	return 0;
}
