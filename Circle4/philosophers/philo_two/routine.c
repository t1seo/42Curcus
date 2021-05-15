/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:19:52 by tseo              #+#    #+#             */
/*   Updated: 2021/05/16 05:39:45 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		eating(t_philo *philo)
{
	sem_wait(g_info.act);
	sem_wait(g_info.fork);
	print_message(philo, TAKEN_FORK, get_time());
	sem_wait(g_info.fork);
	print_message(philo, TAKEN_FORK, get_time());
	print_message(philo, EATING, get_time());
	vsleep(g_info.time_to_eat);
	sem_post(g_info.act);
	sem_post(g_info.fork);
	sem_post(g_info.fork);
	philo->num_of_eat += 1;
	if (philo->num_of_eat == g_info.num_of_must_eat)
	{
		g_info.num_of_eating_done += 1;
		return (1);
	}
	return (0);
}

void	*start_routine(void *arg)
{
	t_philo		*philo;
	pthread_t	tid;

	philo = (t_philo *)arg;
	pthread_create(&tid, NULL, check_status, philo);
	while (1)
	{
		if (eating(philo))
			break ;
		if (print_message(philo, SLEEPING, get_time()))
			break ;
		vsleep(g_info.time_to_sleep);
		if (print_message(philo, THINKING, get_time()))
			break ;
	}
	pthread_join(tid, NULL);
	return (NULL);
}

void	start_eating(void)
{
	int i;

	i = 0;
	while (i < g_info.num_of_philos)
	{
		g_philos[i].last_ate_time = get_time();
		pthread_create(&g_philos[i].tid, NULL, start_routine, &g_philos[i]);
		i++;
	}
	i = 0;
	while (i < g_info.num_of_philos)
	{
		pthread_join(g_philos[i].tid, NULL);
		i++;
	}
}
