#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"longestPalindrome.h"

void Zglyphconversion(char s[100],int x)
{
	int row=strlen(s);
	int list;
	int i,j;
	char temp[row][x];
	int count=0;//给原数组一个标号
	for(i=0;i<row;i++)
		for(j=0;j<x;j++)
		{
			if((i%(x-1))==0)
			{
				temp[i][j]=s[count];
				count++;
			}
			else
			{
				if(j==(i%(x-1)))
				{
					temp[i][j]=s[count];
					count++;
				}
				else
				{
					temp[i][j]=' ';
				}
			}
		}
	temp[i][j]='\0';
	//printf("%s\n",temp);
	row=i;list=j;
	//printf("\nrow=%d,list=%d\n",row,list);
	char p[list][row];
	for(i=0;i<row;i++)
		for(j=0;j<list;j++)
		{
			p[j][i]=temp[i][j];
			//printf("%c ",p[j][i]);
		}
	for(i=0;i<row;i++)
	{
		if(i%(x-1)!=0)
		{
			char t;
			for(j=0;j<list/2;j++)
			{
				t=p[j][i];p[j][i]=p[list-j-1][i];p[list-j-1][i]=t;
			}
		}
	}
	for(j=0;j<list;j++)
		{
			for(i=0;i<row;i++)
				printf(" %c ",p[j][i]);
			printf("\n");
		}
	//memset(temp,0,sizeof temp);
	//memset(p,0,sizeof p);
}
