/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:58:29 by tseo              #+#    #+#             */
/*   Updated: 2020/10/29 21:06:04 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void reset_info(t_va_info *info)
{
	if (!(info->va_data))
		free(info->va_data);
	ft_memset(info, 0, sizeof(t_va_info));
}

char	*ft_itoa_base(unsigned long int value, char const *base)
{
	unsigned long int	n;
	int					i;
	char				*ret;
	int					len;

	len = ft_strlen(base);
	n = value;
	i = 0;
	// if (value == 0 || value < 0)
		// ++i;
	while (n)
	{
		n /= len;
		++i;
	}
	n = value;
	if (!(ret = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	ret[i] = 0;
	// if (value < 0)
	// 	ret[i] = '-';
	// if (value == 0)
	// 	ret[i] = '0';
	while (n)
	{
		--i;
		ret[i] = base[n % len];
		n /= len;
	}
	return (ret);
}

void	memset_and_move(char *dst, int value, int len, t_va_info *info)
{
	ft_memset(dst, value, info->width);
	ft_memmove(dst, info->va_data, len);
}
