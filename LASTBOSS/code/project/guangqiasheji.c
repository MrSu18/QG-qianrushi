#include <reg52.h>
#include <math.h>
#include "������Ϸ.h"
#include "tuxiangku.h"

extern XY towerxy[];//���ڴ洢���������������
extern Enemyxingxi D[];//���ڴ洢ÿ���ؿ����˵���Ϣ
extern uchar idata guangqiachoose;//������ǹؿ�

extern uchar idata n;//���ڼ�¼��������

void diyiguang(uchar flagchoose)//��һ���ܵĽӿں���
{
	uchar defenqian;
	uchar defenbai;
	uchar defenshi;
	first();
	youxixinxi(direnshuliang,HP,1,0,0);
	while(1)
	{
		write_LCD_commond(0x9f);//�򿪹����˸
		write_LCD_ddc(0x21,guangbiaox,guangbiaoy);
		switch (receive_data)
		{
		case 'l':
			guangbiaox=guangbiaox-2;
			write_LCD_ddc(0x21,guangbiaox,guangbiaoy);
			receive_data=0;
			break;
		case 'u':
			guangbiaoy=guangbiaoy-3;
			write_LCD_ddc(0x21,guangbiaox,guangbiaoy);
			receive_data=0;
			break;
		case 'r':
			guangbiaox=guangbiaox+2;
			write_LCD_ddc(0x21,guangbiaox,guangbiaoy);
			receive_data=0;
			break;
		case 'd':
			guangbiaoy=guangbiaoy+2;
			write_LCD_ddc(0x21,guangbiaox,guangbiaoy);
			receive_data=0;
			break;
		case 'y':
			if(jingbi>=10)
			{
				towerxy[n]=zuobiaochuli(guangbiaox,guangbiaoy);
				dprintf(tower,towerxy[n].x,towerxy[n].y);
				n++;
				jingbi=jingbi-10;
				receive_data=0;
				youxixinxi(direnshuliang,HP,jingbi/100,jingbi/10-(jingbi/100)*10,jingbi-(jingbi/100)*100-(jingbi/10)*10);
			}
			break;
		}
		if(jieshuflag==1)
		{
			jieshuflag=0;

			defenqian=defen/1000;
			defenbai=defen/100-(defen/1000)*10;
			defenshi=defen/10-(defen/100)*10;
			while(1)
			{
				tubedisplay(defenqian,defenbai,defenshi,0);
				switch(receive_data)
				{
				case 'y':
					receive_data=0;
					guangqiachoose++;
					selectguangqia(flagchoose);
					break;
				case 'n':
					receive_data=0;

					Weeprom();//��Ϸ�ɹ����������а�

					mainmeun();
					choosemenu(0);
					meun(flagchoose);
					break;
				}
			}
		}
		else if(jieshuflag==2)
		{
			jieshuflag=0;

			while(!receive_data) ;//�ж��û��Ƿ��°���������֮��Ͳŷ������˵�
			receive_data=0;//�ѽ��յ����ź���0�������´�ʹ��

			mainmeun();
			choosemenu(0);
			meun(flagchoose);
		}
	}
}

void dierguang()
{
	uchar i;

	//��ʼ��һ����Ϸ��Ϣ
	guangbiaox=2;
	guangbiaoy=0;
	jingbi=120;
	Dn=0;
	direnshuliang=6;
	for(i=0;i<10;i++)
	{
		D[i].hp=3;
		D[i].n.x=2;
		D[i].n.y=16;

		towerxy[i].x=28;
	}
	HP=3;
	//���ݳ�ʼ������Ϣ��ӡ��̬��Ϸ����
	second();
	youxixinxi2_0(HP,Dn,jingbi);
	init_T0();//����T0��ʱ��

	yaokon();
}

void disanguan()//�����ص��ܽӿں���
{
	uchar i;

	//��ʼ����Ϣ
	guangbiaox=3*x_1;
	guangbiaoy=0;
	jingbi=120;
	Dn=0;
	direnshuliang=6;

	for(i=0;i<10;i++)
	{
		D[i].hp=3;
		D[i].n.x=3*x_1;
		D[i].n.y=0;

		towerxy[i].x=28;
	}
	HP=3;

	//���ݳ�ʼ������Ϣ��ӡ��̬��Ϸ����
	third();
	youxixinxi2_0(HP,Dn,jingbi);
	init_T0();//����T0��ʱ��

	yaokon();

}
