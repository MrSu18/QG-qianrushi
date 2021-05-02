#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

//查找对应文件的结点返回指向该结点的指针，否则返回NULL
FolderPtr Find_folder(FolderTreePtr F_T, char* name) {

	LQueue* Q = NULL;
	Queue_Init(&Q);
	Queue_In(&Q, F_T->root);
	while (!Queue_Empty(Q)) {//如果跳出循环，说明没有找到该文件
		FolderPtr node = Queue_Front(Q);
		if (!node) {
			Queue_Out(&Q);
			continue;
		}

		if (strcmp(node->folder_title, name) == 0) {
			return node;

		}
		Queue_Out(&Q);
		if (node->left) {
			Queue_In(&Q, node->left);
		}
		if (node->right) {
			Queue_In(&Q, node->right);
		}
	}
	free(Q);
	Q = NULL;
	return NULL;
}


//遍历树
Status Tree_Traverse(FolderTreePtr F_T, void (*visit)(FolderPtr q))
{
	LQueue* Q = NULL;
	Queue_Init(&Q);
	Queue_In(&Q, F_T->root);
	while (!Queue_Empty(Q))
	{
		FolderPtr node = Queue_Front(Q);
		/*if (!node)
		{
			Queue_Out(&Q);
			continue;
		}*/
		visit(node);
		printList(node->file_head);
		Queue_Out(&Q);
		if (node->left)
		{
			Queue_In(&Q, node->left);
		}
		if (node->right)
		{
			Queue_In(&Q, node->right);
		}
	}
	free(Q);
	Q = NULL;
}

void visit (FolderPtr q)
{
	printf("%s\t%s\t%s\t%s\t%s\t%s\n"   ,q->folder_title
					,q->folder_tag[0].tag_node
					,q->folder_tag[1].tag_node
					,q->folder_tag[2].tag_node
					,q->folder_tag[3].tag_node
					,q->folder_tag[4].tag_node);
	printf("\n\n");
}

Status printList(FilePtr p)
{
	 if (p == NULL) {
		 return ERROR;
	 }
	FilePtr s = p->next;
	while (s)
	{
		printf("文件名\t%s\t\n", s->file_title);
		int i;
		for (i = 0; i < 5; i++) {
			printf("标签\t%s\n", s->file_tag[i].tag_node);
		}
		s = s->next;
	}
	return TRUE;
}



//功能队列
Status Queue_Init(LQueue** q)
{
	(*q) = (LQueue*)malloc(sizeof(LQueue));
	if (!(*q))return ERROR;
	QNode* p = (QNode*)malloc(sizeof(QNode));
	if (p == NULL) return ERROR;
	p->Qnext = NULL;
	(*q)->rear = p;
	(*q)->front = p;
	return TRUE;
}

Status Queue_Empty(LQueue* q)
{
	return (q->front == q->rear) ? TRUE : ERROR;
}

Status Queue_In(LQueue** q, FolderPtr BNode)
{

	QNode* temp;
	temp = (QNode*)malloc(sizeof(QNode));
	if (!temp)
	{
		return ERROR;
	}
	temp->pdata = BNode;
	(*q)->rear->Qnext = temp;
	(*q)->rear = temp;
	(*q)->rear->Qnext = NULL;
	return TRUE;

}

Status Queue_Out(LQueue** q)
{

	if ((*q)->front == (*q)->rear)
	{
		return ERROR;
	}
	else if ((*q)->front->Qnext == (*q)->rear)
	{
		free((*q)->rear);
		(*q)->front->Qnext = NULL;
		(*q)->rear = (*q)->front;
	}
	else
	{
		QNode* temp = NULL;
		temp = (*q)->front->Qnext;
		(*q)->front->Qnext = temp->Qnext;
		temp->Qnext = NULL;
		free(temp);
	}
	return TRUE;

}
Folder* Queue_Front(LQueue* q) {
	if (q->front == q->rear) {
		return NULL;
	}
	else {
		Folder* temp = q->front->Qnext->pdata;
		return temp;
	}
}
