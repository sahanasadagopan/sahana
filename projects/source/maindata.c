#include<stdio.h>
#include<stdint.h>
#include "data.h"
void main()
{
        
        printf("ASCII to Integer Conversion and dump memory() testing\n");
        
        
	char data[100];
	int32_t res;
	printf("Enter a string for ASCII to integer conversion and dump memory():");
	scanf("%[^\n]",data);
	printf("\nInteger output\n");
	res=my_atoi(data);	
	if(res==0)
	{
		printf("\nInvalid input!letters and special characters except '-' not allowed for ASCII to Integer conversion\n");
	}
	else
	{
		printf("\nSuccess\n");
	}		
	uint32_t length=0;
	uint8_t *lptr=(uint8_t *)data;
	while(*lptr!='\0')
	{
		length++;
		lptr++;
	}	
	*lptr=0;
	printf("\nDump memory output\n");
	dump_memory(data,length);	
	

        printf("\nEndianess Testing\n");


        uint32_t data_endian;
        printf("Enter a 32 bit data for endianness:");
        scanf("%x",&data_endian);
        uint32_t big,little;
        uint32_t testdata=00000001;
        uint8_t *tstptr=(uint8_t *)&testdata;
        if(*(tstptr)==1)
        {
	        big=little_to_big(data_endian);	
        	printf("big endian format of data:%x\n",big);	
        }

        else
        {
                little=big_to_little(data_endian);
                printf("little endian format of data:%x\n",little);	
        }
   
        printf("Integer to ASCII Conversion and dump memory() testing\n");
	
	
	int32_t data_itoa,base;
	char output[100];
	printf("\nEnter the data to convert from integer to ASCII:");
	scanf("%d",&data_itoa);
	printf("Enter the base required:");
	scanf("%d",&base);
	printf("base %d:%s\n",base,my_itoa(output,data_itoa,base));
}
