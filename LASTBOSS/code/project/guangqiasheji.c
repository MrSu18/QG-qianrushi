#include <reg52.h>
#include <math.h>
#include "塔防游戏.h"
#include "tuxiangku.h"

extern XY towerxy[];//用于存储防御塔坐标的数组
extern Enemyxingxi D[];//用于存储每个关卡敌人的信息
extern uchar idata guangqiachoose;//用来标记关卡

extern uchar idata n;//用于记录塔的数量

void diyiguang(uchar flagchoose)//第一关总的接口函数
{
	uchar defenqian;
	uchar defenbai;
	uchar defenshi;
	first();
	youxixinxi(direnshuliang,HP,1,0,0);
	while(1)
	{
		write_LCD_commond(0x9f);//打开光标闪烁
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

					Weeprom();//游戏成功，更新排行榜

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

			while(!receive_data) ;//判断用户是否按下按键，按下之后就才返回主菜单
			receive_data=0;//把接收到的信号置0，放置下次使用

			mainmeun();
			choosemenu(0);
			meun(flagchoose);
		}
	}
}

void dierguang()
{
	uchar i;

	//初始化一下游戏信息
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
	//根据初始化的信息打印静态游戏界面
	second();
	youxixinxi2_0(HP,Dn,jingbi);
	init_T0();//开启T0计时器

	yaokon();
}

void disanguan()//第三关的总接口函数
{
	uchar i;

	//初始化信息
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

	//根据初始化的信息打印静态游戏界面
	third();
	youxixinxi2_0(HP,Dn,jingbi);
	init_T0();//开启T0计时器

	yaokon();

}
