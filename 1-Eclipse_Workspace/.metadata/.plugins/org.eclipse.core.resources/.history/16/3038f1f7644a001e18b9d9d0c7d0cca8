/*
 * SPI_Private.h
 *
 *  Created on: Aug 24, 2023
 *      Author: ma257
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

typedef struct{
	volatile u8 SPCR_REG;
	volatile u8 SPSR_REG;
	volatile u8 SPDR_REG;

	/*	SPCR Bits Enumeration	*/
	enum{
		SPR0,SPR1,CPHA,CPOL,MSTR,DORD,SPE,SPIE
		}SPCR;

	/*	SPSR Bits Enumeration	*/
	enum{
		SPI2X,WCOL = 6,SPIF		//Bit_1 -> Bit_5 are Reserved Bits
		}SPSR;
}SPI_t;

/*	SPI Base Address: 0x2D	*/
#define SPI		((volatile SPI_t*)0x2D)

#define SPI_MASTER_MODE		0
#define SPI_SLAVE_MODE		1

#endif /* SPI_PRIVATE_H_ */
