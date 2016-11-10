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
#include "spi.h"
#include "nrf24L0+.h"
#include <stdio.h>
#include <stdint.h>
#include "led.h"
#include "MKL25Z4.h"
void main()
{

		//UART0_init();
		spi0_init();
	//	NRF_CS_DISABLE();
	   // send_char('A');
//	spi_send('a');
while(1){
	uint8_t k[32]={0x35, 0x35, 0x35, 0x35};
	uint8_t *k_ptr;
	k_ptr=k;
	nrf_transmit_data(k_ptr);
	nrf_config_write();
	nrf_config_read();
	//nrf_flush_tx();
	//nrf_transmit_data();
	proffoz_nrf_status_read();
	//TEST_HIGH;
}
}

void nrf_config(){
	NORDIC_CONFIG_MASK_PWR_UP(1);

}

void nrf_write_register(unsigned char address){
     spi_send(0x00|NORDIC_RX_ADDR_P0_BASE);
}
void nrf_write_tx_address(unsigned char address){
	 spi_send(0X00|NORDIC_W_TX_PAYLOAD);
}

void nrf_read_register(unsigned char address){
	spi_send(0x00|address);

}

//void nrf_transmit_data(const void *buf, uint8_t len){

//}
void nrf_flush_tx(){
	TEST_LOW;
	spi_send(0xE2);
	TEST_HIGH;
}
void nrf_transmit_data(uint8_t *write){
	uint8_t ch=0;
	uint8_t l=32;
	//NRF_CS_DISABLE();
	NRF_CS_ENABLE();

	WAIT_SPTEF;
	SPI0_D=NORDIC_W_TX_PAYLOAD;
	WAIT_SPRF;
	ch=SPI0_D;
while (l>0)
{
	WAIT_SPTEF;
	SPI0_D= *write;
	WAIT_SPRF;
	ch= SPI0_D;
	l--;
	write++;
}
}
//void main(){

//}*/
void nrf_config_write() //write to the config register
{
//	while(WAIT_SPTEF);
	//SPI0_D = 0xFF;
	NRF_CS_DISABLE();
	NRF_CS_ENABLE();
	//TEST_HIGH;
	//TEST_LOW; //toggle CS


	nrf_write_register(NORDIC_CONFIG_BASE);

	spi_send(0x03);

}


void nrf_config_read() //read from the config register
{
	char c;
	spi0_init();
	//nrf_config();
    // NORDIC_CONFIG_PRIM_RX(0);
	TEST_LOW;
     nrf_read_register(NORDIC_CONFIG_BASE);
     c =spi_send(0XFF);
     TEST_HIGH;
     c=spi_send(0X03);
     while(!(SPI0_S & SPI_S_SPTEF_MASK)){
     }
     if (c==0x03){
    	 yellow();
     }
}
uint8_t proffoz_nrf_status_read() {
#define NRF_CS_ENABLE() (PTC_BASE_PTR->PCOR |= 1<<4)
#define NRF_CS_DISABLE() (PTC_BASE_PTR->PSOR |= 1<<4)
#define WAIT_SPTEF ( !(SPI_S_REG(SPI0) & SPI_S_SPTEF_MASK))
#define WAIT_SPRF ( !(SPI_S_REG(SPI0) & SPI_S_SPRF_MASK))
       uint8_t rx_ret = 0;

NRF_CS_DISABLE(); //creating edge for analyser triggering
                 //don't put into final code

       NRF_CS_ENABLE();                // Activate SPI
    while(WAIT_SPTEF);
       SPI_D_REG(SPI0) = 0xFF;
    while(WAIT_SPRF);
       rx_ret = SPI_D_REG(SPI0);

    NRF_CS_DISABLE();

       return(rx_ret);
}
