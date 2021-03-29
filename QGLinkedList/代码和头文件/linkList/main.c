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
		printf("������ѡ�");
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
					InitList(&head);
					p=head;
					printf("�ɹ���ʼ������\n"); 
					break;
				}
			}
			case 2:
			{
				DestroyList(&head);
				printf("�����ѱ����٣���Ҫ����ʹ�ã������³�ʼ��\n"); 
				break;
			}
			case 3:
			{
				int i,j;
				LinkedList count=(LinkedList)malloc(sizeof(LinkedList));
				count->next=head;
				printf("��������Ҫ�������λ�ã�");
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
					printf("��������Ҫ����������ݣ�");
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
					printf("����Ϊѭ���������Ƚ��ѭ���б�\n");
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
				printf("��������Ҫɾ������λ�ã�");
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
		    	printf("����ת����ɣ�"); 
		    	break;
			}
			case 7:
			{
				int j;
				if(status==1)
				{
					printf("�����Ѿ��ɻ��������ٴγɻ�\n"); 
				} 
				else
				{
					count->next=head;
					for(j=0;(count->next)!=NULL;j++)
					{
						count=count->next;
					}
					count->next=head;
					printf("������ɳɻ�\n");
					status=1;
				}
				break; 
			}
			case 8:
			{
				if(status==0)
				{
					printf("����Ϊδ��������Ҫ�����\n"); 
				}
				else
				{
					count->next=NULL;
					printf("������ɽ����\n");
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
					printf("����Ϊѭ���������Ƚ��ѭ���б�\n");
				}
				else
				{

					LinkedList p=NULL;
					p=FindMidNode(&(head)); 
					printf("�м�Ľڵ������Ϊ%d\n",p->data);
				}
				break;
			}
			case 12:
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
				printf("�Ƿ����룬����������\n");
				break; 
			}
		}
	 } 
}
void jiemian ()
{
	printf("***************************************\n"
		   "          ������˵�\n"
		   "1�� ��ʼ������\n" 
		   "2�� �ݻ�����\n"
		   "3�� �ڲ���һ�����,����������\n" 
		   "4�� ���������������\n"
		   "5�� ɾ��ָ��λ�ý�㲢��ֵ�ĵ�ַ������eָ��\n"
		   "6�� ��ת�����������Ա����ٿ���ֵ�Բ���\n"
		   "7�� ���������ɻ�\n"
		   "8�� �⿪ѭ������\n" 
		   "9�� �ж������Ƿ�ɻ�\n" 
		   "10���������е���ż��ת\n"
		   "11����ѯ�����м��㣬�����Ӧ��������\n"
		   "12������\n"
		   "0�� �˳�����\n"
		   
		   "***************************************\n" 
	);
}
