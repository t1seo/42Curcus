/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 01:53:10 by tseo              #+#    #+#             */
/*   Updated: 2021/01/19 21:11:34 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	setup_wall_casting(t_player_info *p_info, t_wall_casting_info *w_info, int x)
{
	w_info->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	w_info->ray_dir_x = p_info->dir_x + p_info->plane_x * w_info->camera_x;
	w_info->ray_dir_y = p_info->dir_y + p_info->plane_y * w_info->camera_x;
	w_info->map_x = (int)p_info->pos_x;
	w_info->map_y = (int)p_info->pos_y;
	w_info->delta_dist_x = fabs(1 / w_info->ray_dir_x);
	w_info->delta_dist_y = fabs(1 / w_info->ray_dir_y);
	w_info->hit = 0;
	// printf("SETUP WALL CASTING\n");
}

void	calc_step_and_sidedist(t_player_info *p_info, t_wall_casting_info *w_info)
{
	if (w_info->ray_dir_x < 0)
	{
		w_info->step_x = -1;
		w_info->side_dist_x = (p_info->pos_x - w_info->map_x) * w_info->delta_dist_x;
	}
	else
	{
		w_info->step_x = 1;
		w_info->side_dist_x = (w_info->map_x + 1.0 - p_info->pos_x) * w_info->delta_dist_x;
	}
	if (w_info->ray_dir_y < 0)
	{
		w_info->step_y = -1;
		w_info->side_dist_y = (p_info->pos_y - w_info->map_y) * w_info->delta_dist_y;
	}
	else
	{
		w_info->step_y = 1;
		w_info->side_dist_y = (w_info->map_y + 1.0 - p_info->pos_y) * w_info->delta_dist_y;
	}
	// printf("CALC STEP AND SIDEDIST\n");
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
		if (g_world_map[w_info->map_x][w_info->map_y] > 0)
			w_info->hit = 1;
	}
	// printf("PERFORM DDA\n");
}

void	calc_perp_wall_dist(t_player_info *p_info, t_wall_casting_info *w_info)
{
	if (w_info->side == 0)
		w_info->perp_wall_dist = (w_info->map_x - p_info->pos_x + (1 - w_info->step_x) / 2) / w_info->ray_dir_x;
	else
		w_info->perp_wall_dist = (w_info->map_y - p_info->pos_y + (1 - w_info->step_y) / 2) / w_info->ray_dir_y;
	// printf("CALC PERP WALL DIST\n");
}

void	calc_draw_position(t_wall_casting_info *w_info)
{
	w_info->line_height = (int)(SCREEN_HEIGHT / w_info->perp_wall_dist);
	w_info->draw_start = -(w_info->line_height) / 2 + SCREEN_HEIGHT / 2;
	if (w_info->draw_start < 0)
		w_info->draw_start  = 0;
	w_info->draw_end = w_info->line_height / 2 + SCREEN_HEIGHT / 2;
	if (w_info->draw_end >= SCREEN_HEIGHT)
		w_info->draw_end = SCREEN_HEIGHT - 1;
	// printf("CALC DRAW POSITION\n");
}

void	calc_wall_x(t_player_info *p_info, t_wall_casting_info *w_info)
{
	if (w_info->side == 0)
		w_info->wall_x = p_info->pos_y + w_info->perp_wall_dist * w_info->ray_dir_y;
	else
		w_info->wall_x = p_info->pos_x + w_info->perp_wall_dist * w_info->ray_dir_x;
	w_info->wall_x -= floor((w_info->wall_x));
	// printf("CALC WALL_X\n");
}

void	calc_wall_texture(t_wall_casting_info *w_info)
{
	// w_info->tex_num = g_world_map[w_info->map_x][w_info->map_y] - 1;
	w_info->tex_x = (int)(w_info->wall_x * (double)TEX_WIDTH);
	if (w_info->side == 0 && w_info->ray_dir_x > 0)
		w_info->tex_x = TEX_WIDTH - w_info->tex_x - 1;
	if (w_info->side == 1 && w_info->ray_dir_y < 0)
		w_info->tex_x = TEX_WIDTH - w_info->tex_x - 1;
	w_info->step = 1.0 * TEX_HEIGHT / w_info->line_height;
	w_info->tex_pos = (w_info->draw_start - SCREEN_HEIGHT / 2 +w_info->line_height / 2) * w_info->step;
	// printf("CALC WALL TEXTURE\n");
}

void	allocate_texture_in_buf(t_player_info *p_info, t_wall_casting_info *w_info, int x)
{
	int y;
	int tex_y;
	int color;

	y = w_info->draw_start;
	while (y < w_info->draw_end)
	{
		tex_y = (int)w_info->tex_pos & (TEX_HEIGHT - 1);
		w_info->tex_pos += w_info->step;
		// color = p_info->texture[w_info->tex_num][TEX_HEIGHT * tex_y + w_info->tex_x];
		if (w_info->side == 1 && w_info->ray_dir_y > 0)
			// color = (color >> 1) & 8355711;
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
	// printf("ALLOCATE TEXTURE IN BUF\n");
}

void	wall_casting(t_player_info *p_info)
{
	int x;
	t_wall_casting_info w_info;

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
		// p_info->z_buffer[x] = w_info.perp_wall_dist;
	}
}
