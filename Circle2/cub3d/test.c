#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str = "map.cub";

	int i = 0;
	while (str[i])
		i++;
	printf("%c\n", str[i - 1]);
	char *ptr = &str[i - 3];

	printf("%d\n", strcmp("cub", ptr));
}
