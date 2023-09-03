/****************************************************************************/
/*    Author	:	Mostafa Ahmed Garhy		                                */
/*    SWC		:	CLCD Driver				                                */
/*    File		:	CLCD_2x16_Program.c		                                */
/*    Date		:	19 Aug 2023				                                */
/*    Version 	:	V1.1					                                */
/*    Desc		:	This APIs allows user to Display characters, strings,   */
/*    				and unsigned and signed numbers on 2x16 CLCD            */
/****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "delay.h"

#include "CLCD_2x16_Interface.h"
#include "CLCD_2x16_Private.h"
#include "DIO_interface.h"

/* Array of ASCII Numbers for Characters of number 0-->9 */
const u8 Arr_Nums[10] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39};

/* Array saves digits of numbers */
u8 Arr_char[DIGITS_RNG];

void CLCD_VidSendCmd(u8 Copy_U8Cmd)
{
	/* Control pins settings */
	DIO_VidSetPinValue(LCD_CTRL, LCD_RS_PIN, PIN_U8_VALUE_LOW);
	DIO_VidSetPinValue(LCD_CTRL, LCD_RW_PIN, PIN_U8_VALUE_LOW);

	/* Entering the command here */
	DIO_VidSetPortValue(LCD_PORT, Copy_U8Cmd);

	/* Enable sequence */
	DIO_VidSetPinValue(LCD_CTRL, LCD_EN_PIN, PIN_U8_VALUE_HIGH);
	_delay_ms(2);
	DIO_VidSetPinValue(LCD_CTRL, LCD_EN_PIN, PIN_U8_VALUE_LOW);
}

void CLCD_VidInit(void)
{
	/* Initialization of Data and Command PORTS */
	DIO_VidSetPortDirection(LCD_PORT, PORT_U8_VALUE_ALL_HIGH);
	DIO_VidSetPinDirection(LCD_CTRL, LCD_RS_PIN, PIN_U8_DIR_OUTPUT);
	DIO_VidSetPinDirection(LCD_CTRL, LCD_RW_PIN, PIN_U8_DIR_OUTPUT);
	DIO_VidSetPinDirection(LCD_CTRL, LCD_EN_PIN, PIN_U8_DIR_OUTPUT);

	_delay_ms(35);
	CLCD_VidSendCmd(FUNC_SET_5X8_4BIT_MODE);
	CLCD_VidSendCmd(Disp_ON_OFF);
#if CURSOR == CURS_OFF
	CLCD_VidSendCmd(CURSOR_OFF);
#else
	CLCD_VidSendCmd(CURSOR_ON);
#endif
	CLCD_VidSendCmd(Disp_CLR);
}
void CLCD_VidWriteChar(u8 Copy_U8Character)
{
	/* Control pins settings */
	DIO_VidSetPinValue(LCD_CTRL, LCD_RS_PIN, PIN_U8_VALUE_HIGH);
	DIO_VidSetPinValue(LCD_CTRL, LCD_RW_PIN, PIN_U8_VALUE_LOW);

	/* Entering the data here */
	DIO_VidSetPortValue(LCD_PORT, Copy_U8Character);

	/* Enable sequence */
	DIO_VidSetPinValue(LCD_CTRL, LCD_EN_PIN, PIN_U8_VALUE_HIGH);
	_delay_ms(2);
	DIO_VidSetPinValue(LCD_CTRL, LCD_EN_PIN, PIN_U8_VALUE_LOW);
}

void CLCD_VidWriteString(u8 *Copy_U8String)
{
	while(*Copy_U8String > NULL_STR)
	{
		CLCD_VidWriteChar(*Copy_U8String++);
	}
}

void CLCD_VidClearScreen(void)
{
	CLCD_VidSendCmd(Disp_CLR);
}

void CLCD_VidGoToXY(u8 Copy_U8YRow, u8 Copy_U8XCol)
{
	/* I/P Validation */
	if(Copy_U8YRow > 2 || Copy_U8YRow <= 0 || Copy_U8XCol > 15 || Copy_U8XCol < 0)
	{
		/* Do Nothing */
	}
	else
	{
		switch(Copy_U8YRow)
		{
			case 1 : CLCD_VidSendCmd(0x80 + Copy_U8XCol);break;
			case 2 : CLCD_VidSendCmd(0xc0 + Copy_U8XCol);break;
		}
	}
}

void CLCD_VidWriteDigitToChar(u8 Copy_U8Digit)
{
	CLCD_VidWriteChar(Arr_Nums[Copy_U8Digit]);
}

void CLCD_VidWriteNumToStr(s32 Copy_U32Number)
{
	u8 counter = 0;
	s32 Local_qoutient = Copy_U32Number, Local_remainder = Copy_U32Number;
	if(Copy_U32Number == 0)
	{
		CLCD_VidWriteChar(' ');
		CLCD_VidWriteDigitToChar(0);
	}
	else
	{
		if(Copy_U32Number > 0)   //Positive number
		{
			/* Reserving each digit in Arr_char */
			while(Local_qoutient /10 > 0)
			{
				Local_remainder = Local_qoutient % 10;
				Local_qoutient /= 10;
				Arr_char[counter++] =  Local_remainder;
			}
			Local_remainder = Local_qoutient % 10;
			Arr_char[counter] = Local_remainder;
		}
		else					//Negative number
		{
			CLCD_VidWriteChar('-');
			Copy_U32Number *= -1;
			Local_qoutient = Copy_U32Number, Local_remainder = Copy_U32Number;
			/* Reserving each digit in Arr_char */
			while(Local_qoutient /10 > 0)
			{
				Local_remainder = Local_qoutient % 10;
				Local_qoutient /= 10;
				Arr_char[counter++] =  Local_remainder;
			}
			Local_remainder = Local_qoutient % 10;
			Arr_char[counter] = Local_remainder;
		}
		for(s8 i = counter; i >= 0; i--)
		{
			CLCD_VidWriteDigitToChar(Arr_char[i]);
		}
		CLCD_VidWriteChar(' ');
	}
}
