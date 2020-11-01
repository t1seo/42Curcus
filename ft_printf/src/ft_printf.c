/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 09:42:46 by tseo              #+#    #+#             */
/*   Updated: 2020/11/01 17:53:49 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

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
	if (info->specifier == '%')
		return (allocate_percent(info));
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
	return (1);
}

static void		print_data(t_va_info *info, int *count)
{
	if (info->specifier == 'c')
		print_char_data(info, count);
	if (info->specifier == '%')
		print_percent_data(info, count);
	if (info->specifier == 's')
		print_str_data(info, count);
	if (info->specifier == 'p')
		print_ptr_data(info, count);
	if (info->specifier == 'd'
		|| info->specifier == 'i'
		|| info->specifier == 'u'
		|| info->specifier == 'd'
		|| info->specifier == 'x'
		|| info->specifier == 'X')
		print_num_data(info, count);
}

static int		init_format_parsing(const char *format, va_list *ap,
									t_va_info *info)
{
	int			count;

	count = 0;
	while (*format)
	{
		reset_info(info);
		if ((*format) == '%')
		{
			if (!(parsing_format(&format, info, ap))
				|| !(data_allocation(info, ap)))
			{
				count = -1;
				break ;
			}
			print_data(info, &count);
			continue ;
		}
		write(1, format++, 1);
		count++;
	}
	reset_info(info);
	free(info);
	return (count);
}

int				ft_printf(const char *format, ...)
{
	int			ret;
	va_list		ap;
	t_va_info	*info;

	if (!(info = (t_va_info*)malloc(sizeof(t_va_info))))
		return (-1);
	if (!ft_strlen(format))
		return (0);
	va_start(ap, format);
	ret = init_format_parsing(format, &ap, info);
	va_end(ap);
	return (ret);
}
