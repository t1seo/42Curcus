/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:33:10 by tseo              #+#    #+#             */
/*   Updated: 2021/01/25 14:12:54 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int			parse_resolution(char *detailed_info, t_map_info *map_info)
{
	parse_resolution_x_y(detailed_info, map_info);
	if (map_info->screen_width && map_info->screen_height
							&& map_info->info_check[0] == 0)
	{
		map_info->info_check[0] = 1;
		return (1);
	}
	else
		return (0);
}

void		parse_detailed_map_info(char *detailed_info,
								t_map_info *map_info, int fd)
{
	int ret;

	ret = 0;
	if (detailed_info[0] == 'R')
		ret = (parse_resolution(detailed_info, map_info));
	else if (detailed_info[0] == 'N' && detailed_info[1] == 'O')
		ret = (parse_no_texture_path(detailed_info, map_info));
	else if (detailed_info[0] == 'S' && detailed_info[1] == 'O')
		ret = (parse_so_texture_path(detailed_info, map_info));
	else if (detailed_info[0] == 'W' && detailed_info[1] == 'E')
		ret = (parse_we_texture_path(detailed_info, map_info));
	else if (detailed_info[0] == 'E' && detailed_info[1] == 'A')
		ret = (parse_ea_texture_path(detailed_info, map_info));
	else if (detailed_info[0] == 'S')
		ret = (parse_s_texture_path(detailed_info, map_info));
	else if (detailed_info[0] == 'F' || detailed_info[0] == 'C')
		ret = (parse_color(detailed_info, map_info));
	else
		print_parsing_error("Wrong Map Specifier", fd);
	if (ret == 0)
		print_parsing_error("Detailed Map Info", fd);
}

void		parse_map_info(t_map_info *map_info)
{
	int		fd;
	int		i;

	if (((fd = open(map_info->map_file_name, O_RDONLY)) == -1))
	{
		printf("Error : Failed to open a file %s: %s\n",
				map_info->map_file_name, strerror(errno));
		close(fd);
		exit(0);
	}
	reset_map_info(map_info);
	get_map_size(map_info);
	if (!(map_info->world_map = (char **)malloc(sizeof(char *)
								* map_info->map_height + 1)))
	{
		printf("Error : Memory Allocation Failed.\n");
		close(fd);
		exit(0);
	}
	map_info->world_map[map_info->map_height] = 0;
	parse_line(map_info, fd);
	close(fd);
}
