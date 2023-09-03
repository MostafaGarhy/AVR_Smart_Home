/*
 * SPI_Program.c
 *
 *  Created on: Aug 24, 2023
 *      Author: ma257
 */

/* LIB */
#include "../../../0-LIB/STD_TYPES.h"
#include "../../../0-LIB/BIT_MATH.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"

void SPI_VidPreInit(void)
{
#if	(SPI_NODE_MODE == SPI_MASTER_MODE)
	/* Disable the SPI Interrupt */
	CLR_BIT(SPI->SPCR_REG, SPIE);
	/* the LSB of the data word is transmitted first */
	SET_BIT(SPI->SPCR_REG, DORD);
	/* Select this Node as ---> Master */
	SET_BIT(SPI->SPCR_REG, MSTR);
	/* Select the Clock Polarity >> Falling is Leading */
	SET_BIT(SPI->SPCR_REG, CPOL);
	/* Select the Clock Phase >> Setup Then Sample */
	SET_BIT(SPI->SPCR_REG, CPHA);
	/* Select the CLOCK for the Master >> Osc.freq/16 */
	SET_BIT(SPI->SPCR_REG, SPR0);
	CLR_BIT(SPI->SPCR_REG, SPR1);
	CLR_BIT(SPI->SPSR_REG, SPI2X);

#elif (SPI_NODE_MODE == SPI_SLAVE_MODE)
	/* Disable the SPI Interrupt */
	CLR_BIT(SPI->SPCR_REG, SPIE);
	/* the LSB of the data word is transmitted first */
	SET_BIT(SPI->SPCR_REG, DORD);
	/* Select this Node as ---> Slave */
	CLR_BIT(SPI->SPCR_REG, MSTR);
	/* Select the Clock Polarity >> Falling is Leading */
	SET_BIT(SPI->SPCR_REG, CPOL);
	/* Select the Clock Phase >> Setup Then Sample */
	SET_BIT(SPI->SPCR_REG, CPHA);
#endif
	/* Enable the SPI Peripheral */
	SET_BIT(SPI->SPCR_REG, SPE);
}

void SPI_VidTransmitData(u8 Copy_U8Data)
{
	SPI->SPDR_REG = Copy_U8Data;
	while(GET_BIT(SPI->SPSR_REG, SPIF) != 1);	//Wait until the data to be sent
}

u8 SPI_U8ReceiveData(void)
{
	while(GET_BIT(SPI->SPSR_REG, SPIF) != 1);	//Wait until the data to be sent
	return SPI->SPDR_REG;
}
