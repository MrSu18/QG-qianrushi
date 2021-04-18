#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"qgsort.h"

void menu()
{
	printf( "选择你测试类型\n"
		"************************************************\n"
		"--> 1、1W层次数据量\n"
		"--> 2、5W层次数据量\n"
		"--> 3、20W层次数据量\n"
		"--> 4、大量小数组\n"
		"--> 5、颜色排序\n"
		"--> 6、选取第K大的数\n"
		"--> 0、退出程序\n"
		"***********************************************\n");
}


void select()
{
	int opoion;
	while(1)
	{
		menu();
		printf("请输入你的选项：\n");
		while(scanf("%d",&opoion)==0||getchar()!='\n')
		{
			printf("非法输入，请重新输入：");
			while(getchar()!='\n');
		}
		system("cls");
		switch (opoion)
		{
		case 1:
			{
				int n=10000;
				int a[n];
				//int *a=(int*)malloc(sizeof(int)*n);
				int *temp=(int*)malloc(sizeof(int)*n);
				if(temp==NULL)
				{
					printf("出错，内存分配不足\n");
					break;
				}

				//生成随机数
				srandtxt(n);
				printf("随机数数据重置成功！\n");

				//读取文件流数据
				readtxt(a,n);

				//给计数排序计算最大值和最小值
				int max = MAX(a,n);
				int min = MIN(a,n);

				//计算时间
				clock_t start = clock();
				insertSort(a,n);
				clock_t diff = clock() - start;
				printf("\n插入排序用时为：%dms\n",diff);

				readtxt(a,n);
				start = clock();
				CountSort(a,n,max,min);
				diff = clock() - start;
				printf("\n计数排序用时为：%dms\n",diff);

				readtxt(a,n);
				start = clock();
				RadixCountSort(a,n);
				diff = clock() - start;
				printf("\n基数排序用时为：%dms\n",diff);

				readtxt(a,n);
				start = clock();
				MergeSort(a,0,n-1,temp);
				diff = clock() - start;
				printf("\n归并排序用时为：%dms\n",diff);
				free(temp);
				temp=NULL;

				start = clock();
				readtxt(a,n);
				QuickSort_Recursion(a,0,n-1);
				diff = clock() - start;
				printf("\n快速排序用时为：%dms\n",diff);

				start = clock();
				readtxt(a,n);
				Partition(a,0,n);
				diff = clock() - start;
				printf("\n三数取中后的快速排序用时为：%dms\n",diff);



				//交互界面友好
				system("pause");
				system("cls");
				break;

			}
		case 2:
			{
				int n=50000;
				int a[n];
				//int *a=(int*)malloc(sizeof(int)*n);
				int *temp=(int*)malloc(sizeof(int)*n);
				if(temp==NULL)
				{
					printf("出错，内存分配不足\n");
					break;
				}

				//生成随机数
				srandtxt(n);
				printf("随机数数据重置成功！\n");

				//读取文件流数据
				readtxt(a,n);

				//给计数排序计算最大值和最小值
				int max = MAX(a,n);
				int min = MIN(a,n);

				//计算时间
				clock_t start = clock();
				insertSort(a,n);
				clock_t diff = clock() - start;
				printf("\n插入排序用时为：%dms\n",diff);

				readtxt(a,n);
				start = clock();
				CountSort(a,n,max,min);
				diff = clock() - start;
				printf("\n计数排序用时为：%dms\n",diff);

				readtxt(a,n);
				start = clock();
				RadixCountSort(a,n);
				diff = clock() - start;
				printf("\n基数排序用时为：%dms\n",diff);

				readtxt(a,n);
				start = clock();
				MergeSort(a,0,n-1,temp);
				diff = clock() - start;
				printf("\n归并排序用时为：%dms\n",diff);
				free(temp);
				temp=NULL;

				start = clock();
				readtxt(a,n);
				QuickSort_Recursion(a,0,n-1);
				diff = clock() - start;
				printf("\n快速排序用时为：%dms\n",diff);

				start = clock();
				readtxt(a,n);
				Partition(a,0,n-1);
				diff = clock() - start;
				printf("\n三数取中后的快速排序用时为：%dms\n",diff);



				//交互界面友好
				system("pause");
				system("cls");
				break;

			}
		case 3:
			{
				int n=200000;
				int a[n];
				//int *a=(int*)malloc(sizeof(int)*n);
				int *temp=(int*)malloc(sizeof(int)*n);
				if(temp==NULL)
				{
					printf("出错，内存分配不足\n");
					break;
				}

				//生成随机数
				srandtxt(n);
				printf("随机数数据重置成功！\n");

				//读取文件流数据
				readtxt(a,n);

				//给计数排序计算最大值和最小值
				int max = MAX(a,n);
				int min = MIN(a,n);

				//计算时间
				clock_t start = clock();
				insertSort(a,n);
				clock_t diff = clock() - start;
				printf("\n插入排序用时为：%dms\n",diff);

				readtxt(a,n);
				start = clock();
				CountSort(a,n,max,min);
				diff = clock() - start;
				printf("\n计数排序用时为：%dms\n",diff);

				readtxt(a,n);
				start = clock();
				RadixCountSort(a,n);
				diff = clock() - start;
				printf("\n基数排序用时为：%dms\n",diff);

				readtxt(a,n);
				start = clock();
				MergeSort(a,0,n-1,temp);
				diff = clock() - start;
				printf("\n归并排序用时为：%dms\n",diff);
				free(temp);
				temp=NULL;

				start = clock();
				readtxt(a,n);
				QuickSort_Recursion(a,0,n-1);
				diff = clock() - start;
				printf("\n快速排序用时为：%dms\n",diff);

				start = clock();
				readtxt(a,n);
				Partition(a,0,n-1);
				diff = clock() - start;
				printf("\n优化后的快速排序用时为：%dms\n",diff);



				//交互界面友好
				system("pause");
				system("cls");
				break;

			}
		case 4:
			{
				printf("请输入你要排序的数组数量为：\n");
				int k;
				while(scanf("%d",&k)==0||getchar()!='\n')
				{
					printf("非法输入，请重新输入：");
					while(getchar()!='\n');
				}


				int n=100;
				int a[n];
				int *temp=(int*)malloc(sizeof(int)*n);
				if(temp==NULL)
				{
					printf("出错，内存分配不足\n");
					break;
				}

				clock_t start = clock();
				for(int i=0;i<k;i++)
				{
					srandtxt(n);
					readtxt(a,n);
					//start = clock();
					insertSort(a,100);
					//diff = clock() - start+diff;
				}
				clock_t diff = clock() - start;
				printf("\n插入排序用时为：%dms\n",diff);

				clock_t start1 = clock();
				for(int i=0;i<k;i++)
				{
					srandtxt(n);
					readtxt(a,n);

					MergeSort(a,0,n-1,temp);

				}
				clock_t diff1 = clock() - start1;
				printf("\n归并排序用时为：%dms\n",diff1);

				int max,min;
				clock_t start2 = clock();
				for(int i=0;i<k;i++)
				{
					srandtxt(n);
					readtxt(a,n);
					CountSort(a,n,MAX(a,n),MIN(a,n));

				}
				clock_t diff2 = clock() - start2;
				printf("\n计数排序用时为：%dms\n",diff2);

				clock_t start3 = clock();
				for(int i=0;i<k;i++)
				{
					srandtxt(n);
					readtxt(a,n);
					RadixCountSort(a,n);
				}
				clock_t diff3 = clock() - start3;
				printf("\n基数排序用时为：%dms\n",diff3);

				clock_t start4 = clock();
				for(int i=0;i<k;i++)
				{
					srandtxt(n);
					readtxt(a,n);
					QuickSort_Recursion(a,0,n-1);
				}
				clock_t diff4 = clock() - start4;
				printf("\n快速排序用时为：%dms\n",diff4);


				clock_t start5 = clock();
				for(int i=0;i<k;i++)
				{
					srandtxt(n);
					readtxt(a,n);
					Partition(a,0,n-1);
				}
				clock_t diff5 = clock() - start5;
				printf("\n三数取中后快速排序用时为：%dms\n",diff5);

				system("pause");
				system("cls");
				break;

			}
		case 5:
			{
				int a[10]={1,0,1,2,0,2,1,2,0,1};
				printf("原数组为:");
				for(int i=0;i<10;i++)
				{
					printf("%d,",a[i]);
				}
				printf("\n");
				ColorSort(a,10);
				printf("排序后的数组为");
				for(int i=0;i<10;i++)
				{
					printf("%d,",a[i]);
				}
				printf("\n");

				system("pause");
				system("cls");
				break;
			}
		case 6:
			{
				int a[10]={2,34,556,433,1,3,4,56,6,4};
				printf("原数组为:");
				for(int i=0;i<10;i++)
				{
					printf("%d,",a[i]);
				}
				printf("\n");
				int k;
				printf("请输入你想查询的第K大位置的数：\n");
				while(scanf("%d",&k)==0||getchar()!='\n')
				{
					printf("非法输入，请重新输入：");
					while(getchar()!='\n');
				}

				int num;
				searchK(a,k-1,0,9);
				//QuickSort_Recursion(a,0,9);
				printf("第%d大的数为：%d\n",k,a[k-1]);

				system("pause");
				system("cls");
				break;
			}
		case 0:
			printf("退出程序！\n");
			system("pasuse");
			exit(0);
		default:
			printf("输入错误，请重新输入：\n");
			break;
		}
	}
}
