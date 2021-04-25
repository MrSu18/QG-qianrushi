#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"LQueue.h"
#include "binary_sort_tree.h"

void InitLQueue(LQueue *Q)//初始化
{
	Q->front=Q->rear=(Queuenode*)malloc(sizeof(Queuenode));
	if(Q->front==NULL)
	{
		printf("初始化失败，内存空间无法分配！\n");
	}
	else
	{
		Q->front->next=NULL;
		Q->length=0;
		printf("层序遍历所需队列初始化成功！\n");
	}
}


void DestoryLQueue(LQueue *Q)
{
	if(Q->front==NULL)
	{
		printf("还未初始化，请先初始化队列！\n");
	}
	else
	{
		Q->rear=Q->front->next;
		free(Q->front);
		Q->front=Q->rear;
		printf("队列销毁成功！\n");
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
		printf("还未初始化，请先初始化队列！\n");
		return ERROR;
	}
	else if(Q->length==0)
	{
		printf("队列为空！\n");
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

		//printf("入队元素为%d\n ",Q->front->N->value);

		Q->length++;
	}
	else
	{
		Queuenode* newnode=(Queuenode*)malloc(sizeof(Queuenode));
		newnode->N=data;

		//printf("入队元素为%d\n ",newnode->N->value);

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
		printf("还未初始化，请先初始化队列！\n");
		return ERROR;
	}
	else if(Q->length==0)
	{
		printf("队列为空！\n");
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
			Q->front=Q->rear=(Queuenode*)malloc(sizeof(Queuenode));//出队这里如果不MALLOC一个可能变成未初始化
		}
		Q->length--;
		return SUCCESS;
	}
}

