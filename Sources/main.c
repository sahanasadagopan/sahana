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

static int i = 0;

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
    	   Green();
        }
    	else k++;
   	}
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
