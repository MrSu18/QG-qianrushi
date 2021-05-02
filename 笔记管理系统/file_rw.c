#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include "file_rw.h"

Status U_file_r(User*head)//对用户文件的读取
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

		//给temp以及后面的指针申请空间
		User temp;
		temp.user_folder->root=(FolderPtr)malloc(sizeof(Folder));

		while(!feof(fp))
		{
			//给节点以及里面的指针申请空间
			UserPtr newnode = (UserPtr)malloc(sizeof(User));
			newnode->user_folder=(FolderTreePtr)malloc(sizeof(FolderTree));
			newnode->user_folder->root=(FolderPtr)malloc(sizeof(Folder));
			//从文件中读取
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

void fvisit(FolderPtr q,char *filename)//写入只要在在遍历中，把visit结点改成fvisit就好了，filrname改成用户根目录加.txt
{
	FILE *fp=fopen(filename,"a");
	if(!fp)
	{
		printf("打开文件出错!\n");
		return ERROR;
	}
	else
	{
		fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n"   ,q->folder_title
							,q->folder_tag[0].tag_node
							,q->folder_tag[1].tag_node
							,q->folder_tag[2].tag_node
							,q->folder_tag[3].tag_node
							,q->folder_tag[4].tag_node);
		fclose(fp);
		return TRUE;
	}
}

Status S_filedir_w(FolderTreePtr F_T,char*dirtxt,char *filetxt, void (*fvisit)(FolderPtr q,char*filename))//对用户文件夹信息进行写入
{
	LQueue* Q = NULL;
	Queue_Init(&Q);
	Queue_In(&Q, F_T->root);
	while (!Queue_Empty(Q))
	{
		FolderPtr node = Queue_Front(Q);

		fvisit(node,dirtxt);//把树的信息写入树txt
		if(node->file_head)
		{
			file_w(node->file_head,filetxt);//把文件链表的信息写入txt
		}

		Queue_Out(&Q);
		if (node->left)
		{
			Queue_In(&Q, node->left);
		}
		if (node->right)
		{
			Queue_In(&Q, node->right);
		}
	}
	free(Q);
	Q = NULL;
}

Status file_r(FILE *fp,FilePtr head)//对对应的文件名进行读取
{
	FilePtr p =(FilePtr)malloc(sizeof(File));
	p=head;
	File temp;
	char pause[10]={'p','a','u','s','e','\0'};

	fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",temp.file_title
						,temp.file_tag[0].tag_node
						,temp.file_tag[1].tag_node
						,temp.file_tag[2].tag_node
						,temp.file_tag[3].tag_node
						,temp.file_tag[4].tag_node);


	while(strcmp(temp.file_title,pause)!=0)
	{
		FilePtr newnode = (FilePtr)malloc(sizeof(File));

		strcpy(newnode->file_title,temp.file_title);
		strcpy(newnode->file_tag[0].tag_node,temp.file_tag[0].tag_node);
		strcpy(newnode->file_tag[1].tag_node,temp.file_tag[1].tag_node);
		strcpy(newnode->file_tag[2].tag_node,temp.file_tag[2].tag_node);
		strcpy(newnode->file_tag[3].tag_node,temp.file_tag[3].tag_node);
		strcpy(newnode->file_tag[4].tag_node,temp.file_tag[4].tag_node);


		fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",temp.file_title
						,temp.file_tag[0].tag_node
						,temp.file_tag[1].tag_node
						,temp.file_tag[2].tag_node
						,temp.file_tag[3].tag_node
						,temp.file_tag[4].tag_node);

		p->next=newnode;
		p=newnode;
		newnode->next=NULL;
	}
	return TRUE;
}

Status file_w(FilePtr head,char *filetxt)//对文件名链表进行写入文本文件
{
	FILE *fp = fopen(filetxt,"a");
	if(!fp)
	{
		printf("打开文件出错!\n");
		return ERROR;
	}
	else
	{
		FilePtr p =(FilePtr)malloc(sizeof(File));
		p=head;
		while(p->next)
		{
			p=p->next;
			fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",p->file_title
							     ,p->file_tag[0].tag_node
							     ,p->file_tag[1].tag_node
							     ,p->file_tag[2].tag_node
							     ,p->file_tag[3].tag_node
							     ,p->file_tag[4].tag_node);
		}
		//给文件写入一个暂停标志
		File pause;
		strcpy(pause.file_title,"pause\0");
		strcpy(pause.file_tag[0].tag_node,"stop\0");
		strcpy(pause.file_tag[1].tag_node,"stop\0");
		strcpy(pause.file_tag[2].tag_node,"stop\0");
		strcpy(pause.file_tag[3].tag_node,"stop\0");
		strcpy(pause.file_tag[4].tag_node,"stop\0");

		fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",pause.file_title
						     ,pause.file_tag[0].tag_node
						     ,pause.file_tag[1].tag_node
						     ,pause.file_tag[2].tag_node
						     ,pause.file_tag[3].tag_node
						     ,pause.file_tag[4].tag_node);

		fclose(fp);

		return TRUE;
	}
}
