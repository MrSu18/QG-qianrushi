#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Librarymanagementsystem.h"
void identityselect()
{
	char opotion;
	printf("\t\t\t\t请选择你的身份：");
		while(scanf("%c",&opotion)==0||getchar()!='\n')
		{
			printf("\t\t\t\t输入了非法字符，请重新输入：");
			while (getchar() != '\n');
		}
		switch(opotion)
		{
		case 'a':
			{
				system("cls");
				char user[30],password[30];
				ADLogin(user,password);
				system("cls");
				Administratormenu();
				Administratorselect();
				break;
			}
		case 'b':
			{
				system("cls");
				char user[30],password[30];
				ULogin(user,password);
				system("cls");
				Usermenu();
				Userselect();
				break;
			}
		case 'c':
			{
				printf("\t\t\t\t欢迎使用，即将退出程序!\n");
				system("pause");
				exit(0);
				break;
			}

		default:
			printf("\t\t\t\t非法输入，请重新输入!\n");
			system("pause");
			system("cls");
			identitymenu();
			identityselect();
			break;
		}
}

void Administratorselect()//管理者选项
{
	int opotion;
	//while (1)
	{
		printf("\t\t\t\t你的选项为：");
			while(scanf("%d",&opotion)==0||getchar()!='\n')
			{
				printf("\t\t\t\t输入了非法字符，请重新输入：");
				while (getchar() != '\n');
			}
			switch(opotion)
			{
			case 1:
				system("cls");
				addbook();
				system("cls");
				Administratormenu();
				Administratorselect();
				break;
			case 2:
			{
				system("cls");
				DLink head;
				head=InitiDL();
				//traval(head);
				deletebook(head);
				system("cls");
				Administratormenu();
				Administratorselect();
				break;
			}
			case 0:
				system("cls");
				identitymenu();
				identityselect();
			default:
				printf("\t\t\t\t非法输入，请重新输入!\n");
				system("pause");
				system("cls");
				Administratormenu();
				Administratorselect();
				break;

			}
	}
}


void Userselect()
{
	int opotion;
	printf("\t\t\t\t你的选项为：");
		while(scanf("%d",&opotion)==0||getchar()!='\n')
		{
			printf("\t\t\t\t输入了非法字符，请重新输入：");
			while (getchar() != '\n');
		}
		switch(opotion)
		{
		case 1:
		{
			system("cls");
			DLink head;
			head=InitiDL();
			lendbook(head);
			system("cls");
			Usermenu();
			Userselect();
			break;
		}
		case 2:
		{
			system("cls");
			DLink head;
			head=InitiDL();
			returnbook(head);
			system("cls");
			Usermenu();
			Userselect();
			break;
		}
		case 3:
			system("cls");
			searchbook();
			system("pause");
			break;
		case 4:
			system("cls");
			readbook();
			system("pause");
			Usermenu();
			Userselect();
			break;
		case 0:
			system("cls");
			identitymenu();
			identityselect();
			break;
		default:
			printf("\t\t\t\t非法输入，请重新输入!\n");
			system("pause");
			system("cls");
			Usermenu();
			Userselect();
			break;
		}
}
