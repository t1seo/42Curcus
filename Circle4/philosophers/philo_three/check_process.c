/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 20:46:20 by tseo              #+#    #+#             */
/*   Updated: 2021/05/15 18:16:15 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	kill_process(void)
{
	int i;

	i = 0;
	while (i < g_info.num_of_philos)
	{
		kill(g_philos[i].pid, SIGKILL);
		i++;
	}
}

void	check_process(void)
{
	int i;
	int status;
	int eat_done;

	eat_done = 0;
	while (1)
	{
		i = -1;
		while (++i < g_info.num_of_philos)
		{
			status = -1;
			waitpid(g_philos[i].pid, &status, WNOHANG);
			if (status == 256)
				break ;
			if (status == 0)
				eat_done++;
			if (eat_done == g_info.num_of_philos)
				break ;
		}
		if (status == 256 || eat_done == g_info.num_of_philos)
		{
			kill_process();
			break ;
		}
	}
}
