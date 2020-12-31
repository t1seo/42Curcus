/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 19:58:16 by tseo              #+#    #+#             */
/*   Updated: 2020/12/31 21:12:19 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include "vector.h"
#include <stdlib.h>

/*
** Keys of Mac OS
*/
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_AR_L 123
#define KEY_AR_R 124
#define KEY_ESC 53

#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_EXIT 17
#define	TEX_WIDTH 64
#define	TEX_HEIGHT 64
#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

/*
** The structure with variables to be used in get_img_data_addr().
*/
typedef struct		s_img
{
	void			*img;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				img_width;
	int				img_height;
}					t_img;

typedef struct		s_info
{
	t_dvec			player_pos;
	t_dvec			dir_vec;
	t_dvec			plane_vec;
	void			*mlx;
	void			*win;
	double			move_speed;
	double			rot_speed;
	t_img			img;
	int				buf[SCREEN_HEIGHT][SCREEN_WIDTH];
	int				**texture;
}					t_info;






#endif
