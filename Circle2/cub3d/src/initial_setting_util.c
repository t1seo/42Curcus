/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setting_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:09:08 by tseo              #+#    #+#             */
/*   Updated: 2021/01/27 13:13:37 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static const double g_vectors[4][4] = {
	{-0.66, 0, 0, -1},
	{0.66, 0, 0, 1},
	{0, 0.66, -1, 0},
	{0, -0.66, 1, 0}
};

void	setup_direction_vectors(t_player_info *p_info, int i)
{
	p_info->plane_x = g_vectors[i][0];
	p_info->plane_y = g_vectors[i][1];
	p_info->dir_x = g_vectors[i][2];
	p_info->dir_y = g_vectors[i][3];
}

void	setup_player_direction(t_player_info *p_info, t_map_info *map_info)
{
	if (map_info->player_direction == 'W')
		setup_direction_vectors(p_info, 0);
	else if (map_info->player_direction == 'E')
		setup_direction_vectors(p_info, 1);
	else if (map_info->player_direction == 'N')
		setup_direction_vectors(p_info, 2);
	else if (map_info->player_direction == 'S')
		setup_direction_vectors(p_info, 3);
}

void	setup_screen_map_config(t_player_info *p_info, t_map_info *map_info)
{
	int resolution_x;
	int resolution_y;

	mlx_get_screen_size(p_info->mlx, &resolution_x, &resolution_y);
	g_map_width = map_info->map_width;
	g_map_height = map_info->map_height;
	if (map_info->screen_width > resolution_x || map_info->screen_width < 100)
		map_info->screen_width = resolution_x;
	if (map_info->screen_height > resolution_y || map_info->screen_height < 100)
		map_info->screen_height = resolution_y;
	g_screen_width = map_info->screen_width;
	g_screen_height = map_info->screen_height;
	g_floor_color = map_info->floor_color;
	g_ceil_color = map_info->ceil_color;
	g_tex_width = 64;
	g_tex_height = 64;
}

void	setup_player_keys(t_player_info *p_info)
{
	p_info->key_a = 0;
	p_info->key_w = 0;
	p_info->key_s = 0;
	p_info->key_d = 0;
	p_info->key_l_arrow = 0;
	p_info->key_r_arrow = 0;
	p_info->key_esc = 0;
}
