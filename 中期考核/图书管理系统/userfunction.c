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
	FILE*fp;
	int n,i,FLAG=0;
	searchbookmenu();

	int opotion;
	printf("\t\t\t\t请输入你的选项：");
	while(scanf("%d",&opotion)==0||getchar()!='\n')
	{
		printf("\t\t\t\t输入了非法字符，请重新输入：");
		while (getchar() != '\n');
	}
	switch(opotion)
	{
	case 1:
		{
			Book temp;
			int num;
			printf("\t\t\t\t请输入查询的图书编号：");
			while(scanf("%d",&num)==0||getchar()!='\n')
			{
				printf("\t\t\t\t输入了非法字符，请重新输入：");
				while (getchar() != '\n');
			}
			fp=fopen("librarybook.txt","r");
			if(!fp)
			{
				printf("\t\t\t\t出错，无库存文件！");
				system("pause");
				break;
			}
			n=0,i=0;
			while(!feof(fp))
			{
				fread(&temp,sizeof(Book),1,fp);
				n++;
			}
			fclose(fp);
			fp=fopen("librarybook.txt","r");
			for(i=0;i<n-1;i++)
			{
				fread(&temp,sizeof(Book),1,fp);
				if(temp.num==num)
				{
					printf("\t\t\t\t%d\t%s\t%s\t%d\t\n",temp.num,temp.bookname,temp.author,temp.booknum);
					FLAG++;
				}
			}
			if(FLAG==0)
			{
				printf("\t\t\t\t没有找到这本书\n");
				break;
			}
			else
			{
				printf("\t\t\t\t有%d种图书",i);
			}
			fclose(fp);
			break;
		}
	case 2:
		{
			Book temp;
			char bookname[10];
			printf("\t\t\t\t请输入查询的图书名：");
			gets(bookname);
			fp=fopen("librarybook.txt","r");
			if(!fp)
			{
				printf("\t\t\t\t出错，无库存文件！");
				system("pause");
				break;
			}
			n=0,i=0;
			while(!feof(fp))
			{
				fread(&temp,sizeof(Book),1,fp);
				n++;
			}
			fclose(fp);
			fp=fopen("librarybook.txt","r");
			for(i=0;i<n-1;i++)
			{
				fread(&temp,sizeof(Book),1,fp);
				if(!strcmp(temp.bookname,bookname))
				{
					printf("\t\t\t\t%d\t%s\t%s\t%d\t\n",temp.num,temp.bookname,temp.author,temp.booknum);
					FLAG++;
				}
			}
			if(FLAG==0)
			{
				printf("\t\t\t\t没有找到这本书\n");
				break;
			}
			else
			{
				printf("\t\t\t\t有%d种图书",i);
			}
			fclose(fp);
			break;
		}
	case 3:
		{
			Book temp;
			char auth[10];
			printf("\t\t\t\t请输入查询的作者：");
			gets(auth);
			fp=fopen("librarybook.txt","r");
			if(!fp)
			{
				printf("\t\t\t\t出错，无库存文件！");
				system("pause");
				break;
			}
			n=0;

			while(!feof(fp))
			{
				fread(&temp,sizeof(Book),1,fp);
				n++;
			}
			fclose(fp);
			fp=fopen("librarybook.txt","r");
			for(i=0;i<n-1;i++)
			{
				fread(&temp,sizeof(Book),1,fp);
				if(!strcmp(temp.author,auth))
				{
					printf("\t\t\t\t%d\t%s\t%s\t%d\t\n",temp.num,temp.bookname,temp.author,temp.booknum);
					FLAG++;
				}
			}
			if(FLAG==0)
			{
				printf("\t\t\t\t没有找到这本书\n");
				break;
			}
			else
			{
				printf("\t\t\t\t有%d种图书",i);
			}
			fclose(fp);
			break;
		}
	case 4:
		{
			Book temp;
			int booknum;
			printf("\t\t\t\t请输入查询的图书库存量：");
			while(scanf("%d",&booknum)==0||getchar()!='\n')
			{
				printf("\t\t\t\t输入了非法字符，请重新输入：");
				while (getchar() != '\n');
			}
			fp=fopen("librarybook.txt","r");
			if(!fp)
			{
				printf("\t\t\t\t出错，无库存文件！");
				system("pause");
				break;
			}
			n=0,i=0;
			while(!feof(fp))
			{
				fread(&temp,sizeof(Book),1,fp);
				n++;
			}
			fclose(fp);
			fp=fopen("librarybook.txt","r");
			for(i=0;i<n-1;i++)
			{
				fread(&temp,sizeof(Book),1,fp);
				if(temp.booknum==booknum)
				{
					printf("%d\t%s\t%s\t%d\t\n",temp.num,temp.bookname,temp.author,temp.booknum);
					FLAG++;
				}
			}
			if(FLAG==0)
			{
				printf("\t\t\t\t没有找到这本书\n");
				break;
			}
			else
			{
				printf("\t\t\t\t有%d种图书",i);
			}
			fclose(fp);
			break;
		}
	case 0:
		system("cls");
		Usermenu();
		Userselect();
		break;
	}
}

