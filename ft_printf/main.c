#include <stdio.h>
#include "libft.h"

int main(void)
{
	char *str = "hello";
	int num = 123;
	printf("%ld\n", ft_strlen(str));
	printf("%s\n", ft_itoa(num));
	return 0;
}
