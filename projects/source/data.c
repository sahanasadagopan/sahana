#include "data.h"
#include <stdint.h>
#include<stdio.h>
int8_t* my_itoa(int8_t *str,int32_t data,int32_t base)
{
	int32_t rem;
	int num=data;
	int8_t i=0;
	int8_t beg,end;
	char temp;
	if(data<0)
	{data=-data;}
	else {data=data;}			
	while(data!=0)
	{
		rem=data%base;
		if(rem>9)
		{	
			*(str+i)=(rem-10)+'a';
		}
		else
		{
		*(str+i)=rem+'0';
		}
		data=data/base;
		i++;
	}
	
	if(base==10 && num<0)
	{
		*(str+i)='-';
		i++;
	}
		
	//to reverse the string
	for(beg=0,end=i-1;beg<end;beg++,end--)
	{
		temp=*(str+beg);
		*(str+beg)=*(str+end);
		*(str+end)=temp;
	}
	*(str+i)='\0';
	i++;
	return str;
}


int32_t my_atoi(int8_t *str)
{
	if(str!=NULL)
	{
		while(*str!='\0')
		{
		if(*str>='0' && *str<='9' || *str=='-')
		{
			printf("%d",*str);
		}
		else return 0;
		str++;	
	}
	}
	*str=0;
}


void dump_memory(uint8_t *start,uint32_t length)
{

	uint8_t i;
	printf("\n");
	for(i=0;i<length;i++)
	{
		printf("%x",*(start+i));	
	}
	printf("\n");
}



uint32_t big_to_little(uint32_t data)
{
	uint32_t little;
	uint8_t *bptr=(uint8_t *)&data;
	uint8_t *lptr=(uint8_t *)&little;
	*lptr=*(bptr+3);
	*(lptr+1)=*(bptr+2);
	*(lptr+2)=*(bptr+1);
	*(lptr+3)=*(bptr);
	return little;
}
	



uint32_t little_to_big(uint32_t data)
{
	uint32_t big;
	uint8_t *lptr=(uint8_t *)&data;
	uint8_t *bptr=(uint8_t *)&big;
	*bptr=*(lptr+3);
	*(bptr+1)=*(lptr+2);
	*(bptr+2)=*(lptr+1);
	*(bptr+3)=*(lptr);
	return big;
}
	
