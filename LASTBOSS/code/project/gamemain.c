#include <reg52.h>
#include <math.h>
#include "塔防游戏.h"
#include "tuxiangku.h"

XY towerxy[10];//用于存储防御塔坐标的数组
Enemyxingxi D[10];//用于存储每个关卡敌人的信息
uchar idata guangqiachoose=0;//用来标记关卡

uchar idata n=0;//用于记录塔的数量
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
//第一关
void initfirstmove()//用于给第一关敌人的坐标HP赋值
{
	direnx=4;
	direny=56;
	direnhp=3;
}
void firstmove()//第一关敌人运动轨迹，用在T0定时器中断
{
	if(1<direnx&&direnx<16)
	{
		direnx=direnx+2;
		dprintf(clear,direnx-2,direny);//擦除影子
		switch (direnhp)
		{
		case 3:
			dprintf(enemy,direnx,direny);//显示敌人
			break;
		default:
			dprintf(zhansunenemy,direnx,direny);//显示损伤后的敌人
			break;
		}
		flag=0;
	}
	else
	{
		if(1<direny&&direny<56+15)
		{
			direny=direny+15;
			dprintf(clear,direnx,direny-15);//擦除影子
			switch (direnhp)
			{
			case 3:
				dprintf(enemy,direnx,direny);//显示敌人
				break;
			default:
				dprintf(zhansunenemy,direnx,direny);//显示损伤后的敌人
				break;
			}
			flag=0;
		}
		else
		{
			if(1<direnx&&direnx<26)
			{
				direnx=direnx+2;
				dprintf(clear,direnx-2,direny);//擦除影子
				switch (direnhp)
				{
				case 3:
					dprintf(enemy,direnx,direny);//显示敌人
					break;
				default:
					dprintf(zhansunenemy,direnx,direny);//显示损伤后的敌人
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
					direnshuliang--;//如果敌人成功到了最后说明这个敌人进入了基地，并且HP--
					initfirstmove();
					youxixinxi(direnshuliang,HP,jingbi/100,jingbi/10-(jingbi/100)*10,jingbi-(jingbi/100)*100-(jingbi/10)*10);
				}
				else
				{
					TR0=0;//停止定时器
					buzzer_d();//蜂鸣器鸣响表示游戏结束
					if(HP==0)
					{
						write_LCD_commond(0x9c);//关闭光标闪烁
						shibaijiemian();
						jieshuflag=2;
					}
					else
					{
						defen=defen+jingbi+HP*100;
						chengongjiemian();
						score[5]=defen;//将得分先保存在数组中游戏结束再写入EEPROM
						write_LCD_commond(0x9c);//关闭光标闪烁
						jieshuflag=1;
					}

				}
			}
		}
	}
}
//***************************************************************************
//第二关
XY zuobiaochuli2_0(uchar guangbiaox,uchar guangbiaoy)
{
	XY temp;
	temp.x=guangbiaox;
	temp.y=guangbiaoy/2*16;
	return temp;
}

void secondmove()//第二关敌人运动轨迹
{
	uchar i=1;//因为后面那个方块会把前面那个方块的影子给扑灭，所以只需要擦除后面那个方块的影子就好,并且用一个I加switch就好
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
		else if(D[Dn-1].n.x==4&&D[Dn-1].n.y>=5*16&&D[Dn-1].n.y<7*16)//因为y是不断在升的，但是x会迂回，所以要多加个条件避免先执行了这一步
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
		dprintf(enemyhome,0,16);//防止擦除的时候把地方基地擦了
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
		D[Dn-1].n.y=0;//把进去之后的敌人给放出屏幕
		if(D[Dn].n.x==10)
			D[Dn].n.x=D[Dn].n.x+2;
	}
	else if(D[Dn].n.x==12&&D[Dn].n.y==16*7&&Dn<direnshuliang-1)
	{
		dprintf(home,12,16*7);
		HP--;

		judgeresult();

		D[Dn].n.x=28;
		D[Dn].n.y=0;//把进去之后的敌人给放出屏幕
		Dn++;
	}
	youxixinxi2_0(HP,Dn+1,jingbi);
}

void judgeresult()//判断成功还是失败的函数
{
	if(HP==0)
	{
		buzzer_d();//蜂鸣器鸣响表示游戏结束

		youxixinxi2_0(HP,Dn+1,jingbi);
		delay_ms(5);
		LM4229_clear();
		shibaijiemian();
		TR0=0;
		write_LCD_commond(0x9c);
		jieshuflag=2;
	}
	else if((D[direnshuliang-1].n.x==28&&D[direnshuliang-1].n.y==0)||Dn==direnshuliang-1)//最后一个敌人如果也进入了墓地
	{
		buzzer_d();//蜂鸣器鸣响表示游戏结束

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
//第三关
void thirdmove()//第三关的敌人移动
{
	if(D[Dn].n.x==3*x_1&&D[Dn].n.y<2*y_1)
	{
		if(Dn==0||Dn==2||Dn==4)//给敌人数量数组的下标加一让它分批进行，Dn相当于一个开关
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
							D[Dn].n.x=28;//将进入的方块放回墓地随后HP--

							HP--;
							dprintf(zhansunenemy,28,0);
							dprintf(home,3*x_1,7*y_1);
							judgeresult();

							Dn++;//并且让Dn自增1，开启下一波
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
XY zuobiaochuli(uchar guangbiaox,uchar guangbiaoy)//坐标处理函数，用于换算光标坐标和防御塔坐标
{
	XY temp;
	temp.x=guangbiaox;
	temp.y=guangbiaoy/2*((56-14)/3);
	return temp;
}

void gongjidir()//用于防御塔攻击敌人
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
			direny=0;//敌人死亡之后擦除掉，并且将坐标置0；

			flag=1;//表示击败敌人要加钱
		}
	}
	if(flag==1)
	{
		jingbi=jingbi+10;
		youxixinxi(direnshuliang,HP,jingbi/100,jingbi/10-(jingbi/100)*10,jingbi-(jingbi/100)*100-(jingbi/10)*10);//信息修改之后要跟新一下信息
		flag=0;//重新置0
	}
}

void gonjidir2_0()//改进之后的攻击敌人
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
				D[Dn].n.y=0;//敌人死亡之后擦除掉，并且将坐标置0；

				flag++;//表示击败敌人要加钱
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
				D[Dn-1].n.y=0;//敌人死亡之后擦除掉，并且将坐标置0；

				flag++;//表示击败敌人要加钱
			}
		}

	}
	if(flag!=0)
	{
		jingbi=jingbi+flag*10;
		youxixinxi2_0(HP,Dn,jingbi);//信息修改之后要跟新一下信息
		flag=0;//重新置0
	}
}

void yaokon()//游戏开始后光标操作的函数
{
	uchar score1,score2;
	while(1)
	{
		write_LCD_commond(0x9f);//打开光标闪烁
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
			jieshuflag=0;//记得要即使清0否则会直接结束游戏
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
