#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	char *str = "Hello, world!";
	int len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		printf("%c", str[i]);
		fflush(stdout);
		usleep(1000000);
	}
	printf("\n");
	return 0;
}
