/*
 * SPI_Interface.h
 *
 *  Created on: Aug 24, 2023
 *      Author: ma257
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_VidPreInit(void);
void SPI_VidSlaveInit(void);
void SPI_VidTransmitData(u8 Copy_U8Data);
u8 SPI_U8ReceiveData(void);

#endif /* SPI_INTERFACE_H_ */
