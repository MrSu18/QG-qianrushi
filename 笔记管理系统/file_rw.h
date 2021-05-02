#ifndef FLIE_RW_H_INCLUDED
#define FLIE_RW_H_INCLUDED
#include "IS.h"


Status U_file_r(User*head);//对用户文件的读取
Status U_file_w(User*head);//把用户链表中的信息存入本地文本

Status S_filedir_w(FolderTreePtr F_T,char*dirtxt,char*fieltxt, void (*fvisit)(FolderPtr q,char*p));//对用户文件夹信息进行写入
void fvisit(FolderPtr q,char *p);//在遍历函数的时候写入文件

Status file_r(FILE *fp,FilePtr head);//对文件名链表进行读取
Status file_w(FilePtr head,char*filetxt);//对文件名链表进行写入文本文件

Status layercreat(FolderTreePtr base,char *filename,char *s);//创建整棵树




#endif // FLIE_RW_H_INCLUDED
