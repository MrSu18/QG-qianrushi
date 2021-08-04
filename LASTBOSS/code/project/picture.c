#include <reg52.h>
#include "塔防游戏.h"
#include "tuxiangku.h"

uint idata score[6]={0,0,0,0,0,0};

void mainmeun()//游戏开始前的主菜单界面
{
	LM4229_init();
	LM4229_clear();
	//昨日方舟
	dprintf(&Y_X_M[0],12,24);
	dprintf(&Y_X_M[32],14,24);
	dprintf(&Y_X_M[64],16,24);
	dprintf(&Y_X_M[96],18,24);
	dprintf(&Y_X_M[128],20,24);

	dprintf(test,10,20);
	dprintf(test,8,20);
	dprintf(test,9,20+15);
	//菜单选项
	dprintf(&new[0],11,55);
	dprintf(&new[32],13,55);
	dprintf(&new[64],15,55);//新游戏

	dprintf(&old[0],11,55+17);
	dprintf(&old[32],13,55+17);
	dprintf(&old[64],15,55+17);
	dprintf(&old[96],17,55+17);


	dprintf(&list[0],11,55+17+17);
	dprintf(&list[32],13,55+17+17);
	dprintf(&list[64],15,55+17+17);//排行榜

}

void choosemenu(uchar x)
{
	dprintf(&choose[0],20,55+x*15);//选择箭头
}
void cachu(uchar x)//擦除前面箭头的函数
{
	dprintf(&clear[0],20,55+x*15);
}
void gameinterface()//用来给游戏界面分区
{
	int i;
	for(i=0;i<30;i=i+2)
	{
		dprintf(huafenhenxian,i,15);
	}

	dprintf(&diren[0],2,0);
	dprintf(&diren[32],4,0);//敌人

	dprintf(&qian[0],22,0);
	dprintf(&qian[32],24,0); //金币

}

void youxixinxi(uchar a,uchar b,uchar bai,uchar shi,uchar ge)//游戏内信息
{
	charprintf(&shuzi[a*16],6,0);

	charprintf(&shuzi[b*16],14,0);

	charprintf(&shuzi[bai*16],26,0);
	charprintf(&shuzi[shi*16],27,0);
	charprintf(&shuzi[ge*16],28,0);
}

void first()//第一关地图
{
	int i;

	LM4229_clear();//清屏

	gameinterface();//给游戏划分信息区域

	dprintf(enemyhome,2,56);
	dprintf(home,26,56+15);

	 //上半边
	for(i=4;i<18;i=i+2)
	{
		dprintf(placed,i,56-15);
	}
	for(i=18;i<26;i=i+2)
	{
		dprintf(placed,i,56);
	}
	//下半边
	for(i=4;i<16;i=i+2)
	{
		dprintf(placed,i,56+15);
	}
	for(i=16;i<26;i=i+2)
	{
		dprintf(placed,i,56+30);
	}

	init_T0();//开启计时器0准备让画面动起来
	initfirstmove();
	HP=3;
	direnshuliang=2; //敌人数量为3
	jingbi=100;

	guangbiaox=1*2;
	guangbiaoy=3*2;
}

void shibaijiemian()//游戏失败界面
{
	LM4229_clear();
	//游戏失败
	dprintf(&shibai[0],10,56);
	dprintf(&shibai[32],12,56);
	dprintf(&shibai[64],14,56);
	dprintf(&shibai[96],16,56);
}
void chengongjiemian()//游戏成功界面
{
	LM4229_clear();
	//游戏成功
	dprintf(&chengong[0],10,56);
	dprintf(&chengong[32],12,56);
	dprintf(&chengong[64],14,56);
	dprintf(&chengong[96],16,56);
	dprintf(&chengong[128],18,56);
}

void paihanbang()//排行榜页面
{
	uchar i,j;
	LM4229_clear();
	Reeprom();
	for(i=0;i<5;i++)
	{
		for(j=0;j<3;j++)
		{
			charprintf(&paihan[j*16],8+j,31+i*15);
		}
		charprintf(&shuzi[(i+1)*16],8+j,31+i*15);
		paihanbangfenshu(i,j,score[i]);
	}
}

