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
		//���ڵ��Լ������ָ������ռ�
		UserPtr newnode = (UserPtr)malloc(sizeof(User));
		newnode->user_folder=(FolderTreePtr)malloc(sizeof(FolderTree));
		newnode->user_folder->root=(FolderPtr)malloc(sizeof(Folder));
		//��temp�Լ������ָ������ռ�
		User temp;
		temp.user_folder->root=(FolderPtr)malloc(sizeof(Folder));

		while(!feof(fp))
		{
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

Status S_filedir_r(char *s)//����s����Ҫ�򿪵��ı��ļ����ļ���
{
	FILE *fp=fopen(s,"r");
	if(!fp)
	{
		printf("���ļ�����!\n");
		return ERROR;
	}
	else
	{
		Folder temp;
		fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\n",temp.folder_title,temp.folder_tag[0].tag_node,temp.folder_tag[1].tag_node,temp.folder_tag[2].tag_node,temp.folder_tag[3].tag_node,temp.folder_tag[4].tag_node);
		printf("%s\t%s\t%s\t%s\t%s\t%s\n",temp.folder_title,temp.folder_tag[0].tag_node,temp.folder_tag[1].tag_node,temp.folder_tag[2].tag_node,temp.folder_tag[3].tag_node,temp.folder_tag[4].tag_node);
		if(strcmp(s,temp.folder_title)==0)
		{
			printf("�ɹ�");
			return TRUE;
		}
		fclose(fp);
	}
}
