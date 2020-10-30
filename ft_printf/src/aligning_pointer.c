/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aligning_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:45:09 by tseo              #+#    #+#             */
/*   Updated: 2020/10/30 22:42:08 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		make_aligned_ptr(t_va_info *info)
{
	char	*parsed_ptr;
	int		len;

	len = ft_strlen(info->va_data);
	if (info->width > len)
	{
		if (!(parsed_ptr = (char*)malloc(sizeof(char) * (info->width + 1))))
			return (0);
		parsed_ptr[info->width] = 0;
		if (info->flag == '-')
		{
			ft_memset(parsed_ptr, ' ', info->width);
			ft_memmove(parsed_ptr, info->va_data, len);
		}
		else if (info->flag == 0 || info->flag == '0')
		{
			ft_memset(parsed_ptr, ' ', info->width);
			ft_memmove(parsed_ptr + (info->width - len), info->va_data, len);
		}
		free(info->va_data);
		info->va_data = parsed_ptr;
		parsed_ptr = 0;
	}
	return (1);
}
