/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:50:18 by tseo              #+#    #+#             */
/*   Updated: 2021/05/07 21:32:20 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		print_error(char *err_msg)
{
	printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET "\n", err_msg);
	return (1);
}

int		print_message(t_philo *philo, t_status status, unsigned long cur_time)
{
	pthread_mutex_lock(&g_info.message);
	if (g_info.num_of_dead != 0)
	{
		pthread_mutex_unlock(&g_info.message);
		return (1);
	}
	printf("%lu %d", cur_time - g_info.start_time, philo->idx);
	if (status == TAKEN_FORK)
		printf(" has taken a fork\n");
	if (status == EATING)
	{
		printf(" is eating\n");
		philo->last_ate_time = cur_time;
	}
	if (status == SLEEPING)
		printf(" is sleeping\n");
	if (status == THINKING)
		printf(" is thinking\n");
	if (status == DEAD)
	{
		printf(ANSI_COLOR_RED " is died" ANSI_COLOR_RESET "\n");
		g_info.num_of_dead += 1;
	}
	pthread_mutex_unlock(&g_info.message);
	return (0);
}
