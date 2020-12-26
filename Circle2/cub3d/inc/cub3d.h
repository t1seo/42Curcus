/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 19:56:09 by tseo              #+#    #+#             */
/*   Updated: 2020/12/26 21:58:24 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "keys.h"
#include "vector.h"
#include "../mlx/mlx.h"
#include "../libft/libft.h"

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_EXIT	17

#define	MAP_WIDTH 24
#define MAP_HEIGHT 24

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef struct		s_player
{
	t_vec	pos;
	t_vec	dir;
	t_vec	plane;
	double	move_speed;
	double	rot_speed;
}					t_player;









#endif
