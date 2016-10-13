/*
 * log.h
 *
 *  Created on: Oct 12, 2016
 *      Author: sahan
 */
#ifndef SOURCES_LOG_FOR_PROFILER_H_
#define SOURCES_LOG_FOR_PROFILER_H_

#include <stdint.h>
//void Log0(char *p,int len);
void Log2(char *p,int len,char *m,int leng);
char intToStr(int x, char str[]);

//void Log1(char *r,uint32_t *parm,int len);
int8_t* my_itoa(int8_t *str,int32_t data,int32_t base);
void my_ftoa(float data, char *str, int number_after_decimal);




#endif /* SOURCES_LOG_FOR_PROFILER_H_ */
