#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int n;
	n = ft_printf("CHAR TEST: %c\n", 'a');
	printf("%d\n", n);
	n = 0;

	ft_printf("STR TEST: %s\n", "Hello");
	printf("%d\n", n);
	n = 0;
	return 0;
}
