#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Librarymanagementsystem.h"

//管理员登录函数
Status ADLogin (char user[30],char password[30])//用于用户输入账户密码
{
	int i=0,flag=0;
	printf( "\n\n\n\n\n\n\n\n"
		"\t\t\t\t\t\t登录\n"
		"\t\t\t\t***************************\n"
		"\t\t\t\t你仅有三次输入机会\n");
	do
	{
		printf("\t\t\t\t请输入用户名：");
		gets(user);
		printf("\t\t\t\t请输入密码：");
		gets(password);
		flag=ADComparePassword(user,password);
		//printf("%d",flag);
		if (flag==1)
		{
			printf( "\t\t\t\t***************************\n");
			return SUCCESS;
		}
		else
		{
			printf("\t\t\t\t您输入的用户名或密码错误。\n");
			i++;
		}
	}while(i<3);
	if(flag==0)
	{
		system("cls");
		printf( "\t\t\t\t您已经输入错误三次，即将退出程序。\n"
			"\t\t\t\t程序退出！"
			"\t\t\t\t***************************\n");
			system("pause");
			exit(0);
	}
}
//账号密码审核函数
Status ADComparePassword (char *user,char *password)//用于审核密码
{
	LoginC s[10];
	int i,N=0,j;
	FILE *fp;
	if ((fp=fopen("adpassword.txt","r"))==NULL)
	{
		printf( "打开文件失败！\n"
			"即将退出程序！\n");
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
	return ERROR;
}



//用户登录函数
Status ULogin(char user[30],char password[30])
{
	int i=0,flag=0;
	printf( "\n\n\n\n\n\n\n\n"
		"\t\t\t\t\t\t登录\n"
		"\t\t\t\t***************************\n"
		"\t\t\t\t你仅有三次输入机会\n");
	do
	{
		printf("\t\t\t\t请输入用户名：");
		gets(user);
		printf("\t\t\t\t请输入密码：");
		gets(password);
		flag=UComparePassword(user,password);
		//printf("%d",flag);
		if (flag==1)
		{
			printf( "\t\t\t\t***************************\n");
			system("pause");
			return SUCCESS;
		}
		else
		{
			printf("\t\t\t\t您输入的用户名或密码错误。\n");
			i++;
		}
	}while(i<3);
	if(flag==0)
	{
		system("cls");
		printf( "\t\t\t\t您已经输入错误三次，即将退出程序。\n"
			"\t\t\t\t程序退出！"
			"\t\t\t\t***************************\n");
			system("pause");
			exit(0);
	}
}
//用户账号密码审核函数
Status UComparePassword (char *user,char *password)//用于审核密码
{
	LoginC s[10];
	int i,N=0,j;
	FILE *fp;
	if ((fp=fopen("userpassword.txt","r"))==NULL)
	{
		printf( "打开文件失败！\n"
			"即将退出程序！\n");
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
