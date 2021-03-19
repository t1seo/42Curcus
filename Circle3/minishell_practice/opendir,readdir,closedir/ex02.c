#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int	remove_all_backup_file(const char *path)
{
	DIR *dir_ptr = NULL;
	struct	dirent *file = NULL;
	struct	stat buf;
	char	*ext;
	char	filename[1024];

	// 목록을 읽을 디렉토리명으로 DIR *을 return 받는다
	if ((dir_ptr = opendir(path)) == NULL)
	{
		return -1;
	}

	// 디렉토리의 처음부터 파일 또는 디렉토리 명을 순서대로 한 개씩 읽는다
	while ((file = readdir(dir_ptr)) != NULL)
	{
		// readdir 읽혀진 파일명 중에서 현재 디렉토리를 나타내는 . 도 포함되어 있으므로
		// 무한 반복에 빠지지 않으려면 파일명이 . 이거나 .. 이면 skip 해야 한다.
		if (strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0)
			continue;
		sprintf(filename, "%s/%s", path, file->d_name);

		// 파일의 속성(파일의 유형, 크기, 생성/변경 시간 등을 얻기 위해서)
		if (stat(filename, &buf) == -1)
			continue;
		if (S_ISDIR(buf.st_mode)) // 검색된 이름의 속성이 디렉토리이면
		{
			// 검색된 파일이 directory이면 재귀호출로 하위 데릭토리를 다시 검색
			remove_all_backup_file(filename);
		}
		else if (S_ISREG(buf.st_mode)) // 검색된 이름의 속성이 일반파일이면
		{
			if ((ext = strrchr(filename, '.')) == NULL)
				continue;
			if (strcmp(ext, ".bak") == 0) // 파일의 확장자가 .bak 이면 파일을 삭제한다
				unlink(filename);
		}
	}

	// open된 directory 정보를 close 한다
	closedir(dir_ptr);
	return 0;
}

int main(int argc, char **argv)
{
	int idx;

	for (idx = 1; idx < argc; idx++)
	{
		printf("%s 디렉토리 하위에 있는 모든 .bak 파일을 지웁니다.\n", argv[idx]);
		remove_all_backup_file(argv[idx]);
	}
}
