#include <reg52.h>
#include <intrins.h>
#include "������Ϸ.h"

void write_LCD_commond(uchar com)//��LCDдһ��ָ��
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

void write_LCD_data(uchar dat)//��LCDдһ������
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

void write_LCD_dc(uchar com,uchar dat)//дһ�����ݺ�һ��ָ��
{
	write_LCD_data(dat);
	write_LCD_commond(com);
}

void write_LCD_ddc(uchar com,uchar dat1,uchar dat2)//д�������ݺ�һ��ָ��
{
	write_LCD_data(dat1);
	write_LCD_data(dat2);
	write_LCD_commond(com);
}

void LM4229_init(void)//LCD��ʼ������
{
	REST = 0;
	delay_ms(20);
	REST = 1;
	write_LCD_ddc(0x40,0x00,0x00);				//�����ı���ʾ���׵�ַ
	write_LCD_ddc(0x41,LcmLengthDots/8,0x00);  	//�����ı���ʾ�����
	write_LCD_ddc(0x42,0x00,0x08);				//����ͼ����ʾ���׵�ַ0x08
	write_LCD_ddc(0x43,LcmLengthDots/8,0x00);  	//����ͼ����ʾ�����
	write_LCD_commond(0xA7);                    	//���ù����״ 8x8����
	write_LCD_commond(0x80);                    	//��ʾ��ʽ���� �ı�andͼ��(���)
	write_LCD_commond(0x92);                    	//���ù��
	write_LCD_commond(0x9e);                    	//��ʾ�������� �ı���,ͼ�ο�,�����˸��
}

void LM4229_clear(void)
{
	uint i;
	write_LCD_ddc(0x24,0x00,0x00); 			//�õ�ַָ��Ϊ���㿪ʼ
   	write_LCD_commond(0xb0); 			//�Զ�д
	for(i = 0;i < LcmLengthDots * LcmWidthDots ;i++)
		write_LCD_data(0x00); 			//��һ��
	write_LCD_commond(0xb2); 			//�Զ�д����
	write_LCD_ddc(0x24,0x00,0x00); 			//���õ�ַָ��
}

void dprintf(unsigned char *bmp_16,uint X_pos,uint Y_pos)
{
	unsigned long int address;
	unsigned char m,n;
	m = 0;
	address = LcmLengthDots / 8 * Y_pos + X_pos + 0x0800;
	for(n = 0;n < 16;n++)                                  		//����ֵ16
    	{
		write_LCD_ddc(0x24,(uchar)(address),(uchar)(address>>8));  	//������ʾ�洢����ַ
		write_LCD_dc(0xc0,bmp_16[m++]);             		//д�뺺����ģ��
		write_LCD_dc(0xc0,bmp_16[m++]);               	  	//д�뺺����ģ�Ҳ�
		address = address + LcmLengthDots/8;                    //�޸���ʾ�洢����ַ����ʾ��һ��
	}
}

 void charprintf(unsigned char *bmp_16,uint X_pos,uint Y_pos)
{
	unsigned long int address;
	unsigned char m,n;
	m = 0;
	address = LcmLengthDots / 8 * Y_pos + X_pos + 0x0800;
	for(n = 0;n < 16;n++)                                  		//����ֵ16
    	{
		write_LCD_ddc(0x24,(uchar)(address),(uchar)(address>>8));  	//������ʾ�洢����ַ
		write_LCD_dc(0xc0,bmp_16[m++]);             		//д�뺺����ģ��

		address = address + LcmLengthDots/8;                    //�޸���ʾ�洢����ַ����ʾ��һ��
	}
}
