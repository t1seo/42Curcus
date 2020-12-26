#include "../include/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct		s_mlx
{
	void	*mlx;
	void	*win;
	int		cnt;
}					t_mlx;

int		keypress_event(int keycode, t_mlx *mlx)
{
	mlx->cnt++;
	printf("cnt : %d\n", mlx->cnt);
	printf("keycode : %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main(void)
{
	t_mlx	mlx;

	mlx.cnt = 0;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 640, 480, "events");

	mlx_hook(mlx.win, 2, 1L << 0, &keypress_event, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
