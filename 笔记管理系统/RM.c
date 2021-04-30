#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IS.h"
Status deldir(char *p)
{
	if(p[0]=='r'&&p[1]=='m'&&p[2]=='-'&&p[3]=='r'&&p[4]=='<')
	{
		int i=0;
		while(p[i]!='>'&&p[i]!='\0')
		{
			i++;
		}//这时候跳出循环的p[i]要么是>或者是\0
		if(p[i]=='\0')
		{
			printf("指令输入错误，请重新输入！\n");
			return ERROR;
		}
		else//进入到这一步的话说明p[i]=='>'的
		{
			char cmd[255]={'r','m','d','i','r',' ','/','s',' '};
			for(int n=5,j=9;n<i;n++,j++)
			{
				cmd[j]=p[n];
			}
			//printf("%s\n",cmd);
			system(cmd);
			printf("指令执行成功！\n");
			return TRUE;
		}

	}
	else
	{
		printf("指令输入错误，请重新输入!\n");
		return ERROR;
	}
}
