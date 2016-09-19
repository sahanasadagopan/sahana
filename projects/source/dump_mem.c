#include<stdio.h>
#include<stdint.h>
void dump_memory(uint8_t *start,uint32_t length);
int main()
{
	uint8_t i;
	uint32_t length=0;
	char data[100];
	printf("\nEnter the data:");
	scanf("%[^\n]",data);
	uint8_t *lptr=(uint8_t *)data;
	while(*lptr!='\0')
	{
		length++;
		lptr++;
	}	
	*lptr=0;
	printf("\nThe length of the entered data:%u",length);
	dump_memory(data,length);	
	
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
