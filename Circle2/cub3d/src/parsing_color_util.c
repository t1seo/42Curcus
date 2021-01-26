/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:32:34 by tseo              #+#    #+#             */
/*   Updated: 2021/01/26 21:42:49 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int			convert_rgb_color(int r, int g, int b)
{
	int color;

	color = 0;
	color |= (r << 16);
	color |= (g << 8);
	color |= b;
	return (color);
}

void		free_colors(char **colors, int len)
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
