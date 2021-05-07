/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:18:52 by tseo              #+#    #+#             */
/*   Updated: 2021/05/07 21:21:09 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*check_status(void *arg)
{
	t_philo			*philo;
	unsigned long	cur_time;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->num_of_eat == g_info.num_of_must_eat)
			break ;
		cur_time = get_time();
		if (g_info.time_to_die < cur_time - philo->last_ate_time)
		{
			print_message(philo, DEAD, cur_time);
			return (NULL);
		}
		vsleep(1);
	}
	return (NULL);
}
