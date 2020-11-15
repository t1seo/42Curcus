#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

# ifndef MAX_FD
#  define MAX_FD 24
# endif

int     get_next_line(int fd, char **line);

#endif