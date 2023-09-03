
/* LIB */
#include "../../0-LIB/STD_TYPES.h"
#include "../../0-LIB/BIT_MATH.h"
#include "../../0-LIB/delay.h"

#include "I2C_Interface.h"
#include "I2C_Private.h"
#include "I2C_Config.h"

void TWI_VidMasterInit(void)
{
	/* Prescaler Option */
	CLR_BIT(TWSR, TWPS0);
	CLR_BIT(TWSR, TWPS1);

	/*  Calculate TWBR Value dependent on SCL_CLK   */
//	TWBR = (((F_CPU/SCL_CLK) - 16) / 2);

//	/* Freq --> 400Khz */
//	TWBR = 2;

//	/* Freq --> 100Khz */
	TWBR = 32;

	SET_BIT(TWCR, TWEA);
	/* Enable I2C Peripheral */
	SET_BIT(TWCR, TWEN);
}

void TWI_VidSlaveInit(u8 Copy_U8SlaveAddress)
{
	/* Enable ACK */
	SET_BIT(TWCR, TWEA);

	/* Write Address */
	TWAR = Copy_U8SlaveAddress << 1;

	/* Enable I2C Peripheral */
	SET_BIT(TWCR, TWEN);
}

void TWI_VidStartCondition(void)
{
	/* Enable start condition & Clear INT_flag */
	SET_BIT(TWCR, TWINT);
	SET_BIT(TWCR, TWSTA);

	/* Wait for the HW Action */
	while(GET_BIT(TWCR, TWINT) == 0);
}

void TWI_VidRestartCondition(void)
{
	/* Enable start condition & Clear INT_flag */
	SET_BIT(TWCR, TWINT);
	SET_BIT(TWCR, TWSTA);

	/* Wait for the HW Action */
	while(GET_BIT(TWCR, TWINT) == 0);
}

void TWI_VidStopCondition(void)
{
	/* Enable stop condition & Clear INT_flag */
	SET_BIT(TWCR, TWINT);
	CLR_BIT(TWCR, TWSTA);			/////////////////////
	SET_BIT(TWCR, TWSTO);
}

void TWI_VidSlaveAddWrite(u8 Copy_U8SlaveAddress)
{
	/* Write the Slave Address to communicate with */
	TWDR = Copy_U8SlaveAddress << 1;

	/* Write Operation: Clear TWDR_RW_BIT */
	CLR_BIT(TWDR, TWDR_RW_BIT);

	/* Disable Start condition */
	CLR_BIT(TWCR, TWSTA);

	SET_BIT(TWCR, TWINT);
	/* Wait for the HW Action */
	while(GET_BIT(TWCR, TWINT) == 0);
}

void TWI_VidSlaveAddRead(u8 Copy_U8SlaveAddress)
{
	/* Write the Slave Address to communicate with */
	TWDR = Copy_U8SlaveAddress << 1;

	/* Read Operation */
	SET_BIT(TWDR, TWDR_RW_BIT);

	/* Disable Start condition */
	CLR_BIT(TWCR, TWSTA);

	SET_BIT(TWCR, TWINT);
	/* Wait for the HW Action */
	while(GET_BIT(TWCR, TWINT) == 0);
}

void TWI_VidMasterSendData(u8 Copy_U8Data)
{
	/* Write Data */
	TWDR = Copy_U8Data;
	SET_BIT(TWCR, TWINT);
	/* Wait for the HW Action */
	while(GET_BIT(TWCR, TWINT) == 0);
}

u8 TWI_U8SlaveReadData(void)
{
	/* First SLA & Write has been received, ACK has been returned */
	while((TWSR & 0xF8) != 0x60);

	/* Clear flag */
	SET_BIT(TWCR, TWINT);

	/* Second SLA & Write has been received, ACK has been returned */
	while((TWSR & 0xF8) != 0x80);

	return TWDR;
}

u8 TWI_U8MasterReadData(void)
{
	SET_BIT(TWCR, TWINT);
	/* Wait for the HW Action */
	while(GET_BIT(TWCR, TWINT) == 0);

	/* Read Data */
	return TWDR;
}










