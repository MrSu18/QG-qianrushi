#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"
#include"LinkStack.h"
#include"LQueue.h"

//*******************************************************************************************
//递归遍历函数
void visit(NodePtr n)
{
	printf(" %d ",n->value);
}

Status RecursionPreTravel(NodePtr node,void (*visit(NodePtr)))
{
	if(node==NULL)
	{
		return ERROR;
	}
	else
	{
		visit(node);
		RecursionPreTravel(node->left,visit);
		RecursionPreTravel(node->right,visit);
	}
}
Status BST_preorderR(BinarySortTreePtr P, void (*visit)(NodePtr))
{
	if(P->root==NULL)
	{
		printf("树为空树！\n");
		return ERROR;
	}
	else
	{
		printf("递归前序遍历结果为\n");
		RecursionPreTravel(P->root,visit);
		printf("\n");
		return SUCCESS;
	}
}


Status RecursionINTravel(NodePtr node,void (*visit(NodePtr)))
{
	if(node==NULL)
	{
		return ERROR;
	}
	else
	{
		RecursionINTravel(node->left,visit);
		visit(node);
		RecursionINTravel(node->right,visit);
	}
}
Status BST_inorderR(BinarySortTreePtr P, void (*visit)(NodePtr))
{
	if(P->root==NULL)
	{
		printf("树为空树！\n");
		return ERROR;
	}
	else
	{
		printf("递归中序遍历结果为\n");
		RecursionINTravel(P->root,visit);
		printf("\n");
		return SUCCESS;
	}
}


Status RecursionPostTravel(NodePtr node,void (*visit(NodePtr)))
{
	if(node==NULL)
	{
		return ERROR;
	}
	else
	{
		RecursionPostTravel(node->left,visit);
		RecursionPostTravel(node->right,visit);
		visit(node);
	}
}
Status BST_postorderR(BinarySortTreePtr P, void (*visit)(NodePtr))
{
	if(P->root==NULL)
	{
		printf("树为空树！\n");
		return ERROR;
	}
	else
	{
		printf("递归后序遍历结果为\n");
		RecursionPostTravel(P->root,visit);
		printf("\n");
		return SUCCESS;
	}
}
//**********************************************************************
//非递归遍历函数
Status BST_preorderI(BinarySortTreePtr P, void (*visit)(NodePtr))
{
	if(P->root==NULL)
	{
		printf("树为空树！\n");
		return ERROR;
	}
	else
	{
		//初始化一个栈
		LinkStack*s = (LinkStack*)malloc(sizeof(LinkStack));
		initLStack(s);

		//开始入栈出栈遍历
		printf("\n非递归前序遍历结果为\n");
		ElemType*data;
		NodePtr cur=(NodePtr)malloc(sizeof(Node));
		NodePtr *top=(NodePtr*)malloc(sizeof(Node));
		cur=P->root;
		while(cur!=NULL||s->count!=0)
		{
			while(cur!=NULL)
			{
				visit(cur);
				pushLStack(s,cur->value,cur);
				cur=cur->left;
			}
			popLStack(s,data,top);
			cur=(*top)->right;
		}
		printf("\n");
	}
}
Status BST_inorderI(BinarySortTreePtr P, void (*visit)(NodePtr))
{
	if(P->root==NULL)
	{
		printf("树为空树！\n");
		return ERROR;
	}
	else
	{
		//初始化一个栈
		LinkStack*s = (LinkStack*)malloc(sizeof(LinkStack));
		initLStack(s);

		//开始入栈出栈遍历
		printf("\n非递归中序遍历结果为\n");
		ElemType*data;
		NodePtr cur=(NodePtr)malloc(sizeof(Node));
		NodePtr *top=(NodePtr*)malloc(sizeof(Node));
		cur=P->root;
		while(cur!=NULL||s->count!=0)
		{
			while(cur!=NULL)
			{
				pushLStack(s,*data,cur);
				cur=cur->left;
			}
			popLStack(s,data,top);
			visit(*top);
			cur=(*top)->right;
		}
		printf("\n");
	}
}

Status BST_postorderI(BinarySortTreePtr P, void (*visit)(NodePtr))
{
	if(P->root==NULL)
	{
		printf("树为空树！\n");
		return ERROR;
	}
	else
	{
		//初始化一个栈
		LinkStack*s = (LinkStack*)malloc(sizeof(LinkStack));
		initLStack(s);

		//开始入栈出栈遍历
		printf("\n非递归后序遍历结果为\n");
		ElemType data;
		NodePtr cur=(NodePtr)malloc(sizeof(Node));
		NodePtr *top=(NodePtr*)malloc(sizeof(Node));
		cur=P->root;
		*top=P->root;
		pushLStack(s,data,*top);
		while(s->count!=0)
		{
			getTopLStack(s,top);
			if(((*top)->left==NULL&&(*top)->right==NULL)||(cur==(*top)->left||cur==(*top)->right))
			{
				visit(*top);
				popLStack(s,&data,top);
				cur=*top;//对已经遍历过的节点进行标记
			}
			else
			{
				if((*top)->right!=NULL)
				{
					pushLStack(s,data,(*top)->right);
				}
				if((*top)->left!=NULL)
				{
					pushLStack(s,data,(*top)->left);
				}
			}
		}
		printf("\n");
	}
}

//**********************************************************
//层序遍历
Status BST_levelOrder(BinarySortTreePtr P, void (*visit)(NodePtr))
{
	if(P->root==NULL)
	{
		printf("树为空树！\n");
		return ERROR;
	}
	else
	{
		//初始化一个队列
		LQueue*s = (LQueue*)malloc(sizeof(LQueue));
		InitLQueue(s);

		//开始入队出队遍历
		printf("\n层序遍历结果为\n");
		NodePtr *top=(NodePtr*)malloc(sizeof(Node));
		NodePtr cur=(NodePtr)malloc(sizeof(Node));
		cur=P->root;

		EnLQueue(s,cur);
		while(!IsEmptyLQueue(s))
		{
			GetHeadLQueue(s,top);
			visit(*top);
			DeLQueue(s);
			if((*top)->left!=NULL)
			{
				EnLQueue(s,(*top)->left);
			}
			if((*top)->right!=NULL)
			{
				EnLQueue(s,(*top)->right);
			}
		}
		printf("\n");
	}
}
