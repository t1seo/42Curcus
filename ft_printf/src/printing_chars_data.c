/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_chars_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:21:53 by tseo              #+#    #+#             */
/*   Updated: 2020/10/31 19:43:59 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void				print_char_data(t_va_info *info, int *count)
{
	if (info->flag == '-')
	{
		write(1, info->va_data, 1);
		(*count)++;
		write_padding(' ', info->width - 1, count);
	}
	else
	{
		write_padding(' ', info->width - 1, count);
		write(1, info->va_data, 1);
		(*count)++;
	}
}

void				print_percent_data(t_va_info *info, int *count)
{
	char percent;

	percent = '%';
	if (info->flag == '-')
	{
		write(1, &percent, 1);
		(*count)++;
		write_padding(' ', info->width - 1, count);
	}
	else
	{
		write_padding(' ', info->width - 1, count);
		write(1, &percent, 1);
		(*count)++;
	}
}
