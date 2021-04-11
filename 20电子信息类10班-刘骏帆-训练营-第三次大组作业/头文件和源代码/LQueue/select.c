#include <stdio.h>
#include <stdlib.h>
#include"../LQueue.h"

void select(LQueue *q,void *e)
{
	int opotion;
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
			if(q->front!=NULL)
			{
				printf("队列已初始化，无需初始化！\n");
			}
			else
			{
				InitLQueue(q);
			}
			break;
		case 2:
			DestoryLQueue(q);
			break;
		case 3:
			if(q->front==NULL)
			{
				printf("还未初始化，请先初始化队列！\n");
			}
			else
			{
				IsEmptyLQueue(q);
			}
			break;

		case 4:
			GetHeadLQueue(q, e);
			break;
		case 5:
			{
				int i;
				i =LengthLQueue(q);
				printf("队列的长度为：%d\n",i);
			}
			break;
		case 6:
			{
				if(q->front==NULL)
				{
					printf("还未初始化，请先初始化队列！\n");
				}
				else if(q->length==0)
				{
					Node*p=q->front;
					system("cls");
					typemenu();
					gettype(p);
					scanftype(q,p);
					system("pause");
					system("cls");
					jiemian();
					//printf("入队失败，请重新选择：\n");
				}
				else
				{
					Node*new=(Node*)malloc(sizeof(Node));
					system("cls");
					typemenu();
					gettype(new);
					scanftype(q,new);
					system("pause");
					system("cls");
					jiemian();
					//printf("入队失败，请重新选择：\n");
				}
			}
                        break;
		case 7:
			DeLQueue(q);
			break;
		case 8:
			ClearLQueue(q);
			break;
		case 9:
			//printf("test");
			TraverseLQueue(q,LPrint);
			printf("\n");
			break;

		case 10:
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
