#include<stdio.h>
#include<string.h>
#include"longestPalindrome.h"

char longestPalindrome(char s[100])//��������Ӵ�
{
	int i=0,j=0;
	int max=0;
	int star,finish;
	int length=strlen(s);
	char p[100]={'\0'};
	if(length==0||length==1)
	{
		printf("��С�����Ӵ�Ϊ:%s",s);
		return s;
	}

	else
	{
		while(i<length-1)
		{
			p[j]=s[i];
			p[j+1]='#';
			i++;
			j=j+2;
		}
		p[j]=s[i];
		int start1,finish1;
		for(i=1;i<j+1;i++)//���ַ����е�ÿ��Ԫ�ض�Ϊһ�λ��������ж�˭�����
		{
			start1=i-1;finish1=i+1;
			//printf("\n%d,%d\n",start1,finish1);
			while(start1>=0&&finish1<=j)
			{
				if(p[start1]==p[finish1])//�����߲���ʱ��˵������Ϊ���Ĳ��ǻ����Ӵ�
				{
					if((finish1-start1)>max)
					{
						max=finish1-start1;
						//printf("max=%d\n",max);
						star=start1;
						finish=finish1;//��¼��������Ӵ���λ��
						//printf("\n%c,%c\n",p[start1],p[finish1]);
					}
					start1--;
					finish1++;

				}
				else
				{
					break;
				}

			}
		}
	}
	j=0;i=0;
	char temp[100]={'\0'};
	//printf("%c",p[star]);
	if(p[star]=='#')
	{
		while((star+i)<finish)
		{
			temp[j]=p[star+i+1];
			i=i+2;
			j++;
		}
		temp[j]='\0';
	}
	else
	{
		while((star+i)<=finish)
		{
			temp[j]=p[star+i];
			i=i+2;
			j++;
		}
		s[j]='\0';
	}
	//s=temp;
	printf("\n������Ӵ�Ϊ��%s\n",temp);
	return (s);
}
