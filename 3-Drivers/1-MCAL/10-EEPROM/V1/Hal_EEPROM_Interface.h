/****************************************************************************************/
/*  Author	:	Mostafa Ahmed Garhy	                                                    */
/*  Date	:	28	Aug	2023		                                                    */
/*  SWC		:	AT24C08 EEPROM Driver	                                                */
/*  File	:	Hal_EEPROM_Interface.h                                                  */
/*  Version	:	V1.0				                                                    */
/*  Desc	:	This API allows user to Write and Read Data into/from the EEPROM    	*/
/****************************************************************************************/

#ifndef HAL_EEPROM_INTERFACE_H_
#define HAL_EEPROM_INTERFACE_H_

void HEEPROM_VidWriteByteData(u16 Copy_u16ByteAddress, u8 Copy_U8ByteData);
u8 HEEPROM_U8ReadByteData(u16 Copy_u16ByteAddress);

#endif /* HAL_EEPROM_INTERFACE_H_ */
