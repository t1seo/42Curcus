/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:29:16 by tseo              #+#    #+#             */
/*   Updated: 2021/01/16 00:39:58 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"
#include "../mlx/mlx.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

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

#define MAX_FD 1024
#define GNL_BUFFER_SIZE 25


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

/*
** info_check index
** 0: R - resolution
** 1: NO - n_wall_texture_path
** 2: SO - s_wall_texture_path
** 3: WE - w_wall_texture_path
** 4: EA - e_wall_texture_path
** 5: S - sprite_texture_path
** 6: F - floor_color
** 7: C - ceil_color
*/

typedef	struct	s_map_info
{
	// 맵이 맨 뒤에 있어야 하므로 다른 정보들이 모두 있는지 체크하기 위한 배열
	char		*map_file_name;
	int			info_check[8];
	int			screen_width; // 0
	int			screen_height; // 0
	char		*n_wall_texture_path; // 1
	char		*s_wall_texture_path; // 2
	char		*w_wall_texture_path; // 3
	char		*e_wall_texture_path; // 4
	char		*sprite_texture_path; // 5
	int			floor_color; // 6
	int			ceil_color; // 7
	int			map_width;
	int			map_height;
	char		**world_map;

}				t_map_info;


int			get_next_line(int fd, char **line);
int			parse_map_info(t_map_info *map_info);
int			get_map_size(t_map_info *map_info);

void	print_map_info(t_map_info *map_info); // to be deleted it is for testing

int		parse_no_texture_path(char *detailed_info, t_map_info *map_info);
int		parse_so_texture_path(char *detailed_info, t_map_info *map_info);
int		parse_we_texture_path(char *detailed_info, t_map_info *map_info);
int		parse_ea_texture_path(char *detailed_info, t_map_info *map_info);
int		parse_s_texture_path(char *detailed_info, t_map_info *map_info);

int		parse_color(char *detailed_info, t_map_info *map_info);

/*
** charset_split.c
*/
char	**ft_charset_split(char *str, char *charset);

/*
** parsing_util.c
*/
int		check_all_information(t_map_info *map_info);

#endif
