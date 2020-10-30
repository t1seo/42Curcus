/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 09:42:46 by tseo              #+#    #+#             */
/*   Updated: 2020/10/31 03:03:29 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char const		*g_format_type = "cspdiuxX%";

static int		parsing_format(const char **ptr, t_va_info *info, va_list *ap)
{
	(*ptr)++;
	parsing_flag(ptr, info);
	parsing_width(ptr, info, ap);
	parsing_precision(ptr, info, ap);
	if (!(parsing_specifier(ptr, info)))
		return (0);
	return (1);
}

static int		data_allocation(t_va_info *info, va_list *ap)
{
	if (info->specifier == 'c')
		return (allocate_char_data(info, ap));
	if (info->specifier == 's')
		return (allocate_str_data(info, ap));
	if (info->specifier == 'p')
		return (allocate_pointer_data(info, ap));
	if (info->specifier == 'd' || info->specifier == 'i')
		return (allocate_signed_int(info, ap));
	if (info->specifier == 'u')
		return (allocate_unsigned_int(info, ap));
	if (info->specifier == 'x' || info->specifier == 'X')
		return (allocate_hex(info, ap));
	if (info->specifier == '%')
		return (allocate_percent(info));
	return (1);
}

static int		make_aligned_data(t_va_info *info)
{
	if (info->specifier == 'c')
		return (make_aligned_char(info));
	if (info->specifier == 's')
		return (make_aligned_str(info));
	if (info->specifier == '%')
		return (make_aligned_percent(info));
	if (info->specifier == 'p')
		return (make_aligned_ptr(info));
	if (info->specifier == 'd' || info->specifier == 'i')
		return (make_aligned_int(info));
	if (info->specifier == 'u')
		return (make_aligned_uint(info));
	if (info->specifier == 'x' || info->specifier == 'X')
		return (make_aligned_hex(info));
	return (1);
}

static void		init_format_parsing(const char *format, t_va_info *info,
									va_list *ap, int *count)
{
	while (*format)
	{
		if ((*format) == '%')
		{
			if (!(parsing_format(&format, info, ap))
				|| !(data_allocation(info, ap))
				|| !(make_aligned_data(info)))
			{
				(*count) = -1;
				break ;
			}
			ft_putstr_fd(info->va_data, ft_strlen(info->va_data));
			(*count) += ft_strlen(info->va_data);
			reset_info(info);
			continue ;
		}
		write(1, format++, 1);
		(*count)++;
	}
	reset_info(info);
	free(info);
}

int				ft_printf(const char *format, ...)
{
	int			ret;
	va_list		ap;
	t_va_info	*info;

	if (!ft_strlen(format))
		return (0);
	ret = 0;
	if (!(info = (t_va_info*)malloc(sizeof(t_va_info))))
		return (-1);
	reset_info(info);
	va_start(ap, format);
	init_format_parsing(format, info, &ap, &ret);
	va_end(ap);
	return (ret);
}
