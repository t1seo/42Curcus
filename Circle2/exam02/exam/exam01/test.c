#include <stdio.h>
int		ft_printf(const char *str, ...);

int main(void)
{
	// ft_printf("%5.3s\n", "Hello, World!\n");
	// ft_printf("%5.0d\n", 0); // 아무것도 출력 되지 않는다.
	// ft_printf("%5.2d\n", 0); // precision 개수만큼  0 출력
	// ft_printf("%5.2d\n", 1); // precision - num_len 만큼 0 출력

	ft_printf("%5.0x\n", 0);
	printf("%5.0x\n", 0);

	return 0;
}
