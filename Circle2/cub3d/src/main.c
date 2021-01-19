/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 23:45:42 by tseo              #+#    #+#             */
/*   Updated: 2021/01/19 15:04:47 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


void	update(t_player_info *p_info, t_map_info *map_info)
{
	draw_floor_ceil(p_info);
	wall_casting(p_info);
	// sprite_casting(p_info);
}

int		main_loop(t_player_info *p_info, t_map_info *map_info)
{
	update(p_info, map_info);
	draw(p_info);
	move_player(p_info, map_info);
	return (0);
}

void	init_cub3d(char *map_file)
{
	t_map_info map_info;
	t_player_info p_info;

	map_info.map_file_name = ft_strdup(map_file);
	parse_map_info(&map_info);
	check_map_validation(&map_info);
	// print_map_info(&map_info);
	setup_player_info(&p_info, &map_info);
	make_world_map(&p_info, &map_info);
	setup_sprite_info(&p_info);
	p_info.mlx = mlx_init();
	load_texture(&p_info, &map_info);
	p_info.win = mlx_new_window(p_info.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");

	p_info.img.img = mlx_new_image(p_info.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	p_info.img.data = (int *)mlx_get_data_addr(p_info.img.img, &p_info.img.bpp, &p_info.img.size_l, &p_info.img.endian);

	mlx_loop_hook(p_info.mlx, &main_loop, &p_info);
	mlx_hook(p_info.win, X_EVENT_KEY_PRESS, 0, &press_key, &p_info);
	mlx_hook(p_info.win, X_EVENT_KEY_RELEASE, 0, &release_key, &p_info);
	mlx_loop(p_info.mlx);
}

int		main(int ac, char **av)
{
	if (ac == 3 && check_cub_file(av[1]) && check_save_arg(av[2]))
		printf("Cub File, Save Option Checked\n");
	else if (ac == 2 && check_cub_file(av[1]))
		init_cub3d(av[1]);
	else if (ac == 1 || ac > 3)
		printf("Error : Wrong Argument\n");
	return (0);
}