//************************************************************************
//借书功能函数
Status lendbook(DLink head)
{

	readbook();

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
		return ERROR;
	}


	//查找图书库进行借书操作
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
		fread(&temp[i],sizeof(Book),1,fp);
		DLink newbook=(DLink)malloc(sizeof(LNode));
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
	//traval(head);

	//让用户输入图书信息找到那个文件
	printf("请输入要借阅图书的编号");
	while(scanf("%d",&temp[9].num)==0||getchar()!='\n')
	{
		printf("输入了非法字符，请重新输入：");
		while (getchar() != '\n');
	}

	p2=head->next;
	while(p2!=NULL)
	{
		if((p2->date.num)==temp[9].num)
		{
			if(p2->date.booknum==0)
			{
				printf("图书库中该书已被借完，需要办理预约吗？");
				yuyuemenu();
				yuyue(temp[9].num);
				return ERROR;
			}
			else
			{
				p2->date.booknum=p2->date.booknum-1;
			}
		}
		p2=p2->next;
	}
	//traval(head);
	fclose(fp);

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
	fclose(fp);
	//以上把书借出去的操作就完成了


	//接下来进行输入借书人信息的操作
	fp1=fopen("reader.txt","a+");
	if(!fp1)
	{
		printf("出错，无库存文件！");
		return ERROR;
	}

	//借阅时候输入个人信息，记录个人信息，保存在本地
	printf("请输入您的个人信息：\n");
	printf("年级专业班级：");
	scanf("%s",a.CLASS);
	printf("学号：");
	scanf("%s",a.ID);
	printf("姓名：");
	scanf("%s",a.stuname);

	fprintf(fp1,"%s\t%s\t%s\n",a.CLASS,a.ID,a.stuname);
	fclose(fp1);

	printf("借书成功！");
	system("pause");
	return SUCCESS;




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
			message->next=head1;
			p=message;
		}
	}
//printf("test3\n");
	int flag=0;
	p=head1->next;
	while(p!=head1)
	{
		if(strcmp(return_data.CLASS,p->shuju.CLASS)==0&&strcmp(return_data.ID,p->shuju.ID)==0&&strcmp(return_data.stuname,p->shuju.stuname)==0)
		{
			p->prev->next=p->next;
			p->next->prev=p->prev;//把和还书人信息一样的结点删去
			free(p);
			flag++;
			break;
		}
		else
		{
			p=p->next;
		}
	}
	if(flag==0)
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

	printf("请输入你想归还的图书的编号、书名和作者\n");
	printf("编号:");
	while(scanf("%d",&return_book.num)==0||getchar()!='\n')
	{
		printf("输入了非法字符，请重新输入：");
		while (getchar() != '\n');
	}
	printf("书名：");
	scanf("%s",return_book.bookname);
	printf("作者：");
	scanf("%s",return_book.author);

	fp1=fopen("librarybook.txt","rb+");
	if(!fp1)
	{
		printf("出错，无库存文件！");
		system("pause");
		return ERROR;
	}
//printf("test1");
	int n=0;//读取文件的内容存储到链表和借书一样的道理
	while(!feof(fp1))
	{
		fread(&temp1,sizeof(Book),1,fp1);
		n++;
	}
	fclose(fp1);
