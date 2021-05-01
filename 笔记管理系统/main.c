#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IS.h"
#include "function.h"
#include "file_rw.h"

int main()
{
	char s[10];
	gets(s);
	FolderTreePtr base=(FolderTreePtr)malloc(sizeof(FolderTree));
	base->root=(FolderPtr)malloc(sizeof(Folder));
	layercreat(base,s);
	Tree_Traverse(base,visit);
	/*printf("%s\t%s\t%s\t%s\t%s\n"   ,base->root->folder_title
					,base->root->folder_tag[0].tag_node
					,base->root->folder_tag[1].tag_node
					,base->root->folder_tag[2].tag_node
					,base->root->folder_tag[3].tag_node
					,base->root->folder_tag[4].tag_node);

	printf("%s\t%s\t%s\t%s\t%s\n"   ,base->root->left->folder_title
					,base->root->left->folder_tag[0].tag_node
					,base->root->left->folder_tag[1].tag_node
					,base->root->left->folder_tag[2].tag_node
					,base->root->left->folder_tag[3].tag_node
					,base->root->left->folder_tag[4].tag_node);

	printf("%s\t%s\t%s\t%s\t%s\n"   ,base->root->right->folder_title
					,base->root->right->folder_tag[0].tag_node
					,base->root->right->folder_tag[1].tag_node
					,base->root->right->folder_tag[2].tag_node
					,base->root->right->folder_tag[3].tag_node
					,base->root->right->folder_tag[4].tag_node);*/

	/*if(base->root->left->left==NULL)
	{
		printf("ÊÇ¿Õ\n");
	}*/

	return 0;
}
