#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Librarymanagementsystem.h"

void identitymenu()//身份菜单
{
	printf( "\n\n\n\n\n\n\n\n"
		"\t\t\t\t************************************************\n"
		"\t\t\t\t\t\t图书管理系统\n\n"
		"\t\t\t\t--> a、管理者登录\n\n"
		"\t\t\t\t--> b、用户登录\n\n"
		"\t\t\t\t--> c、退出程序\n\n"
		"\t\t\t\t*************************************************\n");

}

void Administratormenu()//管理员菜单
{
	printf( "*******************************************\n"
		"\t--> 1、采编入库\n"
		"\t--> 2、清除库存\n"
		"\t--> 0、返回上层目录\n"
		"*******************************************\n");
}

void Usermenu()//用户菜单
{
	printf( "********************************************\n"
		"\t--> 1、借阅图书\n"
		"\t--> 2、归还图书\n"
		"\t--> 3、图书查询\n"
		"\t--> 4、图书总览\n"
		"\t--> 0、返回上层目录\n"
		"********************************************\n");
}
