#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"../AQueue.h"



void InitAQueue(AQueue *Q)//初始化
{
	if(Q->data==NULL)
	{
		printf("初始化失败,内存空间无法分配！\n");
	}
	Q->front=Q->rear=0;
        Q->length=0;
        for(int i=0;i<MAXQUEUE;i++)
		Q->data[i]=(void*)malloc(21);
	printf("初始化成功!\n");
}


void DestoryAQueue(AQueue *Q)//销毁
{
	if(Q->data[0]==NULL)
	{
		printf("还未初始化，请先初始化队列\n");
	}
	else
	{
		for(int i=0;i<MAXQUEUE;i++)
			Q->data[i]=NULL;
		printf("顺序队列销毁完毕！\n");
	}
}

Status IsFullAQueue(const AQueue *Q)
{
	if(Q->data[0]==NULL)
	{
		printf("还未初始化，请先初始化队列\n");
	}
	else if((Q->rear+1)%MAXQUEUE==Q->front)//这步判断循环队列里面的关键，求余之后，只要你是满队不管你队头走到那里都是求余之后的余数
	{
		printf("队列已满无法入队！\n");
		return TRUE;
	}
	else
	{
		printf("队列未满\n");
		return FALSE;
	}
}



Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q->data[0]==NULL)
	{
		printf("还未初始化，请先初始化队列\n");
	}
	else if(Q->rear==Q->front)
	{
		printf("队列为空队！\n");
		return TRUE;
	}
	else
	{
		printf("队列不为空队\n");
		return FALSE;
	}
}





Status GetHeadAQueue(AQueue *Q, void *e)
{
	if(Q->data[0]==NULL)
	{
		printf("还未初始化，请先初始化队列\n");
		return FALSE;
	}
	else if(Q->rear==Q->front)
	{
		printf("没有队头元素\n");
		return FALSE;
	}
	else
	{
		//printf("test");
		memcpy(e,Q->data[Q->front],typesize[Q->front]);
		printf("队头元素为：");
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
		printf("元素入队成功!\n");
		return TRUE;
}



Status DeAQueue(AQueue *Q)
{
	if(Q->data[0]==NULL)
	{
		printf("还未初始化，请先初始化队列\n");
		return FALSE;
	}
	else if(Q->rear==Q->front)
	{
		printf("队列为空队！\n");
		return FALSE;
	}
	else
	{
		Q->front=((Q->front+1)%MAXQUEUE);
		Q->length--;
		printf("出队成功！\n");
		return TRUE;
	}
}

int LengthAQueue(AQueue *Q)
{
	if(Q->data[0]==NULL)
	{
		printf("还未初始化，请先初始化队列\n");
		return FALSE;
	}
	else
	{
		//int len;
		//length==Q->length;
		//printf("队列的长度为：%d"，Q->length);
		return Q->length;
	}
}


void ClearAQueue(AQueue *Q)
{
	if(Q->data[0]==NULL)
	{
		printf("还未初始化，请先初始化队列\n");
		return FALSE;
	}
	else if(Q->rear==Q->front)
	{
		printf("队列为空队，无需清除！\n");
		return FALSE;
	}
	else
	{
		Q->length=Q->front=Q->rear=0;
		printf("队列清理完毕\n");
	}
}



Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q,int count))
{
	if(Q->data[0]==NULL)
	{
		printf("还未初始化，请先初始化队列\n");
		return FALSE;
	}
	else if(Q->rear==Q->front)
	{
		printf("队列为空队！\n");
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


void APrint(void *q,int count)//判断泛型类型函数
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
	printf("请输入你要输入的数据：\n");
	if(datatype[Q->rear]=='i')
	{
		int a ;
		while(scanf("%d",&a)==0||getchar()!='\n')
		{
			printf("输入了非法字符，请重新输入：");
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
			printf("输入了非法字符，请重新输入：");
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
			printf("输入了非法字符，请重新输入：");
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


void gettype(AQueue*q)//得到泛型函数;
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
		//printf("test");
		type ='i';
		typesize[q->rear]=sizeof(int);
		datatype[q->rear]=type;
		printf("类型被定义为整型\n");
		break;
	case 2:
		type ='f';
		typesize[q->rear]=sizeof(float);
		datatype[q->rear]=type;
		printf("类型被定义为浮点型\n");
		break;
	case 3:
		type='c';
		typesize[q->rear]=sizeof(char);
		datatype[q->rear]=type;
		printf("类型被定义为字符型\n");
		break;
	case 4:
		type='s';
		typesize[q->rear]=sizeof(char)*100;
		datatype[q->rear]=type;
		printf("类型被定义为字符串\n");
		break;
	default:
		printf("输入错误，入队失败\n");
	}
}
