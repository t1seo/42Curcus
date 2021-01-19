/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:13:19 by tseo              #+#    #+#             */
/*   Updated: 2021/01/19 20:48:34 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int **g_world_map;
int g_num_of_sprites;

void	make_world_map(t_player_info *p_info, t_map_info *map_info)
{
	int i;
	int j;

	if (!(g_world_map = (int **)malloc(sizeof(int *) * MAP_HEIGHT)))
	{
		printf("Error : Memory Allocation Failed.\n");
		exit(0);
	}
	i = -1;
	while (++i < MAP_HEIGHT)
		if (!(g_world_map[i] = (int *)malloc(sizeof(int) * MAP_WIDTH)))
		{
			printf("Error : Memory Allocation Failed.\n");
			exit(0);
		}

	i = -1;
	while (++i < MAP_HEIGHT)
	{
		j = -1;
		while (++j < MAP_WIDTH)
		{
			g_world_map[i][j] = 1;
		}
	}

	i = -1;
	while (++i < MAP_HEIGHT)
	{
		j = -1;
		while (++j < MAP_WIDTH)
		{
			if (map_info->world_map[i][j] == '0' || map_info->world_map[i][j] == 'N'
		 	|| map_info->world_map[i][j] == 'S' || map_info->world_map[i][j] == 'W'
			|| map_info->world_map[i][j] == 'E')
			{
				g_world_map[i][j] = 0;
			}
			else if (map_info->world_map[i][j] == '2')
			{
				g_world_map[i][j] = 2;
				g_num_of_sprites++;
			}
		}
	}

	// i = -1;
	// while (++i < MAP_HEIGHT)
	// {
	// 	j = -1;
	// 	while (++j < MAP_WIDTH)
	// 	{
	// 		printf("%d", g_world_map[i][j]);
	// 	}
	// 	printf("\n");
	// }
}
