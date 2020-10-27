#include <stdio.h>
#include "ft_printf.h"

int main(void)
{

	int n;
	n = ft_printf("== char test == : %c\n", 'a');
	printf("%d\n" ,n);

	n = ft_printf("== str test == : %s\n", "Hello");
	printf("%d\n", n);



	return 0;
}
