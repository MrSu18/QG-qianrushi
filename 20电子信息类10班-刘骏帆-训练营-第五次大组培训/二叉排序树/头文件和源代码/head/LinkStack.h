#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "binary_sort_tree.h"

typedef  struct StackNode//ջ�Ľ��
{
	Node* node;
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//��ջ
Status initLStack(LinkStack *s);//��ʼ��ջ
Status destroyLStack(LinkStack *s);//����ջ
Status getTopLStack(LinkStack *s,NodePtr* top);//�õ�ջ���ڵ�
Status pushLStack(LinkStack *s,ElemType data,NodePtr );//��ջ
Status popLStack(LinkStack *s,ElemType *data,NodePtr*);//��ջ
Status bianlistack(LinkStack *s);//����ջ


#endif
