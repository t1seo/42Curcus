/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:11:59 by heryu             #+#    #+#             */
/*   Updated: 2020/10/02 12:12:00 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	origin_dstsize;

	origin_dstsize = ft_strlen(dst);
	i = origin_dstsize;
	j = 0;
	while (src[j] != '\0' && j + origin_dstsize + 1 < dstsize)
	{
		dst[i++] = src[j++];
	}
	if (dstsize != 0 && origin_dstsize <= dstsize)
		dst[i] = '\0';
	if (origin_dstsize < dstsize)
		return (ft_strlen(src) + origin_dstsize);
	else
		return (ft_strlen(src) + dstsize);
}
