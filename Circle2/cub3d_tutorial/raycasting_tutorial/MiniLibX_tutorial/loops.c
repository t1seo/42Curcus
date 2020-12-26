#include "../include/mlx.h"
#include <stdio.h>

// typedef struct		s_data
// {
// 	void	*mlx;
// 	void	*win;
// 	int		x;
// 	int		y;
// }					t_data;

// int		event_key(int keycode, t_data *data)
// {
// 	printf("keycode : %d\n", keycode);
// 	data->x++;
// 	data->y++;
// 	return (0);
// }

// int		render_next_frame(t_data *data)
// {
// 	data->x++;
// 	data->y++;
// 	mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0xFF0000);
// 	return (0);
// }

// int		main(void)
// {
// 	t_data data;

// 	data.x = 0;
// 	data.y = 0;

// 	data.mlx = mlx_init();
// 	data.win = mlx_new_window(data.mlx, 640, 480, "loops");
// 	mlx_hook(data.win, 2, 1, event_key, &data);
// 	mlx_loop_hook(data.mlx, render_next_frame, &data);
// 	mlx_loop(data.mlx);
// 	return (0);
// }

typedef struct    s_data
{
    void        *mlx;
    void        *win;
    int            x;
    int            y;
}                t_data;

int     event_key(int keycode, t_data *data)
{
    printf("keycode : %d\n", keycode);
    data->x++;
    data->y++;
    return (0);
}

int     render_next_frame(t_data *data)
{
    data->x++;
    data->y++;
    mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0xFF0000);
    return (0);
}

int     main(void)
{
    t_data data;

    data.x = 0; data.y = 0;
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 1920, 1080, "title");
    mlx_hook(data.win, 2, 1, event_key, &data);
    mlx_loop_hook(data.mlx, render_next_frame, &data);
    mlx_loop(data.mlx);
}
