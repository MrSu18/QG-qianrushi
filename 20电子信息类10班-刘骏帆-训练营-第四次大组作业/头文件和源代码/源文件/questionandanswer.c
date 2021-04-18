#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include"qgsort.h"

void ColorSort(int *a,int size)
{
	int *p0=a;
	int *p=p0;
	int *p2=a+(size-1);
	p++;

	while(p0!=p2&&p!=p0&&p!=p2)
	{
		if(*p==0)
		{
			swap(p,p0);
			p0++;
			if(*p==2)
			{
				swap(p,p2);
				p2--;
			}
		}
		else if(*p==2)
		{
			swap(p,p2);
			p2--;
			if(*p==0)
			{
				swap(p,p0);
				p0++;
			}
		}
		p++;
	}
}


void swap(int *a,int *b)
{
	int t;
	t=*a;*a=*b;*b=t;
}

void searchK(int *a,int k,int begin,int end)
{
	if(begin<end)
	{
		int i=begin,j=end;
		int base = a[begin];

		while(i<j)
		{
			while(i<j&&a[j]>base)
			{
				j--;
			}
			a[i]=a[j];
			while(i<j&&a[i]<=base)
			{
				i++;
			}
			a[j]=a[i];
		}
		a[i]=base;
		//searchK(a,k,begin,i-1);
		//searchK(a,k,i+1,end);
		//printf("%d",i);
		if(i==k)
		{
			//printf("第%d大的数为:%d\n",k+1,a[i]);
			return 0;
		}
		else
		{
			if(i<k)
			{
				//printf("test");
				searchK(a,k,i+1,end);
			}
			else
			{
				//printf("test");
				searchK(a,k,begin,i-1);
				//QuickSort_Recursion(a,base,i);
			}
		}
	}
	return 0;
}
