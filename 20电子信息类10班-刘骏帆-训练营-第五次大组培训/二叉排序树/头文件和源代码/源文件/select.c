#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"

void select (BinarySortTreePtr P)
{
	meun();
	printf("你的选项是：");
	int opotion;
	while(scanf("%d",&opotion)==0||getchar()!='\n')
	{
		printf("非法输入，请重新输入：\n");
		while (getchar()!='\n');
	}
	switch (opotion)
	{
	case 1:
	{
		if(flag!=0)
		{
			printf("已经初始化！\n");
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

		//交互界面
		system("pause");
		system("cls");
		select (P);
		break;
	}
	case 2:
	{
		if(flag==0)
		{
			printf("树未初始化！\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		ElemType data;
		printf("请输入你要插入的数据：");
		while(scanf("%d",&data)==0||getchar()!='\n')
		{
			printf("非法输入，请重新输入：");
			while(getchar()!='\n');
		}
		BST_insert(P,data);

		//交互界面
		system("pause");
		system("cls");
		select (P);
		break;
	}
	case 3:
		if(flag==0)
		{
			printf("树未初始化！\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		ElemType data;
		printf("请输入你要删除的数据：");
		while(scanf("%d",&data)==0||getchar()!='\n')
		{
			printf("非法输入，请重新输入：");
			while(getchar()!='\n');
		}
		BST_delete(P,&P->root,data);

		//交互界面
		system("pause");
		system("cls");
		select (P);
		break;
	case 4:
		if(flag==0)
		{
			printf("树未初始化！\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		ElemType temp;
		printf("请输入你要搜寻的数据：");
		while(scanf("%d",&temp)==0||getchar()!='\n')
		{
			printf("非法输入，请重新输入：");
			while(getchar()!='\n');
		}
		BST_search(P->root,temp);

		//交互界面
		system("pause");
		system("cls");
		select (P);
		break;

	case 5:
		if(flag==0)
		{
			printf("树未初始化！\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		BST_preorderR(P,visit);

		//交互界面
		system("pause");
		system("cls");
		select (P);
		break;
	case 6:
		if(flag==0)
		{
			printf("树未初始化！\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		BST_inorderR(P,visit);

		//交互界面
		system("pause");
		system("cls");
		select (P);
		break;
	case 7:
		if(flag==0)
		{
			printf("树未初始化！\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		BST_postorderR(P,visit);

		//交互界面
		system("pause");
		system("cls");
		select (P);
		break;
	case 8:
		if(flag==0)
		{
			printf("树未初始化！\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		BST_preorderI(P,visit);

		//交互界面
		system("pause");
		system("cls");
		select (P);
		break;
	case 9:
		if(flag==0)
		{
			printf("树未初始化！\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		BST_inorderI(P,visit);

		//交互界面
		system("pause");
		system("cls");
		select (P);
		break;
	case 10:
		if(flag==0)
		{
			printf("树未初始化！\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		BST_postorderI(P,visit);

		//交互界面
		system("pause");
		system("cls");
		select (P);
		break;
	case 11:
		if(flag==0)
		{
			printf("树未初始化！\n");
			system("pause");
			system("cls");
			select (P);
			break;
		}
		BST_levelOrder(P,visit);

		//交互界面
		system("pause");
		system("cls");
		select (P);
		break;
	case 0:
		printf("即将退出程序！\n");
		system("pause");
		exit(0);
		break;
	default:
		printf("非法输入，请重新输入：");
		system("pause");
		system("cls");
		select (P);
		break;
	}
}
