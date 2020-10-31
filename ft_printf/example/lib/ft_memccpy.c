/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:10:11 by heryu             #+#    #+#             */
/*   Updated: 2020/10/02 12:10:12 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	dest_ptr = dest;
	src_ptr = src;
	i = 0;
	while (i < n)
	{
		*dest_ptr = *src_ptr;
		if (*dest_ptr == (unsigned char)c)
			return (dest_ptr + 1);
		dest_ptr++;
		src_ptr++;
		i++;
	}
	return ((void *)0);
}
