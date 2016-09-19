#include<stdio.h>
#include<stdint.h>
int8_t* my_itoa(int8_t *str,int32_t data,int32_t base);
void main()
{
	int32_t data,base;
	char oput[100];
	printf("\nEnter the data:");
	scanf("%d",&data);
	printf("Enter the base required:");
	scanf("%d",&base);
	printf("base %d:%s\n",base,my_itoa(oput,data,base));
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
	data=-data;	
	}
	else {data=data;}		
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
	
	if(base==10 && num<0)
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

	
