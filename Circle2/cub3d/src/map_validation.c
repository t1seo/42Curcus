/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 11:23:11 by tseo              #+#    #+#             */
/*   Updated: 2021/01/17 16:33:33 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	g_dirx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
static int	g_diry[8] = {0, 1, 0, -1, -1, 1, 1, -1};

int			check_player_direction(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int			check_testmap(char **test_map, int x, int y)
{
	int i;

	if (test_map[y][x] == '1' || test_map[y][x] == 'x')
		return (1);
	if (test_map[y][x] == ' ' || test_map[y][x] == '#')
		return (0);
	test_map[y][x] = 'x';

	i = -1;
	while (++i < 8)
		if (check_testmap(test_map, x + g_dirx[i], y + g_diry[i]) == 0)
			return (0);
	return (1);
}

// TODO : 타일이 유효한 문자인지 점검
int			check_tile(char c)
{
	return (c == '0' || c == '1' || c == '2'
			|| c == ' ' || c == 0 || c == 2
			|| check_player_direction(c));
}

// test_map free 해주는 함수
void			free_testmap(char **test_map, int map_height)
{
	while (map_height + 3 >= 0)
	{
		free(test_map[map_height]);
		map_height--;
	}
	free(test_map);
}

char		**make_test_map(t_map_info *map_info)
{
	int		x;
	int		y;
	char	**test_map;

	// 테두리 공간을 확보하기 위해 가로, 세로가 2씩 큰 맵을 생성
	if (!(test_map = (char **)malloc(sizeof(char *) * (map_info->map_height + 3))))
		return (0);

	test_map[map_info->map_height + 2] = 0;
	y = -1;
	while (++y < map_info->map_height + 2)
	{
		if (!(test_map[y] = (char *)malloc(sizeof(char) * (map_info->map_width + 3))))
			return (0);
		test_map[y][map_info->map_width + 2] = 0;
		x = -1;
		while (++x < map_info->map_width + 2)
			test_map[y][x] = '#'; // test_map 전체를 공백으로 채운다
	}

	// 테두리는 공백으로 남겨두고, (1, 1)부터 map의 데이터를 test_map에 복사
	y = -1;
	while (++y < map_info->map_height)
	{
		x = -1;
		while (map_info->world_map[y][++x])
			test_map[y + 1][x + 1] = map_info->world_map[y][x];
	}


	return (test_map);
}



int			check_player(t_map_info *map_info)
{
	int i;
	int j;
	int check;

	i = 0;
	check = 0;
	while (i < map_info->map_height)
	{
		j = 0;
		while (j < map_info->map_width)
		{
			// if (check_tile(map_info->world_map[i][j]) == 0)
			// {
			// 	printf("%d %d - %c\n", i, j, map_info->world_map[i][j]);
			// 	printf("Error : Invalid tile in map.\n");
			// 	return (0);
			// }
			if (check == 0 && check_player_direction(map_info->world_map[i][j]))
			{
				check = 1;
				map_info->player_pos_x = j;
				map_info->player_pos_y = i;
				map_info->player_direction = map_info->world_map[i][j];
			}
			else if (check == 1 && check_player_direction(map_info->world_map[i][j]))
			{
				printf("Error : Player Position Error.\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void		check_map_validation(t_map_info *map_info)
{
	char	**test_map;
	// int		is_zero;

	if (check_player(map_info) == 0)
		exit(0);
	if ((test_map = make_test_map(map_info)) == 0)
	{
		printf("Error : Map Test Failed.\n");
		exit(0);
	}

	// if (check_testmap(test_map, map_info->player_pos_x, map_info->player_pos_y) == 0)
	// {
	// 	printf("Error : Map error.\n");
	// }
	// else
	// {
	// 	printf("MAP OK.\n");
	// }
	// int is_zero = 0;
	int y;
	int x;
		y = -1;
	while (test_map[++y])
	{
		x = -1;
		while (test_map[y][++x])
		{
			if (test_map[y][x] == '0')
			{
				// is_zero = 1;
				if (check_testmap(test_map, x, y) == 0)
				{
					printf("Error : Map is not valid\n");
					exit(0);
					// return (0);
				}
			}
		}
	}
	// if (is_zero == 0)
	// 	printf("ERROR\n");
	// else
	// 	printf("OK\n");


	// printf("Real Map\n");
	// for (int i = 0; map_info->world_map[i]; i++)
	// {
	// 	printf("%s\n", map_info->world_map[i]);
	// }

	// free_testmap(test_map, map_info->map_height);


	// TODO : memory free test_map
	int len = 0;
	while (test_map[len])
		len++;
	printf("%d\n", len);
	for (int i = 0; i < len; i++)
		free(test_map[i]);
	free(test_map);
}
