/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:21:27 by tseo              #+#    #+#             */
/*   Updated: 2020/11/04 14:17:37 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	if (!dst && !src)
		return (0);
	while (n--)
	{
		*(char*)dst++ = *(char*)src;
		if (*(unsigned char*)src++ == (unsigned char)c)
			return (dst);
	}
	return (0);
}
