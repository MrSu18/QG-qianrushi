#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IS.h"
Status IS(char *p)//��ʾ��ǰ·���µ��ļ����ļ���
{
	if(p[0]!='I'||p[1]!='S')
	{
		printf("ָ��������������룡\n");
		return ERROR;
	}
	else
	{
		system("dir");
		return TRUE;
	}
}
Status IS_(char *p)//IS<·��>����
{
	if(p[0]!='I'||p[1]!='S'||p[2]!='<')//�ж��Ƿ������ָ��
	{
		printf("ָ��������������룡\n");
		return ERROR;
	}
	else
	{
		int i=0;
		while(p[i]!='>'&&p[i]!='\0')//�ж���û��>
		{
			i++;
		}
		if(p[i]=='\0')
		{
			printf("ָ��������������룡\n");
			return ERROR;
		}
		else
		{
			char cmd[255]={'d','i','r'};//�����dir �����/b�����Ļ��Ͳ����������޸ĵ�ʱ���ֽ�ʲô��
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
	if(p[0]!='I'||p[1]!='S'||p[2]!='<')//���IS<�Ƿ���ȷ
	{
		printf("ָ��������������룡");
		return ERROR;
	}
	else
	{
		char s[100]={'c','d',' '};

		int i=3,j=0;
		while(p[i]!='>'&&p[i]!='\0')
		{
			s[3+j]=p[i];//����ͬʱ��·��д��s��
			i++;j++;
		}

		if(p[i]=='\0')//�����û��>
		{
			printf("ָ��������������룡");
			return ERROR;
		}
		else
		{
			int temp=0;
			char temps[15]={'\0'};
			while(p[i+temp+1]!='"'&&p[i+temp+1]!='\0')//���>�����ǲ���grep������û�е�һ��"
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
				printf("ָ��������������룡");
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
