#ifndef yaokongqi_H_INCLUDED
#define yaokongqi_H_INCLUDED

#define uchar unsigned char
#define uint unsigned int

extern uchar send_data;
extern uchar receive_data;
//*************************************
//通用函数
void delay_ms(uint i);//延时ms函数
//************************************
//键盘
#define key P2

void matrixkeyscan();//矩阵键盘扫描函数0
//************************************
//双机通信函数
void send ();//发送键盘值
void init();//发送方初始化函数
void ser();//定时器中断

//***********************************
//蜂鸣器播放音乐
void bofangyingyue();

#endif // 遥控器_H_INCLUDED
