/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:44:56 by tseo              #+#    #+#             */
/*   Updated: 2021/01/26 21:31:26 by tseo             ###   ########.fr       */
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

void			sprite_casting(t_player_info *p_info)
{
	int				i;
	t_sprite_info	s_info;

	if (!(g_sprite_order = (int *)malloc(sizeof(int) * (NUM_OF_SPRITES))))
		print_error_and_exit("Memory Allocation Failed");
	if (!(g_sprite_distance = (double *)malloc(sizeof(double)
							* (NUM_OF_SPRITES))))
		print_error_and_exit("Memory Allocation Failed");
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
