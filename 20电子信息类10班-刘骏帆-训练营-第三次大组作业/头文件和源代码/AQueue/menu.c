#include <stdio.h>
#include <stdlib.h>
#include"../AQueue.h"

void menu(AQueue *q,void *e)
{
	int opotion;
	//typemenu();
	//gettype();
	//printf("选择成功，接下来可以使用队列功能！\n\n");
	while(1)
	{
		printf("输入你的选项：");
		while(scanf("%d",&opotion)==0||getchar()!='\n')
		{
			printf("输入了非法字符，请重新输入：");
			while (getchar() != '\n');
		}
		switch(opotion)
		{
		case 1:
			if(q->data[0]!=NULL)
			{
				printf("队列已经初始化，请继续操作！\n");
			}
			else
			{
				InitAQueue(q);
			}
			break;
		case 2:
			DestoryAQueue(q);
			break;
		case 3:
			IsFullAQueue(q);
			break;

		case 4:
			IsEmptyAQueue(q);
			break;
		case 5:
			GetHeadAQueue(q,e);
			break;
		case 6:
			{
				int i ;
				i=LengthAQueue(q);
				printf("队列的长度为：%d\n",i);
				break;

			}
		case 7:
			if(q->data[0]==NULL)
			{
				printf("还未初始化，请先初始化队列\n");
			}
			else if((q->rear+1)%MAXQUEUE==q->front)
			{
				printf("队列满队，无法入队\n");
			}
			else
			{
				system("cls");
				typemenu();
				gettype(q);
				scanftype(q);
				system("pause");
				system("cls");
				jiemian();
			}
			break;
		case 8:
			DeAQueue(q);
			break;
		case 9:
			ClearAQueue(q);
			break;
		case 10:
			printf("遍历队列为：");
			TraverseAQueue(q,APrint);
			printf("\n");
			break;
		case 11:
			system("cls");
			jiemian();
			break;
		case 0:
			printf("退出程序！\n ");
			system("pause");
			exit(0);
			break;
		default:
			printf("输入错误，请重新输入：\n");
			break;
		}

	}
}
