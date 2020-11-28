/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:47:57 by tseo              #+#    #+#             */
/*   Updated: 2020/10/31 22:21:11 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	reset_info(t_va_info *info)
{
	if (!(info->va_data))
		free(info->va_data);
	info->flag = 0;
	info->width = -1;
	info->precision = -1;
	info->specifier = 0;
	info->va_data = 0;
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

void	write_letters(char *str, int len, int *count)
{
	write(1, str, len);
	(*count) += len;
}

void	write_padding(char padding, int size, int *count)
{
	if (padding == 0)
		padding = ' ';
	while (size > 0)
	{
		write(1, &padding, 1);
		(*count)++;
		size--;
	}
}
