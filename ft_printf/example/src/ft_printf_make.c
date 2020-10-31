/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_make.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:21:36 by heryu             #+#    #+#             */
/*   Updated: 2020/10/14 20:24:43 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			make_print_data(t_print_info *info, va_list *ap)
{
	if (info->specifier == 'c' && !make_print_data_char(info, ap))
		return (RET_ERROR);
	if (info->specifier == 's' && !make_print_data_string(info, ap))
		return (RET_ERROR);
	if (info->specifier == 'p' && !make_print_data_pointer(info, ap))
		return (RET_ERROR);
	if (info->specifier == 'x' && !make_print_data_hex_lowercase(info, ap))
		return (RET_ERROR);
	if (info->specifier == 'X' && !make_print_data_hex_uppercase(info, ap))
		return (RET_ERROR);
	if (info->specifier == 'd' && !make_print_data_signed_int(info, ap))
		return (RET_ERROR);
	if (info->specifier == 'i' && !make_print_data_signed_int(info, ap))
		return (RET_ERROR);
	if (info->specifier == 'u' && !make_print_data_unsigned_int(info, ap))
		return (RET_ERROR);
	if (info->specifier == '%' && !make_print_data_percent(info))
		return (RET_ERROR);
	return (RET_SUCCESS);
}
