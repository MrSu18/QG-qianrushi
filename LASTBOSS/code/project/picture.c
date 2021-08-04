#include <reg52.h>
#include "������Ϸ.h"
#include "tuxiangku.h"

uint idata score[6]={0,0,0,0,0,0};

void mainmeun()//��Ϸ��ʼǰ�����˵�����
{
	LM4229_init();
	LM4229_clear();
	//���շ���
	dprintf(&Y_X_M[0],12,24);
	dprintf(&Y_X_M[32],14,24);
	dprintf(&Y_X_M[64],16,24);
	dprintf(&Y_X_M[96],18,24);
	dprintf(&Y_X_M[128],20,24);

	dprintf(test,10,20);
	dprintf(test,8,20);
	dprintf(test,9,20+15);
	//�˵�ѡ��
	dprintf(&new[0],11,55);
	dprintf(&new[32],13,55);
	dprintf(&new[64],15,55);//����Ϸ

	dprintf(&old[0],11,55+17);
	dprintf(&old[32],13,55+17);
	dprintf(&old[64],15,55+17);
	dprintf(&old[96],17,55+17);


	dprintf(&list[0],11,55+17+17);
	dprintf(&list[32],13,55+17+17);
	dprintf(&list[64],15,55+17+17);//���а�

}

void choosemenu(uchar x)
{
	dprintf(&choose[0],20,55+x*15);//ѡ���ͷ
}
void cachu(uchar x)//����ǰ���ͷ�ĺ���
{
	dprintf(&clear[0],20,55+x*15);
}
void gameinterface()//��������Ϸ�������
{
	int i;
	for(i=0;i<30;i=i+2)
	{
		dprintf(huafenhenxian,i,15);
	}

	dprintf(&diren[0],2,0);
	dprintf(&diren[32],4,0);//����

	dprintf(&qian[0],22,0);
	dprintf(&qian[32],24,0); //���

}

void youxixinxi(uchar a,uchar b,uchar bai,uchar shi,uchar ge)//��Ϸ����Ϣ
{
	charprintf(&shuzi[a*16],6,0);

	charprintf(&shuzi[b*16],14,0);

	charprintf(&shuzi[bai*16],26,0);
	charprintf(&shuzi[shi*16],27,0);
	charprintf(&shuzi[ge*16],28,0);
}

void first()//��һ�ص�ͼ
{
	int i;

	LM4229_clear();//����

	gameinterface();//����Ϸ������Ϣ����

	dprintf(enemyhome,2,56);
	dprintf(home,26,56+15);

	 //�ϰ��
	for(i=4;i<18;i=i+2)
	{
		dprintf(placed,i,56-15);
	}
	for(i=18;i<26;i=i+2)
	{
		dprintf(placed,i,56);
	}
	//�°��
	for(i=4;i<16;i=i+2)
	{
		dprintf(placed,i,56+15);
	}
	for(i=16;i<26;i=i+2)
	{
		dprintf(placed,i,56+30);
	}

	init_T0();//������ʱ��0׼���û��涯����
	initfirstmove();
	HP=3;
	direnshuliang=2; //��������Ϊ3
	jingbi=100;

	guangbiaox=1*2;
	guangbiaoy=3*2;
}

void shibaijiemian()//��Ϸʧ�ܽ���
{
	LM4229_clear();
	//��Ϸʧ��
	dprintf(&shibai[0],10,56);
	dprintf(&shibai[32],12,56);
	dprintf(&shibai[64],14,56);
	dprintf(&shibai[96],16,56);
}
void chengongjiemian()//��Ϸ�ɹ�����
{
	LM4229_clear();
	//��Ϸ�ɹ�
	dprintf(&chengong[0],10,56);
	dprintf(&chengong[32],12,56);
	dprintf(&chengong[64],14,56);
	dprintf(&chengong[96],16,56);
	dprintf(&chengong[128],18,56);
}

void paihanbang()//���а�ҳ��
{
	uchar i,j;
	LM4229_clear();
	Reeprom();
	for(i=0;i<5;i++)
	{
		for(j=0;j<3;j++)
		{
			charprintf(&paihan[j*16],8+j,31+i*15);
		}
		charprintf(&shuzi[(i+1)*16],8+j,31+i*15);
		paihanbangfenshu(i,j,score[i]);
	}
}

