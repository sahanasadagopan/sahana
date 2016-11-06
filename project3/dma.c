/*
 * dma.c
 *
 *  Created on: Nov 1, 2016
 *      Author: sasa2453
 */


#include "MKL25Z4.h"
#include <stdio.h>
#include "core_cmFunc.h"
#include "log.h"
uint8_t  c[5000],d[5000];
uint32_t  a=5000;
void dma_init(){
	//uint8_t *str,*dst;
// clock for DMA enabled
SIM_SCGC6 |= SIM_SCGC6_DMAMUX_MASK;
SIM_SCGC7 |= SIM_SCGC7_DMA_MASK ;
DMA_DCR0 = 0x00;

DMAMUX0->CHCFG[0]=0;

//configuring the DMA controller
DMA_SAR0 = DMA_SAR_SAR(c);//source pointer
DMA_DAR0 = DMA_DAR_DAR(d);//destination pointer
DMA_DSR_BCR0 |= DMA_DSR_BCR_BCR(a);//buffer size given as BCR value
DMA_DCR0= DMA_DCR_CS(0);//enabling continuous mode
DMA_DCR0 |= DMA_DCR_SINC_MASK|DMA_DCR_DINC_MASK ;//source and destination increment
DMA_DCR0 |= DMA_DCR_SSIZE(1)|DMA_DCR_DSIZE(1) ;//source and destination size
//DMA0->DMA[0].DCR=DMA_DCR_EINT_MASK|DMA_DCR_AA_MASK|DMA_DCR_SSIZE(0x00)|DMA_DCR_DSIZE(0x00);
//Selecting the channel
DMAMUX0_CHCFG0 |=0x039;
DMAMUX0_CHCFG0 |= DMAMUX_CHCFG_ENBL_MASK;
//__enable_irq();
//NVIC_EnableIRQ(DMA0_IRQn);
}




