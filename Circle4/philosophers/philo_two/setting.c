/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:09:02 by tseo              #+#    #+#             */
/*   Updated: 2021/05/17 15:01:43 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		set_table(void)
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
	if ((g_info.act = sem_open("/act", O_CREAT | O_EXCL,
	0644, g_info.num_of_philos / 2)) == SEM_FAILED)
		return (0);
	if ((g_info.message = sem_open("/message",
	O_CREAT | O_EXCL, 0644, 1)) == SEM_FAILED)
		return (0);
	sem_unlink("/act");
	sem_unlink("/message");
	return (1);
}

void	unset_table(void)
{
	sem_close(g_info.act);
	sem_close(g_info.message);
	free(g_philos);
}
