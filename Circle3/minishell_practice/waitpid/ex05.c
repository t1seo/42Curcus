#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

int main()
{
	pid_t	childPid;
	int		status;

	childPid = fork();

	if (childPid > 0) // 부모 프로세스
	{
		int ret;
		printf("부모 PID: %ld, pid: %d\n", (long)getpid(), childPid);
		sleep(3); // 부모는 3초 동안 동작
		ret = waitpid(99999, &status, WNOHANG); // pid로 99999(존재하지 않는 프로세스 ID)

		printf("부모 종료 %d %d %s\n", ret, errno, strerror(errno)); // 오류가 발생하였을 경우 errno값을 확인
		exit(0);
	}
	else if (childPid == 0) // 자식 코드
	{
		printf("자식 시작 PID: %ld\n", (long)getpid());
		sleep(8);  // 자식은 8초 동안 동작

		printf("자식 종료\n");
		exit(0);
	}
	else // fork 실패
	{
		perror("fork fail!\n");
		return 01;
	}
	return 0;
}
