/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:25:32 by tseo              #+#    #+#             */
/*   Updated: 2021/01/26 21:41:04 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
** loop through every vertical stripe of the sprite on screen
**
**	the conditions in the if are:
**	1) it's in front of camera plane so you don't see things behind you
**	2) it's on the screen (left)
**	3) it's on the screen (right)
**	4) ZBuffer, with perpendicular distance
*/

int				calc_d(t_sprite_info *s_info, int y)
{
	int d;

	d = (y) * 256 - SCREEN_HEIGHT * 128
		+ s_info->sprite_height * 128;
	return (d);
}

int				calc_tex_x(t_sprite_info *s_info, int stripe)
{
	int ret;

	ret = (int)((256 * (stripe - (-s_info->sprite_width
					/ 2 + s_info->sprite_screen_x)) * TEX_WIDTH
					/ s_info->sprite_width) / 256);
	return (ret);
}

int				calc_tex_y(t_sprite_info *s_info, int d)
{
	int ret;

	ret = ((d * TEX_HEIGHT)
		/ s_info->sprite_height) / 256;
	return (ret);
}

int				get_sprite_color(t_player_info *p_info,
								t_sprite_info *s_info, int i)
{
	int color;

	color = p_info->texture[g_sprite[g_sprite_order[i]].texture]
				[TEX_WIDTH * s_info->tex_y + s_info->tex_x];
	return (color);
}

void			allocate_sprite_texture_in_buf(t_player_info *p_info,
										t_sprite_info *s_info, int i)
{
	int stripe;
	int color;
	int d;
	int y;

	stripe = s_info->draw_start_x - 1;
	while (++stripe < s_info->draw_end_x)
	{
		s_info->tex_x = calc_tex_x(s_info, stripe);
		if (s_info->transform_y > 0 && stripe > 0
				&& stripe < SCREEN_WIDTH
				&& s_info->transform_y < p_info->z_buffer[stripe])
		{
			y = s_info->draw_start_y;
			while (y < s_info->draw_end_y)
			{
				d = calc_d(s_info, y);
				s_info->tex_y = calc_tex_y(s_info, d);
				color = get_sprite_color(p_info, s_info, i);
				if ((color & 0x00FFFFFF) != 0)
					p_info->buf[y][stripe] = color;
				y++;
			}
		}
	}
}
