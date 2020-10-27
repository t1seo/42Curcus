/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 09:42:46 by tseo              #+#    #+#             */
/*   Updated: 2020/10/27 17:05:13 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*g_format_type = "cspdiuxX%";

// TEST function
void print_parsed_data_test(t_va_info *info)
{
	printf("\n");
	printf("flag : %c\n", info->flag);
	printf("width : %d\n", info->width);
	printf("precision : %d\n", info->precision);
	printf("specifier : %c\n", info->specifier);
}

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
	return (1);
}

// static int		print_parsed_data(int *count, t_va_info *info, va_list *ap)
// {
// 	if (info->specifier == 'c')
// 		return (print_parsed_char(info, ap, count));
// 	return (1);
// }


static int		init_format_parsing(const char *format, va_list *ap)
{
	const char *ptr = format;
	t_va_info *info;
	int count;

	count = 0;
	if (!ft_strlen(format))
		return (0);
	if (!(info = (t_va_info*)malloc(sizeof(t_va_info))))
		return (-1);
	reset_info(info);
	while (*ptr)
	{
		if ((*ptr) == '%')
		{
			// TODO : data allocation
			if (!(parsing_format(&ptr, info, ap))
				|| !(data_allocation(info, ap)))
			{
				reset_info(info);
				return (-1);
			}
			// TODO : print parsed data
			print_parsed_data_test(info);
			reset_info(info);
			continue ;
		}
		write(1, ptr++, 1);
		(count)++;
	}
	reset_info(info);
	free(info);
	return (count);
}

int			ft_printf(const char *format, ...)
{
	int			ret;
	va_list		ap;

	va_start(ap, format);
	ret = init_format_parsing(format, &ap);
	va_end(ap);

	return (ret);
}
