#include<stdio.h>
#include<stdint.h>
int8_t my_reverse(uint8_t *src,uint32_t length);
int main()
{
	uint8_t i;
	int8_t a;
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
	a=my_reverse(data,length);	
	uint8_t *dptr=(uint8_t *)data;
	if(a==1)
	{
	
		printf("\nThe reversed data is:");	
		for(i=0;i<=length;i++)
		{
			printf("%c",*(dptr+i));
		} 
	}
	else
	{
		printf("Move failed");
	}
	printf("\n");

}

int8_t my_reverse(uint8_t *src,uint32_t length)
{
	uint8_t *last=src+length;;
	uint8_t temp;

	if(src!=NULL)
	{	
		while(src<last)
		{
			temp=*src;
			*src=*last;
			*last=temp;
			src++;
			last--;
		}
	return 1;
	}
	else 
	{
		*src=0;
		return 0;
	}
}
	

