/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 아이디 <이메일>                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:21:27 by tseo              #+#    #+#             */
/*   Updated: 2020/10/07 10:18:51 by 아이디              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	if (!dst &&!src)
		return (NULL);
	while (n--)
	{
		*(char*)dst++ = *(char*)src;
		if (*(unsigned char*)src++ == (unsigned char)c)
			return (dst);
	}
	return (NULL);
}
