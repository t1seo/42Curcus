/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:40:33 by tseo              #+#    #+#             */
/*   Updated: 2021/01/14 00:14:17 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		check_all_information(t_map_info *map_info)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (map_info->info_check[i] == 0)
			return (0);
		i++;
	}
	return (1);
}
