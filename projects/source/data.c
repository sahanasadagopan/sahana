#include "data.h"
#include <stdint.h>
#include<stdio.h>

//Program to convert data from Integer to ASCII
/*      variable definitions
        str:pointer to output converted data
        data:input data
        base:conversion to 2,8,16 or 10
        num=temporary data storage
        i:to traverse the entered data byte by byte
        rem:remainder after extraction of a byte
        beg:indexing the start of converted data
        end:indexing the end of converted data*/
        
int8_t* my_itoa(int8_t *str,int32_t data,int32_t base)
{
   int32_t rem;
   int num=data;
   int8_t i=0;
   int8_t beg,end;
   char temp;
   if(data<0)
   {
      data=-data; //if data is negative, make it positive and execute the code
   }
   else 
   {
      data=data;
   }			
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
	
    if(base==10 && num<0) //if data is negative append a '-' to the converted data
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

//Program to convert data from ASCII to Integer
/*      variable definitions
        str:pointer to output converted data*/
        
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

//Program to convert data to hex equivalent
/*      variable definitions
        start:pointer to input
        length:length of input data*/
        
void dump_memory(uint8_t *start,uint32_t length)
{

	uint8_t i;
	printf("\n");
	for(i=0;i<length;i++)
	{
		printf("%x",*(start+i));//printing hex equivalent using %x
	}
	printf("\n");
}

//Program to convert data from big to little endian
/*      variable definitions
        data:input from user
        little:little endian output
        bptr:pointer to big endian input
        lptr:pointer to little endian output*/

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
	

//Program to convert data from little to big endian
/*      variable definitions
        data:input from user
        little:little endian input
        bptr:pointer to big endian output
        lptr:pointer to little endian input*/


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
	
