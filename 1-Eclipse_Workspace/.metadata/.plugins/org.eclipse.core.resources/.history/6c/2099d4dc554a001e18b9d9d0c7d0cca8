/********************************************************************************/
/*    Author	:	Mostafa Ahmed Garhy		                                    */
/*    SWC		:	CLCD Driver				                                    */
/*    File		:	CLCD_2x16_Interface.h		                                */
/*    Date		:	30 Aug 2023				                                    */
/*    Version 	:	V1.3					                                    */
/*    Desc		:	This header file contains CLCD 2x16 Functions Prototypes    */
/*    				and CLCD Configurations 								    */
/********************************************************************************/
#ifndef CLCD_2X16_INTERFACE_H_
#define CLCD_2X16_INTERFACE_H_

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
//LCD Shift All Pattern to LEFT or RIGHT
void CLCD_VidShiftAll(u8 Copy_U8ShiftType, u8 Copy_U8ShiftNumber);
//LCD Command to set the CGRAM Address
void CLCD_VidSetAddressOfCGRAM(void);
//LCD Write Custom Pattern on CGRAM
void CLCD_VidWritePatternOnCGRAM(u8 *Copy_U8PatternArray);

/* Select LCD Mode :
 * LCD_8_BIT_MODE - LCD_4_BIT_MODE
 *********************************************/
#define LCD_MODE		LCD_8_BIT_MODE

/**********************************************
 *  LCD Data & Control DIO_Ports Configuration:
 * 	PORTA_U8_INDEX
 *	PORTB_U8_INDEX
 *  PORTC_U8_INDEX
 *	PORTD_U8_INDEX
 * ********************************************/
#define LCD_PORT		PORTA_U8_INDEX
#define LCD_CTRL		PORTC_U8_INDEX

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
/* LCD Pins in 4-Bit Mode */
#define LCD_PIN4		PIN4_U8_INDEX
#define LCD_PIN5		PIN5_U8_INDEX
#define LCD_PIN6		PIN6_U8_INDEX
#define LCD_PIN7		PIN7_U8_INDEX


/**********************************************
 *  LCD Cursor Configuration:
 * 	CURS_ON
 *	CURS_OFF
 * ********************************************/
#define CURSOR 			 CURS_OFF

/* Maximum Range of Digit for the Number to String */
#define DIGITS_RNG			10

/* Shifting Type */
#define RIGHT			1
#define LEFT			0


#endif
