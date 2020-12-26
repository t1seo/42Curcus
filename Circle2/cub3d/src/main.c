/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:47:26 by tseo              #+#    #+#             */
/*   Updated: 2020/12/27 00:02:24 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include <stdio.h>

int	world_map[24][24] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						};

// draw the pixiels of the stripe as a vertical line
void	ver_line(void *mlx, void *win, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(mlx, win, x, y, color);
		y++;
	}
}

void	calc(t_player *p_info)
{
	int x;

	x = 0;

	while (x < SCREEN_WIDTH)
	{
		double	camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		t_vec	ray_dir = vec_new(p_info->dir.x + p_info->plane.x * camera_x,
		p_info->dir.y + p_info->plane.y * camera_x);

		t_int_vec map = int_vet_new((int)p_info->pos.x, (int)p_info->pos.y);

		// length of ray from current position to next x or y-side
		t_vec	side_dist;

		// length of ray from one x or y-side to next x or y-side
		t_vec delta_dist = vec_new(fabs(1 / ray_dir.x), fabs(1 / ray_dir.y));
		double perp_wall_dist;

		// what direction to step in x or y-direction (either +1 or -1)
		t_int_vec step;

		int hit = 0; // was there a wall hit?
		int side; // was a NS or a EW wall hit?

		if (ray_dir.x < 0)
		{
			step.x = -1;
			side_dist.x = (p_info->pos.x - map.x) * delta_dist.x;
		}
		else
		{
			step.x = 1;
			side_dist.x = (map.x + 1.0 - p_info->pos.x) * delta_dist.x;
		}
		if (ray_dir.y < 0)
		{
			step.y = -1;
			side_dist.y = (map.y + 1.0 - p_info->pos.y) * delta_dist.y;
		}
		else
		{
			step.y = 1;
			side_dist.y = (map.y + 1.0 - p_info->pos.y) * delta_dist.y;
		}


	}
}


int		key_pressed(int key, t_player *p_info)
{
	// move forwards if there is no wall
	if (key == KEY_W)
	{
		if (!world_map[(int)(p_info->pos.x + p_info->dir.x * p_info->move_speed)]
						[(int)(p_info->pos.y)])
			p_info->pos.x += p_info->dir.x * p_info->move_speed;
		if (!world_map[(int)(p_info->pos.x)]
						[(int)(p_info->pos.y + p_info->dir.y * p_info->move_speed)])
			p_info->pos.y += p_info->dir.y * p_info->move_speed;
	}
	// move backwards
	if (key == KEY_S)
	{
		if (!world_map[(int)(p_info->pos.x - p_info->dir.x * p_info->move_speed)]
						[(int)(p_info->pos.y)])
			p_info->pos.x -= p_info->dir.x * p_info->move_speed;
		if (!world_map[(int)(p_info->pos.x)]
						[(int)(p_info->pos.y - p_info->dir.y * p_info->move_speed)])
			p_info->pos.y -= p_info->dir.y * p_info->move_speed;
	}

	// rotate to the right
	if (key == KEY_D || key == KEY_RIGHT_ARROW)
	{
		p_info->dir = vec_rotation(p_info->dir, -(p_info->rot_speed));
		p_info->plane = vec_rotation(p_info->dir, -(p_info->rot_speed));
	}

	if (key == KEY_A || key == KEY_LEFT_ARROW)
	{
		p_info->dir = vec_rotation(p_info->dir, p_info->rot_speed);
		p_info->plane = vec_rotation(p_info->dir, p_info->rot_speed);
	}

	if (key == KEY_ESC)
		exit(0);
	return (0);
}

void	player_setup(t_player *p_info)
{
	p_info->pos.x = 12;
	p_info->pos.y = 5;
	p_info->dir.x = -1;
	p_info->dir.y = 0;
	p_info->plane.x = 0;
	p_info->plane.y = 0.66;
	p_info->move_speed = 0.05;
	p_info->rot_speed = 0.05;
}

void	setup(t_player *p_info)
{
	// TODO : initialize all objects
	player_setup(p_info);

}

void	update(void)
{
	// TODO : update all game objects before we render the next frame
}

int		draw(void)
{
	update();
	// TODO : render all objects frame by frame
	return (0);
}

int		main(void)
{
	t_player	p_info;
	void		*mlx; // screen connection identifier
	void		*win; // window indentifier

	mlx = mlx_init();
	win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");

	setup(&p_info);
	mlx_loop_hook(mlx, &draw, &p_info);
	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_pressed, &p_info);
	mlx_loop(mlx);
}
