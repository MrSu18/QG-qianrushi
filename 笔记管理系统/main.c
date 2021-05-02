#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IS.h"
#include "function.h"
#include "file_rw.h"

int main()
{
	char dirname[17];
	char filename[24];

	strcpy(dirname,"Áõ¿¥·«±Ê¼Ç.txt");
	strcpy(filename,"filename.txt");

	FolderTreePtr base =(FolderTreePtr)malloc(sizeof(FolderTree));
	base->root=(FolderPtr)malloc(sizeof(Folder));
	layercreat(base,dirname,filename);

	Tree_Traverse(base,visit);


	/*FILE*fp=fopen(dirname,"w");
	fclose(fp);
	fopen(filename,"w");
	fclose(fp);

	S_filedir_w(base,dirname,filename,fvisit);*/

	/*char instrction[50];
	gets(instrction);
	chdir("L:\C\QG\teamexam");
	ISgrep(instrction);*/

	return 0;
}
