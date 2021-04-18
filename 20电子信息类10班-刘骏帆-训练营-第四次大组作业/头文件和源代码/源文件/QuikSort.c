#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"qgsort.h"

void QuickSort_Recursion(int *a, int begin, int end)
{
	if(begin<end)
	{
		int i=begin,j=end;
		int base =*(a+begin);

		while(i<j)
		{
			while(i<j&&*(a+j)>base)
			{
				j--;
			}
			*(a+i)=*(a+j);
			while(i<j&&*(a+i)<=base)
			{
				i++;
			}
			*(a+j)=*(a+i);
		}
		*(a+i)=base;
		QuickSort_Recursion(a,begin,i-1);
		QuickSort_Recursion(a,i+1,end);
	}
}


int Partition(int *a, int begin, int end)
{
	clock_t start = clock();
	int mid=(begin+end)/2;
	if(*(a+begin)>*(a+end))
	{
		int t=*(a+begin);
		*(a+begin)=*(a+end);
		*(a+end)=t;
	}
	else if(*(a+mid)>*(a+end))
	{
		int t=*(a+mid);
		*(a+mid)=*(a+end);
		*(a+end)=t;
	}
	else if(*(a+mid)>*(a+begin))
	{
		int t=*(a+mid);
		*(a+mid)=*(a+begin);
		*(a+begin)=t;
	}
	QuickSort_Recursion(a,begin,end);

}


void QuickSort(int *a,int size)
{

}
