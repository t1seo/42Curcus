/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:44:56 by tseo              #+#    #+#             */
/*   Updated: 2021/01/25 22:09:05 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int				*g_sprite_order;
double			*g_sprite_distance;

static int		compare(const void *first, const void *second)
{
	if (*(int *)first > *(int *)second)
		return (1);
	else if (*(int *)first < *(int *)second)
		return (-1);
	else
		return (0);
}

void			sort_order(t_pair *orders, int num_of_sprites)
{
	t_pair	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < num_of_sprites)
	{
		j = -1;
		while (++j < num_of_sprites - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp = orders[j];
				orders[j] = orders[j + 1];
				orders[j + 1] = tmp;
			}
		}
	}
}

void			sort_sprites(int *order, double *dist, int num_of_sprites)
{
	t_pair	*sprites;
	int		i;

	if (!(sprites = (t_pair *)malloc(sizeof(t_pair) * num_of_sprites)))
	{
		printf("Error : Memory Allocation Failed.\n");
		exit(0);
	}
	i = -1;
	while (++i < num_of_sprites)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
	}
	sort_order(sprites, num_of_sprites);
	i = -1;
	while (++i < num_of_sprites)
	{
		dist[i] = sprites[num_of_sprites - i - 1].first;
		order[i] = sprites[num_of_sprites - i - 1].second;
	}
	free(sprites);
}

void			calc_sprite_distance(t_player_info *p_info)
{
	int i;

	i = 0;
	while (i < NUM_OF_SPRITES)
	{
		g_sprite_order[i] = i;
		g_sprite_distance[i] = ((p_info->pos_x - g_sprite[i].x)
		* (p_info->pos_x - g_sprite[i].x)
		+ (p_info->pos_y - g_sprite[i].y) * (p_info->pos_y - g_sprite[i].y));
		i++;
	}
}

/*
** loop through every vertical stripe of the sprite on screen
**
**	the conditions in the if are:
**	1) it's in front of camera plane so you don't see things behind you
**	2) it's on the screen (left)
**	3) it's on the screen (right)
**	4) ZBuffer, with perpendicular distance
*/
void			allocate_sprite_texture_in_buf(t_player_info *p_info, t_sprite_info *s_info, int i)
{
	int stripe;
	int color;
	int d;
	int y;

	stripe = s_info->draw_start_x - 1;
	while (++stripe < s_info->draw_end_x)
	{
		s_info->tex_x = (int)((256 * (stripe - (-s_info->sprite_width / 2 + s_info->sprite_screen_x)) * TEX_WIDTH / s_info->sprite_width) / 256);
		if (s_info->transform_y > 0 && stripe > 0 && stripe < SCREEN_WIDTH && s_info->transform_y < p_info->z_buffer[stripe])
		{
			y = s_info->draw_start_y;
			while (y < s_info->draw_end_y)
			{
				d = (y) * 256 - SCREEN_HEIGHT * 128 + s_info->sprite_height * 128;
				s_info->tex_y = ((d * TEX_HEIGHT) / s_info->sprite_height) / 256;
				color = p_info->texture[g_sprite[g_sprite_order[i]].texture][TEX_WIDTH * s_info->tex_y + s_info->tex_x];
				if ((color & 0x00FFFFFF) != 0)
					p_info->buf[y][stripe] = color;
				y++;
			}
		}
	}
}

void			sprite_casting(t_player_info *p_info)
{
	int				i;
	t_sprite_info	s_info;

	if (!(g_sprite_order = (int *)malloc(sizeof(int) * (NUM_OF_SPRITES))))
	{
		printf("Error : Memory Allocation Failed.\n");
		exit(0);
	}
	if (!(g_sprite_distance = (double *)malloc(sizeof(double) * (NUM_OF_SPRITES))))
	{
		printf("Error : Memory Allocation Failed.\n");
		exit(0);
	}
	calc_sprite_distance(p_info);
	sort_sprites(g_sprite_order, g_sprite_distance, NUM_OF_SPRITES);
	i = -1;
	while (++i < NUM_OF_SPRITES)
	{
		calc_relative_position(p_info, &s_info, i);
		calc_depth_inside_screen(p_info, &s_info);
		calc_center_pos_of_sprite(&s_info);
		calc_sprite_size(&s_info);
		calc_draw_pos_of_sprite(&s_info);
		allocate_sprite_texture_in_buf(p_info, &s_info, i);
	}
}
