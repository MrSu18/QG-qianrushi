#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Librarymanagementsystem.h"

//����Ա��¼����
void ADLogin (char user[30],char password[30])//�����û������˻�����
{
	int i=0,flag=0;
	printf("\t***************************\n"
		"\t����������������\n");
	do
	{
		printf("\t�������û�����");
		gets(user);
		printf("\t���������룺");
		gets(password);
		flag=ADComparePassword(user,password);
		//printf("%d",flag);
		if (flag==1)
		{
			printf( "\t***************************\n"
				"\n\t��ӭ�������ԱȨ��ϵͳ��\n");
			Administratormenu();
			break;
		}
		else
		{
			printf("\t��������û������������\n");
			i++;
		}
	}while(i<3);
	if(flag==0)
	{
		system("cls");
		printf( "\t���Ѿ�����������Σ������˳�����\n"
			"\t�����˳���");
			system("pause");
			exit(0);
	}
}
//�˺�������˺���
Status ADComparePassword (char *user,char *password)//�����������
{
	LoginC s[10];
	int i,N=0,j;
	FILE *fp;
	if ((fp=fopen("adpassword.txt","r"))==NULL)
	{
		printf( "���ļ�ʧ�ܣ�\n"
			"�����˳�����\n");
		return ERROR;
		system("pause");
		exit(0);
	}
	//char username[30]={'3','1','2','0','0','0','2','5','2','4'};
	//char pass[30]={'1','2','3','4','5','6'};
	while(!feof(fp))
	{
		fscanf(fp,"%s %s",s[N].username,s[N].password);
		if(strcmp(user,s[N].username)==0&&strcmp(password,s[N].password)==0)
		{
			return SUCCESS;
		}
		N++;
	}
	fclose(fp);
	//if(strcmp(user,username)==0&&strcmp(pass,password)==0)
		//return SUCCESS;
	//else
		return ERROR;
}



//�û���¼����
void ULogin(char user[30],char password[30])
{
	int i=0,flag=0;
	printf("\t***************************\n"
		"\t����������������\n");
	do
	{
		printf("\t�������û�����");
		gets(user);
		printf("\t���������룺");
		gets(password);
		flag=UComparePassword(user,password);
		//printf("%d",flag);
		if (flag==1)
		{
			printf( "\t***************************\n"
				"\n\t��ӭ����ͼ�����ϵͳ��\n");
			//Administratormenu();
			break;
		}
		else
		{
			printf("\t��������û������������\n");
			i++;
		}
	}while(i<3);
	if(flag==0)
	{
		system("cls");
		printf( "\t���Ѿ�����������Σ������˳�����\n"
			"\t�����˳���");
			system("pause");
			exit(0);
	}
}
//�û��˺�������˺���
Status UComparePassword (char *user,char *password)//�����������
{
	LoginC s[10];
	int i,N=0,j;
	FILE *fp;
	if ((fp=fopen("userpassword.txt","r"))==NULL)
	{
		printf( "���ļ�ʧ�ܣ�\n"
			"�����˳�����\n");
		return ERROR;
		system("pause");
		exit(0);
	}
	while(!feof(fp))
	{
		fscanf(fp,"%s %s",s[N].username,s[N].password);
		//printf("%s %s",s[N].username,s[N].password);
		if(strcmp(user,s[N].username)==0&&strcmp(password,s[N].password)==0)
		{
			return SUCCESS;
		}
		N++;
	}
	fclose(fp);
	return ERROR;
}
