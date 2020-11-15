#include <unistd.h>

void ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void inter(char *a, char *b)
{
	int i = 0;
	char ck[127] = {0}; // 체크 배열

	// 문자열 b에만 나타난 문자들만 체크 배열에서 1로 체크
	while (*b)
	{
		ck[(int)*b] = 1;
		++b;
	}

	// 문자열 a를 순환하면서 문자열 b에 나왔던 글자들 출력
	while (*a)
	{
		if (ck[(int)*a])
		{
			ft_putchar(*a);
			ck[(int)*a] = 0; // 한번 나타난 문자는 다시 안타나게 0으로 체크
		}
		++a;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
