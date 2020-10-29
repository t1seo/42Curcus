#include <stdio.h>
#include "./header/ft_printf.h"

int main(void)
{
	ft_printf("===== TEST CHAR =====\n");
    ft_printf("%10c Hello\n", 'a');
    ft_printf("%010c Hello\n", 'a');
    ft_printf("%-10c Hello\n", 'a');
	ft_printf("%.5c Hello\n",'a');
	ft_printf("%-010c Hello\n",'a');
	ft_printf("%0-10c Hello\n", 'a');
	ft_printf("%10.10c Hello\n", 'a');
	ft_printf("%010.10c Hello\n", 'a');

	ft_printf("\n===== TEST STR =====\n");
	ft_printf("%10s world!\n","Hello");
	ft_printf("%010s world!\n", "Hello");
	ft_printf("%-10s world!\n", "Hello");
	ft_printf("%.10s world!\n", "Hello");
	ft_printf("%-010s world!\n", "Hello");
	ft_printf("%0-10s world!\n", "Hello");
	ft_printf("%10.10s world!\n", "Hello");
	ft_printf("%010.10s world!\n", "Hello");

	ft_printf("\n===== TEST PERCENT =====\n");
	ft_printf("%10% world!\n");
	ft_printf("%010% world!\n");
	ft_printf("%-10% world!\n");
	ft_printf("%.5% world!\n");
	ft_printf("%-010% world!\n");
	ft_printf("%0-10% world!\n");
	ft_printf("%10.10% world!\n");
	ft_printf("%010.10% world!\n");

	char *str = "hello";
    printf("\n===== TEST POINTER =====\n");
    ft_printf("%p\n", str);
    ft_printf("%20p\n", str);
    ft_printf("%020p\n", str);
    ft_printf("%-20p\n", str);
    ft_printf("%.20p\n", str);
    ft_printf("%-020p\n", str);
    ft_printf("%0-20p\n", str);
    ft_printf("%20.10p\n", str);
    ft_printf("%020.10p\n", str);
    ft_printf("%-20.10p\n", str);
    ft_printf("%10.20p\n", str);
    ft_printf("%010.20p\n", str);

int n = -123;
    printf("\n===== TEST INTEGER NUM ======\n");
    printf("%d\n", n);
    printf("%20d\n", n);
    printf("%020d\n", n);
    printf("%-20d\n", n);
    printf("%.20d\n", n);
    printf("%-020d\n", n);
    printf("%0-20d\n", n);
    printf("%20.10d\n", n);
    printf("%020.10d\n", n);
    printf("%-20.10d\n", n);
    printf("%10.20d\n", n);
    printf("%010.20d\n", n);

printf("\n===== TEST UNSIGNED INTEGER NUM ======\n");
    printf("%u\n", n);
    printf("%20u\n", n);
    printf("%020u\n", n);
    printf("%-20u\n", n);
    printf("%.20u\n", n);
    printf("%-020u\n", n);
    printf("%0-20u\n", n);
    printf("%20.10u\n", n);
    printf("%020.10u\n", n);
    printf("%-20.10u\n", n);
    printf("%10.20u\n", n);
    printf("%010.20u\n", n);

printf("\n===== TEST HEX NUM ======\n");
    printf("%x\n", n);
    printf("%20x\n", n);
    printf("%020x\n", n);
    printf("%-20x\n", n);
    printf("%.20x\n", n);
    printf("%-020x\n", n);
    printf("%0-20x\n", n);
    printf("%20.10x\n", n);
    printf("%020.10x\n", n);
    printf("%-20.10x\n", n);
    printf("%10.20x\n", n);
    printf("%010.20x\n", n);

	return 0;
}
