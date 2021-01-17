/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 23:45:42 by tseo              #+#    #+#             */
/*   Updated: 2021/01/17 14:49:35 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// int		main(int ac, char **av)
// {
// 	char *line = 0;
// 	int ret;
// 	int fd;

// 	fd = open("map.cub", O_RDONLY);
// 	while ((ret = get_next_line(fd, &line)) > 0)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// 	printf("%s\n", line);
// 	free(line);
// 	return (0);
// }



int		check_cub_file(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i])
		i++;
	ptr = &str[i - 3];
	if (str[i - 4] == '.' && !ft_strncmp(ptr, "cub", 3))
		return (1);
	else
	{
		printf("Error : Wrong File\n");
		return (0);
	}
}

int		check_save_arg(char *str)
{
	if ((ft_strlen(str) == 6) && ft_strncmp(str, "--save", 6) == 0)
		return (1);
	else
	{
		printf("Error : Wrong Option\n");
		return (0);
	}
}

void	init_cub3d(char *map_file)
{
	t_map_info *map_info;

	map_info->map_file_name = ft_strdup(map_file);

	parse_map_info(map_info);
	check_map_validation(map_info);
	// print_map_info(map_info);
	// if (!parse_map_info(map_info))
	// 	exit(0);
}

int		main(int ac, char **av)
{
	if (ac == 3 && check_cub_file(av[1]) && check_save_arg(av[2]))
		printf("Cub File, Save Option Checked\n");
	else if (ac == 2 && check_cub_file(av[1]))
		init_cub3d(av[1]);
	else if (ac == 1 || ac > 3)
		printf("Error : Wrong Argument\n");
	return (0);
}
