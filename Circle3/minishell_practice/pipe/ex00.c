#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_BUF 1024
#define READ 0 // 읽기 파이프
#define WRITE 1 // 쓰기 파이프

int main()
{
	int fd[2];
	pid_t pid;
	char buf[MAX_BUF];

	if (pipe(fd) < 0)
	{
		printf("pipe error\n");
		exit(1);
	}
	if ((pid = fork()) < 0)
	{
		printf("fork error\n");
		exit(1);
	}
	printf("\n");

	if (pid > 0) // parent process
	{
		close(fd[READ]); // 부모의 읽기 파이프 닫는다
		strcpy(buf, "message from parent\n");
		write(fd[WRITE], buf, strlen(buf)); // 부모의 쓰기 파이프에 쓴다.
	}
	else // child process
	{
		close(fd[WRITE]); // 자식의 쓰기 파이프는 닫는다
		read(fd[READ], buf, MAX_BUF);
		printf("child got message : %s\n", buf);
	}
	exit(0);
}
