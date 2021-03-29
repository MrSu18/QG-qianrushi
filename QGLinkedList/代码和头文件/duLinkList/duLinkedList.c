#include "duLinkedList.h"
#include<stdio.h>
#include<stdlib.h>




/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L)
{
	*L=(DuLinkedList)malloc(sizeof(DuLinkedList));
	if(!(*L))
	     return ERROR;
	(*L)->next=NULL;
	ElemType data;
	(*L)->data=data; 
	(*L)->prior=NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) 
{
	if(*L==NULL)
	{
		printf("��δ��ʼ���������ȳ�ʼ��\n"); 
	}
	else
	{
		DuLinkedList p;
		while(*L)
		{
			p=(*L)->next;
			free(*L);
			(*L)=p;
			if(p)
			p->prior=NULL;
		}
		printf("�����ѱ����٣���Ҫ����ʹ�ã����ȳ�ʼ������\n"); 
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p//��P֮ǰ����һ��q 
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) 
{
	if(p==NULL)
	{
		printf("��δ��ʼ��\n");
		return ERROR; 
	}
	if(p->prior)
	{
		q->prior=p->prior;
		p->prior=q;
		q->prior->next=q;
		q->next=p;
	}
	q->next=p;
	p->prior=q;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p//��p֮�����һ��q 
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) 
{
	if(p==NULL)
	{
		printf("��δ��ʼ��");
		return ERROR; 
	}
	if(p->next)
	{
		q->prior=p;
		q->next=p->next;
		p->next=q;
		q->next->prior=q;
	}
	q->prior=p;
	p->next=q;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e)//ɾ��P֮��Ľ�㲢��ֵ��e 
{
	if(p==NULL||p->next==NULL)
	{
		printf("����β������\n"); 
		return ERROR; 
	}
	DuLNode *q;
	q=p->next;//����p�����һ�����ĵ�ַ
	*e=q->data;
	if(q->next==NULL)
	{
		p->next=q->next;
		free(q);return SUCCESS;
	}
	q->next->prior=p;
	p->next=q->next;
	free(q);
	return SUCCESS; 
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) 
{
	printf("�����е�����Ϊ��"); 
	DuLNode *p;
	p=L;
	while(p)
	{
		(*visit)(p->data);
		p=p->next;
	}
	printf("\n");
}




DuLNode* newNode(ElemType data)
{
	DuLNode *q=(DuLNode*)malloc(sizeof(DuLNode));
	q->prior=NULL;
	q->data = data;
	q->next = NULL;
	return q;
}





void print(DuLNode*head)
{
	DuLNode * p;
	p=head;
	if(head!=NULL)
	do
	{
		printf(" %d ",p->data);
		p=p->next;
	}while(p!=NULL);
}






DuLNode* FindByX(DuLNode *head, ElemType x)
{
	DuLNode*temp=head;
	if(head==NULL||head->next==NULL)
	{
		printf("����û�н�㣡");
	}
	while(temp!=NULL)
    {
        if (temp->data == x)
        {
			temp=temp->prior;//���Ԫ���ǵ�һ���Ļ�temp�����null�ˣ��� 
            return temp;
        }
        else temp=temp->next;
    }
    return NULL;
}


