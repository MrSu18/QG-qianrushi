#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Librarymanagementsystem.h"
//���ͼ�麯��
Status addbook()
{
	Book temp[10];
	char choose;
	FILE *fp;
	if ((fp=fopen("librarybook.txt","a"))==NULL)
	{
		printf( "���ļ�ʧ�ܣ�\n"
			"�����˳�����\n");
		return ERROR;
		system("pause");
		exit(0);
	}
	printf( "����������Ҫ��ӵ���ģ���ţ����������ߣ��������\n");
	//int num=0;char bookname[20],author[10];int addnum=0;
	while(1)
	{
		printf("\n��������:");
		while(scanf("%d",&temp[0].num)==0||getchar()!='\n')
		{
			printf("�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		printf("\n����������:");
		gets(temp[0].bookname);
		printf("\n����������:");
		gets(temp[0].author);
		printf("\n�����������:");
		while(scanf("%d",&temp[0].booknum)==0||getchar()!='\n')
		{
			printf("�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		fwrite(&temp[0],sizeof(Book),1,fp);
		//fprintf(fp,"%d,%s,%s,%d\n",num,bookname,author,addnum);
		//printf("%d%s%s%d\n",num,bookname,author,addnum);
		printf( "ͼ�����ɹ���\n"
			"����f�˳�\n");
		scanf("%c",&choose);
		//getchar();
		//choose=getchar();
		//printf("%c",choose);
		if(choose=='f')//ESC
		{
			break;
		}
		//ooktype++;
		jilushubenzhonlei(&booktype);
	}
	fclose(fp);
	return SUCCESS;
}


int jilushubenzhonlei(int *x)
{
	(*x)++;
	return *x;
}

void deletebook(DLink head)
{
	DLink p;
	p=head;
	Book temp[10];
	char debook[30];
	int n=1,i=0;
	FILE*fp;
	fp=fopen("librarybook.txt","r");
	if(!fp)
	{
		printf("�����޿���ļ���");
		return ERROR;
	}
	printf("�������ɾ���������������ߣ�");
	scanf("%s",debook);
	int c;
	c=feof(fp);
	printf("feof(fp)=%d",c);
	while(!feof(fp))
	{
		int c;
		c=feof(fp);
		printf("feof(fp)=%d",c);
		fread(&temp[i],sizeof(Book),n,fp);
		printf("%d\t%s\t%s\t%d\t\n",temp[i].num,temp[i].bookname,temp[i].author,temp[i].booknum);
		if(strcmp(temp[i].bookname,debook)==0||strcmp(temp[i].author,debook)==0)
		{
			n++;i++;
			continue;
		}
		else
		{
			DLink newbook=(DLink)malloc(sizeof(LNode));
			 if(newbook!=NULL)
			{
				DLink newbook=(DLink)malloc(sizeof(LNode));
				//���������߸��Ƶ�����
				newbook->date.num=temp[i].num;
				strcpy(newbook->date.bookname,temp[i].bookname);
				strcpy(newbook->date.author,temp[i].author);
				newbook->date.booknum=temp[i].booknum;
				//���������
				p->next=newbook;
				p=newbook;
				newbook->next=NULL;
			}
			n++;i++;
		}

	}
	printf("\n");
	traval(head);

	fclose(fp);

	fp=fopen("librarybook.txt","w");
	fclose(fp);
	fp=fopen("librarybook.txt","a");
	if(!fp)
	{
		printf("�����޿���ļ���");
		return ERROR;
	}
	DLink shu=head->next;
	while(shu!=NULL)
	{
		fwrite(&(shu->date),sizeof(Book),1,fp);
		shu=shu->next;
	}
	fclose(fp);
}
