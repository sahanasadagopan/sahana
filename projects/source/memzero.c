#include<stdio.h>
#include<stdint.h>
int8_t my_memzero(uint8_t *src,uint32_t length);
void main()
{
	uint8_t i;
	int8_t a;
	uint32_t length=0;
	char data[100];
	uint8_t *lptr=(uint8_t *)data;
	printf("\nEnter the data:");
	scanf("%[^\n]",data);
	while(*lptr!='\0')
	{
		length++;
		lptr++;
	}	
	*lptr=0;
	//uint8_t *dptr=(uint8_t *)data;
	printf("The length of the string is:%u\n",length);
	a=my_memzero(data,length);
	if(a==1)
	{
	
		printf("The data at the destination is:");	
		/*while(*dptr!='\0')
		{
			printf("%c",*dptr);
			dptr++;
		}*/
		for(i=0;i<length;i++)
		{
			printf("%d",data[i]);
		}
	}
	else
	{
		printf("Move failed");
	}
	printf("\n");
}



	
int8_t my_memzero(uint8_t *src,uint32_t length)
{		
	if(src!=NULL)
	{	
		while(src<src+length)
		{
			*src=0;
			src++;	
			length--;							
		}
	*src=0;	
	return 1;
	}
	else 
	{
		*src=0;		
		return 0;
	}
}
