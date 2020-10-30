/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocating_chars_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:41:55 by tseo              #+#    #+#             */
/*   Updated: 2020/10/31 01:40:33 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		allocate_char_data(t_va_info *info, va_list *ap)
{
	char tmp;

	if (!(info->va_data = (char*)malloc(sizeof(char) * 2)))
		return (0);
	tmp = va_arg(*ap, int);
	if (!tmp)
		info->va_data[0] = '\x00';
	else
		info->va_data[0] = tmp;
	info->va_data[1] = 0;
	return (1);
}

int		allocate_str_data(t_va_info *info, va_list *ap)
{
	char	*tmp;

	tmp = va_arg(*ap, char*);
	if (!tmp)
	{
		if (!(info->va_data = ft_strdup("(null)")))
			return (0);
		return (1);
	}
	if (!(info->va_data = ft_strdup(tmp)))
		return (0);
	return (1);
}

int		allocate_percent(t_va_info *info)
{
	if (!(info->va_data = (char*)malloc(sizeof(char) * 2)))
		return (0);
	info->va_data[0] = '%';
	info->va_data[1] = 0;
	return (1);
}
