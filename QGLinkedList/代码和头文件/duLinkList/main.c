#include "duLinkedList.h"
#include<stdio.h>
#include <stdlib.h>
void visit(ElemType e)
{
	printf(" %d ",e);
}
int main()
{
	jiemian();
	int option;
	ElemType data;
	ElemType e,x; 
	DuLNode *search;
	DuLinkedList head=NULL,p=NULL,q=NULL,next=NULL;
	while(1)
	{
		printf("你的选项为：");
		while (scanf_s("%d", &option) == 0)
		{
			printf("输入了非法字符，请重新输入：");
			while (getchar() != '\n');
		}
		switch(option)
		{
			case 1:
			{
				if(head!=NULL)
				{
					printf("链表已经初始化，无需再继续初始化\n"); 
					break;
				} 
				else
				{
					InitList_DuL(&head);
					p=head;
					printf("成功初始化链表！\n"); 
					break;
				}
			}
			case 2:
			{
				DestroyList_DuL(&head);
				printf("链表已被销毁，若要继续使用，请重新初始化\n");
				break;
			}
			case 3:
			{
				int i,j;
				DuLinkedList count=(DuLinkedList)malloc(sizeof(DuLinkedList));
				count->next=head;
				printf("请输入你要插入的结点：");
				scanf("%d",&i); 
				for(j=0;(count!=NULL)&&(j<i);j++)
				{
					count=count->next;
				}
				if((count==NULL)||i==0)
				{
					printf("未找到要插入的结点\n"); 
				}
				else if(i==1)
				{
					printf("请输入你要前插结点的数据：");
					scanf("%d",&data);
					q=newNode(data); 
					InsertBeforeList_DuL(count, q);
					head=head->prior; 
					break;
				}
				else
				{
					printf("请输入你要前插结点的数据：");
					scanf("%d",&data);
					q=newNode(data); 
					InsertBeforeList_DuL(count, q);
					break;
				}
			}
			case 4:
			{
				int i,j;
				DuLinkedList count=(DuLinkedList)malloc(sizeof(DuLinkedList));
				count->next=head;
				printf("请输入你要插入的结点：");
				scanf("%d",&i); 
				for(j=0;(count!=NULL)&&(j<i);j++)
				{
					count=count->next;
				}
				if((count==NULL)||i==0)
				{
					printf("未找到要插入的结点\n"); 
				}
				else
				{
					printf("请输入你要尾插结点的数据：");
					scanf("%d",&data);
					q=newNode(data);
					InsertAfterList_DuL(count,q);
					count=count->next;
					break;
				}
			}
			case 5:
			{
				TraverseList_DuL(head, &visit);
				break;
			}
			case 6:
			{
				printf("请输入你想删除的元素：");
				scanf("%d",&x);
				search=FindByX(head,x);
				DeleteList_DuL(search,&e);
				break;
			}
			case 7:
			{
				system("cls");//清屏操作 
				jiemian();
				break;
			}
			case 0:
			{
				printf("程序结束！\n");
				exit(0);
			}
			default:
			{
				printf("非法输入，请重新选择\n");
				break;
			}
		}
	}
}
void jiemian()
{
	printf(
	    "*******************************************\n"
	    "              双向链表菜单                 \n"
	    "1、初始化双向链表\n" 
	    "2、销毁该双向链表\n"
	    "3、在指定结点之前插入一个结点\n"
	    "4、在指定结点之后插入一个结点\n" 
	    "5、遍历链表\n"
	    "6、删除后面一个结点并且把数据保存在e\n"
	    "7、清屏\n"
	    "0、退出程序\n"
	     
	    "*******************************************\n"
	);
}
