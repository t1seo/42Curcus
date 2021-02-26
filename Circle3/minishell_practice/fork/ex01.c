#include <stdio.h>
#include <unistd.h>

int main()
{
	int x;
	x = 0;

	fork(); // 자식 프로세

	x = 1;
	printf("PID : %d, x : %d\n", getpid(), x);
	return 0;
}
