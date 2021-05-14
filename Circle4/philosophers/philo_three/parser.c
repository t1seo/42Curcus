/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:49:13 by tseo              #+#    #+#             */
/*   Updated: 2021/05/14 19:22:04 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		parse_argv(t_info *info, char **argv)
{
	int i;

	info->num_of_must_eat = -1;
	i = 1;
	while (argv[i])
	{
		if (!(is_num(argv[i])))
			return (0);
		if (i == 1 && ((info->num_of_philos = ft_atoi(argv[i])) <= 0))
			return (0);
		if (i == 2 && ((info->time_to_die = ft_atoi(argv[i])) <= 0))
			return (0);
		if (i == 3 && ((info->time_to_eat = ft_atoi(argv[i])) <= 0))
			return (0);
		if (i == 4 && ((info->time_to_sleep = ft_atoi(argv[i])) <= 0))
			return (0);
		if (i == 5 && ((info->num_of_must_eat = ft_atoi(argv[i])) <= 0))
			return (0);
		i++;
	}
	return (1);
}
