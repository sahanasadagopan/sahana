/*
 * spi.c
 *
 *  Created on: Nov 4, 2016
 *      Author: sahan
 */
#include "MKL25Z4.h"
#include "core_cmFunc.h"
#include <stdio.h>
//#include "dma.h"
//#include "uart.h"
#include "spi.h"
//#include "buffer.h"

	/*void main()
	{
		spi0_init();*/
		/*while(1)
		{
	spi_send('a');
	SPI0_D = 'a';
	//out_char ('a');
	}*/
//}

/*void SPI0_IRQHandler(){
	char m='a';
	while (!(SPI_S_SPTEF_MASK & SPI0_S))
	{

		SPI0_D = m;
	}

}*/

void spi0_init()

{
	int baud_divisor;
	//SPI0_C1|=~(SPI_C1_SPE_MASK);//disable spi
	SIM_SCGC4 |= SIM_SCGC4_SPI0_MASK; // enabling the clock and the gate for spi
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK; // giving clock and gate to the port


	//GPIOC_PSOR |=GPIO_PDOR_PDO(0x10);
	//GPIOC_PDDR |= GPIO_PDDR_PDD(0x10);
	PORTC_PCR4 = PORT_PCR_MUX(1); // PCS0
	PORTC_PCR5 = PORT_PCR_MUX(2); //alt 2
	PORTC_PCR6 = PORT_PCR_MUX(2); //MOSI
	PORTC_PCR7 = PORT_PCR_MUX(2);
	PTC_BASE_PTR->PDDR |= 1<<4;

	SPI0_C1 = 0x50;
	//SPI0_C1|=SPI_C1_MSTR_MASK;//Set master mode and clock polarity and phase
	//SPI0_C1|= ~(SPI_C1_CPOL_MASK );//clock polarity
	//BAUD  RATE CALCULATION
	//baud divisor=(SPI_BR_SPPR(1))*2^(SPI_BR_SPR+1);
	//baud_divisor= bus_clock/baud;
	//SPI0_BR|=SPI_BR_SPPR(1)|SPI_BR_SPR(0) ;
	//MISO AND MOSI
	//SPI0_C2 |= SPI_C2_SPC0(0);//|SPI_C2_MODFEN(0);
	//SPI0_C1|=(SPI_C1_SPE_MASK); //enable spi
	//__enable_irq();
    //NVIC_EnableIRQ(SPI0_IRQn);
	SPI0_BR = 0x03;
}

unsigned char spi_send(char m)
{
	uint8_t ch =0;

	 while(WAIT_SPTEF);
	SPI0_D=m;

	 while(WAIT_SPRF);
	 ch=SPI0_D;

	 while(WAIT_SPTEF);
	SPI0_D=0xFF;

	 while(WAIT_SPRF);
	 ch=SPI0_D;
 // m=SPI0_D;
  return m;
}



