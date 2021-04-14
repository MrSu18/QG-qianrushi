#ifndef LIBRARYMANAGEMENTSYSTEM_H_INCLUDED
#define LIBRARYMANAGEMENTSYSTEM_H_INCLUDED
#include"Librarymanagementsystem.h"

int booktype;//���ڼ�¼�������
typedef int count;

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
}Status;

typedef struct LoginC//��¼�˺�����
{
	char username[30];
	char password[30];
}LoginC;
//ͼ��
typedef struct book//ͼ��ṹ��
{
	int num;
	char bookname[20];
	char author[20];
	int booknum;
}Book;
typedef struct LNode//ͼ��������
{
	struct LNode*prev;
	count data;
	struct book date;
	struct LNode*next;
}LNode,*DLink;
//ѧ�����û��������洢�û���Ϣ
typedef struct yonhu
{
	char CLASS[30];
	char ID[20];
	char stuname[10];
}yonhu;
typedef struct stu
{
	struct stu *prev;
	struct yonhu shuju;
	struct stu *next;
}Student,*pStudent;

typedef Book ElemType;

//***************************************
//�˵����溯��
void identitymenu();//��ݲ˵�
void Administratormenu();//����Ա�˵�
void Usermenu();//�û��˵�
//***************************************
//�˵�����
void Administratorselect();
void identityselect();
void Userselect();
//***************************************
//��¼ģ�麯��
Status ADComparePassword (char *user,char *password);
void ADLogin (char user[30],char password[30]);
void ULogin(char user[30],char password[30]);
Status UComparePassword (char *user,char *password);
//***************************************


//***************************************
//����Ա����ģ�麯��
Status addbook();
int jilushubenzhonlei(int *x);
void deletebook(DLink head);
//Status deletebook();
//***************************************
//�û�����ģ�麯��
Status readbook();
void searchbook();
void lendbook(DLink head);
void returnbook(DLink head);

//***************************************
//����ʹ�û�������
DLink InitiDL();
void traval(DLink head);
pStudent Initi();
//****************************************
#endif // LIBRARYMANAGEMENTSYSTEM_H_INCLUDED
