/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 09:42:46 by tseo              #+#    #+#             */
/*   Updated: 2020/10/26 20:55:54 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*g_format_type = "cspdiuxX%";

void	reset_info(t_arg_info *info)
{
	info->flag = 0;
	info->width = 0;
	info->precision = 0;
	info->specifier = 0;
	info->data = 0;
}

// void	parse_info(const char **ptr, va_list *ap, int *count)
// {

// }



void		init_format_parsing(const char *format, va_list *ap, int *count)
{
	const char *ptr = format;
	t_arg_info *info;

	(*count) = 0;
	if (!ft_strlen(format))
		return ;
	if (!(info = (t_arg_info*)malloc(sizeof(t_arg_info))))
	{
		(*count) = -1;
		return ;
	}
	reset_info(info);
	while (*ptr)
	{
		if ((*ptr) == '%')
		{
			// parse_info()
			// TODO: parsing infomation of format
			// TOTO: check validation of parsed format
			// TODO: print argument as parsed
			reset_info(info);
			continue ;
		}
		write(1, ptr++, 1);
		(*count)++;
	}
	free(info);
	parse_format(format, ap, count, info);
}

int			ft_printf(const char *format, ...)
{
	int			ret;
	va_list		ap;

	va_start(ap, format);
	init_format_parsing(format, &ap, &ret);
	va_end(ap);

	return (ret);
}
