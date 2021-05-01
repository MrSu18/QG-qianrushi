#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
#include "file_rw.h"

Status U_file_r(User*head)//���û���Ϣ�ı��Ķ�ȡ
{
	FILE * fp = fopen("USER.txt","r");
	if(!fp)
	{
		printf("���ļ�����!\n");
		return ERROR;
	}
	else
	{
		UserPtr p = (UserPtr)malloc(sizeof(User));
		p=head;

		//��temp�Լ������ָ������ռ�
		User temp;
		temp.user_folder->root=(FolderPtr)malloc(sizeof(Folder));

		while(!feof(fp))
		{
			//���ڵ��Լ������ָ������ռ�
			UserPtr newnode = (UserPtr)malloc(sizeof(User));
			newnode->user_folder=(FolderTreePtr)malloc(sizeof(FolderTree));
			newnode->user_folder->root=(FolderPtr)malloc(sizeof(Folder));
			//���ļ��ж�ȡ
			fscanf(fp,"%s\t%s\t%s\t%s\n",temp.user_name,temp.user_password,temp.user_id,temp.user_folder->root->folder_title);//���ļ��ж�ȡһ���ڵ�����ݴ���temp��
			//���°��ļ���ȡ��������Ϣ����ڵ���
			strcpy(newnode->user_name , temp.user_name);
			strcpy(newnode->user_password , temp.user_password);
			strcpy(newnode->user_id , temp.user_id);
			strcpy(newnode->user_folder->root->folder_title , temp.user_folder->root->folder_title);
			//���ӽڵ�
			p->user_next=newnode;
			p=p->user_next;
			newnode->user_next=NULL;
		}

		fclose(fp);
		return TRUE;
	}
}

Status U_file_w(User*head)//���û������е���Ϣ���뱾���ı�
{
	FILE * fp = fopen("USER.txt","w");
	fclose(fp);
	fp = fopen("USER.txt","a");
	if(!fp)
	{
		printf("���ļ�����!\n");
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

			//�ڵ��ƶ�
			p=p->user_next;
		}
		fclose(fp);
		return TRUE;
	}

}

void fvisit(FolderPtr* q,char *filename)//д��ֻҪ���ڱ����У���visit���ĳ�fvisit�ͺ��ˣ�filrname�ĳ��û���Ŀ¼��.txt
{
	FILE *fp=fopen(filename,"a");
	if(!fp)
	{
		printf("���ļ�����!\n");
		return ERROR;
	}
	else
	{
		fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n"   ,(*q)->folder_title
							,(*q)->folder_tag[0].tag_node
							,(*q)->folder_tag[1].tag_node
							,(*q)->folder_tag[2].tag_node
							,(*q)->folder_tag[3].tag_node
							,(*q)->folder_tag[4].tag_node);
		fclose(fp);
		return TRUE;
	}
}

Status file_r(FILE *fp,FilePtr head)//�Զ�Ӧ���ļ������ж�ȡ
{
	FilePtr p =(FilePtr)malloc(sizeof(File));
	p=head;
	File temp;
	char pause[10]={'p','a','u','s','e','\0'};

	while(strcmp(temp.file_title,pause)!=0)
	{
		fscanf(fp,"%s\t%s\t%s\t%s\t%s\n",temp.file_title
						,temp.file_tag[0].tag_node
						,temp.file_tag[1].tag_node
						,temp.file_tag[2].tag_node
						,temp.file_tag[3].tag_node
						,temp.file_tag[4].tag_node);

		FilePtr newnode = (FilePtr)malloc(sizeof(File));

		strcpy(newnode->file_title,temp.file_title);
		strcpy(newnode->file_tag[0].tag_node,temp.file_tag[0].tag_node);
		strcpy(newnode->file_tag[1].tag_node,temp.file_tag[1].tag_node);
		strcpy(newnode->file_tag[2].tag_node,temp.file_tag[2].tag_node);
		strcpy(newnode->file_tag[3].tag_node,temp.file_tag[3].tag_node);
		strcpy(newnode->file_tag[4].tag_node,temp.file_tag[4].tag_node);

		p->next=newnode;
		p=newnode;
		newnode->next=NULL;
	}
	return TRUE;
}

Status file_w(FilePtr head)//���ļ����������д���ı��ļ�
{
	FILE *fp = fopen("filename.txt","a");
	if(!fp)
	{
		printf("���ļ�����!\n");
		return ERROR;
	}
	else
	{
		FilePtr p =(FilePtr)malloc(sizeof(File));
		p=head->next;
		while(p!=NULL)
		{
			fprintf(fp,"%s\t%s\t%s\t%s\t%s\n",p->file_title
							 ,p->file_tag[0].tag_node
							 ,p->file_tag[1].tag_node
							 ,p->file_tag[2].tag_node
							 ,p->file_tag[3].tag_node
							 ,p->file_tag[4].tag_node);
		}
		//���ļ�д��һ����ͣ��־
		File pause;
		strcpy(pause.file_title,"pause\0");
		strcpy(pause.file_tag[0].tag_node,"\0");
		strcpy(pause.file_tag[1].tag_node,"\0");
		strcpy(pause.file_tag[2].tag_node,"\0");
		strcpy(pause.file_tag[3].tag_node,"\0");
		strcpy(pause.file_tag[4].tag_node,"\0");

		fprintf(fp,"%s\t%s\t%s\t%s\t%s\n",pause.file_title
						 ,pause.file_tag[0].tag_node
						 ,pause.file_tag[1].tag_node
						 ,pause.file_tag[2].tag_node
						 ,pause.file_tag[3].tag_node
						 ,pause.file_tag[4].tag_node);

		fclose(fp);

		return TRUE;
	}
}
