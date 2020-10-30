/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:50:51 by heryu             #+#    #+#             */
/*   Updated: 2020/10/15 23:20:15 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				print_data(t_print_info *info)
{
	if (info->specifier == '%')
		return (print_data_percent(info));
	if (info->specifier == 'c')
		return (print_data_char(info));
	if (info->specifier == 's')
		return (print_data_string(info));
	if (info->specifier == 'p')
		return (print_data_pointer(info));
	if (info->specifier == 'x'
		|| info->specifier == 'X'
		|| info->specifier == 'u'
		|| info->specifier == 'd'
		|| info->specifier == 'i')
		return (print_data_integer(info));
	return (RET_ERROR);
}

void			init_info(t_print_info *info)
{
	if (info->data != NULL)
		free(info->data);
	ft_memset(info, 0, sizeof(*info));
}

int				print_data_and_free(t_print_info *info)
{
	int	ret;

	ret = print_data(info);
	init_info(info);
	return (ret);
}

int				ft_printf(const char *str, ...)
{
	t_print_info	info;
	size_t			print_cnt;
	int				skip_index;
	va_list			ap;

	if (str == NULL)
		return (RET_ERROR);
	print_cnt = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if ((skip_index = parsing_flags(str, &info, &ap)) == RET_ERROR
					|| make_print_data(&info, &ap) == RET_ERROR)
				return (RET_ERROR);
			str += skip_index;
			print_cnt += print_data_and_free(&info);
			continue ;
		}
		write(1, str++, 1);
		print_cnt++;
	}
	va_end(ap);
	return (print_cnt);
}
