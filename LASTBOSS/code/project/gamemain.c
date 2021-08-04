#include <reg52.h>
#include <math.h>
#include "������Ϸ.h"
#include "tuxiangku.h"

XY towerxy[10];//���ڴ洢���������������
Enemyxingxi D[10];//���ڴ洢ÿ���ؿ����˵���Ϣ
uchar idata guangqiachoose=0;//������ǹؿ�

uchar idata n=0;//���ڼ�¼��������
uchar idata Dn=0;

void meun(uchar flagchoose)
{
	while(1)
	{
		switch (receive_data)
		{
		case 'u':
			if(flagchoose==0)
			{
				cachu(flagchoose);
				flagchoose=2;
				choosemenu(flagchoose);
			}
			else
			{
				cachu(flagchoose);
				flagchoose--;
				choosemenu(flagchoose);
			}
			receive_data=0;
			break;
		case 'd':
			if(flagchoose==2)
			{
				cachu(flagchoose);
				flagchoose=0;
				choosemenu(flagchoose);
			}
			else
			{
				cachu(flagchoose);
				flagchoose++;
				choosemenu(flagchoose);
			}
			receive_data=0;
			break;
		case 'y':
			receive_data=0;
			switch(flagchoose)
			{
			case 0:
				guangqiachoose=0;
				switch(guangqiachoose)
				{
				case 0:
					buzzer_d();
					diyiguang(flagchoose);
				default:break;
				}
				case 1:
					jixuyouxi();
					xuanguang_meun(flagchoose);
					break;
				case 2:
					paihanbang();
					while(1)
					{
						if(receive_data!=0)
						{
							receive_data=0;
							break;
						}
					}
					mainmeun();
					meun(flagchoose);
					break;
				default:break;
			}
			receive_data=0;
			break;
		default:break;
		}
	}
}
//***************************************************************
//��һ��
void initfirstmove()//���ڸ���һ�ص��˵�����HP��ֵ
{
	direnx=4;
	direny=56;
	direnhp=3;
}
void firstmove()//��һ�ص����˶��켣������T0��ʱ���ж�
{
	if(1<direnx&&direnx<16)
	{
		direnx=direnx+2;
		dprintf(clear,direnx-2,direny);//����Ӱ��
		switch (direnhp)
		{
		case 3:
			dprintf(enemy,direnx,direny);//��ʾ����
			break;
		default:
			dprintf(zhansunenemy,direnx,direny);//��ʾ���˺�ĵ���
			break;
		}
		flag=0;
	}
	else
	{
		if(1<direny&&direny<56+15)
		{
			direny=direny+15;
			dprintf(clear,direnx,direny-15);//����Ӱ��
			switch (direnhp)
			{
			case 3:
				dprintf(enemy,direnx,direny);//��ʾ����
				break;
			default:
				dprintf(zhansunenemy,direnx,direny);//��ʾ���˺�ĵ���
				break;
			}
			flag=0;
		}
		else
		{
			if(1<direnx&&direnx<26)
			{
				direnx=direnx+2;
				dprintf(clear,direnx-2,direny);//����Ӱ��
				switch (direnhp)
				{
				case 3:
					dprintf(enemy,direnx,direny);//��ʾ����
					break;
				default:
					dprintf(zhansunenemy,direnx,direny);//��ʾ���˺�ĵ���
					break;
				}
				if(direnx==26)
				{
					HP--;
					dprintf(home,26,56+15);
				}
				flag=0;
			}
			else
			{
				if(direnshuliang!=0)
				{
					direnshuliang--;//������˳ɹ��������˵��������˽����˻��أ�����HP--
					initfirstmove();
					youxixinxi(direnshuliang,HP,jingbi/100,jingbi/10-(jingbi/100)*10,jingbi-(jingbi/100)*100-(jingbi/10)*10);
				}
				else
				{
					TR0=0;//ֹͣ��ʱ��
					buzzer_d();//�����������ʾ��Ϸ����
					if(HP==0)
					{
						write_LCD_commond(0x9c);//�رչ����˸
						shibaijiemian();
						jieshuflag=2;
					}
					else
					{
						defen=defen+jingbi+HP*100;
						chengongjiemian();
						score[5]=defen;//���÷��ȱ�������������Ϸ������д��EEPROM
						write_LCD_commond(0x9c);//�رչ����˸
						jieshuflag=1;
					}

				}
			}
		}
	}
}
//***************************************************************************
//�ڶ���
XY zuobiaochuli2_0(uchar guangbiaox,uchar guangbiaoy)
{
	XY temp;
	temp.x=guangbiaox;
	temp.y=guangbiaoy/2*16;
	return temp;
}

