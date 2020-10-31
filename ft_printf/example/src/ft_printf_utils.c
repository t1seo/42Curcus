/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 20:09:28 by heryu             #+#    #+#             */
/*   Updated: 2020/10/14 20:11:26 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	str_rev(char *arr, size_t len)
{
	char	tmp;
	size_t	i;

	i = 0;
	while (i < len / 2)
	{
		tmp = arr[i];
		arr[i] = arr[len - 1 - i];
		arr[len - 1 - i] = tmp;
		i++;
	}
}

char		*ft_itoa_unsigned(unsigned int n)
{
	char	tmp[12];
	size_t	cnt;
	char	*ret;

	cnt = 0;
	while (1)
	{
		tmp[cnt++] = (n % 10) + 0x30;
		n /= 10;
		if (n == 0)
			break ;
	}
	str_rev(tmp, cnt);
	if ((ret = (char *)malloc((cnt + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_memcpy(ret, tmp, cnt);
	ret[cnt] = '\0';
	return (ret);
}

char		get_hex_char_lowercase(int n)
{
	if (0 <= n && n <= 9)
		return (n + 48);
	if (10 <= n && n <= 15)
		return (n + 87);
	return (n);
}

char		*ft_itoa_base_unsigned_hex_ul(unsigned long val)
{
	unsigned long		origin_val;
	size_t				len;
	char				*ret;

	origin_val = val;
	len = 0;
	while (1)
	{
		val /= 16;
		len++;
		if (val == 0)
			break ;
	}
	if ((ret = (char *)malloc((len + 1) * sizeof(char))) == NULL)
		return (ALLOC_ERROR);
	ret[len] = '\0';
	val = origin_val;
	while (len > 0)
	{
		ret[--len] = get_hex_char_lowercase(val % 16);
		val /= 16;
		if (val == 0)
			break ;
	}
	return (ret);
}

char		*ft_itoa_base_unsigned_hex(unsigned int val)
{
	unsigned int		origin_val;
	size_t				len;
	char				*ret;

	origin_val = val;
	len = 0;
	while (1)
	{
		val /= 16;
		len++;
		if (val == 0)
			break ;
	}
	if ((ret = (char *)malloc((len + 1) * sizeof(char))) == NULL)
		return (ALLOC_ERROR);
	ret[len] = '\0';
	val = origin_val;
	while (len > 0)
	{
		ret[--len] = get_hex_char_lowercase(val % 16);
		val /= 16;
		if (val == 0)
			break ;
	}
	return (ret);
}
