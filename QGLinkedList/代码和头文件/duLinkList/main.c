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
		printf("���ѡ��Ϊ��");
		while (scanf_s("%d", &option) == 0)
		{
			printf("�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}
		switch(option)
		{
			case 1:
			{
				if(head!=NULL)
				{
					printf("�����Ѿ���ʼ���������ټ�����ʼ��\n"); 
					break;
				} 
				else
				{
					InitList_DuL(&head);
					p=head;
					printf("�ɹ���ʼ������\n"); 
					break;
				}
			}
			case 2:
			{
				DestroyList_DuL(&head);
				printf("�����ѱ����٣���Ҫ����ʹ�ã������³�ʼ��\n");
				break;
			}
			case 3:
			{
				int i,j;
				DuLinkedList count=(DuLinkedList)malloc(sizeof(DuLinkedList));
				count->next=head;
				printf("��������Ҫ����Ľ�㣺");
				scanf("%d",&i); 
				for(j=0;(count!=NULL)&&(j<i);j++)
				{
					count=count->next;
				}
				if((count==NULL)||i==0)
				{
					printf("δ�ҵ�Ҫ����Ľ��\n"); 
				}
				else if(i==1)
				{
					printf("��������Ҫǰ��������ݣ�");
					scanf("%d",&data);
					q=newNode(data); 
					InsertBeforeList_DuL(count, q);
					head=head->prior; 
					break;
				}
				else
				{
					printf("��������Ҫǰ��������ݣ�");
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
				printf("��������Ҫ����Ľ�㣺");
				scanf("%d",&i); 
				for(j=0;(count!=NULL)&&(j<i);j++)
				{
					count=count->next;
				}
				if((count==NULL)||i==0)
				{
					printf("δ�ҵ�Ҫ����Ľ��\n"); 
				}
				else
				{
					printf("��������Ҫβ��������ݣ�");
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
				printf("����������ɾ����Ԫ�أ�");
				scanf("%d",&x);
				search=FindByX(head,x);
				DeleteList_DuL(search,&e);
				break;
			}
			case 7:
			{
				system("cls");//�������� 
				jiemian();
				break;
			}
			case 0:
			{
				printf("���������\n");
				exit(0);
			}
			default:
			{
				printf("�Ƿ����룬������ѡ��\n");
				break;
			}
		}
	}
}
void jiemian()
{
	printf(
	    "*******************************************\n"
	    "              ˫������˵�                 \n"
	    "1����ʼ��˫������\n" 
	    "2�����ٸ�˫������\n"
	    "3����ָ�����֮ǰ����һ�����\n"
	    "4����ָ�����֮�����һ�����\n" 
	    "5����������\n"
	    "6��ɾ������һ����㲢�Ұ����ݱ�����e\n"
	    "7������\n"
	    "0���˳�����\n"
	     
	    "*******************************************\n"
	);
}
