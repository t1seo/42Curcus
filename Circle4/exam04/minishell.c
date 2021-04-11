#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

typedef struct s_cmd
{
	char **args;
	int is_pipe;
	int fd[2];
	struct s_cmd *prev;
	struct s_cmd *next;
} t_cmd;

/*
** 1. Basic Library
** - ft_strlen
** - ft_putstr
** - exit_fatal
** - ft_strdup
*/

int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}
