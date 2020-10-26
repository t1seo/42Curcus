/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 09:42:46 by tseo              #+#    #+#             */
/*   Updated: 2020/10/26 23:53:14 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*g_format_type = "cspdiuxX%";

void reset_info(t_va_info *info)
{
	if (!(info->va_data))
		free(info->va_data);
	ft_memset(info, 0, sizeof(t_va_info));
}

static void		init_format_parsing(const char *format, va_list *ap, int *count)
{
	const char *ptr = format;
	t_va_info *info;

	(*count) = 0;
	if (!ft_strlen(format))
		return ;
	if (!(info = (t_va_info*)malloc(sizeof(t_va_info))))
	{
		(*count) = -1;
		return ;
	}
	reset_info(info);
	while (*ptr)
	{
		if ((*ptr) == '%')
		{
			// TODO: parsing infomation of format
			if (!(parsing_format(&ptr, info, ap)))
			{
				(*count) = -1;
				break ;
			}
			// TODO: print parsed argument
			reset_info(info);
			continue ;
		}
		write(1, ptr++, 1);
		(*count)++;
	}
	free(info);
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
