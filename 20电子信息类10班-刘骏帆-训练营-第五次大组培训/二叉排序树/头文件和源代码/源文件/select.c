#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"

void select (BinarySortTreePtr P)
{
	meun();
	printf("���ѡ���ǣ�");
	int opotion;
	while(scanf("%d",&opotion)==0||getchar()!='\n')
	{
		printf("�Ƿ����룬���������룺\n");
		while (getchar()!='\n');
	}
	switch (opotion)
	{
	case 1:
	{
		if(flag!=0)
		{
			printf("�Ѿ���ʼ����\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		else
		{
			BST_init(P);
			flag++;
		}

		//��������
		system("pause");
		system("cls");
		select (P);
		break;
	}
	case 2:
	{
		if(flag==0)
		{
			printf("��δ��ʼ����\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		ElemType data;
		printf("��������Ҫ��������ݣ�");
		while(scanf("%d",&data)==0||getchar()!='\n')
		{
			printf("�Ƿ����룬���������룺");
			while(getchar()!='\n');
		}
		BST_insert(P,data);

		//��������
		system("pause");
		system("cls");
		select (P);
		break;
	}
	case 3:
		if(flag==0)
		{
			printf("��δ��ʼ����\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		ElemType data;
		printf("��������Ҫɾ�������ݣ�");
		while(scanf("%d",&data)==0||getchar()!='\n')
		{
			printf("�Ƿ����룬���������룺");
			while(getchar()!='\n');
		}
		BST_delete(P,&P->root,data);

		//��������
		system("pause");
		system("cls");
		select (P);
		break;
	case 4:
		if(flag==0)
		{
			printf("��δ��ʼ����\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		ElemType temp;
		printf("��������Ҫ��Ѱ�����ݣ�");
		while(scanf("%d",&temp)==0||getchar()!='\n')
		{
			printf("�Ƿ����룬���������룺");
			while(getchar()!='\n');
		}
		BST_search(P->root,temp);

		//��������
		system("pause");
		system("cls");
		select (P);
		break;

	case 5:
		if(flag==0)
		{
			printf("��δ��ʼ����\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		BST_preorderR(P,visit);

		//��������
		system("pause");
		system("cls");
		select (P);
		break;
	case 6:
		if(flag==0)
		{
			printf("��δ��ʼ����\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		BST_inorderR(P,visit);

		//��������
		system("pause");
		system("cls");
		select (P);
		break;
	case 7:
		if(flag==0)
		{
			printf("��δ��ʼ����\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		BST_postorderR(P,visit);

		//��������
		system("pause");
		system("cls");
		select (P);
		break;
	case 8:
		if(flag==0)
		{
			printf("��δ��ʼ����\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		BST_preorderI(P,visit);

		//��������
		system("pause");
		system("cls");
		select (P);
		break;
	case 9:
		if(flag==0)
		{
			printf("��δ��ʼ����\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		BST_inorderI(P,visit);

		//��������
		system("pause");
		system("cls");
		select (P);
		break;
	case 10:
		if(flag==0)
		{
			printf("��δ��ʼ����\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		BST_postorderI(P,visit);

		//��������
		system("pause");
		system("cls");
		select (P);
		break;
	case 11:
		if(flag==0)
		{
			printf("��δ��ʼ����\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		BST_levelOrder(P,visit);

		//��������
		system("pause");
		system("cls");
		select (P);
		break;
	case 0:
		printf("�����˳�����\n");
		system("pause");
		exit(0);
		break;
	default:
		printf("�Ƿ����룬���������룺");
		system("pause");
		system("cls");
		select (P);
		break;
	}
}
