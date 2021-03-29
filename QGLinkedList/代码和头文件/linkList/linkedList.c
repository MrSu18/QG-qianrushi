#include "linkedList.h"
#include<stdio.h>
#include<stdlib.h> 


void visit(ElemType *e)
{
	printf(" %d ",e);
}

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L)
{
    *L = (LinkedList)malloc(sizeof(LinkedList));		//����һ���������ռ�
	if(!(*L))											//������ʧ�ܷ��ش���
		return ERROR;
	(*L)->data = 0; 
	(*L)->next = NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) 
{
	LinkedList p;
	while(*L)
	{
		p=(*L)->next;
		free(*L);
		*L=p;
	}
	p=NULL;
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) 
{
	if(!p)
		return ERROR;
	q->next=p->next ;
	p->next=q;
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) 
{
	if((p==NULL)||(p->next==NULL))
	{
		printf("��ɾ�˱�ɾ�ˣ���û��ɾ�˻�ɾ\n");
		return ERROR;
	}
	LNode *q;
	q=p->next;
	*e=q->data;
	p->next=q->next;
	free(q);
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) 
{
	printf("�����е�����Ϊ��"); 
	LNode*p;
	p=L;
	while(p)
	{
		visit(p->data);
		p=p->next;
	}
	printf("\n");
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) 
{
	LNode *p;
	p=L;
	while(p)
	{
		if(p->data==e)
			return SUCCESS;
		else
			p=p->next;
	}
	return ERROR; 
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) 
{
	if(((*L)==NULL)||((*L)->next==NULL))
	{
		printf("ת���ˣ����ǲ�����Ϊ�����ֻ���\n");
		return ERROR; 
	}
	LNode *pre,*cur,*Next;
	pre=*L;
	cur=(*L)->next;
	pre->next=NULL;
	while(cur)//cur==NULL��ʱ��pre�͵���NULLǰ 
	{
		Next=cur->next;
		cur->next=pre;
		pre=cur;
		cur=Next;
	}
	*L=pre;//��ͷ����λ 
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) 
{
	LinkedList fast,slow;
	fast=L;slow=L;
	while(fast&&(fast->next))
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			printf("����ɻ�\n"); 
			return SUCCESS;
		}
	}
	printf("����δ�ɻ�\n"); 
	return ERROR;
	
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) 
{
	LNode *pre,*cur,*Next;
	pre=*L;
	*L=pre->next;
	while(pre&&pre->next)
	{
		cur=pre->next;
		Next=cur->next;
		if(cur->next&&cur->next->next)
		{
			pre->next=cur->next->next;
		}
		else
		{
			pre->next=cur->next;
		}
		cur->next=pre;
		pre=Next;
	}
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) 
{
	LinkedList fast,slow;
	fast=slow=*L;
	if((fast->next)==NULL) 
	{
		printf("ֻ��һ����㣬����\n"); 
		*L=slow;
		return slow;
	}
	else if((fast->next->next)==NULL)
	{
		printf("ֻ��������㣬�м���Ϊǰ���Ǹ�\n");
		*L=slow;
		return slow; 
	} 
	while(fast!=NULL)
	{
	   fast=fast->next->next;
	   slow=slow->next;
    }
    *L=slow;
    return slow;
}




LinkedList newnode (ElemType x)
{
	LinkedList new;
	new=(LinkedList)malloc(sizeof(LNode));
	new->data=x;
	new->next=NULL;
	return new;
}
	
	
	
	
	
LinkedList	Linksearch(LinkedList L,ElemType x)
{
	while(L)
	{
		if((L->data)==x)
			return L;
		else
			L=L->next;
	}
	printf("�Ҳ����������������ݺò�-v-");
	return NULL;
}


