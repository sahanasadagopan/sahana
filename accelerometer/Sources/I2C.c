#include "MKL25Z4.h"
#include "I2C.h"
int i;
void I2C_WriteRegister(unsigned char SlaveAddress, unsigned char RegisterAddress, char Data)
{
	I2C_Start();
	I2C0_D = SlaveAddress << 1;									/* Send I2C device address with W/R bit = 0 */
	I2C_Wait();

	I2C0_D = RegisterAddress;										/* Send register address */
	I2C_Wait();

	I2C0_D = Data;												/* Send the data */
	I2C_Wait();

	I2C_Stop();
	for(i=0;i<50;i++);
   // Pause(50);
}

unsigned char I2C_ReadRegister(unsigned char SlaveAddress, unsigned char RegisterAddress)
{
	unsigned char result;

	I2C_Start();
	I2C0_D = SlaveAddress << 1;									/* Send I2C device address with W/R bit = 0 */
	I2C_Wait();

	I2C0_D = RegisterAddress;										/* Send register address */
	I2C_Wait();

	I2C_RepeatedStart();

	I2C0_D = (SlaveAddress << 1) | 0x01;							/* Send I2C device address this time with W/R bit = 1 */
	I2C_Wait();

	I2C_EnterRxMode();
	I2C_DisableAck();

	result = I2C0_D;
	I2C_Wait();
	I2C_Stop();
	result = I2C0_D;
	for(i=0;i<50;i++);
	//Pause(50);
	return result;
}

void I2C_ReadMultiRegisters(unsigned char SlaveAddress, unsigned char RegisterAddress, unsigned char n, unsigned char *r)
{
	char i;

	I2C_Start();
	I2C0_D = SlaveAddress << 1;									/* Send I2C device address with W/R bit = 0 */
	I2C_Wait();

	I2C0_D = RegisterAddress;										/* Send register address */
	I2C_Wait();

	I2C_RepeatedStart();

	I2C0_D = (SlaveAddress << 1) | 0x01;							/* Send I2C device address this time with W/R bit = 1 */
	I2C_Wait();

	I2C_EnterRxMode();
	I2C_EnableAck();

	i = I2C0_D;
	I2C_Wait();

	for(i=0; i<n-2; i++)
	{
	    *r = I2C0_D;
	    r++;
	    I2C_Wait();
	}

	I2C_DisableAck();
	*r = I2C0_D;
	r++;
	I2C_Wait();
	I2C_Stop();
	*r = I2C0_D;
	for(i=0;i<20;i++);
	//Pause(50);
}

/*void Pause(int number)
{
	int cnt;
	for(cnt=0; cnt<number; cnt++)
	{
		asm("nop");
	};
}*/

