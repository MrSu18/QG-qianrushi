#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"qgsort.h"


void srandtxt(int n)
{
	//生成随机数
	FILE*fp;
	fp=fopen("data.txt","w");
	fclose(fp);
	fp=fopen("data.txt","a");
	if(!fp)
	{
		printf("打开文件出错！\n");
		return -1;
	}

	int a[n],aa;
	int i;

	srand((unsigned)time(NULL));
	for(i=0;i<n;i++)
	{
		aa=rand()%n;
		a[i]=aa;
	}
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%d,",a[i]);
	}
	fclose(fp);
	//printf("随机数数据重置成功！\n");
}


void readtxt(int *a,int n)
{
	FILE *fp;
	fp=fopen("data.txt","r");
	if(!fp)
	{
		printf("r打开文件错误\n");
		return -1;
	}
	int i;
	for(i=0;i<n;i++)
	{
		//printf("test5");
		fscanf(fp,"%d,",&a[i]);
	}
	fclose(fp);
}

