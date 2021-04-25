#include <stdio.h>
#include<stdlib.h>
#include "LinkStack.h"

Status initLStack(LinkStack *s)//初始化栈
{
	s->top=(LinkStack*)malloc(sizeof(StackNode));
	if(s->top==NULL)
	{
		printf("初始化失败，内存空间无法分配！\n");
		return ERROR;
	}
	else
	{
		s->count=0;
		printf("\n非递归遍历所需栈栈初始化成功！\n");
		return SUCCESS;
	}

}
Status destroyLStack(LinkStack *s)//销毁栈
{
	if(s->top==NULL)
	{
		printf("栈未初始化，请先初始化栈！\n");
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
		printf("栈已被销毁\n");
		return SUCCESS;
	}
}

Status pushLStack(LinkStack *s,ElemType data,NodePtr node)//入栈
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

Status popLStack(LinkStack *s,ElemType *data,NodePtr *node)//出栈
{
	if(s->count==0)
	{
		printf("栈为空栈，无法出栈！\n");
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


Status getTopLStack(LinkStack *s,NodePtr* top)//得到栈顶节点
{
	if(s->count==0)
	{
		printf("栈为空栈，没有栈顶元素\n");
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
		printf("栈未初始化，请先初始化栈！\n");
		return ERROR;
	}
	else if((s->count)==0)
	{
		printf ("该栈为空栈\n");
		return ERROR;
	}
	else
	{
		LinkStack*p;
		p=s;
		printf("栈内的元素有：");
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



