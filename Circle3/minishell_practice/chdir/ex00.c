#include <stdio.h>
#include <unistd.h>

#ifndef MAX_PATH
#define MAX_PATH 260
#endif

int main(void)
{
	char strBuffer[MAX_PATH] = {0, };
	char strChangeDir[MAX_PATH] = { "/Users/t1won/Documents/Github/42Curcus/Circle3" };

	int nResult = chdir(strChangeDir);

	if (nResult == 0)
		printf("이동 성공!\n");
	else if (nResult == -1)
		printf("이동 실패\n");
	return 0;
}
