#include<reg52.h>
#include"ң����.h"
void send ()//���ͼ���ֵ
{
	SBUF=send_data;
	while(!TI); //TI�����жϱ�־λ,�ȴ����ݷ�����
	TI=0;
	send_data=0;//�����ͬ�������0
}
void init()
{
	TMOD=0x21;//�趨T1��ʱ��������ʽ2
	TH1=0xfd;
	TL1=0xfd;//��ʱ��TH1,TL1װ��ֵ
	TR1=1;//����T1��ʱ��

	SM0=0;
	SM1=1;//���ô��ڹ�����ʽΪ1
	REN=1;//�򿪽��ն�˫��

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