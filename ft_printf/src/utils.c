/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:58:29 by tseo              #+#    #+#             */
/*   Updated: 2020/10/30 22:55:13 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_info(t_va_info *info)
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
	while (n)
	{
		n /= len;
		++i;
	}
	n = value;
	if (!(ret = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	ret[i] = 0;
	while (n)
	{
		--i;
		ret[i] = base[n % len];
		n /= len;
	}
	return (ret);
}

int		get_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int		handling_width_util(t_va_info *info, char *parsed_data,
							int len, int r_len)
{
	if (info->precision == -1 && info->flag == '0')
	{
		ft_memset(parsed_data, '0', info->width);
		if (info->va_data[0] == '-')
		{
			ft_memmove(parsed_data + r_len + 1, info->va_data + 1, len - 1);
			parsed_data[0] = '-';
		}
		else
			ft_memmove(parsed_data + r_len, info->va_data, len);
	}
	else
	{
		ft_memset(parsed_data, ' ', info->width);
		ft_memmove(parsed_data + r_len, info->va_data, len);
	}
}
