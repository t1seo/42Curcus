/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moving.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:02:18 by tseo              #+#    #+#             */
/*   Updated: 2021/01/26 21:17:56 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	move_forward(t_player_info *p_info, t_map_info *map_info)
{
	printf("Current : %d %d\n", (int)p_info->pos_x, (int)p_info->pos_y);
	if (!g_world_map[(int)(p_info->pos_x + p_info->dir_x
		* p_info->move_speed)][(int)(p_info->pos_y)])
		p_info->pos_x += (p_info->dir_x * p_info->move_speed);
	if (!g_world_map[(int)(p_info->pos_x)][(int)(p_info->pos_y
		+ p_info->dir_y * p_info->move_speed)])
		p_info->pos_y += p_info->dir_y * p_info->move_speed;
}

void	move_backward(t_player_info *p_info, t_map_info *map_info)
{
	printf("Current : %d %d\n", (int)p_info->pos_x, (int)p_info->pos_y);
	if (!g_world_map[(int)(p_info->pos_x - p_info->dir_x
			* p_info->move_speed)][(int)(p_info->pos_y)])
		p_info->pos_x -= p_info->dir_x * p_info->move_speed;
	if (!g_world_map[(int)(p_info->pos_x)]
			[(int)(p_info->pos_y - p_info->dir_y * p_info->move_speed)])
		p_info->pos_y -= p_info->dir_y * p_info->move_speed;
}

void	rot_right(t_player_info *p_info, t_map_info *map_info)
{
	double olddir_x;
	double oldplane_x;

	olddir_x = p_info->dir_x;
	p_info->dir_x = p_info->dir_x * cos(-p_info->rot_speed)
				- p_info->dir_y * sin(-p_info->rot_speed);
	p_info->dir_y = olddir_x * sin(-p_info->rot_speed)
				+ p_info->dir_y * cos(-p_info->rot_speed);
	oldplane_x = p_info->plane_x;
	p_info->plane_x = p_info->plane_x * cos(-p_info->rot_speed)
				- p_info->plane_y * sin(-p_info->rot_speed);
	p_info->plane_y = oldplane_x * sin(-p_info->rot_speed)
				+ p_info->plane_y * cos(-p_info->rot_speed);
}

void	rot_left(t_player_info *p_info, t_map_info *map_info)
{
	double oldplane_x;
	double olddir_x;

	olddir_x = p_info->dir_x;
	p_info->dir_x = p_info->dir_x * cos(p_info->rot_speed)
		- p_info->dir_y * sin(p_info->rot_speed);
	p_info->dir_y = olddir_x * sin(p_info->rot_speed)
		+ p_info->dir_y * cos(p_info->rot_speed);
	oldplane_x = p_info->plane_x;
	p_info->plane_x = p_info->plane_x * cos(p_info->rot_speed)
		- p_info->plane_y * sin(p_info->rot_speed);
	p_info->plane_y = oldplane_x * sin(p_info->rot_speed)
		+ p_info->plane_y * cos(p_info->rot_speed);
}
