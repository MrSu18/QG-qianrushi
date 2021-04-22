#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char

sbit gewei=P2^3;
sbit shiwei=P2^2;

unsigned char code table[] ={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

void delayms(int x);//延迟函数
void display(char a,char b);		//段选函数

char num,num1,num2,shi,ge,flag=0;

void main()
{
	P2=0x0;

	TMOD=0x11;//设置定时器01的工作方式
	 //装初值
	TH0=(65536-45872)/256;
	TL0=(65536-45892)%256;
	TH1=(65536-45872)/256;
	TL1=(65536-45892)%256;

	EA=1;
	ET0=1;
	ET1=1;
	TR0=1;
	TR1=1;
	
	while(1)
	{
		display(shi,ge);
		if(flag==60)
		break;
	}
	while(1);
}

void display(char a,char b)
{
	shiwei=1;
	P0=table[a];
	P0=0xff;
	shiwei=0;
	//delayms(5);

	gewei=1;
	P0=table[b];
	P0=0xff;
	gewei=0;
	//delayms(5);
	
}

void delayms(int x)
{
	int i,j;
	for(i=x;i>0;i--)
		for(j=110;j>0;j--);
}

void T0_time() interrupt 1
{
	TH0=(65536-45872)/256;
	TL0=(65536-45892)%256;
	num1++;
	if(num1==4)
	{
		num1=0;
	}
}

void T1_time () interrupt 3
{
	TH1=(65536-45872)/256;
	TL1=(65536-45892)%256;
	num2++;
	if(num2==20)
	{
		num2=0;
		num++;
		flag++;
		if(num==60)
		{
			num=0;
		}
		shi=num/10;
		ge=num%10;
	}
}