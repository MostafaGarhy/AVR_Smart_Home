/******************************************************************************/
/********    Author		:	********/
/********    SWC		:	********/
/********    ********/
/********    ********/
/******************************************************************************/
#ifndef CLCD_2X16_H_
#define CLCD_2X16_H_

//LCD Initialization Function
void CLCD_VidInit(void);
//LCD Send Command Function
void CLCD_VidSendCmd(u8 Copy_U8Cmd);
//LCD Write Data Function
void CLCD_VidWriteChar(u8 Copy_U8Character);
//LCD Write String Function
void CLCD_VidWriteString(u8 *Copy_U8String);
//LCD Clear Screen Function
void CLCD_VidClearScreen(void);
//LCD Go To Row_Y and Col_X Function
void CLCD_VidGoToXY(u8 Copy_U8YRow, u8 Copy_U8XCol);
//LCD Convert Digit to Char Function
void CLCD_VidWriteDigitToChar(u8 Copy_U8Digit);
//LCD Convert Number of 4 digits to String
void CLCD_VidWriteNumToStr(s32 Copy_U32Number);

/**********************************************
 *  LCD Data & Control DIO_Ports Configuration:
 * 	PORTA_U8_INDEX
 *	PORTB_U8_INDEX
 *  PORTC_U8_INDEX
 *	PORTD_U8_INDEX
 * ********************************************/
#define LCD_PORT		PORTA_U8_INDEX
#define LCD_CTRL		PORTB_U8_INDEX

/**********************************************
 *  LCD Control Pins Configurations:
 * 	PIN0_U8_INDEX
 *  PIN1_U8_INDEX
 *  PIN2_U8_INDEX
 *  PIN3_U8_INDEX
 *  PIN4_U8_INDEX
 *  PIN5_U8_INDEX
 *  PIN6_U8_INDEX
 *  PIN7_U8_INDEX
 * ********************************************/
#define LCD_RS_PIN		PIN0_U8_INDEX
#define LCD_RW_PIN		PIN1_U8_INDEX
#define LCD_EN_PIN		PIN2_U8_INDEX

/**********************************************
 *  LCD Cursor Configuration:
 * 	CURS_ON
 *	CURS_OFF
 * ********************************************/
#define CURSOR 			 CURS_OFF

/* Maximum Range of Digit for the Number to String */
#define DIGITS_RNG			10

#endif
