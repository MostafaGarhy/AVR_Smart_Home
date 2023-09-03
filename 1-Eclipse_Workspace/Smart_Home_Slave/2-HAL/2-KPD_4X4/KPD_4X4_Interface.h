/*
 * KPD_4X4_Interface.h
 *
 *  Created on: Aug 14, 2023
 *      Author: MostafaGarhy
 */

#ifndef KPD_4X4_INTERFACE_H_
#define KPD_4X4_INTERFACE_H_

//KPD 8 Port Pins Initialization Function (4_Lower are Rows_In & 4_Upper are Cols_Out)
void KPD_VidInit(void);
//KPD Get the Pressed Key Number Function
u8 KPD_U8GetPressedKey(void);

/* KPD Display Configuration Macros */
#define KPD_DISP_CHAR	 0
#define KPD_DISP_NUMS	 1

#endif /* KPD_4X4_H_ */
