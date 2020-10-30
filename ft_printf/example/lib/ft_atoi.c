/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:06:46 by heryu             #+#    #+#             */
/*   Updated: 2020/10/02 12:06:51 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	handle_overflow(double n)
{
	long	ret;

	ret = (long)n;
	if (n >= LONG_MAX)
		ret = LONG_MAX;
	if (n <= LONG_MIN)
		ret = LONG_MIN;
	return (ret);
}

int			ft_atoi(const char *str)
{
	double	ret;
	int		sign;
	size_t	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	ret = 0;
	while (ft_isdigit(str[i]))
	{
		ret = 10 * ret + (str[i++] - '0');
	}
	ret *= sign;
	ret = handle_overflow(ret);
	return (ret);
}
