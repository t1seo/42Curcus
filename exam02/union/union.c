#include <unistd.h>

void print_union(char *a, char *b)
{
	int ck[127] = {0}; // 체크 배열
	int c;

	// a의 글자들 중복되지 않게 차례대로 출력
	while (*a)
	{
		c = *a;
		if (ck[c] == 0)
		{
			write(1, a, 1);
			ck[c] = 1;
		}
		++a;
	}

	// b의 글자들 중 중복되지 않게 차례대로 출력
	while (*b)
	{
		c = *b;
		if (ck[c] == 0)
		{
			write(1, b, 1);
			ck[c] = 1;
		}
		++b;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		print_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
