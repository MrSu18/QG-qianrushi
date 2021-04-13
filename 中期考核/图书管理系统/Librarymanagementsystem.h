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

typedef struct book
{
	int num;
	char bookname[20];
	char author[20];
	int booknum;
}Book;

typedef struct LNode
{
	struct LNode*prev;
	count data;
	struct book date;
	struct LNode*next;
}LNode,*DLink;

typedef Book ElemType;

//***************************************
//菜单界面函数
void identitymenu();//身份菜单
void Administratormenu();//管理员菜单
void Usermenu();//用户菜单
//***************************************
//菜单函数
void Administratorselect();
void identityselect();
void Userselect();
//***************************************
//登录模块函数
Status ADComparePassword (char *user,char *password);
void ADLogin (char user[30],char password[30]);
void ULogin(char user[30],char password[30]);
Status UComparePassword (char *user,char *password);
//***************************************


//***************************************
//管理员功能模块函数
Status addbook();
int jilushubenzhonlei(int *x);
void deletebook(DLink head);
//Status deletebook();
//***************************************
//用户功能模块函数
Status readbook();
void searchbook();


//***************************************
//链表使用基本函数
DLink InitiDL();
void traval(DLink head);
//****************************************
#endif // LIBRARYMANAGEMENTSYSTEM_H_INCLUDED
