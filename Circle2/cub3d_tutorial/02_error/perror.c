#include <stdio.h>

int main()
{
	FILE *pFile;
	pFile = fopen("unexist.ent", "rb");
	if (pFile == NULL)
		perror("The following error occured");
	else
		fclose(pFile);
	return 0;
}
