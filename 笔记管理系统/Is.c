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
Status IStrees(char *p,char *USERroot)
{
	char trueorder[150]={'c','d',' '};
	strcat(trueorder,"");
	strcat(trueorder,USERroot);
	strcat(trueorder," && tree /f");
	system(trueorder);
	return TRUE;
}
Status ISgrep(char *p)
{
	if(p[0]!='I'||p[1]!='S'||p[2]!='<')//检测IS<是否正确
	{
		printf("指令错误，请重新输入！");
		return ERROR;
	}
	else
	{
		char s[100]={'c','d',' '};

		int i=3,j=0;
		while(p[i]!='>'&&p[i]!='\0')
		{
			s[3+j]=p[i];//检测的同时把路劲写入s中
			i++;j++;
		}

		if(p[i]=='\0')//检测有没有>
		{
			printf("指令错误，请重新输入！");
			return ERROR;
		}
		else
		{
			int temp=0;
			char temps[15]={'\0'};
			while(p[i+temp+1]!='"'&&p[i+temp+1]!='\0')//检测>后面是不是grep并且有没有第一个"
			{
				temps[temp]=p[i+temp+1];
				temp++;
			}

			int flag=0;
			while(p[i+temp+1+flag+1]!='"'&&p[i+temp+flag+2]!='\0')
			{
				flag++;
			}

			if(p[i+temp+1]=='\0'||p[i+temp+flag+2]=='\0'||strcmp(temps,"grep")!=0)
			{
				printf("指令错误，请重新输入！");
				return ERROR;
			}
			else
			{
				s[3+j]=' ';
				strcat(s,"&& findstr /s /m ");
				int n=0;
				while(p[i+n+5]!='\0')
				{
					s[21+j+n]=p[i+n+5];
					n++;
				}
				s[21+j+n]=' ';s[21+j+n+1]='.';s[21+j+n+2]=92;s[21+j+n+3]='*';s[21+j+n+4]='\0';

				system(s);

				return TRUE;
			}
		}
	}
}
