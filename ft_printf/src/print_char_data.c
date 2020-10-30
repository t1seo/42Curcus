/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 06:23:06 by tseo              #+#    #+#             */
/*   Updated: 2020/10/31 06:38:06 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static void		make_padding(t_va_info *info, char padding, int *count)
{
	int i;
	if (padding == 0)
		padding = ' ';

	i = info->width - 1;
	while (i)
	{
		write(1, &padding, 1);
		(*count)++;
		i--;
	}
}

void			print_char_data(t_va_info *info, int *count)
{
	if (info->flag == '-')
	{
		write(1, info->va_data, 1);
		(*count)++;
		make_padding(info, ' ', count);
	}
	else
	{
		make_padding(info, ' ', count);
		write(1, info->va_data, 1);
		(*count)++;
	}
}
