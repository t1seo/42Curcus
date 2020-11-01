/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_num_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 22:01:01 by tseo              #+#    #+#             */
/*   Updated: 2020/11/01 17:35:43 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		print_num_data_without_precision(t_va_info *info, int va_data_len,
													int *count, int skip_sign_idx)
{
	if (info->flag == '-')
	{
		write_letters(info->va_data, va_data_len, count);
		write_padding(' ', info->width - va_data_len, count);
	}
	else if (info->flag == '0')
	{
		write_letters(info->va_data, skip_sign_idx, count);
		write_padding(info->flag, info->width - va_data_len, count);
		write_letters(info->va_data + skip_sign_idx, va_data_len - skip_sign_idx, count);
	}
	else
	{
		write_padding(info->flag, info->width - va_data_len, count);
		write_letters(info->va_data, va_data_len, count);
	}
}

static void		print_num_data_with_precision(t_va_info *info, int va_data_len,
													int *count, int skip_sign_idx)
{
	int rest_width_len;

	if (va_data_len > info->precision + skip_sign_idx)
		rest_width_len = info->width - va_data_len;
	else
		rest_width_len = info->width - (info->precision + skip_sign_idx);
	if (info->flag == '-')
	{
		write_letters(info->va_data, skip_sign_idx, count);
		write_padding('0', info->precision - (va_data_len - skip_sign_idx), count);
		write_letters(info->va_data + skip_sign_idx, va_data_len - skip_sign_idx, count);
		write_padding(' ', rest_width_len, count);
	}
	else
	{
		write_padding(' ', rest_width_len, count);
		write_letters(info->va_data, skip_sign_idx, count);
		write_padding('0', info->precision - (va_data_len - skip_sign_idx), count);
		write_letters(info->va_data + skip_sign_idx, va_data_len - skip_sign_idx, count);
	}
}

void	print_num_data(t_va_info *info, int *count)
{
	int va_data_len;
	int	skip_sign_idx;

	va_data_len = ft_strlen(info->va_data);
	if (info->va_data[0] == '-')
		skip_sign_idx = 1;
	else
		skip_sign_idx = 0;

	if (info->precision == -1)
		print_num_data_without_precision(info, va_data_len, count, skip_sign_idx);
	else
	{
		if (info->precision == 0 && info->va_data[0] == '0' && va_data_len == 1)
			va_data_len = 0;
		print_num_data_with_precision(info, va_data_len, count, skip_sign_idx);
	}
}