void paihanbangfenshu(uchar i,uchar j,uint p)
{
	charprintf(&shuzi[(p/1000)*16],10+j+1,31+i*15);
	charprintf(&shuzi[(p/100-p/1000*10)*16],10+j+2,31+i*15);
	charprintf(&shuzi[(p/10-p/100*10)*16],10+j+3,31+i*15);
	charprintf(&shuzi[0*16],10+j+4,31+i*15);
}

void jixuyouxi()//������Ϸ�����ѡ�ض����˵�
{
	uchar i;
	LM4229_clear();
	for(i=0;i<5;i++)
	{
		dprintf(&xuanguan[0*32],12,31+i*17);
		charprintf(&shuzi[(i+1)*16],14,31+i*17);
		dprintf(&xuanguan[1*32],15,31+i*17);
	}
}

//****************************************************
void second()//�ڶ��صĽ��溯��
{
	uchar i;

	LM4229_clear();

	youxifenqu();//��Ϸ��̬����

	dprintf(enemyhome,0,16*1);
	dprintf(home,12,16*7);

	//��Ϸ�ڵ�ͼ����
	for(i=0;i<6;i++)
	{
		dprintf(placed,2+i*2,0);
	}
	for(i=0;i<6;i++)
	{
		dprintf(placed,12,16+i*16);
	}
	for(i=0;i<4;i++)
	{
		dprintf(placed,2+i*2,16*2);
	}
	for(i=0;i<3;i++)
	{
		dprintf(placed,8,16*2+i*16);
	}
	for(i=0;i<3;i++)
	{
		dprintf(placed,6-i*2,16*4);
	}
	for(i=0;i<3;i++)
	{
		dprintf(placed,2,16*5+i*16);
	}
	for(i=0;i<3;i++)
	{
		dprintf(placed,6+i*2,16*6);
	}
}
//*****************************************************
//������
void third()//�����صĽ��溯��
{
	uchar i;

	LM4229_clear();

	youxifenqu();//��Ϸ��̬����

	//��Ϸ�ڵ�ͼ����
	dprintf(enemyhome,3*2,0*16);
	dprintf(home,3*2,16*7);

	dprintf(placed,2*2,16);
	dprintf(placed,4*2,16);//���ֵз������Ա�

	for(i=0;i<2;i++)
	{
		dprintf(placed,3*2,(i+3)*16);
	}//�м�����ʯͷ
	for(i=0;i<6;i++)
	{
		dprintf(placed,1*2,(i+1)*16);
		dprintf(placed,5*2,(i+1)*16);//��ͼ����Χ
	}
	dprintf(placed,2*2,6*16);
	dprintf(placed,4*2,6*16);//�ԳƵ��ҷ������ſڵ�ʯͷ
}

void youxifenqu()//��Ϸ�����غϽ��溯�������ٴ��븴����
{
	uchar i;
	//�����򻮷־�̬��Ϣ
	for(i=0;i<9;i++)
	{
		dprintf(huafenxian,14,i*14);
	}
	for(i=0;i<7;i++)
	{
		dprintf(huafenhenxian,16+i*2,56);
	}

	dprintf(&diren[0],16,0);
	dprintf(&diren[32],18,0);//����
	charprintf(&zifu[0*16],21,0);
	charprintf(&shuzi[direnshuliang*16],22,0);

	dprintf(&qian[0],16,18);
	dprintf(&qian[32],18,18); //���

	charprintf(&zifu[1*16],16,36);
	charprintf(&zifu[2*16],18,36);//HP

	for(i=0;i<3;i++)
	{
		dprintf(&daojulang[i*32],20+i*2,56+14);
	}//������
}

void youxixinxi2_0(HP,n,jingbi)//��������֮��Ĺؿ���Ϣ
{
	uchar s,b;

	s=jingbi/10-jingbi/100*10;
	b=jingbi/100;

	charprintf(&shuzi[n*16],20,0);

	charprintf(&shuzi[b*16],20,18);
	charprintf(&shuzi[s*16],21,18);
	charprintf(&shuzi[0],22,18);

	charprintf(&shuzi[HP*16],20,36);
}


