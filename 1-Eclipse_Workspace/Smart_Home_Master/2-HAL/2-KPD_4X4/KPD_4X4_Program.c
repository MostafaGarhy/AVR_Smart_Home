/****************************************************************************/
/***    Author		:	Mostafa Ahmed Garhy								  ***/
/***    Date		:	14 Aug	2023									  ***/
/***    SWC			:	KPD_Driver										  ***/
/***    File		:	KPD_4X4_Program.c								  ***/
/***    Version		:	V1.0     										  ***/
/***    Desc		:	This API allows user to take numbers or chars     ***/
/***    				from a KPD_matrix.					   	  		  ***/
/****************************************************************************/

/* LIB */
#include "../../0-LIB/STD_TYPES.h"
#include "../../0-LIB/BIT_MATH.h"
#include "../../0-LIB/delay.h"

#include "KPD_4X4_Interface.h"
#include "KPD_4X4_Config.h"
#include "../../1-MCAL/1-DIO/DIO_Interface.h"

#if KPD_DISP == KPD_DISP_CHAR
	const u8 Global_KPDArr_Char[4][4] = {
			{'7', '8', '9', '/'},
			{'4', '5', '6', 'x'},
			{'1', '2', '3', '-'},
			{'C', '0', '=', '+'}
	};
#elif KPD_DISP == KPD_DISP_NUMS
	const u8 Global_KPDArr_Nums[4][4] = {
			{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
	};
#endif

void KPD_VidInit(void)
{
	//4_Upper_Cols are 4 Inputs Pins
	DIO_VidSetPortDirection(KPD_PORT, 0x0F);

	//Activate the Pull-Up resistors for the 4_Upper_Cols Input Pins
	//& Make the 4 Lower_Rows Pins are Outputs High
	DIO_VidSetPortValue(KPD_PORT, 0xFF);
}
u8 KPD_U8GetPressedKey(void)
{
	u8 Local_U8Key = 0xFF; //Key Not Pressed
	u8 row, col, Pin_value, Local_u8Flag = 0;
	for(row = 0; row < 4; row++)
	{
		//High The 4_Lower_Rows Output Pins
		DIO_VidSetPinValue(KPD_PORT, row, DIO_PIN_LOW);
		for(col = 4; col < 8; col++)
		{
			//Check the Col_Input Pin if it is Low
			DIO_VidGetPinValue(KPD_PORT, col, &Pin_value);
			if(Pin_value == DIO_PIN_LOW)
			{
				delay_ms(20); //Debouncing
				DIO_VidGetPinValue(KPD_PORT, col, &Pin_value);
				while(Pin_value == DIO_PIN_LOW)
				{
					DIO_VidGetPinValue(KPD_PORT, col, &Pin_value);
				}

				#if KPD_DISP == KPD_DISP_CHAR
				Local_U8Key = Global_KPDArr_Char[row-1][col];
				#elif KPD_DISP == KPD_DISP_NUMS
				Local_U8Key = Global_KPDArr_Nums[row-1][col];
				#endif

				Local_u8Flag = 1;
				break;
			}
		}
		DIO_VidSetPinValue(KPD_PORT, row, DIO_PIN_HIGH);
		if(Local_u8Flag == 1)
		{
			break;
		}
	}
	return Local_U8Key;
}
