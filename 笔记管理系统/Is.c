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
Status IStrees(char *p,char*s)
{
	system("tree /f");
	return TRUE;
}
Status ISgrep(char *p)
{

}
