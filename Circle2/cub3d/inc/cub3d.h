/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:29:16 by tseo              #+#    #+#             */
/*   Updated: 2021/01/25 22:02:31 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"
#include "../mlx_beta/mlx_beta.h"
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


#define NUM_OF_TEXTURES 5

#define KEY_A 0
#define KEY_D 2
#define KEY_S 1
#define KEY_W 13
#define KEY_LA 123
#define KEY_RA 124
#define KEY_ESC 53


//parameters for scaling and moving the sprites
#define uDiv 1
#define vDiv 1

extern int g_map_width;
extern int g_map_height;
extern int g_screen_width;
extern int g_screen_height;
extern int g_tex_width;
extern int g_tex_height;
extern int g_num_of_sprites;
extern int g_floor_color;
extern int g_ceil_color;
extern int **g_world_map;

#define MAP_WIDTH g_map_width
#define MAP_HEIGHT g_map_height
#define SCREEN_WIDTH g_screen_width
#define SCREEN_HEIGHT g_screen_height
#define TEX_WIDTH g_tex_width
#define TEX_HEIGHT g_tex_height
#define FLOOR_COLOR g_floor_color;
#define CEIL_COLOR g_ceil_color;
#define NUM_OF_SPRITES g_num_of_sprites

#define U_DIV 1
#define V_DIV 1
#define V_MOVE 0.0

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

typedef struct	s_window
{
	void	*ptr;
	void	*win;
	t_img	img;
	int		size_x;
	int		size_y;
}				t_window;


typedef struct	s_player_info
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
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
	int			**texture;
	int			**world_map;
	double		move_speed;
	double		rot_speed;
}				t_player_info;

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
	int			player_pos_x;
	int			player_pos_y;
	char		player_direction;
	char		**world_map;

}				t_map_info;

typedef struct	s_wall_casting_info
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_num;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
}				t_wall_casting_info;

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			texture;
}				t_sprite;

typedef struct	s_sprite_info
{
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screen_x;
	int			v_move_screen;
	int			sprite_height;
	int			draw_start_y;
	int			draw_end_y;
	int			sprite_width;
	int			draw_start_x;
	int			draw_end_x;
	int			tex_x;
	int			tex_y;
}				t_sprite_info;

typedef struct	s_pair
{
	double		first;
	int			second;
}				t_pair;


extern t_sprite *g_sprite;
extern int		*g_sprite_order;
extern double	*g_sprite_distance;

/*
** main.c
*/
void	update(t_player_info *p_info);



int			get_next_line(int fd, char **line);
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
** parsing_map.c
*/
void			parse_map_info(t_map_info *map_info);
void				parse_detailed_map_info(char *detailed_info, t_map_info *map_info, int fd);

/*
** parsing_map_util_1.c
*/
int		check_all_information(t_map_info *map_info);
int		parse_resolution_x_y(char *detailed_info, t_map_info *map_info);
void	reset_map_info(t_map_info *map_info);
void	parse_line(t_map_info *map_info, int fd);

/*
** parsing_map_util_2.c
*/
void	skip_space(char *line, int *i);
void	get_map_line(t_map_info *map_info, int *height, char *line);
/*
** debugging_util.c
*/
void	print_map_info(t_map_info *map_info);

/*
** map_validation.c
*/
void		check_map_validation(t_map_info *map_info);

/*
** map_validation_util.c
*/
int			check_player_direction(char c);
void		copy_world_map(t_map_info *map_info, char **test_map);

/*
** check_arguments.c
*/
int		check_cub_file(char *str);
int		check_save_arg(char *str);

/*
** initial_setting.c
*/
void	setup_player_info(t_player_info *p_info, t_map_info *map_info);

/*
** initial_setting_util.c
*/
void	setup_direction_vectors(t_player_info *p_info, int i);
void	setup_player_direction(t_player_info *p_info, t_map_info *map_info);
void	setup_screen_map_config(t_player_info *p_info, t_map_info *map_info);
void	setup_player_keys(t_player_info *p_info);

/*
** key_handling.c
*/
int		press_key(int key, t_player_info *p_info);
int		release_key(int key, t_player_info *p_info);
void	move_player(t_player_info *p_info, t_map_info *map_info);

/*
** player_moving.c
*/
void	move_forward(t_player_info *p_info, t_map_info *map_info);
void	move_backward(t_player_info *p_info, t_map_info *map_info);
void	rot_left(t_player_info *p_info, t_map_info *map_info);
void	rot_right(t_player_info *p_info, t_map_info *map_info);

/*
** loading_image.c
*/
void	load_texture(t_player_info *p_info, t_map_info *map_info);

/*
** drawing.c
*/
void	draw(t_player_info *p_info);
void	draw_floor_ceil(t_player_info *p_info);

/*
** wall_casting.c
*/
void	wall_casting(t_player_info *p_info);

/*
** wall_casting_calc.c
*/
void	calc_step_and_sidedist(t_player_info *p_info,
								t_wall_casting_info *w_info);
void	calc_perp_wall_dist(t_player_info *p_info, t_wall_casting_info *w_info);
void	calc_draw_position(t_wall_casting_info *w_info);
void	calc_wall_x(t_player_info *p_info, t_wall_casting_info *w_info);
void	calc_wall_texture(t_wall_casting_info *w_info);

/*
** making_map.c
*/
void	make_world_map(t_player_info *p_info, t_map_info *map_info);

/*
**  making_map_util.c
*/
int		check_map_tile(char tile);
int		check_invalid_map_tile(char tile);
void	fill_global_map_with_one(void);
void	make_global_map(t_map_info *map_info);

/*
** sprite_casting.c
*/
void	sprite_casting(t_player_info *p_info);

/*
** sprite_casting_calc.c
*/
void	calc_relative_position(t_player_info *p_info, t_sprite_info *s_info, int i);
void	calc_depth_inside_screen(t_player_info *p_info, t_sprite_info *s_info);
void	calc_center_pos_of_sprite(t_sprite_info *s_info);
void	calc_sprite_size(t_sprite_info *s_info);
void	calc_draw_pos_of_sprite(t_sprite_info *s_info);

/*
**  saving_bmp.c
*/
void	save_bmp(t_player_info *p_info);

/*
** error_util.c
*/
void	print_error_and_exit(char *error_msg);
void	print_parsing_error(char *error_msg, int fd);

#endif
