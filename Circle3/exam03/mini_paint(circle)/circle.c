#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int		ft_strlen(char *str)
{
	int		i;

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
		print_error("Error: argument\n");
	if (!(file = fopen(argv[1], "r")))
		print_error("Error: Operation file corrupted\n");
	if (fscanf(file, "%d %d %c\n", &b_width, &b_height, &b_char) != 3)
		print_error("Error: Operation file corrupted\n");
	if (!(b_width > 0 && b_width <= 300 & b_height > 0 && b_height <= 300))
		print_error("Error: Operation file corrupted\n");
	image = (char *)malloc(sizeof(char) * (b_width * b_height));
	memset(image, b_char, b_width * b_height);
	read = fscanf(file, "%c %f %f %f %c\n", &type, &center_x, &center_y, &r, &c_char);

	while (read == 5)
	{
		if (!(r > 0) || !(type == 'c' || type == 'C'))
		{
			free(image);
			print_error("Error: Operation file corrupted\n");
		}
		y = 0;
		while (y < b_height)
		{
			x = 0;
			while (x < b_width)
			{
				distance = sqrtf(powf((float)x - center_x, 2.0) + powf((float)y - center_y, 2.0));
				if (distance <= r)
				{
					if (type == 'c' && r - distance < 1.0f)
						image[b_height * y + x] = c_char;
					else if (type == 'C')
						image[b_height * y + x] = c_char;
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
		print_error("Error: Operation file corrupted\n");
	}

	y = 0;
	while (y < b_height)
	{
		write(1, image + b_width * y, b_width);
		write(1, "\n", 1);
		y++;
	}

	free(image);
	fclose(file);
	return (0);
}

