#include <stdio.h>
#include "./header/ft_printf.h"

int main(void)
{
	// test char %c
    ft_printf("%10c Hello\n", 'a');
    ft_printf("%010c Hello\n", 'a');
    ft_printf("%-10c Hello\n", 'a');
	ft_printf("%.5c Hello\n",'a');
	ft_printf("%-010c Hello\n",'a');
	ft_printf("%0-10c Hello\n", 'a');

	ft_printf("%10s world!\n","Hello");
	ft_printf("%010s world!\n", "Hello");
	ft_printf("%-10s world!\n", "Hello");
	ft_printf("%.10s world!\n", "Hello");
	ft_printf("%-010s world!\n", "Hello");
	ft_printf("%0-10s world!\n", "Hello");

	ft_printf("%10% world!\n");
	ft_printf("%010% world!\n");
	ft_printf("%-10% world!\n");
	ft_printf("%.5% world!\n");
	ft_printf("%-010% world!\n");
	ft_printf("%0-10% world!\n");
	return 0;
}
