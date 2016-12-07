/*
 * log1.c
 *
 *  Created on: Dec 6, 2016
 *      Author: sahan
 */

#include "uart.h"
#include  "stdio.h"
#include "string.h"
#include "math.h"
#include "MKL25Z4.h"

void LOG_0(uint8_t * data, uint32_t len)
{
	uart0_init (SystemCoreClock,38400);
	for (int i=0;i<len;i++)
	{
		//Wait until TX buffer is full or transmission complete flag is set
		while(!(UART0->S1 & UART_S1_TDRE_MASK) && !(UART0->S1 &UART_S1_TC_MASK));
	    UART0_D = *data;
	    data++;				//point to next character
	}



}

void LOG_1(uint8_t * data, uint8_t len, uint32_t param, uint8_t param_size)
{

LOG_0(data,len);
char string[20];
//my_itoa1(string,param,0);
int p_size=strlen(string);
LOG_0(string,p_size);

}
void LOG_2(uint8_t * data, uint8_t len, float param, int param_size)
{

	LOG_0(data,len);
	char string[32];
//my_ftoa1(param,string,20);
	LOG_0(string,param_size);
}


// reverse string after itoa
void reverse(char *str, int len)
{
    int i=0, j=len-1, temp;
    while (i<j)
    {
        temp = *(str+i);
        *(str+i) = *(str+j);
        *(str+j) = temp;
        i++; j--;
    }
}

// Converts integer to ascii
int8_t* my_itoa1(int8_t *str, uint32_t data, int d)
{
    int i = 0,count=0;
    if(data<0)
    {
        count++;
        data=-data;
    }
    if(data=0)
    {
    	*(str+i) = '0';
    }
    while (data>0)
    {
        *(str+i++) = (data%10) + '0';
        data = data/10;
    }

    // If number of digits required is more, then
    // add 0s at the beginning
    reverse(str, i);
    *(str+i) = '\0';
    return str;
}

// Converts a floating point number to string.
void my_ftoa1(float data, char *str, int number_after_decimal)
{
    // Extract integer part
    int before_decimal = (int)data;

    float after_decimal;
    // Extract floating part
    if (data<0)
	 after_decimal= (float)before_decimal-data;

    else
    	after_decimal = data-(float)before_decimal;

    // convert integer part to string
    int i = my_itoa1(str,before_decimal, 0);

    // check for numbers after point
    if (number_after_decimal != 0)
    {
        *(str+i) = '.';  // add dot

        // Get the value of fraction part
        after_decimal = after_decimal * pow(10, number_after_decimal);

        my_itoa1(str+i+1,(int)after_decimal, number_after_decimal);
    }
}



