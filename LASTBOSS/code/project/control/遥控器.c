#include<reg52.h>
#include"ң����.h"
void matrixkeyscan()//�������ɨ�躯��0
{
	uchar temp;
	temp=key;
	if(key!=0xff)
	{
		while(key!=0xff);//�������ͷ�
		switch(temp)
		{
		case 0xfe:
			send_data='l';
			send();
			send_data=0;//�����ͬ�������0
			break;
		case 0xfd:
			send_data='u';
			send();
			send_data=0;//�����ͬ�������0
			break;
		case 0xfb:
			send_data='r';
			send();
			send_data=0;//�����ͬ�������0
			break;
		case 0xf7:
			send_data='d';
			send();
			send_data=0;//�����ͬ�������0
			break;
		case 0xef:
			send_data='y';
			send();
			send_data=0;//�����ͬ�������0
			break;
		case 0xdf:
			send_data='n';
			send();
			send_data=0;//�����ͬ�������0
			break;
		case 0xbf:
			send_data='m';//remake
			send();
			send_data=0;//�����ͬ�������0
			break;
		default:break;
		}
	}
}
