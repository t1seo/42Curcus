/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_num_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:01:01 by tseo              #+#    #+#             */
/*   Updated: 2020/10/31 23:48:59 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	print_num_data(t_va_info *info, int *count)
{
	int len;
	int rest_width;

	len = ft_strlen(info->va_data);
	if (info->precision == -1)
	{
		if (info->flag == '-')
		{
			write_letters(info->va_data, len, count);
			write_padding(' ', info->width - len, count);
		}
		else if (info->flag == '0')
		{
			if (info->va_data[0] == '-')
			{
				write_letters(info->va_data, 1, count);
				write_padding(info->flag, info->width - len, count);
				write_letters(info->va_data + 1, len - 1, count);
			}
			else
			{
				write_padding(info->flag, info->width - len, count);
				write_letters(info->va_data, len, count);
			}
		}
	}
	else
	{
		if (info->flag == '-')
		{
			if (info->va_data[0] == '-')
			{
			}
			else
			{
			}
		}
		else
		{
			if (info->va_data[0] == '-')
			{
			}
			else
			{
			}
		}
	}
}
