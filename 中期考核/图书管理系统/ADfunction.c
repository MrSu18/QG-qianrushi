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

	printf( "����������Ҫ��ӵ���ģ���ţ����������ߣ��������\n");
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

		if ((fp=fopen("librarybook.txt","r"))==NULL)
		{
			printf( "���ļ�ʧ�ܣ�\n"
				"�����˳�����\n");
			return ERROR;
			system("pause");
			exit(0);
		}

		int n=0;
		Book temp0;
		DLink head=InitiDL();
		DLink p2=head;
		while(!feof(fp))
		{
			fread(&temp0,sizeof(Book),1,fp);
			n++;
			//printf("test");
		}
		fclose(fp);
		fp=fopen("librarybook.txt","rb+");
		for(int i=0;i<n-1;i++)
		{
			//printf("test");
			fread(&temp0,sizeof(Book),1,fp);
			//printf("test");
			DLink newbook=(DLink)malloc(sizeof(LNode));
			//printf("test");
			if(newbook!=NULL)
			{
				newbook->date.num=temp0.num;
				strcpy(newbook->date.bookname,temp0.bookname);
				strcpy(newbook->date.author,temp0.author);
				newbook->date.booknum=temp0.booknum;
				//printf("%d\t%s\t%s\t%d\n",newbook->date.num,newbook->date.bookname,newbook->date.author,newbook->date.booknum);
				p2->next=newbook;
				p2=newbook;
				newbook->next=NULL;
			}
		}
		fclose(fp);

		p2=head->next;//���������ݴ�����ݽ����޸�
		int flag=0;
		while(p2!=NULL)
		{
			if(temp[0].num==p2->date.num)
			{
				printf("�˱�ŵ����Ѵ��ڣ��޷��������룡\n");
				system("pause");
				return ERROR;
			}
			else if(strcmp(temp[0].bookname,p2->date.bookname)==0&&strcmp(temp[0].author,p2->date.author)==0)
			{
				p2->date.booknum=p2->date.booknum+temp[0].booknum;
				flag++;
				printf("��������ͼ����У����ӿ������\n");
			}
			p2=p2->next;
		}

		fp=fopen("librarybook.txt","w");//���ô򿪹ر��������֮���ٰ��޸�֮����������ݴ���
		fclose(fp);
		fp=fopen("librarybook.txt","a");
		if(!fp)
		{
			printf("�����޿���ļ���");
		}
		p2=head->next;
		while(p2!=NULL)
		{
			fwrite(&(p2->date),sizeof(Book),1,fp);
			p2=p2->next;
		}

		if(flag==0)
		{
			fwrite(&temp[0],sizeof(Book),1,fp);
		}

		fclose(fp);

		printf( "ͼ�����ɹ���\n"
			"����f�˳�\n");
		scanf("%c",&choose);
		if(choose=='f')//ESC
		{
			break;
		}
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
		fread(&temp[i],sizeof(Book),1,fp);
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
				//DLink newbook=(DLink)malloc(sizeof(LNode));
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


Status zhuceyonhu()
{
	char username[20];
	char password[20];
	printf( "\n\n\n\n\n\n\n\n"
		"\t\t\t\t��������Ҫע����û�����");
	gets(username);
	printf("\t\t\t\t������ע�������:");
	gets(password);

	FILE*fp;

	fp=fopen("userpassword.txt","a");
	fprintf(fp,"%s %s\n",username,password);
	printf("\t\t\t\tע��ɹ�\n");
	fclose(fp);
	system("pause");
	return SUCCESS;
}
