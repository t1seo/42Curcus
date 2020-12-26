#include "../include/mlx.h"

typedef struct	s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;


// encoding color
int		create_trg(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// decoding colors
int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		get_b(int trgb)
{
	return (trgb & 0xFF);
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	print_pyramid(t_img_data *data, int x, int y, int size, int color)
{
	int num = size;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < 2 * i + 1; j++)
			my_mlx_pixel_put(data, num - i + j + x, i + y, color);
}


int		main(void)
{
	void		*mlx;
	void		*win;
	t_img_data	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 480, "mlx");

	img.img = mlx_new_image(mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	print_pyramid(&img, 100, 100, 100, 0x000000FF);
	print_pyramid(&img, 150, 100, 100, 0x0000FF00);
	print_pyramid(&img, 200, 100, 100, 0x00FF0000);

	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}


