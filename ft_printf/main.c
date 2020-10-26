#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	// int n = 0;

	// just print
	// printf("printf : ");
	// printf("Hello, World!\n");

	// printf("ft_printf : ");
	int n;
	n = ft_printf("a%.3d b %4s\n", 24);
	printf("%d\n" ,n);

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
