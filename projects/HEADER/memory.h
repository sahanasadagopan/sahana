#ifndef _memory_H
#define _memory_H
#include<stdint.h>
int8_t my_memmove(uint8_t *src,uint8_t *dst,uint32_t length);
int8_t my_memzero(uint8_t *src,uint32_t length);
int8_t my_reverse(uint8_t *src,uint32_t length);
#endif
