#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[20];

	memset(a, 65, sizeof(a));

	for (int i = 0; i < sizeof(a) / sizeof(char); i++)
	{
		printf("%c\n", a[i]);
	}

	return (0);
}
