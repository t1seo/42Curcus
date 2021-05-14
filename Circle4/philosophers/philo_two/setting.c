/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:09:02 by tseo              #+#    #+#             */
/*   Updated: 2021/05/14 15:42:30 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	set_table(void)
{
	int i;

	i = 0;
	while (i < g_info.num_of_philos)
	{
		g_philos[i].idx = i + 1;
		g_philos[i].num_of_eat = 0;
		i++;
	}
	g_info.start_time = get_time();
	g_info.num_of_eating_done = 0;
	g_info.num_of_dead = 0;
	g_info.act = sem_open("/act", O_CREAT | O_EXCL, 0644, g_info.num_of_philos / 2);
	g_info.message = sem_open("/message", O_CREAT | O_EXCL, 0644, 1);
	g_info.fork = sem_open("/message", O_CREAT | O_EXCL, 0644, g_info.num_of_philos);
	sem_unlink("/act");
	sem_unlink("/message");
	sem_unlink("/fork");
}

void	unset_table(void)
{
	sem_close(g_info.act);
	sem_close(g_info.message);
	sem_close(g_info.fork);
	free(g_philos);
}
