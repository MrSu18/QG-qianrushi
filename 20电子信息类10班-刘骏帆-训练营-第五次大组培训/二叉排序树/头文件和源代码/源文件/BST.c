#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"
//************************************************
//��ʼ������
Status BST_init(BinarySortTreePtr P)
{
	P->root=(BinarySortTree*)malloc(sizeof(BinarySortTree));
	if(P->root==NULL)
	{
		printf("��ʼ��ʧ�ܣ��ڴ�ռ��޷����䣡\n");
		return ERROR;
	}
	else
	{
		P->root=NULL;
		printf("��ʼ���ɹ���\n");
		return SUCCESS;
	}
}

//******************************************************
//��Ѱ����
Status BST_search(NodePtr oldnode, ElemType temp)
{
	NodePtr FLAG=(NodePtr)malloc(sizeof (Node));
	FLAG=oldnode;
	if(oldnode==NULL)
	{
		printf("��Ϊ�գ�\n");
		return ERROR;
	}
	else
	{
		if(oldnode->value==temp)
		{
			printf("\n%d�����У�\n",temp);
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
				printf("\n%d�������У�\n",temp);
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
				printf("\n%d�������У�\n",temp);
				return ERROR;
			}
		}
	}
}



//*******************************************************
//���뺯��

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
			printf("�ڵ����ɹ���\n");
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
					printf("�����Ѵ��ڴ����ݣ�����ʧ�ܣ�\n");
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
			if(n1->value<data)//�������n1=newnode����n=newnode�͵���û�в���һ��
			{
				n1->right=newnode;
			}
			else
			{
				n1->left=newnode;
			}

			printf("�ڵ����ɹ���\n");
			return SUCCESS;
		}
	}
	else
	{
		printf("�����ڵ�����ռ��ڴ治�㣡\n");
		return ERROR;
	}

}

//************************************************************************
//ɾ������
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
	printf("\n�ڵ�ɾ���ɹ���\n");
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
		printf("\n%d�������У��޷�ɾ��\n",data);
		return ERROR;
	}
}
//**************************************************************

