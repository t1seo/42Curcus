/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:30:45 by tseo              #+#    #+#             */
/*   Updated: 2021/01/11 14:16:53 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// int map_width;
// int	map_height;
// int screen_height;
// int screen_width;

int	word_map[MAP_WIDTH][MAP_HEIGHT] =
						{
							{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
							{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
							{4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
							{4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
							{4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
							{4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
							{4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
							{4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
							{4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
							{4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
							{4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
							{6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
							{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
							{6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
							{4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
							{4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
							{4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
							{4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
							{4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
						};


void	setup(t_info *info)
{
	// map_width = 24;
	// map_height = 24;
	// screen_width = 640;
	// screen_height = 480;

	// TODO: GET PLAYER POSITION AND DIRECION FROM CUB FILE
	info->player_pos_x = 22.0;
	info->player_pos_y = 11.5;
	info->dir_vec_x = -1.0;
	info->dir_vec_y = 0.0;
	info->plane_x = 0.0;
	info->plane_y = 0.66;

	info->move_speed = 0.05;
	info->rot_speed = 0.05;

}

int		press_key(int key, t_info *info)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		info->key_w = 1;
	else if (key == KEY_A)
		info->key_a = 1;
	else if (key == KEY_D)
		info->key_d = 1;
	else if (key == KEY_S)
		info->key_s = 1;
	else if (key == KEY_LA)
		info->key_l_arrow = 1;
	else if (key == KEY_RA)
		info->key_r_arrow = 1;
	printf("press key\n");
	return (0);
}

int		release_key(int key, t_info *info)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		info->key_w = 0;
	else if (key == KEY_A)
		info->key_a = 0;
	else if (key == KEY_D)
		info->key_d = 0;
	else if (key == KEY_S)
		info->key_s = 0;
	else if (key == KEY_LA)
		info->key_l_arrow = 0;
	else if (key == KEY_RA)
		info->key_r_arrow = 0;
	printf("release key\n");
	return (0);
}


void	init_cub3d(void)
{
	t_info info;

	setup(&info);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	info.img.img = mlx_new_image(info.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);
	// mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &press_key, &info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &release_key, &info);

	mlx_loop(info.mlx);
}

int		main(int ac, char **av)
{
	// if (ac == 3 && check_cub_file(av[1]) && check_arg(av[2]))
	// {
	// 	// TODO: SAVE BMP
	// 	return (0);
	// }
	// else if (ac == 2 && check_cub_file(av[1]))
	// {
	// 	// TODO
	// 	return (0);
	// }
	// else
	// {
	// 	// TODO: Print Error Message
	// 	// printf("Error. Invaild ")
	// 	init_cub3d();
	// }
	init_cub3d();
	return (0);
}