void secondmove()//�ڶ��ص����˶��켣
{
	uchar i=1;//��Ϊ�����Ǹ�������ǰ���Ǹ������Ӱ�Ӹ���������ֻ��Ҫ���������Ǹ������Ӱ�Ӿͺ�,������һ��I��switch�ͺ�
	if(Dn==0||Dn==2||Dn==4)
	{
		D[Dn].n.x=D[Dn].n.x+2;
		Dn++;
		i=1;
	}
	else
	{
		if(D[Dn-1].n.x<10&&D[Dn-1].n.y==16)
		{
			D[Dn-1].n.x=D[Dn-1].n.x+2;
			D[Dn].n.x=D[Dn].n.x+2;
			i=1;
		}
		else if(D[Dn-1].n.x==10&&D[Dn-1].n.y<5*16)
		{
			if(D[Dn].n.x<10)
			{
				D[Dn].n.x=D[Dn].n.x+2;
				i=1;
			}
			else
			{
				D[Dn].n.y=D[Dn].n.y+16;
				i=0;
			}
			D[Dn-1].n.y=D[Dn-1].n.y+16;
		}
		else if(D[Dn-1].n.y==5*16&&D[Dn-1].n.x>4)
		{
			if(D[Dn].n.y<5*16)
			{
				D[Dn].n.y=D[Dn].n.y+16;
				i=0;
			}
			else
			{
				D[Dn].n.x=D[Dn].n.x-2;
				i=2;
			}
			D[Dn-1].n.x=D[Dn-1].n.x-2;
		}
		else if(D[Dn-1].n.x==4&&D[Dn-1].n.y>=5*16&&D[Dn-1].n.y<7*16)//��Ϊy�ǲ��������ģ�����x���ػأ�����Ҫ��Ӹ�����������ִ������һ��
		{
			if(D[Dn].n.x>4)
			{
				D[Dn].n.x=D[Dn].n.x-2;
				i=2;
			}
			else
			{
				D[Dn].n.y=D[Dn].n.y+16;
				i=0;
			}
			D[Dn-1].n.y=D[Dn-1].n.y+16;
		}
		else if(D[Dn-1].n.y==7*16&&D[Dn-1].n.x<12)
		{
			if(D[Dn].n.y<7*16)
			{
				D[Dn].n.y=D[Dn].n.y+16;
				i=0;
			}
			else
			{
				D[Dn].n.x=D[Dn].n.x+2;
				i=1;
			}
			D[Dn-1].n.x=D[Dn-1].n.x+2;
		}
		else if(D[Dn-1].n.y==0&&D[Dn-1].n.x==26)
		{
			dprintf(clear,D[Dn].n.x,D[Dn].n.y);
			D[Dn].n.x=26;
			D[Dn].n.y=0;
			if(Dn<direnshuliang-1)
			{
				Dn++;
			}
		}
	}
	switch(i)
	{
	case 0:
		dprintf(clear,D[Dn].n.x,D[Dn].n.y-16);
		dprintf(enemy,D[Dn].n.x,D[Dn].n.y);
		dprintf(enemy,D[Dn-1].n.x,D[Dn-1].n.y);
		break;
	case 1:
		dprintf(clear,D[Dn].n.x-2,D[Dn].n.y);
		dprintf(enemyhome,0,16);//��ֹ������ʱ��ѵط����ز���
		dprintf(enemy,D[Dn].n.x,D[Dn].n.y);
		dprintf(enemy,D[Dn-1].n.x,D[Dn-1].n.y);
		break;
	case 2:
		dprintf(clear,D[Dn].n.x+2,D[Dn].n.y);
		dprintf(enemy,D[Dn].n.x,D[Dn].n.y);
		dprintf(enemy,D[Dn-1].n.x,D[Dn-1].n.y);
		break;
	default:
		break;
	}
	if(D[Dn-1].n.x==12&&D[Dn-1].n.y==16*7)
	{
		dprintf(home,12,16*7);
		HP--;

		judgeresult();

		D[Dn-1].n.x=28;
		D[Dn-1].n.y=0;//�ѽ�ȥ֮��ĵ��˸��ų���Ļ
		if(D[Dn].n.x==10)
			D[Dn].n.x=D[Dn].n.x+2;
	}
	else if(D[Dn].n.x==12&&D[Dn].n.y==16*7&&Dn<direnshuliang-1)
	{
		dprintf(home,12,16*7);
		HP--;

		judgeresult();

		D[Dn].n.x=28;
		D[Dn].n.y=0;//�ѽ�ȥ֮��ĵ��˸��ų���Ļ
		Dn++;
	}
	youxixinxi2_0(HP,Dn+1,jingbi);
}

