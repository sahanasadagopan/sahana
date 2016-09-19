/* Variables list:
   arr[32]: An array of 32 bytes(unsigned)
   i:varaible to access the array using pointers
   aptr_1: pointer to arr[0]
   aptr_2:pointer to arr[8]
   aptr_3:pointer to arr[16]
   data:initializing the data 31 and incrementing till 46
 */
 
 
#include<stdio.h>
#include<stdint.h>
#include "project_1.h"
void project_1_report()
{
   uint8_t arr[32];	
   uint8_t i=0;
   uint8_t *aptr_1=arr;
   uint8_t *aptr_2=&arr[8];
   uint8_t *aptr_3=&arr[16];
   uint8_t data=31;
   
   //to enter integers 31 to 46 for first 16 bytes of arr
   
   while(i<16)
   {
        *(aptr_1+i)=data;
	data++;
	i++;
   }
   
   //print the array formed
   
   my_memzero(aptr_3,16);
   printf("\nThe array formed: \n");
   i=0;
   while(i<32)
   {
        printf("%d\t",*(aptr_1+i));
	i++;
   }
   
   //print the shuffled array
   
   my_memmove(aptr_1,aptr_3,8);
   int8_t e=my_memmove(aptr_2,aptr_1,16);
   printf("\nThe final array after shuffling: \n");
   int8_t m=my_reverse(aptr_1,32);
   i=0;
   while(i<32)
   {
	printf("%d\t",*(aptr_1+i));
	i++;
   }
   printf("\n");
}


	


