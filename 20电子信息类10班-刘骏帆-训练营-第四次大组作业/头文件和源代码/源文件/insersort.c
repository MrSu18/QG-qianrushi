#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include"qgsort.h"

void insertSort(int *a,int n)
{
	int i,j;


	for(i=1;i<n;i++)
	{
		//if(*(a+i)<*(a+i-1))
		//{
			int t=*(a+i);
			for(j=i-1;j>=0&&*(a+j)>t;j--)//��iǰ���ұ��Լ�С�����Ӷ�ȷ���Լ���λ��
			{
				*(a+j+1)=*(a+j);//�ѱ�i���������
			}
			*(a+j+1)=t;
		//}
	}
}
