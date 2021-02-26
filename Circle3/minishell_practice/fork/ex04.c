#include <stdio.h>
#include <unistd.h> // fork()
#include <stdlib.h>

int		main(int argc, char **argv)
{
	pid_t	pids[5];
	int		num_of_processes = 0;

	// 5개의 프로세스 생성
	// 자식 프로세스 ID를 배열에 저장한다
	while (num_of_processes < 5)
	{
		pids[num_of_processes] = fork(); // fork 실행

		if (pids[num_of_processes] < 0) // 자식 프로세스 생성 실패
			return (-1);
		else if (pids[num_of_processes] == 0) // 자식 프로세스 생성
		{
			printf("child\t%d, child's parents\t%d\n", getpid(), getppid());
			sleep(2);
			exit(0);
		}
		else
			printf("parent %d, child %d\n", getpid(), pids[num_of_processes]);
		num_of_processes++;
		sleep(1);
	}
}
