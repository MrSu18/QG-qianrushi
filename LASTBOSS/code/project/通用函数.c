#include <reg52.h>
#include "������Ϸ.h"

uchar flag2;
void delay_ms(uint i)//��ʱms����
{
	uint x,y;
	for(x=i;x>0;x--)
		for(y=110;y>0;y--);
}

void init_T0()//�Զ�ʱ��0���г�ʼ��
{
	TH0=(65536-22936)/256;
	TL0=(65536-22936)%256;//װ��ֵ����ʱΪ100ms

	ET0=1;//������ʱ��0���ж� ��
	TR0=1;//������ʱ��0��
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
			flag2=0;//��������Ļ����������֮������0������֮������Ҳ�����У�ԭ��δ֪
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
