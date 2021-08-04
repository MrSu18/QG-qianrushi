#include <reg52.h>
#include "塔防游戏.h"

void init_R()//对接收方进行初始化
{
	TMOD=0x21;//设定T1定时器工作方式2，定时器0为工作方式1对敌人的移动进行改变
	TH1=0xfd;
	TL1=0xfd;//定时器TH1,TL1装初值
	TR1=1;//启动T1计时器

	SM0=0;
	SM1=1;//设置串口工作方式为1
	REN=1;//打开允许接受端

	EA=1;//开总中断
	ES=1;//开串口中断
}

void ser() interrupt 4//定时器中断
{
	if(RI==1)
	{
		RI=0;//接收中断标志位，接受到停止位的时候内部会置1，发起中断，所以要手动置0；
		receive_data=SBUF;
	}
}




