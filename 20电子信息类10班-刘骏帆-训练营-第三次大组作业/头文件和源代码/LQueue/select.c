#include <stdio.h>
#include <stdlib.h>
#include"../LQueue.h"

void select(LQueue *q,void *e)
{
	int opotion;
	while(1)
	{
		printf("�������ѡ�");
		while(scanf("%d",&opotion)==0||getchar()!='\n')
		{
			printf("�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		switch(opotion)
		{
		case 1:
			if(q->front!=NULL)
			{
				printf("�����ѳ�ʼ���������ʼ����\n");
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
				printf("��δ��ʼ�������ȳ�ʼ�����У�\n");
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
				printf("���еĳ���Ϊ��%d\n",i);
			}
			break;
		case 6:
			{
				if(q->front==NULL)
				{
					printf("��δ��ʼ�������ȳ�ʼ�����У�\n");
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
					//printf("���ʧ�ܣ�������ѡ��\n");
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
					//printf("���ʧ�ܣ�������ѡ��\n");
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
			printf("�˳�����\n ");
			system("pause");
			exit(0);
			break;
		default:
			printf("����������������룺\n");
			break;
		}
	}
}
