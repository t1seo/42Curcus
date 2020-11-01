/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_ptr_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:39:06 by tseo              #+#    #+#             */
/*   Updated: 2020/11/01 17:11:18 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	print_ptr_data(t_va_info *info, int *count)
{
	int va_data_len;

	va_data_len = ft_strlen(info->va_data);
	if (info->precision == 0 && !ft_strncmp(info->va_data, "0x0", 3)
		&& va_data_len == 3)
		va_data_len--;
	if (info->flag == '-')
	{
		write_letters(info->va_data, va_data_len, count);
		write_padding(' ', info->width - va_data_len, count);
	}
	else
	{
		write_padding(' ', info->width - va_data_len, count);
		write_letters(info->va_data, va_data_len, count);
	}
}
