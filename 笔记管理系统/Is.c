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
Status IStrees(char *p)
{
	system("tree /f");
	return TRUE;
}
Status ISgrep(char *p)
{
	int i=0;
	char cmd[255]={'c','d',' '};
	while(p[i]!='<')//�ж���û��>
	{
		i++;
	}
	//��ʱ��p[i]==��<'
	int j=1;
	while(p[i+j]!='>')
	{
		cmd[2+j]=p[i+j];
		j++;
	}
	//��ʱp[i+j]=='>',cmd=="cd ·��
	cmd[2+j]=' ';//cmd=="cd ·�� ;
	cmd[2+j+1]='&';cmd[2+j+2]='&';cmd[2+j+3]=' ';//cmd=="cd ·�� && ;
	cmd[5+j+1]='f';cmd[5+j+2]='i';cmd[5+j+3]='n';cmd[5+j+4]='d';cmd[5+j+5]='s';cmd[5+j+6]='t';cmd[5+j+7]='r';cmd[5+j+8]=' ';//cmd=="cd ·�� && findstr ;
	cmd[13+j+1]='/';cmd[13+j+2]='s';cmd[13+j+3]=' ';//cmd=="cd ·�� && findstr /s ;
	cmd[16+j+1]='/';cmd[16+j+2]='A';cmd[16+j+3]=':';cmd[16+j+4]='0';cmd[16+j+5]='2';cmd[16+j+6]=' ';//cmd=="cd ·�� && findstr /s /A:02 ;
	//��is<·��>grep������������p[i+j+4]=p;
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
