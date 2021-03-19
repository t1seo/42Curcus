#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	pid = fork();

	if (pid < 0)
		printf("fork failed\n");
	else if (pid == 0)
	{
		execl("/bin/ls", "ls", "-l", (char *)0);
		printf("exec failed");
	}
	else
	{
		wait((int*) 0);
		printf("ls completed\n");
		exit(0);
	}
}
