/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:09:02 by tseo              #+#    #+#             */
/*   Updated: 2021/05/07 20:17:45 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	set_table(void)
{
	int i;

	i = 0;
	while (i < g_info.num_of_philos)
	{
		pthread_mutex_init(&g_info.forks[i], NULL);
		g_philos[i].idx = i + 1;
		g_philos[i].num_of_eat = 0;
		g_philos[i].fork_1 = i - 1;
		g_philos[i].fork_2 = i;
		if (i == 0)
			g_philos[i].fork_1 = g_info.num_of_philos - 1;
		i++;
	}
	pthread_mutex_init(&g_info.message, NULL);
	g_info.start_time = get_time();
	g_info.num_of_eating_done = 0;
	g_info.num_of_dead = 0;
}

void	unset_table(void)
{
	int i;

	i = 0;
	while (i < g_info.num_of_philos)
	{
		pthread_mutex_destroy(&g_info.forks[i]);
		i++;
	}
	pthread_mutex_destroy(&g_info.message);
	free(g_info.forks);
	free(g_philos);
}
