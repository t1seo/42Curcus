/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:10:32 by heryu             #+#    #+#             */
/*   Updated: 2020/10/02 12:10:33 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_ptr;
	const char	*src_ptr;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_ptr = dest;
	src_ptr = src;
	i = 0;
	while (i < n)
	{
		*dest_ptr++ = *src_ptr++;
		i++;
	}
	return (dest);
}
