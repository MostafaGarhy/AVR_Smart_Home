/************************************************************************************/
/*   Authors	:	Sama Saleh	      -    Nada Mohammed 	 		     			*/
/*   				Bassem Hussien 	  -    Mostafa Ahmed 			     			*/
/*   Date		:	3rd Sep	2032													*/
/*   Project	:	Smart Home														*/
/*   Version	:	V1.0															*/
/************************************************************************************/
/* LIB */
#include "0-LIB/STD_TYPES.h"
#include "0-LIB/BIT_MATH.h"
#include "0-LIB/delay.h"

/* MCAL */
#include "1-MCAL/1-DIO/DIO_Interface.h"

/*********************************		Master Application		********************************/
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
