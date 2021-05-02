#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include "file_rw.h"

Status layercreat(FolderTreePtr base,char *dirname,char *filename)//创建整棵树
{
	int FLAG=0;

	FILE *fp1=fopen(filename,"r");//s为用户对应的存储文件名以及文件标签的txt
	FILE *fp=fopen(dirname,"r");//s为用户对应的存储文件夹名以及文件标签的txt
	if(!fp)
	{
		printf("打开文件出错!\n");
		return ERROR;
	}

	//初始化一个队列
	LQueue*q=(LQueue*)malloc(sizeof(LQueue));
	Queue_Init(&q);
	//读取数据到root里面
	Folder temp;
	fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",temp.folder_title
					    ,temp.folder_tag[0].tag_node
					    ,temp.folder_tag[1].tag_node
					    ,temp.folder_tag[2].tag_node
					    ,temp.folder_tag[3].tag_node
					    ,temp.folder_tag[4].tag_node);

	strcpy(base->root->folder_title,temp.folder_title);
	strcpy(base->root->folder_tag[0].tag_node,temp.folder_tag[0].tag_node);
	strcpy(base->root->folder_tag[1].tag_node,temp.folder_tag[1].tag_node);
	strcpy(base->root->folder_tag[2].tag_node,temp.folder_tag[2].tag_node);
	strcpy(base->root->folder_tag[3].tag_node,temp.folder_tag[3].tag_node);
	strcpy(base->root->folder_tag[4].tag_node,temp.folder_tag[4].tag_node);
	base->root->left=NULL;
	base->root->right=NULL;

	Queue_In(&q,base->root);
	FLAG++;

	FolderPtr T=(FolderPtr)malloc(sizeof(Folder));//用来保存出队的结点
	//while(!Queue_Empty(q))
	while(!feof(fp))
	{
		T=Queue_Front(q);
		T->file_head=(FilePtr)malloc(sizeof(File));
		T->file_head->next=NULL;

		file_r(fp1,T->file_head);//把T的文件链表也创建好

		Queue_Out(&q);
		FLAG--;
		//准备给左孩子的数据，左孩子创建并且赋值之后入队
		if(!feof(fp))
		{

			fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",temp.folder_title
							    ,temp.folder_tag[0].tag_node
							    ,temp.folder_tag[1].tag_node
							    ,temp.folder_tag[2].tag_node
							    ,temp.folder_tag[3].tag_node
							    ,temp.folder_tag[4].tag_node);



			T->left=(FolderPtr)malloc(sizeof(Folder));
			strcpy(T->left->folder_title,temp.folder_title);
			strcpy(T->left->folder_tag[0].tag_node,temp.folder_tag[0].tag_node);
			strcpy(T->left->folder_tag[1].tag_node,temp.folder_tag[1].tag_node);
			strcpy(T->left->folder_tag[2].tag_node,temp.folder_tag[2].tag_node);
			strcpy(T->left->folder_tag[3].tag_node,temp.folder_tag[3].tag_node);
			strcpy(T->left->folder_tag[4].tag_node,temp.folder_tag[4].tag_node);
			T->left->left=NULL;
			T->left->right=NULL;

			Queue_In(&q,T->left);
			FLAG++;
		}
		//同理创建右孩子，并且入队
		if(!feof(fp))
		{
			fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",temp.folder_title
							    ,temp.folder_tag[0].tag_node
							    ,temp.folder_tag[1].tag_node
							    ,temp.folder_tag[2].tag_node
							    ,temp.folder_tag[3].tag_node
							    ,temp.folder_tag[4].tag_node);


			T->right=(FolderPtr)malloc(sizeof(Folder));
			strcpy(T->right->folder_title,temp.folder_title);
			strcpy(T->right->folder_tag[0].tag_node,temp.folder_tag[0].tag_node);
			strcpy(T->right->folder_tag[1].tag_node,temp.folder_tag[1].tag_node);
			strcpy(T->right->folder_tag[2].tag_node,temp.folder_tag[2].tag_node);
			strcpy(T->right->folder_tag[3].tag_node,temp.folder_tag[3].tag_node);
			strcpy(T->right->folder_tag[4].tag_node,temp.folder_tag[4].tag_node);
			T->right->left=NULL;
			T->right->right=NULL;

			Queue_In(&q,T->right);
			FLAG++;
		}
	}
	while(FLAG)
	{
		T=Queue_Front(q);
		T->file_head=(FilePtr)malloc(sizeof(File));
		T->file_head->next=NULL;//给文件链表头指针初始化，并且NEXT置空不然可能会使得

		//file_r(fp1,T->file_head);

		Queue_Out(&q);
		FLAG--;
	}
	fclose(fp);
	return TRUE;
}
