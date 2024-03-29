#ifndef LIBRARYMANAGEMENTSYSTEM_H_INCLUDED
#define LIBRARYMANAGEMENTSYSTEM_H_INCLUDED
#include"Librarymanagementsystem.h"

int booktype;//用于记录书的种类
typedef int count;

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
}Status;

typedef struct LoginC//登录账号密码
{
	char username[30];
	char password[30];
}LoginC;
//图书
typedef struct book//图书结构体
{
	int num;
	char bookname[20];
	char author[20];
	int booknum;
}Book;
typedef struct LNode//图书链表结点
{
	struct LNode*prev;
	count data;
	struct book date;
	struct LNode*next;
}LNode,*DLink;
//学生，用户，用来存储用户信息
typedef struct yonhu
{
	char CLASS[30];
	char ID[20];
	char stuname[10];
	int yuyuenum;
}yonhu;
typedef struct stu
{
	struct stu *prev;
	struct yonhu shuju;
	struct stu *next;
}Student,*pStudent;

typedef Book ElemType;

//***************************************
//菜单界面函数
void identitymenu();//身份菜单
void Administratormenu();//管理员菜单
void Usermenu();//用户菜单
void searchbookmenu();
void yuyuemenu();
//***************************************
//菜单函数
void Administratorselect();
void identityselect();
void Userselect();
//***************************************
//登录模块函数
Status ADComparePassword (char *user,char *password);
Status ADLogin (char user[30],char password[30]);
Status ULogin(char user[30],char password[30]);
Status UComparePassword (char *user,char *password);
//***************************************


//***************************************
//管理员功能模块函数
Status addbook();
int jilushubenzhonlei(int *x);
void deletebook(DLink head);
Status zhuceyonhu();
//***************************************
//用户功能模块函数
Status readbook();
void searchbook();
Status lendbook(DLink head);
Status returnbook(DLink head);
Status yuyue(int x);

//***************************************
//链表使用基本函数
DLink InitiDL();
void traval(DLink head);
pStudent Initi();
//****************************************
#endif // LIBRARYMANAGEMENTSYSTEM_H_INCLUDED
