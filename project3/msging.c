/*
 * msging.c
 *
 *  Created on: Nov 9, 2016
 *      Author: sahan
 */
#include "MKL25Z4.h"
#include "uart.h"
#include "led.h"
#include "msgst.h"
#include <stdio.h>
#include <string.h>
void message()
{
	int i;
	char packet[6];
		CI_Msg CI_Msg_t;
		for(i=0;i<8;i++)
		{
			while(!(UART0_S1 & UART_S1_RDRF_MASK));
			packet[i]=UART0_D;

		}


		CI_Msg_t.command=packet[0];
		CI_Msg_t.length=packet[1];
		CI_Msg_t.data[0]=packet[2];
		CI_Msg_t.data[1]=packet[3];
		CI_Msg_t.data[2]=packet[4];
		CI_Msg_t.checksum=packet[5];
		//CI_Msg_t.command=UART0_D;
		UART0_D=CI_Msg_t.command;
			while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 &UART_S1_TC_MASK));
				UART0_D=CI_Msg_t.length;
				for(int i=0;i<6;i++)
				{
				while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 &UART_S1_TC_MASK));
						UART0_D=CI_Msg_t.data[i];
						}
						//while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 &UART_S1_TC_MASK));
							//			UART0_D=CI_Msg_t.checksum;



}



