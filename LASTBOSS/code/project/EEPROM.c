#include<reg52.h>
#include"������Ϸ.h"


void delay(){;;}

void init_EEPROM()
{
	SCL=1;
	delay();
	SDA=1;//�����߶��������ͷ�����
	delay();
}

void start()
{
	SDA=1;
	delay();
	SCL=1;
	delay();
	SDA=0;//��SCL�ߵ�ƽ�ڼ䣬SDA�½��������ź�
	delay();
}

void respons()
{
	uchar i=0;
	SCL=1;
	delay();
	while(SDA==1&&i<255)//����һ��ʱ����û���յ��ӻ���Ӧ��������Ĭ���յ�
		i++;
	SCL=0;
	delay();
}

void stop()
{
	SDA=0;
	delay();
	SCL=1;
	delay();
	SDA=1;
	delay();
}//SCL�ߵ�λʱ��SDA����һ�������ر�ʾֹͣ

void writebyte(uchar date)
{
	uchar i,temp;
	temp=date;
	for(i=0;i<8;i++)
	{
		temp=temp<<1;
		SCL=0;
		delay();
		SDA=CY;
		delay();
		SCL=1;
		delay();
	}
	SCL=0;
	delay();
	SDA=1;
	delay();
}

uchar readbyte()
{
	uchar i,k;
	SCL=0;
	delay();
	SDA=1;
	delay();
	for(i=0;i<8;i++)
	{
		SCL=1;
		delay();
		k=(k<<1)|SDA;
		SCL=0;
		delay();
	}
	return k;
}


void write_add(uchar address,uchar date)
{
	start();
	writebyte(0xa0);
	respons();
	writebyte(address);
	respons();
	writebyte(date);
	respons();
	stop();
}

uchar read_add(uchar address)
{
	uchar date;
	start();
	writebyte(0xa0);//�洢���ĵ�ַ��+0��ʾд����
	respons();
	writebyte(address);
	respons();
	start();
	writebyte(0xa1);//������
	respons();
	date=readbyte();//��һ���ֽڳ���������֮��λ�ƽ���CY
	stop();
	return date;
}

void scorepaixu(uint *p)//�Դ洢���ݵ������������ʹ֮������ٴ���EEPROM
{
	char i,j;
	int t;
	p[5]=defen;//ÿ�ε÷ֶ���P[5]��λ��,����֮��������������λ�þ�˵����������Ҳ������eeprom
	for(i=1;i<6;i++)
	{
		t=p[i];
		for(j=i-1;j>=0&&p[j]<t;j--)
		{
			p[j+1]=p[j];
		}
		p[j+1]=t;
	}
}

 void Weeprom()//�洢���ݵ�EEPROM��
{
	char i;
	uchar score1,score2;
	scorepaixu(score);
	for(i=0;i<5;i++)
	{
		score1=score[i]/100;
		score2=score[i]-score1*100;

		write_add(i*2+1,score1);
		delay_ms(5);
		write_add(i*2+2,score2);
		delay_ms(5);
	}
	defen=0;//��д��֮���defen��0��ֹ����һ����Ϸ����ˢ��
}

void Reeprom()
{
	char i;
	uchar score1,score2;
	for(i=0;i<5;i++)
	{
		score1=read_add(i*2+1);
		delay_ms(5);
		score2=read_add(i*2+2);
		delay_ms(5);
		score[i]=score1*100+score2;
	}
}

