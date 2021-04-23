#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Librarymanagementsystem.h"
//添加图书函数
Status addbook()
{
	Book temp[10];
	char choose;
	FILE *fp;

	printf( "请输入所需要添加的书的，编号，书名，作者，入库数：\n");
	while(1)
	{

		printf("\n请输入编号:");
		while(scanf("%d",&temp[0].num)==0||getchar()!='\n')
		{
			printf("输入了非法字符，请重新输入：");
			while (getchar() != '\n');
		}
		printf("\n请输入书名:");
		gets(temp[0].bookname);
		printf("\n请输入作者:");
		gets(temp[0].author);
		printf("\n请输入入库数:");
		while(scanf("%d",&temp[0].booknum)==0||getchar()!='\n')
		{
			printf("输入了非法字符，请重新输入：");
			while (getchar() != '\n');
		}

		if ((fp=fopen("librarybook.txt","r"))==NULL)
		{
			printf( "打开文件失败！\n"
				"即将退出程序！\n");
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

		p2=head->next;//对链表中暂存的数据进行修改
		int flag=0;
		while(p2!=NULL)
		{
			if(temp[0].num==p2->date.num)
			{
				printf("此编号的书已存在，无法继续存入！\n");
				system("pause");
				return ERROR;
			}
			else if(strcmp(temp[0].bookname,p2->date.bookname)==0&&strcmp(temp[0].author,p2->date.author)==0)
			{
				p2->date.booknum=p2->date.booknum+temp[0].booknum;
				flag++;
				printf("该书已在图书库中，增加库存量！\n");
			}
			p2=p2->next;
		}

		fp=fopen("librarybook.txt","w");//采用打开关闭清空数据之后再把修改之后的链表数据存入
		fclose(fp);
		fp=fopen("librarybook.txt","a");
		if(!fp)
		{
			printf("出错，无库存文件！");
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

		printf( "图书入库成功！\n"
			"输入f退出\n");
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
		printf("出错，无库存文件！");
		return ERROR;
	}
	printf("请输入查删除的书名或者作者：");
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
				//将书名作者复制到链表
				newbook->date.num=temp[i].num;
				strcpy(newbook->date.bookname,temp[i].bookname);
				strcpy(newbook->date.author,temp[i].author);
				newbook->date.booknum=temp[i].booknum;
				//将链表插入
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
		printf("出错，无库存文件！");
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
		"\t\t\t\t请输入你要注册的用户名：");
	gets(username);
	printf("\t\t\t\t请输入注册的密码:");
	gets(password);

	FILE*fp;

	fp=fopen("userpassword.txt","a");
	fprintf(fp,"%s %s\n",username,password);
	printf("\t\t\t\t注册成功\n");
	fclose(fp);
	system("pause");
	return SUCCESS;
}
