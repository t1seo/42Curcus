#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *pFile;
	pFile = fopen("unexist.ent", "r");
	if (pFile == NULL)
		printf("Error operning file unexist.ent: %s\n", strerror(errno));
	return 0;
}
