#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Librarymanagementsystem.h"

DLink InitiDL()
{
	DLink head = (DLink)malloc(sizeof(LNode));
	if(head)
	{
		head->data=0;
		head->next=head->prev=head;
		//head->next=NULL;
		//head->prev=NULL;
	}
	return head;
}

void traval(DLink head)
{
	//int test=0;
	//printf("test");
	//DLink shu=NULL;
	DLink shu=head->next;
	//shu->date.num=1;
	//shu->date.booknum=2;
	//gets(shu->date.bookname);
	//gets(shu->date.author);
	//shu->next=NULL;
	//if(shu==NULL)
	//{
		//printf("³ö´í");
	//}
	while(shu!=NULL)
	{
		printf("%d\t%s\t%s\t%d\n",shu ->date.num,shu->date.bookname,shu->date.author,shu->date.booknum);
		shu=shu->next;
		//test++;
	}
	//printf("%d",test);
}

