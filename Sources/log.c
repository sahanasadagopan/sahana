/*
 * log.c
 *
 *  Created on: Dec 5, 2016
 *      Author: sahan
 */
#include "log.h"
#include "uart.h"
#include "string.h"
//#include "Buffer.h"
#include "MKL25Z4.h"
//#include "itoa.h"
//#include "ftoa.h"



void LOG(char *s,int l)
{
	 int i = 0;
	int j=0;
	uart0_init (SystemCoreClock,38400);
		while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 &UART_S1_TC_MASK));
		while(i<l)
		{
		UART0_D=*(s+i);
		i++;
		for(int k=0;k<700;k++);
		}
		i=0;
}
void LOG1(char *p,int l,int param,int data_type_size)
{
	//uart0_init(SystemCoreClock,38400);
	//while(!(UART0_S1 & UART_S1_RDRF_MASK));
//for(int i=0;i<1000;i++);
char par[l];
my_itoa(par,param ,10);
char* str=strcat(p,par);
LOG(str,strlen(str));
}
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
/*void UART0_IRQHandler(){
	while(j<3)
	{
while(!(UART0_S1 & UART_S1_RDRF_MASK));
		*(s1+j)=UART0_D;
		//for(int i=0;i<700;i++);
j++;
	//__disable_irq();
		//for(int j=0;j<700;j++);
}*/

//}




