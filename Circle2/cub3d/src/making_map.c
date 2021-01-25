/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 02:13:19 by tseo              #+#    #+#             */
/*   Updated: 2021/01/25 19:45:55 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int			**g_world_map;
int			g_num_of_sprites;
t_sprite	*g_sprite;

void	get_sprite_position(void)
{
	int num;
	int i;
	int j;

	if (!(g_sprite = (t_sprite *)malloc(sizeof(t_sprite) * NUM_OF_SPRITES)))
	{
		printf("Error : Memory Allocation Failed.\n");
		exit(0);
	}
	i = -1;
	num = 0;
	while (++i < MAP_HEIGHT)
	{
		j = -1;
		while (++j < MAP_WIDTH)
		{
			if (g_world_map[i][j] == 2)
			{
				g_sprite[num].x = (double)i + 0.5;
				g_sprite[num].y = (double)j + 0.5;
				g_sprite[num].texture = 4;
				num++;
			}
		}
	}
}

void	make_world_map(t_player_info *p_info, t_map_info *map_info)
{
	int i;

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
	fill_global_map_with_one();
	make_global_map(map_info);
	get_sprite_position();
}
