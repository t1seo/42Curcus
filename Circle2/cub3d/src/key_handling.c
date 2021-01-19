/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 23:51:43 by tseo              #+#    #+#             */
/*   Updated: 2021/01/19 11:35:15 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		press_key(int key, t_player_info *p_info)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		p_info->key_w = 1;
	else if (key == KEY_A)
		p_info->key_a = 1;
	else if (key == KEY_S)
		p_info->key_s = 1;
	else if (key == KEY_D)
	{

		printf("Preesed D\n");
		p_info->key_d = 1;
	}
	else if (key == KEY_LA)
		p_info->key_l_arrow = 1;
	else if (key == KEY_RA)
		p_info->key_r_arrow = 1;
	return (0);
}

int		release_key(int key, t_player_info *p_info)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_W)
		p_info->key_w = 0;
	else if (key == KEY_A)
		p_info->key_a = 0;
	else if (key == KEY_S)
		p_info->key_s = 0;
	else if (key == KEY_D)
	{

		printf("Released D\n");
		p_info->key_d = 0;
	}
	else if (key == KEY_LA)
		p_info->key_l_arrow = 0;
	else if (key == KEY_RA)
		p_info->key_r_arrow = 0;
	return (0);
}

void	move_player(t_player_info *p_info, t_map_info *map_info)
{
	if (p_info->key_a || p_info->key_l_arrow)
	{
		printf("ROT LEFT\n");
		rot_left(p_info, map_info);
	}
	if (p_info->key_d || p_info->key_r_arrow)
	{
		printf("ROT RIGHT\n");
		rot_right(p_info, map_info);
	}
	if (p_info->key_w)
	{
		printf("MOVE FORWARD\n");
		move_forward(p_info, map_info);
	}
	if (p_info->key_s)
	{
		printf("MOVE BACKWWARD\n");
		move_backward(p_info, map_info);
	}
	if (p_info->key_esc)
		exit(0);
}
