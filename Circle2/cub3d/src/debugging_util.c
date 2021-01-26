/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:43:58 by tseo              #+#    #+#             */
/*   Updated: 2021/01/26 15:55:27 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	print_map_info(t_map_info *map_info)
{
	int i;

	printf("SCREEN_WIDTH : %d, SCREEN_HEIGHT : %d\n", map_info->screen_width,
												map_info->screen_height);
	printf("N WALL TEXTURE PATH : %s\n", map_info->n_wall_texture_path);
	printf("S WALL TEXTURE PATH : %s\n", map_info->s_wall_texture_path);
	printf("N WALL TEXTURE PATH : %s\n", map_info->w_wall_texture_path);
	printf("N WALL TEXTURE PATH : %s\n", map_info->e_wall_texture_path);
	printf("SPRITE TEXTURE PATH : %s\n", map_info->sprite_texture_path);
	printf("FLOOR COLOR : %d\n", map_info->floor_color);
	printf("CEIL COLOR : %d\n", map_info->ceil_color);
	printf("MAP SIZE : %d x %d\n", map_info->map_width, map_info->map_height);
	i = 0;
	while (i < map_info->map_height)
	{
		printf("%s\n", map_info->world_map[i]);
		i++;
	}
	i = 0;
	while (i < NUM_OF_TEXTURES)
	{
		printf("Sprite %d : %lf %lf %d\n", i, g_sprite[i].x,
		g_sprite[i].y, g_sprite[i].texture);
		i++;
	}
}
