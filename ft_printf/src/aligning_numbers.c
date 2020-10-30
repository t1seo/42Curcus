/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aligning_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:44:50 by tseo              #+#    #+#             */
/*   Updated: 2020/10/30 22:00:08 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include <stdio.h>

int		make_aligned_int(t_va_info *info)
{
	char *parsed_int;
	int len;
	int r_len;

	len = ft_strlen(info->va_data);
	if (info->precision > len)
	{
		r_len = info->precision - len;
		if (info->va_data[0] == '-')
		{
			if (!(parsed_int = (char*)malloc(sizeof(char) * (info->precision + 2))))
				return (0);
			ft_memset(parsed_int, '0', info->precision);
			parsed_int[info->precision + 1] = 0;
			ft_memmove(parsed_int + r_len + 2, info->va_data + 1, len - 1);
			parsed_int[0] = '-';
		}
		else
		{
			if (!(parsed_int = (char*)malloc(sizeof(char) * (info->precision + 1))))
				return (0);
			ft_memset(parsed_int, '0', info->precision);
			parsed_int[info->precision] = 0;
			ft_memmove(parsed_int + r_len, info->va_data, len);
		}
		free(info->va_data);
		info->va_data = parsed_int;
		parsed_int = 0;
	}
	if (info->width > len && info->width > info->precision)
	{
		len = ft_strlen(info->va_data);
		r_len = info->width - len;
		if (!(parsed_int = (char*)malloc(sizeof(char) * (info->width + 1))))
			return (0);
		parsed_int[info->width] = 0;
		if (info->flag == '-')
		{
			ft_memset(parsed_int, ' ', info->width);
			ft_memmove(parsed_int, info->va_data, len);
		}
		else if (info->flag == 0 || info->flag == '0')
		{
			// printf("HELLO\n");
			// printf("flag : %d\n", info->flag);
			// printf("precision : %d\n", info->precision);
			if (info->precision == -1 && info->flag == '0')
			{
				ft_memset(parsed_int, '0', info->width);
				if (info->va_data[0] == '-')
				{
					ft_memmove(parsed_int + r_len + 1, info->va_data + 1, len - 1);
					parsed_int[0] = '-';
				}
				else
					ft_memmove(parsed_int + r_len, info->va_data, len);
			}
			else
			{
				ft_memset(parsed_int, ' ', info->width);
				ft_memmove(parsed_int + r_len, info->va_data, len);
			}
		}
		free(info->va_data);
		info->va_data = parsed_int;
		parsed_int = 0;
	}
	return (1);
}


int		make_aligned_uint(t_va_info *info)
{
	if (!(make_aligned_int(info)))
		return (0);
	return (1);
}

int     make_aligned_hex(t_va_info *info)
{
		if (!(make_aligned_int(info)))
		return (0);
	return (1);
}
