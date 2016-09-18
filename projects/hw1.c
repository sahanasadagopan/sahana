#include<stdio.h>
#include "hw1.h"
char reverse_string(char* str, int length)
{
int i;
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



