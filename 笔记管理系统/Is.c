#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IS.h"
Status IS(char *p)//显示当前路劲下的文件和文件夹
{
	if(p[0]!='I'||p[1]!='S')
	{
		printf("指令出错，请重新输入！\n");
		return ERROR;
	}
	else
	{
		system("dir");
		return TRUE;
	}
}
Status IS_(char *p)//IS<路径>函数
{
	if(p[0]!='I'||p[1]!='S'||p[2]!='<')//判断是否是这个指令
	{
		printf("指令出错，请重新输入！\n");
		return ERROR;
	}
	else
	{
		int i=0;
		while(p[i]!='>'&&p[i]!='\0')//判断有没有>
		{
			i++;
		}
		if(p[i]=='\0')
		{
			printf("指令出错，请重新输入！\n");
			return ERROR;
		}
		else
		{
			char cmd[255]={'d','i','r'};//如果在dir 后面加/b参数的话就不会出现最后修改的时间字节什么的
			p[0]=' ';p[1]=' ';p[2]=' ';
			p[i]=' ';
			strcat(cmd,p);
			system(cmd);
			return TRUE;
		}
	}
}
Status IStrees(char *p)
{
	system("tree /f");
	return TRUE;
}
Status ISgrep(char *p)
{
	int i=0;
	char cmd[255]={'c','d',' '};
	while(p[i]!='<')//判断有没有>
	{
		i++;
	}
	//此时的p[i]==‘<'
	int j=1;
	while(p[i+j]!='>')
	{
		cmd[2+j]=p[i+j];
		j++;
	}
	//此时p[i+j]=='>',cmd=="cd 路径
	cmd[2+j]=' ';//cmd=="cd 路径 ;
	cmd[2+j+1]='&';cmd[2+j+2]='&';cmd[2+j+3]=' ';//cmd=="cd 路径 && ;
	cmd[5+j+1]='f';cmd[5+j+2]='i';cmd[5+j+3]='n';cmd[5+j+4]='d';cmd[5+j+5]='s';cmd[5+j+6]='t';cmd[5+j+7]='r';cmd[5+j+8]=' ';//cmd=="cd 路径 && findstr ;
	cmd[13+j+1]='/';cmd[13+j+2]='s';cmd[13+j+3]=' ';//cmd=="cd 路径 && findstr /s ;
	cmd[16+j+1]='/';cmd[16+j+2]='A';cmd[16+j+3]=':';cmd[16+j+4]='0';cmd[16+j+5]='2';cmd[16+j+6]=' ';//cmd=="cd 路径 && findstr /s /A:02 ;
	//把is<路径>grep跳过，所以是p[i+j+4]=p;
	int n=1;
	//printf("%c\n",p[i+j+4 +n]);
	while(p[i+j+4+n]!='\0')
	{
		cmd[22+j+n]=p[i+j+4+n];
		n++;
	}
	cmd[22+j+n+0]=' ';cmd[22+j+n+1]='.';cmd[22+j+n+2]='/';cmd[22+j+n+3]='*';cmd[22+j+n+4]='\0';//
	//printf("%s",cmd);
	system(cmd);
	return TRUE;
}
