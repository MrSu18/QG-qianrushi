#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Librarymanagementsystem.h"

Status readbook()//总览图书
{
	//printf("%d",booktype);
	Book temp[10];
	int n=0,i=0;
	FILE*fp;
	fp=fopen("librarybook.txt","r");
	if(!fp)
	{
		printf("出错，无库存文件！");
		return ERROR;
	}
	printf("编号\t书名\t作者\t库存量\n");
	//fread(&temp[i],sizeof(Book),n,fp);
	while(!feof(fp))
	{
		fread(&temp[i],sizeof(Book),1,fp);
		n++;
		//printf("%d\n",count);
	}
	//重置fp的指针地址
	fclose(fp);
	fp=fopen("librarybook.txt","r");
	//******************************
	for(i=0;i<n-1;i++)
	{
		fread(&temp[i],sizeof(Book),1,fp);
		printf("%d\t%s\t%s\t%d\t\n",temp[i].num,temp[i].bookname,temp[i].author,temp[i].booknum);
	}
	fclose(fp);

	printf("一共有%d种书\n",(n-1));
	return SUCCESS;
}


void searchbook()//搜索图书
{
	//int num=0;char bookname[20]={'\0'},author[10]={'\0'};int kucunnum=0;
	Book temp[10];
	char lookupbook[30];
	int n=0,i=0;
	FILE*fp;
	fp=fopen("librarybook.txt","r");
	if(!fp)
	{
		printf("出错，无库存文件！");
	}
	printf("请输入查找的书名或者作者：");
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
		printf("没有找到这本书\n");
	}
	fclose(fp);
}

//************************************************************************
//借书功能函数
void lendbook(DLink head)
{
	FILE *fp;
	FILE *fp1;

	pStudent head1=Initi();
	//暂存借的书
	Book temp[10];
	//记录借书的同学
	yonhu a;
	yonhu temp1;
	//打开文件
	fp=fopen("librarybook.txt","rb+");
	if(!fp)
	{
		printf("出错，无库存文件！");
	}
	fp1=fopen("reader.txt","a+");
	if(!fp1)
	{
		printf("出错，无库存文件！");
	}
	//借阅时候输入个人信息，审核是否是图书馆用户
	printf("请输入您的个人信息：\n");
	printf("年级专业班级：");
	scanf("%s",a.CLASS);
	printf("学号：");
	scanf("%s",a.ID);
	printf("姓名：");
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
				//将读取出来的数据放入链表
				strcpy(newyonhu->shuju.CLASS,temp1.CLASS);
				strcpy(newyonhu->shuju.ID,temp1.ID);
				strcpy(newyonhu->shuju.stuname,temp1.stuname);
				//链表insert
				p->next=newyonhu;
				newyonhu->next=NULL;
				p=newyonhu;

			}
		}
	}

	int flag;//用来记录用户是否存在
	pStudent p1=head1->next;
	while(p1!=head1)
	{
		if(strcmp(p1->shuju.CLASS,a.CLASS)==0&&strcmp(p1->shuju.ID,a.ID)==0&&strcmp(p1->shuju.stuname,a.stuname)==0)//将文件中的数据和借书人信息进行比对
		{
			printf("借书成功！");
			flag++;
			break;
		}
		else if(strcmp(p1->shuju.CLASS,a.CLASS)==0||strcmp(p1->shuju.ID,a.ID)==0||strcmp(p1->shuju.stuname,a.stuname)==0)
		{
			printf("用户存在，但名字班级学号不完全对应，借书失败!\n");
			flag++;
			break;
		}
		p1=p1->next;
	}
	if(flag==0)
	{
		printf("用户不存在！");
	}
	fclose(fp1);
	//printf("test1");
	//找到用户名之后查找图书库进行借书操作
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

	//让用户输入图书信息找到那个文件
	printf("请输入要借阅图书的编号");
	while(scanf("%d",&temp[9].num)==0||getchar()!='\n')
	{
		printf("\t输入了非法字符，请重新输入：");
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
		printf("出错，无库存文件！");
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
//还书功能函数
Status returnbook(DLink head)
{
	FILE *fp;//用来开reader.txt文件
	FILE *fp1;//用来开librarybook.txt

        //处理借书人的信息,消除借书记录
	pStudent head1=Initi();//初始化一个读取借书学生信息的链表
	yonhu return_data;//定义一个用来存储还书同学信息的变量
	yonhu temp;//用来读取txt的时候起到个缓冲的作用

	printf("请输入您的个人信息：\n");
	printf("年级专业班级：");
	scanf("%s",return_data.CLASS);
	printf("学号：");
	scanf("%s",return_data.ID);
	printf("姓名：");
	scanf("%s",return_data.stuname);
//printf("test1\n");
	fp=fopen("reader.txt","r");
	if(!fp1)
	{
		printf("出错，无库存文件！");
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
			//printf("test\n");//把和还书人信息一样的结点删去
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
		printf("该用户未借阅过图书，还书失败!\n");
		printf("请输入任意按键返回菜单！\n");
		system("pause");
		return ERROR;
	}
//printf("test4\n");
	fclose(fp);




	//处理图书信息让图书归还
	Book return_book;
	Book temp1;
	DLink p2=head;

	printf("请输入你想归还的图书的书名和作者\n");
	printf("书名：");
	scanf("%s",return_book.bookname);
	printf("作者：");
	scanf("%s",return_book.author);

	fp1=fopen("librarybook.txt","rb+");
	if(!fp)
	{
		printf("出错，无库存文件！");
		system("pause");
		return ERROR;
	}

	int n=0;//读取文件的内容存储到链表和借书一样的道理
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

	p2=head->next;//对链表中暂存的数据进行修改
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

	//如果找不到要还的书
	if(flag==0)
	{
		printf("图书馆内没有该图书，还书失败！\n");
		system("pause");
		return ERROR;
	}

	//修改本地记录消除借书记录的信息
	fp=fopen("reader.txt","w");
	fclose(fp);
	fp=fp=fopen("reader.txt","a");
	if(!fp)
	{
		printf("出错，无库存文件！");
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


	fp1=fopen("librarybook.txt","w");//采用打开关闭清空数据之后再把修改之后的链表数据存入
	fclose(fp1);
	fp1=fopen("librarybook.txt","a");
	if(!fp1)
	{
		printf("出错，无库存文件！");
	}
	p2=head->next;
	while(p2!=NULL)
	{
		fwrite(&(p2->date),sizeof(Book),1,fp1);
		p2=p2->next;
	}
	fclose(fp);
	printf("还书成功!\n");
	system("pause");
	return SUCCESS;

}
