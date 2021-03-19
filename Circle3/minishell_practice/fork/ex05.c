#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int	main()
{
	pid_t pid;

	printf("Before the fork()\n");
	pid = fork();

	if (pid == 0)
		printf("This is a Child. PID = %d\n", pid);
	else if (pid > 0)
		printf("This is a Parent. PID = %d\n", pid);
	else
		printf("Fork is failed!!\n");
}
