#include <stdio.h> // FILE
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef	struct		s_background
{
	int		width;
	int		height;
	char	character;
}					t_background;

typedef struct		s_circle
{
	char	type;
	float	center_x;
	float	center_y;
	float	radius;
	char	character;
}					t_circle;

int		ft_strlen(char *str)
{
	int i;

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


int		main(int argc, char *argv[])
{
	FILE	*file;
	char	*image;
	int 	read;

	int				x;
	int				y;
	float			distance;
	t_background	bg;
	t_circle		circle;

	if (argc != 2) // 인자 개수
		return (print_error("Error: argument\n"));
	if (!(file = fopen(argv[1], "r"))) // 파일 열기
		return (print_error("Error: Operation file corrupted\n"));
	if (fscanf(file, "%d %d %d\n", &bg.width, &bg.height, &bg.character) != 3) // 배경 파싱
		return (print_error("Error: Operation file corrupted\n"));
	if (!(bg.width > 0 && bg.width <= 300 && bg.height > 0 && bg.height <= 300)) // 배경 에러 처리
		return (print_error("Error: Operation file corrupted\n"));

	image = (char *)malloc(sizeof(char) * (bg.width * bg.height)); // 배경 크기만큼 할당
	memset(image, bg.character, bg.width * bg.height); // 배경 채우기
	read = fscanf(file, "%c %f %f %f %c\n", &circle.type, &circle.center_x,
		&circle.center_y, &circle.radius, &circle.character); // 원 값 파싱

	// 원 그리기
	while (read == 5)
	{
		y = 0;
		while (y < bg.height)
		{
			x = 0;
			while (x < bg.width)
			{
				distance = sqrtf(powf(x - circle.center_x, 2.) + powf(y - circle.center_y, 2.));
				if (distance <= circle.radius)
				{
					if (circle.type == 'c')
					{
						if (circle.radius - distance < 1.0f)
							image[y * bg.width + x] = circle.character;
					}
					else if (circle.type == 'C')
						image[y * bg.width + x] = circle.character;
				}
				x++;
			}
			y++;
		}
		read = fscanf(file, "%c %f %f %f %c\n", &circle.type, &circle.center_x,
			&circle.center_y, &circle.radius, &circle.character); // 원 값 파싱
	}

	// EOF이 아닐 때
	if (read != -1)
	{
		free(image);
		return (print_error("Error: Operation file corrupted\n"));
	}
	// 그리기
	y = 0;
	while (y < bg.height)
	{
		write(1, image + y * bg.height, bg.width);
		write(1, "\n", 1);
	}
	free(image);
	free(file);
	return (0);
}


