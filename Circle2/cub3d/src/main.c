/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 23:45:42 by tseo              #+#    #+#             */
/*   Updated: 2021/01/18 13:52:54 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_cub3d(char *map_file)
{
	t_map_info *map_info;

	map_info->map_file_name = ft_strdup(map_file);

	parse_map_info(map_info);
	check_map_validation(map_info);
	print_map_info(map_info);
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
