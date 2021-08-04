#include <reg52.h>
#include "塔防游戏.h"

uchar flag2;
void delay_ms(uint i)//延时ms函数
{
	uint x,y;
	for(x=i;x>0;x--)
		for(y=110;y>0;y--);
}

void init_T0()//对定时器0进行初始化
{
	TH0=(65536-22936)/256;
	TL0=(65536-22936)%256;//装初值，定时为100ms

	ET0=1;//开启定时器0的中断 ；
	TR0=1;//启动定时器0；
}

void T0_time() interrupt 1
{
	TH0=(65536-22936)/256;
	TL0=(65536-22936)%256;
	flag++;
	flag2++;
	switch(guangqiachoose)
	{
	case 0:
		if(flag2==5)
		{
			gongjidir();
			flag2=0;
		}
		if(flag==60)
		{
			firstmove();
			flag=0;
		}
		break;
	case 1:
		if(flag2==40)
		{
			gonjidir2_0();
			flag2=0;//若不清零的画会数据溢出之后再清0好像，总之不清零也能运行，原因还未知
		}
		if(flag==60)
		{
			secondmove();
			judgeresult();
			flag=0;
		}
		break;
	case 2:
		if(flag2==40)
		{
			gonjidir2_0();
			flag2=0;
		}
		if(flag==60)
		{
			thirdmove();
			judgeresult();
			flag=0;
		}
		break;
	}
}
