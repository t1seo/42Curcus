/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measuring_map_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 21:54:18 by tseo              #+#    #+#             */
/*   Updated: 2021/01/26 16:29:23 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void		calc_map_size(char *line, int *map_height, int *map_width)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while ((9 <= line[i] && line[i] <= 13) || line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]))
	{
		*map_height += 1;
		len = ft_strlen(line);
		if (len > *map_width)
			*map_width = len;
	}
}

int			get_map_size(t_map_info *map_info)
{
	int		fd;
	int		ret;
	int		map_width;
	int		map_height;
	char	*line;

	map_width = 0;
	map_height = 0;
	if (((fd = open(map_info->map_file_name, O_RDONLY)) == -1))
	{
		printf("Error opening file %s: %s\n",
				map_info->map_file_name, strerror(errno));
		close(fd);
		exit(0);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		calc_map_size(line, &map_height, &map_width);
		free(line);
	}
	calc_map_size(line, &map_height, &map_width);
	map_info->map_height = map_height;
	map_info->map_width = map_width;
	free(line);
	return (1);
}
