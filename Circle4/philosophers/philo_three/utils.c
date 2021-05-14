/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:50:54 by tseo              #+#    #+#             */
/*   Updated: 2021/05/14 19:22:11 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int				ft_atoi(const char *str)
{
	int i;
	int n;
	int sign;

	i = 0;
	n = 0;
	sign = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	return (sign * n);
}

unsigned long	get_time(void)
{
	struct timeval	tv;
	const double	milli = 1000.0L;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * milli + tv.tv_usec / milli);
}

void			vsleep(unsigned long time)
{
	unsigned long start_time;

	start_time = get_time();
	while (get_time() - start_time < time)
		usleep(100);
}

int				is_num(char *num)
{
	int i;

	i = 0;
	while (num[i])
	{
		if (!('0' <= num[i] && num[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
