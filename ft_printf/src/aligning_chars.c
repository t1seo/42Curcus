/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aligning_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:19:10 by tseo              #+#    #+#             */
/*   Updated: 2020/10/29 21:24:12 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		make_aligned_char(t_va_info *info)
{
	char *parsed_char;
	int len;
	int r_len;

	len = ft_strlen(info->va_data);
	r_len = info->width - len;
	if (info->width > ft_strlen(info->va_data))
	{
		if (!(parsed_char = (char*)malloc(sizeof(char) * (info->width + 1))))
			return (0);
		parsed_char[info->width] = 0;
		if (info->flag == '-')
		{
			ft_memset(parsed_char, ' ', info->width);
			ft_memmove(parsed_char, info->va_data, len);
		}
		else if (info->flag == '0')
		{
			ft_memset(parsed_char, '0', info->width);
			ft_memmove(parsed_char + r_len, info->va_data, len);
		}
		else if (info->flag == 0)
		{
			ft_memset(parsed_char, ' ', info->width);
			ft_memmove(parsed_char + r_len, info->va_data, len);
		}
		free(info->va_data);
		info->va_data = parsed_char;
	}
	return (1);
}

int		make_aligned_str(t_va_info *info)
{
	if (!(make_aligned_char(info)))
		return (0);
	return (1);
}

int		make_aligned_percent(t_va_info *info)
{
	if (!(make_aligned_char(info)))
		return (0);
	return (1);
}
