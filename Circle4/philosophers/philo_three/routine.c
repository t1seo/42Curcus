/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:19:52 by tseo              #+#    #+#             */
/*   Updated: 2021/05/14 21:19:35 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
	philo->last_ate_time = get_time();
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
		g_philos[i].pid = fork();
		if (g_philos[i].pid == 0)
			break ;
		i++;
	}
	if (i != g_info.num_of_philos)
	{
		start_routine(&g_philos[i]);
		exit(0);
	}
	else
		check_process();
}
