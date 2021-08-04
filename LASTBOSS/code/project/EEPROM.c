#include<reg52.h>
#include"塔防游戏.h"


void delay(){;;}

void init_EEPROM()
{
	SCL=1;
	delay();
	SDA=1;//将总线都拉高以释放总线
	delay();
}

void start()
{
	SDA=1;
	delay();
	SCL=1;
	delay();
	SDA=0;//在SCL高电平期间，SDA下降沿启动信号
	delay();
}

void respons()
{
	uchar i=0;
	SCL=1;
	delay();
	while(SDA==1&&i<255)//若在一段时间内没用收到从机的应答，则主机默认收到
		i++;
	SCL=0;
	delay();
}

void stop()
{
	SDA=0;
	delay();
	SCL=1;
	delay();
	SDA=1;
	delay();
}//SCL高电位时候SDA产生一个上升沿表示停止

void writebyte(uchar date)
{
	uchar i,temp;
	temp=date;
	for(i=0;i<8;i++)
	{
		temp=temp<<1;
		SCL=0;
		delay();
		SDA=CY;
		delay();
		SCL=1;
		delay();
	}
	SCL=0;
	delay();
	SDA=1;
	delay();
}

uchar readbyte()
{
	uchar i,k;
	SCL=0;
	delay();
	SDA=1;
	delay();
	for(i=0;i<8;i++)
	{
		SCL=1;
		delay();
		k=(k<<1)|SDA;
		SCL=0;
		delay();
	}
	return k;
}


void write_add(uchar address,uchar date)
{
	start();
	writebyte(0xa0);
	respons();
	writebyte(address);
	respons();
	writebyte(date);
	respons();
	stop();
}

uchar read_add(uchar address)
{
	uchar date;
	start();
	writebyte(0xa0);//存储器的地址码+0表示写操作
	respons();
	writebyte(address);
	respons();
	start();
	writebyte(0xa1);//读操作
	respons();
	date=readbyte();//读一个字节出来，读完之后位移进入CY
	stop();
	return date;
}

void scorepaixu(uint *p)//对存储数据的数组进行排序，使之有序后再存入EEPROM
{
	char i,j;
	int t;
	p[5]=defen;//每次得分都在P[5]的位置,排序之后如果它还在这个位置就说明它是最后的也不存入eeprom
	for(i=1;i<6;i++)
	{
		t=p[i];
		for(j=i-1;j>=0&&p[j]<t;j--)
		{
			p[j+1]=p[j];
		}
		p[j+1]=t;
	}
}

 void Weeprom()//存储数据到EEPROM中
{
	char i;
	uchar score1,score2;
	scorepaixu(score);
	for(i=0;i<5;i++)
	{
		score1=score[i]/100;
		score2=score[i]-score1*100;

		write_add(i*2+1,score1);
		delay_ms(5);
		write_add(i*2+2,score2);
		delay_ms(5);
	}
	defen=0;//在写入之后把defen清0防止出现一次游戏不断刷分
}

void Reeprom()
{
	char i;
	uchar score1,score2;
	for(i=0;i<5;i++)
	{
		score1=read_add(i*2+1);
		delay_ms(5);
		score2=read_add(i*2+2);
		delay_ms(5);
		score[i]=score1*100+score2;
	}
}

