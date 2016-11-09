#include "MKL25Z4.h"
#include "uart.h"
#include "led.h"
#include "msgst.h"
#include <stdio.h>
#include <string.h>

char packet[7];
int i;
void uart0_init (int sysclk, int baud);
int main(void)
{
	/*CI_Msg CI_Msg_t;
	CI_Msg_t.checksum = CI_Msg_t.command ^ CI_Msg_t.length ^ CI_Msg_t.data;*/
	uart0_init(SystemCoreClock,38400);

}
void UART0_IRQHandler()
{
	CI_Msg CI_Msg_t;
	/*for(i=0;i<8;i++)
	{
		while(!(UART0_S1 & UART_S1_RDRF_MASK));
		packet[i]=UART0_D;

	}


	CI_Msg_t.command=packet[0];
	CI_Msg_t.length=packet[1];
	CI_Msg_t.data[0]=packet[2];
	CI_Msg_t.data[1]=packet[3];
	CI_Msg_t.data[2]=packet[4];
	CI_Msg_t.checksum=packet[5];
	//CI_Msg_t.command=UART0_D;
	 if(CI_Msg_t.command == '1')
		red();
	 if(CI_Msg_t.command == '2')
		 Blue();
	 if(CI_Msg_t.command == '3')
		 Green();
	 if(CI_Msg_t.command == '4')
		 yellow();
	 if(CI_Msg_t.command == '5')
		 cyan();
	 if(CI_Msg_t.command == '6')
		 voilet();
	 if(CI_Msg_t.command == '7')
		 off();*/
	 //data value
	for(i=0;i<maxdatasize;i++)
	{
		while(!(UART0_S1 & UART_S1_RDRF_MASK));
		CI_Msg_t.data[i]=UART0_D;
	}
	while(!(UART0_S1 & UART_S1_RDRF_MASK));
	CI_Msg_t.inten=UART0_D;
		 if(CI_Msg_t.data[0]=='r' && CI_Msg_t.data[1]=='e' && CI_Msg_t.data[2]=='d')
	     {
     	     CI_Msg_t.command ='1';
		     CI_Msg_t.length=3;
		     CI_Msg_t.checksum=65;
		     CI_Msg_t.data[3]=CI_Msg_t.data[4]=CI_Msg_t.data[5]=CI_Msg_t.data[6]=CI_Msg_t.data[7]=CI_Msg_t.data[8]=0;
		 }
		 if(CI_Msg_t.data[0]=='b' && CI_Msg_t.data[1]=='l' && CI_Msg_t.data[2]=='u' && CI_Msg_t.data[3]=='e')
		 {
			 CI_Msg_t.command ='2';
			 CI_Msg_t.length=4;
			 CI_Msg_t.checksum=40;
			 CI_Msg_t.data[4]=CI_Msg_t.data[5]=CI_Msg_t.data[6]=CI_Msg_t.data[7]=CI_Msg_t.data[8]=0;
		 }
		 if(CI_Msg_t.data[0]=='g' && CI_Msg_t.data[1]=='r' && CI_Msg_t.data[2]=='e' && CI_Msg_t.data[3]=='e' && CI_Msg_t.data[4]=='n')
		 {
		     CI_Msg_t.command ='3';
		     CI_Msg_t.length=5;
		     CI_Msg_t.checksum=77;
		     CI_Msg_t.data[5]=CI_Msg_t.data[6]=CI_Msg_t.data[7]=CI_Msg_t.data[8]=0;
		 }
		 if(CI_Msg_t.data[0]=='y' && CI_Msg_t.data[1]=='e' && CI_Msg_t.data[2]=='l' && CI_Msg_t.data[3]=='l' && CI_Msg_t.data[4]=='o' && CI_Msg_t.data[5]=='w')
		 {
		     CI_Msg_t.command ='4';
		     CI_Msg_t.length=6;
		     CI_Msg_t.checksum=54;
		     CI_Msg_t.data[6]=CI_Msg_t.data[7]=CI_Msg_t.data[8]=0;
		 }
		 if(CI_Msg_t.data[0]=='c' && CI_Msg_t.data[1]=='y' && CI_Msg_t.data[2]=='a' && CI_Msg_t.data[3]=='n')
		 {
			 CI_Msg_t.command ='5';
		     CI_Msg_t.length=4;
		     CI_Msg_t.checksum=36;
		     CI_Msg_t.data[4]=CI_Msg_t.data[5]=CI_Msg_t.data[6]=CI_Msg_t.data[7]=CI_Msg_t.data[8]=0;
 		 }
		 if(CI_Msg_t.data[0]=='v' && CI_Msg_t.data[1]=='i' && CI_Msg_t.data[2]=='o' && CI_Msg_t.data[3]=='l' && CI_Msg_t.data[4]=='e' && CI_Msg_t.data[5]=='t')
		 {
		     CI_Msg_t.command ='6';
		     CI_Msg_t.length=6;
		     CI_Msg_t.checksum=71;
		     CI_Msg_t.data[6]=CI_Msg_t.data[7]=CI_Msg_t.data[8]=0;
 		 }
		 if(CI_Msg_t.data[0]=='w' && CI_Msg_t.data[1]=='h' && CI_Msg_t.data[2]=='i' && CI_Msg_t.data[3]=='t' && CI_Msg_t.data[4]=='e')
		 {
		 	 CI_Msg_t.command ='7';
		     CI_Msg_t.length=5;
		     CI_Msg_t.checksum=101;
		     CI_Msg_t.data[4]=CI_Msg_t.data[5]=CI_Msg_t.data[6]=CI_Msg_t.data[7]=CI_Msg_t.data[8]=0;
		 }
		 if(CI_Msg_t.data[0]=='i' && CI_Msg_t.data[1]=='n' && CI_Msg_t.data[2]=='t' && CI_Msg_t.data[3]=='e' && CI_Msg_t.data[4]=='n' && CI_Msg_t.data[5]=='s'&& CI_Msg_t.data[6]=='i' && CI_Msg_t.data[7]=='t' && CI_Msg_t.data[8]=='y')
		 {
		     CI_Msg_t.command ='8';
 		     CI_Msg_t.length=9;
 		     CI_Msg_t.checksum=26;
 		 }
		 uint8_t cz=(CI_Msg_t.data[0]^CI_Msg_t.command^CI_Msg_t.length^CI_Msg_t.data[1]^CI_Msg_t.data[2]^CI_Msg_t.data[3]^CI_Msg_t.data[4]^CI_Msg_t.data[5]^CI_Msg_t.data[6]^CI_Msg_t.data[7]^CI_Msg_t.data[8]);
		 if(cz==CI_Msg_t.checksum)
		 {
		                 if(CI_Msg_t.command == '1')
		                 {	red();
		                 intensity(CI_Msg_t.inten);
		                 }
				 		 if(CI_Msg_t.command == '2')
				 			 Blue();
				 		 if(CI_Msg_t.command == '3')
				 			 Green();
				 		 if(CI_Msg_t.command == '4')
				 			 yellow();
				 		 if(CI_Msg_t.command == '5')
				 			 cyan();
				 		 if(CI_Msg_t.command == '6')
				 			 voilet();
				 		 if(CI_Msg_t.command == '7')
				 			 off();
				 		 if(CI_Msg_t.command == '8')
				 			 intensity(CI_Msg_t.inten);


		 }
}
