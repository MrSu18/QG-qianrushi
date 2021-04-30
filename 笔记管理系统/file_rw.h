#ifndef FLIE_RW_H_INCLUDED
#define FLIE_RW_H_INCLUDED
#include "IS.h"


Status U_file_r(User*head);//对用户文件的读取
Status U_file_w(User*head);//把用户链表中的信息存入本地文本

Status S_filedir_r(char*s);//对用户文件夹信息进行读取
void fvisit(FolderPtr* q,char *p);//在遍历函数的时候写入文件




#endif // FLIE_RW_H_INCLUDED
