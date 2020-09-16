/*
 * Keypad.c
 *
 * Created: 9/13/2020 1:39:13 AM
 *  Author: monad
 */ 
#include "Keypad.h"
#include "DIO_INOUT.h"
void Keypad_Init(void)
{
	DIO_init(DIO_PORTD,PIN_ZERO,INPUT);
	DIO_init(DIO_PORTD,PIN_ONE,INPUT);
	DIO_init(DIO_PORTD,PIN_TWO,INPUT);
	DIO_init(DIO_PORTD,PIN_THREE,INPUT);
	DIO_init(DIO_PORTD,PIN_FOUR,OUTPUT);
	DIO_init(DIO_PORTD,PIN_FIVE,OUTPUT);
	DIO_init(DIO_PORTD,PIN_SIX,OUTPUT);
	DIO_init(DIO_PORTD,PIN_SEVEN,OUTPUT);
}
void Check_Key (unsigned char* num,unsigned char* check)
{
	;
	DIO_WRITE_DATA(DIO_PORTD,0b11101111);
	if (GetBit(PIND_IO,PIN_ZERO)==0)
	{
		while(GetBit(PIND_IO,PIN_ZERO)==0);
		*num='7';
		*check=0;
	}
	else if (GetBit(PIND_IO,PIN_ONE)==0)
	{
		while(GetBit(PIND_IO,PIN_ONE)==0);
		*num='8';
		*check=0;
	}
	else if (GetBit(PIND_IO,PIN_TWO)==0)
	{
		while(GetBit(PIND_IO,PIN_TWO)==0);
		*num='9';
		*check=0;
	}
	else if (GetBit(PIND_IO,PIN_THREE)==0)
	{
		while(GetBit(PIND_IO,PIN_THREE)==0);
		*num='/';
		*check=0;
	}
	DIO_WRITE_DATA(DIO_PORTD,0b11011111);
	if (GetBit(PIND_IO,PIN_ZERO)==0)
	{
		while(GetBit(PIND_IO,PIN_ZERO)==0);
		*num='4';
		*check=0;
	}
	else if (GetBit(PIND_IO,PIN_ONE)==0)
	{
		while(GetBit(PIND_IO,PIN_ONE)==0);
		*num='5';
		*check=0;
	}
	else if (GetBit(PIND_IO,PIN_TWO)==0)
	{
		while(GetBit(PIND_IO,PIN_TWO)==0);
		*num='6';
		*check=0;
	}
	else if (GetBit(PIND_IO,PIN_THREE)==0)
	{
		while(GetBit(PIND_IO,PIN_THREE)==0);
		*num='*';
		*check=0;
	}
	DIO_WRITE_DATA(DIO_PORTD,0b10111111);
	if (GetBit(PIND_IO,PIN_ZERO)==0)
	{
		while(GetBit(PIND_IO,PIN_ZERO)==0);
		*num='1';
		*check=0;
	}
	else if (GetBit(PIND_IO,PIN_ONE)==0)
	{
		while(GetBit(PIND_IO,PIN_ONE)==0);
		*num='2';
		*check=0;
	}
	else if (GetBit(PIND_IO,PIN_TWO)==0)
	{
		while(GetBit(PIND_IO,PIN_TWO)==0);
		*num='3';
		*check=0;
	}
	else if (GetBit(PIND_IO,PIN_THREE)==0)
	{
		while(GetBit(PIND_IO,PIN_THREE)==0);
		*num='-';
		*check=0;
	}
	DIO_WRITE_DATA(DIO_PORTD,0b01111111);
	if (GetBit(PIND_IO,PIN_ZERO)==0)
	{
		while(GetBit(PIND_IO,PIN_ZERO)==0);
		*num='!';
		*check=0;
	}
	else if (GetBit(PIND_IO,PIN_ONE)==0)
	{
		while(GetBit(PIND_IO,PIN_ONE)==0);
		*num='0';
		*check=0;
	}
	else if (GetBit(PIND_IO,PIN_TWO)==0)
	{
		while(GetBit(PIND_IO,PIN_TWO)==0);
		*num='=';
		*check=0;
	}
	else if (GetBit(PIND_IO,PIN_THREE)==0)
	{
		while(GetBit(PIND_IO,PIN_THREE)==0);
		*num='+';
		*check=0;
	}
}
char key_pressed (void)
{
	unsigned char check,num;
	check=1;
	num=0;
	while(check)
	{
		Check_Key(&num,&check);
	}
	return num;
}