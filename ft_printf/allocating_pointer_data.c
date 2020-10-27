/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocating_pointer_data.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:43:59 by tseo              #+#    #+#             */
/*   Updated: 2020/10/27 19:52:08 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		allocate_pointer_data(t_va_info *info, va_list *ap)
{
	unsigned long int	tmp;
	char				*hex_data;

	tmp = (unsigned long)va_arg(*ap, void*);
	if (!(hex_data = ft_itoa_hex(tmp)))
		return (0);
	printf("tmp : %ld\n", tmp);
	printf("memory address: %s\n", hex_data);
	if (!(info->va_data = ft_strjoin("0x", hex_data)))
	{
		free(hex_data);
		return (0);
	}
	free(hex_data);
	return (1);
}
