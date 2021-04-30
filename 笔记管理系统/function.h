#pragma once

typedef enum Status
{
	TRUE=1,
	ERROR=0
}Status;

#define MAXSIZE 31



//标签结构体
typedef struct tag
{
	char tag_node[20];			//一个标签
}Tag;

//文件单链表
typedef struct file
{
	char file_title[50];		//文件名
	Tag file_tag[5];			//文件标签（最多5个）
	struct file* next;			//下一结点
}File, * FilePtr;

//文件夹二叉树
typedef struct folder
{
	char folder_title[51];		//文件夹名
	Tag folder_tag[5];			//文件夹标签（最多5个）
	FilePtr file_head;			//文件头指针（文件，若无文件=NULL）
	struct folder* left, * right;	//左右孩子结点
}Folder, * FolderPtr;

//二叉树根
typedef struct folderhead
{
	FolderPtr root;				//根节点
}FolderTree, * FolderTreePtr;

//用户单链表
typedef struct user
{
	char user_name[31];			//用户名
	char user_password[31];		//密码
	char user_id[31];			//证件号码
	struct user* user_next;     //下一个用户
	FolderTreePtr user_folder;	//用户的根目录
}User, * UserPtr;



extern User* user;



void build_dir(User* newn);//注册时初始化目录
Status DIR_init(FolderTreePtr* F_T);//文件目录树初始化
Status DIR_insert(FolderPtr );//文件夹插入


User* user_insert();
User* user_name_search(User* user_temp, char* name_input);
User* user_id_search(User* user_temp, char* id_input);
