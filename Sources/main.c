/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "MKL25Z4.h"
#include "tsi_led.h"
#include "adc.h"
#include "log.h"
#include "log1.h"
#include "string.h"
#include "I2C.h"
#include "acc.h"
static int i = 0;


unsigned char AccData[6];
char Data;
char Xoffset, Yoffset, Zoffset;
short Xout_14_bit, Yout_14_bit, Zout_14_bit;
int Xout_g, Yout_g, Zout_g;
int x;




void TSI_init()
{
	SIM_SCGC5 |= SIM_SCGC5_TSI_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;

	TSI0_GENCS|=TSI_GENCS_MODE(0);
	TSI0_GENCS|=TSI_GENCS_REFCHRG(2);//2uA discharge
	TSI0_GENCS|=TSI_GENCS_DVOLT(0);//POWER RAIL:1.03V
	TSI0_GENCS|=TSI_GENCS_EXTCHRG(7);//64uA
	TSI0_GENCS|=TSI_GENCS_PS(2);//PRESCALER DIVIDE BY 4
	TSI0_GENCS|=TSI_GENCS_NSCN(15);//16 SCANS
	TSI0_GENCS|=TSI_GENCS_STPE_MASK;
	TSI0_GENCS|= TSI_GENCS_TSIEN_MASK;
	//PORTB_PCR18=PORT_PCR_MUX(0);//SELECT CHANNEL 11
	//PORTB_PCR19=PORT_PCR_MUX(0);//SELECT CHANNEL 12
	PORTB_PCR16 = PORT_PCR_MUX(0);      // PTB16 as touch channel 9
	PORTB_PCR17 = PORT_PCR_MUX(0);      // PTB17 as touch channel 10
}

void TSI_Start(int CH_IP)
{
	TSI0_DATA|=TSI_DATA_TSICH(CH_IP);
	TSI0_DATA|=TSI_DATA_SWTS_MASK;
}

inline static uint16_t TSI_Stop_check()
{
	TSI0_GENCS |= TSI_GENCS_EOSF_MASK;
	return TSI0_DATA & TSI_DATA_TSICNT_MASK;
}

int main(void)
{


    TSI_init();
    uint16_t count;
    uint16_t k=0;
    while(1)
    {
    	//TSI_Start(11);
    	TSI_Start(9);
    	while(!(TSI0_GENCS & TSI_GENCS_EOSF_MASK));
    	count = TSI_Stop_check();
    	count = count;
    	if(count>0x29)
    	{
    		int i;
    			Data = 0;
    		    clock_Init();
    			I2C0_F  = 0x14; 						// SDA hold time = 2.125us, SCL start hold time = 4.25us, SCL stop hold time = 5.125us *
    			I2C0_C1 = I2C_C1_IICEN_MASK;    		// Enable I2C0 module
    			Accelerometer_Init();
    		  	Calibrate();

    				//if (Data)		// new set of data ready
    				//{
    					Data = 0;

    					I2C_ReadMultiRegisters(MMA845x_I2C_ADDRESS, OUT_Y_MSB_REG, 6, AccData);		// Read data output registers 0x01-0x06

    					Xout_14_bit = ((AccData[0]<<8 | AccData[1])) >> 4;		// Compute 14-bit X-axis output value
    					Yout_14_bit = ((AccData[2]<<8 | AccData[3])) >> 4;		// Compute 14-bit Y-axis output value
    					Zout_14_bit = ((AccData[4]<<8 | AccData[5])) >> 4;		// Compute 14-bit Z-axis output value

    					Xout_g = (Xout_14_bit) / SENSITIVITY_2G;		// Compute X-axis output value in g's
    					Yout_g = (Yout_14_bit) / SENSITIVITY_2G;		// Compute Y-axis output value in g's
    					Zout_g = (Zout_14_bit) / SENSITIVITY_2G;		// Compute Z-axis output value in g's
    		//for(i=0;i<10;i++);

    				//}
    					int j=0;
    				char str[]="\n\rCoordinates:";
    				int l=strlen(str);
    				LOG(str,l);
    				if(Xout_g==0)
    				{
    					LOG("0",1);
						if (Yout_g==0 && Zout_g==0 )
						{
							LOG("0",1);
							LOG("0",1);
						}
						else if(Yout_g!=0 && Zout_g==0 )
						{
							LOG3(Yout_g,1);
							LOG("0",1);

						}
						else if(Yout_g==0 && Zout_g!=0 )
						{
							LOG("0",1);
							LOG3(Zout_g,1);
						}
						else
						{
							LOG3(Yout_g,1);
							LOG3(Zout_g,1);
						}
    				}
						else if(Xout_g!=0)
						{
	    					LOG3(Xout_g,1);
							if (Yout_g==0 && Zout_g==0 )
							{
								LOG("0",1);
								LOG("0",1);
							}
							else if(Yout_g!=0 && Zout_g==0 )
							{
								LOG3(Yout_g,1);
								LOG("0",1);
							}
							else if(Yout_g==0 && Zout_g!=0 )
							{
								LOG("0",1);
								LOG3(Zout_g,1);
							}
							else
							{
								LOG3(Yout_g,1);
								LOG3(Zout_g,1);
							}
						}
  		  		    		int temp_1,temp_2,temp_3;
  		  		    			uint16_t temp;
  		  		    			adc_init();
  		  		    			float temperature, temp1;
  		  		    			temp=adc_read();
  		  		    			temp1 = (int)((3.3 / 65536) * temp * 1000);
  		  		    			temperature = 25 - ((temp1 - 716) / 1620);
  		  		    				int  y;
  		  		    			//adc_calibrate();
  		  		    				char str1[]="\n\rThe temperature of the Board in Celsius:";
  		  		                    int k=strlen(str1);
  		  		    				LOG1(str1,k,temperature,32);
  		  		    	//	while(1){;}
//#endif
//#endif

    	}
   	}
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
