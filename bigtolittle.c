#include<stdio.h>
#include<stdint.h>
uint32_t big_to_little(uint32_t data);

void main()
{
	uint32_t data;
	printf("Enter a 32 bit data:");
	scanf("%x",&data);
	uint32_t little=big_to_little(data);	
	printf("little:%x\n",little);
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
	
