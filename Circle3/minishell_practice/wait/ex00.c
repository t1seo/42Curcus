#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int		main(void)
{
	int		counter = 1;
	int		status;
	pid_t	pid;
	pid_t	pid_child;

	pid = fork(); // fork 실행

	if (pid < 0)
	{
		printf("자식 프로세스 생성 실패\n");
		return -1;
	}
	else if (pid == 0)
	{
		printf("저는 자식 프로세스로 5까지 카운트하고 종료하겠습니다.\n");
		while (6 > counter)
		{
			printf("자식 : %d\n", counter++);
			sleep(1);
		}
		return 99; // 자식 프로세스는 일을 종료하고 99를 리턴한다.
	}
	else
	{
		printf("저는 부모 프로세스로 자식 프로세스 작업이 \
		끝날 때까지 대기합니다.\n");

		pid_child = wait(&status); // wait

		printf("종료된 자식 프로세스 ID는 %d\n", pid_child);

		// 정상 종료되면 상위 8비트에 반환값이 저장된다.
		if (0 == (status & 0xff))
		{
			printf("정상적으로 종료되었고 반환값은 %d입니다.\n", status >> 8);
		}
		// 시그널에 의해 종료되면 하위 8비트에 시그널 번호가 저장된다.
		else
		{
			printf("비 정상적으로 종료되었고 종료 시그널 번호는 %d입니다.\n", status);
		}

		printf("이제 제 일을 처리하겠습니다.\n");

		while(1)
		{
			printf("부모: %d\n", counter++);
			sleep(1);
		}
	}
}