void judgeresult()//�жϳɹ�����ʧ�ܵĺ���
{
	if(HP==0)
	{
		buzzer_d();//�����������ʾ��Ϸ����

		youxixinxi2_0(HP,Dn+1,jingbi);
		delay_ms(5);
		LM4229_clear();
		shibaijiemian();
		TR0=0;
		write_LCD_commond(0x9c);
		jieshuflag=2;
	}
	else if((D[direnshuliang-1].n.x==28&&D[direnshuliang-1].n.y==0)||Dn==direnshuliang-1)//���һ���������Ҳ������Ĺ��
	{
		buzzer_d();//�����������ʾ��Ϸ����

		defen=defen+HP*100+jingbi*10;

		youxixinxi2_0(HP,Dn+1,jingbi);
		delay_ms(5);
		LM4229_clear();
		chengongjiemian();
		TR0=0;
		write_LCD_commond(0x9c);
		jieshuflag=1;
	}

}

//***************************************************************************
//������
void thirdmove()//�����صĵ����ƶ�
{
	if(D[Dn].n.x==3*x_1&&D[Dn].n.y<2*y_1)
	{
		if(Dn==0||Dn==2||Dn==4)//����������������±��һ�����������У�Dn�൱��һ������
		{
			Dn++;
		}

		D[Dn-1].n.y+=y_1;
		D[Dn].n.y+=y_1;

		dprintf(clear,3*x_1,D[Dn].n.y-y_1);
		dprintf(enemyhome,3*x_1,0);
		dprintf(enemy,3*x_1,D[Dn].n.y);
	}
	else
	{
		if(D[Dn-1].n.y==2*y_1&&D[Dn-1].n.x>2*x_1)
		{
			dprintf(clear,D[Dn-1].n.x,D[Dn-1].n.y);
			D[Dn-1].n.x-=x_1;
			dprintf(enemy,D[Dn-1].n.x,D[Dn-1].n.y);
		}
		if(D[Dn].n.y==2*y_1&&D[Dn].n.x<4*x_1)
		{
			dprintf(clear,D[Dn].n.x,D[Dn].n.y);
			D[Dn].n.x+=x_1;
			dprintf(enemy,D[Dn].n.x,D[Dn].n.y);
		}
		else
		{
			if(D[Dn-1].n.y<5*y_1&&D[Dn-1].n.x==2*x_1)
			{
				dprintf(clear,D[Dn-1].n.x,D[Dn-1].n.y);
				D[Dn-1].n.y+=y_1;
				dprintf(enemy,D[Dn-1].n.x,D[Dn-1].n.y);
			}
			if(D[Dn].n.y<5*y_1&&D[Dn].n.x==4*x_1)
			{
				dprintf(clear,D[Dn].n.x,D[Dn].n.y);
				D[Dn].n.y+=y_1;
				dprintf(enemy,D[Dn].n.x,D[Dn].n.y);
			}
			else
			{
				if(D[Dn-1].n.y==5*y_1&&D[Dn-1].n.x==2*x_1)
				{
					dprintf(clear,D[Dn-1].n.x,D[Dn-1].n.y);
					D[Dn-1].n.x+=x_1;
					dprintf(enemy,D[Dn-1].n.x,D[Dn-1].n.y);
				}
				if(D[Dn].n.y==5*y_1&&D[Dn].n.x==4*x_1)
				{
					dprintf(clear,D[Dn].n.x,D[Dn].n.y);
					D[Dn].n.x-=x_1;
					dprintf(enemy,D[Dn].n.x,D[Dn].n.y);
				}
				else
				{
					if(D[Dn-1].n.y<7*y_1&&D[Dn-1].n.x==3*x_1)
					{
						dprintf(clear,D[Dn-1].n.x,D[Dn-1].n.y);
						D[Dn-1].n.y+=y_1;
						dprintf(enemy,D[Dn-1].n.x,D[Dn-1].n.y);
						if(D[Dn-1].n.y==7*y_1&&D[Dn-1].n.x==3*x_1)
						{
							D[Dn-1].n.y=0;
							D[Dn-1].n.x=28;

							HP--;
							dprintf(zhansunenemy,28,0);
							dprintf(home,3*x_1,7*y_1);
							judgeresult();
						}
					}
					if(D[Dn].n.y<7*y_1&&D[Dn].n.x==3*x_1)
					{
						dprintf(clear,D[Dn].n.x,D[Dn].n.y);
						D[Dn].n.y+=y_1;
						dprintf(enemy,D[Dn].n.x,D[Dn].n.y);
						if(D[Dn].n.y==7*y_1&&D[Dn].n.x==3*x_1)
						{
							D[Dn].n.y=0;
							D[Dn].n.x=28;//������ķ���Ż�Ĺ�����HP--

							HP--;
							dprintf(zhansunenemy,28,0);
							dprintf(home,3*x_1,7*y_1);
							judgeresult();

							Dn++;//������Dn����1��������һ��
						}
					}
				}
			}
		}
	}
	if((D[Dn].n.y==0&&D[Dn].n.x==26)&&Dn<direnshuliang)
	{
		Dn++;
	}
	youxixinxi2_0(HP,Dn+1,jingbi);
}
//*******************************************************************************
XY zuobiaochuli(uchar guangbiaox,uchar guangbiaoy)//���괦���������ڻ���������ͷ���������
{
	XY temp;
	temp.x=guangbiaox;
	temp.y=guangbiaoy/2*((56-14)/3);
	return temp;
}

