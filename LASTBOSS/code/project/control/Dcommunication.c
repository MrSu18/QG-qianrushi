#include<reg52.h>
#include"遥控器.h"
void send ()//发送键盘值
{
	SBUF=send_data;
	while(!TI); //TI发送中断标志位,等待数据发送完
	TI=0;
	send_data=0;//与接收同理发完就置0
}
void init()
{
	TMOD=0x21;//设定T1定时器工作方式2
	TH1=0xfd;
	TL1=0xfd;//定时器TH1,TL1装初值
	TR1=1;//启动T1计时器

	SM0=0;
	SM1=1;//设置串口工作方式为1
	REN=1;//打开接收端双工

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