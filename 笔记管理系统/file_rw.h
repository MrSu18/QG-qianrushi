#ifndef FLIE_RW_H_INCLUDED
#define FLIE_RW_H_INCLUDED
#include "IS.h"


Status U_file_r(User*head);//���û��ļ��Ķ�ȡ
Status U_file_w(User*head);//���û������е���Ϣ���뱾���ı�

Status S_filedir_r(char*s);//���û��ļ�����Ϣ���ж�ȡ
void fvisit(FolderPtr* q,char *p);//�ڱ���������ʱ��д���ļ�




#endif // FLIE_RW_H_INCLUDED
