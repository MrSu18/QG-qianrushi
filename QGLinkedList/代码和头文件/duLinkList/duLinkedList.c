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
		printf("还未初始化链表，请先初始化\n"); 
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
		printf("链表已被销毁，若要继续使用，请先初始化链表\n"); 
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p//在P之前插入一个q 
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) 
{
	if(p==NULL)
	{
		printf("还未初始化\n");
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
 *	@description : insert node q after node p//在p之后插入一个q 
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) 
{
	if(p==NULL)
	{
		printf("还未初始化");
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
Status DeleteList_DuL(DuLNode *p, ElemType *e)//删除P之后的结点并将值给e 
{
	if(p==NULL||p->next==NULL)
	{
		printf("请先尾插入结点\n"); 
		return ERROR; 
	}
	DuLNode *q;
	q=p->next;//保存p结点下一个结点的地址
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
	printf("链表中的数据为："); 
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
		printf("后续没有结点！");
	}
	while(temp!=NULL)
    {
        if (temp->data == x)
        {
			temp=temp->prior;//如果元素是第一个的话temp会等于null了，淦 
            return temp;
        }
        else temp=temp->next;
    }
    return NULL;
}


