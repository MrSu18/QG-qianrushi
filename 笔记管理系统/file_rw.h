#ifndef FLIE_RW_H_INCLUDED
#define FLIE_RW_H_INCLUDED
#include "IS.h"


Status U_file_r(User*head);//���û��ļ��Ķ�ȡ
Status U_file_w(User*head);//���û������е���Ϣ���뱾���ı�

Status S_filedir_w(FolderTreePtr F_T,char*dirtxt,char*fieltxt, void (*fvisit)(FolderPtr q,char*p));//���û��ļ�����Ϣ����д��
void fvisit(FolderPtr q,char *p);//�ڱ���������ʱ��д���ļ�

Status file_r(FILE *fp,FilePtr head);//���ļ���������ж�ȡ
Status file_w(FilePtr head,char*filetxt);//���ļ����������д���ı��ļ�

Status layercreat(FolderTreePtr base,char *filename,char *s);//����������




#endif // FLIE_RW_H_INCLUDED
