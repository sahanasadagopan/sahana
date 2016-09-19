#include<stdio.h>
#include<stdint.h>
uint32_t little_to_big(uint32_t data);
//little endian machine
void main()
{
	uint32_t data;
	printf("Enter a 32 bit data:");
	scanf("%x",&data);
	uint32_t big;
	uint32_t testdata=00000001;
	uint8_t *tstptr=(uint8_t *)&testdata;
	if(*(tstptr)==1)
	{
		big=little_to_big(data);	
		printf("1.big:%x\n",big);
	}
	else
	{
		printf("2.big:%x\n",data);
	}
		
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
	
