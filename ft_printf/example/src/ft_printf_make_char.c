/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_make_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:15:27 by heryu             #+#    #+#             */
/*   Updated: 2020/10/14 20:17:00 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			make_print_data_char(t_print_info *info, va_list *ap)
{
	if ((info->data = (char *)malloc(2 * sizeof(char))) == NULL)
		return (ALLOC_ERROR);
	info->data[0] = va_arg(*ap, int);
	info->data[1] = '\0';
	return (RET_SUCCESS);
}

int			make_print_data_string(t_print_info *info, va_list *ap)
{
	char	*tmp;
	size_t	length;

	tmp = va_arg(*ap, char *);
	if (tmp == NULL)
	{
		if ((info->data = (char *)malloc(7 * sizeof(char))) == NULL)
			return (ALLOC_ERROR);
		ft_memcpy(info->data, "(null)", 6);
		info->data[6] = '\0';
		return (RET_SUCCESS);
	}
	length = ft_strlen(tmp);
	if ((info->data = (char *)malloc((length + 1) * sizeof(char))) == NULL)
		return (ALLOC_ERROR);
	ft_memcpy(info->data, tmp, length);
	info->data[length] = '\0';
	return (RET_SUCCESS);
}

int			make_print_data_percent(t_print_info *info)
{
	if ((info->data = (char *)malloc(2 * sizeof(char))) == NULL)
		return (ALLOC_ERROR);
	info->data[0] = '%';
	info->data[1] = '\0';
	return (RET_SUCCESS);
}
