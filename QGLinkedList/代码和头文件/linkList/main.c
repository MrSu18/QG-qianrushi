#include<stdio.h>
#include <stdlib.h>
#include "linkedList.h"
int main()
{
	jiemian();
	int option,status;
	ElemType x,e;
	LinkedList search=NULL,head=NULL,p=NULL,q=NULL,tail;
	LinkedList count=(LinkedList)malloc(sizeof(LinkedList));
	while(1)
	{
		printf("请输入选项：");
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
					InitList(&head);
					p=head;
					printf("成功初始化链表！\n"); 
					break;
				}
			}
			case 2:
			{
				DestroyList(&head);
				printf("链表已被销毁，若要继续使用，请重新初始化\n"); 
				break;
			}
			case 3:
			{
				int i,j;
				LinkedList count=(LinkedList)malloc(sizeof(LinkedList));
				count->next=head;
				printf("请输入你要插入结点的位置：");
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
					printf("请输入你要插入结点的数据：");
					scanf("%d",&x);
					q=newnode(x);
					InsertList(count, q); 
					count=count->next;
				}
				break;
			}
			case 4:
			{
				if(status==1)
				{
					printf("链表为循环链表，请先解除循环列表\n");
				}
				else
				{
					TraverseList(head->next, &visit);
				}
				break;  
			}
			case 5:
			{
				int i,j;
				count->next=head;
				printf("请输入你要删除结点的位置：");
				scanf("%d",&i); 
				for(j=0;(count!=NULL)&&(j<i);j++)
				{
					count=count->next;
				}
				DeleteList(count, &e);
				break;
		    }
		    case 6:
		    {
		    	ReverseList(&head);
		    	printf("链表反转已完成！"); 
		    	break;
			}
			case 7:
			{
				int j;
				if(status==1)
				{
					printf("链表已经成环，无需再次成环\n"); 
				} 
				else
				{
					count->next=head;
					for(j=0;(count->next)!=NULL;j++)
					{
						count=count->next;
					}
					count->next=head;
					printf("链表完成成环\n");
					status=1;
				}
				break; 
			}
			case 8:
			{
				if(status==0)
				{
					printf("链表为未环，不需要解除环\n"); 
				}
				else
				{
					count->next=NULL;
					printf("链表完成解除环\n");
					status=0;
				}
				break;
			}
			case 9:
			{
				IsLoopList(head);
				break;
			}
			case 10:
			{
				ReverseEvenList(&head);
				break;
			}
			case 11:
			{
				if(status==1)
				{
					printf("链表为循环链表，请先解除循环列表\n");
				}
				else
				{

					LinkedList p=NULL;
					p=FindMidNode(&(head)); 
					printf("中间的节点的数据为%d\n",p->data);
				}
				break;
			}
			case 12:
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
				printf("非法输入，请重新输入\n");
				break; 
			}
		}
	 } 
}
void jiemian ()
{
	printf("***************************************\n"
		   "          单链表菜单\n"
		   "1、 初始化链表\n" 
		   "2、 摧毁链表\n"
		   "3、 在插入一个结点,并存入数据\n" 
		   "4、 遍历并且输出链表\n"
		   "5、 删除指定位置结点并把值的地址保存在e指针\n"
		   "6、 反转你的链表，你可以遍历再看看值对不对\n"
		   "7、 让你的链表成环\n"
		   "8、 解开循环链表\n" 
		   "9、 判断链表是否成环\n" 
		   "10、让链表中的奇偶反转\n"
		   "11、查询链表中间结点，输出对应的数据域\n"
		   "12、清屏\n"
		   "0、 退出程序\n"
		   
		   "***************************************\n" 
	);
}
