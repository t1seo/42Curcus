/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:58:29 by tseo              #+#    #+#             */
/*   Updated: 2020/10/27 20:39:55 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void reset_info(t_va_info *info)
{
	if (!(info->va_data))
		free(info->va_data);
	ft_memset(info, 0, sizeof(t_va_info));
}

char	*ft_itoa_hex(unsigned long int value)
{
	unsigned long int	n;
	int					i;
	char				*ret;
	const char			*hex_digits = "0123456789abcdef";

	n = value;
	i = 0;
	while (n)
	{
		n /= 16;
		++i;
	}
	n = value;
	if (!(ret = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	ret[i] = 0;
	while (n)
	{
		--i;
		ret[i] = hex_digits[n % 16];
		n /= 16;
	}
	return (ret);
}
