#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include"qgsort.h"

void CountSort(int *a, int size , int max,int min)
{
	int range =max-min+1;
	int *temp=(int*)malloc(sizeof(int)*range);

	memset(temp,0,sizeof(int)*range);
	//printf("%d",sizeof(int)*range);
	for(int i=0;i<size;i++)
	{
		temp[a[i]-min]++;
	}

	int j=0;
	for(int i=0;i<range;i++)
	{
		while(temp[i]--)
			a[j++]=i+min;
	}
	free(temp);
	temp=NULL;
	//for(int i=0;i<range;i++)
		//printf("%d,",a[i]);
}

void RadixCountSort(int *a,int size)
{
	int i,index,max;
	int rad =1;//geweishu

	max=MAX(a,size);

	int *count =(int*)malloc(sizeof(int)*10);
	int *sorted=(int*)malloc(sizeof(int)*size);//��Ϊ��ʱ������������Ժ�ԭ����ĳ�����һ����
	if(count==NULL)
	{
		printf("�����ڴ���䲻��\n");
		exit(0);
	}
	if(sorted==NULL)
	{
		printf("�����ڴ���䲻��\n");
		exit(0);
	}

	while(max/rad>0)
	{
		memset(count,0,sizeof(int)*10);
		for(i=0;i<size;i++)
		{
			index=a[i]/rad%10;
			count[index]++;
		}
		for(i=1;i<10;i++)//��ǰ��Ĵ����ۼ������õ�����������С������±����������
		{
			count[i]=count[i]+count[i-1];
		}
		for(i=size-1;i>=0;i--)//����������������Ӧ�ڼ��������еļ�����һ֮������������������е�λ��
		{
			index=a[i]/rad%10;
			count[index]--;
			sorted[count[index]]=a[i];
		}
		for(i=0;i<size;i++)//�ر���Ҫfor�᲻��������Խ��
		{
			a[i]=sorted[i];
		}
		rad=rad*10;
	}

        //printf("test\n");
        free(count);
        count=NULL;
         //printf("test\n");
        free(sorted);
        sorted=NULL;
         //printf("test\n");
}

int MAX(int *a,int size)
{
	int i,max=a[0];
	for(i=0;i<size;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}


int MIN (int *a,int size)
{
	int i,min=a[0];
	for(i=0;i<size;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
		}
	}
	return min;
}
