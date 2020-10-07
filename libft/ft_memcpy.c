/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 11:53:18 by tseo              #+#    #+#             */
/*   Updated: 2020/10/07 10:28:25 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void*	ft_memcpy(void *dst, const void* src, size_t n)
{
	void *ret;

	if (!dst && !src)
		return (0);
	ret = dst;
	while (n--)
		*(char*)dst++ = *(char*)src++;
	return (ret);
}
