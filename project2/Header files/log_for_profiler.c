
#include "log_for_profiler.h"
#include "uart.h"
//#include "Buffer.h"
#include "MKL25Z4.h"
#include "math.h"
#include <string.h>
#include <stdio.h>

int i=0;
void Log2(char *p,int len,char *m,int leng)
{
	int k;
	uart0_init (SystemCoreClock,38400);

	while(i<len)
	{
		while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 &UART_S1_TC_MASK));
	UART0_D=*(p+i);
	i++;
	//for(k=0;k<700;k++);
	}
	i=0;
	while(i<leng){
		while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 &UART_S1_TC_MASK));
//		intToStr(len,m,3);
	UART0_D=*(m+i);
	i++;
	}
}
/*void Log1(char *r,int len,uint32_t *parm,int lent)
{


	int i=0;
	Log0(r,len);
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
