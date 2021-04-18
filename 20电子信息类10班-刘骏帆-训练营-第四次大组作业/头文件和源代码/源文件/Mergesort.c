#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"qgsort.h"

void MergeArray(int *a,int begin,int mid,int end,int *temp)//��������������ϲ���һ����������
{
	int i=0,j=0,k=0;
	for(k=begin;k<=end;k++)
	{
		*(temp+k)=*(a+k);
	}
	for(i=begin,j=mid+1,k=i;i<=mid&&j<=end;k++)//K��Ϊ�˸���������õĵ���������ǵ�
	{
		if(*(temp+i)<=*(temp+j))//�Ƚϱ��ֿ�����������ĵ�һλ�Ĵ�С
		{
			*(a+k)=*(temp+i);
			i++;
		}
		else
		{
			*(a+k)=*(temp+j);
			j++;
		}
	}
	while(i<=mid)
	{
		*(a+k)=*(temp+i);
		k++;i++;
	}
	while(j<=end)
	{
		*(a+k)=*(temp+j);
		k++;j++;
	}

}


void MergeSort(int *a,int begin,int end,int *temp)//�鲢���򣬵ݹ麯����������԰���
{
	if(begin<end)
	{
		int mid=(begin+end)/2;

		MergeSort(a,begin,mid,temp);//���������
		//for(int a1=begin;a1<=mid;a1++)
			//printf("%d,",*(a+a1));
		//printf("\n");
		//system("pause");
		MergeSort(a,mid+1,end,temp);//���ұ�����
		//for(int a1=end;a1>mid;a1--)
			//printf("%d,",*(a+a1));
		//printf("\n");
		//system("pause");
		MergeArray(a,begin,mid,end,temp);
	}
	else
	{
		;
	}

}
