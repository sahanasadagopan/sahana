/*
 * main.c
 *
 *  Created on: Nov 4, 2016
 *      Author: sahan
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
	   // send_char('A');
//	spi_send('a');
while(1){
	nrf_config_write();
	nrf_config_read();
	proffoz_nrf_status_read();
}
}

void nrf_config(){
	NORDIC_CONFIG_MASK_PWR_UP(1);
}

void nrf_write_register(unsigned char address){
     spi_send(0x00|NORDIC_RX_ADDR_P0_BASE);
}


void nrf_read_register(unsigned char address){
	spi_send(0x00|address);

}

void nrf_transmit_data(const void *buf, uint8_t len){

}
void flush_tx(){

}
void nrf_set_tx_address(){

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
    	 red();
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





