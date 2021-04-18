#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"qgsort.h"

void menu()
{
	printf( "ѡ�����������\n"
		"************************************************\n"
		"--> 1��1W���������\n"
		"--> 2��5W���������\n"
		"--> 3��20W���������\n"
		"--> 4������С����\n"
		"--> 5����ɫ����\n"
		"--> 6��ѡȡ��K�����\n"
		"--> 0���˳�����\n"
		"***********************************************\n");
}


void select()
{
	int opoion;
	while(1)
	{
		menu();
		printf("���������ѡ�\n");
		while(scanf("%d",&opoion)==0||getchar()!='\n')
		{
			printf("�Ƿ����룬���������룺");
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
					printf("�����ڴ���䲻��\n");
					break;
				}

				//���������
				srandtxt(n);
				printf("������������óɹ���\n");

				//��ȡ�ļ�������
				readtxt(a,n);

				//����������������ֵ����Сֵ
				int max = MAX(a,n);
				int min = MIN(a,n);

				//����ʱ��
				clock_t start = clock();
				insertSort(a,n);
				clock_t diff = clock() - start;
				printf("\n����������ʱΪ��%dms\n",diff);

				readtxt(a,n);
				start = clock();
				CountSort(a,n,max,min);
				diff = clock() - start;
				printf("\n����������ʱΪ��%dms\n",diff);

				readtxt(a,n);
				start = clock();
				RadixCountSort(a,n);
				diff = clock() - start;
				printf("\n����������ʱΪ��%dms\n",diff);

				readtxt(a,n);
				start = clock();
				MergeSort(a,0,n-1,temp);
				diff = clock() - start;
				printf("\n�鲢������ʱΪ��%dms\n",diff);
				free(temp);
				temp=NULL;

				start = clock();
				readtxt(a,n);
				QuickSort_Recursion(a,0,n-1);
				diff = clock() - start;
				printf("\n����������ʱΪ��%dms\n",diff);

				start = clock();
				readtxt(a,n);
				Partition(a,0,n);
				diff = clock() - start;
				printf("\n����ȡ�к�Ŀ���������ʱΪ��%dms\n",diff);



				//���������Ѻ�
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
					printf("�����ڴ���䲻��\n");
					break;
				}

				//���������
				srandtxt(n);
				printf("������������óɹ���\n");

				//��ȡ�ļ�������
				readtxt(a,n);

				//����������������ֵ����Сֵ
				int max = MAX(a,n);
				int min = MIN(a,n);

				//����ʱ��
				clock_t start = clock();
				insertSort(a,n);
				clock_t diff = clock() - start;
				printf("\n����������ʱΪ��%dms\n",diff);

				readtxt(a,n);
				start = clock();
				CountSort(a,n,max,min);
				diff = clock() - start;
				printf("\n����������ʱΪ��%dms\n",diff);

				readtxt(a,n);
				start = clock();
				RadixCountSort(a,n);
				diff = clock() - start;
				printf("\n����������ʱΪ��%dms\n",diff);

				readtxt(a,n);
				start = clock();
				MergeSort(a,0,n-1,temp);
				diff = clock() - start;
				printf("\n�鲢������ʱΪ��%dms\n",diff);
				free(temp);
				temp=NULL;

				start = clock();
				readtxt(a,n);
				QuickSort_Recursion(a,0,n-1);
				diff = clock() - start;
				printf("\n����������ʱΪ��%dms\n",diff);

				start = clock();
				readtxt(a,n);
				Partition(a,0,n-1);
				diff = clock() - start;
				printf("\n����ȡ�к�Ŀ���������ʱΪ��%dms\n",diff);



				//���������Ѻ�
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
					printf("�����ڴ���䲻��\n");
					break;
				}

				//���������
				srandtxt(n);
				printf("������������óɹ���\n");

				//��ȡ�ļ�������
				readtxt(a,n);

				//����������������ֵ����Сֵ
				int max = MAX(a,n);
				int min = MIN(a,n);

				//����ʱ��
				clock_t start = clock();
				insertSort(a,n);
				clock_t diff = clock() - start;
				printf("\n����������ʱΪ��%dms\n",diff);

				readtxt(a,n);
				start = clock();
				CountSort(a,n,max,min);
				diff = clock() - start;
				printf("\n����������ʱΪ��%dms\n",diff);

				readtxt(a,n);
				start = clock();
				RadixCountSort(a,n);
				diff = clock() - start;
				printf("\n����������ʱΪ��%dms\n",diff);

				readtxt(a,n);
				start = clock();
				MergeSort(a,0,n-1,temp);
				diff = clock() - start;
				printf("\n�鲢������ʱΪ��%dms\n",diff);
				free(temp);
				temp=NULL;

				start = clock();
				readtxt(a,n);
				QuickSort_Recursion(a,0,n-1);
				diff = clock() - start;
				printf("\n����������ʱΪ��%dms\n",diff);

				start = clock();
				readtxt(a,n);
				Partition(a,0,n-1);
				diff = clock() - start;
				printf("\n�Ż���Ŀ���������ʱΪ��%dms\n",diff);



				//���������Ѻ�
				system("pause");
				system("cls");
				break;

			}
		case 4:
			{
				printf("��������Ҫ�������������Ϊ��\n");
				int k;
				while(scanf("%d",&k)==0||getchar()!='\n')
				{
					printf("�Ƿ����룬���������룺");
					while(getchar()!='\n');
				}


				int n=100;
				int a[n];
				int *temp=(int*)malloc(sizeof(int)*n);
				if(temp==NULL)
				{
					printf("�����ڴ���䲻��\n");
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
				printf("\n����������ʱΪ��%dms\n",diff);

				clock_t start1 = clock();
				for(int i=0;i<k;i++)
				{
					srandtxt(n);
					readtxt(a,n);

					MergeSort(a,0,n-1,temp);

				}
				clock_t diff1 = clock() - start1;
				printf("\n�鲢������ʱΪ��%dms\n",diff1);

				int max,min;
				clock_t start2 = clock();
				for(int i=0;i<k;i++)
				{
					srandtxt(n);
					readtxt(a,n);
					CountSort(a,n,MAX(a,n),MIN(a,n));

				}
				clock_t diff2 = clock() - start2;
				printf("\n����������ʱΪ��%dms\n",diff2);

				clock_t start3 = clock();
				for(int i=0;i<k;i++)
				{
					srandtxt(n);
					readtxt(a,n);
					RadixCountSort(a,n);
				}
				clock_t diff3 = clock() - start3;
				printf("\n����������ʱΪ��%dms\n",diff3);

				clock_t start4 = clock();
				for(int i=0;i<k;i++)
				{
					srandtxt(n);
					readtxt(a,n);
					QuickSort_Recursion(a,0,n-1);
				}
				clock_t diff4 = clock() - start4;
				printf("\n����������ʱΪ��%dms\n",diff4);


				clock_t start5 = clock();
				for(int i=0;i<k;i++)
				{
					srandtxt(n);
					readtxt(a,n);
					Partition(a,0,n-1);
				}
				clock_t diff5 = clock() - start5;
				printf("\n����ȡ�к����������ʱΪ��%dms\n",diff5);

				system("pause");
				system("cls");
				break;

			}
		case 5:
			{
				int a[10]={1,0,1,2,0,2,1,2,0,1};
				printf("ԭ����Ϊ:");
				for(int i=0;i<10;i++)
				{
					printf("%d,",a[i]);
				}
				printf("\n");
				ColorSort(a,10);
				printf("����������Ϊ");
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
				printf("ԭ����Ϊ:");
				for(int i=0;i<10;i++)
				{
					printf("%d,",a[i]);
				}
				printf("\n");
				int k;
				printf("�����������ѯ�ĵ�K��λ�õ�����\n");
				while(scanf("%d",&k)==0||getchar()!='\n')
				{
					printf("�Ƿ����룬���������룺");
					while(getchar()!='\n');
				}

				int num;
				searchK(a,k-1,0,9);
				//QuickSort_Recursion(a,0,9);
				printf("��%d�����Ϊ��%d\n",k,a[k-1]);

				system("pause");
				system("cls");
				break;
			}
		case 0:
			printf("�˳�����\n");
			system("pasuse");
			exit(0);
		default:
			printf("����������������룺\n");
			break;
		}
	}
}
