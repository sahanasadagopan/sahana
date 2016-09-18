#include<stdio.h>
#include<stdint.h>
int8_t my_memmove(uint8_t *src,uint8_t *dst,uint32_t length);
void main()
{
	uint8_t i;
	int8_t a;
	uint32_t length=0;
	char data[100],dstdata[100];
	uint8_t *lptr=(uint8_t *)data;
	printf("\nEnter the data:");
	scanf("%[^\n]",data);
	while(*lptr!='\0')
	{
		length++;
		lptr++;
	}	
	*lptr=0;
	uint8_t *dptr=(uint8_t *)dstdata;
	printf("The length of the string is:%u\n",length);
	a=my_memmove(data,dstdata,length);
	if(a==1)
	{
	
		printf("The data at the destination is:");	
		while(*dptr!='\0')
		{
			printf("%c",*dptr);
			dptr++;
		}
	}
	else
	{
		printf("Move failed");
	}
	printf("\n");
}
	
int8_t my_memmove(uint8_t *src,uint8_t *dst,uint32_t length)
{	
	if(src!=NULL && dst!=NULL)
	{	while(src<src+length)
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
	*src=0;
	*dst=0;
	return 1;
	}
	else return 0;
	
	
}



