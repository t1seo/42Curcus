/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aligning_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:44:50 by tseo              #+#    #+#             */
/*   Updated: 2020/10/30 22:56:50 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	handling_precision(t_va_info *info, int len, int r_len)
{
	char *parsed_data;

	if (info->va_data[0] == '-')
	{
		if (!(parsed_data = (char*)malloc(sizeof(char)
							* (info->precision + 2))))
			return (0);
		ft_memset(parsed_data, '0', info->precision);
		parsed_data[info->precision + 1] = 0;
		ft_memmove(parsed_data + r_len + 2, info->va_data + 1, len - 1);
		parsed_data[0] = '-';
	}
	else
	{
		if (!(parsed_data = (char*)malloc(sizeof(char)
							* (info->precision + 1))))
			return (0);
		ft_memset(parsed_data, '0', info->precision);
		parsed_data[info->precision] = 0;
		ft_memmove(parsed_data + r_len, info->va_data, len);
	}
	free(info->va_data);
	info->va_data = parsed_data;
	parsed_data = 0;
	return (1);
}

static int	handling_width(t_va_info *info, int len, int r_len)
{
	char *parsed_data;

	if (!(parsed_data = (char*)malloc(sizeof(char) * (info->width + 1))))
		return (0);
	parsed_data[info->width] = 0;
	if (info->flag == '-')
	{
		ft_memset(parsed_data, ' ', info->width);
		ft_memmove(parsed_data, info->va_data, len);
	}
	else if (info->flag == 0 || info->flag == '0')
	{
		handling_width_util(info, parsed_data, len, r_len);
	}
	free(info->va_data);
	info->va_data = parsed_data;
	parsed_data = 0;
	return (1);
}

int			make_aligned_int(t_va_info *info)
{
	int len;
	int r_len;

	len = ft_strlen(info->va_data);
	if (info->precision > len)
	{
		r_len = info->precision - len;
		if (!(handling_precision(info, len, r_len)))
			return (0);
	}
	if (info->width > len && info->width > info->precision)
	{
		len = ft_strlen(info->va_data);
		r_len = info->width - len;
		if (!(handling_width(info, len, r_len)))
			return (0);
	}
	return (1);
}

int			make_aligned_uint(t_va_info *info)
{
	if (!(make_aligned_int(info)))
		return (0);
	return (1);
}

int			make_aligned_hex(t_va_info *info)
{
	if (!(make_aligned_int(info)))
		return (0);
	return (1);
}
