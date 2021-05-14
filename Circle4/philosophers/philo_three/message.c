/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:50:18 by tseo              #+#    #+#             */
/*   Updated: 2021/05/14 21:23:39 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		print_error(char *err_msg)
{
	printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET "\n", err_msg);
	return (-1);
}

void	print_red_msg(char *msg, t_philo *philo, unsigned long cur_time)
{
	printf(ANSI_COLOR_RED "%lu %d %s\n" ANSI_COLOR_RESET,
	cur_time - g_info.start_time, philo->idx, msg);
}

void	print_green_msg(char *msg, t_philo *philo, unsigned long cur_time)
{
	printf(ANSI_COLOR_GREEN "%lu %d %s\n" ANSI_COLOR_RESET,
	cur_time - g_info.start_time, philo->idx, msg);
}

int		print_message(t_philo *philo, t_status status, unsigned long cur_time)
{
	sem_wait(g_info.message);
	if (g_info.num_of_dead != 0)
	{
		sem_post(g_info.message);
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
		print_red_msg(" is died", philo, cur_time);
		g_info.num_of_dead += 1;
		return (1);
	}
	sem_post(g_info.message);
	return (0);
}
