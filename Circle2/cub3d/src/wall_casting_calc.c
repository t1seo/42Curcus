/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting_calc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:54:38 by tseo              #+#    #+#             */
/*   Updated: 2021/01/26 21:42:05 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	calc_step_and_sidedist(t_player_info *p_info,
								t_wall_casting_info *w_info)
{
	if (w_info->ray_dir_x < 0)
	{
		w_info->step_x = -1;
		w_info->side_dist_x = (p_info->pos_x - w_info->map_x)
								* w_info->delta_dist_x;
	}
	else
	{
		w_info->step_x = 1;
		w_info->side_dist_x = (w_info->map_x + 1.0 - p_info->pos_x)
								* w_info->delta_dist_x;
	}
	if (w_info->ray_dir_y < 0)
	{
		w_info->step_y = -1;
		w_info->side_dist_y = (p_info->pos_y - w_info->map_y)
								* w_info->delta_dist_y;
	}
	else
	{
		w_info->step_y = 1;
		w_info->side_dist_y = (w_info->map_y + 1.0 - p_info->pos_y)
								* w_info->delta_dist_y;
	}
}

void	calc_perp_wall_dist(t_player_info *p_info, t_wall_casting_info *w_info)
{
	if (w_info->side == 0)
		w_info->perp_wall_dist = (w_info->map_x - p_info->pos_x
				+ (1 - w_info->step_x) / 2) / w_info->ray_dir_x;
	else
		w_info->perp_wall_dist = (w_info->map_y - p_info->pos_y
				+ (1 - w_info->step_y) / 2) / w_info->ray_dir_y;
}

void	calc_draw_position(t_wall_casting_info *w_info)
{
	w_info->line_height = (int)(SCREEN_HEIGHT / w_info->perp_wall_dist);
	w_info->draw_start = -(w_info->line_height) / 2 + SCREEN_HEIGHT / 2;
	if (w_info->draw_start < 0)
		w_info->draw_start = 0;
	w_info->draw_end = w_info->line_height / 2 + SCREEN_HEIGHT / 2;
	if (w_info->draw_end >= SCREEN_HEIGHT)
		w_info->draw_end = SCREEN_HEIGHT - 1;
}

void	calc_wall_x(t_player_info *p_info, t_wall_casting_info *w_info)
{
	if (w_info->side == 0)
		w_info->wall_x = p_info->pos_y + w_info->perp_wall_dist
						* w_info->ray_dir_y;
	else
		w_info->wall_x = p_info->pos_x + w_info->perp_wall_dist
						* w_info->ray_dir_x;
	w_info->wall_x -= floor((w_info->wall_x));
}

void	calc_wall_texture(t_wall_casting_info *w_info)
{
	w_info->tex_x = (int)(w_info->wall_x * (double)TEX_WIDTH);
	if (w_info->side == 0 && w_info->ray_dir_x > 0)
		w_info->tex_x = TEX_WIDTH - w_info->tex_x - 1;
	if (w_info->side == 1 && w_info->ray_dir_y < 0)
		w_info->tex_x = TEX_WIDTH - w_info->tex_x - 1;
	w_info->step = 1.0 * TEX_HEIGHT / w_info->line_height;
	w_info->tex_pos = (w_info->draw_start - SCREEN_HEIGHT / 2
					+ w_info->line_height / 2) * w_info->step;
}
