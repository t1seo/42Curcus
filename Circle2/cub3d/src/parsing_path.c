/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:07:30 by tseo              #+#    #+#             */
/*   Updated: 2021/01/26 21:13:43 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		parse_no_texture_path(char *detailed_info, t_map_info *map_info)
{
	int i;

	i = 0;
	i += 2;
	while ((9 <= detailed_info[i] && detailed_info[i] <= 13)
			|| detailed_info[i] == ' ')
		i++;
	map_info->n_wall_texture_path = ft_strdup(&detailed_info[i]);
	if (map_info->n_wall_texture_path && map_info->info_check[1] == 0)
	{
		map_info->info_check[1] = 1;
		return (1);
	}
	else
	{
		return (0);
	}
}

int		parse_so_texture_path(char *detailed_info, t_map_info *map_info)
{
	int i;

	i = 0;
	i += 2;
	while ((9 <= detailed_info[i] && detailed_info[i] <= 13)
		|| detailed_info[i] == ' ')
		i++;
	map_info->s_wall_texture_path = ft_strdup(&detailed_info[i]);
	if (map_info->s_wall_texture_path && map_info->info_check[2] == 0)
	{
		map_info->info_check[2] = 1;
		return (1);
	}
	else
	{
		return (0);
	}
}

int		parse_we_texture_path(char *detailed_info, t_map_info *map_info)
{
	int i;

	i = 0;
	i += 2;
	while ((9 <= detailed_info[i] && detailed_info[i] <= 13)
		|| detailed_info[i] == ' ')
		i++;
	map_info->w_wall_texture_path = ft_strdup(&detailed_info[i]);
	if (map_info->w_wall_texture_path && map_info->info_check[3] == 0)
	{
		map_info->info_check[3] = 1;
		return (1);
	}
	else
	{
		return (0);
	}
}

int		parse_ea_texture_path(char *detailed_info, t_map_info *map_info)
{
	int i;

	i = 0;
	i += 2;
	while ((9 <= detailed_info[i] && detailed_info[i] <= 13)
		|| detailed_info[i] == ' ')
		i++;
	map_info->e_wall_texture_path = ft_strdup(&detailed_info[i]);
	if (map_info->e_wall_texture_path && map_info->info_check[4] == 0)
	{
		map_info->info_check[4] = 1;
		return (1);
	}
	else
	{
		return (0);
	}
}

int		parse_s_texture_path(char *detailed_info, t_map_info *map_info)
{
	int i;

	i = 0;
	i += 1;
	while ((9 <= detailed_info[i] && detailed_info[i] <= 13)
		|| detailed_info[i] == ' ')
		i++;
	map_info->sprite_texture_path = ft_strdup(&detailed_info[i]);
	if (map_info->sprite_texture_path && map_info->info_check[5] == 0)
	{
		map_info->info_check[5] = 1;
		return (1);
	}
	else
	{
		return (0);
	}
}
