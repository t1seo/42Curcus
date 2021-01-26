/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_util_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:40:33 by tseo              #+#    #+#             */
/*   Updated: 2021/01/26 22:07:35 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	g_height;
static char	*g_line;

void	reset_map_info(t_map_info *map_info)
{
	int i;

	i = -1;
	while (++i < 8)
		map_info->info_check[i] = 0;
	map_info->screen_width = 0;
	map_info->screen_height = 0;
	map_info->n_wall_texture_path = 0;
	map_info->s_wall_texture_path = 0;
	map_info->w_wall_texture_path = 0;
	map_info->e_wall_texture_path = 0;
	map_info->sprite_texture_path = 0;
	map_info->floor_color = 0;
	map_info->ceil_color = 0;
	map_info->map_width = 0;
	map_info->map_height = 0;
	map_info->world_map = 0;
	map_info->player_pos_x = 0;
	map_info->player_pos_y = 0;
	map_info->player_direction = 0;
}

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

void	parse_resolution_x_y(char *detailed_info, t_map_info *map_info)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (detailed_info[i])
	{
		if (flag == 0 && ft_isdigit(detailed_info[i]))
		{
			map_info->screen_width = ft_atoi(&detailed_info[i]);
			while (ft_isdigit(detailed_info[i]))
				i++;
			flag = 1;
		}
		else if (flag == 1 && ft_isdigit(detailed_info[i]))
		{
			map_info->screen_height = ft_atoi(&detailed_info[i]);
			break ;
		}
		i++;
	}
}

void	parse_line(t_map_info *map_info, int fd)
{
	int		i;
	int		ret;

	while ((ret = get_next_line(fd, &g_line)) > 0)
	{
		i = 0;
		skip_space(g_line, &i);
		if (ft_isalpha(g_line[i]) && !check_all_information(map_info))
			parse_detailed_map_info(&g_line[i], map_info, fd);
		else if (ft_isdigit(g_line[i]) && !check_all_information(map_info))
			print_parsing_error("Lack of Map Information", fd);
		else if (ft_isdigit(g_line[i]) && check_all_information(map_info))
		{
			map_info->world_map[g_height] = ft_strdup(g_line);
			g_height++;
		}
		free(g_line);
	}
	skip_space(g_line, &i);
	if (ft_isdigit(g_line[i]) && check_all_information(map_info))
	{
		map_info->world_map[g_height] = ft_strdup(g_line);
		g_height++;
	}
	free(g_line);
}
