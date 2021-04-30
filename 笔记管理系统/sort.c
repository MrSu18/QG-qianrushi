#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IS.h"
#include"function.h"

Status sortfile(char *p)//将目标文件夹进行排序
{
	char title0[15];
	char title1[15];
	char Userorder[25];
	char tureorder[100]={'d','i','r',' ','/','b',' '};

	SplitCommand(p,Userorder,title0,title1);

	strcat(tureorder,title0);

	printf("%s\n",tureorder);
	system(tureorder);
	system("pause");
}
