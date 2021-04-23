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
	printf( "\n\n\n\n\n\n\n\n"
		"\t\t\t\t\t欢迎进入管理员权限系统！\n"
		"\t\t\t\t*******************************************\n"
		"\t\t\t\t--> 1、采编入库\n"
		"\t\t\t\t--> 2、清除库存\n"
		"\t\t\t\t--> 3、注册用户\n"
		"\t\t\t\t--> 4、总览图书\n"
		"\t\t\t\t--> 0、返回上层目录\n"
		"\t\t\t\t*******************************************\n");
}

void Usermenu()//用户菜单
{
	printf( "\n\n\n\n\n\n\n\n"
		"\t\t\t\t\t欢迎进入图书借阅系统！\n"
		"\t\t\t\t********************************************\n"
		"\t\t\t\t--> 1、借阅图书\n"
		"\t\t\t\t--> 2、归还图书\n"
		"\t\t\t\t--> 3、图书查询\n"
		"\t\t\t\t--> 4、图书总览\n"
		"\t\t\t\t--> 0、返回上层目录\n"
		"\t\t\t\t********************************************\n");
}


void searchbookmenu()//搜索图书的选择界面
{
	printf( "\n\n\n\n\n\n\n\n"
		"\t\t\t\t********************************************\n"
		"\t\t\t\t--> 1、按图书编号搜索\n"
		"\t\t\t\t--> 2、按书名搜索\n"
		"\t\t\t\t--> 3、按作者搜索\n"
		"\t\t\t\t--> 4、按库存量搜索\n"
		"\t\t\t\t--> 0、返回上层目录\n"
		"\t\t\t\t********************************************\n");
}


void yuyuemenu()
{
	printf( "\n"
		"--> a、办理预约\n"
		"--> b、取消借阅\n");
}
