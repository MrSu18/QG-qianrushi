#include <stdio.h>
#include <stdlib.h>
#include"../AQueue.h"

void menu(AQueue *q,void *e)
{
	int opotion;
	//typemenu();
	//gettype();
	//printf("ѡ��ɹ�������������ʹ�ö��й��ܣ�\n\n");
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
			if(q->data[0]!=NULL)
			{
				printf("�����Ѿ���ʼ���������������\n");
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
				printf("���еĳ���Ϊ��%d\n",i);
				break;

			}
		case 7:
			if(q->data[0]==NULL)
			{
				printf("��δ��ʼ�������ȳ�ʼ������\n");
			}
			else if((q->rear+1)%MAXQUEUE==q->front)
			{
				printf("�������ӣ��޷����\n");
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
			printf("��������Ϊ��");
			TraverseAQueue(q,APrint);
			printf("\n");
			break;
		case 11:
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
