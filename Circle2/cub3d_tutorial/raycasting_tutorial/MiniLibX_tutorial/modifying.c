#include <stdio.h>
#include "../include/mlx.h"

typedef struct		s_mlx
{
	void	*mlx;
	void	*win;
}					t_mlx;

typedef struct		s_img
{
	void	*img;
	int		*data;
	int		width;
	int		height;
	int		bpp;
	int		line_size;
	int		endian;
}					t_img;

int		main(void)
{
	t_mlx	mlx;
	t_img	img;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 300, 300, "modifying");
	img.img = mlx_xpm_file_to_image(mlx.mlx, "./textures/wall_n.xpm", &img.width, &img.height);
	img.data = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.line_size, &img.endian);

	// draw vertical lines
	int y = 0;
	while (y < img.height)
	{
		int x = 0;
		while (x < img.width)
		{
			if (x % 5 == 0)
				img.data[img.width * y + x] = 0x00FF00;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
