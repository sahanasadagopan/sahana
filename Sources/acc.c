/*
 * acc.c
 *
 *  Created on: Dec 4, 2016
 *      Author: sahan
 */
#include "MKL25Z4.h"
#include "acc.h"
#include "I2C.h"
#include "uart.h"
#include "log1.h"
#include "string.h"


unsigned char AccData[6];
char Data;
char Xoffset, Yoffset, Zoffset;
short Xout_14_bit, Yout_14_bit, Zout_14_bit;
void clock_Init(void)
{
	//I2C0 module initialization
	SIM_SCGC4 |= SIM_SCGC4_I2C0_MASK;		// Turn on clock to I2C0 module
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;		// Turn on clock to Port E module
	PORTE_PCR24 = PORT_PCR_MUX(5);			// PTE24 pin is I2C0 SCL line
	PORTE_PCR25 = PORT_PCR_MUX(5);			// PTE25 pin is I2C0 SDA line

	//Configure the PTA14 pin (connected to the INT1 of the MMA8451Q) for falling edge interrupts
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;		// Turn on clock to Port A module
	PORTA_PCR14 |= (0|PORT_PCR_ISF_MASK|	// Clear the interrupt flag
					  PORT_PCR_MUX(0x1)|	// PTA14 is configured as GPIO
					  PORT_PCR_IRQC(0xA));	// PTA14 is configured for falling edge interrupts

	//Enable PORTA interrupt on NVIC
	NVIC_ICPR |= 1 << ((INT_PORTA - 16)%32);
	NVIC_ISER |= 1 << ((INT_PORTA - 16)%32);
}


void Accelerometer_Init (void)
{
	unsigned char reg_val = 0;

	I2C_WriteRegister(MMA845x_I2C_ADDRESS, CTRL_REG2, 0x40);		// Reset all registers to POR values

	 do		// Wait for the RST bit to clear
	{
		reg_val = I2C_ReadRegister(MMA845x_I2C_ADDRESS, CTRL_REG2) & 0x40;
	} 	while (reg_val);

	I2C_WriteRegister(MMA845x_I2C_ADDRESS, XYZ_DATA_CFG_REG, 0x00);		// +/-2g range -> 1g = 16384/4 = 4096 counts
	I2C_WriteRegister(MMA845x_I2C_ADDRESS, CTRL_REG2, 0x02);		// High Resolution mode
	I2C_WriteRegister(MMA845x_I2C_ADDRESS, CTRL_REG1, 0x3D);	// ODR = 1.56Hz, Reduced noise, Active mode
}

void Calibrate (void)
{
	unsigned char reg_val = 0;

	while (!reg_val)		// Wait for a first set of data
	{
		reg_val = I2C_ReadRegister(MMA845x_I2C_ADDRESS, STATUS_REG) & 0x08;
	}

	I2C_ReadMultiRegisters(MMA845x_I2C_ADDRESS, OUT_X_MSB_REG, 6, AccData);		// Read data output registers 0x01-0x06

	Xout_14_bit = ((short) (AccData[0]<<8 | AccData[1])) >> 2;		// Compute 14-bit X-axis output value
	Yout_14_bit = ((short) (AccData[2]<<8 | AccData[3])) >> 2;		// Compute 14-bit Y-axis output value
	Zout_14_bit = ((short) (AccData[4]<<8 | AccData[5])) >> 2;		// Compute 14-bit Z-axis output value

	Xoffset = -(Xout_14_bit / 8) ;		// Compute X-axis offset correction value
	Yoffset = -(Yout_14_bit / 8);		// Compute Y-axis offset correction value
	Zoffset = (Zout_14_bit - SENSITIVITY_2G) / 8 * (-1);		// Compute Z-axis offset correction value

	I2C_WriteRegister(MMA845x_I2C_ADDRESS, CTRL_REG1, 0x00);		// Standby mode to allow writing to the offset registers
	I2C_WriteRegister(MMA845x_I2C_ADDRESS, OFF_X_REG, Xoffset);
	I2C_WriteRegister(MMA845x_I2C_ADDRESS, OFF_Y_REG, Yoffset);
	I2C_WriteRegister(MMA845x_I2C_ADDRESS, OFF_Z_REG, Zoffset);
	I2C_WriteRegister(MMA845x_I2C_ADDRESS, CTRL_REG3, 0x00);		// Push-pull, active low interrupt
	I2C_WriteRegister(MMA845x_I2C_ADDRESS, CTRL_REG4, 0x01);		// Enable DRDY interrupt
	I2C_WriteRegister(MMA845x_I2C_ADDRESS, CTRL_REG5, 0x01);		// DRDY interrupt routed to INT1 - PTA14
	I2C_WriteRegister(MMA845x_I2C_ADDRESS, CTRL_REG1, 0x3D);		// ODR = 1.56Hz, Reduced noise, Active mode
}

void PORTA_IRQHandler()
{
	PORTA_PCR14 |= PORT_PCR_ISF_MASK;			// Clear the interrupt flag
	Data = 1;
}
