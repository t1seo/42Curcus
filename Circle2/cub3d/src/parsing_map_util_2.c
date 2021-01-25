/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_util_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:21:23 by tseo              #+#    #+#             */
/*   Updated: 2021/01/25 14:03:01 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	skip_space(char *line, int *i)
{
	while ((9 <= line[*i] && line[*i] <= 13) || line[*i] == ' ')
		*i++;
}

void	get_map_line(t_map_info *map_info, int *height, char *line)
{
	map_info->world_map[*height] = ft_strdup(line);
	printf("HELLO\n");
	*height++;
	printf("WORLD\n");
}
