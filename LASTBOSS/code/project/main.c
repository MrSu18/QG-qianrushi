#include <reg52.h>
#include <intrins.h>
#include "������Ϸ.h"

uchar receive_data;

uchar flag=0;//������T0��ʱ���Ƿ��ж���һ����ǣ��ﵽ��ʱ2S������
uchar idata flagchoose;

uchar idata direnx;
uchar idata direny;//���˵�λ��xy�ö�ʱ���жϿ��Ƶ����ƶ�
uchar idata direnhp;

uchar idata direnshuliang; //��������

uchar idata HP;//����Ѫ��
uint idata jingbi;//�������
uint idata defen=0;//�û��ĵ÷�
uchar idata jieshuflag=0;//���������Ϸ�Ƿ����

uchar guangbiaox;
uchar guangbiaoy;//�������xy

void main()
{
	uchar flagchoose=0;//������Ǽ�ͷλ�õ�

	mainmeun();
	choosemenu(0);

	init_R();
	init_EEPROM();
	Reeprom();//�Ȱ����ݶ������ŵ���������
	meun(flagchoose);
	while(1);
}
