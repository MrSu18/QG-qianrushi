#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"../LQueue.h"

void InitLQueue(LQueue *Q)//初始化
{
	Q->front=Q->rear=(Node*)malloc(sizeof(Node));
	if(Q->front==NULL)
	{
		printf("初始化失败，内存空间无法分配！\n");
	}
	else
	{
		Q->front->next=NULL;
		Q->length=0;
		printf("初始化成功！\n");
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
		printf("队列为空！\n");
		return TRUE;
	}
	else
	{
		printf("队列不为空！");
		return FALSE;
	}
}


Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q->front==NULL)
	{
		printf("还未初始化，请先初始化队列！\n");
		return FALSE;
	}
	else if(Q->length==0)
	{
		printf("队列为空！\n");
		return FALSE;
	}
	else
	{
		memcpy(e,Q->front->data,Q->front->typesize);
		printf("队头元素为：");
		LPrint(e,Q->front);
		printf("\n");
		return TRUE;
	}
}

int LengthLQueue(LQueue *Q)
{
	if(Q->front==NULL)
	{
		printf("还未初始化，请先初始化队列！\n");
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
		Q->front->data=(void*)malloc(Q->front->typesize);//别忘记了给这里的数据也malloc一下不然存储为字符串的时候可能会出事
		memcpy(Q->front->data,data,Q->front->typesize);
		Q->length++;
		printf("元素入队成功！\n");
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
		printf("元素入队成功！\n");
	}
	return TRUE;
}

Status DeLQueue(LQueue *Q)
{
	if(Q->front==NULL)
	{
		printf("还未初始化，请先初始化队列！\n");
		return FALSE;
	}
	else if(Q->length==0)
	{
		printf("队列为空！\n");
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
			Q->front=Q->rear=(Node*)malloc(sizeof(Node));//出队这里如果不MALLOC一个可能变成未初始化
		}
		Q->length--;
		printf("元素出队成功！\n");
		return TRUE;
	}
}


void ClearLQueue(LQueue *Q)
{
	if(Q->front==NULL)
	{
		printf("还未初始化，请先初始化队列！\n");
		return FALSE;
	}
	else if(Q->length==0)
	{
		printf("队列为空！\n");
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
		printf("队列已被清空！\n");
		return TRUE;
	}
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,Node*p))
{
	if(Q->front==NULL)
	{
		printf("还未初始化，请先初始化队列！\n");
		return FALSE;
	}
	else if(Q->length==0)
	{
		printf("队列为空！\n");
		return FALSE;
	}
	else
	{
		printf("遍历队列为：\n");
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
			printf("，");
		}
		return TRUE;
	}
}


//*****************************************************************************************
//以下是泛型函数
void gettype(Node*p)//得到泛型函数;
{
	int n;
	printf("输入你的选项：");
	while(scanf("%d",&n)==0||getchar()!='\n')
	{
		printf("输入了非法字符，请重新输入：");
		while (getchar() != '\n');
	}
	switch(n)
	{
	case 1:
		p->type ='i';
		p->typesize=sizeof(int);
		printf("类型被定义为整型\n");
		break;
	case 2:
		p->type ='f';
		p->typesize=sizeof(float);
		printf("类型被定义为浮点型\n");
		break;
	case 3:
		p->type='c';
		p->typesize=sizeof(char);
		printf("类型被定义为字符型\n");
		break;
	case 4:
		p->type='s';
		p->typesize=sizeof(char)*100;
		printf("类型被定义为字符串\n");
		break;
	default:
		printf("输入错误，入队失败\n");
	}
}



void scanftype(LQueue *Q,Node*p)
{
	printf("请输入你要输入的数据：\n");
	if(p->type=='i')
	{
		int a ;
		while(scanf("%d",&a)==0||getchar()!='\n')
		{
			printf("输入了非法字符，请重新输入：");
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
			printf("输入了非法字符，请重新输入：");
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
			printf("输入了非法字符，请重新输入：");
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


void LPrint(void *q,Node*p)//输出泛型类型函数
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
		printf("出错\n");
	}

}
