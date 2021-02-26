#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef	struct		s_background
{
	int		width;
	int		height;
	char	b_char;
}					t_background;

typedef struct		s_rectangle
{
	char	r_type;
	float	start_x;
	float	start_y;
	float	width;
	float	height;
	char	r_char;
}					t_rectangle;

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		print_error(char *error_msg)
{
	write(1, error_msg, ft_strlen(error_msg));
	return (1); // 에러가 발생하면 프로그램은 1을 리턴
}

int		is_on_border(int x, int y, t_rectangle rect)
{
	return ((float)x - rect.start_x < 1.0f
	|| (rect.start_x + rect.width) - (float)x < 1.0f
	|| (float)y - rect.start_y < 1.0f
	|| (rect.start_y + rect.width) - (float)y < 1.0f);
}

int		is_in_rectangle(int x, int y, t_rectangle rect)
{
	return ((float)x >= rect.start_x
	&& (float)x <= rect.start_x + rect.width
	&& (float)y >= rect.start_y
	&& (float)y >= rect.start_y + rect.height);
}



