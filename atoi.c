#include<stdio.h>
#include<stdint.h>
int32_t my_atoi(int8_t *str);
void main()
{
	char data[100];
	int32_t res;
	printf("Enter a string:");
	scanf("%[^\n]",data);
	res=my_atoi(data);	
	if(res==0)
	{
		printf("\nInvalid input!letters and special characters except '-' not allowed\n");
	}
	else
	{
		printf("\nSuccess\n");
	}		
}


int32_t my_atoi(int8_t *str)
{
	if(str!=NULL)
	{
		while(*str!='\0')
		{
		if(*str>='0' && *str<='9' || *str=='-')
		{
			printf("%d",*str);
		}
		else return 0;
		str++;	
	}
	}
	*str=0;
}
	
