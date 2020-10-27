#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	// int n;
	// n = ft_printf("CHAR TEST: %c\n", 'a');
	// printf("=> %d\n", n);
	// n = 0;

	// n = ft_printf("STR TEST: %s\n", "Hello");
	// printf("=> %d\n", n);
	// n = 0;
	char *str = "hello";

	ft_printf("%p\n", str);
	printf("%p\n", str);

	ft_printf("%d\n", 123);
	ft_printf("%i\n", -123);

	ft_printf("%u\n", 123);
	printf("%u\n", 123);
	ft_printf("%u\n", -123);
	printf("%u\n", -123);

	ft_printf("%x\n", 123);
	ft_printf("%x\n", -123);
	ft_printf("%X\n", 123);
	ft_printf("%X\n", -123);

	return 0;
}