//printf("test1");
	fp1=fopen("librarybook.txt","rb+");
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
//printf("tset1\n");
	//对预约者.txt进行处理
	FILE*fp3;
	fp3=fopen("jieyue.txt","r");
	if(!fp3)
	{
		printf("出错，无库存文件！");
		system("pasue");
		return ERROR;
	}
	//printf("test1\n");
        yonhu temp3;//读取预约用户信息
        //printf("test1\n");
        pStudent head3=Initi();
        //printf("test1\n");
        pStudent p3=head3;
        //printf("test1\n");
        while(!feof(fp3))
	{
		//printf("test1\n");
		fscanf(fp3,"%s\t%s\t%s\t%d\n",&temp3.CLASS,&temp3.ID,&temp3.stuname,&temp3.yuyuenum);
		//printf("test1\n");
		pStudent message=(pStudent)malloc(sizeof(Student));
		if(message!=NULL)
		{
			//printf("test1\n");
			strcpy(message->shuju.CLASS,temp3.CLASS);
			strcpy(message->shuju.ID,temp3.ID);
			strcpy(message->shuju.stuname,temp3.stuname);
			message->shuju.yuyuenum=temp3.yuyuenum;
//printf("test1\n");
			p3->next=message;
			message->prev=p3;
			message->next=head3;
			p3=message;
		}
	}
//printf("tset1\n");
	//搜寻比对，若有相同则剔除
	pStudent T2=head1;
	int FLAG=0;
	p3=head3->next;
	while(p3!=head3)
	{
		if(p3->shuju.yuyuenum==return_book.num)
		{
			p3->prev->next=p3->next;
			p3->next->prev=p3->prev;//把和预约信息一样的结点删去

			//printf("tset1\n");
			p3->next=head1->next;
			//printf("tset1\n");
			p3->next->prev=p3;
			head1->next=p3;
			//printf("tset1\n");
			p3->prev=p;
			//printf("tset1\n");
			//printf("tset1\n");
			FLAG++;
			break;

		}
		else
		{
			p3=p3->next;
		}
	}
	fclose(fp3);

	fp3=fopen("jieyue.txt","w");
	fclose(fp3);
	fp3=fopen("jieyue.txt","a");
	if(!fp3)
	{
		printf("出错，无库存文件！");
		system("pause");
		return ERROR;
	}
	pStudent T=head3->next;
	while(T!=head3)
	{
		//printf("test1");
		fprintf(fp3,"%s\t%s\t%s\t%d\n",T->shuju.CLASS,T->shuju.ID,T->shuju.stuname);
		T=T->next;
	}
	fclose(fp3);


	if(FLAG==0)
	{
		p2=head->next;//对链表中暂存的数据进行修改
		int flag1=0;
		while(p2!=NULL)
		{
			if(strcmp(return_book.bookname,p2->date.bookname)==0&&strcmp(return_book.author,p2->date.author)==0)
			{
				p2->date.booknum=p2->date.booknum+1;
				flag1++;
			}
			p2=p2->next;
		}
	//printf("test1");
		//如果找不到要还的书
		if(flag1==0)
		{
			printf("图书馆内没有该图书，还书失败！\n");
			system("pause");
			return ERROR;
		}
	//printf("test1");
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
		fclose(fp1);
	}
//printf("test1");

	//修改本地记录消除借书记录的信息
	fp=fopen("reader.txt","w");
	fclose(fp);
	fp=fopen("reader.txt","a");
	if(!fp)
	{
		printf("出错，无库存文件！");
		system("pause");
		return ERROR;
	}
	pStudent p1=head1->next;
	while(p1!=head1)
	{
		//printf("test1");
		fprintf(fp,"%s\t%s\t%s\n",p1->shuju.CLASS,p1->shuju.ID,p1->shuju.stuname);
		p1=p1->next;
	}
	fclose(fp);

	printf("还书成功!\n");
	system("pause");
	return SUCCESS;

}


//*********************************
//预约图书函数
Status yuyue(int x)
{
	char choose;
	scanf("%c",&choose);
	switch(choose)
	{
	case 'a':
		{
			yonhu a;
			printf("请输入您的个人信息：\n");
			printf("年级专业班级：");
			scanf("%s",a.CLASS);
			printf("学号：");
			scanf("%s",a.ID);
			printf("姓名：");
			scanf("%s",a.stuname);

			FILE *fp;
			fp=fopen("jieyue.txt","a");
			if(!fp)
			{
				printf("出错，无库存文件！");
				return ERROR;
			}
			fprintf(fp,"%s\t%s\t%s\t%d\n",a.CLASS,a.ID,a.stuname,x);
			fclose(fp);
			printf("预约成功!");
			system("pause");
			return SUCCESS;
			break;
		}
	case 'b':
		{
			return ERROR;
			break;
		}
	default:
		printf("非法输入，请重新输入!\n");
		system("pause");
		system("cls");
		yuyuemenu();
		yuyue(x);
		break;
	}
}
