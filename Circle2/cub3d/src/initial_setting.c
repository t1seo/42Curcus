/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 19:08:22 by tseo              #+#    #+#             */
/*   Updated: 2021/01/25 19:14:06 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int g_map_width;
int g_map_height;
int g_screen_width;
int g_screen_height;
int g_floor_color;
int g_ceil_color;
int g_tex_width;
int g_tex_height;

void	init_buf(t_player_info *p_info)
{
	int i;
	int j;

	if (!(p_info->buf = (int **)malloc(sizeof(int *) * SCREEN_HEIGHT)))
	{
		printf("Error : Memory Allocation Failed.\n");
		exit(0);
	}
	i = -1;
	while (++i < SCREEN_HEIGHT)
		if (!(p_info->buf[i] = (int *)malloc(sizeof(int) * SCREEN_WIDTH)))
		{
			printf("Error : Memory Allocation Failed.\n");
			exit(0);
		}
	i = -1;
	while (++i < SCREEN_HEIGHT)
	{
		j = -1;
		while (++j < SCREEN_WIDTH)
			p_info->buf[i][j] = 0;
	}
}

void	init_texture(t_player_info *p_info)
{
	int i;
	int j;

	if (!(p_info->texture = (int **)malloc(sizeof(int *) * NUM_OF_TEXTURES)))
	{
		printf("Error : Memory Allocation Failed.\n");
		exit(0);
	}
	i = -1;
	while (++i < NUM_OF_TEXTURES)
	{
		if (!(p_info->texture[i] = (int *)malloc(sizeof(int)
					* (TEX_HEIGHT) * (TEX_WIDTH))))
		{
			printf("Error : Memory Allocation Failed.\n");
			exit(0);
		}
	}
	i = -1;
	while (++i < NUM_OF_TEXTURES)
	{
		j = -1;
		while (++j < TEX_HEIGHT * TEX_WIDTH)
			p_info->texture[i][j] = 0;
	}
}

void	setup_player_info(t_player_info *p_info, t_map_info *map_info)
{
	p_info->pos_x = (double)map_info->player_pos_x;
	p_info->pos_y = (double)map_info->player_pos_y;
	setup_player_direction(p_info, map_info);
	setup_screen_map_config(p_info, map_info);
	setup_player_keys(p_info);
	init_buf(p_info);
	init_texture(p_info);
	p_info->move_speed = 0.05;
	p_info->rot_speed = 0.05;
}
