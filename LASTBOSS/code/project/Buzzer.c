#include <reg52.h>
#include "������Ϸ.h"

extern uchar idata n;

void Beep()//�������ߵ�Ƶ�仯
{
	beep=~beep;//���иߵ͵�ƽ��ת������~����ȡ������
	delay_ms(1);
}

void buzzer_d()//������������ʾ��
{
	n=255;
	while(n)
	{
		Beep();
		n--;
	}
}
