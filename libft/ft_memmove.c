/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 아이디 <이메일>                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:09:23 by tseo              #+#    #+#             */
/*   Updated: 2020/10/07 10:24:06 by 아이디              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
