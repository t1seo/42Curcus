/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:25:33 by heryu             #+#    #+#             */
/*   Updated: 2020/10/15 23:19:33 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			write_padding(char padding_char, int cnt)
{
	int		i;

	if (padding_char == 0)
		padding_char = ' ';
	i = 0;
	while (i < cnt)
	{
		write(1, &padding_char, 1);
		i++;
	}
	return (cnt);
}

int			print_data_char(t_print_info *info)
{
	if (info->flag == '-')
	{
		write(1, info->data, 1);
		write_padding(' ', info->width - 1);
	}
	else
	{
		write_padding(' ', info->width - 1);
		write(1, info->data, 1);
	}
	return (info->width > 0 ? info->width : 1);
}

int			print_data_string(t_print_info *info)
{
	int		data_size;
	int		print_size;

	data_size = ft_strlen(info->data);
	if (info->precision == -1)
		print_size = data_size;
	else
		print_size = info->precision < data_size ? info->precision : data_size;
	if (info->flag == '-')
	{
		write(1, info->data, print_size);
		write_padding(' ', info->width - print_size);
	}
	else
	{
		write_padding(' ', info->width - print_size);
		write(1, info->data, print_size);
	}
	return (info->width > print_size ? info->width : print_size);
}

int			print_data_pointer(t_print_info *info)
{
	int		print_size;

	print_size = ft_strlen(info->data);
	if (info->precision == 0 && print_size == 3 && info->data[2] == '0')
		print_size -= 1;
	if (info->flag == '-')
	{
		write(1, info->data, print_size);
		write_padding(' ', info->width - print_size);
	}
	else
	{
		write_padding(' ', info->width - print_size);
		write(1, info->data, print_size);
	}
	return (info->width > print_size ? info->width : print_size);
}

int			print_data_percent(t_print_info *info)
{
	char	percent;

	percent = '%';
	if (info->flag == '-')
	{
		write(1, &percent, 1);
		write_padding(' ', info->width - 1);
	}
	else
	{
		write_padding(info->flag, info->width - 1);
		write(1, &percent, 1);
	}
	return (info->width > 0 ? info->width : 1);
}
