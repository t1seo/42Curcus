/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:10:41 by heryu             #+#    #+#             */
/*   Updated: 2020/10/02 12:10:41 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t		i;
	char		*dest_ptr;
	const char	*src_ptr;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_ptr = dest;
	src_ptr = src;
	i = 0;
	if (dest <= src)
	{
		while (i++ < len)
			*dest_ptr++ = *src_ptr++;
	}
	else
	{
		while (i < len)
		{
			*(dest_ptr + len - 1 - i) = *(src_ptr + len - 1 - i);
			i++;
		}
	}
	return (dest);
}
