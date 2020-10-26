/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 09:42:46 by tseo              #+#    #+#             */
/*   Updated: 2020/10/26 14:28:18 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*g_format_type = "cspdiuxX%";

void	reset_info(t_arg_info *info)
{
}

// void	parse_info(const char *format, va_list *ap, int *count)
// {

// }

// format ex) "hello %*d %c world %s"
void	parse_format(const char *format, va_list *ap, int *count, t_arg_info *info)
{
	const char *ptr = format;
	int idx;

	while (*ptr)
	{
		if ((*ptr) == '%')
		{
			ptr += idx;
			continue ;
		}
		write(1, ptr++, 1);
		(*count)++;
	}
	free(info);
}

void		init_format_parsing(const char *format, va_list *ap, int *count)
{
	int	i;
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
