#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int		main(void)
{
	int counter = 1;
	int	status;
	pid_t pid;
	pid_t pid_child;

	pid = fork();

	if (pid == -1)
	{
		printf("자식 프로세스 생성 실패\n");
		return -1;
	}
	else if (pid == 0)
	{
		printf("자식 프로세스를 5까지 카운트하고 종료\n");
		while (6 > counter)
		{
			printf("자식 : %d\n", counter++);
			sleep(1);
		}
		return 99;
	}
	else if (pid > 0)
	{
		printf("부모 프로세스는 자식 프로세스 작업이 끝날 때까지 기다린다.\n");

		pid_child = wait(&status);

		printf("종료된 자식 프로세스 ID는 %d이며, ", pid_child);
		if (0 == (status & 0xff))
		{
			printf("정상적으로 종료되었고 반환값은 %d이다\n", status >> 8);
		}
		else
		{
			printf("비정상적으로 종료되었고 종료 시그널 번호는 %d이다.\n", status);
		}
		printf("이제 부모 프로세스의 일 처리\n");

		while (1)
		{
			printf("부모 : %d\n", counter++);
			sleep(1);
		}
	}
}
