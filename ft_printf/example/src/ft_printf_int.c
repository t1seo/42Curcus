/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:29:03 by heryu             #+#    #+#             */
/*   Updated: 2020/10/14 23:15:18 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	get_max(int a, int b)
{
	return (a > b ? a : b);
}

static void	print_int_no_prec(t_print_info *info, int data_size, int skip_sign)
{
	if (info->flag == '-')
	{
		write(1, info->data, data_size);
		write_padding(' ', info->width - data_size);
	}
	else if (info->flag == '0')
	{
		write(1, info->data, skip_sign);
		write_padding(info->flag, info->width - data_size);
		write(1, info->data + skip_sign, data_size - skip_sign);
	}
	else
	{
		write_padding(info->flag, info->width - data_size);
		write(1, info->data, data_size);
	}
}

static void	print_int_prec(t_print_info *info, int data_size, int skip_sign)
{
	int	rest_width;

	rest_width = info->width - get_max(data_size, info->precision + skip_sign);
	if (info->flag == '-')
	{
		write(1, info->data, skip_sign);
		write_padding('0', info->precision - (data_size - skip_sign));
		write(1, info->data + skip_sign, data_size - skip_sign);
		write_padding(' ', rest_width);
	}
	else
	{
		write_padding(' ', rest_width);
		write(1, info->data, skip_sign);
		write_padding('0', info->precision - (data_size - skip_sign));
		write(1, info->data + skip_sign, data_size - skip_sign);
	}
}

int			print_data_integer(t_print_info *info)
{
	int		data_size;
	int		max_value;
	int		skip_sign;

	skip_sign = (info->data[0] == '-' ? 1 : 0);
	data_size = ft_strlen(info->data);
	if (info->precision == -1)
	{
		print_int_no_prec(info, data_size, skip_sign);
	}
	else
	{
		if (info->precision == 0 && info->data[0] == '0' && data_size == 1)
			data_size = 0;
		print_int_prec(info, data_size, skip_sign);
	}
	max_value = get_max(data_size, info->precision + skip_sign);
	max_value = get_max(max_value, info->width);
	return (max_value);
}
