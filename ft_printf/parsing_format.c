/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 14:15:02 by tseo              #+#    #+#             */
/*   Updated: 2020/10/26 23:52:26 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// printf에서 -와 0을 동시에 flag 옵션을 주면 - 우선
static void		parsing_flag(const char **ptr, t_va_info *info)
{
	if (*ptr == '-' || *ptr == '0')
	{
		info->flag = (*ptr);
		(*ptr)++;
		while (*ptr == '-' || *ptr == '0')
		{
			if (*ptr == '-')
				info->flag = '-';
			(*ptr)++;
		}
		return (1);
	}
	info->flag = 0;
}

// width * -> 가변인자
// 양수 : 오른쪽 정렬
// 음수 : 왼쪽 정렬
static void		parsing_width(const char **ptr, t_va_info *info, va_list *ap)
{
	if (*ptr == '*')
	{
		info->width = va_arg(*ap, int);
		if (info->width < 0)
		{
			info->width *= -1;
			info->flag = '-';
		}
		(*ptr)++;
	}
	// pointer test
	info->width = ft_atoi(*ptr);
	while (ft_isdigit(*ptr))
		(*ptr)++;
}

// precision
// 정수(d, i): 오른쪽 정렬하고 0으로 채운다
// 음수가 할당되면 무시된다.
static void		parsing_precision(const char **ptr, t_va_info *info, va_list *ap)
{
	if (*ptr != '.')
	{
		info->precision = -1;
		return ;
	}
	(*ptr)++;
	if (*ptr == '*')
	{
		info->precision = va_arg(*ap, int);
		if (info->precision < 0)
			info->precision = -1;
		(*ptr)++;
	}
	info->precision = ft_atoi(*ptr);
	while (ft_isdigit(*ptr))
		(*ptr)++;
}

static int	parsing_specifier(const char **ptr, t_va_info *info)
{
	char *format_type;

	format_type = g_format_type;
	while (*format_type)
	{
		if (*format_type == *ptr)
		{
			info->specifier = *format_type;
			(*ptr)++;
			return (1);
		}
		format_type++;
	}
	return (0);
}

// flag -> width -> precision -> length -> specifier
int		parsing_format(const char **ptr, t_va_info *info, va_list *ap)
{
	(*ptr)++;
	parsing_flag(ptr, info);
	parsing_width(ptr, info, ap);
	parsing_precision(ptr, info, ap);
	if (!(parsing_specifier(ptr, info)))
		return (0);
	return (1);
}
