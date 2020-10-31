/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:11:15 by heryu             #+#    #+#             */
/*   Updated: 2020/10/02 12:11:16 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	tmp[10];
	int		sign;
	int		cnt;

	if (fd < 0)
		return ;
	sign = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		sign = -1;
	}
	cnt = 0;
	while (1)
	{
		tmp[cnt++] = sign * (n % 10) + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	while (cnt--)
		ft_putchar_fd(tmp[cnt], fd);
}
