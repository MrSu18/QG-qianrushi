#ifndef LM4229_H_INCLUDED
#define LM4229_H_INCLUDED

#define uchar unsigned char
#define uint unsigned int

#define y_1 16
#define x_1 2

typedef struct zuobiao
{
	uchar x;
	uchar y;
}XY;

typedef struct enemyxingxi
{
	struct zuobiao n;
	uchar	hp;
}Enemyxingxi;


extern uchar receive_data;

extern uchar flag;//用来对T0定时器是否中断做一个标记，达到定时2S的作用
extern uchar idata flagchoose;//用来主菜单的选择按键

extern uchar idata guangqiachoose;

extern uchar idata direnx;
extern uchar idata direny;//敌人的位置xy用定时器中断控制敌人移动
extern uchar idata direnhp;

extern uchar idata direnshuliang;//用来标记敌人的数量，从而达到依次出怪的效果

extern uchar idata Dn;//敌人目前出现的数量
extern uchar idata HP;//基地血量
extern uint idata jingbi;//金币数量
extern uint idata defen;//玩家得分
extern uchar idata jieshuflag;//用来标记游戏是否结束

extern uchar guangbiaox;
extern uchar guangbiaoy;//光标坐标

extern uint idata score[];

//*************************************
//通用函数
void delay_ms(uint i);//延时ms函数
void init_T0();//对定时器0进行初始化
//*************************************
//LCD
#define LCD_data P2//LCD的数据端口
#define LcmLengthDots    240
#define LcmWidthDots     128//对LCD的屏幕数据进行定义方便修改

sbit C_D=P1^4;	//对LCD的功能端口进行命名
sbit R_D=P1^5;
sbit W_R=P1^6;
sbit C_E=P1^7;
sbit REST=P3^7;
//***************************************
//数码管
#define digitaltube P0

sbit qianwei 	=P1^0;//对数码管功能端口进行命名
sbit baiwei	=P1^1;
sbit shiwei	=P1^2;
sbit gewei	=P1^3;
//***************************************
//EEPROM断电存储器
sbit SDA=P3^6;
sbit SCL=P3^5;
//***************************************
//蜂鸣器
sbit beep=P3^4;
//***************************************
//LCD功能函数
void write_LCD_commond(uchar com);//对LCD写一个指令
void write_LCD_data(uchar dat);//对LCD写一个数据

void write_LCD_dc(uchar com,uchar dat);//写一个数据和一个指令
void write_LCD_ddc(uchar com,uchar dat1,uchar dat2);//写两个数据和一个指令

void LM4229_init(void);//LCD初始化函数
void LM4229_clear(void);//LCD清屏函数
void dprintf(uchar *bmp_16,uint X_pos,uint Y_pos);//lcd显示函数(x,y)240*128,0<x<28,0<y<122
void charprintf(unsigned char *bmp_16,uint X_pos,uint Y_pos);

//***************************************
//画面函数
void mainmeun();//游戏开始前的主菜单界面
void choosemenu(uchar x);//通过传递参数来改变箭头的位置
void cachu(uchar x);//擦除前面箭头的函数

void gameinterface();//用来给游戏界面分区
void first();//新游戏界面，默认第一关开始

void youxixinxi(uchar a,uchar b,uchar bai,uchar shi,uchar ge);//显示敌人剩余量，基地血量，还有金币数量的函数，需要根据变量去控制显示
void youxixinxi2_0(HP,n,jingbi);//后续更新之后的关卡信息
void shibaijiemian();//游戏失败界面
void chengongjiemian();//游戏成功界面

void jixuyouxi();//继续游戏里面的选关二级菜单
void paihanbang();//显示排行榜信息
void paihanbangfenshu(uchar i,uchar j,uint p);//分别对排行榜上的分数进行打印，给paihanbang函数用

//菜单选择函数
void xuanguang_meun(uchar x);//选关时候的动态函数
void selectguangqia(uchar flagchoose);//把关卡选择封装成一个函数

//**************************************
//数码管功能函数
void tubedisplay(uint ge,uint shi,uint bai,uint qian);//段选函数
//**************************************
//双机通信功能函数
void init_R();//对接收方进行初始化
void ser();//定时器中断
//**************************************
//游戏核心逻辑函数
void meun(uchar flagchoose);

XY zuobiaochuli(uchar guangbiaox,uchar guangbiaoy);//坐标处理函数，用于换算光标坐标和防御塔坐标
XY zuobiaochuli2_0(uchar guangbiaox,uchar guangbiaoy);//2*16对应的坐标处理函数

void gongjidir();//用于防御塔攻击敌人

void yaokon();//游戏开始后光标操作的函数

//每关的设计函数
//第一关
void initfirstmove();//给第一关敌人的移动 设定初始定初始值
void firstmove();//第一关敌人运动轨迹，用在T0定时器中断
void diyiguang(uchar flagchoose);//第一关总的接口函数
//第二关
void second();//第二关的界面函数
void youxifenqu();//游戏基础重合界面函数，减少代码复用性
void secondmove();//第二关敌人运动东轨迹
void dierguang();//第二关总的接口函数
void judgeresult();//判断成功还是失败的函数
void gonjidir2_0();//改进之后的攻击敌人
uchar towerjiance2();//检测防御塔是否在敌人路径上，在返回0不在返回1
//第三关
void third();//第三关的界面函数
void disanguan();//第三关的总接口函数
void thirdmove();//第三关的敌人移动
//**************************************
//EEPROM功能函数
void delay();
void init_EEPROM();
void respons();
void stop();
void writebyte(uchar date);
uchar readbyte();
void write_add(uchar address,uchar date);
uchar read_add(uchar address);
//存储读取信息
void scorepaixu(uint *p);//对存储数据的数组进行排序，使之有序后再存入EEPROM
void Weeprom();//存储数据到EEPROM中
void Reeprom();//从EEPROM中读取数据
//**************************************
//蜂鸣器
void Beep();//蜂鸣器高低频变化
void buzzer_d();//蜂鸣器发出提示音
#endif // LM4229_H_INCLUDED
