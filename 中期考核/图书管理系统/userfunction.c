#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Librarymanagementsystem.h"

Status readbook()//����ͼ��
{
	//printf("%d",booktype);
	Book temp[10];
	int n=0,i=0;
	FILE*fp;
	fp=fopen("librarybook.txt","r");
	if(!fp)
	{
		printf("�����޿���ļ���");
		return ERROR;
	}
	printf("���\t����\t����\t�����\n");
	//fread(&temp[i],sizeof(Book),n,fp);
	while(!feof(fp))
	{
		fread(&temp[i],sizeof(Book),1,fp);
		n++;
		//printf("%d\n",count);
	}
	//����fp��ָ���ַ
	fclose(fp);
	fp=fopen("librarybook.txt","r");
	//******************************
	for(i=0;i<n-1;i++)
	{
		fread(&temp[i],sizeof(Book),1,fp);
		printf("%d\t%s\t%s\t%d\t\n",temp[i].num,temp[i].bookname,temp[i].author,temp[i].booknum);
	}
	fclose(fp);

	printf("һ����%d����\n",(n-1));
	return SUCCESS;
}


void searchbook()//����ͼ��
{
	//int num=0;char bookname[20]={'\0'},author[10]={'\0'};int kucunnum=0;
	Book temp[10];
	char lookupbook[30];
	int n=0,i=0;
	FILE*fp;
	fp=fopen("librarybook.txt","r");
	if(!fp)
	{
		printf("�����޿���ļ���");
	}
	printf("��������ҵ������������ߣ�");
	scanf("%s",lookupbook);
	while(!feof(fp))
	{
		//fscanf(fp,"%d\t%s\t%s\t%d\t",&num,bookname,author,&kucunnum);
		fread(&temp[i],sizeof(Book),n,fp);
		if(strcmp(temp[i].bookname,lookupbook)==0||strcmp(temp[i].author,lookupbook)==0)
		{
			printf("%d\t%s\t%s\t%d\t\n",temp[i].num,temp[i].bookname,temp[i].author,temp[i].booknum);
		}
		i++;n++;
	}
	if(n==0)
	{
		printf("û���ҵ��Ȿ��\n");
	}
	fclose(fp);
}

