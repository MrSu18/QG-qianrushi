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
			for(j=i-1;j>=0&&*(a+j)>t;j--)//从i前面找比自己小的数从而确定自己的位置
			{
				*(a+j+1)=*(a+j);//把比i大的往后扔
			}
			*(a+j+1)=t;
		//}
	}
}
