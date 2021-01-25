/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saving_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:11:22 by tseo              #+#    #+#             */
/*   Updated: 2021/01/25 19:54:44 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void		int_to_char(int n, unsigned char *src)
{
	src[0] = (unsigned char)(n);
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

static void		write_bmp_header(int fd, int file_size)
{
	unsigned char bmp_header[54];

	ft_bzero(bmp_header, 54);
	bmp_header[0] = (unsigned char)('B');
	bmp_header[1] = (unsigned char)('M');
	int_to_char(file_size, bmp_header + 2);
	bmp_header[10] = (unsigned char)(54);
	bmp_header[14] = (unsigned char)(40);
	int_to_char(SCREEN_WIDTH, bmp_header + 18);
	int_to_char(SCREEN_HEIGHT, bmp_header + 22);
	bmp_header[26] = (unsigned char)(1);
	bmp_header[28] = (unsigned char)(32);
	write(fd, bmp_header, 54);
}

void		write_bmp_pixel_data(t_player_info *p_info, int fd)
{
	int y = SCREEN_HEIGHT - 1;
	while (y >= 0)
	{
		int x = 0;
		while (x < SCREEN_WIDTH)
			write(fd, &(p_info->img.data[(y * SCREEN_WIDTH) + x++]), 4);
		y--;
	}
}

void	save_bmp(t_player_info *p_info)
{
	int			fd;
	t_bmp_info	b_info;
	// update(p_info);
	// draw(p_info);

	int pad = (4 - (SCREEN_WIDTH * 3) % 4) % 4;
	int file_size = 54 + (SCREEN_WIDTH * SCREEN_HEIGHT) * 4;
	ft_bzero(&b_info, sizeof(b_info));
	if (!(fd = open("screenshot.bmp", O_WRONLY | O_CREAT
	| O_TRUNC | O_APPEND, 0666)))
	{
		printf("Error : cannot open bmp.\n");
		exit(0);
	}
	write_bmp_header(fd, file_size);
	// int y = SCREEN_HEIGHT - 1;
	// while (y >= 0)
	// {
	// 	int x = 0;
	// 	while (x < SCREEN_WIDTH)
	// 		write(fd, &(p_info->img.data[(y * SCREEN_WIDTH) + x++]), 4);
	// 	y--;
	// }
	write_bmp_pixel_data(p_info, fd);
	close(fd);
}
