#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IS.h"
#include"function.h"

Status SplitCommand(char *str,char *order,char *title0,char *title1)
{
	int i,j=0,k=0,m=0,flag0=0,flag1=0;
	int len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]=='<'&&flag0==0)
		{	//��һ���ļ���
			for(j=0,i++;str[i]!='>';j++,i++)
			{
				if(str[i]=='\0')
				{
					printf("����ָ���ʽ����\n");
					return ERROR;
				}
				title0[j]=str[i];
				flag0=1;
			}
		}
		else if(str[i]=='<'&&flag0==1)
		{	//���еڶ����ļ���
			for(k=0,i++;str[i]!='>';k++,i++)
			{
				if(str[i]=='\0')
				{
					printf("����ָ���ʽ����\n");
					return ERROR;
				}
				title1[k]=str[i];
			}
		}
		else
		{	//ָ��
			order[m]=str[i];
			m++;
		}
	}

	title0[j++]='\0';
	title1[k++]='\0';
	order[m++]='\0';

	return TRUE;
}

Status mvfile(char *p)//�ƶ�
{
	char title0[15];
	char title1[15];
	char Userorder[25];
	char tureorder[100]={'m','o','v','e',' '};

	SplitCommand(p,Userorder,title0,title1);

	strcat(tureorder,title0);

	int L = strlen(tureorder);
	tureorder[L]=' ';

	strcat(tureorder,title1);

	printf("%s\n",tureorder);
	system(tureorder);
	system("pause");
}

