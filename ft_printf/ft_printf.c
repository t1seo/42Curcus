/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 09:42:46 by tseo              #+#    #+#             */
/*   Updated: 2020/10/24 17:19:36 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		init_format_parse(va_list ap, const char *format)
{
	t_format_info	*info;
	int				i;
	int				ret;

	i = 0;
	ret = 0;
	if (!(info = malloc(sizeof(t_format_info))))
		return (-1);

	free(info);
	return (ret);
}

// ft_printf("%s %d\n", "Hello ", 42);
int			ft_printf(const char *format, ...)
{
	int			ret;
	va_list		ap;

	va_start(ap, format);
	ret = init_format_parse(ap, format);
	va_end(ap);

	// return the number of characters printed
	// return a negative value if an error occurs
	// return 0 if format string is empty
	return (ret);
}
