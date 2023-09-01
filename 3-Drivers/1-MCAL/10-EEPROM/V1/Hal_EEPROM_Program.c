/****************************************************************************************/
/*  Author	:	Mostafa Ahmed Garhy	                                                    */
/*  Date	:	28	Aug	2023		                                                    */
/*  SWC		:	AT24C08 EEPROM Driver	                                                */
/*  File	:	Hal_EEPROM_Program.c                                                    */
/*  Version	:	V1.0				                                                    */
/*  Desc	:	This API allows user to Write and Read Data into/from the EEPROM    	*/
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "I2C_Interface.h"
#include <util/delay.h>
#include "Hal_EEPROM_Interface.h"
#include "Hal_EEPROM_Private.h"

/****************************************************************************************/
/*    Function Name	:	HEEPROM_VidWriteByteData								   		*/
/*    I/P Arguments	:	Copy_u16ByteAddress Options: 0x0000 --> 0x3FF (10-bit Address)	*/
/*    I/P Arguments	:	Copy_U8ByteData Options: 0x00 --> 0xFF	  (8-bit Address)		*/
/*    Returning 	:	Noting															*/
/*    Description	:	This API allows user to Access 1K Bytes (8K Bits) EEPROM 		*/
/*    					and send Byte Data into the EEPROM		  					    */
/****************************************************************************************/
void HEEPROM_VidWriteByteData(u16 Copy_u16ByteAddress, u8 Copy_U8ByteData)
{
	//[1] Master Sends Start Condition
	TWI_VidStartCondition();

	//[2] Send Device Address to access & Write Operation
	TWI_VidSlaveAddWrite((EEPROM_FIXED_ADD)|(EEPROM_A2_Value<<2)|(Copy_u16ByteAddress>>8));

	//[3] Master Sends Byte Address (Location) to write
	TWI_VidMasterSendData((u8)Copy_u16ByteAddress);

	//[4] Master Sends Byte Data
	TWI_VidMasterSendData(Copy_U8ByteData);

	//[5] Stop Condition
	TWI_VidStopCondition();

	//[6] Wait for Writing Cycle
	_delay_ms(5);
}

/****************************************************************************************/
/*    Function Name	:	HEEPROM_U8ReadByteData									   		*/
/*    I/P Arguments	:	Copy_u16ByteAddress Options: 0x0000 --> 0x3FF (10-bit Address)	*/
/*    Returning 	:	Local_U8Data													*/
/*    Description	:	This API allows user to Access 1K Bytes (8K Bits) EEPROM 		*/
/*    					and receive Byte Data from the EEPROM		 				    */
/****************************************************************************************/
u8 HEEPROM_U8ReadByteData(u16 Copy_u16ByteAddress)
{
	u8 Local_U8Data;

	//[1] Master Sends Start Condition
	TWI_VidStartCondition();

	//[2] Send Device Address to access & Write Operation
	TWI_VidSlaveAddWrite((EEPROM_FIXED_ADD)|(EEPROM_A2_Value<<2)|(Copy_u16ByteAddress>>8));

	//[3] Master Sends Byte Address (Location) to receive
	TWI_VidMasterSendData((u8)Copy_u16ByteAddress);

	//[4] Master Sends Start Condition
	TWI_VidRestartCondition();

	//[5] Send Device Address to access & Read Operation
	TWI_VidSlaveAddRead((EEPROM_FIXED_ADD)|(EEPROM_A2_Value<<2)|(Copy_u16ByteAddress>>8));

	//[6] Master Receives Data
	Local_U8Data = TWI_U8MasterReadData();

	//[7] Stop Condition
	TWI_VidStopCondition();

	//[8] Wait for Reading Cycle
	_delay_ms(5);

	return Local_U8Data;
}
