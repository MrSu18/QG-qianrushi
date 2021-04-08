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
		printf("请输入你的选项：");
		while (scanf_s("%d", &opotion) == 0 || getchar() != '\n')
		{
			printf("输入了非法字符，请重新输入：");
			while (getchar() != '\n');
		}//判断用户是否非法输入
		switch(opotion)
		{
		case 1:
			printf("请输入一串字符串：");
			while (scanf_s("%s", s) == 0 )
			{
				printf("输入了非法字符，请重新输入：");
				while (getchar() != '\n');
			}//判断用户是否非法输入
			//gets(s);
			longestPalindrome(s);
			// printf("最长回文子串为：%s",s);
			printf("\n");
			break;
		case 2:
			printf("请输入一串字符串：");
			int row;
			while (scanf_s("%s", s) == 0 )
			{
				printf("输入了非法字符，请重新输入：");
				while (getchar() != '\n');
			}//判断用户是否非法输入
			printf("请输入你要z字转化的行数：");
			while (scanf_s("%d", &row) == 0 || getchar() != '\n')
			{
				printf("输入了非法字符，请重新输入：");
				while (getchar() != '\n');
			}//判断用户是否非法输入
			Zglyphconversion(s,row);
			memset(s,0,sizeof s);
			break;
		case 3:
			system("cls");
			jiemian();
			break;

		case 0:
			printf("退出程序！");
			system("pause");
			exit(0);
			break;
		default:
			printf("输入错误！请重新输入!!\n");
			break;
		}


	}

}
