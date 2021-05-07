/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:50:18 by tseo              #+#    #+#             */
/*   Updated: 2021/05/07 22:00:34 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		print_error(char *err_msg)
{
	printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET "\n", err_msg);
	return (1);
}

void	print_red_msg(char *msg, t_philo *philo, unsigned long cur_time)
{
	printf(ANSI_COLOR_RED);
	printf("%lu %d", cur_time - g_info.start_time, philo->idx);
	printf("%s\n", msg);
	printf(ANSI_COLOR_RESET);
}

void	print_green_msg(char *msg, t_philo *philo, unsigned long cur_time)
{
	printf(ANSI_COLOR_GREEN);
	printf("%lu %d", cur_time - g_info.start_time, philo->idx);
	printf("%s\n", msg);
	printf(ANSI_COLOR_RESET);
}



int		print_message(t_philo *philo, t_status status, unsigned long cur_time)
{
	pthread_mutex_lock(&g_info.message);
	if (g_info.num_of_dead != 0)
	{
		pthread_mutex_unlock(&g_info.message);
		return (1);
	}
	if (status == TAKEN_FORK)
		print_green_msg(" has taken a fork", philo, cur_time);
	if (status == EATING)
	{
		print_green_msg(" is eating", philo, cur_time);
		philo->last_ate_time = cur_time;
	}
	if (status == SLEEPING)
		print_green_msg(" is sleeping", philo, cur_time);
	if (status == THINKING)
		print_green_msg(" is thinking", philo, cur_time);
	if (status == DEAD)
	{
		print_red_msg(" is thinking", philo, cur_time);
		g_info.num_of_dead += 1;
	}
	pthread_mutex_unlock(&g_info.message);
	return (0);
}
