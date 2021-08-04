#include<reg52.h>
#include"Ò£¿ØÆ÷.h"
#include<Windows.h>
uchar send_data=0;
uchar receive_data=0;


void delay_ms(uint i)//ÑÓÊ±msº¯Êý
{
	uint x,y;
	for(x=0;x<i;x++)
		for(y=0;y<110;y++)
	{
		;
	}
}
void main()
{
	init();
	ET0=1;
	delay_ms(100);
	
	while(1)
	{
		matrixkeyscan(); 
	}
}
