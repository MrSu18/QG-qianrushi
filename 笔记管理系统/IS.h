#ifndef IS_H_INCLUDED
#define IS_H_INCLUDED
#include"function.h"

//*****************************
//显示指令函数
Status IS(char *p);//显示当前工作目录文件
Status IS_(char *p);//IS<路径>函数
Status IStrees(char *p);//IS-a函数
Status ISgrep(char *p);//搜索包含搜寻内容的文件
//*******************************
//删除文件函数
Status deldir(char *p);//删除指定文件夹以及文件夹下的所有内容



#endif // IS_H_INCLUDED
