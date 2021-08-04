#include <reg52.h>
#include <intrins.h>
#include "塔防游戏.h"

uchar receive_data;

uchar flag=0;//用来对T0定时器是否中断做一个标记，达到定时2S的作用
uchar idata flagchoose;

uchar idata direnx;
uchar idata direny;//敌人的位置xy用定时器中断控制敌人移动
uchar idata direnhp;

uchar idata direnshuliang; //敌人数量

uchar idata HP;//基地血量
uint idata jingbi;//金币数量
uint idata defen=0;//用户的得分
uchar idata jieshuflag=0;//用来标记游戏是否结束

uchar guangbiaox;
uchar guangbiaoy;//光标坐标xy

void main()
{
	uchar flagchoose=0;//用来标记箭头位置的

	mainmeun();
	choosemenu(0);

	init_R();
	init_EEPROM();
	Reeprom();//先把数据读出来放到数组里面
	meun(flagchoose);
	while(1);
}
