#pragma once

typedef enum Status
{
	TRUE=1,
	ERROR=0
}Status;

#define MAXSIZE 31



//��ǩ�ṹ��
typedef struct tag
{
	char tag_node[20];			//һ����ǩ
}Tag;

//�ļ�������
typedef struct file
{
	char file_title[50];		//�ļ���
	Tag file_tag[5];			//�ļ���ǩ�����5����
	struct file* next;			//��һ���
}File, * FilePtr;

//�ļ��ж�����
typedef struct folder
{
	char folder_title[51];		//�ļ�����
	Tag folder_tag[5];			//�ļ��б�ǩ�����5����
	FilePtr file_head;			//�ļ�ͷָ�루�ļ��������ļ�=NULL��
	struct folder* left, * right;	//���Һ��ӽ��
}Folder, * FolderPtr;

//��������
typedef struct folderhead
{
	FolderPtr root;				//���ڵ�
}FolderTree, * FolderTreePtr;

//�û�������
typedef struct user
{
	char user_name[31];			//�û���
	char user_password[31];		//����
	char user_id[31];			//֤������
	struct user* user_next;     //��һ���û�
	FolderTreePtr user_folder;	//�û��ĸ�Ŀ¼
}User, * UserPtr;



extern User* user;



void build_dir(User* newn);//ע��ʱ��ʼ��Ŀ¼
Status DIR_init(FolderTreePtr* F_T);//�ļ�Ŀ¼����ʼ��
Status DIR_insert(FolderPtr );//�ļ��в���


User* user_insert();
User* user_name_search(User* user_temp, char* name_input);
User* user_id_search(User* user_temp, char* id_input);
