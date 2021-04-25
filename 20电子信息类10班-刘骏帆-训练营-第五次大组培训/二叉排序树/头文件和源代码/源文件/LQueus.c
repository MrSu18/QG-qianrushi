#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"LQueue.h"
#include "binary_sort_tree.h"

void InitLQueue(LQueue *Q)//��ʼ��
{
	Q->front=Q->rear=(Queuenode*)malloc(sizeof(Queuenode));
	if(Q->front==NULL)
	{
		printf("��ʼ��ʧ�ܣ��ڴ�ռ��޷����䣡\n");
	}
	else
	{
		Q->front->next=NULL;
		Q->length=0;
		printf("�������������г�ʼ���ɹ���\n");
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
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
}


Status GetHeadLQueue(LQueue *Q, NodePtr *top)
{
	if(Q->front==NULL)
	{
		printf("��δ��ʼ�������ȳ�ʼ�����У�\n");
		return ERROR;
	}
	else if(Q->length==0)
	{
		printf("����Ϊ�գ�\n");
		return ERROR;
	}
	else
	{
		*top=Q->front->N;
		return SUCCESS;
	}
}



Status EnLQueue(LQueue *Q, NodePtr data)
{
	if(Q->length==0)
	{
		Q->front->N=data;

		//printf("���Ԫ��Ϊ%d\n ",Q->front->N->value);

		Q->length++;
	}
	else
	{
		Queuenode* newnode=(Queuenode*)malloc(sizeof(Queuenode));
		newnode->N=data;

		//printf("���Ԫ��Ϊ%d\n ",newnode->N->value);

		newnode->next=NULL;
		Q->rear->next=newnode;
		Q->rear=newnode;
		Q->length++;
	}
	return SUCCESS;
}

Status DeLQueue(LQueue *Q)
{
	if(Q->front==NULL)
	{
		printf("��δ��ʼ�������ȳ�ʼ�����У�\n");
		return ERROR;
	}
	else if(Q->length==0)
	{
		printf("����Ϊ�գ�\n");
		return ERROR;
	}
	else
	{
		Queuenode*p;
		p=Q->front;
		Q->front=p->next;
		free(p);
		if(Q->front==NULL)
		{
			Q->front=Q->rear=(Queuenode*)malloc(sizeof(Queuenode));//�������������MALLOCһ�����ܱ��δ��ʼ��
		}
		Q->length--;
		return SUCCESS;
	}
}

