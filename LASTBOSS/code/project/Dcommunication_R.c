#include <reg52.h>
#include "������Ϸ.h"

void init_R()//�Խ��շ����г�ʼ��
{
	TMOD=0x21;//�趨T1��ʱ��������ʽ2����ʱ��0Ϊ������ʽ1�Ե��˵��ƶ����иı�
	TH1=0xfd;
	TL1=0xfd;//��ʱ��TH1,TL1װ��ֵ
	TR1=1;//����T1��ʱ��

	SM0=0;
	SM1=1;//���ô��ڹ�����ʽΪ1
	REN=1;//���������ܶ�

	EA=1;//�����ж�
	ES=1;//�������ж�
}

void ser() interrupt 4//��ʱ���ж�
{
	if(RI==1)
	{
		RI=0;//�����жϱ�־λ�����ܵ�ֹͣλ��ʱ���ڲ�����1�������жϣ�����Ҫ�ֶ���0��
		receive_data=SBUF;
	}
}



