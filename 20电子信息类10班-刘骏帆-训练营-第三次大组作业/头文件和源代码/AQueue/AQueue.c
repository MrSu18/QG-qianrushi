#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"../AQueue.h"



void InitAQueue(AQueue *Q)//��ʼ��
{
	if(Q->data==NULL)
	{
		printf("��ʼ��ʧ��,�ڴ�ռ��޷����䣡\n");
	}
	Q->front=Q->rear=0;
        Q->length=0;
        for(int i=0;i<MAXQUEUE;i++)
		Q->data[i]=(void*)malloc(21);
	printf("��ʼ���ɹ�!\n");
}


void DestoryAQueue(AQueue *Q)//����
{
	if(Q->data[0]==NULL)
	{
		printf("��δ��ʼ�������ȳ�ʼ������\n");
	}
	else
	{
		for(int i=0;i<MAXQUEUE;i++)
			Q->data[i]=NULL;
		printf("˳�����������ϣ�\n");
	}
}

Status IsFullAQueue(const AQueue *Q)
{
	if(Q->data[0]==NULL)
	{
		printf("��δ��ʼ�������ȳ�ʼ������\n");
	}
	else if((Q->rear+1)%MAXQUEUE==Q->front)//�ⲽ�ж�ѭ����������Ĺؼ�������֮��ֻҪ�������Ӳ������ͷ�ߵ����ﶼ������֮�������
	{
		printf("���������޷���ӣ�\n");
		return TRUE;
	}
	else
	{
		printf("����δ��\n");
		return FALSE;
	}
}



Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q->data[0]==NULL)
	{
		printf("��δ��ʼ�������ȳ�ʼ������\n");
	}
	else if(Q->rear==Q->front)
	{
		printf("����Ϊ�նӣ�\n");
		return TRUE;
	}
	else
	{
		printf("���в�Ϊ�ն�\n");
		return FALSE;
	}
}





Status GetHeadAQueue(AQueue *Q, void *e)
{
	if(Q->data[0]==NULL)
	{
		printf("��δ��ʼ�������ȳ�ʼ������\n");
		return FALSE;
	}
	else if(Q->rear==Q->front)
	{
		printf("û�ж�ͷԪ��\n");
		return FALSE;
	}
	else
	{
		//printf("test");
		memcpy(e,Q->data[Q->front],typesize[Q->front]);
		printf("��ͷԪ��Ϊ��");
		APrint(e,Q->front);
		printf("\n");
		return TRUE;
	}
}


Status EnAQueue(AQueue *Q, void *data)
{

		memcpy(Q->data[Q->rear],data,typesize[Q->rear]);
		Q->rear=(Q->rear+1)%MAXQUEUE;
		Q->length++;
		printf("Ԫ����ӳɹ�!\n");
		return TRUE;
}



Status DeAQueue(AQueue *Q)
{
	if(Q->data[0]==NULL)
	{
		printf("��δ��ʼ�������ȳ�ʼ������\n");
		return FALSE;
	}
	else if(Q->rear==Q->front)
	{
		printf("����Ϊ�նӣ�\n");
		return FALSE;
	}
	else
	{
		Q->front=((Q->front+1)%MAXQUEUE);
		Q->length--;
		printf("���ӳɹ���\n");
		return TRUE;
	}
}

int LengthAQueue(AQueue *Q)
{
	if(Q->data[0]==NULL)
	{
		printf("��δ��ʼ�������ȳ�ʼ������\n");
		return FALSE;
	}
	else
	{
		//int len;
		//length==Q->length;
		//printf("���еĳ���Ϊ��%d"��Q->length);
		return Q->length;
	}
}


void ClearAQueue(AQueue *Q)
{
	if(Q->data[0]==NULL)
	{
		printf("��δ��ʼ�������ȳ�ʼ������\n");
		return FALSE;
	}
	else if(Q->rear==Q->front)
	{
		printf("����Ϊ�նӣ����������\n");
		return FALSE;
	}
	else
	{
		Q->length=Q->front=Q->rear=0;
		printf("�����������\n");
	}
}



Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q,int count))
{
	if(Q->data[0]==NULL)
	{
		printf("��δ��ʼ�������ȳ�ʼ������\n");
		return FALSE;
	}
	else if(Q->rear==Q->front)
	{
		printf("����Ϊ�նӣ�\n");
		return FALSE;
	}
	else
	{
		for(int i =Q->front,j=Q->length;j>0;j--)
		{
			//printf("test");
			foo(Q->data[i],i);
			printf(",");
			i=(i+1)%MAXQUEUE;
		}
		return TRUE;
	}
}


void APrint(void *q,int count)//�жϷ������ͺ���
{
	if (datatype[count]=='i')
		printf("%d",*(int*)q);
	else if(datatype[count]=='f')
		printf("%f",*(float*)q);
	else if(datatype[count]=='c')
		printf("%c",*(char*)q);
	else if(datatype[count]=='s')
		{
			printf("%s",(char*)q);
			//printf(",");
		}
	else
	{
		;
	}

}

void scanftype(AQueue *Q)
{
	printf("��������Ҫ��������ݣ�\n");
	if(datatype[Q->rear]=='i')
	{
		int a ;
		while(scanf("%d",&a)==0||getchar()!='\n')
		{
			printf("�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		//scanf("%d",&a);
		EnAQueue(Q,&a);
	}
	else if(datatype[Q->rear]=='f')
	{
		float a ;
		while(scanf("%f",&a)==0||getchar()!='\n')
		{
			printf("�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		//scanf("%f",&a);
		EnAQueue(Q,&a);
	}
	else if(datatype[Q->rear]=='c')
	{
		char a ;
		while(scanf("%c",&a)==0||getchar()!='\n')
		{
			printf("�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		//scanf("%c",&a);
		EnAQueue(Q,&a);
	}
	else if(datatype[Q->rear]=='s')
	{
		char a[100];
		gets(a);
		//scanf("%s",a);
		EnAQueue(Q,a);
	}
	else
	{
		;
	}
}


void gettype(AQueue*q)//�õ����ͺ���;
{
	int n;
	printf("�������ѡ�");
	while(scanf("%d",&n)==0||getchar()!='\n')
	{
		printf("�����˷Ƿ��ַ������������룺");
		while (getchar() != '\n');
	}
	switch(n)
	{
	case 1:
		//printf("test");
		type ='i';
		typesize[q->rear]=sizeof(int);
		datatype[q->rear]=type;
		printf("���ͱ�����Ϊ����\n");
		break;
	case 2:
		type ='f';
		typesize[q->rear]=sizeof(float);
		datatype[q->rear]=type;
		printf("���ͱ�����Ϊ������\n");
		break;
	case 3:
		type='c';
		typesize[q->rear]=sizeof(char);
		datatype[q->rear]=type;
		printf("���ͱ�����Ϊ�ַ���\n");
		break;
	case 4:
		type='s';
		typesize[q->rear]=sizeof(char)*100;
		datatype[q->rear]=type;
		printf("���ͱ�����Ϊ�ַ���\n");
		break;
	default:
		printf("����������ʧ��\n");
	}
}
