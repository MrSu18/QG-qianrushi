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
		}//��ʱ������ѭ����p[i]Ҫô��>������\0
		if(p[i]=='\0')
		{
			printf("ָ������������������룡\n");
			return ERROR;
		}
		else//���뵽��һ���Ļ�˵��p[i]=='>'��
		{
			char cmd[255]={'r','m','d','i','r',' ','/','s',' '};
			for(int n=5,j=9;n<i;n++,j++)
			{
				cmd[j]=p[n];
			}
			//printf("%s\n",cmd);
			system(cmd);
			printf("ָ��ִ�гɹ���\n");
			return TRUE;
		}

	}
	else
	{
		printf("ָ�������������������!\n");
		return ERROR;
	}
}
