/********************************************************************************************/
/*  Author	:	Mostafa Ahmed Garhy	                                                        */
/*  Date	:	17	Aug	2023		                                                        */
/*  SWC		:	ADC Driver			                                                        */
/*  File	:	ADC_Program.c		                                                        */
/*  Version	:	V1.0				                                                        */
/*  Desc	:	This API allows user to Initialize The ADC and get the 10-Bit Digital Value	*/
/********************************************************************************************/

/* LIB */
#include "../../0-LIB/STD_TYPES.h"
#include "../../0-LIB/BIT_MATH.h"

#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"
#include "../1-DIO/DIO_Interface.h"
#include "../3-GIE/GI_interface.h"

void ADC_VidInit(void)
{
	//Set the Vref as AVCC
	SET_BIT(ADC_U8_ADMUX_REG, 6);
	CLR_BIT(ADC_U8_ADMUX_REG, 7);

	//Select Right Adjust
	CLR_BIT(ADC_U8_ADMUX_REG, 5);

	//Prescaler = 8 Mhz / 128
	SET_BIT(ADC_U8_ADCSRA_REG, 0);
	SET_BIT(ADC_U8_ADCSRA_REG, 1);
	SET_BIT(ADC_U8_ADCSRA_REG, 2);

	//Disable Auto Triggering
	CLR_BIT(ADC_U8_ADCSRA_REG, 5);

	//Enable ADC Peripheral
	SET_BIT(ADC_U8_ADCSRA_REG, 7);
}

u16 ADC_U16GetDigitalValue(u8 Copy_U8ChannelNum)
{
	u16 Local_U16DigitalValue = 0, Local_U16TimeOut = 0;
	if(Copy_U8ChannelNum > 7)
	{
		/* Do Nothing */
	}
	else
	{
		//Select the channel Number
		Copy_U8ChannelNum &= 0x07;
		ADC_U8_ADMUX_REG &= 0xE0;
		ADC_U8_ADMUX_REG |= Copy_U8ChannelNum;

		//Start Conversion
		SET_BIT(ADC_U8_ADCSRA_REG, 6);

		//Polling on the flag
		while((GET_BIT(ADC_U8_ADCSRA_REG, 4) == 0) && (Local_U16TimeOut < 50000))
		{
			Local_U16TimeOut++;
		}
		if(GET_BIT(ADC_U8_ADCSRA_REG, 4) == 1)
		{
			//Clear The Flag
			SET_BIT(ADC_U8_ADCSRA_REG, 4);

			//Read The Digital Converted Value
			Local_U16DigitalValue = ADC_U8_ADCL_REG;
		}
	}
	return Local_U16DigitalValue;
}
