#include <reg52.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
void delayms(uint);
uchar led;
int main()
{
	int i;
	led=0xfe;//����ֵ11111110
	for(i=0;i<8;i++)
	{
		P0=led; //�����ȵ����˵�һ��LED
		delayms(500);
		led=_crol_(led,1);  //500ms֮���aaѭ������һλҲ���Ǳ����11111101
	}																			  
	P0=0x00;
	delayms(500);
	for(i=0;i<4;i++)
	{
		P0=0x55;
		delayms(500);
		P0=_crol_(P0,1);
		delayms(500);
	}
	P0=0xff;
	while(1);
}
void delayms(uint xms)
{
	uint i,j;
	for(i=xms;i>0;i--)
		for(j=110;j>0;j--);//ִ�п�ѭ��110���൱��1ms
}
