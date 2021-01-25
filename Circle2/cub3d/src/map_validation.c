/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:23:11 by tseo              #+#    #+#             */
/*   Updated: 2021/01/25 19:02:57 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	g_dirx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
static int	g_diry[8] = {0, 1, 0, -1, -1, 1, 1, -1};

int			check_testmap(char **test_map, int x, int y)
{
	int i;

	if (test_map[y][x] == '1' || test_map[y][x] == 'x')
		return (1);
	if (test_map[y][x] == ' ' || test_map[y][x] == '#')
		return (0);
	test_map[y][x] = 'x';
	i = -1;
	while (++i < 8)
		if (check_testmap(test_map, x + g_dirx[i], y + g_diry[i]) == 0)
			return (0);
	return (1);
}

char		**make_test_map(t_map_info *map_info)
{
	int		x;
	int		y;
	char	**test_map;

	if (!(test_map = (char **)malloc(sizeof(char *)
					* (map_info->map_height + 3))))
		return (0);
	test_map[map_info->map_height + 2] = 0;
	y = -1;
	while (++y < map_info->map_height + 2)
	{
		if (!(test_map[y] = (char *)malloc(sizeof(char)
						* (map_info->map_width + 3))))
			return (0);
		test_map[y][map_info->map_width + 2] = 0;
		x = -1;
		while (++x < map_info->map_width + 2)
			test_map[y][x] = '#';
	}
	copy_world_map(map_info, test_map);
	return (test_map);
}

void		check_player_position(t_map_info *map_info)
{
	int i;
	int j;
	int check;

	i = 0;
	check = 0;
	while (i < map_info->map_height)
	{
		j = 0;
		while (j < map_info->map_width)
		{
			if (check == 0 && check_player_direction(map_info->world_map[i][j]))
			{
				check = 1;
				map_info->player_pos_x = j;
				map_info->player_pos_y = i;
				map_info->player_direction = map_info->world_map[i][j];
			}
			else if (check == 1
					&& check_player_direction(map_info->world_map[i][j]))
				print_error_and_exit("Player Position Error");
			j++;
		}
		i++;
	}
}

void		search_map_exhausltly(t_map_info *map_info, char **test_map)
{
	int	x;
	int	y;

	y = -1;
	while (test_map[++y])
	{
		x = -1;
		while (test_map[y][++x])
		{
			if (test_map[y][x] == '0')
			{
				if (check_testmap(test_map, x, y) == 0)
					print_error_and_exit("Map is not valid");
			}
		}
	}
}

void		check_map_validation(t_map_info *map_info)
{
	char	**test_map;
	int		len;

	check_player_position(map_info);
	if ((test_map = make_test_map(map_info)) == 0)
		print_error_and_exit("Making Test Map Failed");
	search_map_exhausltly(map_info, test_map);
	len = 0;
	while (test_map[len])
		len++;
	while (--len >= 0)
		free(test_map[len]);
	free(test_map);
}
