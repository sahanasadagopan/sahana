#include<stdio.h>
#include"hw1.h"
char reverse(char*str,int length)
{
char temp;
int len;
if(length<=0)
{
return (1);
}
else
{

len = length;
while(len/2)
{
temp=*str;
*str=*(str + len);
*(str + len)=temp;
str++;
len = len-2;
}
return (0);
}
}

int main()
{
int i,length;
char arr[100];
int result;
printf("elements\n");
scanf("%[^\t\n]s",arr);
printf("Enter the length of the string");
scanf("%d",&length);

result = reverse(arr,length);
if(result == 1) 
{
printf("the length entered by the user is negative");
}
else
{
printf("\n The reverse order\n");

for (i=0;i<=length;i++)
{
printf(" %c\n",arr[i]);
}
}
return(1);
}
