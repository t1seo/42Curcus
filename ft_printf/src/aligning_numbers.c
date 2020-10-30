/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aligning_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:44:50 by tseo              #+#    #+#             */
/*   Updated: 2020/10/30 23:38:15 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int			make_aligned_int(t_va_info *info)
{
	if (!(make_aligned(info)))
		return (0);
	return (1);
}

int			make_aligned_uint(t_va_info *info)
{
	if (!(make_aligned(info)))
		return (0);
	return (1);
}

int			make_aligned_hex(t_va_info *info)
{
	if (!(make_aligned(info)))
		return (0);
	return (1);
}
