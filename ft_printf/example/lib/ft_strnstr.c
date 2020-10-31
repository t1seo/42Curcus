/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:12:32 by heryu             #+#    #+#             */
/*   Updated: 2020/10/02 12:12:32 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_length;
	size_t	needle_length;
	size_t	pivot_end;
	size_t	pivot;

	haystack_length = ft_strlen(haystack);
	needle_length = ft_strlen(needle);
	if (needle_length == 0)
		return ((char *)haystack);
	if (haystack_length < needle_length || needle_length > len)
		return (NULL);
	if (haystack_length < len)
		pivot_end = haystack_length - needle_length;
	else
		pivot_end = len - needle_length;
	pivot = 0;
	while (pivot <= pivot_end)
	{
		if (ft_strncmp(haystack + pivot, needle, needle_length) == 0)
			return ((char *)(haystack + pivot));
		pivot++;
	}
	return (NULL);
}
