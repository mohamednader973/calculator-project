/*
 * Rechner.c
 *
 * Created: 9/16/2020 1:27:41 AM
 * Author : monad
 */ 

#include <avr/io.h>
#include "LCD.h"
#include "Keypad.h"
#include "DIO_INOUT.h"
void tostring(char str[], int num)
{
	int i, rem, len = 0, n;
	
	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
}

int Str2Int(char arr[]){
	int s = 1;
	int i = -1;
	int res = 0;

	if (arr[0] == '-') {
		s = -1;
		i = 0;
	}

	while (arr[++i] != '\0') { //iterate until the array end
		res = res*10 + (arr[i] - '0'); //generating the integer according to read parsed numbers.
	}

	res = res*s;
	return res;
}



int main(void)
{
	Keypad_Init();
	LCD_Init();
    /* Replace with your application code */
	
    while (1) 
    {
		char number1[7],number2[7];
		unsigned char count =0;
		char op;
		int op1,op2;
		int result=0;
		while (1)
		{
		
		number1[count]=key_pressed();
		LCD_char(number1[count]);
		if(number1[count]=='+')
		{
		op='+';
		number1[count]='\0';
		break;	
		}
		else if(number1[count]=='-')
		{
			op='-';
			number1[count]='\0';
			break;
		}
		else if(number1[count]=='*')
		{
			op='*';
			number1[count]='\0';
			break;
		}
		else if(number1[count]=='/')
		{
			op='/';
			number1[count]='\0';
			break;
		}
		count++;
		}
		count=0;
				while(1){
					number2[count]= key_pressed();
					LCD_char(number2[count]);
					if(number2[count] == '='){
						number2[count] = '\0';
						break;
					}
					count++;
				}
				op1 = Str2Int(number1);
				op2 = Str2Int(number2);
				
				switch(op){
					case '+':
					result = op1 + op2;
					break;
					case '-':
					result = op1 - op2;
					break;
					case '/':
					result = op1 / op2;
					break;
					case '*':
					result = op1 * op2;
					break;
				}
				
				char Sresult[10];
				tostring(Sresult,result);
				LCD_String(Sresult);
				
				
				if(key_pressed() == '!'){
					LCD_Init();
				}
    }
}

