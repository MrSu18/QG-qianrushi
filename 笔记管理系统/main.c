#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IS.h"

int main()
{
	while(1)
	{
		char s[255];
		char instrction[255];
		gets(instrction);
		chdir(instrction);
		printf(" ‰»Î÷∏¡Ó£∫");
		gets(s);
		system(s);
	}

	//ISgrep(instrction);
	return 0;
}
