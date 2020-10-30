/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aligning_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:19:10 by tseo              #+#    #+#             */
/*   Updated: 2020/10/31 06:36:59 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

// int				make_aligned_char(void)
// {
// 	// char	*parsed_char;
// 	// int		len;
// 	// int		r_len;

// 	// len = ft_strlen(info->va_data);
// 	// r_len = info->width - len;
// 	// if (info->width > len)
// 	// {
// 	// 	if (!(parsed_char = (char*)malloc(sizeof(char) * (info->width))))
// 	// 		return (0);
// 	// 	ft_memset(parsed_char, ' ', info->width - 1);
// 	// 	parsed_char[info->width - 1] = 0;
// 	// 	if (info->flag == '-')
// 	// 		ft_memmove(parsed_char, info->va_data, len);
// 	// 	else if (info->flag == 0 || info->flag == '0')
// 	// 		ft_memmove(parsed_char + r_len, info->va_data, len);
// 	// 	ft_make_free(parsed_char, info);
// 	// }
// 	return (1);
// }



int				make_aligned_str(t_va_info *info)
{
	char	*parsed_str;
	int		len;

	len = ft_strlen(info->va_data);
	if (info->precision != -1 && info->precision < len)
	{
		if (!(parsed_str = (char*)malloc(sizeof(char) * (info->precision + 1))))
			return (0);
		ft_strlcpy(parsed_str, info->va_data, info->precision + 1);
		ft_make_free(parsed_str, info);
	}
	len = ft_strlen(info->va_data);
	if (info->width > len)
	{
		if (!(parsed_str = (char*)malloc(sizeof(char) * (info->width + 1))))
			return (0);
		parsed_str[info->width] = 0;
		ft_memset(parsed_str, ' ', info->width);
		if (info->flag == '-')
			ft_memmove(parsed_str, info->va_data, len);
		else
			ft_memmove(parsed_str + (info->width - len), info->va_data, len);
		ft_make_free(parsed_str, info);
	}
	return (1);
}

int				make_aligned_percent(t_va_info *info)
{
	if (!(make_aligned(info)))
		return (0);
	return (1);
}
