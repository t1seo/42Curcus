/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseo <tseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:41:40 by tseo              #+#    #+#             */
/*   Updated: 2020/10/06 20:13:19 by tseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_set(char c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && is_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (start < end && is_set(s1[end - 1], set))
		end--;
	if (!(str = (char*)malloc(sizeof(char) * (end - start + 1))))
		return (0);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}
