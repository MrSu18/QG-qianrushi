#include <reg52.h>
#include "塔防游戏.h"

extern uchar idata n;

void Beep()//蜂鸣器高低频变化
{
	beep=~beep;//进行高低电平的转换，‘~’是取反符号
	delay_ms(1);
}

void buzzer_d()//蜂鸣器发出提示音
{
	n=255;
	while(n)
	{
		Beep();
		n--;
	}
}
