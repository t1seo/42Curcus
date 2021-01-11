#include <stdio.h>
#include "../include/mlx.h"

int main(void)
{
	void	*mlx;
	void	*win;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;

	int		img_width;
	int		img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "img_load");
	img1 = mlx_xpm_file_to_image(mlx, "../textures/wall_n.xpm", &img_width, &img_height);;
	img2 = mlx_xpm_file_to_image(mlx, "../textures/wall_s.xpm", &img_width, &img_height);;
	img3 = mlx_xpm_file_to_image(mlx, "../textures/wall_e.xpm", &img_width, &img_height);;
	img4 = mlx_xpm_file_to_image(mlx, "../textures/wall_w.xpm", &img_width, &img_height);;
	mlx_put_image_to_window(mlx, win, img1, 50, 50);
	mlx_put_image_to_window(mlx, win, img2, 200, 50);
	mlx_put_image_to_window(mlx, win, img3, 50, 200);
	mlx_put_image_to_window(mlx, win, img4, 200, 200);
	mlx_loop(mlx);
	return (0);
}
