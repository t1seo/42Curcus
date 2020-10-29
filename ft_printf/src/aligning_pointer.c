/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aligning_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:45:09 by tseo              #+#    #+#             */
/*   Updated: 2020/10/29 22:30:50 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include <stdio.h>

int		make_aligned_ptr(t_va_info *info)
{
	char	*parsed_ptr;
	int		len;
	int		r_len;

	len = ft_strlen(info->va_data);
	if (info->width > len && info->width > info->precision)
	{
		r_len = info->width - len;
		if (!(parsed_ptr = (char*)malloc(sizeof(char) * (info->width + 1))))
			return (0);
		parsed_ptr[info->width] = 0;
		if (info->flag == '-')
		{
			ft_memset(parsed_ptr, ' ', info->width);
			ft_memmove(parsed_ptr, info->va_data, len);
		}
		else if (info->flag == 0)
		{
			ft_memset(parsed_ptr, ' ', info->width);
			ft_memmove(parsed_ptr + r_len, info->va_data, len);
		}
		else if (info->flag == '0')
		{
			ft_memset(parsed_ptr, '0', info->width);
			parsed_ptr[0] = info->va_data[0];
			parsed_ptr[1] = info->va_data[1];
			ft_memmove(parsed_ptr + r_len + 2, info->va_data + 2, len - 2);
		}
		free(info->va_data);
		info->va_data = parsed_ptr;
	}
	else if (info->precision > len && info->precision > info->width)
	{
		// printf("PRECISION : %d\n", info->precision);
		if (!(parsed_ptr = (char*)malloc(sizeof(char) * (info->precision + 1))))
			return (0);
		parsed_ptr[info->precision] = 0;
		r_len = info->precision - len;

		ft_memset(parsed_ptr, '0', info->precision);
		parsed_ptr[0] = info->va_data[0];
		parsed_ptr[1] = info->va_data[1];
		ft_memmove(parsed_ptr + r_len + 2, info->va_data + 2, len - 2);

		free(info->va_data);
		info->va_data = parsed_ptr;
	}
	return (1);
}
