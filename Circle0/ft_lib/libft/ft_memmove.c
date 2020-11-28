/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:09:23 by tseo              #+#    #+#             */
/*   Updated: 2020/11/04 14:17:53 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	void *ret;

	if (!dst && !src)
		return (0);
	ret = dst;
	if (dst <= src)
	{
		while (n--)
			*(char*)dst++ = *(char*)src++;
	}
	else
	{
		src += n;
		dst += n;
		while (n--)
			*(char*)--dst = *(char*)--src;
	}
	return (ret);
}
