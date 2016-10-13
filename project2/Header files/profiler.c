/*
 * Copyright (c) 2015, Freescale Semiconductor,  * All rights reserved.
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
#include "log.h"
#include <string.h>
#include "uart.h"
//#include "buffer.h"
#include <stdio.h>
#include <math.h>
uint8_t overflow_count=0;

void timer()
{
//MCG_BASE_PTR->C1 = MCG_C1_IREFS_MASK | MCG_C1_IRCLKEN_MASK;
//MCG_BASE_PTR->C2 = MCG_C2_IRCS_MASK; //Select fast internal clock
SIM_SCGC6 |= SIM_SCGC6_TPM1_MASK; //Enable TPM1 clock
SIM_SOPT2 |= SIM_SOPT2_TPMSRC(1);
TPM1->SC =0x00;

TPM1_SC|=TPM_SC_PS(0);
TPM1_MOD = 65535;

NVIC_EnableIRQ(TPM1_IRQn);
__enable_irq();
TPM1->SC = TPM_SC_TOIE_MASK;

}

void TPM1_IRQ(){
	while (!(TPM1_SC & TPM_SC_TOF_MASK));
	overflow_count++;
	TPM1_SC&=~(TPM1_SC & TPM_SC_TOF_MASK);
}

void start()
{
	//timer();
	TPM1_SC |= TPM_SC_CMOD(1);
}
void end()
{
	int n=0;
	char s[]="timing:";
	char o[4];
	int timing=0;
	TPM1_SC = TPM_SC_CMOD(0);
	//cycle=TPM1_CNT;
	timing=TPM1_CNT/21;
	if(overflow_count !=0){
	timing=timing+((TPM1_MOD/21)*overflow_count);
	overflow_count=0;
	}
	    int i = 0;
	    char str[1000];
	    while (timing)
	    {
	        str[i++] = (timing%10) + '0';
	        timing= timing/10;
	    }

	    int j=i-1, temp;
	    i=0;
	        while (i<j)
	        {
	            temp = str[i];
	            str[i] = str[j];
	            str[j] = temp;
	            i++; j--;
	        }
	        str[i] = '\0';
	        i++;
	    	//for(n=0;n<700;n++);
	Log2(s,6,str,strlen(str));
}

void main()
{
	uart0_init(SystemCoreClock,38400);
	int i=0;
uint8_t a[10],b[10];
timer();
start();
memmove(a,b,10);
//for(i=0;i<100;i++);
end();
//timing=0;
}
