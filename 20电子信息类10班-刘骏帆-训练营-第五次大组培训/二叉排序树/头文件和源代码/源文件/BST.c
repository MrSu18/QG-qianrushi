#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"
//************************************************
//初始化函数
Status BST_init(BinarySortTreePtr P)
{
	P->root=(BinarySortTree*)malloc(sizeof(BinarySortTree));
	if(P->root==NULL)
	{
		printf("初始化失败，内存空间无法分配！\n");
		return ERROR;
	}
	else
	{
		P->root=NULL;
		printf("初始化成功！\n");
		return SUCCESS;
	}
}

//******************************************************
//搜寻函数
Status BST_search(NodePtr oldnode, ElemType temp)
{
	NodePtr FLAG=(NodePtr)malloc(sizeof (Node));
	FLAG=oldnode;
	if(oldnode==NULL)
	{
		printf("树为空！\n");
		return ERROR;
	}
	else
	{
		if(oldnode->value==temp)
		{
			printf("\n%d在树中！\n",temp);
			return SUCCESS;
		}
		else if(oldnode->value<temp)
		{
			if(FLAG->right!=NULL)
			{
				BST_search(FLAG->right,temp);
			}
			else
			{
				printf("\n%d不在树中！\n",temp);
				return ERROR;
			}
		}
		else if(oldnode->value>temp)
		{
			if(oldnode->left!=NULL)
			{
				BST_search(FLAG->left,temp);
			}
			else
			{
				printf("\n%d不在树中！\n",temp);
				return ERROR;
			}
		}
	}
}



//*******************************************************
//插入函数

Status BST_insert(BinarySortTreePtr P, ElemType data)
{
	NodePtr newnode = (NodePtr)malloc(sizeof(Node));
        if(newnode!=NULL)
	{
		newnode->value=data;
		newnode->left=NULL;
		newnode->right=NULL;
		if(P->root==NULL)
		{
			P->root=(NodePtr)malloc(sizeof(Node));
			P->root->value=data;
			P->root->left=NULL;
			P->root->right=NULL;
			free(newnode);
			printf("节点插入成功！\n");
			return SUCCESS;
		}

		else
		{
			NodePtr n=(NodePtr)malloc(sizeof(Node));
			NodePtr n1=(NodePtr)malloc(sizeof(Node));
			n1=n=P->root;

			while(n!=NULL)
			{
				if(n->value<data)
				{
					n1=n;
					n=n->right;
				}
				else if(n->value==data)
				{
					printf("树中已存在此数据，插入失败！\n");
					return ERROR;
				}
				else if(n->value>data)
				{
					n1=n;
					n=n->left;
				}
				else
				{
					return ERROR;
				}
			}
			if(n1->value<data)//如果你是n1=newnode或者n=newnode就等于没有操作一样
			{
				n1->right=newnode;
			}
			else
			{
				n1->left=newnode;
			}

			printf("节点插入成功！\n");
			return SUCCESS;
		}
	}
	else
	{
		printf("创建节点出错，空间内存不足！\n");
		return ERROR;
	}

}

//************************************************************************
//删除函数
Status deletetemp(NodePtr* oldnode)
{
	NodePtr q=NULL,s=NULL;
	if((*oldnode)->right==NULL)
	{
		q=*oldnode;
		*oldnode=(*oldnode)->left;
		free(q);
	}
	else if((*oldnode)->left==NULL)
	{
		q=*oldnode;
		*oldnode=(*oldnode)->right;
		free(q);
	}
	else
	{
		q=*oldnode;
		s=(*oldnode)->left;
		while(s->right)
		{
			q=s;
			s=s->right;
		}
		(*oldnode)->value=s->value;
		if(q!=*oldnode)
		{
			q->right=s->left;
		}
		else
		{
			q->left=s->right;
		}
		free(s);
	}
	printf("\n节点删除成功！\n");
	return SUCCESS;
}

Status BST_delete(BinarySortTreePtr P,NodePtr *T,ElemType data)
{
	if(BST_search(P->root,data))
	{
		if((*T)->value==data)
		{
			deletetemp(T);
			return SUCCESS;
		}
		else if((*T)->value>data)
		{
			BST_delete(P,&(*T)->left,data);
		}
		else
		{
			BST_delete(P,&(*T)->right,data);
		}
	}
	else
	{
		printf("\n%d不在树中，无法删除\n",data);
		return ERROR;
	}
}
//**************************************************************

