/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 20:31:15 by tseo              #+#    #+#             */
/*   Updated: 2020/12/31 22:06:22 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	world_map[MAP_WIDTH][MAP_HEIGHT] =
						{
							{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
							{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
							{4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
							{4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
							{4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
							{4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
							{4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
							{4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
							{4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
							{4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
							{4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
							{6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
							{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
							{6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
							{4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
							{4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
							{4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
							{4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
							{4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
						};


// 버퍼를 이용하여 한 번에 화면 출력
void	draw(t_info *info)
{
	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			info->img.data[y * SCREEN_WIDTH + x] = info->buf[y][x];
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	calc(t_info *info)
{
	// 바닥과 천장을 칠해준다.
    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
        for (int y = 0; y < SCREEN_HEIGHT; y++)
        {
            info->buf[y][x] = 0xFFFFFF; // 하얀색
            info->buf[SCREEN_HEIGHT - y - 1][x] = 0x000000; // 검정색
            // buf[screenHeight - 1 ~ screenHeight - screenHeight][x] 를 칠해줌.
        }
    }
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		// cameraX는 for문의 x값이 카메라 평면 상에 있을 때의 x좌표
		double camera_x = 2 * x / (double)SCREEN_WIDTH - 1;

		// 광선의 방향은 방향벡터 + 카메라 평면 * 베수
		t_dvec ray_dir;
		ray_dir = create_dvec(info->dir_vec.x + info->plane_vec.x * camera_x,
		info->dir_vec.y + info->plane_vec.y * camera_x);

		// DDA Algorithm
		// 현재 플레이어가 위차한 맵 내 위치
		t_ivec map_pos;
		map_pos = create_ivec((int)info->player_pos.x, (int)info->player_pos.y);

		// 현재 위치에서 다음 x 사이드 또는 y 사이드까지의 거리
		t_dvec side_dist;

		// 첫 번째 x, y면에서 그 다음 x, y면까지의 광선의 이동거리
		t_dvec delta_dist;
		delta_dist = create_dvec(fabs(1 / ray_dir.x), fabs(1 / ray_dir.y));

		// 어안효과 방지를 위한 수직 거리 계산
		double perp_wall_dist;

		// 반복문이 실행 될 때마다 x, y방향으로 한 칸씩 점프하는데
		// 어느 방향으로 점프할지 +1, -1
		t_ivec step;

		int hit = 0; // 벽에 부딪혔는지
		int side; // x면에 부딪힌거라면 side=0, y면에 부딪힌거라면 1이된다.

		// DDA 알고리즘 시작전에 step과 sideDist에 값을 넣어준다
		if (ray_dir.x < 0)
		{
			step.x = -1;
			side_dist.x = (info->player_pos.x - map_pos.x) * delta_dist.x;
		}
		else
		{
			step.y = 1;
			side_dist.x = (map_pos.x + 1.0 - info->player_pos.x) * delta_dist.x;
		}
		if (ray_dir.y < 0)
		{
			step.y = -1;
			side_dist.y = (info->player_pos.y - map_pos.y) * delta_dist.y;
		}
		else
		{
			step.y = 1;
			side_dist.y = (map_pos.y + 1.0 - info->player_pos.y) * delta_dist.y;
		}

		// DDA 알고리즘 세팅 끝

		// DDA 알고리즘 시작
		// while문은 벽에 부딪힐 때까지 매번 한 칸씩 광선 이동한다
		// 광선이 점프할 때마다 side_dist에 delta_dist가 더해지면서 업데이트 된다.
		while (hit == 0)
		{
			if (side_dist.x < side_dist.y)
			{
				side_dist.x += delta_dist.x;
				map_pos.x += step.x; // stepX는 1, -1 중 하나
				side = 0; // x 면에 부딪혔다면 side = 0
			}
			else
			{
				side_dist.y += delta_dist.y;
				map_pos.y += step.y;
				side = 1;
			}
			// 광선이 벽에 맞았는지 체크
			if (world_map[map_pos.x][map_pos.y] > 0) hit = 1;
		}

		// 어안효과 방지를 위한 수직 거리 계산
		if (side == 0)
			perp_wall_dist = (map_pos.x - info->player_pos.x + (1 - step.x) / 2) / ray_dir.x;
		else
			perp_wall_dist = (map_pos.y - info->player_pos.y + (1 - step.y) / 2) / ray_dir.y;

		// 스크린에 그릴 line의 높이를 계산
		int line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);

		// 선의 시작지점과 끝 지점을 계산
		int draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
		if(draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
		if(draw_end >= SCREEN_HEIGHT)
			draw_end = SCREEN_HEIGHT - 1;

		// texturing calculations
		// 1을 빼주는 이유는 0번째 텍스쳐도 0, 벽이 없어도 0이기 때문
		int tex_num = world_map[map_pos.x][map_pos.y];

		// calculate value of wallX
		// wallX의 값은 벽의 x면과 부딪힌 경우 (side == 0) 벽의 y좌표가 된다
		// wallX의 값은 텍스처의 x좌표에 대해서만 사용한다.
		double wall_x;
		if (side == 0)
			wall_x = info->player_pos.y + perp_wall_dist * ray_dir.y;
		else
			wall_x = info->player_pos.x + perp_wall_dist * ray_dir.x;
		wall_x -= floor(wall_x);

		// x coordinate on the texture
		// texX는 texture의 x좌표를 나타낸다.
		int tex_x = (int)(wall_x * (double)TEX_WIDTH);
		if (side == 0 && ray_dir.x > 0)
			tex_x = TEX_WIDTH - tex_x - 1;
		if (side == 1 && ray_dir.y  < 0)
			tex_x = TEX_WIDTH - tex_x - 1;

		// texY를 지정하는 반복문
		// step은 스크린 픽셀당 texture 좌표를 얼마나 증가시켜줄 건지를 결정
		// buffer[y][x]에 넣을 color는 texture 배열에서 가져온다
		// How much to increase the texture coordinate perscreen pixel
		double pixel_per_texture = 1.0 * TEX_HEIGHT / line_height;
		// Starting texture coordinate
		double tex_pos = (draw_start - SCREEN_HEIGHT / 2 + line_height / 2) * pixel_per_texture;
		for (int y = draw_start; y < draw_end; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)tex_pos & (TEX_HEIGHT - 1);
			tex_pos += pixel_per_texture;
			int color = info->texture[tex_num][TEX_HEIGHT * texY + tex_x];

			// y면은 더 어둡게
			// color를 2로 나누고 835811을 AND 연산하여 더 어둡게 표현
			if (side == 1)
				color = (color >> 1) & 8355711;
			info->buf[y][x] = color;
		}
		x++;
	}
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}

int	key_press(int key, t_info *info)
{
	if (key == KEY_W)
	{
		if (!world_map[(int)(info->player_pos.x + info->dir_vec.x * info->move_speed)][(int)(info->player_pos.y)])
			info->player_pos.x += info->dir_vec.x * info->move_speed;
		if (!world_map[(int)(info->player_pos.x)][(int)(info->player_pos.x + info->dir_vec.y * info->move_speed)])
			info->player_pos.y += info->dir_vec.y * info->move_speed;
	}
	//move backwards if no wall behind you
	if (key == KEY_S)
	{
		if (!world_map[(int)(info->player_pos.x - info->dir_vec.x * info->move_speed)][(int)(info->player_pos.y)])
			info->player_pos.x -= info->dir_vec.x * info->move_speed;
		if (!world_map[(int)(info->player_pos.x)][(int)(info->player_pos.y - info->dir_vec.y * info->move_speed)])
			info->player_pos.y -= info->dir_vec.y * info->move_speed;
	}
	//rotate to the right
	if (key == KEY_D)
	{
		//both camera direction and camera plane must be rotated
		double old_dir_vec = info->dir_vec.x;
		info->dir_vec.x = info->dir_vec.x * cos(-info->rot_speed) - info->dir_vec.y * sin(-info->rot_speed);
		info->dir_vec.y = old_dir_vec * sin(-info->rot_speed) + info->dir_vec.y * cos(-info->rot_speed);
		double old_plane_vec = info->plane_vec.x;
		info->plane_vec.x = info->plane_vec.x * cos(-info->rot_speed) - info->plane_vec.y * sin(-info->rot_speed);
		info->plane_vec.y = old_plane_vec * sin(-info->rot_speed) + info->plane_vec.y * cos(-info->rot_speed);
	}
	//rotate to the left
	if (key == KEY_A)
	{
		//both camera direction and camera plane must be rotated
		double old_dir_vec = info->dir_vec.x;
		info->dir_vec.x = info->dir_vec.x * cos(info->rot_speed) - info->dir_vec.y * sin(info->rot_speed);
		info->dir_vec.y = old_dir_vec * sin(info->rot_speed) + info->dir_vec.y * cos(info->rot_speed);
		double old_plane_vec = info->plane_vec.x;
		info->plane_vec.x = info->plane_vec.x * cos(info->rot_speed) - info->plane_vec.y * sin(info->rot_speed);
		info->plane_vec.y = old_plane_vec * sin(info->rot_speed) + info->plane_vec.y * cos(info->rot_speed);
	}
	if (key == KEY_ESC)
		exit(0);
	return (0);
}

// mlx_xpm_file_to_image를 이용하여 이미지 로드
void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], "textures/eagle.xpm", &img);
	load_image(info, info->texture[1], "textures/redbrick.xpm", &img);
	load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
	load_image(info, info->texture[3], "textures/greystone.xpm", &img);
	load_image(info, info->texture[4], "textures/bluestone.xpm", &img);
	load_image(info, info->texture[5], "textures/mossy.xpm", &img);
	load_image(info, info->texture[6], "textures/wood.xpm", &img);
	load_image(info, info->texture[7], "textures/colorstone.xpm", &img);
}

int	main(void)
{
	t_info info;
	info.mlx = mlx_init();

	info.player_pos.x = 22.0;
	info.player_pos.y = 11.5;
	info.dir_vec.x = -1.0;
	info.dir_vec.y = 0.0;
	info.plane_vec.x = 0.0;
	info.plane_vec.y = 0.66;

	// 버퍼를 초기화 해준다.
	// 버퍼는 우리가 띄운 창의 크기와 같다.
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		for (int j = 0; j < SCREEN_WIDTH; j++)
		{
			info.buf[i][j] = 0;
		}
	}

	// texture 하당하고 초기화
	if (!(info.texture = (int **)malloc(sizeof(int *) * 8)))
		return (-1);
	for (int i = 0; i < 8; i++)
	{
		if (!(info.texture[i] = (int *)malloc(sizeof(int) * (TEX_HEIGHT * TEX_WIDTH))))
			return (-1);
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < TEX_HEIGHT * TEX_WIDTH; j++)
		{
			info.texture[i][j] = 0;
		}
	}

	load_texture(&info);

	info.move_speed = 0.05;
	info.rot_speed = 0.05;

	// 이미지 생성하고 주소 저장
	info.win = mlx_new_window(info.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "mlx");
	info.img.img = mlx_new_image(info.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);

	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);

	mlx_loop(info.mlx);
}
