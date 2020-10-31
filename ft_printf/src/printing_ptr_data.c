/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_ptr_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 21:39:06 by tseo              #+#    #+#             */
/*   Updated: 2020/10/31 21:43:11 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	print_ptr_data(t_va_info *info, int *count)
{
	int len;

	len = ft_strlen(info->va_data);
	if (info->precision == 0 && !ft_strncmp(info->va_data, "0x0", 3))
		len--;
	if (info->flag == '-')
	{
		write(1, info->va_data, len);
		(*count) += len;
		write_padding(' ', info->width - len, count);
	}
	else
	{
		write_padding(' ', info->width - len, count);
		write(1, info->va_data, len);
		(*count) += len;
	}
}
