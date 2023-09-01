/*********************************************************************************/
/**************************** Author: "Mostafa Garhy" ****************************/
/******************************* Date: 2nd sep 2022 ******************************/
/****************************** File: 7Seg_Program.c *****************************/
/********************************* Version: V1.0 *********************************/
/****** Desc: A c file has the implementation of the 7-Segment APIs functions. ***/
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "delay.h"

#include "7Seg_Interface.h"
#include "7Seg_Private.h"
#include "7Seg_Config.h"
#include "DIO_interface.h"

const u8 Num_arr[10] = {ZERO,ONE,TWO,THREE,FOUR,
							FIVE,SIX,SEVEN,EIGHT,NINE};

void SevSeg_VidDisplayNumber ( u8 Copy_U8PortNumber , u8 Copy_U8Number)
{
	if(Copy_U8PortNumber >= 0 && Copy_U8PortNumber < 4)
	{
		if(Copy_U8Number >= 0 && Copy_U8Number < 10)
		{
			#if SEVENSEG_TYPE == COM_CATHODE
			DIO_VidSetPortValue( Copy_U8PortNumber , Num_arr[Copy_U8Number] );
			#elif SEVENSEG_TYPE == COM_ANODE
			DIO_VidSetPortValue( Copy_U8PortNumber , 0xFF - (Num_arr[Copy_U8Number]));
			#else 
				#error "Wrong input of the 7-Segment type"
			#endif
		}
	}
}

void SevSeg_VidDispDescend (u8 Copy_U8Digit1Port, u8 Copy_U8Digit2Port, u8 Last_num, u8 First_num, u16 _delay_ms_)
{
	/*		Display Last_num --> First_num		*/
	s8 first_rem = First_num % 10;
	s8 first_quot = First_num / 10;


	s8 last_rem = Last_num % 10;
	s8 last_quot = Last_num / 10;

	s8 first_dig = 0;

	s8 i,j;
	for(i = last_quot; i >= first_quot; i--)
	{
		SevSeg_VidDisplayNumber(Copy_U8Digit2Port, i);
		if(i == first_quot)
		{
			first_dig = first_rem;
		}
		for(j = last_rem; j >= first_dig; j--)
		{
			SevSeg_VidDisplayNumber(Copy_U8Digit1Port, j);
			delay_ms(_delay_ms_);
		}
		if(j == -1)
		{
			last_rem = 9;
		}
	}
}
