#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Librarymanagementsystem.h"

Status readbook()
{
	//printf("%d",booktype);
	Book temp[10];
	int n=1,i=0;
	FILE*fp;
	fp=fopen("librarybook.txt","r");
	if(!fp)
	{
		printf("出错，无库存文件！");
		return ERROR;
	}
	printf("编号\t书名\t作者\t库存量\n");
	fread(&temp[i],sizeof(Book),n,fp);
	while(!feof(fp))
	{
		//int num=0;char bookname[20]={'\0'},author[10]={'\0'};int kucunnum=0;
		//fscanf(fp,"%d%s%s%d",&num,bookname,author,&kucunnum);
		printf("%d\t%s\t%s\t%d\t\n",temp[i].num,temp[i].bookname,temp[i].author,temp[i].booknum);//将printf函数放在fread前面可以起到先输出再移动指针的效果这样可以让多出来循环一次读到的数据不显示
		n++;i++;
		fread(&temp[i],sizeof(Book),n,fp);
		//printf("%d",num);
		//printf("%d\t%s\t%s\t%d\t\n",num,bookname,author,kucunnum);
		//printf("%d\t%s\t%s\t%d\t\n",temp[i].num,temp[i].bookname,temp[i].author,temp[i].booknum);
		//n++;i++;
	}
	fclose(fp);

	printf("一共有%d种书",(n-1));
	return SUCCESS;
}


void searchbook()
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
		return ERROR;
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
			//printf("%d\t%s\t%s\t%d\t\n",num,bookname,author,kucunnum);
			//return SUCCESS;
			//break;
		}
		//else
		//{
			//printf("请稍等\n");
			//return ERROR;
		//}
		i++;n++;
	}
	if(n==0)
	{
		printf("没有找到这本书\n");
	}
	fclose(fp);
}
