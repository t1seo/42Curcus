/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 12:09:27 by tseo              #+#    #+#             */
/*   Updated: 2020/10/06 20:06:39 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	if (!s1 || !s2)
		return (0);
	if (!s2[0])
		return ((char*)s1);
	i = 0;
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i + j] && s2[j] && i + j < len && s1[i + j] == s2[j])
			j++;
		if (!s2[j])
			return ((char*)(s1 + i));
		i++;
	}
	return (0);
}
