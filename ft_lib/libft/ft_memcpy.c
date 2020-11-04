/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 11:53:18 by tseo              #+#    #+#             */
/*   Updated: 2020/11/04 14:17:48 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *ret;

	if (!dst && !src)
		return (0);
	ret = dst;
	while (n--)
		*(char*)dst++ = *(char*)src++;
	return (ret);
}
