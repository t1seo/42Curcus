#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int n = 0;

	// just print
	n = printf("Hello, World!\n");
	printf("Return value of printf : %d\n", n);

	n = ft_printf("Hello, World!\n");
	printf("Return value of ft_printf : %d\n\n", n);

	// nothing in format
	// n = printf("");
	// printf("printf : %d\n", n);

	// n = ft_printf("");
	// printf("ft_printf : %d\n\n", n);


	// find %
	// printf("Hello %% C %% Programming\n");
	// ft_printf("hello %% C Progra%mming")

	return 0;
}