void gongjidir()//���ڷ�������������
{
	uchar i,flag;
	for(i=0;i<=n;i++)
	{
		if(sqrt((towerxy[i].x-direnx)^2+(towerxy[i].y-direny)^2)<sqrt(2^2+14^2)+1)
		{
			direnhp--;
			dprintf(zhansunenemy,direnx,direny);

		}
		if(direnhp==0)
		{
			dprintf(clear,direnx,direny);
			direnx=0;
			direny=0;//��������֮������������ҽ�������0��

			flag=1;//��ʾ���ܵ���Ҫ��Ǯ
		}
	}
	if(flag==1)
	{
		jingbi=jingbi+10;
		youxixinxi(direnshuliang,HP,jingbi/100,jingbi/10-(jingbi/100)*10,jingbi-(jingbi/100)*100-(jingbi/10)*10);//��Ϣ�޸�֮��Ҫ����һ����Ϣ
		flag=0;//������0
	}
}

void gonjidir2_0()//�Ľ�֮��Ĺ�������
{
	uchar i,flag=0;
	for(i=0;i<=n;i++)
	{
		if(sqrt((towerxy[i].x-D[Dn].n.x)^2+(towerxy[i].y-D[Dn].n.y)^2)<sqrt(2^2+14^2))
		{
			D[Dn].hp--;
			dprintf(zhansunenemy,D[Dn].n.x,D[Dn].n.y);
			if(D[Dn].hp==0)
			{
				dprintf(clear,D[Dn].n.x,D[Dn].n.y);
				D[Dn].n.x=26;
				D[Dn].n.y=0;//��������֮������������ҽ�������0��

				flag++;//��ʾ���ܵ���Ҫ��Ǯ
			}
		}
		if(sqrt((towerxy[i].x-D[Dn-1].n.x)^2+(towerxy[i].y-D[Dn-1].n.y)^2)<2*sqrt(2^2+14^2))
		{
			D[Dn-1].hp--;
			dprintf(zhansunenemy,D[Dn-1].n.x,D[Dn-1].n.y);
			if(D[Dn-1].hp==0)
			{
				dprintf(clear,D[Dn-1].n.x,D[Dn-1].n.y);
				D[Dn-1].n.x=26;
				D[Dn-1].n.y=0;//��������֮������������ҽ�������0��

				flag++;//��ʾ���ܵ���Ҫ��Ǯ
			}
		}

	}
	if(flag!=0)
	{
		jingbi=jingbi+flag*10;
		youxixinxi2_0(HP,Dn,jingbi);//��Ϣ�޸�֮��Ҫ����һ����Ϣ
		flag=0;//������0
	}
}

