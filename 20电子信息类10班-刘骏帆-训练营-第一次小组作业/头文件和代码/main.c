#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	jiemian();
	char s[100]={'\0'};
	int opotion;
	while(1)
	{
		printf("���������ѡ�");
		while (scanf_s("%d", &opotion) == 0 || getchar() != '\n')
		{
			printf("�����˷Ƿ��ַ������������룺");
			while (getchar() != '\n');
		}//�ж��û��Ƿ�Ƿ�����
		switch(opotion)
		{
		case 1:
			printf("������һ���ַ�����");
			while (scanf_s("%s", s) == 0 )
			{
				printf("�����˷Ƿ��ַ������������룺");
				while (getchar() != '\n');
			}//�ж��û��Ƿ�Ƿ�����
			//gets(s);
			longestPalindrome(s);
			// printf("������Ӵ�Ϊ��%s",s);
			printf("\n");
			break;
		case 2:
			printf("������һ���ַ�����");
			int row;
			while (scanf_s("%s", s) == 0 )
			{
				printf("�����˷Ƿ��ַ������������룺");
				while (getchar() != '\n');
			}//�ж��û��Ƿ�Ƿ�����
			printf("��������Ҫz��ת����������");
			while (scanf_s("%d", &row) == 0 || getchar() != '\n')
			{
				printf("�����˷Ƿ��ַ������������룺");
				while (getchar() != '\n');
			}//�ж��û��Ƿ�Ƿ�����
			Zglyphconversion(s,row);
			memset(s,0,sizeof s);
			break;
		case 3:
			system("cls");
			jiemian();
			break;

		case 0:
			printf("�˳�����");
			system("pause");
			exit(0);
			break;
		default:
			printf("�����������������!!\n");
			break;
		}


	}

}
