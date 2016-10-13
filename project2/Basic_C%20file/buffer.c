/*
 * buffer.c
 *
 *  Created on: Oct 12, 2016
 *      Author: Divya Sampath
 */
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "log.h"
#include "Buffer.h"
enum bufferstates{additem,deleteitem,bufferfull,bufferempty};

uint8_t buff_full(circbuffer *cb)
{
        if(cb->num_elements==cb->size)
        {
                return 1;
        }
        else return 0;
}


void add_item(circbuffer *cb,uint8_t item)
{
	uint8_t buffcheck=buff_full(cb);
	if(buffcheck)
	{
		char s[]="Buffer is full, wrap around is done";
		Log0(s,strlen(s));
		cb->num_elements=0;
		cb->head=cb->buffer;
	}
		*cb->head=item;
		char s[]="Success";
		Log0(s,strlen(s));
		//printf("success");
		cb->head++;
		cb->num_elements++;
}

uint8_t buff_empty(circbuffer *cb)
{
	if(cb->num_elements==0)
	{
		return 1;
	}
	else return 0;
}

void del_item(circbuffer *cb)
{
	uint8_t buffcheck=buff_empty(cb);
	if(buffcheck)
	{
		char s[]="Buffer empty";
		Log0(s,strlen(s));
	}
	else
	{
		uint8_t item;
		item=*cb->tail;
		char s[]="\nDeleted item\n";
		Log0(s,strlen(s));
		cb->tail++;
		cb->num_elements--;
	}
}

uint8_t dataget(circbuffer *cb)
{
	cb->head--;
	return (*cb->head);
	cb->head++;

}
int Buffer_init()
{
	d = (char *)malloc(15);
	return d;
}
/*void release(char *s)
{
	free(s);
}*/