void yaokon()//��Ϸ��ʼ��������ĺ���
{
	uchar score1,score2;
	while(1)
	{
		write_LCD_commond(0x9f);//�򿪹����˸
		write_LCD_ddc(0x21,guangbiaox,guangbiaoy);
		switch (receive_data)
		{
		case 'l':
			receive_data=0;
			if(guangbiaox==0)
			{
				guangbiaox=12;
			}
			else
			{
				guangbiaox=guangbiaox-2;
			}
			write_LCD_ddc(0x21,guangbiaox,guangbiaoy);
			break;
		case 'u':
			receive_data=0;
			if(guangbiaoy==0)
			{
				guangbiaoy=14;
			}
			else
			{
				guangbiaoy=guangbiaoy-2;
			}
			write_LCD_ddc(0x21,guangbiaox,guangbiaoy);
			break;
		case 'r':
			receive_data=0;
			if(guangbiaox==12)
			{
				guangbiaox=0;
			}
			else
			{
				guangbiaox=guangbiaox+2;
			}
			write_LCD_ddc(0x21,guangbiaox,guangbiaoy);
			break;
		case 'd':
			receive_data=0;
			if(guangbiaoy==14)
			{
				guangbiaoy=0;
			}
			else
			{
				guangbiaoy=guangbiaoy+2;
			}
			write_LCD_ddc(0x21,guangbiaox,guangbiaoy);
			break;
		case 'y':
			receive_data=0;
			if(jingbi>=10)
			{
				towerxy[n]=zuobiaochuli2_0(guangbiaox,guangbiaoy);
				dprintf(tower,towerxy[n].x,towerxy[n].y);
				n++;
				jingbi=jingbi-10;

				youxixinxi2_0(HP,Dn,jingbi);
			}
			break;
		}
		if(jieshuflag==2)
		{
			jieshuflag=0;
			while(1)
			{
				if(receive_data!=0)
				{
					receive_data=0;
					mainmeun();
					choosemenu(0);
					meun(flagchoose);
				}
			}
		}
		else if(jieshuflag==1)
		{
			jieshuflag=0;//�ǵ�Ҫ��ʹ��0�����ֱ�ӽ�����Ϸ
			score1=defen/100;
			score2=defen%100;
			while(1)
			{
				tubedisplay(score1/10,score1%10,score2/10,0);
				switch(receive_data)
				{
				case 'y':
					receive_data=0;
					guangqiachoose++;
					selectguangqia(flagchoose);
				case 'n':
					receive_data=0;
					mainmeun();
					choosemenu(0);
					Weeprom();
					meun(flagchoose);
				}
			}
		}
	}
}
