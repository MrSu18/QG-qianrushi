#ifndef yaokongqi_H_INCLUDED
#define yaokongqi_H_INCLUDED

#define uchar unsigned char
#define uint unsigned int

extern uchar send_data;
extern uchar receive_data;
//*************************************
//ͨ�ú���
void delay_ms(uint i);//��ʱms����
//************************************
//����
#define key P2

void matrixkeyscan();//�������ɨ�躯��0
//************************************
//˫��ͨ�ź���
void send ();//���ͼ���ֵ
void init();//���ͷ���ʼ������
void ser();//��ʱ���ж�

//***********************************
//��������������
void bofangyingyue();

#endif // ң����_H_INCLUDED
