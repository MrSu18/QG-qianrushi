#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IS.h"

int main()
{
	char s[255];
	char instrction[255];
	gets(instrction);
	chdir(instrction);
	system("cd");
	printf(" ‰»Î÷∏¡Ó£∫");
	gets(s);
	deldir(s);
	//system(s);



	return 0;
}
