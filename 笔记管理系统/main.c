#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IS.h"
#include "function.h"
#include "file_rw.h"

int main()
{
	FILE* fp =fopen("filename.txt","r");
	FILE* fp1 =fopen("filename.txt","r");
	FilePtr head1 =(FilePtr)malloc(sizeof(File));
	head1->next=NULL;
	FilePtr head2 =(FilePtr)malloc(sizeof(File));
	head2->next=NULL;
	file_r(fp,head1);
	file_r(fp,head2);
	fclose(fp);
	printf("%s\t%s\t%s\t%s\t%s\t%s\n",head1->next->file_title
					 ,head1->next->file_tag[0].tag_node
					 ,head1->next->file_tag[1].tag_node
					 ,head1->next->file_tag[2].tag_node
					 ,head1->next->file_tag[3].tag_node
					 ,head1->next->file_tag[4].tag_node);

	/*printf("%s\t%s\t%s\t%s\t%s\t%s\n",head1->next->next->file_title
					 ,head1->next->next->file_tag[0].tag_node
					 ,head1->next->next->file_tag[1].tag_node
					 ,head1->next->next->file_tag[2].tag_node
					 ,head1->next->next->file_tag[3].tag_node
					 ,head1->next->next->file_tag[4].tag_node);*/


	printf("%s\n",head2->next->file_title);

	/*printf("%s\t%s\t%s\t%s\t%s\t%s\n",head2->next->file_title
					 ,head2->next->file_tag[0].tag_node
					 ,head2->next->file_tag[1].tag_node
					 ,head2->next->file_tag[2].tag_node
					 ,head2->next->file_tag[3].tag_node
					 ,head2->next->file_tag[4].tag_node);*/

	return 0;
}
