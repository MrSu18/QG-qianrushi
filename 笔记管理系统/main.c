#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IS.h"
#include "function.h"
#include "file_rw.h"

int main()
{
	/*UserPtr head =(UserPtr)malloc(sizeof(User));
	head->user_next=NULL;
	head->user_name[0]='\0';
	head->user_password[0]='\0';
	head->user_id[0]='\0';


	U_file_r(head);
	printf("%s\t%s\t%s\t%s\n",head->user_next->user_name,head->user_next->user_password,head->user_next->user_id,head->user_next->user_folder->root->folder_title);

	gets(head->user_next->user_name);
	U_file_w(head);*/

	char instrction [100];
	gets(instrction);
	mvfile(instrction);

	return 0;
}
