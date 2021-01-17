/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:40:20 by tseo              #+#    #+#             */
/*   Updated: 2021/01/16 03:19:30 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		convert_rgb_color(int r, int g, int b)
{
	int color;

	color = 0;
	color |= (r << 16);
	color |= (g << 8);
	color |= b;
	return (color);
}

int		check_color_info(char *detailed_info)
{
	int i;

	i = 1;
	while (detailed_info[i])
	{
		if (!(detailed_info[i] == ',' || detailed_info[i] == ' '
		|| ft_isdigit(detailed_info[i])))
			return (0);
		i++;
	}
	return (1);
}

int		check_valid_color_range(int r, int g, int b)
{
	if (!(0 <= r && r <= 255))
		return (0);
	if (!(0 <= g && g <= 255))
		return (0);
	if (!(0 <= b && b <= 255))
		return (0);
	return (1);
}

void	free_colors(char **colors, int len)
{
	int i;

	i = 0;
	while (i < len + 1)
	{
		free(colors[i]);
		i++;
	}
	free(colors);

}

int		parse_color(char *detailed_info, t_map_info *map_info)
{
	char **colors;
	int len;
	int r;
	int g;
	int b;

	if (!check_color_info(detailed_info))
		return (0);

	colors = ft_charset_split(&detailed_info[1], ", ");
	len = 0;
	while (colors[len])
		len++;
	if (len != 3)
		return (0);
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (!check_valid_color_range(r, g, b))
		return (0);
	if (detailed_info[0] == 'F')
	{
		map_info->info_check[6] = 1;
		map_info->floor_color = convert_rgb_color(r, g, b);
	}
	if (detailed_info[0] == 'C')
	{
		map_info->info_check[7] = 1;
		map_info->ceil_color = convert_rgb_color(r, g, b);
	}
	free_colors(colors, len);
	return (1);
}
