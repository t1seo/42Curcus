/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_map_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:20:11 by tseo              #+#    #+#             */
/*   Updated: 2021/01/25 19:45:32 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		check_map_tile(char tile)
{
	if (tile == '0' || tile == 'N' || tile == 'S'
	|| tile == 'W' || tile == 'E')
		return (1);
	else
		return (0);
}

int		check_invalid_map_tile(char tile)
{
	if ('3' <= tile && tile <= '9')
		return (1);
	if (ft_isalpha(tile) && tile != 'N' && tile != 'S'
		&& tile != 'W' && tile != 'E')
		return (1);
	return (0);
}

void	fill_global_map_with_one(void)
{
	int i;
	int j;

	i = -1;
	while (++i < MAP_HEIGHT)
	{
		j = -1;
		while (++j < MAP_WIDTH)
		{
			g_world_map[i][j] = 1;
		}
	}
}

void	make_global_map(t_map_info *map_info)
{
	int i;
	int j;

	i = -1;
	while (++i < MAP_HEIGHT)
	{
		j = -1;
		while (++j < MAP_WIDTH)
		{
			if (check_map_tile(map_info->world_map[i][j]))
			{
				g_world_map[i][j] = 0;
			}
			else if (map_info->world_map[i][j] == '2')
			{
				g_world_map[i][j] = 2;
				g_num_of_sprites++;
			}
			else if (check_invalid_map_tile(map_info->world_map[i][j]))
			{
				printf("MAP TILE ERROR\n");
				exit(0);
			}
		}
	}
}
