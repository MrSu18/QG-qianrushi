#include <reg52.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
void delayms(uint);
uchar led;
int main()
{
	int i;
	led=0xfe;//赋初值11111110
	for(i=0;i<8;i++)
	{
		P0=led; //等于先点亮了第一个LED
		delayms(500);
		led=_crol_(led,1);  //500ms之后把aa循环左移一位也就是变成了11111101
	}																			  
	P0=0x00;
	delayms(500);
	for(i=0;i<4;i++)
	{
		P0=0x55;
		delayms(500);
		P0=_crol_(P0,1);
		delayms(500);
	}
	P0=0xff;
	while(1);
}
void delayms(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);//执行空循环110次相当于1ms
}
