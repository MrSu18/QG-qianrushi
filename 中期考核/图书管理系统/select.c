#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Librarymanagementsystem.h"
void identityselect()
{
	char opotion;
	printf("\t\t\t\t��ѡ�������ݣ�");
		while(scanf("%c",&opotion)==0||getchar()!='\n')
		{
			printf("\t\t\t\t�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		switch(opotion)
		{
		case 'a':
			{
				system("cls");
				char user[30],password[30];
				ADLogin(user,password);
				Administratorselect();
				break;
			}
		case 'b':
			{
				system("cls");
				char user[30],password[30];
				ULogin(user,password);
				Usermenu();
				Userselect();
				break;
			}
		case 'c':
			{
				printf("\t\t\t\t��ӭʹ�ã������˳�����!\n");
				system("pause");
				exit(0);
				break;
			}

		default:
			printf("\t\t\t\t�Ƿ����룬����������!\n");
			system("pause");
			system("cls");
			identitymenu();
			identityselect();
			break;
		}
}

void Administratorselect()//������ѡ��
{
	int opotion;
	//while (1)
	{
		printf("\t���ѡ��Ϊ��");
			while(scanf("%d",&opotion)==0||getchar()!='\n')
			{
				printf("\t�����˷Ƿ��ַ������������룺");
				while (getchar() != '\n');
			}
			switch(opotion)
			{
			case 1:
				addbook();
				system("cls");
				Administratormenu();
				Administratorselect();
				break;
			case 2:
			{
				DLink head;
				head=InitiDL();
				//traval(head);
				deletebook(head);
				break;

			}
			case 0:
				exit(0);
			default:
				printf("�Ƿ����룬����������!\n");
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
	printf("\t���ѡ��Ϊ��");
		while(scanf("%d",&opotion)==0||getchar()!='\n')
		{
			printf("\t�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		switch(opotion)
		{
		case 1:
		{
			DLink head;
			head=InitiDL();
			lendbook(head);
			Usermenu();
			Userselect();
			break;
		}
		case 2:
		{
			DLink head;
			head=InitiDL();
			returnbook(head);
			Usermenu();
			Userselect();
			break;
		}
		case 3:
			searchbook();
			system("pause");
			break;
		case 4:
			readbook();
			system("pause");
			Usermenu();
			Userselect();
			break;
		default:
			printf("�Ƿ����룬����������!\n");
			system("pause");
			system("cls");
			Usermenu();
			Userselect();
			break;
		}
}
