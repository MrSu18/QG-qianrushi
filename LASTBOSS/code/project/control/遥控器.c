#include<reg52.h>
#include"遥控器.h"
void matrixkeyscan()//矩阵键盘扫描函数0
{
	uchar temp;
	temp=key;
	if(key!=0xff)
	{
		while(key!=0xff);//检测键盘释放
		switch(temp)
		{
		case 0xfe:
			send_data='l';
			send();
			send_data=0;//与接收同理发完就置0
			break;
		case 0xfd:
			send_data='u';
			send();
			send_data=0;//与接收同理发完就置0
			break;
		case 0xfb:
			send_data='r';
			send();
			send_data=0;//与接收同理发完就置0
			break;
		case 0xf7:
			send_data='d';
			send();
			send_data=0;//与接收同理发完就置0
			break;
		case 0xef:
			send_data='y';
			send();
			send_data=0;//与接收同理发完就置0
			break;
		case 0xdf:
			send_data='n';
			send();
			send_data=0;//与接收同理发完就置0
			break;
		case 0xbf:
			send_data='m';//remake
			send();
			send_data=0;//与接收同理发完就置0
			break;
		default:break;
		}
	}
}
