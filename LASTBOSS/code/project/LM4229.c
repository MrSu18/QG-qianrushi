#include <reg52.h>
#include <intrins.h>
#include "塔防游戏.h"

void write_LCD_commond(uchar com)//对LCD写一个指令
{
	C_E = 0;
	C_D = 1;
	R_D = 1;
	LCD_data = com;
	W_R = 0;// write
	_nop_();
	W_R = 1;// disable write
	C_E = 1;
	C_D = 0;
}

void write_LCD_data(uchar dat)//对LCD写一个数据
{
	C_E = 0;
	C_D = 0;
	R_D = 1;
	LCD_data = dat;
	W_R = 0;
	_nop_();
	W_R = 1;
	C_E = 1;
	C_D = 1;
}

void write_LCD_dc(uchar com,uchar dat)//写一个数据和一个指令
{
	write_LCD_data(dat);
	write_LCD_commond(com);
}

void write_LCD_ddc(uchar com,uchar dat1,uchar dat2)//写两个数据和一个指令
{
	write_LCD_data(dat1);
	write_LCD_data(dat2);
	write_LCD_commond(com);
}

void LM4229_init(void)//LCD初始化函数
{
	REST = 0;
	delay_ms(20);
	REST = 1;
	write_LCD_ddc(0x40,0x00,0x00);				//设置文本显示区首地址
	write_LCD_ddc(0x41,LcmLengthDots/8,0x00);  	//设置文本显示区宽度
	write_LCD_ddc(0x42,0x00,0x08);				//设置图形显示区首地址0x08
	write_LCD_ddc(0x43,LcmLengthDots/8,0x00);  	//设置图形显示区宽度
	write_LCD_commond(0xA7);                    	//设置光标形状 8x8方块
	write_LCD_commond(0x80);                    	//显示方式设置 文本and图形(异或)
	write_LCD_commond(0x92);                    	//设置光标
	write_LCD_commond(0x9e);                    	//显示开关设置 文本开,图形开,光标闪烁关
}

void LM4229_clear(void)
{
	uint i;
	write_LCD_ddc(0x24,0x00,0x00); 			//置地址指针为从零开始
   	write_LCD_commond(0xb0); 			//自动写
	for(i = 0;i < LcmLengthDots * LcmWidthDots ;i++)
		write_LCD_data(0x00); 			//清一屏
	write_LCD_commond(0xb2); 			//自动写结束
	write_LCD_ddc(0x24,0x00,0x00); 			//重置地址指针
}

void dprintf(unsigned char *bmp_16,uint X_pos,uint Y_pos)
{
	unsigned long int address;
	unsigned char m,n;
	m = 0;
	address = LcmLengthDots / 8 * Y_pos + X_pos + 0x0800;
	for(n = 0;n < 16;n++)                                  		//计数值16
    	{
		write_LCD_ddc(0x24,(uchar)(address),(uchar)(address>>8));  	//设置显示存储器地址
		write_LCD_dc(0xc0,bmp_16[m++]);             		//写入汉字字模左部
		write_LCD_dc(0xc0,bmp_16[m++]);               	  	//写入汉字字模右部
		address = address + LcmLengthDots/8;                    //修改显示存储器地址，显示下一列
	}
}

 void charprintf(unsigned char *bmp_16,uint X_pos,uint Y_pos)
{
	unsigned long int address;
	unsigned char m,n;
	m = 0;
	address = LcmLengthDots / 8 * Y_pos + X_pos + 0x0800;
	for(n = 0;n < 16;n++)                                  		//计数值16
    	{
		write_LCD_ddc(0x24,(uchar)(address),(uchar)(address>>8));  	//设置显示存储器地址
		write_LCD_dc(0xc0,bmp_16[m++]);             		//写入汉字字模左部

		address = address + LcmLengthDots/8;                    //修改显示存储器地址，显示下一列
	}
}
