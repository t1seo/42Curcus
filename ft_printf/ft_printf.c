/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 09:42:46 by tseo              #+#    #+#             */
/*   Updated: 2020/10/25 03:25:30 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_format_info **info)
{
	ft_memset(*info, 0, sizeof(t_format_info));
}

void	parse_format(const char **format, va_list *ap, t_format_info **info, int *ret)
{
	while (*format)
	{
		write(1, &format, 1);
		(*format)++;
		(*ret)++;
	}
}

int		init_format_parsing(const char **format, va_list *ap)
{
	int	i;
	int	ret;
	t_format_info	*info;

	if (!ft_strlen(format))
		return (0);
	if (!(info = malloc(sizeof(t_format_info))))
		return (-1);
	parse_format(format, ap, &info, &ret);
	return (ret);
}

// ft_printf("%s %d %c\n", "Hello ", 42, '!');
int			ft_printf(const char *format, ...)
{
	int			ret;
	va_list		ap;

	va_start(ap, format);
	ret = init_format_parsing(&format, &ap);
	va_end(ap);

	// return the number of characters printed
	// return a negative value if an error occurs
	// return 0 if format string is empty
	return (ret);
}
