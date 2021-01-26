/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting_calc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:49:07 by tseo              #+#    #+#             */
/*   Updated: 2021/01/26 21:46:16 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
** 	translate sprite position to relative to camera
*/

void	calc_relative_position(t_player_info *p_info,
							t_sprite_info *s_info, int i)
{
	s_info->sprite_x = g_sprite[g_sprite_order[i]].x - p_info->pos_x;
	s_info->sprite_y = g_sprite[g_sprite_order[i]].y - p_info->pos_y;
}

/*
** inv_det : required for correct matrix multiplication
** transform : this is actually the depth inside the screen,
** that what Z is in 3D, the distance of sprite to player,
** matching sqrt(spriteDistance[i])
*/

void	calc_depth_inside_screen(t_player_info *p_info,
								t_sprite_info *s_info)
{
	s_info->inv_det = 1.0 / (p_info->plane_x * p_info->dir_y
					- p_info->dir_x * p_info->plane_y);
	s_info->transform_x = s_info->inv_det * (p_info->dir_y
				* s_info->sprite_x - p_info->dir_x * s_info->sprite_y);
	s_info->transform_y = s_info->inv_det * (-p_info->plane_y
				* s_info->sprite_x + p_info->plane_x * s_info->sprite_y);
}

void	calc_center_pos_of_sprite(t_sprite_info *s_info)
{
	s_info->sprite_screen_x = (int)((SCREEN_WIDTH / 2)
			* (1 + s_info->transform_x / s_info->transform_y));
}

/*
** calculate height and width of sprite on screen
** using "transformY" instead of the real distance prevents fisheye
*/

void	calc_sprite_size(t_sprite_info *s_info)
{
	s_info->sprite_height = (int)fabs((SCREEN_HEIGHT
							/ s_info->transform_y) / V_DIV);
	s_info->sprite_width = (int)fabs((SCREEN_HEIGHT
							/ s_info->transform_y) / U_DIV);
}

/*
** calculate lowest and highest pixel to fill in current stripe
*/

void	calc_draw_pos_of_sprite(t_sprite_info *s_info)
{
	s_info->draw_start_y = -s_info->sprite_height / 2 + SCREEN_HEIGHT / 2;
	if (s_info->draw_start_y < 0)
		s_info->draw_start_y = 0;
	s_info->draw_end_y = s_info->sprite_height / 2 + SCREEN_HEIGHT / 2;
	if (s_info->draw_end_y >= SCREEN_HEIGHT)
		s_info->draw_end_y = SCREEN_HEIGHT - 1;
	s_info->draw_start_x = -s_info->sprite_width / 2 + s_info->sprite_screen_x;
	if (s_info->draw_start_x < 0)
		s_info->draw_start_x = 0;
	s_info->draw_end_x = s_info->sprite_width / 2 + s_info->sprite_screen_x;
	if (s_info->draw_end_x >= SCREEN_WIDTH)
		s_info->draw_end_x = SCREEN_WIDTH - 1;
}
