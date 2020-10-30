/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:11:52 by heryu             #+#    #+#             */
/*   Updated: 2020/10/14 20:14:02 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	set_flags(const char *str, t_print_info *info)
{
	size_t	i;

	i = 0;
	if (str[i] == '0' || str[i] == '-')
	{
		info->flag = str[i];
		i++;
		while (str[i] == '0' || str[i] == '-')
		{
			if (str[i] == '-')
				info->flag = '-';
			i++;
		}
		return (i);
	}
	info->flag = '\0';
	return (0);
}

static int	set_width(const char *str, t_print_info *info, va_list *ap)
{
	size_t	i;

	i = 0;
	if (str[i] == '*')
	{
		info->width = va_arg(*ap, int);
		if (info->width < 0)
		{
			info->width *= -1;
			info->flag = '-';
		}
		i++;
		return (i);
	}
	info->width = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

static int	set_precision(const char *str, t_print_info *info, va_list *ap)
{
	size_t	i;

	i = 0;
	if (str[i] != '.')
	{
		info->precision = -1;
		return (0);
	}
	i++;
	if (str[i] == '*')
	{
		info->precision = va_arg(*ap, int);
		if (info->precision < 0)
			info->precision = -1;
		i++;
		return (i);
	}
	info->precision = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

static int	set_specifier(const char *str, t_print_info *info)
{
	size_t	i;

	i = 0;
	if (str[i] == 'c' || str[i] == 's' || str[i] == 'p'
		|| str[i] == 'd' || str[i] == 'i' || str[i] == 'u'
			|| str[i] == 'x' || str[i] == 'X' || str[i] == '%')
	{
		info->specifier = str[i];
		return (1);
	}
	info->specifier = '\0';
	return (RET_ERROR);
}

int			parsing_flags(const char *str, t_print_info *info, va_list *ap)
{
	size_t	i;
	size_t	tmp;

	i = 1;
	if ((tmp = set_flags(&str[i], info)) == RET_ERROR)
		return (RET_ERROR);
	i += tmp;
	if ((tmp = set_width(&str[i], info, ap)) == RET_ERROR)
		return (RET_ERROR);
	i += tmp;
	if ((tmp = set_precision(&str[i], info, ap)) == RET_ERROR)
		return (RET_ERROR);
	i += tmp;
	if ((tmp = set_specifier(&str[i], info)) == RET_ERROR)
		return (RET_ERROR);
	i += tmp;
	return (i);
}
