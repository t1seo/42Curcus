/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_make_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:18:51 by heryu             #+#    #+#             */
/*   Updated: 2020/10/14 20:19:40 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			make_print_data_pointer(t_print_info *info, va_list *ap)
{
	unsigned long	tmp;
	char			*data_hex;
	size_t			len;

	tmp = (unsigned long)va_arg(*ap, void *);
	if ((data_hex = ft_itoa_base_unsigned_hex_ul(tmp)) == NULL)
		return (ALLOC_ERROR);
	len = ft_strlen(data_hex);
	if ((info->data = (char*)malloc((len + 3) * sizeof(char))) == NULL)
	{
		free(data_hex);
		return (ALLOC_ERROR);
	}
	ft_memcpy(info->data + 2, data_hex, len);
	free(data_hex);
	info->data[0] = '0';
	info->data[1] = 'x';
	info->data[len + 2] = '\0';
	return (RET_SUCCESS);
}

int			make_print_data_hex_lowercase(t_print_info *info, va_list *ap)
{
	unsigned int	tmp;

	tmp = va_arg(*ap, unsigned int);
	if ((info->data = ft_itoa_base_unsigned_hex(tmp)) == NULL)
		return (ALLOC_ERROR);
	return (RET_SUCCESS);
}

int			make_print_data_hex_uppercase(t_print_info *info, va_list *ap)
{
	unsigned int	tmp;
	size_t			i;

	tmp = va_arg(*ap, unsigned int);
	if ((info->data = ft_itoa_base_unsigned_hex(tmp)) == NULL)
		return (ALLOC_ERROR);
	i = 0;
	while (info->data[i] != '\0')
	{
		info->data[i] = ft_toupper(info->data[i]);
		i++;
	}
	return (RET_SUCCESS);
}

int			make_print_data_signed_int(t_print_info *info, va_list *ap)
{
	int		tmp;

	tmp = va_arg(*ap, int);
	if ((info->data = ft_itoa(tmp)) == NULL)
		return (ALLOC_ERROR);
	return (RET_SUCCESS);
}

int			make_print_data_unsigned_int(t_print_info *info, va_list *ap)
{
	unsigned int	tmp;

	tmp = va_arg(*ap, unsigned int);
	if ((info->data = ft_itoa_unsigned(tmp)) == NULL)
		return (ALLOC_ERROR);
	return (RET_SUCCESS);
}
