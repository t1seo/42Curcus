#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

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

	// background
	int		b_width;
	int		b_height;
	char	b_char;

	// rectangle
	char	type;
	float	start_x;
	float	start_y;
	float	width;
	float	height;
	char	r_char;



	if (argc != 2)
		print_error("Error: argument\n");
	if (!(file = fopen(argv[1], "r")))
		print_error("Error: Operation file corrupted\n");
	if (fscanf(file, "%d %d %c\n", &b_width, &b_height, &b_char) != 3)
		print_error("Error: Operation file corrupted\n");
	if (!(b_width > 0 && b_width <= 300 && b_height > 0 && b_height <= 300))
		print_error("Error: Operation file corrupted\n");

	image = (char *)malloc(sizeof(char) * (b_width * b_height));
	memset(image, b_char, b_width * b_height);
	read = fscanf(file, "%c %f %f %f %f %c\n", &type, &start_x, &start_y, &width, &height, &r_char);


	while (read == 6)
	{
		if (!(width > 0 && height > 0) || !(type == 'r' || type == 'R'))
		{
			free(image);
			print_error("Error: Operation file corrupted\n");
		}
		//  if (!(width > 0 && height > 0) || !(type == 'R' || type == 'r'))
        // {
        //     free(image);
        //     return (print_error("Error: Operation file corrupted\n"));
        // }
		y = 0;
		while (y < b_height)
		{
			x = 0;
			while (x < b_width)
			{

				if (type == 'r')
				{
					if ((float)x - start_x < 1.0f || (start_x + width) - (float)x < 1.0f
					|| (float)y - start_y < 1.0f || (start_y + height) - (float)y < 1.0f)
					{
						if ((float)x >= start_x && (float)x <= start_x + width
						&& (float)y >= start_y && (float)y <= start_y + height)
							image[b_width * y + x] = r_char;
					}
				}
				else if (type == 'R')
				{
					if ((float)x >= start_x && (float)x <= start_x + width
					&& (float)y >= start_y && (float)y <= start_y + height)
						image[b_width * y + x] = r_char;
				}
				x++;
			}
			y++;
		}
		read = fscanf(file, "%c %f %f %f %f %c\n", &type, &start_x, &start_y, &width, &height, &r_char);
	}

	//     while (read == 6)
    // {
    //     // 직사각형 타입과 가로 세로 에러 처리
    //     if (!(width > 0 && height > 0) || !(type == 'R' || type == 'r'))
    //     {
    //         free(image);
    //         return (print_error("Error: Operation file corrupted\n"));
    //     }
    //     // 직사각형 그리기
    //     y = 0;
    //     while (y < b_height)
    //     {
    //         x = 0;
    //         while (x < b_width)
    //         {
    //             if (type == 'r')
    //             {
    //                 // 테두리인지 확인하기 (직사각형의 좌, 우, 상, 하의 면 확인)
    //                 if ((float)x - start_x < 1.0f || (start_x + width) - (float)x < 1.0000000 ||
    //                     (float)y - start_y < 1.0000000 || (start_y + height) - (float)y < 1.0000000)
    //                 {
    //                 if ((float)x >= start_x && (float)x <= start_x + width &&
    //                     (float)y >= start_y && (float)y <= start_y + height)
    //                     image[y * b_width + x] = r_char;
    //                 }
    //             }
    //             else if (type == 'R')
    //             {
    //                 if ((float)x >= start_x && (float)x <= start_x + width &&
    //                     (float)y >= start_y && (float)y <= start_y + height)
    //                     image[y * b_width + x] = r_char;
    //             }
    //             x++;
    //         }
    //         y++;
    //     }
    //     read = fscanf(file, "%c %f %f %f %f %c\n", &type, &start_x, &start_y, &width, &height, &r_char);
    // }

	if (read != -1)
	{
		free(image);
		print_error("Error: Operation file corrupted\n");
	}

	y = 0;
	while (y < b_height)
	{
		write(1, image + y * b_height, b_width);
		write(1, "\n", 1);
		y++;
	}

	free(image);
	fclose(file);
	return (0);



}


