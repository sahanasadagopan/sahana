/*
 * log1.h
 *
 *  Created on: Dec 6, 2016
 *      Author: sahan
 */

#ifndef SOURCES_LOG1_H_
#define SOURCES_LOG1_H_
void LOG_0(uint8_t * data, uint32_t len);
void LOG_1(uint8_t * data, uint8_t len, uint32_t param, uint8_t param_size);
void LOG_2(uint8_t * data, uint8_t len, float param, uint8_t param_size);
void reverse(char *str, int len);
int my_itoa(char *str, int data, int d);
void my_ftoa(float data, char *str, int number_after_decimal);





#endif /* SOURCES_LOG1_H_ */
