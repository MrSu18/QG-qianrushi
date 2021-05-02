#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IS.h"
#include "function.h"
#include "file_rw.h"

int main()
{
	char filename[17];
	char s[24];

	strcpy(filename,"Áõ¿¥·«±Ê¼Ç.txt");
	strcpy(s,"filename.txt");

	FolderTreePtr base =(FolderTreePtr)malloc(sizeof(FolderTree));
	base->root=(FolderPtr)malloc(sizeof(Folder));
	layercreat(base,filename,s);

	//S_filedir_w(base,filename,s,fvisit);

	return 0;
}
