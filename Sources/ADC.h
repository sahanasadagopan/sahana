/*
 * ADC.h
 *
 *  Created on: Nov 29, 2016
 *      Author: sahan
 */

#ifndef SOURCES_ADC_H_
#define SOURCES_ADC_H_
void adc_init(void);
unsigned short adc_read();
int adc_calibrate();
#endif /* SOURCES_ADC_H_ */
