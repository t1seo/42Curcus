/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 19:08:22 by tseo              #+#    #+#             */
/*   Updated: 2021/01/22 11:10:24 by tseo             ###   ########.fr       */
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

void	setup_direction_vectors(t_player_info *p_info,
	double plane_x, double plane_y, double dir_x, double dir_y)
{
		p_info->plane_x = plane_x;
		p_info->plane_y = plane_y;
		p_info->dir_x = dir_x;
		p_info->dir_y = dir_y;
}

void	setup_player_direction(t_player_info *p_info, t_map_info *map_info)
{
	if (map_info->player_direction == 'W')
		setup_direction_vectors(p_info, 0, 0.66, -1, 0);
	else if (map_info->player_direction == 'E')
		setup_direction_vectors(p_info, 0, 0.66, 1, 0);
	else if (map_info->player_direction == 'N')
		setup_direction_vectors(p_info, 0.66, 0, 0, 1);
	else if (map_info->player_direction == 'S')
		setup_direction_vectors(p_info, 0.66, 0, 0, -1);
}

void	setup_screen_map_config(t_map_info *map_info)
{
	g_map_width = map_info->map_width;
	g_map_height = map_info->map_height;
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
		if(!(p_info->buf[i] = (int *)malloc(sizeof(int) * SCREEN_WIDTH)))
		{
			printf("Error : Memory Allocation Failed.\n");
			exit(0);
		}

	// TODO : bzero 사용하기
	i = -1;
	while (++i < SCREEN_HEIGHT)
	{
		j = -1;
		while (++j < SCREEN_WIDTH)
			p_info->buf[i][j] = 0;
	}
	// for (int i = 0; i < SCREEN_HEIGHT; i++)
	// {
	// 	for (int j = 0; j < SCREEN_WIDTH; j++)
	// 		printf("%d", p_info->buf[i][j]);
	// 	printf("\n");
	// }
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
		if (!(p_info->texture[i] = (int *)malloc(sizeof(int) * (TEX_HEIGHT) * (TEX_WIDTH))))
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
	setup_screen_map_config(map_info);
	setup_player_keys(p_info);
	init_buf(p_info);
	init_texture(p_info);
	p_info->move_speed = 0.05;
	p_info->rot_speed = 0.05;
}

