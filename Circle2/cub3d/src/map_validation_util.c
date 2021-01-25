/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:16:45 by tseo              #+#    #+#             */
/*   Updated: 2021/01/25 19:02:41 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int			check_player_direction(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

void		copy_world_map(t_map_info *map_info, char **test_map)
{
	int x;
	int y;

	y = -1;
	while (++y < map_info->map_height)
	{
		x = -1;
		while (map_info->world_map[y][++x])
			test_map[y + 1][x + 1] = map_info->world_map[y][x];
	}
}

