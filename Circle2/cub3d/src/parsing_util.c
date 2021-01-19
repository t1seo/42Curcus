/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:40:33 by tseo              #+#    #+#             */
/*   Updated: 2021/01/19 02:31:37 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		check_all_information(t_map_info *map_info)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (map_info->info_check[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

void	print_map_info(t_map_info *map_info)
{
	printf("SCREEN_WIDTH : %d, SCREEN_HEIGHT : %d\n", map_info->screen_width, map_info->screen_height);
	printf("N WALL TEXTURE PATH : %s\n", map_info->n_wall_texture_path);
	printf("S WALL TEXTURE PATH : %s\n", map_info->s_wall_texture_path);
	printf("N WALL TEXTURE PATH : %s\n", map_info->w_wall_texture_path);
	printf("N WALL TEXTURE PATH : %s\n", map_info->e_wall_texture_path);
	printf("SPRITE TEXTURE PATH : %s\n", map_info->sprite_texture_path);
	printf("FLOOR COLOR : %d\n", map_info->floor_color);
	printf("CEIL COLOR : %d\n", map_info->ceil_color);
	printf("MAP SIZE : %d x %d\n", map_info->map_width, map_info->map_height);

	// for (int i = 0; i < map_info->map_height; i++)
	// {
	// 	for (int j = 0; j < map_info->map_width; j++)
	// 	{
	// 		printf("%c", map_info->world_map[i][j]);
	// 	}
	// 	printf("\n");
	// }
	for (int i = 0; i < map_info->map_height; i++)
	{
		printf("%s\n", map_info->world_map[i]);
	}

	printf("check all infomation:\n");
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", map_info->info_check[i]);
	}
	printf("\n");

	printf("Player Position : [%d, %d]\n", map_info->player_pos_x, map_info->player_pos_y);
	printf("Player Direction : %c\n", map_info->player_direction);
	// int i, j;
	// 	i = -1;
	// while (++i < SCREEN_HEIGHT)
	// {
	// 	j = -1;
	// 	while (++j < SCREEN_WIDTH)
	// 	{
	// 		printf("%d", p_info->world_map[i][j]);
	// 	}
	// 	printf("\n");
	// }
}
