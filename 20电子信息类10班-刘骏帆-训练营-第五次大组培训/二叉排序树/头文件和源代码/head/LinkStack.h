#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "binary_sort_tree.h"

typedef  struct StackNode//栈的结点
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



//链栈
Status initLStack(LinkStack *s);//初始化栈
Status destroyLStack(LinkStack *s);//销毁栈
Status getTopLStack(LinkStack *s,NodePtr* top);//得到栈顶节点
Status pushLStack(LinkStack *s,ElemType data,NodePtr );//入栈
Status popLStack(LinkStack *s,ElemType *data,NodePtr*);//出栈
Status bianlistack(LinkStack *s);//遍历栈


#endif
