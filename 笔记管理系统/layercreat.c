#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include "file_rw.h"

Status layercreat(FolderTreePtr base,char *s)//����������
{
	FILE *fp=fopen("�������ʼ�.txt","r");
	if(!fp)
	{
		printf("���ļ�����!\n");
		return ERROR;
	}

	//��ʼ��һ������
	LQueue*q=(LQueue*)malloc(sizeof(LQueue));
	Queue_Init(&q);
	//��ȡ���ݵ�root����
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

	FolderPtr T=(FolderPtr)malloc(sizeof(Folder));//����������ӵĽ��
	//while(!Queue_Empty(q));
	while(!feof(fp))
	{
		T=Queue_Front(q);
		Queue_Out(&q);
		//׼�������ӵ����ݣ����Ӵ������Ҹ�ֵ֮�����
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
		//ͬ�����Һ��ӣ��������
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
