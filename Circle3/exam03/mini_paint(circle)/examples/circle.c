#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

int		ft_strlen(char *str)
{
	int i;

	while (str[i])
		i++;
	return (i);
}

int		print_error(char *error_msg)
{
	write(1, error_msg, ft_strlen(error_msg));
	return (1);
}

int		main(int argc, char *argv[])
{
	FILE	*file;
	char	*image;
	int		read;
	int		x;
	int		y;
	float	distance;

	// background
	int		b_width;
	int		b_height;
	char	b_char;

	// circle
	char	type;
	float	center_x;
	float	center_y;
	float	r;
	char	c_char;

	if (argc != 2)
		return (print_error("Error: argument\n"));
	if (!(file = fopen(argv[1], "r")))
		return (print_error("Error: Operation file corrupted\n"));
	if (fscanf(file, "%d %d %c\n", &b_width, &b_height, &b_char) != 3)
		return (print_error("Error: Operation file corrupted\n"));
	if (!(b_width > 0 && b_width <= 300 & b_height > 0 && b_height <= 300))
		return (print_error("Error: Operation file corrupted\n"));
	image = (char *)malloc(sizeof(char) * (b_width * b_height));
	memset(image, b_char, b_width * b_height);
	read = fscanf(file, "%c %f %f %f %c\n", &type, &center_x, &center_y, &r, &c_char);

	while (read == 5)
	{
		if (!(r > 0) || !(type == 'c' || type == 'C'))
		{
			free(image);
			return (print_error("Error: Operation file corrupted"));
		}
		y = 0;
		while (y < b_height)
		{
			x = 0;
			while (x < b_width)
			{
				distance = sqrtf(powf(x - center_x, 2) + powf(y - center_y, 2));
				if (distance <= r)
				{
					if (type == 'c' && r - distance < 1.0f)
						image[y * b_width + x] = c_char;
					else if (type == 'C')
						image[y * b_width + x] = c_char;
				}
				x++;
			}
			y++;
		}
		read = fscanf(file, "%c %f %f %f %c\n", &type, &center_x, &center_y, &r, &c_char);
	}
	if (read != -1)
	{
		free(image);
		return (print_error("Error: Operation file corrupted\n"));
	}
	y = 0;
	while (y < b_height)
	{
		write(1, image + y * b_width, b_width);
		write(1, "\n", 1);
		y++;
	}
	free(image);
	fclose(file);
	return (0);
}
