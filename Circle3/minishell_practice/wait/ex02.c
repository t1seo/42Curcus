#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int		main(void)
{
	pid_t	childPid;
	int		status, i;

	childPid = fork();

	if (childPid > 0) // 부모 프로세스
	{
		pid_t	waitPid;
		printf("부모 PID: %ld, pid: %d %d\n", (long)getpid(), childPid, errno);

		waitPid = wait(&status);

		if (waitPid == -1) // wait 함수 오류
		{
			printf("에러 넘버: %d\n", errno);
			perror("wait 함수 오류 반환\n");
		}
		else
		{
			if (WIFEXITED(status)) // 자식 프로세스가 정상적으로 종료
			{
				printf("wait: 자식 프로세스 정상 종료 %d\n", WEXITSTATUS(status));
			}
			else if (WIFSIGNALED(status)) // 자식 프로세스 비정상 종료
			{
				printf("wait: 자식 프로세스 비정상 종료 %d\n", WTERMSIG(status));
			}
		}
		printf("부모 종료 %d %d\n", waitPid, WTERMSIG(status));
	}
	else if (childPid == 0) // 자식 코드
	{
		printf("자식 PID : %ld\n", (long)getpid());

		// 자식 프로세스 5초 동안 동작
		for (i = 0; i < 5; i++)
		{
			sleep(1);
		}
		printf("자식 종료\n");
		exit(0);
	}
	else // fork 실패
	{
		perror("fork fail!\n");
		return -1;
	}
	return 0;
}
