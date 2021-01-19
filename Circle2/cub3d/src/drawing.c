/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 01:44:37 by tseo              #+#    #+#             */
/*   Updated: 2021/01/19 01:49:58 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw(t_player_info *p_info)
{
	int y;
	int x;

	y = -1;
	while (++y < SCREEN_HEIGHT)
	{
		x = -1;
		while (++x < SCREEN_WIDTH)
		{
			p_info->img.data[y * SCREEN_WIDTH + x] = p_info->buf[y][x];
		}
	}
	mlx_put_image_to_window(p_info->mlx, p_info->win, p_info->img.img, 0, 0);
}

void	draw_floor_ceil(t_player_info *p_info)
{
	int x;
	int y;

	x = -1;
	while (++x < SCREEN_WIDTH)
	{
		y = -1;
		while (++y < SCREEN_HEIGHT)
		{
			p_info->buf[y][x] = FLOOR_COLOR;
			p_info->buf[SCREEN_HEIGHT - y - 1][x] = CEIL_COLOR;
		}
	}
}
