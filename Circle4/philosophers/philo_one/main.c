/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:48:59 by tseo              #+#    #+#             */
/*   Updated: 2021/05/07 20:05:50 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_info			g_info;
t_philo			*g_philos;

int		main(int argc, char *argv[])
{
	if (!(argc == 5 || argc == 6))
		return (print_error(WRONG_ARGC));
	if (!(parse_argv(&g_info, argv)))
		return (print_error(WRONG_ARGS));
	if (!(g_philos = malloc(sizeof(t_philo) * g_info.num_of_philos)))
		return (print_error(MALLOC_FAIL));
	if (!(g_info.forks = malloc(sizeof(pthread_mutex_t) * g_info.num_of_philos)))
		return (print_error(MALLOC_FAIL));

	printf("The number of philos: %d\n", g_info.num_of_philos);
	printf("Time to die : %lu\n", g_info.time_to_die);
	printf("Time to eat : %lu\n", g_info.time_to_eat);
	printf("Time to sleep : %lu\n", g_info.time_to_sleep);
	if (g_info.num_of_must_eat)
		printf("The number of must eat : %d\n", g_info.num_of_must_eat);

	// set_table();
	// start_eating();
	// unset_table();
	return (0);
}
