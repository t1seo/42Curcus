/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_chars_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:21:53 by tseo              #+#    #+#             */
/*   Updated: 2020/10/31 22:23:17 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void				print_char_data(t_va_info *info, int *count)
{
	if (info->flag == '-')
	{
		write_letters(info->va_data, 1, count);
		write_padding(' ', info->width - 1, count);
	}
	else
	{
		write_padding(' ', info->width - 1, count);
		write_letters(info->va_data, 1, count);
	}
}

void				print_percent_data(t_va_info *info, int *count)
{
	if (info->flag == '-')
	{
		write_letters("%%", 1, count);
		write_padding(' ', info->width - 1, count);
	}
	else
	{
		write_padding(info->flag, info->width - 1, count);
		write_letters("%%", 1, count);
	}
}

void				print_str_data(t_va_info *info, int *count)
{
	int len;

	len = ft_strlen(info->va_data);
	if (info->precision != -1 && info->precision < len)
		len = info->precision;
	if (info->flag == '-')
	{
		write_letters(info->va_data, len, count);
		write_padding(' ', info->width - len, count);
	}
	else
	{
		write_padding(' ', info->width - len, count);
		write_letters(info->va_data, len, count);
	}
}
