#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int		main(void)
{
	int		counter = 1;
	int		status;
	pid_t	pid;
	pid_t	pid_child;

	printf("부모: 첫번째 자식 프로세스를 생성한다.\n");
	pid = fork();

	if (pid < 0)
	{
		printf("자식 프로세스 생성 실패\n");
		return -1;
	}
	else if (pid == 0)
	{
		printf("첫번째 자식: 5까지 카운트하고 종료\n");

		while (6 > counter)
		{
			printf("1st: %d\n", counter++);
			sleep(1);
		}
		return 99;
	}
	else if (pid > 0)
	{
		printf("부모: 두번째 자식 프로세스를 생성\n");
		pid = fork();

		if (pid < 0)
		{
			printf("자식 프로세스 생성 실패\n");
			return -1;
		}
		else if (pid == 0)
		{
			printf("두번쨰 자식: 10까지 카운트하고 종료\n");
			while (11 > counter)
			{
				printf("2nd: %d\n", counter++);
				sleep(1);
			}
			return 99;
		}
		else if (pid > 0)
		{
			printf("부모: 부모 프로세스로 자식 프로세스 작업이 종료되었는지 확인하면서 일을 한다\n");

			while (1)
			{
				printf("부모: %d\n", counter++);
				pid_child = waitpid(pid, &status, WNOHANG);
				if (0 != pid_child)
				{
					printf("자식 프로세스가 종료되었다.\n");
				}
				sleep(1);
			}
		}
	}
}
