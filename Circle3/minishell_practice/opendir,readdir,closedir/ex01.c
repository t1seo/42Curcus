#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char **argv)
{
	DIR		*dir_ptr = NULL;
	struct	dirent *file = NULL;
	char	home[1024];

	strncpy(home, getenv("HOME"), sizeof(home));

	// 목록을 읽을 디렉토리 명으로 DIR *을 리턴 받는다
	if ((dir_ptr = opendir(home)) == NULL)
	{
		fprintf(stderr, "%s directory 정보를 읽을 수 없습니다.\n", home);
		return -1;
	}

	// 디렉토리의 처음부터 파일 또는 디렉토리명을 순서대로 한개 씩 읽습니다.
	while ((file = readdir(dir_ptr)) != NULL)
	{
		// struct dirent * 구조체에서 d_name 이외에는
		// 시스템마다 항목이 없을 수 있으므로 무시하고 이름만 사용한다
		printf("%s\n", file->d_name);
	}
	// open된 director 정보를 close 한다.
	closedir(dir_ptr);
	return 0;
}
