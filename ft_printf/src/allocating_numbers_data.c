/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocating_numbers_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:44:19 by tseo              #+#    #+#             */
/*   Updated: 2020/10/29 13:16:51 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

char const	*hex_digits_lower = "0123456789abcdef";
char const	*hex_digits_upper = "0123456789ABCDEF";
char const	*int_digits = "0123456789";

int		allocate_signed_int(t_va_info *info, va_list *ap)
{
	int tmp;

	tmp = va_arg(*ap, int);
	if (!(info->va_data = ft_itoa(tmp)))
		return (0);
	return (1);
}

int		allocate_unsigned_int(t_va_info *info, va_list *ap)
{
	unsigned int tmp;

	tmp = va_arg(*ap, unsigned int);
	if (!(info->va_data = ft_itoa_base(tmp, int_digits)))
		return (0);
	return (1);
}
int		allocate_hex(t_va_info *info, va_list *ap)
{
	unsigned int tmp;

	tmp = va_arg(*ap, unsigned int);
	if (info->specifier == 'x')
	{
		if (!(info->va_data = ft_itoa_base(tmp, hex_digits_lower)))
			return (0);
	}
	if (info->specifier == 'X')
	{
		if (!(info->va_data = ft_itoa_base(tmp, hex_digits_upper)))
			return (0);
	}
	return (1);
}
