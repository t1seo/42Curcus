/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:29:16 by tseo              #+#    #+#             */
/*   Updated: 2021/01/11 14:14:07 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"
#include "../mlx/mlx.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_RELEASE 3
#define X_EVENT_KEY_EXIT	17

#define TEX_WIDTH	64
#define TEX_HEIGHT	64

#define KEY_A 0
#define KEY_D 2
#define KEY_S 1
#define KEY_W 13
#define KEY_LA 123
#define KEY_RA 124
#define KEY_ESC 53

// extern int map_width;
// extern int map_height;
// extern int screen_width;
// extern int screen_height;

#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


typedef struct	s_img
{
	void		*img;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			img_width;
	int			img_height;
}				t_img;

typedef struct	s_info
{
	double		player_pos_x;
	double		player_pos_y;
	double		dir_vec_x;
	double		dir_vec_y;
	double		plane_x;
	double		plane_y;
	void		*mlx;
	void		*win;
	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_esc;
	int			key_l_arrow;
	int			key_r_arrow;
	t_img		img;
	// should be memory allocated
	int			**buf;
	double		*z_buffer;
	int			**textures;
	double		move_speed;
	double		rot_speed;
}				t_info;


#endif
