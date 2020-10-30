/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aligning_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:19:10 by tseo              #+#    #+#             */
/*   Updated: 2020/10/30 23:35:25 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		make_aligned_char(t_va_info *info)
{
	if (!(make_aligned(info)))
		return (0);
	return (1);
}

int		make_aligned_str(t_va_info *info)
{
	if (!(make_aligned(info)))
		return (0);
	return (1);
}

int		make_aligned_percent(t_va_info *info)
{
	if (!(make_aligned(info)))
		return (0);
	return (1);
}