void paihanbangfenshu(uchar i,uchar j,uint p)
{
	charprintf(&shuzi[(p/1000)*16],10+j+1,31+i*15);
	charprintf(&shuzi[(p/100-p/1000*10)*16],10+j+2,31+i*15);
	charprintf(&shuzi[(p/10-p/100*10)*16],10+j+3,31+i*15);
	charprintf(&shuzi[0*16],10+j+4,31+i*15);
}

void jixuyouxi()//继续游戏里面的选关二级菜单
{
	uchar i;
	LM4229_clear();
	for(i=0;i<5;i++)
	{
		dprintf(&xuanguan[0*32],12,31+i*17);
		charprintf(&shuzi[(i+1)*16],14,31+i*17);
		dprintf(&xuanguan[1*32],15,31+i*17);
	}
}

//****************************************************
void second()//第二关的界面函数
{
	uchar i;

	LM4229_clear();

	youxifenqu();//游戏静态画面

	dprintf(enemyhome,0,16*1);
	dprintf(home,12,16*7);

	//游戏内地图布局
	for(i=0;i<6;i++)
	{
		dprintf(placed,2+i*2,0);
	}
	for(i=0;i<6;i++)
	{
		dprintf(placed,12,16+i*16);
	}
	for(i=0;i<4;i++)
	{
		dprintf(placed,2+i*2,16*2);
	}
	for(i=0;i<3;i++)
	{
		dprintf(placed,8,16*2+i*16);
	}
	for(i=0;i<3;i++)
	{
		dprintf(placed,6-i*2,16*4);
	}
	for(i=0;i<3;i++)
	{
		dprintf(placed,2,16*5+i*16);
	}
	for(i=0;i<3;i++)
	{
		dprintf(placed,6+i*2,16*6);
	}
}
//*****************************************************
//第三关
void third()//第三关的界面函数
{
	uchar i;

	LM4229_clear();

	youxifenqu();//游戏静态画面

	//游戏内地图布局
	dprintf(enemyhome,3*2,0*16);
	dprintf(home,3*2,16*7);

	dprintf(placed,2*2,16);
	dprintf(placed,4*2,16);//开局敌方基地旁边

	for(i=0;i<2;i++)
	{
		dprintf(placed,3*2,(i+3)*16);
	}//中间两块石头
	for(i=0;i<6;i++)
	{
		dprintf(placed,1*2,(i+1)*16);
		dprintf(placed,5*2,(i+1)*16);//地图最外围
	}
	dprintf(placed,2*2,6*16);
	dprintf(placed,4*2,6*16);//对称的我方基地门口的石头
}

void youxifenqu()//游戏基础重合界面函数，减少代码复用性
{
	uchar i;
	//给区域划分静态信息
	for(i=0;i<9;i++)
	{
		dprintf(huafenxian,14,i*14);
	}
	for(i=0;i<7;i++)
	{
		dprintf(huafenhenxian,16+i*2,56);
	}

	dprintf(&diren[0],16,0);
	dprintf(&diren[32],18,0);//敌人
	charprintf(&zifu[0*16],21,0);
	charprintf(&shuzi[direnshuliang*16],22,0);

	dprintf(&qian[0],16,18);
	dprintf(&qian[32],18,18); //金币

	charprintf(&zifu[1*16],16,36);
	charprintf(&zifu[2*16],18,36);//HP

	for(i=0;i<3;i++)
	{
		dprintf(&daojulang[i*32],20+i*2,56+14);
	}//道具栏
}

void youxixinxi2_0(HP,n,jingbi)//后续更新之后的关卡信息
{
	uchar s,b;

	s=jingbi/10-jingbi/100*10;
	b=jingbi/100;

	charprintf(&shuzi[n*16],20,0);

	charprintf(&shuzi[b*16],20,18);
	charprintf(&shuzi[s*16],21,18);
	charprintf(&shuzi[0],22,18);

	charprintf(&shuzi[HP*16],20,36);
}


