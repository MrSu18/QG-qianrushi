#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"../LQueue.h"

void InitLQueue(LQueue *Q)//��ʼ��
{
	Q->front=Q->rear=(Node*)malloc(sizeof(Node));
	if(Q->front==NULL)
	{
		printf("��ʼ��ʧ�ܣ��ڴ�ռ��޷����䣡\n");
	}
	else
	{
		Q->front->next=NULL;
		Q->length=0;
		printf("��ʼ���ɹ���\n");
	}
}


void DestoryLQueue(LQueue *Q)
{
	if(Q->front==NULL)
	{
		printf("��δ��ʼ�������ȳ�ʼ�����У�\n");
	}
	else
	{
		Q->rear=Q->front->next;
		free(Q->front);
		Q->front=Q->rear;
		printf("�������ٳɹ���\n");
	}
}



Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->length==0)
	{
		printf("����Ϊ�գ�\n");
		return TRUE;
	}
	else
	{
		printf("���в�Ϊ�գ�");
		return FALSE;
	}
}


Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q->front==NULL)
	{
		printf("��δ��ʼ�������ȳ�ʼ�����У�\n");
		return FALSE;
	}
	else if(Q->length==0)
	{
		printf("����Ϊ�գ�\n");
		return FALSE;
	}
	else
	{
		memcpy(e,Q->front->data,Q->front->typesize);
		printf("��ͷԪ��Ϊ��");
		LPrint(e,Q->front);
		printf("\n");
		return TRUE;
	}
}

int LengthLQueue(LQueue *Q)
{
	if(Q->front==NULL)
	{
		printf("��δ��ʼ�������ȳ�ʼ�����У�\n");
		return FALSE;
	}
	else
	{
		return Q->length;
	}
}

Status EnLQueue(LQueue *Q, void *data,Node*p)
{
	if(Q->length==0)
	{
		Q->front->data=(void*)malloc(Q->front->typesize);//�������˸����������Ҳmallocһ�²�Ȼ�洢Ϊ�ַ�����ʱ����ܻ����
		memcpy(Q->front->data,data,Q->front->typesize);
		Q->length++;
		printf("Ԫ����ӳɹ���\n");
	}
	else
	{
		p->data=(void*)malloc(p->typesize);//
		memcpy(p->data,data,p->typesize);
		//printf("\n%d\n",*(int*)Q->front->data);
		//printf("\n%d\n",*(int*)Q->rear->data);
		//printf("\n%d\n",*(int*)data);
		//printf("\n%d\n",*(int*)p->data);
		p->next=NULL;
		Q->rear->next=p;
		Q->rear=p;
		Q->length++;
		printf("Ԫ����ӳɹ���\n");
	}
	return TRUE;
}

Status DeLQueue(LQueue *Q)
{
	if(Q->front==NULL)
	{
		printf("��δ��ʼ�������ȳ�ʼ�����У�\n");
		return FALSE;
	}
	else if(Q->length==0)
	{
		printf("����Ϊ�գ�\n");
		return FALSE;
	}
	else
	{
		Node*p;
		p=Q->front;
		Q->front=p->next;
		free(p);
		if(Q->front==NULL)
		{
			Q->front=Q->rear=(Node*)malloc(sizeof(Node));//�������������MALLOCһ�����ܱ��δ��ʼ��
		}
		Q->length--;
		printf("Ԫ�س��ӳɹ���\n");
		return TRUE;
	}
}


void ClearLQueue(LQueue *Q)
{
	if(Q->front==NULL)
	{
		printf("��δ��ʼ�������ȳ�ʼ�����У�\n");
		return FALSE;
	}
	else if(Q->length==0)
	{
		printf("����Ϊ�գ�\n");
		return FALSE;
	}
	else
	{


		Node* p,*q;
		q=p=Q->front;
		Q->front=Q->rear=(Node*)malloc(sizeof(Node));
		Q->front->next=NULL;
		Q->rear=Q->front;
		//printf("test");
		while(p->next!=NULL)
		{
			p=p->next;
			free(q);
			q=p;
		}
		free(p);
		p=q=NULL;
		Q->length=0;
		printf("�����ѱ���գ�\n");
		return TRUE;
	}
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,Node*p))
{
	if(Q->front==NULL)
	{
		printf("��δ��ʼ�������ȳ�ʼ�����У�\n");
		return FALSE;
	}
	else if(Q->length==0)
	{
		printf("����Ϊ�գ�\n");
		return FALSE;
	}
	else
	{
		printf("��������Ϊ��\n");
		//printf("test");
		Node*temp;
		temp=Q->front;
		while(temp!=NULL)
		{
			//printf("test");

			//printf("%c",temp->type);
			//printf("%d",*(int*)temp->data);
			foo(temp->data,temp);
			temp=temp->next;
			printf("��");
		}
		return TRUE;
	}
}


//*****************************************************************************************
//�����Ƿ��ͺ���
void gettype(Node*p)//�õ����ͺ���;
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
		p->type ='i';
		p->typesize=sizeof(int);
		printf("���ͱ�����Ϊ����\n");
		break;
	case 2:
		p->type ='f';
		p->typesize=sizeof(float);
		printf("���ͱ�����Ϊ������\n");
		break;
	case 3:
		p->type='c';
		p->typesize=sizeof(char);
		printf("���ͱ�����Ϊ�ַ���\n");
		break;
	case 4:
		p->type='s';
		p->typesize=sizeof(char)*100;
		printf("���ͱ�����Ϊ�ַ���\n");
		break;
	default:
		printf("����������ʧ��\n");
	}
}



void scanftype(LQueue *Q,Node*p)
{
	printf("��������Ҫ��������ݣ�\n");
	if(p->type=='i')
	{
		int a ;
		while(scanf("%d",&a)==0||getchar()!='\n')
		{
			printf("�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		//printf("%d",a);
		//scanf("%d",&a);
		EnLQueue(Q,&a,p);
	}
	else if(p->type=='f')
	{
		float a ;
		while(scanf("%f",&a)==0||getchar()!='\n')
		{
			printf("�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		//scanf("%f",&a);
		EnLQueue(Q,&a,p);
	}
	else if(p->type=='c')
	{
		char a ;
		while(scanf("%c",&a)==0||getchar()!='\n')
		{
			printf("�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		//scanf("%c",&a);
		EnLQueue(Q,&a,p);
	}
	else if(p->type=='s')
	{
		char a[100];
		gets(a);
		//scanf("%s",a);
		EnLQueue(Q,a,p);
	}
	else
	{
		;
	}
}


void LPrint(void *q,Node*p)//����������ͺ���
{
	if ((p->type)=='i')
		printf("%d",*(int*)q);
	else if((p->type)=='f')
		printf("%f",*(float*)q);
	else if((p->type)=='c')
		printf("%c",*(char*)q);
	else if((p->type)=='s')
		puts((char*)q);
		//printf("%s",(char*)q);
	else
	{
		printf("����\n");
	}

}
