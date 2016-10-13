

#include "log.h"
#include "uart.h"
#include "Buffer.h"
#include "MKL25Z4.h"
#include "math.h"
#include <string.h>
#include <stdio.h>

int i=0;
void Log0(char *p,int len)
{
	int k;
	uart0_init (SystemCoreClock,38400);
	while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 &UART_S1_TC_MASK));
	while(i<len)
	{
	UART0_D=*(p+i);
	i++;
	for(k=0;k<700;k++);
	}
	i=0;
}

/*void Log1(char *r,uint32_t *parm,int len)
{


	int i=0;
	Log0(*parm,len);
	int8_t str[100];
	int8_t s[10];
	my_itoa(s,*parm,10);
	while(*(r+i)!='/0')
	{
		*(str+i)=*(r+i);
		i++;
	}
	while(len>0)
	{
		*(str+i)=*s;
		i++;
		len--;
	}
	for(i=0;i<48;i++){
	//UART0_D=*(str+i);
	}
}*/

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


