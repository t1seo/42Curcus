/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:38:11 by tseo              #+#    #+#             */
/*   Updated: 2021/01/18 13:38:32 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
		printf("Error : Wrong File Format\n");
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
