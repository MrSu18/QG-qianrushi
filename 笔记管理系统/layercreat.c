#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include "file_rw.h"

Status layercreat(FolderTreePtr base,char *s)//创建整棵树
{
	FILE *fp=fopen("刘骏帆笔记.txt","r");
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
	fscanf(fp,"%s\t%s\t%s\t%s\t%s\n",temp.folder_title,temp.folder_tag[0].tag_node,temp.folder_tag[1].tag_node,temp.folder_tag[2].tag_node,temp.folder_tag[3].tag_node,temp.folder_tag[4].tag_node);

	strcpy(base->root->folder_title,temp.folder_title);
	strcpy(base->root->folder_tag[0].tag_node,temp.folder_tag[0].tag_node);
	strcpy(base->root->folder_tag[1].tag_node,temp.folder_tag[1].tag_node);
	strcpy(base->root->folder_tag[2].tag_node,temp.folder_tag[2].tag_node);
	strcpy(base->root->folder_tag[3].tag_node,temp.folder_tag[3].tag_node);
	strcpy(base->root->folder_tag[4].tag_node,temp.folder_tag[4].tag_node);
	base->root->left=NULL;
	base->root->right=NULL;

	Queue_In(&q,base->root);

	FolderPtr T=(FolderPtr)malloc(sizeof(Folder));//用来保存出队的结点
	//while(!Queue_Empty(q));
	while(!feof(fp))
	{
		T=Queue_Front(q);
		Queue_Out(&q);
		//准备给左孩子的数据，左孩子创建并且赋值之后入队
		if(!feof(fp))
		{

			fscanf(fp,"%s\t%s\t%s\t%s\t%s\n",temp.folder_title,temp.folder_tag[0].tag_node,temp.folder_tag[1].tag_node,temp.folder_tag[2].tag_node,temp.folder_tag[3].tag_node,temp.folder_tag[4].tag_node);

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
		}
		//同理创建右孩子，并且入队
		if(!feof(fp))
		{
			fscanf(fp,"%s\t%s\t%s\t%s\t%s\n",temp.folder_title,temp.folder_tag[0].tag_node,temp.folder_tag[1].tag_node,temp.folder_tag[2].tag_node,temp.folder_tag[3].tag_node,temp.folder_tag[4].tag_node);


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
		}
	}
	fclose(fp);
	return TRUE;
}
