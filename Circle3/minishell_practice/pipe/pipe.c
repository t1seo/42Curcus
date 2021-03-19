#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char *argv[])
{
	int	fds[2]; // 2개의 fd를 담을 배열 정의
	pipe(fds); // pipe를 호출해 두 개의 fd로 배열을 채워준다
	pid_t pid = fork(); // 부모 프로세스의 fd와 메모리를 복제한 자식 프로세스를 생성한다.

	if (pid == 0) // 자식 프로세스
	{
		dup2(fds[0], STDIN_FILENO); // fds[0]으로 표준입력을 넘겨준다
		close(fds[0]);				// 자식 프로세스에서는 더 이상 필요하지 않기 때문에 닫아준다.
		close(fds[1]);				// 원래부터 필요없었던 fd라 닫아준다.
		char *cmd[] = {(char *)"sort", NULL}; // sort 명령어 인자를 만들어준다.
		if (execvp(cmd[0], cmd) < 0)
			exit(0); // sort 명령어 실행하고 문제있으면 exit
	}

	// 부모 프로세스 코드 시작
	close(fds[0]); // 부모는 쓰기만 하면 되므로 부모 프로세스에서 필요 없는 읽기는 닫아준다.
	const char *words[] = {"pear", "peach", "apple"};

	for (int i = 0; i < 3; i++)
		dprintf(fds[1], "%s\n", words[i]); // fds[1]에 출력을 쓴다.
	close(fds[1]);

	int status;
	pid_t wpid = waitpid(pid, &status, 0); // 자식 프로세스가 종료될 때까지 기다린다.
	return (wpid == pid && WIFEXITED(status) ? WEXITSTATUS(status) : -1);
}
