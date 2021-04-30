#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include "file_rw.h"

Status U_file_r(User*head)//对用户信息文本的读取
{
	FILE * fp = fopen("USER.txt","r");
	if(!fp)
	{
		printf("打开文件出错!\n");
		return ERROR;
	}
	else
	{
		UserPtr p = (UserPtr)malloc(sizeof(User));
		p=head;
		//给节点以及里面的指针申请空间
		UserPtr newnode = (UserPtr)malloc(sizeof(User));
		newnode->user_folder=(FolderTreePtr)malloc(sizeof(FolderTree));
		newnode->user_folder->root=(FolderPtr)malloc(sizeof(Folder));
		//给temp以及后面的指针申请空间
		User temp;
		temp.user_folder->root=(FolderPtr)malloc(sizeof(Folder));

		while(!feof(fp))
		{
			fscanf(fp,"%s\t%s\t%s\t%s\n",temp.user_name,temp.user_password,temp.user_id,temp.user_folder->root->folder_title);//从文件中读取一个节点的数据存在temp中
			//以下把文件读取出来的信息存入节点中
			strcpy(newnode->user_name , temp.user_name);
			strcpy(newnode->user_password , temp.user_password);
			strcpy(newnode->user_id , temp.user_id);
			strcpy(newnode->user_folder->root->folder_title , temp.user_folder->root->folder_title);
			//连接节点
			p->user_next=newnode;
			p=p->user_next;
			newnode->user_next=NULL;
		}

		fclose(fp);
		return TRUE;
	}
}

Status U_file_w(User*head)//把用户链表中的信息存入本地文本
{
	FILE * fp = fopen("USER.txt","w");
	fclose(fp);
	fp = fopen("USER.txt","a");
	if(!fp)
	{
		printf("打开文件出错!\n");
		return ERROR;
	}
	else
	{
		UserPtr p = (UserPtr)malloc(sizeof(User));
		p->user_folder=(FolderTreePtr)malloc(sizeof(FolderTree));
		p->user_folder->root=(FolderPtr)malloc(sizeof(Folder));
		p=head->user_next;

		while(p!=NULL)
		{
			fprintf(fp,"%s\t%s\t%s\t%s\n",p->user_name,p->user_password,p->user_id,p->user_folder->root->folder_title);

			//节点移动
			p=p->user_next;
		}
		fclose(fp);
		return TRUE;
	}

}

Status S_filedir_r(char *s)//参数s是需要打开的文本文件的文件名
{
	FILE *fp=fopen(s,"r");
	if(!fp)
	{
		printf("打开文件出错!\n");
		return ERROR;
	}
	else
	{
		Folder temp;
		fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",temp.folder_title,temp.folder_tag[0].tag_node,temp.folder_tag[1].tag_node,temp.folder_tag[2].tag_node,temp.folder_tag[3].tag_node,temp.folder_tag[4].tag_node);
		printf("%s\t%s\t%s\t%s\t%s\t%s\n",temp.folder_title,temp.folder_tag[0].tag_node,temp.folder_tag[1].tag_node,temp.folder_tag[2].tag_node,temp.folder_tag[3].tag_node,temp.folder_tag[4].tag_node);
		if(strcmp(s,temp.folder_title)==0)
		{
			printf("成功");
			return TRUE;
		}
		fclose(fp);
	}
}
