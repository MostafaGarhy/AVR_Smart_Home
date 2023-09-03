/************************************************************************************/
/***************************** Author: "MOSTAFA GARHY" ******************************/
/****************************** File: 7Seg_Interface.h ******************************/
/******************************* Date: 2nd sep 2022 *********************************/
/********************************** Version: V1.0 ***********************************/
/*** Desc: An interfacing file includes a function takes a number and port number ***/
/********** as input parameters then it displays the corresponding number. **********/
/************************************************************************************/

#ifndef _7SEG_INTERFACE_H_
#define _7SEG_INTERFACE_H_

//Function allows user to display number from 0 to 9 for only one 7_Seg_digit
void SevSeg_VidDisplayNumber ( u8 Copy_U8PortNumber , u8 Copy_U8Number);
//Function allows user to display number descending from 99 to 00
void SevSeg_VidDispDescend (u8 Copy_U8Digit1Port, u8 Copy_U8Digit2Port, u8 Last_num, u8 First_num, u16 delay_ms_);

#endif
