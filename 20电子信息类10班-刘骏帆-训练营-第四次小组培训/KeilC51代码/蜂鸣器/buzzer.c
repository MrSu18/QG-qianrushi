#include <reg52.h>
#include <intrins.h>

sbit beep=P0^0;

void delay(int x);
void Beep();
void main()
{
	int x=5000;
	
	while(x--)
	{
		Beep();
		delay(10);
	}
	x=500;
	while(x--)
	{
		Beep();
		delay(70);
	}
	while(1);
}
void Beep()
{
	beep=~beep;//进行高低电平的转换，‘~’是取反符号
	//delay(10);
}
void delay(int x)
{
	int i,j;
	for(i=0;i<x;i++) ;
		//for(j=0;j<110;j++);
}