#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

int main(void)
{
    printf("%d\n", atoi("123"));
    printf("%d\n", ft_atoi("123"));

    printf("%d\n", atoi("-123aaa"));
    printf("%d\n", ft_atoi("-123aaa"));

    printf("%d\n", atoi("   -123bbb"));
    printf("%d\n", ft_atoi("   -123bbb"));

    printf("%d\n", atoi("a123"));
    printf("%d\n", ft_atoi("a123"));

		printf("%d\n", atoi("2147483647"));
		printf("%d\n", ft_atoi("2147483647"));

		printf("%d\n", atoi("-2147483648"));
		printf("%d\n", ft_atoi("-2147483648"));

    return 0;
}
