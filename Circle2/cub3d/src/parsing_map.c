/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:33:10 by tseo              #+#    #+#             */
/*   Updated: 2021/01/17 13:36:31 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	reset_map_info(t_map_info *map_info)
{
	int i;

	i = -1;
	while (++i < 8)
		map_info->info_check[i] = 0;
	map_info->screen_width = 0;
	map_info->screen_height = 0;
	map_info->n_wall_texture_path = 0;
	map_info->s_wall_texture_path = 0;
	map_info->w_wall_texture_path = 0;
	map_info->e_wall_texture_path = 0;
	map_info->sprite_texture_path = 0;
	map_info->floor_color = 0;
	map_info->ceil_color = 0;
	map_info->map_width = 0;
	map_info->map_height = 0;
	map_info->world_map = 0;
	map_info->player_pos_x = 0;
	map_info->player_pos_y = 0;
	map_info->player_direction = 0;
}

int		parse_resolution(char *detailed_info, t_map_info *map_info)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (detailed_info[i])
	{
		if (flag == 0 && ft_isdigit(detailed_info[i]))
		{
			map_info->screen_width = ft_atoi(&detailed_info[i]);
			while (ft_isdigit(detailed_info[i]))
				i++;
			flag = 1;
		}
		else if (flag == 1 && ft_isdigit(detailed_info[i]))
		{
			map_info->screen_height = ft_atoi(&detailed_info[i]);
			break;
		}
		i++;
	}
	if (map_info->screen_width && map_info->screen_height && map_info->info_check[0] == 0)
	{
		map_info->info_check[0] = 1;
		return (1);
	}
	else
		return (0);
}

int		parse_detailed_map_info(char *detailed_info, t_map_info *map_info)
{
	if (detailed_info[0] == 'R')
		return (parse_resolution(detailed_info, map_info));
	else if (detailed_info[0] == 'N' && detailed_info[1] == 'O')
		return (parse_no_texture_path(detailed_info, map_info));
	else if (detailed_info[0] == 'S' && detailed_info[1] == 'O')
		return (parse_so_texture_path(detailed_info, map_info));
	else if (detailed_info[0] == 'W' && detailed_info[1] == 'E')
		return (parse_we_texture_path(detailed_info, map_info));
	else if (detailed_info[0] == 'E' && detailed_info[1] == 'A')
		return (parse_ea_texture_path(detailed_info, map_info));
	else if (detailed_info[0] == 'S')
		return (parse_s_texture_path(detailed_info, map_info));
	else if (detailed_info[0] == 'F' || detailed_info[0] == 'C')
		return (parse_color(detailed_info, map_info));
	else
		return (0);
}


void		parse_map_info(t_map_info *map_info)
{
	char 	*line;
	int		ret;
	int		fd;
	int		flag;
	int		i;
	int		height;

	flag = 0;
	height = 0;
	if (((fd = open(map_info->map_file_name, O_RDONLY)) == -1))
	{
		printf("Error : Failed to open a file %s: %s\n", map_info->map_file_name, strerror(errno));
		close(fd);
		exit(0);
	}
	reset_map_info(map_info); // 맵 정보 초기화
	get_map_size(map_info); // 맵 사이즈 읽기
	// 맵 저장할 공간 동적 할당
	if (!(map_info->world_map = (char **)malloc(sizeof(char *) * map_info->map_height + 1)))
	{
		printf("Error : Memory Allocation Failed.\n");
		close(fd);
	}
	map_info->world_map[map_info->map_height] = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		i = 0;
		while ((9 <= line[i] && line[i] <= 13) || line[i] == ' ')
			i++;
		if (flag == 0 && ft_isalpha(line[i]))
		{
				if (!parse_detailed_map_info(&line[i], map_info))
				{
					printf("Error : Wrong Map Specifier\n");
					close(fd);
					exit(0);
				}
				if (check_all_information(map_info) == 1)
					flag = 1;

		}
		else if (flag == 0 && ft_isdigit(line[i]))
		{
			printf("Error : Lack of Map Information\n");
			close(fd);
			exit(0);
		}
		else if (flag == 1 && ft_isdigit(line[i]))
		{
			map_info->world_map[height] = ft_strdup(line);
			// printf("%s\n", map_info->world_map[height]);
			height++;
		}
		// printf("%s\n", line);
		free(line);
	}
	while ((9 <= line[i] && line[i] <= 13) || line[i] == ' ')
			i++;
	if (flag == 1 && ft_isdigit(line[i]))
	{
		map_info->world_map[height] = ft_strdup(line);
		height++;
	}
	// TODO: map 마지막에 NULL 넣어주기
	// printf("%s\n", line);
	free(line);
	close(fd);
}
