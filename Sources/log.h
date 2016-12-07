/*
 * log.h
 *
 *  Created on: Dec 5, 2016
 *      Author: sahan
 */

#ifndef SOURCES_LOG_H_
#define SOURCES_LOG_H_

#include <stdint.h>
void LOG(char *s,int l);
void LOG1(char *p,int l,int param,int data_type_size);
int8_t* my_itoa(int8_t *str,int32_t data,int32_t base);
void LOG3(int s,int l);
#endif /* SOURCES_LOG_H_ */