//************************************************************************
//���鹦�ܺ���
void lendbook(DLink head)
{
	FILE *fp;
	FILE *fp1;

	pStudent head1=Initi();
	//�ݴ�����
	Book temp[10];
	//��¼�����ͬѧ
	yonhu a;
	yonhu temp1;
	//���ļ�
	fp=fopen("librarybook.txt","rb+");
	if(!fp)
	{
		printf("�����޿���ļ���");
	}
	fp1=fopen("reader.txt","a+");
	if(!fp1)
	{
		printf("�����޿���ļ���");
	}
	//����ʱ�����������Ϣ������Ƿ���ͼ����û�
	printf("���������ĸ�����Ϣ��\n");
	printf("�꼶רҵ�༶��");
	scanf("%s",a.CLASS);
	printf("ѧ�ţ�");
	scanf("%s",a.ID);
	printf("������");
	scanf("%s",a.stuname);

	Student *p;
	p=head1;

	while(!feof(fp1))
	{
		//printf("test\n");
		fscanf(fp1,"%s\t%s\t%s\t\n",temp1.CLASS,temp1.ID,temp1.stuname);
		printf("%s\t%s\t%s\t\n",temp1.CLASS,temp1.ID,temp1.stuname);
		if(head1)
		{
			pStudent newyonhu=(pStudent)malloc(sizeof(Student));
			if(newyonhu)
			{
				//����ȡ���������ݷ�������
				strcpy(newyonhu->shuju.CLASS,temp1.CLASS);
				strcpy(newyonhu->shuju.ID,temp1.ID);
				strcpy(newyonhu->shuju.stuname,temp1.stuname);
				//����insert
				p->next=newyonhu;
				newyonhu->next=NULL;
				p=newyonhu;

			}
		}
	}

	int flag;//������¼�û��Ƿ����
	pStudent p1=head1->next;
	while(p1!=head1)
	{
		if(strcmp(p1->shuju.CLASS,a.CLASS)==0&&strcmp(p1->shuju.ID,a.ID)==0&&strcmp(p1->shuju.stuname,a.stuname)==0)//���ļ��е����ݺͽ�������Ϣ���бȶ�
		{
			printf("����ɹ���");
			flag++;
			break;
		}
		else if(strcmp(p1->shuju.CLASS,a.CLASS)==0||strcmp(p1->shuju.ID,a.ID)==0||strcmp(p1->shuju.stuname,a.stuname)==0)
		{
			printf("�û����ڣ������ְ༶ѧ�Ų���ȫ��Ӧ������ʧ��!\n");
			flag++;
			break;
		}
		p1=p1->next;
	}
	if(flag==0)
	{
		printf("�û������ڣ�");
	}
	fclose(fp1);
	//printf("test1");
	//�ҵ��û���֮�����ͼ�����н������
	DLink p2;
	//printf("test2\n");
	p2=head;
	//printf("test3\n");
	int i=0,n=0;
	while(!feof(fp))
	{
		fread(&temp[i],sizeof(Book),1,fp);
		n++;
	}
	fclose(fp);
	fp=fopen("librarybook.txt","rb+");
	for(i=0;i<n-1;i++)
	{
		//printf("test4\n");
		//fscanf(fp,"%d\t%s\t%s\t%d\n",&temp[i].num,temp[i].bookname,temp[i].author,&temp[i].booknum);
		fread(&temp[i],sizeof(Book),1,fp);
		//printf("test5\n");
		printf("%d\t%s\t%s\t%d\n",temp[i].num,temp[i].bookname,temp[i].author,temp[i].booknum);
		//printf("test6\n");
		DLink newbook=(DLink)malloc(sizeof(LNode));
		//printf("test7\n");
		if(newbook)
		{
			newbook->date.num=temp[i].num;
			strcpy(newbook->date.bookname,temp[i].bookname);
			strcpy(newbook->date.author,temp[i].author);
			newbook->date.booknum=temp[i].booknum;

			p2->next=newbook;
			p2=newbook;
			newbook->next=NULL;
		}
	}
	//printf("test");
	fclose(fp);
	//traval(head);

	//���û�����ͼ����Ϣ�ҵ��Ǹ��ļ�
	printf("������Ҫ����ͼ��ı��");
	while(scanf("%d",&temp[9].num)==0||getchar()!='\n')
	{
		printf("\t�����˷Ƿ��ַ������������룺");
		while (getchar() != '\n');
	}

	p2=head->next;
	while(p2!=NULL)
	{
		if((p2->date.num)==temp[9].num)
		{
			p2->date.booknum=p2->date.booknum-1;
		}
		p2=p2->next;
	}
	//traval(head);

	fp=fopen("librarybook.txt","w");
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
	fclose(fp);
}
//**************************************************************************
//���鹦�ܺ���
Status returnbook(DLink head)
{
	FILE *fp;//������reader.txt�ļ�
	FILE *fp1;//������librarybook.txt

        //��������˵���Ϣ,���������¼
	pStudent head1=Initi();//��ʼ��һ����ȡ����ѧ����Ϣ������
	yonhu return_data;//����һ�������洢����ͬѧ��Ϣ�ı���
	yonhu temp;//������ȡtxt��ʱ���𵽸����������

	printf("���������ĸ�����Ϣ��\n");
	printf("�꼶רҵ�༶��");
	scanf("%s",return_data.CLASS);
	printf("ѧ�ţ�");
	scanf("%s",return_data.ID);
	printf("������");
	scanf("%s",return_data.stuname);
//printf("test1\n");
	fp=fopen("reader.txt","r");
	if(!fp1)
	{
		printf("�����޿���ļ���");
		return ERROR;
	}
//printf("test2\n");
	pStudent p=head1;
	while(!feof(fp))
	{
		fscanf(fp,"%s\t%s\t%s\n",temp.CLASS,temp.ID,temp.stuname);

		pStudent message=(pStudent)malloc(sizeof(Student));
		if(message!=NULL)
		{
			strcpy(message->shuju.CLASS,temp.CLASS);
			strcpy(message->shuju.ID,temp.ID);
			strcpy(message->shuju.stuname,temp.stuname);

			p->next=message;
			message->prev=p;
			message->next=NULL;
			p=message;
		}
	}
//printf("test3\n");
	p=head1->next;
	while(p!=NULL)
	{
		//printf("test\n");
		if(strcmp(return_data.CLASS,p->shuju.CLASS)==0&&strcmp(return_data.ID,p->shuju.ID)==0&&strcmp(return_data.stuname,p->shuju.stuname)==0)
		{
			p->prev->next=p->next;
			//printf("test\n");
			p->next->prev=p->prev;
			//printf("test\n");//�Ѻͻ�������Ϣһ���Ľ��ɾȥ
			free(p);
			//printf("test\n");
			break;
		}
		else
		{
			p=p->next;
		}
	}
	if(p==NULL)
	{
		printf("���û�δ���Ĺ�ͼ�飬����ʧ��!\n");
		printf("���������ⰴ�����ز˵���\n");
		system("pause");
		return ERROR;
	}
//printf("test4\n");
	fclose(fp);




	//����ͼ����Ϣ��ͼ��黹
	Book return_book;
	Book temp1;
	DLink p2=head;

	printf("����������黹��ͼ�������������\n");
	printf("������");
	scanf("%s",return_book.bookname);
	printf("���ߣ�");
	scanf("%s",return_book.author);

	fp1=fopen("librarybook.txt","rb+");
	if(!fp)
	{
		printf("�����޿���ļ���");
		system("pause");
		return ERROR;
	}

	int n=0;//��ȡ�ļ������ݴ洢������ͽ���һ���ĵ���
	while(!feof(fp1))
	{
		fread(&temp1,sizeof(Book),1,fp1);
		n++;
	}
	fclose(fp1);
	fp=fopen("librarybook.txt","rb+");
	for(int i=0;i<n-1;i++)
	{
		fread(&temp1,sizeof(Book),1,fp1);
		DLink newbook=(DLink)malloc(sizeof(LNode));
		if(newbook)
		{
			newbook->date.num=temp1.num;
			strcpy(newbook->date.bookname,temp1.bookname);
			strcpy(newbook->date.author,temp1.author);
			newbook->date.booknum=temp1.booknum;

			p2->next=newbook;
			p2=newbook;
			newbook->next=NULL;
		}
	}
	fclose(fp1);

	p2=head->next;//���������ݴ�����ݽ����޸�
	int flag=0;
	while(p2!=NULL)
	{
		if(strcmp(return_book.bookname,p2->date.bookname)==0&&strcmp(return_book.author,p2->date.author)==0)
		{
			p2->date.booknum=p2->date.booknum+1;
			flag++;
		}
		p2=p2->next;
	}

	//����Ҳ���Ҫ������
	if(flag==0)
	{
		printf("ͼ�����û�и�ͼ�飬����ʧ�ܣ�\n");
		system("pause");
		return ERROR;
	}

	//�޸ı��ؼ�¼���������¼����Ϣ
	fp=fopen("reader.txt","w");
	fclose(fp);
	fp=fp=fopen("reader.txt","a");
	if(!fp)
	{
		printf("�����޿���ļ���");
		system("pause");
		return ERROR;
	}
	pStudent p1=head1->next;
	while(p1!=NULL)
	{
		fprintf(fp,"%s\t%s\t%s\n",p1->shuju.CLASS,p1->shuju.ID,p1->shuju.stuname);
		p1=p1->next;
	}
	fclose(fp);


	fp1=fopen("librarybook.txt","w");//���ô򿪹ر��������֮���ٰ��޸�֮����������ݴ���
	fclose(fp1);
	fp1=fopen("librarybook.txt","a");
	if(!fp1)
	{
		printf("�����޿���ļ���");
	}
	p2=head->next;
	while(p2!=NULL)
	{
		fwrite(&(p2->date),sizeof(Book),1,fp1);
		p2=p2->next;
	}
	fclose(fp);
	printf("����ɹ�!\n");
	system("pause");
	return SUCCESS;

}
