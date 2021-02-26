#include <stdio.h>
#include <unistd.h>

int		main(void)
{
	int		counter = 0;
	pid_t	pid;

	pid = fork(); // fork 실행

	// fork 후
	if (pid == -1)
	{
		printf("자식 프로세스 생성 실패\n");
		return -1;
	}
	else if (pid == 0) // 자식 프로세스
	{
		printf("자식 프로세스 디스카운트\n");
		while (1)
		{
			printf("자식: %d\n", counter--);
			sleep(1);
		}
	}
	else if (pid > 0) // 부모 프로세스
	{
		printf("부모 프로세스 카운트\n");
		printf("자식 프로세스의 pid %d\n", pid);
		while (1)
		{
			printf("부모: %d\n", counter++);
			sleep(1);
		}
	}
}
