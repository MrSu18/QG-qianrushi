#include <stdio.h>
#include<stdlib.h>
#include "LinkStack.h"

Status initLStack(LinkStack *s)//��ʼ��ջ
{
	s->top=(LinkStack*)malloc(sizeof(StackNode));
	if(s->top==NULL)
	{
		printf("��ʼ��ʧ�ܣ��ڴ�ռ��޷����䣡\n");
		return ERROR;
	}
	else
	{
		s->count=0;
		printf("\n�ǵݹ��������ջջ��ʼ���ɹ���\n");
		return SUCCESS;
	}

}
Status destroyLStack(LinkStack *s)//����ջ
{
	if(s->top==NULL)
	{
		printf("ջδ��ʼ�������ȳ�ʼ��ջ��\n");
		return ERROR;
	}
	else
	{
		while (s->count!=0)
		{
			StackNode*p;
			p=s->top;
			s->top=p->next;
			free(p);
			s->count--;
		}
		s->top=NULL;
		printf("ջ�ѱ�����\n");
		return SUCCESS;
	}
}

Status pushLStack(LinkStack *s,ElemType data,NodePtr node)//��ջ
{
	StackNode*p;
	if(s->count==0)
	{
		s->top->data=data;
		s->top->node=node;
		s->count++;
		return SUCCESS;
	}
	else
	{
		p=(LinkStack*)malloc(sizeof (StackNode));
		p->next=s->top;
		p->data=data;
		p->node=node;
		s->count++;
		s->top=p;
		return SUCCESS;
	}
}

Status popLStack(LinkStack *s,ElemType *data,NodePtr *node)//��ջ
{
	if(s->count==0)
	{
		printf("ջΪ��ջ���޷���ջ��\n");
		return ERROR;
	}
	else if(s->count==1)
	{
		*data=s->top->data;
		*node=s->top->node;
		s->count=0;
		return SUCCESS;
	}
	else
	{
		StackNode*p;
		p=s->top;
		*data=p->data;
		*node=p->node;
		s->top=p->next;
		free(p);
		s->count--;
		return SUCCESS;
	}
}


Status getTopLStack(LinkStack *s,NodePtr* top)//�õ�ջ���ڵ�
{
	if(s->count==0)
	{
		printf("ջΪ��ջ��û��ջ��Ԫ��\n");
		return ERROR;
	}
	else
	{
		*top=s->top->node;
		return SUCCESS;
	}
}


Status bianlistack(LinkStack *s)
{
	if(s->top==NULL)
	{
		printf("ջδ��ʼ�������ȳ�ʼ��ջ��\n");
		return ERROR;
	}
	else if((s->count)==0)
	{
		printf ("��ջΪ��ջ\n");
		return ERROR;
	}
	else
	{
		LinkStack*p;
		p=s;
		printf("ջ�ڵ�Ԫ���У�");
		while(p->count!=0)
		{
			printf(" %d ",p->top->data);
			p->top=p->top->next;
			p->count--;
		}
		printf("\n");

		return SUCCESS;
	}
}



