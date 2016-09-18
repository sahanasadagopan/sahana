#include "memory.h"
#include <stdint.h>
#include<stdio.h>
int8_t my_memmove(uint8_t *src,uint8_t *dst,uint32_t length)
{	
	if(src!=NULL && dst!=NULL)
	{
		while(src<src+length)
		{
			if(dst>src && dst<src+length)
			{
				dst=dst+length;
				src=src+length;
				*dst=*src+length;
				dst--;
				src--;
			}
			else
			{
				*dst=*src;
				src++;
				dst++;
				length--;
			}
		}
	return 1;
	}
	else return 0;
	
	
}

	
int8_t my_memzero(uint8_t *src,uint32_t length)
{		
	if(src!=NULL)
	{	
		while(src<src+length)
		{
			*src=0;
			src++;	
			length--;							
		}
	*src=0;	
	return 1;
	}
	else 
	{
		*src=0;		
		return 0;
	}
}


int8_t my_reverse(uint8_t *src,uint32_t length)
{
	uint8_t *last=src+length;;
	uint8_t temp;

	if(src!=NULL)
	{	
		while(src<last)
		{
			temp=*src;
			*src=*last;
			*last=temp;
			src++;
			last--;
		}
	return 1;
	}
	else 
	{
		*src=0;
		return 0;
	}
}
