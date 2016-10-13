/*
 * buffer.h
 *
 *  Created on: Oct 12, 2016
 *      Author: sahan
 */
#ifndef SOURCES_BUFFER_H_
#define SOURCES_BUFFER_H_

#include<stdint.h>
typedef struct
{
        uint8_t *head;
        uint8_t *tail;
	    uint8_t *buffer;
        uint8_t size;
        uint8_t num_elements;
}circbuffer;
char *d;
uint8_t buff_full(circbuffer *cb);
void add_item(circbuffer *cb,uint8_t item);
uint8_t buff_empty(circbuffer *cb);
void del_item(circbuffer *cb);
uint8_t dataget(circbuffer *cb);
int Buffer_init();
void release(char *s);



#endif /* SOURCES_BUFFER_H_ */


