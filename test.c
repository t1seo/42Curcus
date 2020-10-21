#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *strs[3] = {
		"Hello",
		"World!",
		"This is a C Programming"
	};

	printf("%s\n", strs[1]);
	printf("%c\n", strs[2][3]);
	printf("%ld\n", strlen(&strs[1][3]));
}
