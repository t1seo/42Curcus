/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocating_pointer_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:43:59 by tseo              #+#    #+#             */
/*   Updated: 2020/10/30 22:40:44 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		allocate_pointer_data(t_va_info *info, va_list *ap)
{
	unsigned long int	tmp;
	char				*hex_data;

	tmp = (unsigned long)va_arg(*ap, void*);
	if (!(hex_data = ft_itoa_base(tmp, g_hex_digits_lower)))
		return (0);
	if (!(info->va_data = ft_strjoin("0x", hex_data)))
	{
		free(hex_data);
		return (0);
	}
	free(hex_data);
	return (1);
}
