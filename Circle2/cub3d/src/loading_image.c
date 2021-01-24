/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 01:18:32 by tseo              #+#    #+#             */
/*   Updated: 2021/01/20 19:52:11 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	load_image(t_player_info *p_info, int *texture, char *path, t_img *img)
{
	int y;
	int x;
	// TODO : 이미지 없을 때 예외처리
	img->img = mlx_xpm_file_to_image(p_info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	y = -1;
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(p_info->mlx, img->img);
}

void	load_texture(t_player_info *p_info, t_map_info *map_info)
{
	t_img img;

	load_image(p_info, p_info->texture[0], map_info->n_wall_texture_path, &img);
	load_image(p_info, p_info->texture[1], map_info->s_wall_texture_path, &img);
	load_image(p_info, p_info->texture[2], map_info->e_wall_texture_path, &img);
	load_image(p_info, p_info->texture[3], map_info->w_wall_texture_path, &img);
	load_image(p_info, p_info->texture[4], map_info->sprite_texture_path, &img);
}
