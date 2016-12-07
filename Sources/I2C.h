/*
 * I2C.h
 *
 *  Created on: Dec 4, 2016
 *      Author: sahan
 */

#ifndef SOURCES_I2C_H_
#define SOURCES_I2C_H_


#define I2C_DisableAck()       I2C0_C1 |= I2C_C1_TXAK_MASK
#define I2C_EnableAck()        I2C0_C1 &= ~I2C_C1_TXAK_MASK
#define I2C_RepeatedStart()    I2C0_C1 |= I2C_C1_RSTA_MASK
#define I2C_EnterRxMode()      I2C0_C1 &= ~I2C_C1_TX_MASK
#define I2C_write_byte(data)   I2C0_D = data

#define I2C_Start()            I2C0_C1 |= I2C_C1_TX_MASK;\
                               I2C0_C1 |= I2C_C1_MST_MASK

#define I2C_Stop()             I2C0_C1 &= ~I2C_C1_MST_MASK;\
                               I2C0_C1 &= ~I2C_C1_TX_MASK

#define I2C_Wait()             while((I2C0_S & I2C_S_IICIF_MASK)==0) {} \
                               I2C0_S |= I2C_S_IICIF_MASK;

void I2C_WriteRegister(unsigned char SlaveAddress, unsigned char RegisterAddress, char u8Data);
unsigned char I2C_ReadRegister(unsigned char SlaveAddress, unsigned char RegisterAddress);
void I2C_ReadMultiRegisters(unsigned char SlaveAddress, unsigned char RegisterAddress, unsigned char n, unsigned char *r);
//void Pause(int number);

#endif /* SOURCES_I2C_H_ */
