/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 01:53:10 by tseo              #+#    #+#             */
/*   Updated: 2021/01/25 20:59:34 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	setup_wall_casting(t_player_info *p_info,
							t_wall_casting_info *w_info, int x)
{
	w_info->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	w_info->ray_dir_x = p_info->dir_x + p_info->plane_x * w_info->camera_x;
	w_info->ray_dir_y = p_info->dir_y + p_info->plane_y * w_info->camera_x;
	w_info->map_x = (int)p_info->pos_x;
	w_info->map_y = (int)p_info->pos_y;
	w_info->delta_dist_x = fabs(1 / w_info->ray_dir_x);
	w_info->delta_dist_y = fabs(1 / w_info->ray_dir_y);
	w_info->hit = 0;
}

void	perform_dda(t_wall_casting_info *w_info)
{
	while (w_info->hit == 0)
	{
		if (w_info->side_dist_x < w_info->side_dist_y)
		{
			w_info->side_dist_x += w_info->delta_dist_x;
			w_info->map_x += w_info->step_x;
			w_info->side = 0;
		}
		else
		{
			w_info->side_dist_y += w_info->delta_dist_y;
			w_info->map_y += w_info->step_y;
			w_info->side = 1;
		}
		if (g_world_map[w_info->map_x][w_info->map_y] == 1)
			w_info->hit = 1;
	}
}

void	allocate_texture_in_buf(t_player_info *p_info,
						t_wall_casting_info *w_info, int x)
{
	int y;
	int tex_y;
	int color;

	y = w_info->draw_start;
	while (y < w_info->draw_end)
	{
		tex_y = (int)w_info->tex_pos & (TEX_HEIGHT - 1);
		w_info->tex_pos += w_info->step;
		if (w_info->side == 1 && w_info->ray_dir_y > 0)
			color = p_info->texture[0][TEX_HEIGHT * tex_y + w_info->tex_x];
		else if (w_info->side == 1 && w_info->ray_dir_y < 0)
			color = p_info->texture[1][TEX_HEIGHT * tex_y + w_info->tex_x];
		else if (w_info->side == 0 && w_info->ray_dir_x > 0)
			color = p_info->texture[2][TEX_HEIGHT * tex_y + w_info->tex_x];
		else if (w_info->side == 0 && w_info->ray_dir_x < 0)
			color = p_info->texture[3][TEX_HEIGHT * tex_y + w_info->tex_x];
		p_info->buf[y][x] = color;
		y++;
	}
}

void	wall_casting(t_player_info *p_info)
{
	int					x;
	t_wall_casting_info	w_info;

	if (!(p_info->z_buffer = (double *)malloc(sizeof(double) * SCREEN_WIDTH)))
	{
		printf("Error : Memory Allocation Failed.\n");
		exit(0);
	}
	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		setup_wall_casting(p_info, &w_info, x);
		calc_step_and_sidedist(p_info, &w_info);
		perform_dda(&w_info);
		calc_perp_wall_dist(p_info, &w_info);
		calc_draw_position(&w_info);
		calc_wall_x(p_info, &w_info);
		calc_wall_texture(&w_info);
		allocate_texture_in_buf(p_info, &w_info, x);
		p_info->z_buffer[x] = w_info.perp_wall_dist;
	}
}
